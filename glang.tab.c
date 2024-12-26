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
#line 1 "glang.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>
#include "glang.h"

extern FILE *yyin;
extern int yylex();
extern void yyrestart(FILE *input_file);

void yyerror(const char *s);
volatile sig_atomic_t canJump = 0;

/* Set to 1 once "env" buffer has been
   initialized by [sig]setjmp() */
  static jmp_buf env;



#line 93 "glang.tab.c"

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

#include "glang.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VAR = 3,                        /* VAR  */
  YYSYMBOL_INT_VAL = 4,                    /* INT_VAL  */
  YYSYMBOL_FLOAT_VAL = 5,                  /* FLOAT_VAL  */
  YYSYMBOL_DOUBLE_VAL = 6,                 /* DOUBLE_VAL  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_DOUBLE = 9,                     /* DOUBLE  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_PRINT = 12,                     /* PRINT  */
  YYSYMBOL_SCAN = 13,                      /* SCAN  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_LPAREN = 15,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 16,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 17,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 18,                    /* RBRACE  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 20,                 /* SEMICOLON  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_MODULO = 22,                    /* MODULO  */
  YYSYMBOL_IFX = 23,                       /* IFX  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_PLUS = 25,                      /* PLUS  */
  YYSYMBOL_MINUS = 26,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 27,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 28,                    /* DIVIDE  */
  YYSYMBOL_EQUAL = 29,                     /* EQUAL  */
  YYSYMBOL_NOTEQUAL = 30,                  /* NOTEQUAL  */
  YYSYMBOL_LESSEQUAL = 31,                 /* LESSEQUAL  */
  YYSYMBOL_GREATEREQUAL = 32,              /* GREATEREQUAL  */
  YYSYMBOL_LESS = 33,                      /* LESS  */
  YYSYMBOL_GREATER = 34,                   /* GREATER  */
  YYSYMBOL_UMINUS = 35,                    /* UMINUS  */
  YYSYMBOL_FUNCTION = 36,                  /* FUNCTION  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_program = 38,                   /* program  */
  YYSYMBOL_function = 39,                  /* function  */
  YYSYMBOL_function_call = 40,             /* function_call  */
  YYSYMBOL_expr_list = 41,                 /* expr_list  */
  YYSYMBOL_type = 42,                      /* type  */
  YYSYMBOL_stmt = 43,                      /* stmt  */
  YYSYMBOL_block_stmt = 44,                /* block_stmt  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_stmt_list = 46,                 /* stmt_list  */
  YYSYMBOL_scan_statement = 47,            /* scan_statement  */
  YYSYMBOL_print_statement = 48,           /* print_statement  */
  YYSYMBOL_assignment = 49,                /* assignment  */
  YYSYMBOL_declaration = 50,               /* declaration  */
  YYSYMBOL_function_declaration = 51,      /* function_declaration  */
  YYSYMBOL_block_stmt_func = 52,           /* block_stmt_func  */
  YYSYMBOL_parameter_list = 53,            /* parameter_list  */
  YYSYMBOL_while_statement = 54,           /* while_statement  */
  YYSYMBOL_if_statement = 55,              /* if_statement  */
  YYSYMBOL_expr = 56                       /* expr  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    64,    66,    70,    77,    81,    87,    88,
      89,    92,    94,    96,    98,   100,   102,   104,   106,   108,
     113,   112,   126,   128,   131,   134,   138,   141,   145,   149,
     153,   159,   165,   171,   173,   178,   183,   188,   193,   198,
     204,   208,   217,   227,   231,   233,   237,   238,   242,   246,
     250,   252,   254,   256,   258,   260,   269,   271,   273,   275,
     277,   279,   281,   285,   289,   293
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VAR", "INT_VAL",
  "FLOAT_VAL", "DOUBLE_VAL", "INT", "FLOAT", "DOUBLE", "IF", "WHILE",
  "PRINT", "SCAN", "RETURN", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "COMMA", "SEMICOLON", "ASSIGN", "MODULO", "IFX", "ELSE", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "EQUAL", "NOTEQUAL", "LESSEQUAL", "GREATEREQUAL",
  "LESS", "GREATER", "UMINUS", "FUNCTION", "$accept", "program",
  "function", "function_call", "expr_list", "type", "stmt", "block_stmt",
  "$@1", "stmt_list", "scan_statement", "print_statement", "assignment",
  "declaration", "function_declaration", "block_stmt_func",
  "parameter_list", "while_statement", "if_statement", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-97)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -97,     4,   100,   -97,    11,   -97,   -97,   -97,     8,    12,
      16,    13,    14,    42,    42,   124,   -97,   -97,    42,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   179,
      42,    42,    10,    38,    54,    42,    42,    18,   194,   209,
      34,    40,    47,   126,   100,   -97,   -97,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    35,   294,   224,
       0,   -97,    42,     5,   -97,    42,    57,   -97,    42,   145,
     164,   -97,   -97,    42,    42,    42,   -97,   -97,    75,   135,
     135,   114,   114,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
      42,   -97,   -97,   -97,   -97,    59,    86,    51,   239,    59,
      78,   254,    59,    80,   269,   100,   100,   -97,   -97,   -97,
     -97,   -97,   294,    77,   -97,   -97,    59,   115,   -97,   -97,
      59,   -97,   -97,    59,   -97,    76,   -97,    42,   -97,    99,
     -97,   -97,   100,   284,   -97,   -97,   103,   -97
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    50,    47,    48,    49,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    11,     0,    46,
       3,    19,    14,    13,    16,    15,    33,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,    51,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,    30,     0,     0,    31,     0,     0,    32,     0,     0,
       0,    25,    24,     0,     0,     0,    65,    22,     0,    52,
      53,    54,    55,    61,    60,    59,    58,    56,    57,     5,
       0,    26,     8,     9,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    63,    64,
      21,    23,     7,     0,    37,    41,     0,     0,    27,    38,
       0,    28,    39,     0,    29,    44,    43,     0,    34,     0,
      35,    36,     0,     0,    42,    45,     0,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -97,   -97,   -97,   -97,   -97,     1,   -34,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -96,    53,   -97,   -97,   -13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    19,    57,    96,    20,    21,    44,    78,
      22,    23,    24,    25,    26,   114,    97,    27,    28,    29
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,    39,    43,   119,     3,    45,   122,    92,    93,    94,
      77,    32,    92,    93,    94,    33,    95,    58,    59,    34,
     128,    99,    69,    70,   130,    60,    30,   131,    35,    36,
      61,    62,    31,    30,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,   111,    37,     5,     6,     7,    98,
      73,    89,   101,    63,    90,   104,    74,    15,    64,    65,
     107,   108,   109,    75,    92,    93,    94,   116,    18,    66,
     117,   125,   126,   102,    67,    68,   113,   112,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   115,
      15,   127,    16,   110,   120,    17,   123,   117,   135,   117,
     132,    18,   134,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,   133,    15,   100,    16,   129,   103,
      17,   137,    92,    93,    94,     0,    18,    37,     5,     6,
       7,    40,    41,    42,     0,     0,     0,     0,     0,    15,
       0,     0,    76,    51,    52,    53,    54,    55,    56,     0,
      18,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,   105,    49,    50,    51,    52,    53,    54,    55,    56,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
     106,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    46,
       0,     0,     0,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    71,     0,     0,     0,     0,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    72,
       0,     0,     0,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    91,     0,     0,     0,     0,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,   118,
       0,     0,     0,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,   121,     0,     0,     0,     0,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,   124,
       0,     0,     0,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,   136,     0,     0,     0,     0,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56
};

static const yytype_int16 yycheck[] =
{
      13,    14,    15,    99,     0,    18,   102,     7,     8,     9,
      44,     3,     7,     8,     9,     3,    16,    30,    31,     3,
     116,    16,    35,    36,   120,    15,    15,   123,    15,    15,
      20,    21,    21,    15,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    78,     3,     4,     5,     6,    62,
      16,    16,    65,    15,    19,    68,    16,    15,    20,    21,
      73,    74,    75,    16,     7,     8,     9,    16,    26,    15,
      19,   105,   106,    16,    20,    21,    17,    90,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     3,
      15,    14,    17,    18,    16,    20,    16,    19,   132,    19,
      24,    26,     3,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,   127,    15,    63,    17,   117,    66,
      20,    18,     7,     8,     9,    -1,    26,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    16,    29,    30,    31,    32,    33,    34,    -1,
      26,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    16,    27,    28,    29,    30,    31,    32,    33,    34,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    15,    17,    20,    26,    40,
      43,    44,    47,    48,    49,    50,    51,    54,    55,    56,
      15,    21,     3,     3,     3,    15,    15,     3,    56,    56,
       7,     8,     9,    56,    45,    56,    20,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    41,    56,    56,
      15,    20,    21,    15,    20,    21,    15,    20,    21,    56,
      56,    20,    20,    16,    16,    16,    16,    43,    46,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    16,
      19,    20,     7,     8,     9,    16,    42,    53,    56,    16,
      53,    56,    16,    53,    56,    16,    16,    56,    56,    56,
      18,    43,    56,    17,    52,     3,    16,    19,    20,    52,
      16,    20,    52,    16,    20,    43,    43,    14,    52,    42,
      52,    52,    24,    56,     3,    43,    20,    18
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    41,    41,    42,    42,
      42,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      45,    44,    46,    46,    47,    48,    49,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    51,    51,    51,    51,
      52,    53,    53,    54,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     1,     3,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     1,     2,     3,     3,     4,     5,     5,     5,
       3,     3,     3,     1,     6,     6,     6,     5,     5,     5,
       5,     2,     4,     5,     5,     7,     1,     1,     1,     1,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     4,     3
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: function  */
#line 61 "glang.y"
        { freeVars(); }
