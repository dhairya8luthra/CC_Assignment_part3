/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "proj3.y"

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

#line 141 "proj3.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "proj3.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BEGIN_KEY = 3,                  /* BEGIN_KEY  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_PROGRAM = 5,                    /* PROGRAM  */
  YYSYMBOL_VARDECL = 6,                    /* VARDECL  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_DO = 13,                        /* DO  */
  YYSYMBOL_TO = 14,                        /* TO  */
  YYSYMBOL_INC = 15,                       /* INC  */
  YYSYMBOL_DEC = 16,                       /* DEC  */
  YYSYMBOL_PRINT = 17,                     /* PRINT  */
  YYSYMBOL_SCAN = 18,                      /* SCAN  */
  YYSYMBOL_ASSIGNOP = 19,                  /* ASSIGNOP  */
  YYSYMBOL_ADDOP = 20,                     /* ADDOP  */
  YYSYMBOL_SUBOP = 21,                     /* SUBOP  */
  YYSYMBOL_MULOP = 22,                     /* MULOP  */
  YYSYMBOL_DIVOP = 23,                     /* DIVOP  */
  YYSYMBOL_MODOP = 24,                     /* MODOP  */
  YYSYMBOL_RELOP = 25,                     /* RELOP  */
  YYSYMBOL_LPAREN = 26,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 27,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 28,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 29,                  /* RBRACKET  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 31,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 32,                     /* COLON  */
  YYSYMBOL_ID = 33,                        /* ID  */
  YYSYMBOL_STRCONST = 34,                  /* STRCONST  */
  YYSYMBOL_NUM = 35,                       /* NUM  */
  YYSYMBOL_INTCONST = 36,                  /* INTCONST  */
  YYSYMBOL_CHARCONST = 37,                 /* CHARCONST  */
  YYSYMBOL_INDEX = 38,                     /* INDEX  */
  YYSYMBOL_UMINUS = 39,                    /* UMINUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 40,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_var_decl_block = 43,            /* var_decl_block  */
  YYSYMBOL_varlist = 44,                   /* varlist  */
  YYSYMBOL_var_decl = 45,                  /* var_decl  */
  YYSYMBOL_type = 46,                      /* type  */
  YYSYMBOL_stmt_block = 47,                /* stmt_block  */
  YYSYMBOL_stmt = 48,                      /* stmt  */
  YYSYMBOL_assign_stmt = 49,               /* assign_stmt  */
  YYSYMBOL_io_stmt = 50,                   /* io_stmt  */
  YYSYMBOL_print_stmt = 51,                /* print_stmt  */
  YYSYMBOL_print_args = 52,                /* print_args  */
  YYSYMBOL_scan_stmt = 53,                 /* scan_stmt  */
  YYSYMBOL_scan_fmt = 54,                  /* scan_fmt  */
  YYSYMBOL_scan_args = 55,                 /* scan_args  */
  YYSYMBOL_cond_stmt = 56,                 /* cond_stmt  */
  YYSYMBOL_loop_stmt = 57,                 /* loop_stmt  */
  YYSYMBOL_while_stmt = 58,                /* while_stmt  */
  YYSYMBOL_for_stmt = 59,                  /* for_stmt  */
  YYSYMBOL_for_setup = 60,                 /* for_setup  */
  YYSYMBOL_block = 61,                     /* block  */
  YYSYMBOL_expr = 62                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   184

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    95,    95,   104,   108,   109,   113,   115,   117,   122,
     123,   127,   128,   132,   133,   134,   135,   136,   140,   149,
     150,   154,   156,   161,   162,   166,   171,   175,   176,   180,
     192,   202,   203,   207,   220,   232,   256,   260,   267,   274,
     281,   289,   296,   303,   310,   312,   318,   325,   332
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BEGIN_KEY", "END",
  "PROGRAM", "VARDECL", "INT", "CHAR", "IF", "ELSE", "WHILE", "FOR", "DO",
  "TO", "INC", "DEC", "PRINT", "SCAN", "ASSIGNOP", "ADDOP", "SUBOP",
  "MULOP", "DIVOP", "MODOP", "RELOP", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "COMMA", "SEMICOLON", "COLON", "ID", "STRCONST", "NUM",
  "INTCONST", "CHARCONST", "INDEX", "UMINUS", "LOWER_THAN_ELSE", "$accept",
  "program", "var_decl_block", "varlist", "var_decl", "type", "stmt_block",
  "stmt", "assign_stmt", "io_stmt", "print_stmt", "print_args",
  "scan_stmt", "scan_fmt", "scan_args", "cond_stmt", "loop_stmt",
  "while_stmt", "for_stmt", "for_setup", "block", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-49)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,    -2,    15,    10,   -49,    41,    26,    40,    24,    40,
      35,    37,    48,    56,    58,    80,    13,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,    87,   -49,    75,    36,
      29,    29,    96,   110,   111,    29,   118,   -49,   128,   114,
       0,   -49,   -49,    29,    29,   -49,   -49,   -49,   -49,    89,
      97,    29,   -19,   -49,   116,    54,   -49,   117,   -21,   143,
     -49,   -49,   105,    29,    29,    29,    29,    29,    29,   128,
     137,    66,   120,    29,   121,   -49,   -49,   -18,    60,   -49,
     -49,     5,     5,   -49,   -49,   -49,   119,    -8,   128,    29,
     -49,   125,    72,   123,   129,   126,   130,   -49,   -49,   131,
     128,   -49,   132,    83,   133,    29,   121,   134,   127,   136,
     138,   139,   -49,    29,   -49,   -49,   -49,   -49,    60,    60,
     -49,   -49,   113,   135,   140,   141,   142,   -49,   -49
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,    13,    14,
      19,    20,    15,    16,    31,    32,     0,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     5,    36,     0,     0,    48,    45,    46,    47,     0,
       0,     0,     0,    26,     0,     0,     2,     0,     0,     0,
       4,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    34,     0,     0,     3,
      44,    37,    38,    39,    40,    41,    42,     0,     0,     0,
      21,     0,    23,    27,     0,     0,     0,     9,    10,     0,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,    22,    24,    28,    25,     0,     0,
       6,    29,    35,     0,     0,     0,     0,     7,     8
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -49,   -49,   -49,   -49,   144,   -48,   151,   -10,   -49,   -49,
     -49,    63,   -49,   -49,    55,   -49,   -49,   -49,   -49,   -49,
     -28,   -30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,    40,    41,    99,    16,    17,    18,    19,
      20,    91,    21,    54,    94,    22,    23,    24,    25,    26,
      27,    92
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      49,    50,   100,     3,    59,    55,    37,    77,    72,    78,
      57,    73,     1,    61,    62,     4,     9,    36,    95,    37,
      96,    71,    10,   101,    11,    12,    39,    65,    66,    67,
      13,    14,     8,    81,    82,    83,    84,    85,    86,     9,
      42,    87,     5,     9,     6,    10,    15,    11,    12,    10,
      43,    11,    12,    13,    14,    44,    28,    13,    14,   103,
     102,    30,    45,    31,    46,    47,    48,    97,    98,    15,
     123,   124,   111,    15,    63,    64,    65,    66,    67,    68,
      89,    32,    33,   122,    34,    75,    63,    64,    65,    66,
      67,    68,    63,    64,    65,    66,    67,    68,   113,    35,
      38,    39,   105,    63,    64,    65,    66,    67,    68,    63,
      64,    65,    66,    67,    68,    51,    69,    63,    64,    65,
      66,    67,    68,    56,    70,    63,    64,    65,    66,    67,
      68,     9,    80,    63,    64,    65,    66,    67,    68,    63,
      64,    65,    66,    67,    52,    53,    74,    58,    76,    79,
      88,    90,   104,   106,    93,   108,   107,   118,   110,   109,
      29,   116,   125,   112,   114,   117,   119,   126,   115,   120,
     121,     0,   127,   128,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60
};

