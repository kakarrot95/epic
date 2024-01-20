grammar Eson;

SPACE: [ \t\n] -> skip;

INT : [+-]? ('0' | [1-9][0-9]* | '0' [0-7]+ | '0x' [0-9a-fA-F]+ ) ;

FLOAT: [+-]? ([0-9]+'.' | '.'[0-9]+ | [0-9]+'.'[0-9]+);

FLOAT_EXP: (FLOAT | INT) ([eE][+-]?[0-9]+)?;

CHAR: '\'' ( ~['\\] | '\\' [nt\\"'] | '\\u' [0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F] ) '\'';

STRING : '"' ( ~["\\] | '\\"' | '\\n' | '\\t' | '\\\\' | '\\\'' | '\\u' [0-9a-fA-F]{4} )* '"' ;

DATE: [0-9][0-9][0-9][0-9] '-' ('0'[1-9] | '1'[0-2]) '-' ('0'[1-9] | [12][0-9] | '3'[01]);

TIME : ([01][0-9] | '2'[0-3]) ':' ([0-5][0-9]) ':' ([0-5][0-9]) ('.'[0-9]+)?;

DATETIME : DATE 'T' TIME ;

DURATION : (FLOAT | [+-]?[0-9]+) ('ns'|'us'|'ms'|'s'|'m'|'h') ;

BOOLEAN : 'true' | 'false' ;

NULL : 'null' ;

SYMBOL : [a-zA-Z] [a-zA-Z0-9_-]* ;

COMMENT: '#' ~[\r\n]* -> skip;

eson_value : INT | FLOAT | FLOAT_EXP | CHAR | DATE | TIME | DATETIME | DURATION | BOOLEAN | NULL | key;

item :  dict | list | eson_value;

list : '[' (item (',' item)* ','?)? ']';

key : (SYMBOL | STRING);
dict_key_value : key '=' item;
dict : '{' (dict_key_value (',' dict_key_value*)* ','?)? '}';
