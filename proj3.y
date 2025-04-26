/* proj3.y */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"

extern FILE *yyin;
extern int yylex(void);
void yyerror(const char *s);

/* --- 3AC storage --- */
int qind = 0;
struct quadruple {
    char op[8], a1[20], a2[20], res[20];
} quad[200];

void addQuadruple(const char *x,const char *o,const char *y,const char *r){
    strcpy(quad[qind].op,  o);
    strcpy(quad[qind].a1, x);
    strcpy(quad[qind].a2, y);
    strcpy(quad[qind].res, r);
    qind++;
}

void displayQuadruple(){
    printf("\n--- Three Address Code ---\n");
    for(int i=0;i<qind;i++){
        char *op=quad[i].op, *a1=quad[i].a1,
             *a2=quad[i].a2, *r=quad[i].res;
        if (!strcmp(op,"iffalse"))
            printf("if %s=0 goto %s\n", a1, r);
        else if (!strcmp(op,"goto"))
            printf("goto %s\n", r);
        else if (!strcmp(op,"label"))
            printf("%s:\n", r);
        else if (!strcmp(op,"print"))
            printf("print %s %s\n", a1, a2);
        else if (!strcmp(op,"scan"))
            printf("scan %s %s\n", a1, a2);
        else if (!strcmp(op,""))
            printf("%s = %s\n", r, a1);
        else
            printf("%s = %s %s %s\n", r, a1, op, a2);
    }
    printf("END PROGRAM\n");
}

/* --- temp vars and labels (fixed) --- */
int tempCount = 0;
char* tempVar(){
    char buf[20];
    sprintf(buf, "t%d", tempCount++);
    return strdup(buf);
}

int lblCount = 0;
char* newLabel(){
    char buf[20];
    sprintf(buf, "L%d", lblCount++);
    return strdup(buf);
}

/* for‐loop temporaries */
static char *for_var_name, *for_inc_val;
static char *for_head, *for_exit;

/* if–else labels */
static char *elseLab, *endLab;
%}

%union {
    int    ival;
    char*  sval;
}

%token <sval> BEGIN_KEY END PROGRAM VARDECL INT CHAR
%token <sval> IF ELSE WHILE FOR DO TO INC DEC
%token <sval> PRINT SCAN ASSIGNOP ADDOP SUBOP MULOP DIVOP MODOP RELOP
%token <sval> LPAREN RPAREN LBRACKET RBRACKET COMMA SEMICOLON COLON
%token <sval> ID STRCONST
%token <ival> NUM INTCONST CHARCONST INDEX

%type <sval> program var_decl_block varlist var_decl type
%type <sval> stmt_block stmt assign_stmt io_stmt print_stmt scan_stmt print_args scan_fmt scan_args cond_stmt loop_stmt while_stmt for_stmt for_setup block expr

%left RELOP
%left ADDOP SUBOP
%left MULOP DIVOP MODOP
%nonassoc UMINUS LOWER_THAN_ELSE

%%

program
  : BEGIN_KEY PROGRAM COLON var_decl_block stmt_block END PROGRAM
    {
      printf("Successfully parsed !!!\n");
      displayQuadruple();
      printSymbolTable();
    }
  ;

var_decl_block
  : BEGIN_KEY VARDECL COLON varlist END VARDECL
  ;

varlist
  : varlist var_decl
  | var_decl
  ;

var_decl
  : LPAREN ID COMMA type RPAREN SEMICOLON
    { insertSymbol($2, $4); free($2); free($4); }
  | LPAREN ID LBRACKET INTCONST RBRACKET COMMA type RPAREN SEMICOLON
    { insertSymbol($2, $7); free($2); free($7); }
  | LPAREN ID LBRACKET INDEX RBRACKET COMMA type RPAREN SEMICOLON
    { insertSymbol($2, $7); free($2); free($7); }
  ;

type
  : INT  { $$ = strdup("int"); }
  | CHAR { $$ = strdup("char"); }
  ;

stmt_block
  : stmt_block stmt
  | stmt
  ;

stmt
  : assign_stmt
  | io_stmt
  | cond_stmt
  | loop_stmt
  | block
  ;

assign_stmt
  : ID ASSIGNOP expr SEMICOLON
    {
      addQuadruple($3, "", "", $1);
      updateSymbol($1, atoi($3));
      free($1); free($3);
    }
  ;

io_stmt
  : print_stmt
  | scan_stmt
  ;

print_stmt
  : PRINT LPAREN STRCONST RPAREN SEMICOLON
    { addQuadruple("", "print", $3, ""); free($3); }
  | PRINT LPAREN STRCONST COMMA print_args RPAREN SEMICOLON
    { addQuadruple("", "print", $3, $5); free($3); free($5); }
  ;

print_args
  : expr                 { $$ = $1; }
  | expr COMMA print_args{ free($3); $$ = $1; }
  ;

