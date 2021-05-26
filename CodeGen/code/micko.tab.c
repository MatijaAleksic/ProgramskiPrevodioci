/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "micko.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int lab_num = -1;
  FILE *output;
  
  int argument_type_check= -1;
  int param_num = 0;

  int tip = -1;
  int return_exists = -1;
  
  int bloc_idx = -1;
  int bloc_vars = 0;
  int bloc_active = 0;
  
  int for_active = -1;
  int for_indx = -1;
  int lit1 = 999;
  int lit2 = 998;
  
  int fun_call_params = 0;
  int fun_call_params_check_type=0;
  int for_exit_num = -1;
  
  int check_tip = -1;
  
  int condif_mov_idx = -1;
  int condif_active = 0;
  
  int while_active = 0;
  int while_cmp = -1;
  int while_stat = -1;
  int while_exit_num = -1;
  
  int lab_num_backup = -1;
  int check_cmp_num = -1;
  int check_exit_num = -1;
  int otherwise_exits = -1;
  
  int increment_list[10]={0,0,0,0,0,0,0,0,0,0};
  
  int var_assign_indx_list[10]={0,0,0,0,0,0,0,0,0,0};
  int literal_assign_list[10]={0,0,0,0,0,0,0,0,0,0};
  
  int check_idx = -1;
  int check_cmp[20]={-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99};
  

#line 137 "micko.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_MICKO_TAB_H_INCLUDED
# define YY_YY_MICKO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _TYPE = 258,
    _IF = 259,
    _ELSE = 260,
    _RETURN = 261,
    _ID = 262,
    _INT_NUMBER = 263,
    _UINT_NUMBER = 264,
    _LPAREN = 265,
    _RPAREN = 266,
    _LBRACKET = 267,
    _RBRACKET = 268,
    _ASSIGN = 269,
    _SEMICOLON = 270,
    _AROP = 271,
    _RELOP = 272,
    _COMMA = 273,
    _QUESTION = 274,
    _INCREMENT = 275,
    _WHILE = 276,
    _FOR = 277,
    _DOTDOT = 278,
    _AND = 279,
    _OR = 280,
    _CHECK = 281,
    _CASE = 282,
    _ARROW = 283,
    _BREAK = 284,
    _OTHERWISE = 285,
    ONLY_IF = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 68 "micko.y"

  int i;
  char *s;

#line 226 "micko.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MICKO_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   114,   114,   124,   125,   132,   146,   147,   152,   151,
     179,   180,   184,   196,   211,   215,   210,   240,   241,   246,
     245,   255,   273,   291,   337,   370,   371,   375,   376,   377,
     378,   379,   380,   380,   381,   382,   383,   388,   405,   404,
     424,   423,   459,   460,   484,   488,   494,   509,   513,   517,
     523,   528,   536,   535,   572,   576,   604,   616,   617,   635,
     645,   670,   672,   679,   684,   678,   699,   697,   725,   748,
     771,   772,   777,   776,   797,   798,   798,   803,   804,   811,
     810,   890,   905,   889,   918,   928,   917,   949,   953,   957,
     964,   978,   986
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_TYPE", "_IF", "_ELSE", "_RETURN",
  "_ID", "_INT_NUMBER", "_UINT_NUMBER", "_LPAREN", "_RPAREN", "_LBRACKET",
  "_RBRACKET", "_ASSIGN", "_SEMICOLON", "_AROP", "_RELOP", "_COMMA",
  "_QUESTION", "_INCREMENT", "_WHILE", "_FOR", "_DOTDOT", "_AND", "_OR",
  "_CHECK", "_CASE", "_ARROW", "_BREAK", "_OTHERWISE", "ONLY_IF",
  "$accept", "program", "global_list", "global_var", "function_list",
  "function", "$@1", "parameter_list", "parameters", "body", "$@2", "$@3",
  "variable_list", "variable", "$@4", "vars", "statement_list",
  "statement", "$@5", "increment", "compound_statement", "$@6",
  "assignment_statement", "$@7", "num_exp", "exp", "literal",
  "function_call", "$@8", "arguments", "argument", "if_statement",
  "if_part", "@9", "$@10", "check_statement", "$@11", "check_expression",
  "cases", "case_statement", "$@12", "case_body", "$@13", "otherwise",
  "for_statement", "$@14", "while_statement", "$@15", "$@16",
  "conditional_exp", "@17", "$@18", "rel_expresions", "rel_exp",
  "return_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

