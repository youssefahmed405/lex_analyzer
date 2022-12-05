#include "assist.h"
//HERE  we can add any type we want
enum token_type{

    INT,FLOAT,DOUBLE,SIGNED,UNSIGNED,CONST,BOOL,VOID,LONG,SHORT,CHAR,BYTE,

    IF,WHILE,ELSE,FOR,RETURN,AUTO,BREAK,CONTINUE,TRUE,FALSE,NEW,THIS,CASE,
    SWITCH,STRUCT,GOTO,SIZEOF,DELETE,ENUM,EXTERN,

    GREATER_THAN,GREATER_OR_EQUAL,EQUAL,NOT_EQUAL,LESS_THAN,LESS_OR_EQUAL,
    
    L_PAREN,R_PAREN,L_BRACE,R_BRACE,COMMA,DOT,SEMICOLON,L_BRACKET,R_BRACKET,

    PLUS,MINUS,MUL,DIV,

    LITERAL,EQUAL_EQUAL,ERROR,NUMERIC,ID,MACRO,FLOAT_NUMBER,IN_LIB,OPERATOR
};


class token
{
public:
    string lexeme; //int
    token_type type; //int
};

token_type t_type(string x)
{
if( x =="int") return INT; 
if( x == "float") return FLOAT;         
if( x =="double") return DOUBLE;       
if( x =="signed") return SIGNED;       
if( x =="unsigned") return UNSIGNED;   
if( x =="const") return CONST;         
if( x =="bool") return BOOL;           
if( x =="void") return VOID;           
if( x =="long") return LONG;           
if( x =="short") return SHORT;         
if( x =="char") return CHAR;           
if( x =="byte") return BYTE;           
if( x =="if") return IF;               
if( x =="while") return WHILE;         
if( x =="else") return ELSE;           
if( x =="for") return FOR;             
if( x =="return") return RETURN;       
if( x =="auto") return AUTO;           
if( x =="break") return BREAK;         
if( x =="continue") return CONTINUE;   
if( x =="true") return TRUE; 
if( x =="false") return FALSE;
if( x =="new") return NEW;
if( x =="this") return THIS; 
if( x =="case") return CASE; 
if( x =="switch") return SWITCH; 
if( x =="struct") return STRUCT; 
if( x =="gote") return GOTO; 
if( x =="sizeof") return SIZEOF; 
if( x =="delete") return DELETE; 
if( x =="enum") return ENUM; 
if( x =="extern") return EXTERN; 
if( x ==">") return GREATER_THAN; 
if( x ==">=") return GREATER_OR_EQUAL; 
if( x =="=") return EQUAL; 
if( x =="!=") return NOT_EQUAL; 
if( x =="<") return LESS_THAN; 
if( x =="<=") return LESS_OR_EQUAL; 
if( x =="(") return L_PAREN; 
if( x ==")") return R_PAREN; 
if( x =="{") return L_BRACE; 
if( x =="}") return R_BRACE; 
if( x ==",") return COMMA;
if( x ==".") return DOT; 
if( x ==";") return SEMICOLON;
if( x =="[") return L_BRACKET;
if( x =="]") return R_BRACKET;
if( x =="+") return PLUS;
if( x =="-") return MINUS;
if( x =="*") return MUL;
if( x =="/") return DIV;
if( _catch_a_res_lib_(x))return IN_LIB;
if(x[0] == '\"' && x.back() == '\"') return LITERAL;
if(x[0] == '#') return MACRO;
if( _catch_a_operator_(x))return OPERATOR;
if( x =="==")return EQUAL_EQUAL;
if( is_integer(x) || x == "0")return NUMERIC;
if(_check_for_id_(x) && !_catch_a_res_word_(x))return ID;
if( is_float(x))return FLOAT_NUMBER;
else return ERROR;
}



//JUST IN CASE WE NNED TO PRINT ||')
string return_value(int index)
{
string temp = "";
switch (index)
{
case 0: temp = "INT"; break;
case 1: temp = "FLOAT"; break;
case 2: temp = "DOUBLE"; break;
case 3: temp = "SIGNED"; break;
case 4: temp = "UNSIGNED"; break;
case 5: temp = "CONST"; break;
case 6: temp = "BOOL"; break;
case 7: temp = "VOID"; break;
case 8: temp = "LONG"; break;
case 9: temp = "SHORT"; break;
case 10: temp = "CHAR"; break;
case 11: temp = "BYTE"; break;
case 12: temp = "IF"; break;
case 13: temp = "WHILE"; break;
case 14: temp = "ELSE"; break;
case 15: temp = "FOR"; break;
case 16: temp = "RETURN"; break;
case 17: temp = "AUTO"; break;
case 18: temp = "BREAK"; break;
case 19: temp = "CONTINUE"; break;
case 20: temp = "TRUE"; break;
case 21: temp = "FALSE"; break;
case 22: temp = "NEW"; break;
case 23: temp = "THIS"; break;
case 24: temp = "CASE"; break;
case 25: temp = "SWITCH"; break;
case 26: temp = "STRUCT"; break;
case 27: temp = "GOTO"; break;
case 28: temp = "SIZEOF"; break;
case 29: temp = "DELETE"; break;
case 30: temp = "ENUM"; break;
case 31: temp = "EXTERN"; break;
case 32: temp = "GREATER_THAN"; break;
case 33: temp = "GREATER_OR_EQUAL"; break;
case 34: temp = "EQUAL"; break;
case 35: temp = "NOT_EQUAL"; break;
case 36: temp = "LESS_THAN"; break;
case 37: temp = "LESS_OR_EQUAL"; break;
case 38: temp = "L_PAREN"; break;
case 39: temp = "R_PAREN"; break;
case 40: temp = "L_BRACE"; break;
case 41: temp = "R_BRACE"; break;
case 42: temp = "COMMA"; break;
case 43: temp = "DOT"; break;
case 44: temp = "SEMICOLON"; break;
case 45: temp = "L_BRACKET"; break;
case 46: temp = "R_BRACKET"; break;
case 47: temp = "PLUS"; break;
case 48: temp = "MINUS"; break;
case 49: temp = "MUL"; break;
case 50: temp = "DIV"; break;
case 51: temp = "LITERAL"; break;
case 52: temp = "EQUAL_EQUAL";break;
case 53: temp = "ERROR";break;
case 54: temp = "NUMERIC";break;
case 55: temp = "ID";break;
case 56: temp = "MACRO";break;
case 57: temp = "FLOAT_NUMBER";break;
case 58: temp = "IN_LIB";break;
case 59: temp = "OPERATOR";break;
defualt : break;
}
return temp;
}
