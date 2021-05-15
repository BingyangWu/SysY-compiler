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
#line 1 "SysY.y"

    #include <cstdio>
    #include "globals.h"
    #include "stmt.h"
    #include "expr.h"
    int yyerror(const char *);
    extern int yylex(void);

#line 79 "SysY.tab.cpp"

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
#ifndef YY_YY_SYSY_TAB_HPP_INCLUDED
# define YY_YY_SYSY_TAB_HPP_INCLUDED
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
    IF = 258,
    ELSE = 259,
    WHILE = 260,
    BREAK = 261,
    CONTINUE = 262,
    RET = 263,
    AND = 264,
    OR = 265,
    EQ = 266,
    NEQ = 267,
    LEQ = 268,
    GEQ = 269,
    INT = 270,
    CONST = 271,
    VOID = 272,
    IMM = 273,
    ID = 274
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYSY_TAB_HPP_INCLUDED  */



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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   261

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

#define YYUNDEFTOK  2
#define YYMAXUTOK   274


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
       2,     2,     2,    34,     2,     2,     2,    33,     2,     2,
      25,    26,    31,    29,    21,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    20,
      35,    22,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,    24,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    19,    19,    21,    22,    23,    24,    26,    27,    29,
      31,    32,    34,    36,    37,    38,    40,    41,    43,    45,
      46,    48,    49,    51,    52,    53,    55,    56,    58,    59,
      60,    61,    63,    64,    66,    68,    69,    70,    71,    73,
      74,    76,    77,    79,    81,    82,    84,    85,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    99,
     101,   102,   103,   105,   106,   107,   108,   110,   111,   112,
     113,   114,   115,   116,   117,   119,   120,   123,   125,   126,
     128,   129,   131,   132,   133,   135,   136,   137,   138,   139
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "BREAK",
  "CONTINUE", "RET", "AND", "OR", "EQ", "NEQ", "LEQ", "GEQ", "INT",
  "CONST", "VOID", "IMM", "ID", "';'", "','", "'='", "'{'", "'}'", "'('",
  "')'", "'['", "']'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'<'",
  "'>'", "$accept", "Program", "CompUnit", "Decl", "ConstDecl",
  "ConstDefSeq", "ConstDef", "ConstInitVal", "ConstInitValSeq", "VarDecl",
  "VarDefSeq", "VarDef", "InitVal", "InitValSeq", "FuncDef", "FuncFParams",
  "FuncParam", "FuncIdent", "Ident", "BrackertsSeq", "Block",
  "BlockItemSeq", "BlockItem", "Stmt", "ConstExp", "Exp", "Term", "Factor",
  "FuncRParams", "Cond", "LorOp", "LandOp", "EqOp", "RelOp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      59,    44,    61,   123,   125,    40,    41,    91,    93,    43,
      45,    42,    47,    37,    33,    60,    62
};
# endif