#define YYPACT_NINF (-83)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-76)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -83,    16,    20,   -83,    30,   -83,    39,   -83,    33,    38,
     -83,   -83,    53,   -83,    73,    61,    69,    70,   -83,    80,
      92,   -83,   -83,    94,   -83,   -83,    99,   -83,   -83,   -83,
      96,     1,    90,    10,    95,    43,    27,   -83,   -83,    97,
      98,   -83,    84,   -83,   -83,   -83,   100,   -83,   104,   -83,
     -83,   -83,    12,   -83,   103,   -83,     9,   -83,   -83,    65,
     -83,    45,   -83,   -83,   -83,   -83,   -83,   101,   102,   -83,
     -83,   106,   107,   -83,   -83,    28,   -83,   108,    65,   -83,
      22,    41,   -83,   -83,    65,    65,   -83,    78,    99,    65,
     -83,   110,   111,   -83,    12,    66,    41,   -83,    65,    65,
      65,   112,   -83,    75,    91,   -83,    46,   -83,     5,    41,
     113,   117,   -83,   115,   116,   -83,   -83,   109,   -83,   -83,
     -83,    78,    78,   -83,   118,   114,   119,    28,    65,   -83,
     -83,    28,    12,    -3,   -83,    12,   -83,   -83,   -83,   -83,
     -83,    88,   -83,   120,   121,   122,   123,   124,    12,    65,
      28,    28,   -83,   125,   -83,   105,   -83,   126,   -83,   127,
     130,    28,   131,   -83,   -83,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     4,     2,     6,     8,     0,
       7,     5,     0,     8,    10,     0,     0,    11,    12,     0,
       0,    14,     9,     0,    17,    13,    15,    19,    25,    18,
       0,    32,    21,     0,     0,     0,    52,    38,    16,     0,
       0,    26,     0,    36,    27,    28,     0,    29,    61,    35,
      31,    30,     0,    20,     0,    63,    45,    50,    51,     0,
      92,     0,    42,    44,    47,    48,    40,     0,     0,    17,
      81,     0,     0,    33,    34,    32,    23,    22,     0,    46,
       0,    84,    87,    91,     0,     0,    37,    57,    25,     0,
      69,     0,     0,    62,     0,     0,    64,    49,     0,     0,
       0,     0,    43,     0,    58,    59,     0,    54,    32,    82,
       0,     0,    24,     0,    90,    89,    88,     0,    41,    60,
      53,    57,    57,    39,     0,     0,     0,    32,     0,    55,
      56,    32,     0,    66,    70,     0,    65,    85,    83,    72,
      68,     0,    71,     0,     0,     0,     0,     0,     0,     0,
      32,    32,    67,     0,    86,    74,    73,    77,    79,     0,
       0,    32,     0,    78,    80,    76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -83,   -83,   -83,   -83,   129,   -83,   -83,   -83,   -83,
     -83,   -83,    58,   -83,   -83,   -83,    50,   -72,   -83,   -83,
     -83,   -83,   -83,   -83,   -29,   -82,   -51,   -31,   -83,   -83,
     -28,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,    -2,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -74,    -1,   -83
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,     7,    12,    16,    17,    22,
      24,    28,    26,    29,    30,    33,    31,    41,    42,    43,
      44,    69,    45,    85,    95,    62,    63,    64,    68,   106,
     107,    47,    48,    78,   113,    49,   141,    91,   133,   134,
     145,   156,   159,   147,    73,   161,    50,    89,   124,    65,
     101,   144,    81,    82,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    76,   102,    93,    96,    34,    61,    35,    36,    34,
     140,    35,    36,    37,    38,   109,     3,    37,   123,   -52,
      57,    58,    39,     4,   132,    53,    39,    40,    54,    79,
      80,    40,    34,    97,    35,    36,   105,     8,    84,    98,
      37,    66,     9,   112,    46,    13,   137,    67,    11,    39,
      56,    57,    58,    59,    40,   136,   103,   120,    60,   138,
      83,    84,   121,    14,   122,    99,   100,   154,    18,   114,
     105,   105,    56,    57,    58,    59,    15,    46,   155,   157,
      19,   139,    84,    98,   143,   104,    57,    58,    20,   164,
     118,    84,    21,   129,   130,    23,    46,   153,   115,   116,
      46,    25,    27,    32,    52,    55,    72,    70,    71,    75,
      77,   119,    87,    90,   111,    74,    86,    92,   146,    46,
      46,   110,    94,   117,   126,   125,   127,    88,   128,   131,
      46,   142,    84,   135,   -75,    10,   158,   152,   108,     0,
       0,   132,     0,   148,   149,   163,   165,     0,     0,     0,
     150,   151,     0,     0,     0,   160,   162
};

