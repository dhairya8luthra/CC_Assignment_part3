/* proj3.y - Corrected Version */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"

static char *while_start, *while_exit;
static char *for_var_name = NULL, *for_inc_val = NULL, *for_head = NULL, *for_exit = NULL, *for_bound = NULL;
static int for_is_inc = 0;


static char *makeBinary(const char *l, const char *op, const char *r)
{
    size_t L = strlen(l) + strlen(op) + strlen(r) + 3; /* 2 spaces + NUL */
    char *buf = (char *)malloc(L);
    sprintf(buf, "%s %s %s", l, op, r);
    return buf;
}
/* build the decimal text of an integer and return strdup’ed copy       */
static char *intToStr(int v)
{
    char tmp[32];
    sprintf(tmp, "%d", v);
    return strdup(tmp);
}


/* --- 3AC storage --- */
int qind = 0;
struct quadruple {
    char op[8], a1[40], a2[40], res[40];
} quad[200];

void addQuadruple(const char *x, const char *o, const char *y, const char *r){
    strcpy(quad[qind].op,  o);
    strcpy(quad[qind].a1, x);
    strcpy(quad[qind].a2, y);
    strcpy(quad[qind].res, r);
    qind++;
}

/* --- temp vars and labels --- */
int tempCount = 1, condCount = 1, lblCount = 1;
static char *elseLab, *endLab;
char* tempVar(){
    char buf[20];
    sprintf(buf, "t%d", tempCount++);
    return strdup(buf);
}

char* condVar(){
    char buf[20];
    sprintf(buf, "t_cond%d", condCount++);
    return strdup(buf);
}

char* newLabel(){
    char buf[20];
    sprintf(buf, "L%d", lblCount++);
    return strdup(buf);
}

/* --- display 3AC in required format --- */
void displayQuadruple(){
    printf("\n--- Three Address Code ---\n");
    int lastWasLabel = 0;
    for(int i=0;i<qind;i++){
        char *op=quad[i].op, *a1=quad[i].a1, *a2=quad[i].a2, *r=quad[i].res;

        if (!strcmp(op,"label")) {
            if (i != 0) printf("\n");
            printf("%s:\n", r);
            lastWasLabel = 1;
            continue;
        }

        if (lastWasLabel) {
            printf("\n");
            lastWasLabel = 0;
        }

        printf("  ");

        if (!strcmp(op,"iffalse"))
            printf("if %s := 0 goto %s\n", a1, r);
        else if (!strcmp(op,"iftrue"))
            printf("if %s == 1 goto %s\n", a1, r);
        else if (!strcmp(op,"goto"))
            printf("goto %s\n", r);
        else if (!strcmp(op,""))
            printf("%s := %s\n", r, a1);
        else
            printf("%s := %s %s %s\n", r, a1, op, a2);
    }
    printf("\n");
}

static char *for_inc_temp = NULL;


/* --- tuple formatting helper --- */
static int parseLiteral(const char *lit) {
    char valstr[32], basestr[8];
    int i = 0;
    const char *p = lit + 1;
    while (*p != ',' && *p) valstr[i++] = *p++;
    valstr[i] = '\0';
    while (*p && (*p == ',' || *p == ' ')) ++p;
    i = 0;
    while (*p && *p != ')') basestr[i++] = *p++;
    basestr[i] = '\0';
    int base = atoi(basestr);
    return (int)strtol(valstr, NULL, base);
}

extern FILE *yyin;
extern int yylex(void);
void yyerror(const char *s);
%}

%union {
    int    ival;
    struct {int value,base;}iconst;
    char*  sval;
}



%token <sval> BEGIN_KEY END PROGRAM VARDECL INT CHAR
%token <sval> IF ELSE WHILE FOR DO TO INC DEC
%token <sval> PRINT SCAN ASSIGNOP ADDOP SUBOP MULOP DIVOP MODOP RELOP
%token <sval> LPAREN RPAREN LBRACKET RBRACKET COMMA SEMICOLON COLON
%token <sval> ID STRCONST
%token <ival> NUM CHARCONST INDEX
%token <iconst> INTCONST



%type <sval> program var_decl_block varlist var_decl type
%type <sval> stmt_block stmt assign_stmt bound_expr io_stmt print_stmt scan_stmt print_args scan_fmt scan_args cond_stmt loop_stmt while_stmt for_stmt for_setup block expr




%left RELOP
%left ADDOP SUBOP
%left MULOP DIVOP MODOP
%nonassoc UMINUS LOWER_THAN_ELSE BOUND_PREC
%right ASSIGNOP  

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
  : SCAN LPAREN scan_fmt RPAREN SEMICOLON
    { addQuadruple("", "scan", $3, ""); free($3); }
  | SCAN LPAREN scan_fmt COMMA scan_args RPAREN SEMICOLON
    { addQuadruple("", "scan", $3, $5); free($3); free($5); }
  ;

scan_fmt
  : STRCONST
    { $$ = $1; }
  ;

scan_args
  : ID
    { $$ = $1; }
  | ID COMMA scan_args
    {
      size_t L = strlen($1) + 2 + strlen($3) + 1;
      char *buf = malloc(L);
      sprintf(buf, "%s, %s", $1, $3);
      free($1);
      free($3);
      $$ = buf;
    }
  ;