#define YYPACT_NINF (-136)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     120,   -11,     4,     7,    36,   120,  -136,  -136,  -136,  -136,
      23,    41,  -136,    18,    33,    51,  -136,  -136,  -136,    -3,
     227,    67,  -136,    33,   185,    71,    95,  -136,    68,     9,
      86,    84,    30,  -136,  -136,    60,   227,   227,   227,   227,
    -136,    92,   107,  -136,   227,  -136,    49,  -136,   112,  -136,
      33,   193,    84,    38,   100,  -136,   142,  -136,   129,    84,
     206,    66,  -136,  -136,  -136,  -136,   227,   227,   227,   227,
     227,   125,  -136,  -136,    82,  -136,   164,  -136,  -136,   112,
    -136,    84,    52,    67,   126,   131,   139,   143,   219,    33,
    -136,  -136,   144,  -136,    94,  -136,  -136,    -9,  -136,  -136,
    -136,   112,    63,  -136,   107,   107,  -136,  -136,  -136,  -136,
     185,  -136,  -136,  -136,   105,  -136,    71,   227,   227,  -136,
    -136,  -136,    13,   227,  -136,  -136,  -136,   227,  -136,  -136,
     193,  -136,    67,   112,   155,   160,   177,   157,    -7,   170,
    -136,    24,   112,  -136,   172,   227,   227,   227,   227,   227,
     227,   227,   227,   172,  -136,   195,   177,   157,    -7,    -7,
     112,   112,   112,   112,  -136,   172,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     5,     7,     8,     6,
      40,     0,    20,    21,     0,     0,     1,     3,     4,     0,
       0,    39,    18,     0,     0,    40,     0,    11,     0,     0,
       0,     0,     0,    33,    69,    40,     0,     0,     0,     0,
      68,     0,    62,    66,     0,    19,     0,    22,    23,     9,
       0,     0,     0,     0,    38,    34,     0,    31,     0,     0,
       0,     0,    72,    73,    74,    42,     0,     0,     0,     0,
       0,     0,    25,    27,     0,    10,     0,    12,    13,    59,
      29,     0,     0,    36,     0,     0,     0,     0,     0,     0,
      50,    46,    68,    51,     0,    45,    47,     0,    32,    30,
      71,    76,     0,    67,    60,    61,    63,    64,    65,    41,
       0,    24,    15,    17,     0,    28,    37,     0,     0,    55,
      56,    58,     0,     0,    43,    44,    49,     0,    70,    26,
       0,    14,    35,    89,     0,    77,    79,    81,    84,     0,
      57,     0,    75,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    52,    78,    80,    82,    83,
      87,    88,    85,    86,    54,     0,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,    34,  -136,  -136,   150,   -72,  -136,  -136,
    -136,   182,   -44,  -136,   202,   180,   159,  -136,    -1,   -51,
     -21,  -136,   119,  -135,  -136,   -19,   118,   -23,  -136,   102,
    -136,    76,    80,    26
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    91,     7,    26,    27,    77,   114,     8,
      11,    12,    47,    74,     9,    32,    33,    55,    40,    21,
      93,    94,    95,    96,    78,   133,    42,    43,   102,   134,
     135,   136,   137,   138
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,    41,    73,    83,   113,    48,   149,   150,    10,   155,
      57,   126,    30,    28,    62,    63,    64,    61,   164,    14,
      66,    67,    13,    31,    30,    71,    15,    48,   151,   152,
     166,    80,    79,   140,     6,    52,    16,    97,    99,    17,
      24,   101,    66,    67,   154,   106,   107,   108,    19,    28,
      20,    58,    25,    66,    67,    92,    59,    79,   143,    58,
     115,    22,    23,    41,    81,   132,   129,    34,    35,   122,
      34,    35,    46,    72,    36,    97,    29,    36,    37,    38,
     116,    37,    38,    39,   127,    60,    39,    20,    13,   128,
      51,    48,   103,    92,    44,    66,    67,    84,    20,    85,
      86,    87,    88,   110,   141,    54,   111,    56,   142,    89,
       2,    79,    34,    35,    90,    49,    50,    56,   124,    36,
      65,    66,    67,    37,    38,    97,   130,    82,    39,   131,
     160,   161,   162,   163,    97,     1,     2,     3,    68,    69,
      70,    66,    67,    92,    30,    84,    97,    85,    86,    87,
      88,   117,    92,   109,    66,    67,   118,    89,     2,   119,
      34,    35,    90,   120,    92,    56,   123,    36,   147,   148,
     145,    37,    38,   158,   159,    84,    39,    85,    86,    87,
      88,   144,    34,    35,   104,   105,   146,    76,   112,    36,
      34,    35,    90,    37,    38,    56,   153,    36,    39,   165,
      75,    37,    38,    34,    35,    45,    39,    18,    46,    53,
      36,    34,    35,   125,    37,    38,    76,    98,    36,    39,
     139,   156,    37,    38,    34,    35,   157,    39,     0,     0,
       0,    36,   100,     0,     0,    37,    38,    34,    35,   121,
      39,     0,     0,     0,    36,    34,    35,     0,    37,    38,
       0,     0,    36,    39,     0,     0,    37,    38,     0,     0,
       0,    39
};