static const yytype_int16 yycheck[] =
{
      31,    52,    84,    75,    78,     4,    35,     6,     7,     4,
      13,     6,     7,    12,    13,    89,     0,    12,    13,    10,
       8,     9,    21,     3,    27,    15,    21,    26,    18,    20,
      59,    26,     4,    11,     6,     7,    87,     7,    16,    17,
      12,    14,     3,    94,    75,     7,   128,    20,    15,    21,
       7,     8,     9,    10,    26,   127,    85,    11,    15,   131,
      15,    16,    16,    10,    18,    24,    25,   149,     7,    98,
     121,   122,     7,     8,     9,    10,     3,   108,   150,   151,
      11,   132,    16,    17,   135,     7,     8,     9,    18,   161,
      15,    16,    12,   121,   122,     3,   127,   148,    99,   100,
     131,     7,     3,     7,    14,    10,    22,    10,    10,     5,
       7,    20,    10,     7,     3,    15,    15,    10,    30,   150,
     151,    11,    14,    11,     7,    12,    11,    69,    19,    11,
     161,   133,    16,    14,    29,     6,    11,    13,    88,    -1,
      -1,    27,    -1,    23,    23,    15,    15,    -1,    -1,    -1,
      28,    28,    -1,    -1,    -1,    29,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    34,     0,     3,    35,    36,    37,     7,     3,
      37,    15,    38,     7,    10,     3,    39,    40,     7,    11,
      18,    12,    41,     3,    42,     7,    44,     3,    43,    45,
      46,    48,     7,    47,     4,     6,     7,    12,    13,    21,
      26,    49,    50,    51,    52,    54,    59,    63,    64,    67,
      78,    86,    14,    15,    18,    10,     7,     8,     9,    10,
      15,    56,    57,    58,    59,    81,    14,    20,    60,    53,
      10,    10,    22,    76,    15,     5,    58,     7,    65,    20,
      56,    84,    85,    15,    16,    55,    15,    10,    44,    79,
       7,    69,    10,    49,    14,    56,    84,    11,    17,    24,
      25,    82,    57,    56,     7,    58,    61,    62,    48,    84,
      11,     3,    58,    66,    56,    85,    85,    11,    15,    20,
      11,    16,    18,    13,    80,    12,     7,    11,    19,    62,
      62,    11,    27,    70,    71,    14,    49,    57,    49,    58,
      13,    68,    71,    58,    83,    72,    30,    75,    23,    23,
      28,    28,    13,    58,    57,    49,    73,    49,    11,    74,
      29,    77,    29,    15,    49,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    36,    36,    38,    37,
      39,    39,    40,    40,    42,    43,    41,    44,    44,    46,
      45,    47,    47,    47,    47,    48,    48,    49,    49,    49,
      49,    49,    50,    49,    49,    49,    49,    51,    53,    52,
      55,    54,    56,    56,    57,    57,    57,    57,    57,    57,
      58,    58,    60,    59,    61,    61,    61,    62,    62,    62,
      62,    63,    63,    65,    66,    64,    68,    67,    67,    69,
      70,    70,    72,    71,    73,    74,    73,    75,    75,    77,
      76,    79,    80,    78,    82,    83,    81,    84,    84,    84,
      85,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     3,     1,     2,     0,     7,
       0,     1,     2,     4,     0,     0,     6,     0,     2,     0,
       4,     1,     3,     3,     5,     0,     2,     1,     1,     1,
       1,     1,     0,     2,     2,     1,     1,     3,     0,     5,
       0,     5,     1,     3,     1,     1,     2,     1,     1,     3,
       1,     1,     0,     5,     1,     3,     3,     0,     1,     1,
       2,     1,     3,     0,     0,     7,     0,     9,     7,     1,
       1,     2,     0,     5,     1,     0,     4,     3,     5,     0,
      11,     0,     0,     7,     0,     0,     9,     1,     3,     3,
       3,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
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
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 115 "micko.y"
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
			//print_symtab();
       }
#line 1527 "micko.tab.c"
    break;

  case 5:
#line 133 "micko.y"
        {
		int idx = lookup_symbol((yyvsp[-1].s), GVAR); 
		if (idx != NO_INDEX) 
		{
				err("redefinition of '%s'", (yyvsp[-1].s));
		} else {
			insert_symbol((yyvsp[-1].s), GVAR, (yyvsp[-2].i), NO_ATR, NO_ATR);
			code("\n%s:\n\t\tWORD\t1", (yyvsp[-1].s));
		}
	}
#line 1542 "micko.tab.c"
    break;

  case 8:
#line 152 "micko.y"
      {
        fun_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol((yyvsp[0].s), FUN, (yyvsp[-1].i), NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", (yyvsp[0].s));
	  
	    code("\n%s:", (yyvsp[0].s));
		code("\n\t\tPUSH\t%%14");
		code("\n\t\tMOV \t%%15,%%14");
      }
#line 1558 "micko.tab.c"
    break;

  case 9:
#line 164 "micko.y"
      {
        //clear_symbols(fun_idx + 1);
        var_num = 0;
		param_num = 0;
		
		code("\n@%s_exit:", (yyvsp[-5].s));
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
#line 1573 "micko.tab.c"
    break;

  case 10:
#line 179 "micko.y"
      { set_atr1(fun_idx, 0); }
#line 1579 "micko.tab.c"
    break;

  case 12:
#line 185 "micko.y"
      {
		if((yyvsp[-1].i) == VOID)
			err("cannot assign void to parameter");
		
		
		insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), ++param_num, fun_idx	);
        set_atr1(fun_idx, param_num);
        set_atr2(fun_idx, (yyvsp[-1].i));
		
		
      }
#line 1595 "micko.tab.c"
    break;

  case 13:
#line 197 "micko.y"
          {
		  if((yyvsp[-1].i) == VOID)
			err("cannot assign void to parameter");
		
		
		insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), ++param_num, fun_idx);
        set_atr1(fun_idx, param_num);
        set_atr2(fun_idx, (yyvsp[-1].i));
	  }