cond_stmt
  : IF LPAREN bound_expr RPAREN
      {
        elseLab = newLabel();
        endLab  = newLabel();
        char *Tcond = condVar();
        addQuadruple($3, "", "", Tcond);
        addQuadruple(Tcond, "iffalse", "", elseLab);
        free($3);
      }
    block
      {
        addQuadruple("", "goto", "", endLab);
        addQuadruple("", "label", "", elseLab);
      }
    ELSE
    block SEMICOLON
      {
        addQuadruple("", "label", "", endLab);
      }
  ;

loop_stmt
  : while_stmt
  | for_stmt
  ;

while_stmt
  : WHILE LPAREN bound_expr RPAREN
      {
        while_start = newLabel();
        while_exit  = newLabel();
        addQuadruple("", "label", "", while_start);
        char *Tcond = condVar();
        addQuadruple($3, "", "", Tcond);
        addQuadruple(Tcond, "iffalse", "", while_exit);
        free($3);
      }
    DO block SEMICOLON
      {
        addQuadruple("", "goto",  "", while_start);
        addQuadruple("", "label", "", while_exit);
      }
  ;

for_stmt
  : for_setup DO block SEMICOLON
    {
      char *Tupd = tempVar();
      if (for_is_inc) {
        addQuadruple(for_var_name, "+", for_inc_temp, Tupd);
      } else {
        addQuadruple(for_var_name, "-", for_inc_temp, Tupd);
      }
      addQuadruple(Tupd, "", "", for_var_name);
      addQuadruple("", "goto", "", for_head);
      addQuadruple("", "label", "", for_exit);
      free(for_var_name);
      free(for_inc_val);
      free(for_head);
      free(for_exit);
      free(for_bound);
    }
  ;

/* ---------- for-loop (incrementing) ---------- */
for_setup
  : FOR ID ASSIGNOP expr TO bound_expr INC expr
      {         


        /* 1. initialise loop variable */
        addQuadruple($4, "", "", $2);
        updateSymbol($2, atoi($4));

        /* 2. create the head label before the bound is parsed */
        for_head = newLabel();
        addQuadruple("", "label", "", for_head);

        /* 3. remember info we still need */
        for_var_name = $2;
        for_is_inc   = 1;
      
 // SAVE it globally for later use

        for_bound   = $6;
        for_inc_val = $8;
        for_exit    = newLabel();

        /* evaluate (possibly changed) bound each iteration */
        char *Tbound = tempVar();
        addQuadruple($6, "", "", Tbound);

        char *IncOp = tempVar();
for_inc_temp = IncOp; 
        
        addQuadruple($8, "", "", IncOp);

        char *Tcond = condVar();
        addQuadruple($2, ">", Tbound, Tcond);    /* termination test   */
        addQuadruple(Tcond, "iffalse", "", for_exit);
      }

/* ---------- for-loop (decrementing) ---------- */
  | FOR ID ASSIGNOP expr TO expr DEC expr
      {                           /* ← same idea for DEC case */
        addQuadruple($4, "", "", $2);
        updateSymbol($2, atoi($4));

        for_head = newLabel();
        addQuadruple("", "label", "", for_head);

        for_var_name = $2;
        for_is_inc   = 0;
  
        for_bound   = $6;
        for_inc_val = $8;
        for_exit    = newLabel();

        char *Tbound = tempVar();
        addQuadruple($6, "", "", Tbound);

        char *Tcond = condVar();
        addQuadruple($2, "<", Tbound, Tcond);
        addQuadruple(Tcond, "iffalse", "", for_exit);
      }
  ;

  block
  : BEGIN_KEY stmt_block END
  ;

bound_expr
  : bound_expr ADDOP bound_expr %prec BOUND_PREC
      { $$ = makeBinary($1, "+", $3);  free($1); free($3); }
  | bound_expr SUBOP bound_expr %prec BOUND_PREC
      { $$ = makeBinary($1, "-", $3);  free($1); free($3); }
  | bound_expr MULOP bound_expr %prec BOUND_PREC
      { $$ = makeBinary($1, "*", $3);  free($1); free($3); }
  | bound_expr DIVOP bound_expr %prec BOUND_PREC
      { $$ = makeBinary($1, "/", $3);  free($1); free($3); }
  | bound_expr MODOP bound_expr %prec BOUND_PREC
      { $$ = makeBinary($1, "mod", $3); free($1); free($3); }

  | bound_expr RELOP bound_expr %prec BOUND_PREC
      { $$ = makeBinary($1, $2, $3);   free($1); free($2); free($3); }

  | SUBOP bound_expr %prec UMINUS 
      { $$ = makeBinary("uminus", "", $2);        free($2); }

  | LPAREN bound_expr RPAREN     { $$ = $2; }

  | NUM                        { $$ = intToStr($1); }

  | INTCONST 
      
    {
      /* keep the original (value, base) text */
      char buf[32];
      sprintf(buf, "(%d, %d)", $1.value, $1.base);
      $$ = strdup(buf);
    }


  | CHARCONST
      {
        char tmp[4];
        sprintf(tmp, "'%c'", (char)$1);
        $$ = strdup(tmp);
      }

  | ID 
      {
        int i = lookupSymbol($1);
        if (i < 0) yyerror("undeclared var");
        if (!symtab[i].init) yyerror("uninitialized var");
        $$ = strdup($1);
        free($1);
      }
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
      char *T = condVar();
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
      char buf[32];
      sprintf(buf, "(%d, %d)", $1.value, $1.base);
      $$ = strdup(buf);
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
      if (i < 0) yyerror("undeclared var");
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