static const yytype_int16 yycheck[] =
{
       1,    20,    46,    54,    76,    24,    13,    14,    19,   144,
      31,    20,    15,    14,    37,    38,    39,    36,   153,    15,
      29,    30,    23,    26,    15,    44,    19,    46,    35,    36,
     165,    52,    51,    20,     0,    26,     0,    56,    59,     5,
      22,    60,    29,    30,    20,    68,    69,    70,    25,    50,
      27,    21,    19,    29,    30,    56,    26,    76,   130,    21,
      81,    20,    21,    82,    26,   116,   110,    18,    19,    88,
      18,    19,    23,    24,    25,    94,    25,    25,    29,    30,
      28,    29,    30,    34,    21,    25,    34,    27,    89,    26,
      22,   110,    26,    94,    27,    29,    30,     3,    27,     5,
       6,     7,     8,    21,   123,    19,    24,    23,   127,    15,
      16,   130,    18,    19,    20,    20,    21,    23,    24,    25,
      28,    29,    30,    29,    30,   144,    21,    27,    34,    24,
     149,   150,   151,   152,   153,    15,    16,    17,    31,    32,
      33,    29,    30,   144,    15,     3,   165,     5,     6,     7,
       8,    25,   153,    28,    29,    30,    25,    15,    16,    20,
      18,    19,    20,    20,   165,    23,    22,    25,    11,    12,
      10,    29,    30,   147,   148,     3,    34,     5,     6,     7,
       8,    26,    18,    19,    66,    67,     9,    23,    24,    25,
      18,    19,    20,    29,    30,    23,    26,    25,    34,     4,
      50,    29,    30,    18,    19,    23,    34,     5,    23,    29,
      25,    18,    19,    94,    29,    30,    23,    58,    25,    34,
     118,   145,    29,    30,    18,    19,   146,    34,    -1,    -1,
      -1,    25,    26,    -1,    -1,    29,    30,    18,    19,    20,
      34,    -1,    -1,    -1,    25,    18,    19,    -1,    29,    30,
      -1,    -1,    25,    34,    -1,    -1,    29,    30,    -1,    -1,
      -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    16,    17,    38,    39,    40,    41,    46,    51,
      19,    47,    48,    55,    15,    19,     0,    40,    51,    25,
      27,    56,    20,    21,    22,    19,    42,    43,    55,    25,
      15,    26,    52,    53,    18,    19,    25,    29,    30,    34,
      55,    62,    63,    64,    27,    48,    23,    49,    62,    20,
      21,    22,    26,    52,    19,    54,    23,    57,    21,    26,
      25,    62,    64,    64,    64,    28,    29,    30,    31,    32,
      33,    62,    24,    49,    50,    43,    23,    44,    61,    62,
      57,    26,    27,    56,     3,     5,     6,     7,     8,    15,
      20,    40,    55,    57,    58,    59,    60,    62,    53,    57,
      26,    62,    65,    26,    63,    63,    64,    64,    64,    28,
      21,    24,    24,    44,    45,    57,    28,    25,    25,    20,
      20,    20,    62,    22,    24,    59,    20,    21,    26,    49,
      21,    24,    56,    62,    66,    67,    68,    69,    70,    66,
      20,    62,    62,    44,    26,    10,     9,    11,    12,    13,
      14,    35,    36,    26,    20,    60,    68,    69,    70,    70,
      62,    62,    62,    62,    60,     4,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    39,    40,    40,    41,
      42,    42,    43,    44,    44,    44,    45,    45,    46,    47,
      47,    48,    48,    49,    49,    49,    50,    50,    51,    51,
      51,    51,    52,    52,    53,    54,    54,    54,    54,    55,
      55,    56,    56,    57,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      62,    62,    62,    63,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    65,    66,    67,    67,
      68,    68,    69,    69,    69,    70,    70,    70,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     1,     4,
       3,     1,     3,     1,     3,     2,     3,     1,     3,     3,
       1,     1,     3,     1,     3,     2,     3,     1,     6,     5,
       6,     5,     3,     1,     2,     4,     2,     3,     1,     2,
       1,     4,     3,     3,     2,     1,     1,     1,     4,     2,
       1,     1,     5,     7,     5,     2,     2,     3,     2,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     1,     1,
       4,     3,     2,     2,     2,     3,     1,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1
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
#line 19 "SysY.y"
                                                        { TreeRoot = yyvsp[0]; }
#line 1451 "SysY.tab.cpp"
    break;

  case 3:
#line 21 "SysY.y"
                                                        { yyval = &AppendStmt(*dynamic_cast<SeqStmt*>(yyvsp[-1]), *dynamic_cast<SeqStmt*>(yyvsp[0])); }
#line 1457 "SysY.tab.cpp"
    break;

  case 4:
#line 22 "SysY.y"
                                                        { yyval = &AppendStmt(*dynamic_cast<SeqStmt*>(yyvsp[-1]), *new SeqStmt(*dynamic_cast<Stmt*>(yyvsp[0]))); }
#line 1463 "SysY.tab.cpp"
    break;

  case 5:
#line 23 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1469 "SysY.tab.cpp"
    break;

  case 6:
#line 24 "SysY.y"
                                                        { yyval = new SeqStmt(*dynamic_cast<Stmt*>(yyvsp[0])); }
#line 1475 "SysY.tab.cpp"
    break;

  case 7:
#line 26 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1481 "SysY.tab.cpp"
    break;

  case 8:
#line 27 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1487 "SysY.tab.cpp"
    break;

  case 9:
#line 29 "SysY.y"
                                                        { yyval = yyvsp[-1]; }
#line 1493 "SysY.tab.cpp"
    break;

  case 10:
#line 31 "SysY.y"
                                                        { yyval = &AppendStmt(*dynamic_cast<SeqStmt*>(yyvsp[-2]), *new SeqStmt(*dynamic_cast<Stmt*>(yyvsp[0]))); }
#line 1499 "SysY.tab.cpp"
    break;

  case 11:
#line 32 "SysY.y"
                                                        { yyval = new SeqStmt(*dynamic_cast<Stmt*>(yyvsp[0])); }
#line 1505 "SysY.tab.cpp"
    break;

  case 12:
#line 34 "SysY.y"
                                                        { yyval = new Allocate(*dynamic_cast<Var*>(yyvsp[-2]), *dynamic_cast<Expr*>(yyvsp[0]), true); }
#line 1511 "SysY.tab.cpp"
    break;

  case 13:
#line 36 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1517 "SysY.tab.cpp"
    break;

  case 14:
#line 37 "SysY.y"
                                                        { yyval = yyvsp[-1]; }
#line 1523 "SysY.tab.cpp"
    break;

  case 15:
#line 38 "SysY.y"
                                                        { yyval = EmptyList<Expr>(); }
#line 1529 "SysY.tab.cpp"
    break;

  case 16:
#line 40 "SysY.y"
                                                        { yyval = &AppendList(*dynamic_cast<List<Expr>*>(yyvsp[-2]), *new List<Expr>(*dynamic_cast<Expr*>(yyvsp[0]))); }
#line 1535 "SysY.tab.cpp"
    break;

  case 17:
#line 41 "SysY.y"
                                                        { yyval = new List<Expr>(*dynamic_cast<Expr*>(yyvsp[0])); }
#line 1541 "SysY.tab.cpp"
    break;

  case 18:
#line 43 "SysY.y"
                                                       { yyval = yyvsp[-1]; }
#line 1547 "SysY.tab.cpp"
    break;

  case 19:
#line 45 "SysY.y"
                                                        { yyval = &AppendStmt(*dynamic_cast<SeqStmt*>(yyvsp[-2]), *new SeqStmt(*dynamic_cast<Stmt*>(yyvsp[0]))); }
#line 1553 "SysY.tab.cpp"
    break;

  case 20:
#line 46 "SysY.y"
                                                        { yyval = new SeqStmt(*dynamic_cast<Stmt*>(yyvsp[0])); }
#line 1559 "SysY.tab.cpp"
    break;

  case 21:
#line 48 "SysY.y"
                                                        { yyval = new Allocate(*dynamic_cast<Var*>(yyvsp[0]), Expr(), false); }
#line 1565 "SysY.tab.cpp"
    break;

  case 22:
#line 49 "SysY.y"
                                                        { yyval = new Allocate(*dynamic_cast<Var*>(yyvsp[-2]), *dynamic_cast<Expr*>(yyvsp[0]), true); }
#line 1571 "SysY.tab.cpp"
    break;

  case 23:
#line 51 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1577 "SysY.tab.cpp"
    break;

  case 24:
#line 52 "SysY.y"
                                                        { yyval = yyvsp[-1]; }
#line 1583 "SysY.tab.cpp"
    break;

  case 25:
#line 53 "SysY.y"
                                                        { yyval = EmptyList<Expr>(); }
#line 1589 "SysY.tab.cpp"
    break;

  case 26:
#line 55 "SysY.y"
                                                        { yyval = &AppendList(*dynamic_cast<List<Expr>*>(yyvsp[-2]), *new List<Expr>(*dynamic_cast<Expr*>(yyvsp[0]))); }
#line 1595 "SysY.tab.cpp"
    break;

  case 27:
#line 56 "SysY.y"
                                                        { yyval = new List<Expr>(*dynamic_cast<Expr*>(yyvsp[0])); }
#line 1601 "SysY.tab.cpp"
    break;

  case 28:
#line 58 "SysY.y"
                                                    { yyval = new Func(kVoid, *dynamic_cast<Var*>(yyvsp[-4]), *dynamic_cast<List<Var>*>(yyvsp[-2]), *dynamic_cast<SeqStmt*>(yyvsp[0])); }
#line 1607 "SysY.tab.cpp"
    break;

  case 29:
#line 59 "SysY.y"
                                                    { yyval = new Func(kVoid, *dynamic_cast<Var*>(yyvsp[-3]), *EmptyList<Var>(), *dynamic_cast<SeqStmt*>(yyvsp[0])); }
#line 1613 "SysY.tab.cpp"
    break;

  case 30:
#line 60 "SysY.y"
                                                   { yyval = new Func(kInt, *dynamic_cast<Var*>(yyvsp[-4]), *dynamic_cast<List<Var>*>(yyvsp[-2]), *dynamic_cast<SeqStmt*>(yyvsp[0])); }
#line 1619 "SysY.tab.cpp"
    break;

  case 31:
#line 61 "SysY.y"
                                                   { yyval = new Func(kInt, *dynamic_cast<Var*>(yyvsp[-3]), *EmptyList<Var>(), *dynamic_cast<SeqStmt*>(yyvsp[0])); }
#line 1625 "SysY.tab.cpp"
    break;

  case 32:
#line 63 "SysY.y"
                                                        { yyval = &AppendList(*dynamic_cast<List<Var>*>(yyvsp[-2]), *new List<Var>(*dynamic_cast<Var*>(yyvsp[0]))); }
#line 1631 "SysY.tab.cpp"
    break;

  case 33:
#line 64 "SysY.y"
                                                        { yyval = new List<Var>(*dynamic_cast<Var*>(yyvsp[0])); }
#line 1637 "SysY.tab.cpp"
    break;

  case 34:
#line 66 "SysY.y"
                                                       { yyval = yyvsp[0]; }
#line 1643 "SysY.tab.cpp"
    break;

  case 35:
#line 68 "SysY.y"
                                                        { yyval = new Array(*dynamic_cast<Var*>(yyvsp[-3]), *dynamic_cast<List<Expr>*>(yyvsp[-1]), true); }
#line 1649 "SysY.tab.cpp"
    break;

  case 36:
#line 69 "SysY.y"
                                                        { yyval = new Array(*dynamic_cast<Var*>(yyvsp[-1]), *dynamic_cast<List<Expr>*>(yyvsp[0]), false); }
#line 1655 "SysY.tab.cpp"
    break;

  case 37:
#line 70 "SysY.y"
                                                        { yyval = new Array(*dynamic_cast<Var*>(yyvsp[-2]), *EmptyList<Expr>(), true); }
#line 1661 "SysY.tab.cpp"
    break;

  case 38:
#line 71 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1667 "SysY.tab.cpp"
    break;

  case 39:
#line 73 "SysY.y"
                                                        { yyval = new Array(*dynamic_cast<Var*>(yyvsp[-1]), *dynamic_cast<List<Expr>*>(yyvsp[0]), false); }
#line 1673 "SysY.tab.cpp"
    break;

  case 40:
#line 74 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1679 "SysY.tab.cpp"
    break;

  case 41:
#line 76 "SysY.y"
                                                        { yyval = &AppendList(*dynamic_cast<List<Expr>*>(yyvsp[-3]), *new List<Expr>(*dynamic_cast<Expr*>(yyvsp[-1]))); }
#line 1685 "SysY.tab.cpp"
    break;

  case 42:
#line 77 "SysY.y"
                                                        { yyval = new List<Expr>(*dynamic_cast<Expr*>(yyvsp[-1])); }
#line 1691 "SysY.tab.cpp"
    break;

  case 43:
#line 79 "SysY.y"
                                                        { yyval = yyvsp[-1]; }
#line 1697 "SysY.tab.cpp"
    break;

  case 44:
#line 81 "SysY.y"
                                                        { yyval = &AppendStmt(*dynamic_cast<SeqStmt*>(yyvsp[-1]), *dynamic_cast<SeqStmt*>(yyvsp[0])); }
#line 1703 "SysY.tab.cpp"
    break;

  case 45:
#line 82 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1709 "SysY.tab.cpp"
    break;

  case 46:
#line 84 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1715 "SysY.tab.cpp"
    break;

  case 47:
#line 85 "SysY.y"
                                                        { yyval = new SeqStmt(*dynamic_cast<Stmt*>(yyvsp[0])); }
#line 1721 "SysY.tab.cpp"
    break;

  case 48:
#line 87 "SysY.y"
                                                        { yyval = new Store(*dynamic_cast<Var*>(yyvsp[-3]), *dynamic_cast<Expr*>(yyvsp[-1])); }
#line 1727 "SysY.tab.cpp"
    break;

  case 49:
#line 88 "SysY.y"
                                                        { yyval = new Evaluate(*dynamic_cast<Expr*>(yyvsp[-1])); }
#line 1733 "SysY.tab.cpp"
    break;

  case 50:
#line 89 "SysY.y"
                                                        { yyval = new Stmt(); }
#line 1739 "SysY.tab.cpp"
    break;

  case 51:
#line 90 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1745 "SysY.tab.cpp"
    break;

  case 52:
#line 91 "SysY.y"
                                                        { yyval = new IfThenElse(*dynamic_cast<Expr*>(yyvsp[-2]), *dynamic_cast<Stmt*>(yyvsp[0])); }
#line 1751 "SysY.tab.cpp"
    break;

  case 53:
#line 92 "SysY.y"
                                                        { yyval = new IfThenElse(*dynamic_cast<Expr*>(yyvsp[-4]), *dynamic_cast<Stmt*>(yyvsp[-2]), *dynamic_cast<Stmt*>(yyvsp[0]), true); }
#line 1757 "SysY.tab.cpp"
    break;

  case 54:
#line 93 "SysY.y"
                                                        { yyval = new While(*dynamic_cast<Expr*>(yyvsp[-2]), *dynamic_cast<Stmt*>(yyvsp[0])); }
#line 1763 "SysY.tab.cpp"
    break;

  case 55:
#line 94 "SysY.y"
                                                        { yyval = new Goto("next"); }
#line 1769 "SysY.tab.cpp"
    break;

  case 56:
#line 95 "SysY.y"
                                                        { yyval = new Goto("begin"); }
#line 1775 "SysY.tab.cpp"
    break;

  case 57:
#line 96 "SysY.y"
                                                        { yyval = new Ret(*dynamic_cast<Expr*>(yyvsp[-1]), true); }
#line 1781 "SysY.tab.cpp"
    break;

  case 58:
#line 97 "SysY.y"
                                                        { yyval = new Ret(Expr(), false); }
#line 1787 "SysY.tab.cpp"
    break;

  case 59:
#line 99 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1793 "SysY.tab.cpp"
    break;

  case 60:
#line 101 "SysY.y"
                                                        { yyval = new BinaryOp(*dynamic_cast<Expr*>(yyvsp[-2]), kAdd, *dynamic_cast<Expr*>(yyvsp[0])); }
#line 1799 "SysY.tab.cpp"
    break;

  case 61:
#line 102 "SysY.y"
                                                        { yyval = new BinaryOp(*dynamic_cast<Expr*>(yyvsp[-2]), kSub, *dynamic_cast<Expr*>(yyvsp[0])); }
#line 1805 "SysY.tab.cpp"
    break;

  case 62:
#line 103 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1811 "SysY.tab.cpp"
    break;

  case 63:
#line 105 "SysY.y"
                                                        { yyval = new BinaryOp(*dynamic_cast<Expr*>(yyvsp[-2]), kMul, *dynamic_cast<Expr*>(yyvsp[0])); }
#line 1817 "SysY.tab.cpp"
    break;

  case 64:
#line 106 "SysY.y"
                                                        { yyval = new BinaryOp(*dynamic_cast<Expr*>(yyvsp[-2]), kDiv, *dynamic_cast<Expr*>(yyvsp[0])); }
#line 1823 "SysY.tab.cpp"
    break;

  case 65:
#line 107 "SysY.y"
                                                        { yyval = new BinaryOp(*dynamic_cast<Expr*>(yyvsp[-2]), kMod, *dynamic_cast<Expr*>(yyvsp[0])); }
#line 1829 "SysY.tab.cpp"
    break;

  case 66:
#line 108 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1835 "SysY.tab.cpp"
    break;

  case 67:
#line 110 "SysY.y"
                                                        { yyval = yyvsp[-1]; }
#line 1841 "SysY.tab.cpp"
    break;

  case 68:
#line 111 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1847 "SysY.tab.cpp"
    break;

  case 69:
#line 112 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1853 "SysY.tab.cpp"
    break;

  case 70:
#line 113 "SysY.y"
                                                        { yyval = new Call(*dynamic_cast<Var*>(yyvsp[-3]), *dynamic_cast<List<Expr>*>(yyvsp[-1])); }
#line 1859 "SysY.tab.cpp"
    break;

  case 71:
#line 114 "SysY.y"
                                                        { yyval = new Call(*dynamic_cast<Var*>(yyvsp[-2]), *EmptyList<Expr>()); }
#line 1865 "SysY.tab.cpp"
    break;

  case 72:
#line 115 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1871 "SysY.tab.cpp"
    break;

  case 73:
#line 116 "SysY.y"
                                                        { yyval = new BinaryOp(Imm(kInt, 0), kSub, *dynamic_cast<Expr*>(yyvsp[0])); }
#line 1877 "SysY.tab.cpp"
    break;

  case 74:
#line 117 "SysY.y"
                                                        { yyval = new Not(*dynamic_cast<Expr*>(yyvsp[0])); }
#line 1883 "SysY.tab.cpp"
    break;

  case 75:
#line 119 "SysY.y"
                                                        { yyval = &AppendList(*dynamic_cast<List<Expr>*>(yyvsp[-2]), *new List<Expr>(*dynamic_cast<Expr*>(yyvsp[0]))); }
#line 1889 "SysY.tab.cpp"
    break;

  case 76:
#line 120 "SysY.y"
                                                        { yyval = new List<Expr>(*dynamic_cast<Expr*>(yyvsp[0])); }
#line 1895 "SysY.tab.cpp"
    break;

  case 77:
#line 123 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1901 "SysY.tab.cpp"
    break;

  case 78:
#line 125 "SysY.y"
                                                        { yyval = new BinaryOp(*dynamic_cast<Expr*>(yyvsp[-2]), kOr, *dynamic_cast<Expr*>(yyvsp[0])); }
#line 1907 "SysY.tab.cpp"
    break;

  case 79:
#line 126 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1913 "SysY.tab.cpp"
    break;

  case 80:
#line 128 "SysY.y"
                                                        { yyval = new BinaryOp(*dynamic_cast<Expr*>(yyvsp[-2]), kAnd, *dynamic_cast<Expr*>(yyvsp[0])); }
#line 1919 "SysY.tab.cpp"
    break;

  case 81:
#line 129 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1925 "SysY.tab.cpp"
    break;

  case 82:
#line 131 "SysY.y"
                                                        { yyval = new BinaryOp(*dynamic_cast<Expr*>(yyvsp[-2]), kEQ, *dynamic_cast<Expr*>(yyvsp[0])); }
#line 1931 "SysY.tab.cpp"
    break;

  case 83:
#line 132 "SysY.y"
                                                        { yyval = new BinaryOp(*dynamic_cast<Expr*>(yyvsp[-2]), kNEQ, *dynamic_cast<Expr*>(yyvsp[0])); }
#line 1937 "SysY.tab.cpp"
    break;

  case 84:
#line 133 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1943 "SysY.tab.cpp"
    break;

  case 85:
#line 135 "SysY.y"
                                                        { yyval = new BinaryOp(*dynamic_cast<Expr*>(yyvsp[-2]), kLT, *dynamic_cast<Expr*>(yyvsp[0])); }
#line 1949 "SysY.tab.cpp"
    break;

  case 86:
#line 136 "SysY.y"
                                                        { yyval = new BinaryOp(*dynamic_cast<Expr*>(yyvsp[-2]), kGT, *dynamic_cast<Expr*>(yyvsp[0])); }
#line 1955 "SysY.tab.cpp"
    break;

  case 87:
#line 137 "SysY.y"
                                                        { yyval = new BinaryOp(*dynamic_cast<Expr*>(yyvsp[-2]), kLEQ, *dynamic_cast<Expr*>(yyvsp[0])); }
#line 1961 "SysY.tab.cpp"
    break;

  case 88:
#line 138 "SysY.y"
                                                        { yyval = new BinaryOp(*dynamic_cast<Expr*>(yyvsp[-2]), kGEQ, *dynamic_cast<Expr*>(yyvsp[0])); }
#line 1967 "SysY.tab.cpp"
    break;

  case 89:
#line 139 "SysY.y"
                                                        { yyval = yyvsp[0]; }
#line 1973 "SysY.tab.cpp"
    break;


#line 1977 "SysY.tab.cpp"

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
#line 141 "SysY.y"

int yyerror(const char *message) {
	return 0;
}