#line 1609 "micko.tab.c"
    break;

  case 14:
#line 211 "micko.y"
          {
		  return_exists = -1;
	  }
#line 1617 "micko.tab.c"
    break;

  case 15:
#line 215 "micko.y"
          {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
		
		for(int i=0;i< 10;i++){ 
			if(var_assign_indx_list[i] != 0){
				gen_mov(literal_assign_list[i],var_assign_indx_list[i]);
		  }
		  var_assign_indx_list[i] = 0;
		  literal_assign_list[i] = 0;
		}
      }
#line 1635 "micko.tab.c"
    break;

  case 16:
#line 230 "micko.y"
          {
		if(get_type(fun_idx) == INT || get_type(fun_idx) == UINT)
		{
			if(return_exists == -1)
			warning("Function should return something!");
		}
	  }
#line 1647 "micko.tab.c"
    break;

  case 19:
#line 246 "micko.y"
  {
	  if((yyvsp[0].i) == VOID)
		err("Cannot assign void to variable");
	  tip = (yyvsp[0].i);
  }
#line 1657 "micko.tab.c"
    break;

  case 21:
#line 256 "micko.y"
          {
		if(bloc_active == 0)
		{
			int idx_var = lookup_symbol((yyvsp[0].s), VAR|PAR);
			if(idx_var == NO_INDEX)
			   insert_symbol((yyvsp[0].s), VAR, tip , ++var_num, fun_idx);
			else
				if(get_atr2(idx_var) == fun_idx)
					err("redefinition of '%s'", (yyvsp[0].s));
				else
					insert_symbol((yyvsp[0].s), VAR, tip , ++var_num, fun_idx);
		}
		else
	    {
		  insert_symbol((yyvsp[0].s), VAR, tip , ++bloc_vars, fun_idx);
	    }
      }
#line 1679 "micko.tab.c"
    break;

  case 22:
#line 274 "micko.y"
        {
		if(bloc_active == 0)
		{
			int idx_var = lookup_symbol((yyvsp[0].s), VAR|PAR);
			if(idx_var == NO_INDEX)
			   insert_symbol((yyvsp[0].s), VAR, tip , ++var_num, fun_idx);
			else 
				if(get_atr2(idx_var) == fun_idx)
					err("redefinition of '%s'", (yyvsp[0].s) );
				else
					insert_symbol((yyvsp[0].s), VAR, tip , ++var_num, fun_idx);
		}
		else
	    {
		  insert_symbol((yyvsp[0].s), VAR, tip , ++bloc_vars, fun_idx);
	    }
      }
#line 1701 "micko.tab.c"
    break;

  case 23:
#line 292 "micko.y"
          {
		if(bloc_active == 0)
		{
			int idx_var = lookup_symbol((yyvsp[-2].s), VAR|PAR);
			if(idx_var == NO_INDEX)
			   insert_symbol((yyvsp[-2].s), VAR, tip , ++var_num, fun_idx);
			else 
				if(get_atr2(idx_var) == fun_idx)
					err("redefinition of '%s'", (yyvsp[-2].s));
				else
					insert_symbol((yyvsp[-2].s), VAR, tip , ++var_num, fun_idx);
		}
		else
	    {
		  insert_symbol((yyvsp[-2].s), VAR, tip , ++bloc_vars, fun_idx);
	    }
		
		if(get_type(lookup_symbol((yyvsp[-2].s), VAR|PAR)) != get_type((yyvsp[0].i)))
			err("variable and literal are not of the same type");
		
		int id_index = lookup_symbol((yyvsp[-2].s), VAR|PAR);
		if(id_index == NO_INDEX)
		{
			err("Not defined %s", (yyvsp[-2].s));
		}


		for(int i=0;i< 10;i++){ 
			if(var_assign_indx_list[i] == 0){
				var_assign_indx_list[i] = id_index;
				literal_assign_list[i] = (yyvsp[0].i);
				break;
		  }
		}
		//gen_mov($3, id_index);
		
		
		
		
		
		
		
		
		
      }
#line 1751 "micko.tab.c"
    break;

  case 24:
#line 338 "micko.y"
          {
		if(bloc_active == 0)
		{
			int idx_var = lookup_symbol((yyvsp[-2].s), VAR|PAR);
			if(idx_var == NO_INDEX)
			   insert_symbol((yyvsp[-2].s), VAR, tip , ++var_num, fun_idx);
			else 
				if(get_atr2(idx_var) == fun_idx)
					err("redefinition of '%s'", (yyvsp[-2].s));
				else
					insert_symbol((yyvsp[-2].s), VAR, tip , ++var_num, fun_idx);
		}
		else
	    {
		  insert_symbol((yyvsp[-2].s), VAR, tip , ++bloc_vars, fun_idx);
	    }
		
		if(get_type(lookup_symbol((yyvsp[-2].s), VAR|PAR)) != get_type((yyvsp[0].i)))
			err("variable and literal are not of the same type");
		
		
		int id_index = lookup_symbol((yyvsp[-2].s), VAR|PAR);
		if(id_index == NO_INDEX)
		{
			err("Not defined %s", (yyvsp[-2].s));
		}
		
		gen_mov((yyvsp[0].i), id_index);
      }