static const yytype_int8 yycheck[] =
{
      30,    31,    10,     5,     4,    35,    16,    28,    27,    30,
      38,    30,     3,    43,    44,     0,     3,     4,    36,    29,
      38,    51,     9,    31,    11,    12,    26,    22,    23,    24,
      17,    18,     6,    63,    64,    65,    66,    67,    68,     3,
       4,    69,    32,     3,     3,     9,    33,    11,    12,     9,
      21,    11,    12,    17,    18,    26,    32,    17,    18,    89,
      88,    26,    33,    26,    35,    36,    37,     7,     8,    33,
     118,   119,   100,    33,    20,    21,    22,    23,    24,    25,
      14,    33,    26,   113,    26,    31,    20,    21,    22,    23,
      24,    25,    20,    21,    22,    23,    24,    25,    15,    19,
      13,    26,    30,    20,    21,    22,    23,    24,    25,    20,
      21,    22,    23,    24,    25,    19,    27,    20,    21,    22,
      23,    24,    25,     5,    27,    20,    21,    22,    23,    24,
      25,     3,    27,    20,    21,    22,    23,    24,    25,    20,
      21,    22,    23,    24,    34,    34,    30,    33,    31,     6,
      13,    31,    27,    30,    33,    29,    27,    30,    27,    29,
       9,   106,    27,    31,    31,    31,    30,    27,   105,    31,
      31,    -1,    31,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    42,     5,     0,    32,     3,    43,     6,     3,
       9,    11,    12,    17,    18,    33,    47,    48,    49,    50,
      51,    53,    56,    57,    58,    59,    60,    61,    32,    47,
      26,    26,    33,    26,    26,    19,     4,    48,    13,    26,
      44,    45,     4,    21,    26,    33,    35,    36,    37,    62,
      62,    19,    34,    34,    54,    62,     5,    61,    33,     4,
      45,    62,    62,    20,    21,    22,    23,    24,    25,    27,
      27,    62,    27,    30,    30,    31,    31,    28,    30,     6,
      27,    62,    62,    62,    62,    62,    62,    61,    13,    14,
      31,    52,    62,    33,    55,    36,    38,     7,     8,    46,
      10,    31,    61,    62,    27,    30,    30,    27,    29,    29,
      27,    61,    31,    15,    31,    52,    55,    31,    30,    30,
      31,    31,    62,    46,    46,    27,    27,    31,    31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    44,    44,    45,    45,    45,    46,
      46,    47,    47,    48,    48,    48,    48,    48,    49,    50,
      50,    51,    51,    52,    52,    53,    54,    55,    55,    56,
      56,    57,    57,    58,    59,    60,    61,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     6,     2,     1,     6,     9,     9,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     5,     7,     1,     3,     7,     1,     1,     3,     8,
       6,     1,     1,     7,     4,     8,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: BEGIN_KEY PROGRAM COLON var_decl_block stmt_block END PROGRAM  */
#line 96 "proj3.y"
    {
      printf("Successfully parsed !!!\n");
      displayQuadruple();
      printSymbolTable();
    }
#line 1280 "proj3.tab.c"
    break;

  case 6: /* var_decl: LPAREN ID COMMA type RPAREN SEMICOLON  */
#line 114 "proj3.y"
    { insertSymbol((yyvsp[-4].sval), (yyvsp[-2].sval)); free((yyvsp[-4].sval)); free((yyvsp[-2].sval)); }
#line 1286 "proj3.tab.c"
    break;

  case 7: /* var_decl: LPAREN ID LBRACKET INTCONST RBRACKET COMMA type RPAREN SEMICOLON  */
#line 116 "proj3.y"
    { insertSymbol((yyvsp[-7].sval), (yyvsp[-2].sval)); free((yyvsp[-7].sval)); free((yyvsp[-2].sval)); }
#line 1292 "proj3.tab.c"
    break;

  case 8: /* var_decl: LPAREN ID LBRACKET INDEX RBRACKET COMMA type RPAREN SEMICOLON  */
#line 118 "proj3.y"
    { insertSymbol((yyvsp[-7].sval), (yyvsp[-2].sval)); free((yyvsp[-7].sval)); free((yyvsp[-2].sval)); }
#line 1298 "proj3.tab.c"
    break;

  case 9: /* type: INT  */
#line 122 "proj3.y"
         { (yyval.sval) = strdup("int"); }
#line 1304 "proj3.tab.c"
    break;

  case 10: /* type: CHAR  */
#line 123 "proj3.y"
         { (yyval.sval) = strdup("char"); }
#line 1310 "proj3.tab.c"
    break;

  case 18: /* assign_stmt: ID ASSIGNOP expr SEMICOLON  */
#line 141 "proj3.y"
    {
      addQuadruple((yyvsp[-1].sval), "", "", (yyvsp[-3].sval));
      updateSymbol((yyvsp[-3].sval), atoi((yyvsp[-1].sval)));
      free((yyvsp[-3].sval)); free((yyvsp[-1].sval));
    }
#line 1320 "proj3.tab.c"
    break;

  case 21: /* print_stmt: PRINT LPAREN STRCONST RPAREN SEMICOLON  */
#line 155 "proj3.y"
    { addQuadruple("", "print", (yyvsp[-2].sval), ""); free((yyvsp[-2].sval)); }
#line 1326 "proj3.tab.c"
    break;

  case 22: /* print_stmt: PRINT LPAREN STRCONST COMMA print_args RPAREN SEMICOLON  */
#line 157 "proj3.y"
    { addQuadruple("", "print", (yyvsp[-4].sval), (yyvsp[-2].sval)); free((yyvsp[-4].sval)); free((yyvsp[-2].sval)); }
#line 1332 "proj3.tab.c"
    break;

  case 23: /* print_args: expr  */
#line 161 "proj3.y"
                         { (yyval.sval) = (yyvsp[0].sval); }
#line 1338 "proj3.tab.c"
    break;

  case 24: /* print_args: expr COMMA print_args  */
#line 162 "proj3.y"
                         { free((yyvsp[0].sval)); (yyval.sval) = (yyvsp[-2].sval); }
#line 1344 "proj3.tab.c"
    break;

  case 25: /* scan_stmt: SCAN LPAREN scan_fmt COMMA scan_args RPAREN SEMICOLON  */
#line 167 "proj3.y"
    { addQuadruple("", "scan", (yyvsp[-4].sval), ""); free((yyvsp[-4].sval)); }
#line 1350 "proj3.tab.c"
    break;

  case 26: /* scan_fmt: STRCONST  */
#line 171 "proj3.y"
             { (yyval.sval) = (yyvsp[0].sval); }
#line 1356 "proj3.tab.c"
    break;

  case 27: /* scan_args: ID  */
#line 175 "proj3.y"
                       { free((yyvsp[0].sval)); }
#line 1362 "proj3.tab.c"
    break;

  case 28: /* scan_args: ID COMMA scan_args  */
#line 176 "proj3.y"
                       { free((yyvsp[-2].sval)); free((yyvsp[0].sval)); }
#line 1368 "proj3.tab.c"
    break;

  case 29: /* cond_stmt: IF LPAREN expr RPAREN block ELSE block SEMICOLON  */
#line 181 "proj3.y"
      {
        elseLab = newLabel();
        endLab  = newLabel();
        addQuadruple((yyvsp[-5].sval),"iffalse","",elseLab);
        free((yyvsp[-5].sval));
        /* after then: skip over else */
        addQuadruple("", "goto", "", endLab);
        addQuadruple("", "label", "", elseLab);
        /* else‐block code was just emitted */
        addQuadruple("", "label", "", endLab);
      }
#line 1384 "proj3.tab.c"
    break;

  case 30: /* cond_stmt: IF LPAREN expr RPAREN block SEMICOLON  */
#line 193 "proj3.y"
      {
        elseLab = newLabel();
        addQuadruple((yyvsp[-3].sval),"iffalse","",elseLab);
        free((yyvsp[-3].sval));
        addQuadruple("", "label", "", elseLab);
      }
#line 1395 "proj3.tab.c"
    break;

  case 33: /* while_stmt: WHILE LPAREN expr RPAREN DO block SEMICOLON  */
#line 208 "proj3.y"
    {
      char *L1 = newLabel(), *L2 = newLabel();
      addQuadruple("", "label", "", L1);
      addQuadruple((yyvsp[-4].sval), "iffalse", "", L2);
      free((yyvsp[-4].sval));
      /* body already emitted */
      addQuadruple("", "goto", "", L1);
      addQuadruple("", "label", "", L2);
    }
#line 1409 "proj3.tab.c"
    break;

  case 34: /* for_stmt: for_setup DO block SEMICOLON  */
#line 221 "proj3.y"
    {
      /* after body: increment, back to head, exit label */
      addQuadruple(for_inc_val, "", "", for_var_name);
      addQuadruple("", "goto", "", for_head);
      addQuadruple("", "label", "", for_exit);
      free(for_var_name);
      free(for_inc_val);
    }
#line 1422 "proj3.tab.c"
    break;

  case 35: /* for_setup: FOR ID ASSIGNOP expr TO expr INC expr  */
#line 233 "proj3.y"
    {
      /* save for the closing action */
      for_var_name = (yyvsp[-6].sval);
      for_inc_val   = (yyvsp[0].sval);
      /* init loop var */
      addQuadruple((yyvsp[-4].sval), "", "", (yyvsp[-6].sval));
      updateSymbol((yyvsp[-6].sval), atoi((yyvsp[-4].sval)));
      /* labels */
      for_head = newLabel();
      for_exit = newLabel();
      /* head label */
      addQuadruple("", "label", "", for_head);
      /* test: tX = ID > upper */
      {
        char *T = tempVar();
        addQuadruple((yyvsp[-6].sval), ">", (yyvsp[-2].sval), T);
        addQuadruple(T, "iffalse", "", for_exit);
      }
      free((yyvsp[-4].sval)); free((yyvsp[-2].sval));
    }
#line 1447 "proj3.tab.c"
    break;

  case 37: /* expr: expr ADDOP expr  */
#line 261 "proj3.y"
    {
      char *T = tempVar();
      addQuadruple((yyvsp[-2].sval), "+", (yyvsp[0].sval), T);
      (yyval.sval) = strdup(T);
      free((yyvsp[-2].sval)); free((yyvsp[0].sval));
    }
#line 1458 "proj3.tab.c"
    break;

  case 38: /* expr: expr SUBOP expr  */
#line 268 "proj3.y"
    {
      char *T = tempVar();
      addQuadruple((yyvsp[-2].sval), "-", (yyvsp[0].sval), T);
      (yyval.sval) = strdup(T);
      free((yyvsp[-2].sval)); free((yyvsp[0].sval));
    }
#line 1469 "proj3.tab.c"
    break;

  case 39: /* expr: expr MULOP expr  */
#line 275 "proj3.y"
    {
      char *T = tempVar();
      addQuadruple((yyvsp[-2].sval), "*", (yyvsp[0].sval), T);
      (yyval.sval) = strdup(T);
      free((yyvsp[-2].sval)); free((yyvsp[0].sval));
    }
#line 1480 "proj3.tab.c"
    break;

  case 40: /* expr: expr DIVOP expr  */
#line 282 "proj3.y"
    {
      if (!atoi((yyvsp[0].sval))) yyerror("division by zero");
      char *T = tempVar();
      addQuadruple((yyvsp[-2].sval), "/", (yyvsp[0].sval), T);
      (yyval.sval) = strdup(T);
      free((yyvsp[-2].sval)); free((yyvsp[0].sval));
    }
#line 1492 "proj3.tab.c"
    break;

  case 41: /* expr: expr MODOP expr  */
#line 290 "proj3.y"
    {
      char *T = tempVar();
      addQuadruple((yyvsp[-2].sval), "mod", (yyvsp[0].sval), T);
      (yyval.sval) = strdup(T);
      free((yyvsp[-2].sval)); free((yyvsp[0].sval));
    }
#line 1503 "proj3.tab.c"
    break;

  case 42: /* expr: expr RELOP expr  */
#line 297 "proj3.y"
    {
      char *T = tempVar();
      addQuadruple((yyvsp[-2].sval), (yyvsp[-1].sval), (yyvsp[0].sval), T);
      (yyval.sval) = strdup(T);
      free((yyvsp[-2].sval)); free((yyvsp[0].sval)); free((yyvsp[-1].sval));
    }
#line 1514 "proj3.tab.c"
    break;

  case 43: /* expr: SUBOP expr  */
#line 304 "proj3.y"
    {
      char *T = tempVar();
      addQuadruple("uminus", "", (yyvsp[0].sval), T);
      (yyval.sval) = strdup(T);
      free((yyvsp[0].sval));
    }
#line 1525 "proj3.tab.c"
    break;

  case 44: /* expr: LPAREN expr RPAREN  */
#line 311 "proj3.y"
    { (yyval.sval) = (yyvsp[-1].sval); }
#line 1531 "proj3.tab.c"
    break;

  case 45: /* expr: NUM  */
#line 313 "proj3.y"
    {
      char buf[20];
      sprintf(buf,"%d",(yyvsp[0].ival));
      (yyval.sval) = strdup(buf);
    }
#line 1541 "proj3.tab.c"
    break;

  case 46: /* expr: INTCONST  */
#line 319 "proj3.y"
    {
      char *T = tempVar(), buf[32];
      sprintf(buf,"(%d,10)",(yyvsp[0].ival));
      addQuadruple(buf,"","",T);
      (yyval.sval) = strdup(T);
    }
#line 1552 "proj3.tab.c"
    break;

  case 47: /* expr: CHARCONST  */
#line 326 "proj3.y"
    {
      char *T = tempVar(), buf[4];
      sprintf(buf,"'%c'",(char)(yyvsp[0].ival));
      addQuadruple(buf,"","",T);
      (yyval.sval) = strdup(T);
    }
#line 1563 "proj3.tab.c"
    break;

  case 48: /* expr: ID  */
#line 333 "proj3.y"
    {
      int i = lookupSymbol((yyvsp[0].sval));
      if (i < 0)            yyerror("undeclared var");
      if (!symtab[i].init) yyerror("uninitialized var");
      (yyval.sval) = strdup((yyvsp[0].sval));
      free((yyvsp[0].sval));
    }
#line 1575 "proj3.tab.c"
    break;


#line 1579 "proj3.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 342 "proj3.y"


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
