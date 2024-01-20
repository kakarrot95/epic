import sys
from antlr4 import FileStream, CommonTokenStream
from antlr4.error.ErrorListener import ErrorListener, ConsoleErrorListener
from EpicLangLexer import EpicLangLexer
from EpicLangParser import EpicLangParser
from EpicLangVisitor import EpicLangVisitor


# handler for syntax errors
class ErrorHandler(ErrorListener):
    def syntaxError(self, recognizer, offendingSymbol, line, column, msg, e):
        print('syntax error')
        sys.exit(0)


def main():
    # create input stream
    in_stream = FileStream(sys.argv[1])

    # create a lexer
    lexer = EpicLangLexer(in_stream)
    # add error handling for our lexer
    lexer.addErrorListener(ErrorHandler())
    lexer.removeErrorListener(ConsoleErrorListener.INSTANCE)

    # create a parser with the lexer as an input
    stream = CommonTokenStream(lexer)
    parser = EpicLangParser(stream)
    # add error handling for our parser
    parser.addErrorListener(ErrorHandler())
    parser.removeErrorListener(ConsoleErrorListener.INSTANCE)

    # use the parser to obtain an abstract syntax tree
    tree = parser.program()

    # TODO : traverse the tree and execute the program


if __name__ == "__main__":
    main()
