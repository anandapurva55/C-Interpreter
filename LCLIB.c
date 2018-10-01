//
//  LCLIB.c
//  Interpreter

//  Copyright © 2018 apurva anand. All rights reserved.
//

#include "LCLIB.h"

#include <stdio.h>
#include <stdlib.h>

extern char *prog;
extern char token[80];
extern char token_type;
extern char tok;
enum tok_types {DELIMETER, IDENTIFIER, NUMBER, KEYWORD, TEMP, STRING, BLOCK};

/* These are the constants used to call sntx_err() when a syntax error occurs.
 NOTE: SYNTAX is a generic error message used when nothing else seems appropriate */
enum error_msg
{SYNTAX, UNBAL_PARENS, NO_EXP, EQUALS_EXPECTED, NOT_VAR, PARAM_ERR, SEMI_EXPECTED, UNBAL_BRACES, FUNC_UNDEF, TYPE_EXPECTED, NEST_FUNC, RET_NOCALL, PAREN_EXPECTED, WHILE_EXPECTED, QUOTE_EXPECTED, NOT_TEMP, TOO_MANY_LVARS, DIV_BY_ZERO};
int get_token(void);
void sntx_err(int error), eval_exp(int *result);
void putback(void);

/*Get a character from console.(Use getchar() if your compiler doesnot support _getche().)*/
int call_getche(){
    char ch;
    ch = getchar();
    while(*prog != ')') prog++;
    prog++; //advance to end of line
    return ch;
}

//Put a character to the display */
int call_putch(){
    int value;
    
    eval_exp(&value);
    printf("%c",value);
    return value;
}

//Call puts
int call_puts(void){
    get_token();
    if(*token != '(') sntx_err(PAREN_EXPECTED);
    get_token();
    
    if(token_type != STRING)  sntx_err(QUOTE_EXPECTED);
    puts(token);
    get_token();
    if(*token != ')') sntx_err(PAREN_EXPECTED);
    
    get_token();
    if(*token != ';' ) sntx_err(SEMI_EXPECTED);
    putback();
    return 0;
}

int print(void){
    int i;
    
    get_token();
    if(*token != '(') sntx_err(PAREN_EXPECTED);
    
    get_token();
    if(token_type == STRING) { /*output a string */
        printf("%s",token);
    }
    else{ // output a number
        putback();
        eval_exp(&i);
        printf("%d",i);
    }
    
    get_token();
    
    if(*token != ')')  sntx_err(PAREN_EXPECTED);
    
    get_token();
    if(*token != ';') sntx_err(PAREN_EXPECTED);
    if(*token != ';') sntx_err(SEMI_EXPECTED);
    putback();
    return 0;
}


//Read an intger from the keyboard
int getnum(void){
    char s[80];
    
    gets(s);
    while(*prog != ')') prog++;
    prog++; // move to end of line
    return atoi(s);
}