scan_stmt
  : SCAN LPAREN scan_fmt COMMA scan_args RPAREN SEMICOLON
    { addQuadruple("", "scan", $3, ""); free($3); }
  ;

scan_fmt
  : STRCONST { $$ = $1; }
  ;

scan_args
  : ID                 { free($1); }
  | ID COMMA scan_args { free($1); free($3); }
  ;

cond_stmt
  : IF LPAREN expr RPAREN block ELSE block SEMICOLON
      {
        elseLab = newLabel();
        endLab  = newLabel();
        addQuadruple($3,"iffalse","",elseLab);
        free($3);
        /* after then: skip over else */
        addQuadruple("", "goto", "", endLab);
        addQuadruple("", "label", "", elseLab);
        /* else‐block code was just emitted */
        addQuadruple("", "label", "", endLab);
      }
  | IF LPAREN expr RPAREN block SEMICOLON
      {
        elseLab = newLabel();
        addQuadruple($3,"iffalse","",elseLab);
        free($3);
        addQuadruple("", "label", "", elseLab);
      }
  ;

loop_stmt
  : while_stmt
  | for_stmt
  ;

while_stmt
  : WHILE LPAREN expr RPAREN DO block SEMICOLON
    {
      char *L1 = newLabel(), *L2 = newLabel();
      addQuadruple("", "label", "", L1);
      addQuadruple($3, "iffalse", "", L2);
      free($3);
      /* body already emitted */
      addQuadruple("", "goto", "", L1);
      addQuadruple("", "label", "", L2);
    }
  ;

for_stmt
  : for_setup DO block SEMICOLON
    {
      /* after body: increment, back to head, exit label */
      addQuadruple(for_inc_val, "", "", for_var_name);
      addQuadruple("", "goto", "", for_head);
      addQuadruple("", "label", "", for_exit);
      free(for_var_name);
      free(for_inc_val);
    }
  ;

for_setup
  : FOR ID ASSIGNOP expr TO expr INC expr
    {
      /* save for the closing action */
      for_var_name = $2;
      for_inc_val   = $8;
      /* init loop var */
      addQuadruple($4, "", "", $2);
      updateSymbol($2, atoi($4));
      /* labels */
      for_head = newLabel();
      for_exit = newLabel();
      /* head label */
      addQuadruple("", "label", "", for_head);
      /* test: tX = ID > upper */
      {
        char *T = tempVar();
        addQuadruple($2, ">", $6, T);
        addQuadruple(T, "iffalse", "", for_exit);
      }
      free($4); free($6);
    }
  ;

block
  : BEGIN_KEY stmt_block END
  ;

expr
  : expr ADDOP expr
    {
      char *T = tempVar();
      addQuadruple($1, "+", $3, T);
      $$ = strdup(T);
      free($1); free($3);
    }
  | expr SUBOP expr
    {
      char *T = tempVar();
      addQuadruple($1, "-", $3, T);
      $$ = strdup(T);
      free($1); free($3);
    }
  | expr MULOP expr
    {
      char *T = tempVar();
      addQuadruple($1, "*", $3, T);
      $$ = strdup(T);
      free($1); free($3);
    }
  | expr DIVOP expr
    {
      if (!atoi($3)) yyerror("division by zero");
      char *T = tempVar();
      addQuadruple($1, "/", $3, T);
      $$ = strdup(T);
      free($1); free($3);
    }
  | expr MODOP expr
    {
      char *T = tempVar();
      addQuadruple($1, "mod", $3, T);
      $$ = strdup(T);
      free($1); free($3);
    }
  | expr RELOP expr
    {
      char *T = tempVar();
      addQuadruple($1, $2, $3, T);
      $$ = strdup(T);
      free($1); free($3); free($2);
    }
  | SUBOP expr %prec UMINUS
    {
      char *T = tempVar();
      addQuadruple("uminus", "", $2, T);
      $$ = strdup(T);
      free($2);
    }
  | LPAREN expr RPAREN
    { $$ = $2; }
  | NUM
    {
      char buf[20];
      sprintf(buf,"%d",$1);
      $$ = strdup(buf);
    }
  | INTCONST
    {
      char *T = tempVar(), buf[32];
      sprintf(buf,"(%d,10)",$1);
      addQuadruple(buf,"","",T);
      $$ = strdup(T);
    }
  | CHARCONST
    {
      char *T = tempVar(), buf[4];
      sprintf(buf,"'%c'",(char)$1);
      addQuadruple(buf,"","",T);
      $$ = strdup(T);
    }
  | ID
    {
      int i = lookupSymbol($1);
      if (i < 0)            yyerror("undeclared var");
      if (!symtab[i].init) yyerror("uninitialized var");
      $$ = strdup($1);
      free($1);
    }
  ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error: %s\n", s);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <infile>\n", argv[0]);
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if (!yyin) { perror("open"); return 1; }
    yyparse();
    fclose(yyin);
    return 0;
}