#line 1785 "micko.tab.c"
    break;

  case 32:
#line 380 "micko.y"
   {for_indx = get_last_element() + 1;}
#line 1791 "micko.tab.c"
    break;

  case 37:
#line 389 "micko.y"
        {
	  int inc_idx = lookup_symbol((yyvsp[-2].s), VAR|PAR|GVAR);
	  if(inc_idx == NO_INDEX)
		err("Not defined:'%s'", (yyvsp[-2].s) );
	
	  code("\n\t\tADDS\t");
	  gen_sym_name(inc_idx);
	  code(",$1,");
	  gen_sym_name(inc_idx);
	}
#line 1806 "micko.tab.c"
    break;

  case 38:
#line 405 "micko.y"
          {
		bloc_active = 1;
		bloc_idx = get_last_element() + 1;
		bloc_vars = 0;
	  }
#line 1816 "micko.tab.c"
    break;

  case 39:
#line 411 "micko.y"
          {
		bloc_active = 0;
		bloc_idx = get_last_element() - bloc_vars;
		clear_symbols(bloc_idx);
		/*print_symtab();
		clear_symbols(bloc_idx);
		print_symtab();*/
	  }
#line 1829 "micko.tab.c"
    break;

  case 40:
#line 424 "micko.y"
        {
		condif_active = 0;
		condif_mov_idx = lookup_symbol((yyvsp[-1].s), VAR|PAR|GVAR);
	}
#line 1838 "micko.tab.c"
    break;

  case 41:
#line 429 "micko.y"
      {
		int idx = lookup_symbol((yyvsp[-4].s), VAR|PAR|GVAR);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", (yyvsp[-4].s));
        else
          if(get_type(idx) != get_type((yyvsp[-1].i)))
            err("incompatible types in assignment");
		
		
		for(int i=0;i< 10;i++){ 
			if(increment_list[i] != 0){
				
				code("\n\t\tADDS\t");
				gen_sym_name(increment_list[i]);
				code(",$1,");
				gen_sym_name(increment_list[i]);
		  }
		  increment_list[i] = 0;
		}
		
		if(condif_active == 0)
		{
			gen_mov((yyvsp[-1].i), idx);
		}
		//gen_mov($4, idx);
      }
#line 1869 "micko.tab.c"
    break;

  case 42:
#line 459 "micko.y"
        { (yyval.i) = (yyvsp[0].i); }
#line 1875 "micko.tab.c"
    break;

  case 43:
#line 461 "micko.y"
      {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: arithmetic operation");
		int t1 = get_type((yyvsp[-2].i));   
		
		code("\n\t\t%s\t", ar_instructions[(yyvsp[-1].i) + (t1 - 1) * AROP_NUMBER]);
		gen_sym_name((yyvsp[-2].i));
		code(",");
		gen_sym_name((yyvsp[0].i));
		code(",");
		
		//OVO MOZDA TREBA IZBRISATI
		//free_if_reg($3);
		//free_if_reg($1);
		
		(yyval.i) = take_reg();
        gen_sym_name((yyval.i));
        set_type((yyval.i), t1);
		
	  }
#line 1900 "micko.tab.c"
    break;

  case 44:
#line 485 "micko.y"
          {
		  (yyval.i) = (yyvsp[0].i);
	  }
#line 1908 "micko.tab.c"
    break;

  case 45:
#line 489 "micko.y"
      {
        (yyval.i) = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
        if((yyval.i) == NO_INDEX)
          err("'%s' undeclared", (yyvsp[0].s));
      }
#line 1918 "micko.tab.c"
    break;

  case 46:
#line 495 "micko.y"
          {	  
		(yyval.i) = lookup_symbol((yyvsp[-1].s), VAR|PAR|GVAR);
        if((yyval.i) == NO_INDEX)
          err("'%s' undeclared", (yyvsp[-1].s));
	  
	  
		for(int i=0;i< 10;i++){ 
		  if(increment_list[i] == 0){
			  increment_list[i] = (yyval.i);
			  break;
		  }
		}
		
	  }
#line 1937 "micko.tab.c"
    break;

  case 47:
#line 510 "micko.y"
         {
		 (yyval.i)  = (yyvsp[0].i);
	 }
#line 1945 "micko.tab.c"
    break;

  case 48:
#line 514 "micko.y"
        {
		(yyval.i)  = (yyvsp[0].i);
	}
#line 1953 "micko.tab.c"
    break;

  case 49:
#line 518 "micko.y"
      { (yyval.i) = (yyvsp[-1].i); }
#line 1959 "micko.tab.c"
    break;

  case 50:
#line 524 "micko.y"
      { 
		(yyval.i) = insert_literal((yyvsp[0].s), INT);
	  }
#line 1967 "micko.tab.c"
    break;

  case 51:
#line 529 "micko.y"
      { 
		(yyval.i) = insert_literal((yyvsp[0].s), UINT);
	  }
