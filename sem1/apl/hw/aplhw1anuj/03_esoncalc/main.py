from antlr4 import FileStream, CommonTokenStream
from EsonLexer import EsonLexer
from EsonParser import EsonParser
from EsonVisitor import EsonVisitor
import datetime
import json
import sys
import math


def parse_time(time):
    return datetime.datetime.strptime(
        time,
        '%H:%M:%S.%f' if '.' in time[:15] else '%H:%M:%S')


def parse_date(date):
    return datetime.datetime.fromisoformat(date)


def parse_datetime(dt):
    d, t = dt.split('T')
    d = parse_date(d)
    t = parse_time(t)
    return datetime.datetime.combine(d.date(), t.time())


def format_time(time):
    return time.strftime('%H:%M:%S.%f')


def format_date(date):
    return date.strftime('%Y-%m-%d')


def format_datetime(dt):
    return dt.strftime('%Y-%m-%dT%H:%M:%S.%f')


class Visitor(EsonVisitor):
    def visitList(self, ctx):
        return [self.visit(item) for item in ctx.item()]

    def visitDict(self, ctx):
        result = {}
        for pair in ctx.dict_key_value():
            key = visitor.visit(pair.key())
            value = visitor.visit(pair.item())
            result[key] = value
        return result

    def visitKey(self, ctx):
        if ctx.SYMBOL():
            return ctx.SYMBOL().getText()
        elif ctx.STRING():
            return bytes(ctx.STRING().getText()[1:-1], 'utf-8').decode('unicode_escape')

    def handle_int(self, text):
        sign = 1
        if text.startswith('+') or text.startswith('-'):
            sign = -1 if text.startswith('-') else 1
            text = text[1:]
        if text.startswith('0x'):
            return sign * int(text[2:], 16)
        elif text.startswith('0'):
            if len(text) > 1:
                return sign * int(text[1:], 8)

        return sign * int(text)

    def handle_duration(self, text):
        suffixes = { 'ns': 1e-9, 'us': 1e-6, 'ms': 1e-3, 's': 1, 'm': 60, 'h': 3600 }
        for suffix, multiplier in suffixes.items():
            if text.endswith(suffix):
                return float(text[:-len(suffix)]) * multiplier

    def visitItem(self, ctx):
        if ctx.CHAR():
            return bytes(ctx.CHAR().getText()[1:-1], 'utf-8').decode('unicode_escape')
        elif ctx.DATE():
            return format_date(parse_date(ctx.DATE().getText()))
        elif ctx.TIME():
            return format_time(parse_time(ctx.TIME().getText()))
        elif ctx.DATETIME():
            return format_datetime(parse_datetime(ctx.DATETIME().getText()))
        elif ctx.DURATION():
            return self.handle_duration(ctx.DURATION().getText())
        elif ctx.BOOLEAN():
            return ctx.BOOLEAN().getText() == 'true'
        elif ctx.NULL():
            return None
        elif ctx.key():
            return self.visit(ctx.key())
        elif ctx.expr():
            return self.visit(ctx.expr())
        elif ctx.list_():
            return self.visit(ctx.list_())
        elif ctx.dict_():
            return self.visit(ctx.dict_())

    def visitExpr(self, ctx):
        return self.visit(ctx.term())

    def visitTerm(self, ctx):
        result = self.visit(ctx.factor(0))  
        
        for i in range(1, len(ctx.factor())):
            operator = ctx.getChild(2 * i - 1).getText() 
            right_operand = self.visit(ctx.factor(i))  
 
            if operator == '+':
                result += right_operand
            elif operator == '-':
                result -= right_operand

        return result

    def visitFactor(self, ctx):
        result = self.visit(ctx.unary(0))  
 
        for i in range(1, len(ctx.unary())):
            operator = ctx.getChild(2 * i - 1).getText()
            right_operand = self.visit(ctx.unary(i))  
            
            if operator == '*':
                result *= right_operand
            elif operator == '/':
                result /= right_operand

        return result

    def visitUnary(self, ctx):
        if ctx.PLUS():
            return self.visit(ctx.unary())
        elif ctx.MINUS():
            return -self.visit(ctx.unary())
        elif ctx.SIN():
            return math.sin(self.visit(ctx.unary()))
        elif ctx.COS():
            return math.cos(self.visit(ctx.unary()))
        elif ctx.primary():
            return self.visit(ctx.primary())
        elif ctx.unary():
            return self.visit(ctx.unary())

    def visitPrimary(self, ctx):
        if ctx.INT():
            return self.handle_int(ctx.INT().getText())
        elif ctx.FLOAT():
            return float(ctx.FLOAT().getText())
        elif ctx.FLOAT_EXP():
            return float(ctx.FLOAT_EXP().getText())
        elif ctx.expr():
            return self.visit(ctx.expr())

in_stream = FileStream('input.eson')
lexer = EsonLexer(in_stream)
stream = CommonTokenStream(lexer)
parser = EsonParser(stream)
tree = parser.item()
visitor = Visitor()
result = visitor.visit(tree)
json.dump(result, sys.stdout, indent='  ', sort_keys=True)