#line 1527 "glang.tab.c"
    break;

  case 3: /* function: function stmt  */
#line 65 "glang.y"
        { interpret((yyvsp[0].node)); freeNode((yyvsp[0].node));  }
#line 1533 "glang.tab.c"
    break;

  case 5: /* function_call: VAR LPAREN expr_list RPAREN  */
#line 71 "glang.y"
    {
        (yyval.node) = nodOper(FUNCTION, 2, nodId((yyvsp[-3].sval), OTHER_TYPE), (yyvsp[-1].node));
    }
#line 1541 "glang.tab.c"
    break;

  case 6: /* expr_list: expr  */
#line 78 "glang.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1549 "glang.tab.c"
    break;

  case 7: /* expr_list: expr_list COMMA expr  */
#line 82 "glang.y"
    {
        (yyval.node) = nodOper(COMMA, 2, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1557 "glang.tab.c"
    break;

  case 8: /* type: INT  */
#line 87 "glang.y"
            { (yyval.iVal) = INT_TYPE; }
#line 1563 "glang.tab.c"
    break;

  case 9: /* type: FLOAT  */
#line 88 "glang.y"
            { (yyval.iVal) = FLOAT_TYPE; }
#line 1569 "glang.tab.c"
    break;

  case 10: /* type: DOUBLE  */
#line 89 "glang.y"
             { (yyval.iVal) = DOUBLE_TYPE; }
#line 1575 "glang.tab.c"
    break;

  case 11: /* stmt: SEMICOLON  */
#line 93 "glang.y"
    { (yyval.node) = nodOper(SEMICOLON, 2, NULL, NULL); }
#line 1581 "glang.tab.c"
    break;

  case 12: /* stmt: expr SEMICOLON  */
#line 95 "glang.y"
    { (yyval.node) = (yyvsp[-1].node); }
#line 1587 "glang.tab.c"
    break;

  case 13: /* stmt: print_statement  */
#line 97 "glang.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1593 "glang.tab.c"
    break;

  case 14: /* stmt: scan_statement  */
#line 99 "glang.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1599 "glang.tab.c"
    break;

  case 15: /* stmt: declaration  */
#line 101 "glang.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1605 "glang.tab.c"
    break;

  case 16: /* stmt: assignment  */
#line 103 "glang.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1611 "glang.tab.c"
    break;

  case 17: /* stmt: while_statement  */
#line 105 "glang.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1617 "glang.tab.c"
    break;

  case 18: /* stmt: if_statement  */
#line 107 "glang.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1623 "glang.tab.c"
    break;

  case 19: /* stmt: block_stmt  */
#line 109 "glang.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1629 "glang.tab.c"
    break;

  case 20: /* $@1: %empty  */
#line 113 "glang.y"
    { 
        enterScope();
    }
#line 1637 "glang.tab.c"
    break;

  case 21: /* block_stmt: LBRACE $@1 stmt_list RBRACE  */
#line 120 "glang.y"
    {
       exitScope(); 
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1646 "glang.tab.c"
    break;

  case 22: /* stmt_list: stmt  */
#line 127 "glang.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1652 "glang.tab.c"
    break;

  case 23: /* stmt_list: stmt_list stmt  */
#line 129 "glang.y"
        { (yyval.node) = nodOper(SEMICOLON, 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1658 "glang.tab.c"
    break;

  case 24: /* scan_statement: SCAN expr SEMICOLON  */
#line 132 "glang.y"
        { (yyval.node) = nodOper(SCAN, 1, (yyvsp[-1].node)); }
#line 1664 "glang.tab.c"
    break;

  case 25: /* print_statement: PRINT expr SEMICOLON  */
#line 135 "glang.y"
    { (yyval.node) = nodOper(PRINT, 1, (yyvsp[-1].node)); }
#line 1670 "glang.tab.c"
    break;

  case 26: /* assignment: VAR ASSIGN expr SEMICOLON  */
#line 139 "glang.y"
    { (yyval.node) = nodOper(ASSIGN, 2, nodId((yyvsp[-3].sval),OTHER_TYPE), (yyvsp[-1].node)); }
#line 1676 "glang.tab.c"
    break;

  case 27: /* declaration: INT VAR ASSIGN expr SEMICOLON  */
#line 142 "glang.y"
    { 
        (yyval.node) = nodOper(ASSIGN, 2, nodId((yyvsp[-3].sval),INT_TYPE), (yyvsp[-1].node));
    }
#line 1684 "glang.tab.c"
    break;

  case 28: /* declaration: FLOAT VAR ASSIGN expr SEMICOLON  */
#line 146 "glang.y"
    {      
            (yyval.node) = nodOper(ASSIGN, 2, nodId((yyvsp[-3].sval),FLOAT_TYPE), (yyvsp[-1].node));
    }
#line 1692 "glang.tab.c"
    break;

  case 29: /* declaration: DOUBLE VAR ASSIGN expr SEMICOLON  */
#line 150 "glang.y"
    {
         (yyval.node) = nodOper(ASSIGN, 2, nodId((yyvsp[-3].sval),DOUBLE_TYPE), (yyvsp[-1].node));
    }
#line 1700 "glang.tab.c"
    break;

  case 30: /* declaration: INT VAR SEMICOLON  */
#line 154 "glang.y"
    {
        void*val=malloc(sizeof(int));
        *(int*)val=0;
        (yyval.node) = nodOper(ASSIGN, 2, nodId((yyvsp[-1].sval),INT_TYPE),nodCon(&val,INT_TYPE)); 
    }
#line 1710 "glang.tab.c"
    break;

  case 31: /* declaration: FLOAT VAR SEMICOLON  */
#line 160 "glang.y"
    {
       void*val=malloc(sizeof(float));
        *(float*)val=0;
        (yyval.node) = nodOper(ASSIGN, 2, nodId((yyvsp[-1].sval),FLOAT_TYPE),nodCon(&val,FLOAT_TYPE)); 
    }
#line 1720 "glang.tab.c"
    break;

  case 32: /* declaration: DOUBLE VAR SEMICOLON  */
#line 166 "glang.y"
    {
       void*val=malloc(sizeof(double));
        *(double*)val=0;
        (yyval.node) = nodOper(ASSIGN, 2, nodId((yyvsp[-1].sval),DOUBLE_TYPE),nodCon(&val, DOUBLE_TYPE)); 
    }
#line 1730 "glang.tab.c"
    break;

  case 34: /* function_declaration: INT VAR LPAREN parameter_list RPAREN block_stmt_func  */
#line 174 "glang.y"
    {
        addFunction((yyvsp[-4].sval), INT_TYPE, (yyvsp[0].node));
        (yyval.node) = NULL;  // Function declarations don't produce a value
    }
#line 1739 "glang.tab.c"
    break;

  case 35: /* function_declaration: FLOAT VAR LPAREN parameter_list RPAREN block_stmt_func  */
#line 179 "glang.y"
    {
        addFunction((yyvsp[-4].sval), FLOAT_TYPE, (yyvsp[0].node));
        (yyval.node) = NULL; 
    }
#line 1748 "glang.tab.c"
    break;

  case 36: /* function_declaration: DOUBLE VAR LPAREN parameter_list RPAREN block_stmt_func  */
#line 184 "glang.y"
    {
        addFunction((yyvsp[-4].sval), DOUBLE_TYPE, (yyvsp[0].node));
        (yyval.node) = NULL;
    }
#line 1757 "glang.tab.c"
    break;

  case 37: /* function_declaration: INT VAR LPAREN RPAREN block_stmt_func  */
#line 189 "glang.y"
    {
        addFunction((yyvsp[-3].sval), INT_TYPE, (yyvsp[0].node));
        (yyval.node) = NULL;
    }
#line 1766 "glang.tab.c"
    break;

  case 38: /* function_declaration: FLOAT VAR LPAREN RPAREN block_stmt_func  */
#line 194 "glang.y"
    {
        addFunction((yyvsp[-3].sval), FLOAT_TYPE, (yyvsp[0].node));
        (yyval.node) = NULL;
    }
#line 1775 "glang.tab.c"
    break;

  case 39: /* function_declaration: DOUBLE VAR LPAREN RPAREN block_stmt_func  */
#line 199 "glang.y"
    {
        addFunction((yyvsp[-3].sval), DOUBLE_TYPE, (yyvsp[0].node));
        (yyval.node) = NULL;
    }
#line 1784 "glang.tab.c"
    break;

  case 40: /* block_stmt_func: LBRACE RETURN expr SEMICOLON RBRACE  */
#line 205 "glang.y"
    { (yyval.node) = (yyvsp[-2].node); }
#line 1790 "glang.tab.c"
    break;

  case 41: /* parameter_list: type VAR  */
#line 209 "glang.y"
    {
        // Store parameter information in current function
        Function* func = &functionTable.functions[functionTable.count];
        func->paramTypes[func->paramCount] = (yyvsp[-1].iVal);
        strncpy(func->paramNames[func->paramCount], (yyvsp[0].sval), sizeof(func->paramNames[0]) - 1);
        func->paramCount++;
        (yyval.node) = nodId((yyvsp[0].sval), (yyvsp[-1].iVal));
    }
#line 1803 "glang.tab.c"
    break;

  case 42: /* parameter_list: parameter_list COMMA type VAR  */
#line 218 "glang.y"
    {
        Function* func = &functionTable.functions[functionTable.count];
        func->paramTypes[func->paramCount] = (yyvsp[-1].iVal);
        strncpy(func->paramNames[func->paramCount], (yyvsp[0].sval), sizeof(func->paramNames[0]) - 1);
        func->paramCount++;
        (yyval.node) = nodOper(COMMA, 2, (yyvsp[-3].node), nodId((yyvsp[0].sval), (yyvsp[-1].iVal)));
    }
#line 1815 "glang.tab.c"
    break;

  case 43: /* while_statement: WHILE LPAREN expr RPAREN stmt  */
#line 228 "glang.y"
    { (yyval.node) = nodOper(WHILE, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1821 "glang.tab.c"
    break;

  case 44: /* if_statement: IF LPAREN expr RPAREN stmt  */
#line 232 "glang.y"
    { (yyval.node) = nodOper(IF, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1827 "glang.tab.c"
    break;

  case 45: /* if_statement: IF LPAREN expr RPAREN stmt ELSE stmt  */
#line 234 "glang.y"
    { (yyval.node) = nodOper(IF, 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1833 "glang.tab.c"
    break;

  case 46: /* expr: function_call  */
#line 237 "glang.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1839 "glang.tab.c"
    break;

  case 47: /* expr: INT_VAL  */
#line 239 "glang.y"
    {   
        (yyval.node) = nodCon(&(yyvsp[0].iVal),INT_TYPE); 
    }
#line 1847 "glang.tab.c"
    break;

  case 48: /* expr: FLOAT_VAL  */
#line 243 "glang.y"
    { 
        (yyval.node) = nodCon(&(yyvsp[0].fVal),FLOAT_TYPE); 
    }
#line 1855 "glang.tab.c"
    break;

  case 49: /* expr: DOUBLE_VAL  */
#line 247 "glang.y"
    { 
        (yyval.node) = nodCon(&(yyvsp[0].dVal),DOUBLE_TYPE); 
    }
#line 1863 "glang.tab.c"
    break;

  case 50: /* expr: VAR  */
#line 251 "glang.y"
    { (yyval.node) = nodId((yyvsp[0].sval),OTHER_TYPE); }
#line 1869 "glang.tab.c"
    break;

  case 51: /* expr: MINUS expr  */
#line 253 "glang.y"
    { (yyval.node) = nodOper(UMINUS, 1, (yyvsp[0].node)); }
#line 1875 "glang.tab.c"
    break;

  case 52: /* expr: expr PLUS expr  */
#line 255 "glang.y"
    { (yyval.node) = nodOper(PLUS, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1881 "glang.tab.c"
    break;

  case 53: /* expr: expr MINUS expr  */
#line 257 "glang.y"
    { (yyval.node) = nodOper(MINUS, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1887 "glang.tab.c"
    break;

  case 54: /* expr: expr MULTIPLY expr  */
#line 259 "glang.y"
    { (yyval.node) = nodOper(MULTIPLY, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1893 "glang.tab.c"
    break;

  case 55: /* expr: expr DIVIDE expr  */
#line 261 "glang.y"
    {
        if ((yyvsp[0].node)->con.iVal == 0) 
        {
            yyerror("Division by zero.");
            (yyvsp[0].node)->con.iVal=1;
        }
        (yyval.node) = nodOper(DIVIDE, 2, (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 1906 "glang.tab.c"
    break;

  case 56: /* expr: expr LESS expr  */
#line 270 "glang.y"
    { (yyval.node) = nodOper(LESS, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1912 "glang.tab.c"
    break;

  case 57: /* expr: expr GREATER expr  */
#line 272 "glang.y"
    { (yyval.node) = nodOper(GREATER, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1918 "glang.tab.c"
    break;

  case 58: /* expr: expr GREATEREQUAL expr  */
#line 274 "glang.y"
    { (yyval.node) = nodOper(GREATEREQUAL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1924 "glang.tab.c"
    break;

  case 59: /* expr: expr LESSEQUAL expr  */
#line 276 "glang.y"
    { (yyval.node) = nodOper(LESSEQUAL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1930 "glang.tab.c"
    break;

  case 60: /* expr: expr NOTEQUAL expr  */
#line 278 "glang.y"
    { (yyval.node) = nodOper(NOTEQUAL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1936 "glang.tab.c"
    break;

  case 61: /* expr: expr EQUAL expr  */
#line 280 "glang.y"
    { (yyval.node) = nodOper(EQUAL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1942 "glang.tab.c"
    break;

  case 62: /* expr: LPAREN INT RPAREN expr  */
#line 282 "glang.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1950 "glang.tab.c"
    break;

  case 63: /* expr: LPAREN FLOAT RPAREN expr  */
#line 286 "glang.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1958 "glang.tab.c"
    break;

  case 64: /* expr: LPAREN DOUBLE RPAREN expr  */
#line 290 "glang.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1966 "glang.tab.c"
    break;

  case 65: /* expr: LPAREN expr RPAREN  */
#line 294 "glang.y"
    { (yyval.node) = (yyvsp[-1].node); }
#line 1972 "glang.tab.c"
    break;


#line 1976 "glang.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 296 "glang.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

void signal_handler(int signo)
{
    printf("Signal %d caught!\n", signo);
    longjmp(env, 1);
    
    exit(0);
}

void setEndSignal()
{
  struct sigaction sa;
  memset(&sa, 0, sizeof(sa));
  sa.sa_handler = signal_handler;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);
  sigaction(SIGINT, &sa, NULL);
  sigaction(SIGTERM,&sa, NULL);
  sigaction(SIGSEGV, &sa, NULL);
}


int main(int argc, char *argv[]) {

    setEndSignal();
    char input[100];
    printf("Welcome to the C PARSER\n\n");
    for(int i=0; i<30; i++,printf("="));
    printf("\n");

    // Set up the initial jump point
    if (sigsetjmp(env, 1) != 0) 
    {
        // We've jumped back here after a signal
        printf("\nReturned to main loop after signal.\n");
        clearInputBuffer();
        fflush(stdout);
    }

    while(1)
    {
        // Activate the jump mechanism
        canJump = 1;

        printf("Enter to start (or analyze a program: run <script_name> or <exit> to shutdown the program): ");
        fgets(input, sizeof(input), stdin);

         // Deactivate the jump mechanism during processing
        canJump = 0;

        if(strcmp(input, "exit\n") == 0)
            break;
        printf("Start analyzing the context!\n");
        if(strstr(input, "run"))
        {
            char *p=strtok(input," ");
            p=strtok(NULL," \n");
            printf("FILENAME: %s\n",p);
            yyin=fopen(p, "r");
            yyparse();
            fclose(yyin);
            // reset lexer internal state
            yyrestart(stdin);
            yyin=stdin;
            clearInputBuffer();
        }
        else
        {
            yyin=stdin;
            yyparse();
            clearInputBuffer();
        }
        fflush(stdin);
    }
    return 0;
}