#line 1975 "micko.tab.c"
    break;

  case 52:
#line 536 "micko.y"
      {
        fcall_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", (yyvsp[0].s));
	    fun_call_params = 0;
		fun_call_params_check_type = fcall_idx + 1;
      }
#line 1987 "micko.tab.c"
    break;

  case 53:
#line 544 "micko.y"
      {
        if(get_atr1(fcall_idx) != fun_call_params)
          err("wrong number of args to function '%s'",get_name(fcall_idx));
        (yyval.i) = fcall_idx;
		
		code("\n\t\t\tPUSH\t");
		gen_sym_name((yyvsp[-1].i));
		
		code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if((yyvsp[-1].i) > 0)
          code("\n\t\t\tADDS\t%%15,$%d,%%15", fun_call_params * 4);
        set_type(FUN_REG, get_type(fcall_idx));
        (yyval.i) = FUN_REG;
		
		for(int i=0;i< 10;i++){ 
			if(increment_list[i] != 0){
				
				code("\n\t\t\tADDS\t");
				gen_sym_name(increment_list[i]);
				code(",$1,");
				gen_sym_name(increment_list[i]);
		  }
		  increment_list[i] = 0;
		}
      }
#line 2017 "micko.tab.c"
    break;

  case 54:
#line 573 "micko.y"
    {
	  (yyval.i) = (yyvsp[0].i);
    }
#line 2025 "micko.tab.c"
    break;

  case 55:
#line 577 "micko.y"
    {
	  fun_call_params_check_type--;
	  fun_call_params--;
	  (yyval.i) = (yyvsp[0].i);
	  
	  /*code("\n\t\tADDS\t");
	  gen_sym_name($1);
	  code(",");
	  gen_sym_name($3);*/
	  
	  
	  if(get_type(argument_type_check) != get_type((yyvsp[0].i)))
          err("Types not matching!");
		int t1 = get_type((yyvsp[-2].i));   
		
	  code("\n\t\t\t%s\t", ar_instructions[(yyvsp[-1].i) + (t1 - 1) * AROP_NUMBER]);
	  gen_sym_name((yyvsp[-2].i));
	  code(",");
	  gen_sym_name((yyvsp[0].i));
	  code(",");
	  //free_if_reg($3);
	  //free_if_reg($1);
	  (yyval.i) = take_reg(); //$$ = take_reg();
      gen_sym_name((yyval.i));
      set_type((yyval.i), t1);
	  
    }
#line 2057 "micko.tab.c"
    break;

  case 56:
#line 605 "micko.y"
    {  
	  if(get_type(argument_type_check) != get_type((yyvsp[0].i)))
          err("Types not matching!");
	  
	  code("\n\t\t\tPUSH\t");
	  gen_sym_name((yyvsp[-2].i));
	  (yyval.i) = (yyvsp[0].i);
	}
#line 2070 "micko.tab.c"
    break;

  case 57:
#line 616 "micko.y"
                {(yyval.i) = 0;}
#line 2076 "micko.tab.c"
    break;

  case 58:
#line 618 "micko.y"
        { 
		(yyval.i) = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
        if((yyval.i) == NO_INDEX)
          err("'%s' undeclared", (yyvsp[0].s));
		
		int id_idx = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
		if(get_type(fun_call_params_check_type) != get_type(id_idx))
			err("Type of parameter '%s' not valid", get_name(id_idx));
		fun_call_params_check_type++;
		fun_call_params++;
		
		//free_if_reg(id_idx);
		
		//$$ = 1;
		argument_type_check = (yyval.i);
	}
#line 2097 "micko.tab.c"
    break;

  case 59:
#line 636 "micko.y"
        {
		if(get_type(fun_call_params_check_type) != get_type((yyvsp[0].i)))
			err("Type of parameter '%d' not valid", fun_call_params);
		fun_call_params_check_type++;
		fun_call_params++;
		
		(yyval.i) = (yyvsp[0].i);
		argument_type_check = (yyval.i);
	}
#line 2111 "micko.tab.c"
    break;

  case 60:
#line 646 "micko.y"
          {
		(yyval.i) = lookup_symbol((yyvsp[-1].s), VAR|PAR|GVAR);
        if((yyval.i) == NO_INDEX)
          err("'%s' undeclared", (yyvsp[-1].s));
	  
		int id_idx = lookup_symbol((yyvsp[-1].s), VAR|PAR|GVAR);
		if(get_type(fun_call_params_check_type) != get_type(id_idx))
			err("Type of parameter '%s' not valid", get_name(id_idx));
		fun_call_params_check_type++;
		fun_call_params++;
	
		
		for(int i=0;i< 10;i++){ 
		  if(increment_list[i] == 0){
			  increment_list[i] = (yyval.i);
			  break;
		  }
		}
		argument_type_check = (yyval.i);
	  }
#line 2136 "micko.tab.c"
    break;

  case 61:
#line 671 "micko.y"
        { code("\n@exit%d:", (yyvsp[0].i)); }
#line 2142 "micko.tab.c"
    break;

  case 62:
#line 673 "micko.y"
        { code("\n@exit%d:", (yyvsp[-2].i)); }
#line 2148 "micko.tab.c"
    break;

  case 63:
#line 679 "micko.y"
          {
        (yyval.i) = ++lab_num;
        code("\n@if%d:", lab_num);
      }
#line 2157 "micko.tab.c"
    break;

  case 64:
#line 684 "micko.y"
          {
        code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[0].i)], (yyvsp[-1].i)); 
        code("\n@true%d:", (yyvsp[-1].i));
      }
#line 2166 "micko.tab.c"
    break;

  case 65:
#line 689 "micko.y"
          {
        code("\n\t\tJMP \t@exit%d", (yyvsp[-4].i));
        code("\n@false%d:", (yyvsp[-4].i));
        (yyval.i) = (yyvsp[-4].i);
      }
#line 2176 "micko.tab.c"
    break;

  case 66:
#line 699 "micko.y"
        {
		lab_num++;
		code("\n@L%d:", lab_num);
	}
#line 2185 "micko.tab.c"
    break;

  case 67:
#line 704 "micko.y"
        {
		code("\n@CHECK_CMP%d:", check_cmp_num);
		

		
		for(int i=0;i< 20;i++){ 
		  if(check_cmp[i] != -99){
			  
			  gen_cmp(check_idx, check_cmp[i]);
			  code("\n\t\tJEQ\t@L%d", lab_num_backup);
			  lab_num_backup++;
		  }
		}
		code("\n\t\tJMP\t@L%d", lab_num_backup);
		
		code("\n@CHECK_EXIT%d:", check_exit_num);
		check_idx = -1;
	}
#line 2208 "micko.tab.c"
    break;

  case 68:
#line 727 "micko.y"
        {
		code("\n@CHECK_CMP%d:", check_cmp_num);
		
		for(int i=0;i< 20;i++){ 
		  if(check_cmp[i] != -99){
			  gen_cmp(check_idx, check_cmp[i]);
			  code("\n\t\tJEQ\t@L%d", lab_num_backup);
			  lab_num_backup++;
		  }
		}
			
		
		
		
		
		code("\n@CHECK_EXIT%d:", check_exit_num);
		check_idx = -1;
	}
#line 2231 "micko.tab.c"
    break;

  case 69:
#line 749 "micko.y"
          {
		  int id_indx = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
		  if(id_indx == NO_INDEX)
			   err("'%s' must be defined", (yyvsp[0].s));
		   
		  check_tip = get_type(id_indx);
		  check_idx = id_indx;
		  
		  //dal treba?
		  lab_num_backup = lab_num + 1;
		  
		  ++check_exit_num;
		  ++check_cmp_num;
		  
		  code("\n\t\tJMP\t@CHECK_CMP%d", check_cmp_num);
		  
		  	  //gen_cmp(check_idx, $2);
			//code("\n\t\tJEQ\t@L%d", lab_num);
	  }
#line 2255 "micko.tab.c"
    break;

  case 72:
#line 777 "micko.y"
  {  
	  if(check_tip != get_type((yyvsp[0].i)))
			err("Case type and literal are not of the same type");
	  ++lab_num;
	  
	  for(int i=0;i< 20;i++){ 
		  if(check_cmp[i] == -99){
			  check_cmp[i] = (yyvsp[0].i);
			  break;
		  }
		}
		
		
	  code("\n@L%d:", lab_num);
  }
#line 2275 "micko.tab.c"
    break;

  case 74:
#line 797 "micko.y"
              {code("\n\t\tJMP\t@CHECK_EXIT%d", check_exit_num);}
#line 2281 "micko.tab.c"
    break;

  case 75:
#line 798 "micko.y"
              {code("\n\t\tJMP\t@CHECK_EXIT%d", check_exit_num);}
#line 2287 "micko.tab.c"
    break;

  case 77:
#line 803 "micko.y"
                               {code("\n\t\tJMP\t@CHECK_EXIT%d", check_exit_num);}
#line 2293 "micko.tab.c"
    break;

  case 78:
#line 804 "micko.y"
                                                  {code("\n\t\tJMP\t@CHECK_EXIT%d", check_exit_num);}
#line 2299 "micko.tab.c"
    break;

  case 79:
#line 811 "micko.y"
  {
	  int idx = lookup_symbol((yyvsp[-5].s), VAR|PAR|GVAR);
	  if(idx == NO_INDEX)
		insert_symbol((yyvsp[-5].s), VAR, (yyvsp[-6].i) , NO_ATR, NO_ATR);
	  else
	  {
		err("redefinition of '%s'", (yyvsp[-5].s));
		insert_symbol((yyvsp[-5].s), VAR, (yyvsp[-6].i) , NO_ATR, NO_ATR);
	  }
		   
	  if((yyvsp[-6].i) != get_type((yyvsp[-3].i)) || (yyvsp[-6].i) != get_type((yyvsp[-1].i)))
	  {
		  err("Incopatable types in for loop");
	  }
	  for_active = 1;
	  ++for_exit_num;
	  
	  
	  lit1 = take_reg();
	  lit2 = take_reg();
	  
	  code("\n\t\tMOV \t");
	  gen_sym_name((yyvsp[-3].i));
	  code(",");
	  gen_sym_name(lit1);
	  
	  
	  code("\n\t\tMOV \t");
	  gen_sym_name((yyvsp[-1].i));
	  code(",");
	  gen_sym_name(lit2);

	  
	  while_active = 1;
	  ++lab_num;

	  code("\n@L%d:", lab_num);
	  
	  
	  
	  code("\n\t\tCMPU \t");
	
	  gen_sym_name(lit1);
	  code(",");
	  gen_sym_name(lit2);
  
  
	  code("\n\t\tJEQ \t@L_exit%d", for_exit_num);
	  

	  
	  code("\n@L%d:", ++lab_num);
	  
	  code("\n\t\tADDS\t");
	  gen_sym_name(lit1);
	  code(",$1,");
	  gen_sym_name(lit1);
	  
  }
#line 2363 "micko.tab.c"
    break;

  case 80:
#line 871 "micko.y"
  {
	  
	  /*print_symtab();
	  printf("%d", for_indx);*/
	  
	  clear_symbols(for_indx);
	  for_indx = -1;
	  
	  code("\n\t\tJMP \t@L%d", lab_num-1);
	  code("\n@L_exit%d:", for_exit_num);
	  while_active = 0;
	  for_active = -1;
	  //clear_symbols(for_indx);
	  /*print_symtab();*/
  }
#line 2383 "micko.tab.c"
    break;

  case 81:
#line 890 "micko.y"
          {
		while_active = 1;
		++while_exit_num;
		
		lab_num = lab_num + 2;
		
		while_cmp = lab_num - 1;
		while_stat = lab_num;
		
		code("\n\t\tJMP\t@L%d", while_cmp);

		code("\n@L%d:", while_cmp);

      }
#line 2402 "micko.tab.c"
    break;

  case 82:
#line 905 "micko.y"
        {
		code("\n@L%d:", while_stat);
	}
#line 2410 "micko.tab.c"
    break;

  case 83:
#line 909 "micko.y"
        {
        code("\n\t\tJMP \t@L%d", while_cmp);
		code("\n@L_exit:");
		while_active = 0;
    }
#line 2420 "micko.tab.c"
    break;

  case 84:
#line 918 "micko.y"
                {
			condif_active = 1;
			(yyval.i) = ++lab_num;
			code("\n@if%d:", lab_num);
			
		  code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[0].i)], lab_num); 
		  
		  code("\n@true%d:", lab_num);
		}
#line 2434 "micko.tab.c"
    break;

  case 85:
#line 928 "micko.y"
                {
	
		  gen_mov((yyvsp[0].i), condif_mov_idx);
		  code("\n\t\tJMP \t@exit%d", lab_num);
		  code("\n@false%d:", lab_num);
		}
#line 2445 "micko.tab.c"
    break;

  case 86:
#line 935 "micko.y"
                {
			if(get_type((yyvsp[0].i)) != get_type((yyvsp[-3].i)))
				err("Incompatable types conditional_exp!");
	  
			gen_mov((yyvsp[0].i), condif_mov_idx);
			
			 
			(yyval.i) = (yyvsp[-3].i);
			code("\n@exit%d:", lab_num);
		}
#line 2460 "micko.tab.c"
    break;

  case 87:
#line 950 "micko.y"
  {
	  (yyval.i) = (yyvsp[0].i);
  }
#line 2468 "micko.tab.c"
    break;

  case 88:
#line 954 "micko.y"
  {
	  (yyval.i) = (yyvsp[0].i);
  }
#line 2476 "micko.tab.c"
    break;

  case 89:
#line 958 "micko.y"
  {
	  (yyval.i) = (yyvsp[0].i);
  }
#line 2484 "micko.tab.c"
    break;

  case 90:
#line 965 "micko.y"
      {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: relational operator");
		(yyval.i) = (yyvsp[-1].i) + ((get_type((yyvsp[-2].i)) - 1) * RELOP_NUMBER);
        gen_cmp((yyvsp[-2].i), (yyvsp[0].i));
		
		if(while_active == 1){
			code("\n\t\t%s\t@L_exit%d", opp_jumps[(yyval.i)], while_exit_num); 
		}
      }
#line 2499 "micko.tab.c"
    break;

  case 91:
#line 979 "micko.y"
      {
		return_exists = 1;
        if(get_type(fun_idx) != get_type((yyvsp[-1].i)))
          err("incompatible types in return");
		gen_mov((yyvsp[-1].i), FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));  
      }
#line 2511 "micko.tab.c"
    break;

  case 92:
#line 987 "micko.y"
          {
		return_exists = 1;
		if(get_type(fun_idx) == INT || get_type(fun_idx) == UINT)
          warning("Function should return the specified type!");
		code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));
	  }
#line 2522 "micko.tab.c"
    break;


#line 2526 "micko.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 995 "micko.y"


int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count){
	remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}

