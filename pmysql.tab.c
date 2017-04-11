/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 6 "pmysql.y" /* yacc.c:339  */

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
void yyerror(char *s, ...);
void show_log(char *s, ...);
#if YYBISON
union YYSTYPE;
//int yylex(union YYSTYPE *, void *); //for re-entrant?
int yylex();
#endif

#line 80 "pmysql.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "pmysql.tab.h".  */
#ifndef YY_YY_PMYSQL_TAB_H_INCLUDED
# define YY_YY_PMYSQL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NAME = 258,
    STRING = 259,
    INTNUM = 260,
    BOOL = 261,
    APPROXNUM = 262,
    USERVAR = 263,
    ASSIGN = 264,
    OR = 265,
    XOR = 266,
    ANDOP = 267,
    IN = 268,
    IS = 269,
    LIKE = 270,
    REGEXP = 271,
    NOT = 272,
    BETWEEN = 273,
    COMPARISON = 274,
    SHIFT = 275,
    MOD = 276,
    UMINUS = 277,
    ADD = 278,
    ALL = 279,
    ALTER = 280,
    ANALYZE = 281,
    AND = 282,
    ANY = 283,
    AS = 284,
    ASC = 285,
    AUTO_INCREMENT = 286,
    BEFORE = 287,
    BIGINT = 288,
    BINARY = 289,
    BIT = 290,
    BLOB = 291,
    BOTH = 292,
    BY = 293,
    CALL = 294,
    CASCADE = 295,
    CASE = 296,
    CHANGE = 297,
    CHAR = 298,
    CHECK = 299,
    COLLATE = 300,
    COLUMN = 301,
    COMMENT = 302,
    CONDITION = 303,
    CONSTRAINT = 304,
    CONTINUE = 305,
    CONVERT = 306,
    CREATE = 307,
    CROSS = 308,
    CURRENT_DATE = 309,
    CURRENT_TIME = 310,
    CURRENT_TIMESTAMP = 311,
    CURRENT_USER = 312,
    CURSOR = 313,
    DATABASE = 314,
    DATABASES = 315,
    DATE = 316,
    DATETIME = 317,
    DAY_HOUR = 318,
    DAY_MICROSECOND = 319,
    DAY_MINUTE = 320,
    DAY_SECOND = 321,
    DECIMAL = 322,
    DECLARE = 323,
    DEFAULT = 324,
    DELAYED = 325,
    DELETE = 326,
    DESC = 327,
    DESCRIBE = 328,
    DETERMINISTIC = 329,
    DISTINCT = 330,
    DISTINCTROW = 331,
    DIV = 332,
    DOUBLE = 333,
    DROP = 334,
    DUAL = 335,
    EACH = 336,
    ELSE = 337,
    ELSEIF = 338,
    ENCLOSED = 339,
    END = 340,
    ENUM = 341,
    ESCAPED = 342,
    EXISTS = 343,
    EXIT = 344,
    EXPLAIN = 345,
    FETCH = 346,
    FLOAT = 347,
    FOR = 348,
    FORCE = 349,
    FOREIGN = 350,
    FROM = 351,
    FULLTEXT = 352,
    GRANT = 353,
    GROUP = 354,
    HAVING = 355,
    HIGH_PRIORITY = 356,
    HOUR_MICROSECOND = 357,
    HOUR_MINUTE = 358,
    HOUR_SECOND = 359,
    IF = 360,
    IGNORE = 361,
    IMPORT = 362,
    INDEX = 363,
    INFILE = 364,
    INNER = 365,
    INOUT = 366,
    INSENSITIVE = 367,
    INSERT = 368,
    INT = 369,
    INTEGER = 370,
    INTERVAL = 371,
    INTO = 372,
    ITERATE = 373,
    JOIN = 374,
    KEY = 375,
    KEYS = 376,
    KILL = 377,
    LEADING = 378,
    LEAVE = 379,
    LEFT = 380,
    LIMIT = 381,
    LINES = 382,
    LOAD = 383,
    LOCALTIME = 384,
    LOCALTIMESTAMP = 385,
    LOCK = 386,
    LONG = 387,
    LONGBLOB = 388,
    LONGTEXT = 389,
    LOOP = 390,
    LOW_PRIORITY = 391,
    MATCH = 392,
    MEDIUMBLOB = 393,
    MEDIUMINT = 394,
    MEDIUMTEXT = 395,
    MINUTE_MICROSECOND = 396,
    MINUTE_SECOND = 397,
    MODIFIES = 398,
    NATURAL = 399,
    NO_WRITE_TO_BINLOG = 400,
    NULLX = 401,
    NUMBER = 402,
    ON = 403,
    ONDUPLICATE = 404,
    OPTIMIZE = 405,
    OPTION = 406,
    OPTIONALLY = 407,
    ORDER = 408,
    OUT = 409,
    OUTER = 410,
    OUTFILE = 411,
    PRECISION = 412,
    PRIMARY = 413,
    PROCEDURE = 414,
    PURGE = 415,
    QUICK = 416,
    READ = 417,
    READS = 418,
    REAL = 419,
    REFERENCES = 420,
    RELEASE = 421,
    RENAME = 422,
    REPEAT = 423,
    REPLACE = 424,
    REQUIRE = 425,
    RESTRICT = 426,
    RETURN = 427,
    REVOKE = 428,
    RIGHT = 429,
    ROLLUP = 430,
    SCHEMA = 431,
    SCHEMAS = 432,
    SECOND_MICROSECOND = 433,
    SELECT = 434,
    SENSITIVE = 435,
    SEPARATOR = 436,
    SET = 437,
    SHOW = 438,
    SMALLINT = 439,
    SOME = 440,
    SONAME = 441,
    SPATIAL = 442,
    SPECIFIC = 443,
    SQL = 444,
    SQLEXCEPTION = 445,
    SQLSTATE = 446,
    SQLWARNING = 447,
    SQL_BIG_RESULT = 448,
    SQL_CALC_FOUND_ROWS = 449,
    SQL_SMALL_RESULT = 450,
    SSL = 451,
    STARTING = 452,
    STRAIGHT_JOIN = 453,
    TABLE = 454,
    TEMPORARY = 455,
    TEST_SEL = 456,
    TEXT = 457,
    TERMINATED = 458,
    THEN = 459,
    TIME = 460,
    TIMESTAMP = 461,
    TINYBLOB = 462,
    TINYINT = 463,
    TINYTEXT = 464,
    TO = 465,
    TRAILING = 466,
    TRIGGER = 467,
    UNDO = 468,
    UNION = 469,
    UNIQUE = 470,
    UNLOCK = 471,
    UNSIGNED = 472,
    UPDATE = 473,
    USAGE = 474,
    USE = 475,
    USING = 476,
    UTC_DATE = 477,
    UTC_TIME = 478,
    UTC_TIMESTAMP = 479,
    VALUES = 480,
    VARBINARY = 481,
    VARCHAR = 482,
    VARYING = 483,
    WHEN = 484,
    WHERE = 485,
    WHILE = 486,
    WITH = 487,
    WRITE = 488,
    YEAR = 489,
    YEAR_MONTH = 490,
    ZEROFILL = 491,
    FSUBSTRING = 492,
    FTRIM = 493,
    FDATE_ADD = 494,
    FDATE_SUB = 495,
    FCOUNT = 496,
    FSUM = 497
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 21 "pmysql.y" /* yacc.c:355  */

	int intval;
	double floatval;
	char *strval;
	int subtok;
	attr_node_header_t *attr_node;
	table_node_t *table_node;
	stmt_node_t *stmt_node;
	col_node_t *col_node;
	insert_vals_node_t *insr_node;
	expr_node_t *expr_node;
	char *alias_name;// 0401
	select_col_node_t *select_col_node;//0401
	select_table_node_t *select_table_node;//0401
	cret_def_node_t *cret_node;

#line 380 "pmysql.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PMYSQL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 395 "pmysql.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1600

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  257
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  286
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  597

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   497

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    18,     2,     2,     2,    28,    22,     2,
     254,   255,    26,    24,   256,    25,   253,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   252,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    21,     2,     2,     2,     2,     2,
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
      15,    16,    17,    19,    20,    23,    29,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   328,   328,   329,   332,   334,   335,   337,   339,   343,
     345,   348,   351,   357,   362,   367,   372,   373,   376,   377,
     378,   379,   380,   383,   383,   386,   387,   390,   391,   394,
     395,   396,   397,   400,   406,   412,   415,   418,   421,   427,
     430,   435,   440,   445,   450,   451,   452,   453,   454,   456,
     462,   467,   468,   471,   472,   472,   475,   476,   477,   478,
     479,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   497,   498,   499,   506,   507,   508,
     511,   512,   513,   517,   518,   555,   558,   559,   560,   563,
     564,   572,   575,   577,   583,   584,   586,   587,   591,   593,
     597,   598,   599,   602,   603,   606,   606,   608,   608,   611,
     611,   612,   615,   616,   619,   620,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   634,   635,   636,   639,   641,
     642,   645,   646,   650,   651,   653,   654,   657,   658,   661,
     662,   663,   667,   669,   671,   673,   675,   679,   680,   681,
     684,   685,   688,   689,   692,   693,   694,   697,   697,   700,
     701,   705,   707,   709,   711,   714,   715,   718,   719,   722,
     727,   730,   735,   736,   737,   738,   741,   746,   747,   751,
     751,   753,   759,   762,   768,   774,   780,   783,   790,   791,
     792,   796,   799,   802,   805,   813,   817,   818,   821,   822,
     827,   830,   832,   832,   835,   837,   842,   843,   844,   845,
     846,   847,   848,   851,   852,   853,   854,   855,   856,   857,
     858,   859,   860,   861,   862,   863,   864,   865,   866,   867,
     868,   869,   870,   871,   872,   875,   876,   877,   878,   881,
     885,   886,   889,   890,   893,   894,   895,   896,   897,   900,
     904,   905,   907,   908,   910,   911,   912,   913,   914,   917,
     918,   919,   922,   923,   926,   927,   928,   929,   930,   931,
     932,   933,   934,   937,   938,   939,   940,   943,   944,   947,
     948,   951,   952,   955,   956,   957,   960
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "STRING", "INTNUM", "BOOL",
  "APPROXNUM", "USERVAR", "ASSIGN", "OR", "XOR", "ANDOP", "IN", "IS",
  "LIKE", "REGEXP", "NOT", "'!'", "BETWEEN", "COMPARISON", "'|'", "'&'",
  "SHIFT", "'+'", "'-'", "'*'", "'/'", "'%'", "MOD", "'^'", "UMINUS",
  "ADD", "ALL", "ALTER", "ANALYZE", "AND", "ANY", "AS", "ASC",
  "AUTO_INCREMENT", "BEFORE", "BIGINT", "BINARY", "BIT", "BLOB", "BOTH",
  "BY", "CALL", "CASCADE", "CASE", "CHANGE", "CHAR", "CHECK", "COLLATE",
  "COLUMN", "COMMENT", "CONDITION", "CONSTRAINT", "CONTINUE", "CONVERT",
  "CREATE", "CROSS", "CURRENT_DATE", "CURRENT_TIME", "CURRENT_TIMESTAMP",
  "CURRENT_USER", "CURSOR", "DATABASE", "DATABASES", "DATE", "DATETIME",
  "DAY_HOUR", "DAY_MICROSECOND", "DAY_MINUTE", "DAY_SECOND", "DECIMAL",
  "DECLARE", "DEFAULT", "DELAYED", "DELETE", "DESC", "DESCRIBE",
  "DETERMINISTIC", "DISTINCT", "DISTINCTROW", "DIV", "DOUBLE", "DROP",
  "DUAL", "EACH", "ELSE", "ELSEIF", "ENCLOSED", "END", "ENUM", "ESCAPED",
  "EXISTS", "EXIT", "EXPLAIN", "FETCH", "FLOAT", "FOR", "FORCE", "FOREIGN",
  "FROM", "FULLTEXT", "GRANT", "GROUP", "HAVING", "HIGH_PRIORITY",
  "HOUR_MICROSECOND", "HOUR_MINUTE", "HOUR_SECOND", "IF", "IGNORE",
  "IMPORT", "INDEX", "INFILE", "INNER", "INOUT", "INSENSITIVE", "INSERT",
  "INT", "INTEGER", "INTERVAL", "INTO", "ITERATE", "JOIN", "KEY", "KEYS",
  "KILL", "LEADING", "LEAVE", "LEFT", "LIMIT", "LINES", "LOAD",
  "LOCALTIME", "LOCALTIMESTAMP", "LOCK", "LONG", "LONGBLOB", "LONGTEXT",
  "LOOP", "LOW_PRIORITY", "MATCH", "MEDIUMBLOB", "MEDIUMINT", "MEDIUMTEXT",
  "MINUTE_MICROSECOND", "MINUTE_SECOND", "MODIFIES", "NATURAL",
  "NO_WRITE_TO_BINLOG", "NULLX", "NUMBER", "ON", "ONDUPLICATE", "OPTIMIZE",
  "OPTION", "OPTIONALLY", "ORDER", "OUT", "OUTER", "OUTFILE", "PRECISION",
  "PRIMARY", "PROCEDURE", "PURGE", "QUICK", "READ", "READS", "REAL",
  "REFERENCES", "RELEASE", "RENAME", "REPEAT", "REPLACE", "REQUIRE",
  "RESTRICT", "RETURN", "REVOKE", "RIGHT", "ROLLUP", "SCHEMA", "SCHEMAS",
  "SECOND_MICROSECOND", "SELECT", "SENSITIVE", "SEPARATOR", "SET", "SHOW",
  "SMALLINT", "SOME", "SONAME", "SPATIAL", "SPECIFIC", "SQL",
  "SQLEXCEPTION", "SQLSTATE", "SQLWARNING", "SQL_BIG_RESULT",
  "SQL_CALC_FOUND_ROWS", "SQL_SMALL_RESULT", "SSL", "STARTING",
  "STRAIGHT_JOIN", "TABLE", "TEMPORARY", "TEST_SEL", "TEXT", "TERMINATED",
  "THEN", "TIME", "TIMESTAMP", "TINYBLOB", "TINYINT", "TINYTEXT", "TO",
  "TRAILING", "TRIGGER", "UNDO", "UNION", "UNIQUE", "UNLOCK", "UNSIGNED",
  "UPDATE", "USAGE", "USE", "USING", "UTC_DATE", "UTC_TIME",
  "UTC_TIMESTAMP", "VALUES", "VARBINARY", "VARCHAR", "VARYING", "WHEN",
  "WHERE", "WHILE", "WITH", "WRITE", "YEAR", "YEAR_MONTH", "ZEROFILL",
  "FSUBSTRING", "FTRIM", "FDATE_ADD", "FDATE_SUB", "FCOUNT", "FSUM", "';'",
  "'.'", "'('", "')'", "','", "$accept", "stmt_list", "stmt",
  "show_log_stmt", "import_file_stmt", "test_stmt", "insert_stmt",
  "opt_ondupupdate", "insert_opts", "opt_into", "opt_col_names",
  "insert_vals_list", "insert_vals", "insert_asgn_list",
  "create_table_stmt", "create_col_list", "create_definition", "$@1",
  "column_atts", "opt_length", "opt_uz", "opt_csc", "data_type",
  "create_select_statement", "opt_ignore_replace", "opt_temporary",
  "select_stmt", "opt_where", "opt_groupby", "groupby_list",
  "opt_asc_desc", "opt_with_rollup", "opt_having", "opt_orderby",
  "opt_limit", "opt_into_list", "column_list", "select_opts",
  "select_expr_list", "select_expr", "table_references", "table_reference",
  "table_factor", "opt_as", "opt_as_alias", "join_table",
  "opt_inner_cross", "opt_outer", "left_or_right",
  "opt_left_or_right_outer", "opt_join_condition", "join_condition",
  "index_hint", "opt_for_join", "index_list", "table_subquery",
  "delete_stmt", "delete_opts", "delete_list", "opt_dot_star",
  "replace_stmt", "update_stmt", "update_opts", "update_asgn_list",
  "create_database_stmt", "opt_if_not_exists", "set_stmt", "set_list",
  "set_expr", "expr", "val_list", "opt_val_list", "trim_ltb",
  "interval_exp", "case_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    33,   273,
     274,   124,    38,   275,    43,    45,    42,    47,    37,   276,
      94,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,    59,    46,    40,    41,    44
};
# endif

#define YYPACT_NINF -368

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-368)))

#define YYTABLE_NINF -191

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-191)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1106,   113,   -30,  -368,    61,  -368,  -368,  -368,   158,   198,
    -368,     2,   218,   -79,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,  -368,   -52,   -10,    97,    97,
      25,     8,   -49,   -52,   -52,   287,    53,   -42,  -368,  -368,
    -368,   191,     4,  -368,   -16,  -368,  -368,  -368,  -368,  -368,
    -368,   222,    97,   179,   275,   277,    97,    97,   282,    64,
     293,  -368,  -368,  -368,   -73,   121,   330,   332,    55,  -368,
    -368,  -368,  -368,   361,   771,   771,   771,  -368,  -368,   771,
     396,  -368,  -368,  -368,  -368,  -368,   133,  -368,  -368,  -368,
    -368,  -368,   141,   144,   151,   166,   182,   188,   -72,  -368,
    1434,   771,   771,   158,     6,     7,     9,     3,  -120,    43,
    -368,  -368,   337,  -368,   190,   409,  -368,  -368,  -368,   463,
     467,   234,   446,  -368,    58,    -7,     4,   478,  -368,  -113,
    -112,   489,   771,   771,   562,   562,  -368,  -368,   771,  1128,
     -41,   307,   771,   142,   771,   771,   479,   506,     4,   771,
    -368,   771,   771,   771,   254,    40,   771,   771,    86,   771,
      18,   771,   771,   771,   771,   771,   771,   771,   771,   771,
     771,   512,  -368,  1495,  1495,  -368,   513,   -27,   262,    69,
     515,     4,  -368,  -368,  -368,    60,  -368,     4,   391,   356,
    -368,   518,   522,   292,   273,   285,    46,   212,  -368,   771,
     368,     4,  -191,    64,   537,     1,   537,  -154,  -368,   912,
    -368,   286,  1495,  1180,   -19,   771,  -368,   771,   290,   859,
     291,  -368,  -368,  -368,   295,   771,   933,   955,   296,  1035,
     297,  1056,  -191,  -368,  1515,  1534,  1552,   555,  -368,    13,
    -368,  1570,  1570,   294,   771,   771,  1468,   299,   300,   301,
     307,   869,   736,   428,   450,   389,   389,   517,   517,   517,
     517,  -368,  -368,    57,   436,   437,   438,  -368,  -368,  -368,
      -6,    47,    43,   356,   356,   429,   407,     4,  -368,   440,
    -368,  -368,    72,   320,   212,   212,   100,  -368,   321,   323,
     449,  -368,   576,   212,    76,  -368,   590,  -368,   337,    83,
    1495,   547,   460,  -191,  -368,  -368,   577,   -69,   320,   320,
     605,   -14,   441,   -69,   320,   441,   771,  -368,   771,   771,
    -368,  1348,  1223,  -368,   771,  -368,  -368,  1251,   471,   471,
    -368,  -368,  -368,  -368,   492,   346,   347,  -368,  -368,   555,
    1570,  1570,   771,   307,   307,   307,   349,   -27,   504,   504,
     504,   771,   604,   611,   368,  -368,  -368,     4,   771,  -139,
       4,  -368,   612,   -14,    90,    93,   362,   363,   522,   522,
     367,   -38,   109,  -368,   212,   -28,   307,  -368,   771,   771,
    -368,  -368,   654,   495,   622,  -368,   -14,   -14,  -368,   112,
    1495,   372,  -368,  -368,  -368,   -14,  -368,  -368,  1495,  1375,
    -368,   771,  1014,   771,   771,   373,   374,   580,   523,  -368,
    -368,   376,   378,  1279,   380,   381,   382,  -368,  -368,   510,
     385,   386,   387,  1495,   629,    -5,   460,  -368,  1495,   771,
     397,  -368,  -368,  -139,  -368,  -368,  -368,  -368,   522,   522,
     118,   122,   522,   212,  -368,   -78,  -368,   399,   400,  -368,
    -368,   394,  1396,   976,  -368,  1495,   439,   636,  -368,  -368,
    -368,   670,   605,  -368,  -368,  1495,   771,  -368,   408,  1107,
    -368,  -368,   771,   771,   368,  -368,  -368,  -368,  -368,  -368,
    -368,   661,   661,   661,   771,   771,   662,  -368,  1495,   522,
    -368,   127,   130,  -368,  -368,   152,   167,  -368,   675,  -368,
     676,    14,   771,  -368,  -368,  -368,   771,   537,   765,  -368,
    1495,   169,  1077,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,    -4,  1495,   460,  -368,   174,   177,   185,
    1495,  1495,   647,   192,  -368,  -368,  -368,   -59,   207,  -141,
     427,   529,  -368,   681,   351,  -368,  -368,   557,  -100,  1396,
    1495,   433,  -368,  1495,  -368,  -368,   507,  -368,   564,  -368,
     689,  -368,  -368,   771,  -368,  -368,  -368,   688,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,   522,
    -368,  -368,   522,  -368,  -368,  1495,   443,   168,   209,   444,
    -368,   503,   692,  -368,   695,  -368,  -368
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    18,    89,   175,     0,    18,    18,   116,     0,     0,
      10,    18,     0,     0,     4,     7,     9,    11,    39,    91,
     170,   182,   186,   195,   200,    90,    24,     0,   198,   198,
       0,     0,     0,    24,    24,     0,     0,   201,   202,     5,
       6,     0,     0,     1,     0,     2,    20,    21,    22,    23,
      19,     0,   198,     0,     0,     0,   198,   198,     0,   179,
       0,   174,   172,   173,     0,     0,     0,     0,   206,   209,
     210,   212,   211,   207,     0,     0,     0,   127,   117,     0,
       0,   284,   285,   283,   118,   119,     0,   120,   123,   124,
     122,   121,     0,     0,     0,     0,     0,     0,    92,   125,
     141,     0,     0,     0,    22,    19,   141,     0,     0,   129,
     131,   132,   138,     3,    25,     0,   199,   196,   197,     0,
       0,     0,     0,   177,    94,     0,     0,     0,     8,    25,
      25,     0,   242,     0,   232,   233,   219,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,   205,   204,   203,     0,   164,     0,     0,
       0,     0,   149,   148,   152,   156,   153,     0,     0,   150,
     137,     0,     0,     0,     0,     0,    53,    53,   180,     0,
     107,     0,    94,   179,     0,     0,     0,     0,   208,   240,
     243,     0,   234,     0,     0,     0,   275,     0,     0,   240,
       0,   261,   259,   260,     0,     0,     0,     0,     0,     0,
       0,     0,    94,   126,   221,   222,   220,     0,   237,     0,
     235,   279,   281,     0,     0,     0,     0,     0,     0,     0,
       0,   223,   228,   229,   231,   213,   214,   215,   216,   217,
     218,   230,   139,   141,     0,     0,     0,   133,   169,   136,
       0,    94,   130,   150,   150,     0,   143,     0,   151,     0,
     135,   114,     0,     0,    53,    53,     0,    87,     0,     0,
       0,    88,     0,    53,     0,    51,     0,    43,   138,     0,
      95,     0,   109,    94,   176,   178,     0,    16,     0,     0,
       0,    16,    16,    16,     0,    16,     0,   249,     0,     0,
     273,     0,     0,   248,     0,   254,   257,     0,     0,     0,
     250,   251,   252,   253,    96,     0,     0,   238,   236,     0,
     280,   282,     0,     0,     0,     0,     0,   164,   166,   166,
     166,     0,     0,     0,   107,   154,   155,     0,     0,   158,
       0,    26,     0,    16,     0,     0,     0,     0,     0,     0,
       0,    86,    46,    45,    53,     0,     0,    44,     0,     0,
     171,   181,     0,     0,     0,    33,    16,    16,    30,     0,
      29,     0,    14,    34,   184,    16,   185,   241,   277,     0,
     276,     0,     0,     0,     0,     0,     0,     0,   105,   246,
     244,     0,     0,   239,     0,     0,     0,   224,   134,     0,
       0,     0,     0,   191,     0,     0,   109,   146,   144,     0,
       0,   142,   157,     0,   115,    13,    47,    48,     0,     0,
       0,     0,     0,    53,    50,    86,    52,    74,     0,    61,
      85,   108,   100,   110,    36,    35,     0,     0,    15,    12,
      27,     0,     0,   183,   274,   278,     0,   255,     0,     0,
     262,   263,     0,     0,   107,   247,   245,   227,   225,   226,
     165,     0,     0,     0,     0,     0,     0,   187,   159,     0,
     145,     0,     0,    58,    57,     0,     0,    42,     0,    77,
       0,    55,     0,   101,   102,    98,     0,     0,     0,    32,
      31,     0,     0,   258,   264,   265,   266,   267,   270,   271,
     272,   269,   268,   103,   106,   109,   167,     0,     0,     0,
     192,   193,     0,     0,    59,    60,    56,    86,     0,    83,
       0,     0,    68,     0,     0,    72,    63,     0,     0,   100,
     111,    17,    38,    37,    28,   256,     0,    97,   112,   163,
       0,   162,   161,     0,   160,    49,    75,     0,    78,    79,
      80,    62,    73,    64,    65,    67,    66,    71,    70,     0,
      99,   104,     0,    93,   168,   194,     0,    84,     0,   113,
      76,     0,     0,    69,     0,    82,    81
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -368,  -368,   691,  -368,  -368,  -368,  -368,    48,   276,   435,
     369,   -55,   239,  -205,  -368,  -128,   331,  -368,  -368,  -368,
    -368,  -368,  -368,  -351,  -368,   704,   -99,    39,  -368,   235,
     159,  -368,  -368,  -302,  -367,  -368,  -352,  -368,  -368,   560,
     125,   530,  -157,   412,   -93,  -368,  -368,   227,  -368,  -368,
    -368,   279,   375,   153,    24,  -368,  -368,  -368,   655,   511,
    -368,  -368,  -368,  -368,  -368,   324,  -368,  -368,   613,   -35,
    -140,  -368,  -368,   392,   584
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    17,   385,    26,    51,
     193,   311,   389,   307,    18,   294,   295,   296,   501,   499,
     539,   587,   449,   297,   298,    27,    19,   200,   408,   451,
     505,   557,   474,   302,   380,   583,   282,    35,    98,    99,
     108,   109,   110,   191,   172,   111,   188,   279,   189,   275,
     431,   432,   267,   420,   527,   112,    20,    31,    64,   123,
      21,    22,    42,   271,    23,    54,    24,    37,    38,   209,
     210,   211,   225,   405,   140
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     100,   313,   220,   224,   308,  -188,   106,   106,   178,  -190,
    -189,    59,   150,   177,   351,   485,   440,   441,   429,   337,
     444,    68,    69,    70,    71,    72,    73,    46,    56,   578,
     276,   541,   126,   148,     7,    74,    75,   287,    28,   134,
     135,   136,   218,    76,   137,   139,   238,   171,   199,   -54,
     215,   247,   426,   216,   542,   248,   287,   239,    47,   487,
     150,    79,   101,    48,    32,   181,   173,   174,    80,   299,
     543,   180,   319,   102,    49,   320,   264,   287,   204,   206,
     314,    81,    82,    83,   -86,   568,   491,   492,   265,   383,
     495,   430,   544,    50,   497,   171,   447,   336,   212,   243,
     291,   244,   245,   213,   569,   182,   312,   219,   315,   226,
     227,   229,   231,    60,   100,    86,   234,   235,   236,   291,
     359,   241,   242,    61,   246,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   181,   533,   335,    53,
     291,   192,   192,   545,   383,    68,    69,    70,    71,    72,
      73,   346,   286,    62,   579,    29,   364,   365,   558,    74,
      75,   287,   183,   288,   300,   372,    36,    76,   338,   546,
     347,  -147,   525,    45,   -40,   289,   397,   184,    63,    25,
     321,   547,   322,   127,   149,    79,   565,   384,   221,     7,
     327,     7,    80,   -41,   273,   240,   185,   217,    52,   412,
     427,    39,   266,   433,    65,    81,    82,    83,   448,   340,
     341,    53,   249,   290,   103,   -54,   443,   366,    43,   217,
     591,     1,   592,   201,   291,   114,   186,   588,   363,   367,
     589,    40,   179,    57,   -86,   309,   113,   556,   548,    86,
     411,   304,   391,   274,   414,   415,   416,   352,   486,   127,
     187,   202,   502,   386,   387,   310,  -188,   107,   107,   395,
    -190,  -189,   176,   468,    92,    93,    94,    95,    96,    97,
      46,   334,   250,   232,   222,   390,   116,   450,   117,     2,
     118,    33,    34,   398,   399,   121,   199,    41,  -179,   402,
      68,    69,    70,    71,    72,    73,   124,   199,     3,   292,
     293,    47,   551,   353,    74,    75,   104,   413,   131,   132,
     354,   122,    76,    77,  -179,   496,   423,   122,   286,   128,
      78,   -89,    25,   428,   269,   181,   303,   361,   362,   288,
      79,   373,   374,   129,     4,   130,   105,    80,   377,   374,
       5,   289,   381,   452,   453,   436,   374,   455,   437,   374,
      81,    82,    83,    55,    58,   573,   574,   575,   576,   392,
     393,   394,   223,   396,   445,   374,   465,   460,   461,   469,
     133,    84,    85,   493,   362,   190,   115,   494,   362,   290,
     119,   120,   534,   362,    86,   535,   362,   141,    92,    93,
      94,    95,    96,    97,   488,   142,     6,    87,   143,    68,
      69,    70,    71,    72,    73,   144,     7,   536,   362,     8,
       9,   435,   194,    74,    75,   166,   167,   168,   169,   170,
     145,    76,   537,   374,   554,   461,   510,   390,    10,   559,
     560,   512,   561,   560,   458,   459,   146,   452,   524,    79,
     562,   560,   147,   463,   192,    11,    80,   564,   362,   530,
     531,   163,   164,   165,   166,   167,   168,   169,   170,    81,
      82,    83,   566,   567,   593,   362,   195,   549,    66,    67,
     196,   550,   198,   553,   164,   165,   166,   167,   168,   169,
     170,   203,    68,    69,    70,    71,    72,    73,   197,    88,
      89,    90,   208,    86,    91,     7,    74,    75,   205,   207,
     355,   356,   421,   422,    76,   228,   528,   529,   237,    68,
      69,    70,    71,    72,    73,   262,   263,   268,   270,   277,
     278,   280,    79,    74,    75,   281,   283,   284,   585,    80,
     301,    76,   230,    92,    93,    94,    95,    96,    97,   285,
     306,   317,    81,    82,    83,   323,   325,   170,   339,    79,
     326,   330,   332,   343,   344,   345,    80,   357,    68,    69,
      70,    71,    72,    73,   358,   348,   349,   350,   360,    81,
      82,    83,    74,    75,   310,   368,    86,   369,   370,   371,
      76,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   375,   378,   379,   404,   382,    79,   383,
     407,   409,   410,    86,   417,    80,   419,   424,    68,    69,
      70,    71,    72,    73,   425,   434,   438,   439,    81,    82,
      83,   442,    74,    75,   456,   457,   462,   472,   470,   471,
      76,   475,   473,   476,   138,   477,   478,   479,   480,   481,
     482,   483,    92,    93,    94,    95,    96,    97,    79,   484,
     502,   489,    86,   498,   500,    80,   508,    68,    69,    70,
      71,    72,    73,   513,   526,   532,   507,   563,    81,    82,
      83,    74,    75,    68,    69,    70,    71,    72,    73,    76,
     538,   540,   570,   388,   571,   572,   577,    74,    75,   384,
     582,   581,   584,   586,   594,    76,   595,    79,   590,   596,
     362,   511,    86,    44,    80,   446,    30,   523,   580,   233,
     376,   272,   490,    79,   305,   125,   175,    81,    82,    83,
      80,   406,   418,   214,     0,    92,    93,    94,    95,    96,
      97,     0,   454,    81,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,   509,     0,
       0,    86,    92,    93,    94,    95,    96,    97,   162,   163,
     164,   165,   166,   167,   168,   169,   170,    86,    68,    69,
      70,    71,    72,    73,    68,    69,    70,    71,    72,    73,
       0,     0,    74,    75,     0,     0,     0,     0,    74,    75,
      76,     0,     0,     0,     0,     0,    76,     0,     0,     0,
       0,    92,    93,    94,    95,    96,    97,     0,    79,     0,
       0,     0,     0,     0,    79,    80,     0,     0,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,    81,    82,
      83,     0,     0,     0,    81,    82,    83,     0,     0,     0,
       0,     0,     0,   552,     0,     0,     0,     0,     0,     0,
       0,    92,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,    86,     0,     0,     0,     0,     0,    86,   151,
     152,   153,   154,   155,   156,   157,   158,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
      92,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,    93,    94,    95,
      96,    97,   151,   152,   153,   154,   155,   156,   157,   158,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   151,   152,   153,   154,   155,   156,   157,
     158,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   324,   151,   152,   153,   154,   155,
     156,   157,   158,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   151,   152,   153,   154,
     155,   156,   157,   158,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,     0,     0,     0,
       0,    92,    93,    94,    95,    96,    97,    92,    93,    94,
      95,    96,    97,     0,   151,   152,   153,   154,   155,   156,
     157,   158,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   151,   152,   153,   154,   155,
     156,   157,   158,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   151,   152,   153,   154,
     155,   156,   157,   158,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   151,   152,   153,
     154,   155,   156,   157,   158,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,     0,     1,
       0,     0,     0,     0,     0,   316,   466,   151,   152,   153,
     154,   155,   156,   157,   158,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   151,   152,
     153,   154,   155,   156,   157,   158,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,     0,
       0,     0,     0,     0,     0,     0,     0,     2,   316,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   514,
     515,   516,   517,     0,     0,     0,     3,     0,     0,   328,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   329,     0,     0,     0,     0,     0,     0,   518,   519,
     520,     0,     4,     0,     0,     0,     0,     0,     5,     0,
       0,     0,   506,   151,   152,   153,   154,   155,   156,   157,
     158,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,     0,     0,     0,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   156,   157,   158,   467,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,     0,     0,     6,     0,     0,     0,     0,     0,
     331,     0,     0,     0,     7,     0,     0,     8,     9,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
       0,   333,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   555,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     521,   522,     0,     0,     0,     0,   403,     0,   151,   152,
     153,   154,   155,   156,   157,   158,   138,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,     0,
       0,     0,     0,     0,     0,   151,   152,   153,   154,   155,
     156,   157,   158,   318,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   151,   152,   153,   154,
     155,   156,   157,   158,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,     0,     0,     0,
       0,     0,     0,     0,     0,   503,   401,   150,     0,     0,
       0,     0,   400,     0,   151,   152,   153,   154,   155,   156,
     157,   158,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,     0,     0,     0,     0,   464,
       0,     0,   171,     0,     0,     0,     0,   504,   151,   152,
     153,   154,   155,   156,   157,   158,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,     0,
       0,     0,     0,     0,   342,   151,   152,   153,   154,   155,
     156,   157,   158,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   152,   153,   154,   155,
     156,   157,   158,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   153,   154,   155,   156,
     157,   158,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   154,   155,   156,   157,   158,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,  -191,  -191,  -191,  -191,   158,     0,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170
};

static const yytype_int16 yycheck[] =
{
      35,   206,   142,   143,     3,     3,     3,     3,   107,     3,
       3,     3,     3,   106,    20,    20,   368,   369,   157,     6,
     371,     3,     4,     5,     6,     7,     8,    79,     3,   129,
     187,    17,   105,   105,   188,    17,    18,   115,    68,    74,
      75,    76,   141,    25,    79,    80,     6,    38,   239,     3,
      91,    33,   354,    94,    40,    37,   115,    17,   110,   426,
       3,    43,     9,   115,     3,   256,   101,   102,    50,   197,
      56,   191,    91,    20,   126,    94,   103,   115,   191,   191,
     234,    63,    64,    65,    38,   226,   438,   439,   115,   158,
     442,   230,    78,   145,   445,    38,   124,   237,   133,    13,
     178,    15,    16,   138,   245,    62,   205,   142,   207,   144,
     145,   146,   147,   105,   149,    97,   151,   152,   153,   178,
     277,   156,   157,   115,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   256,   489,   237,   114,
     178,   254,   254,   129,   158,     3,     4,     5,     6,     7,
       8,   250,   106,   145,   254,   185,   284,   285,   525,    17,
      18,   115,   119,   117,   199,   293,     8,    25,   155,   155,
     263,   128,   474,   252,   252,   129,   316,   134,   170,   209,
     215,   167,   217,   256,   256,    43,   537,   256,    46,   188,
     225,   188,    50,   252,   134,   155,   153,   238,   208,   339,
     357,     3,   229,   360,   253,    63,    64,    65,   236,   244,
     245,   114,   194,   167,   256,     3,   254,   117,     0,   238,
      52,     3,    54,   230,   178,     3,   183,   579,   283,   129,
     582,    33,   107,   208,   188,   234,   252,   241,   224,    97,
     339,   202,   256,   183,   343,   344,   345,   253,   253,   256,
     207,   126,   256,   308,   309,   254,   254,   254,   254,   314,
     254,   254,   253,   403,   246,   247,   248,   249,   250,   251,
      79,   232,   254,   148,   132,   310,    97,   376,     3,    61,
       3,     5,     6,   318,   319,     3,   239,    11,   230,   324,
       3,     4,     5,     6,     7,     8,     3,   239,    80,   253,
     254,   110,   507,   256,    17,    18,   115,   342,   253,   254,
     271,   253,    25,    26,   256,   443,   351,   253,   106,   198,
      33,   208,   209,   358,   255,   256,   201,   255,   256,   117,
      43,   255,   256,     3,   116,     3,   145,    50,   255,   256,
     122,   129,   303,   378,   379,   255,   256,   382,   255,   256,
      63,    64,    65,    29,    30,     4,     5,     6,     7,   311,
     312,   313,   220,   315,   255,   256,   401,   255,   256,   404,
       9,    84,    85,   255,   256,    38,    52,   255,   256,   167,
      56,    57,   255,   256,    97,   255,   256,   254,   246,   247,
     248,   249,   250,   251,   429,   254,   178,   110,   254,     3,
       4,     5,     6,     7,     8,   254,   188,   255,   256,   191,
     192,   363,     3,    17,    18,    26,    27,    28,    29,    30,
     254,    25,   255,   256,   255,   256,   461,   462,   210,   255,
     256,   466,   255,   256,   386,   387,   254,   472,   473,    43,
     255,   256,   254,   395,   254,   227,    50,   255,   256,   484,
     485,    23,    24,    25,    26,    27,    28,    29,    30,    63,
      64,    65,   255,   256,   255,   256,     3,   502,    33,    34,
       3,   506,    26,   508,    24,    25,    26,    27,    28,    29,
      30,     3,     3,     4,     5,     6,     7,     8,   254,   202,
     203,   204,     3,    97,   207,   188,    17,    18,   129,   130,
     273,   274,   349,   350,    25,    26,   482,   483,   254,     3,
       4,     5,     6,     7,     8,     3,     3,   255,     3,   128,
     164,     3,    43,    17,    18,     3,   234,   254,   563,    50,
     162,    25,    26,   246,   247,   248,   249,   250,   251,   254,
       3,   255,    63,    64,    65,   255,   255,    30,   254,    43,
     255,   255,   255,   254,   254,   254,    50,   128,     3,     4,
       5,     6,     7,     8,   157,   129,   129,   129,   128,    63,
      64,    65,    17,    18,   254,   254,    97,   254,   129,     3,
      25,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     3,    47,   135,   125,    20,    43,   158,
     108,   255,   255,    97,   255,    50,   102,     3,     3,     4,
       5,     6,     7,     8,     3,     3,   254,   254,    63,    64,
      65,   254,    17,    18,   129,     3,   254,    47,   255,   255,
      25,   255,   109,   255,   238,   255,   255,   255,   128,   254,
     254,   254,   246,   247,   248,   249,   250,   251,    43,    20,
     256,   254,    97,   254,   254,    50,    20,     3,     4,     5,
       6,     7,     8,   255,     3,     3,   227,    20,    63,    64,
      65,    17,    18,     3,     4,     5,     6,     7,     8,    25,
       5,     5,   255,    78,   155,     4,   129,    17,    18,   256,
     126,   184,     3,     5,   191,    25,     4,    43,   255,     4,
     256,   462,    97,    12,    50,   374,     2,   472,   549,   149,
     298,   181,   433,    43,   203,    60,   103,    63,    64,    65,
      50,   329,   347,   139,    -1,   246,   247,   248,   249,   250,
     251,    -1,    78,    63,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    97,   246,   247,   248,   249,   250,   251,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    97,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,     8,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    17,    18,
      25,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,   250,   251,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    43,    50,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    97,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
     250,   251,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,   105,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,   250,   251,   246,   247,   248,
     249,   250,   251,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,     3,
      -1,    -1,    -1,    -1,    -1,   256,   102,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,   256,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    -1,    -1,    -1,    80,    -1,    -1,   256,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,   256,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,    -1,   116,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,   256,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,   255,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,   188,    -1,    -1,   191,   192,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,   255,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   255,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,    -1,    -1,    -1,   105,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,   238,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,   213,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,   213,     3,    -1,    -1,
      -1,    -1,    94,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    94,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    81,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    36,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    11,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    13,    14,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,    61,    80,   116,   122,   178,   188,   191,   192,
     210,   227,   258,   259,   260,   261,   262,   263,   271,   283,
     313,   317,   318,   321,   323,   209,   265,   282,    68,   185,
     282,   314,     3,   265,   265,   294,     8,   324,   325,     3,
      33,   265,   319,     0,   259,   252,    79,   110,   115,   126,
     145,   266,   208,   114,   322,   322,     3,   208,   322,     3,
     105,   115,   145,   170,   315,   253,   266,   266,     3,     4,
       5,     6,     7,     8,    17,    18,    25,    26,    33,    43,
      50,    63,    64,    65,    84,    85,    97,   110,   202,   203,
     204,   207,   246,   247,   248,   249,   250,   251,   295,   296,
     326,     9,    20,   256,   115,   145,     3,   254,   297,   298,
     299,   302,   312,   252,     3,   322,    97,     3,     3,   322,
     322,     3,   253,   316,     3,   315,   105,   256,   198,     3,
       3,   253,   254,     9,   326,   326,   326,   326,   238,   326,
     331,   254,   254,   254,   254,   254,   254,   254,   105,   256,
       3,    10,    11,    12,    13,    14,    15,    16,    17,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    38,   301,   326,   326,   325,   253,   301,   283,   297,
     191,   256,    62,   119,   134,   153,   183,   207,   303,   305,
      38,   300,   254,   267,     3,     3,     3,   254,    26,   239,
     284,   230,   297,     3,   191,   267,   191,   267,     3,   326,
     327,   328,   326,   326,   331,    91,    94,   238,   283,   326,
     327,    46,   132,   220,   327,   329,   326,   326,    26,   326,
      26,   326,   297,   296,   326,   326,   326,   254,     6,    17,
     155,   326,   326,    13,    15,    16,   326,    33,    37,   194,
     254,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,     3,     3,   103,   115,   229,   309,   255,   255,
       3,   320,   298,   134,   183,   306,   299,   128,   164,   304,
       3,     3,   293,   234,   254,   254,   106,   115,   117,   129,
     167,   178,   253,   254,   272,   273,   274,   280,   281,   272,
     326,   162,   290,   297,   284,   316,     3,   270,     3,   234,
     254,   268,   283,   270,   234,   283,   256,   255,   213,    91,
      94,   326,   326,   255,   105,   255,   255,   326,   256,   256,
     255,   255,   255,   255,   284,   283,   327,     6,   155,   254,
     326,   326,    36,   254,   254,   254,   283,   301,   129,   129,
     129,    20,   253,   256,   284,   304,   304,   128,   157,   299,
     128,   255,   256,   268,   272,   272,   117,   129,   254,   254,
     129,     3,   272,   255,   256,     3,   300,   255,    47,   135,
     291,   284,    20,   158,   256,   264,   268,   268,    78,   269,
     326,   256,   264,   264,   264,   268,   264,   327,   326,   326,
      94,   213,   326,   105,   125,   330,   330,   108,   285,   255,
     255,   283,   327,   326,   283,   283,   283,   255,   309,   102,
     310,   310,   310,   326,     3,     3,   290,   299,   326,   157,
     230,   307,   308,   299,     3,   264,   255,   255,   254,   254,
     293,   293,   254,   254,   280,   255,   273,   124,   236,   279,
     283,   286,   326,   326,    78,   326,   129,     3,   264,   264,
     255,   256,   254,   264,    94,   326,   102,   255,   327,   326,
     255,   255,    47,   109,   289,   255,   255,   255,   255,   255,
     128,   254,   254,   254,    20,    20,   253,   291,   326,   254,
     308,   293,   293,   255,   255,   293,   272,   280,   254,   276,
     254,   275,   256,    39,    81,   287,   256,   227,    20,    78,
     326,   269,   326,   255,    72,    73,    74,    75,   111,   112,
     113,   243,   244,   286,   326,   290,     3,   311,   311,   311,
     326,   326,     3,   293,   255,   255,   255,   255,     5,   277,
       5,    17,    40,    56,    78,   129,   155,   167,   224,   326,
     326,   270,    78,   326,   255,   255,   241,   288,   291,   255,
     256,   255,   255,    20,   255,   280,   255,   256,   226,   245,
     255,   155,     4,     4,     5,     6,     7,   129,   129,   254,
     287,   184,   126,   292,     3,   326,     5,   278,   293,   293,
     255,    52,    54,   255,   191,     4,     4
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   257,   258,   258,   259,   260,   260,   259,   261,   259,
     262,   259,   263,   263,   263,   263,   264,   264,   265,   265,
     265,   265,   265,   266,   266,   267,   267,   268,   268,   269,
     269,   269,   269,   263,   263,   270,   270,   270,   270,   259,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   272,   272,   273,   274,   273,   273,   273,   273,   273,
     273,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   276,   276,   276,   277,   277,   277,
     278,   278,   278,   279,   279,   280,   281,   281,   281,   282,
     282,   259,   283,   283,   284,   284,   285,   285,   286,   286,
     287,   287,   287,   288,   288,   289,   289,   290,   290,   291,
     291,   291,   292,   292,   293,   293,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   295,   295,   295,   296,   297,
     297,   298,   298,   299,   299,   299,   299,   300,   300,   301,
     301,   301,   302,   302,   302,   302,   302,   303,   303,   303,
     304,   304,   305,   305,   306,   306,   306,   307,   307,   308,
     308,   309,   309,   309,   309,   310,   310,   311,   311,   312,
     259,   313,   314,   314,   314,   314,   313,   315,   315,   316,
     316,   313,   259,   317,   317,   317,   259,   318,   319,   319,
     319,   320,   320,   320,   320,   259,   321,   321,   322,   322,
     259,   323,   324,   324,   325,   325,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     327,   327,   328,   328,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   329,
     329,   329,   326,   326,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   326,   326,   326,   326,   331,   331,   326,
     326,   326,   326,   326,   326,   326,   326
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     1,     2,     2,     1,     4,     1,
       1,     1,     8,     8,     7,     8,     0,     4,     0,     2,
       2,     2,     2,     1,     0,     0,     3,     3,     5,     1,
       1,     3,     3,     7,     7,     3,     3,     5,     5,     1,
       8,    10,     9,     6,     7,     7,     7,     8,     8,    11,
       8,     1,     3,     0,     0,     4,     5,     4,     4,     5,
       5,     0,     3,     2,     3,     3,     3,     3,     2,     5,
       3,     3,     2,     3,     0,     3,     5,     0,     2,     2,
       0,     4,     3,     3,     5,     3,     0,     1,     1,     0,
       1,     1,     3,    11,     0,     2,     0,     4,     2,     4,
       0,     1,     1,     0,     2,     0,     2,     0,     3,     0,
       2,     4,     0,     2,     1,     3,     0,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     3,     1,     2,     1,
       3,     1,     1,     3,     5,     3,     3,     1,     0,     2,
       1,     0,     5,     3,     5,     6,     5,     0,     1,     1,
       0,     1,     1,     1,     2,     2,     0,     1,     0,     2,
       4,     6,     6,     6,     0,     2,     0,     1,     3,     3,
       1,     7,     2,     2,     2,     0,     6,     2,     4,     0,
       2,     7,     1,     8,     7,     7,     1,     8,     0,     2,
       2,     3,     5,     5,     7,     1,     4,     4,     0,     2,
       1,     2,     1,     3,     3,     3,     1,     1,     3,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     5,     6,     6,     6,     3,     3,
       3,     3,     2,     2,     3,     3,     4,     3,     4,     5,
       1,     3,     0,     1,     5,     6,     5,     6,     4,     4,
       4,     4,     4,     4,     4,     6,     8,     4,     7,     1,
       1,     1,     6,     6,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     6,     3,     5,     4,     5,     3,
       4,     3,     4,     1,     1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 328 "pmysql.y" /* yacc.c:1646  */
    { sql_stmt_handle((yyvsp[-1].stmt_node));}
#line 2161 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 329 "pmysql.y" /* yacc.c:1646  */
    {sql_stmt_handle((yyvsp[-1].stmt_node));}
#line 2167 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 332 "pmysql.y" /* yacc.c:1646  */
    {(yyval.stmt_node)=(yyvsp[0].stmt_node);}
#line 2173 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 334 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_show_table_content((yyvsp[0].strval)); free((yyvsp[0].strval));}
#line 2179 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 335 "pmysql.y" /* yacc.c:1646  */
    {(yyval.stmt_node) = sql_show_all_table();}
#line 2185 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 337 "pmysql.y" /* yacc.c:1646  */
    {(yyval.stmt_node)=(yyvsp[0].stmt_node);}
#line 2191 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 339 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node)= sql_import_file((yyvsp[-2].strval)); show_log("import\n");free((yyvsp[-2].strval));}
#line 2197 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 343 "pmysql.y" /* yacc.c:1646  */
    {(yyval.stmt_node)=(yyvsp[0].stmt_node);}
#line 2203 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 345 "pmysql.y" /* yacc.c:1646  */
    {select_stmt_t *test=sql_test_select();(yyval.stmt_node)=sql_sel_stmt_hdl(test);}
#line 2209 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 348 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].stmt_node) ;}
#line 2215 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 354 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_insert_stmt_create((yyvsp[-4].strval), (yyvsp[-3].col_node), (yyvsp[-1].insr_node));show_log("INSERTVALS %d %d %s", (yyvsp[-6].intval), (yyvsp[-1].insr_node), (yyvsp[-4].strval)); }
#line 2221 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 360 "pmysql.y" /* yacc.c:1646  */
    { printf(" %s should be INSERT\n",(yyvsp[-7].strval));(yyval.stmt_node)=NULL; free((yyvsp[-4].strval)); }
#line 2227 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 365 "pmysql.y" /* yacc.c:1646  */
    { printf(" \"VALUES\" is missing\n");(yyval.stmt_node)=NULL; free((yyvsp[-3].strval)); }
#line 2233 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 370 "pmysql.y" /* yacc.c:1646  */
    { printf(" \"%s\" should be VALUES\n", (yyvsp[-2].strval));(yyval.stmt_node)=NULL; free((yyvsp[-4].strval));free((yyvsp[-2].strval)); }
#line 2239 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 373 "pmysql.y" /* yacc.c:1646  */
    { show_log("DUPUPDATE %d", (yyvsp[0].intval)); }
#line 2245 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 376 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2251 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 377 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 01 ; }
#line 2257 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 378 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 02 ; }
#line 2263 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 379 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 04 ; }
#line 2269 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 380 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 010 ; }
#line 2275 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 386 "pmysql.y" /* yacc.c:1646  */
    { (yyval.col_node) = NULL ;}
#line 2281 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 387 "pmysql.y" /* yacc.c:1646  */
    { (yyval.col_node) = (yyvsp[-1].col_node); sql_print_col_node((yyvsp[-1].col_node));show_log("INSERTCOLS %d", (yyvsp[-1].col_node)); }
#line 2287 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 390 "pmysql.y" /* yacc.c:1646  */
    { (yyval.insr_node) = (yyvsp[-1].insr_node); }
#line 2293 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 391 "pmysql.y" /* yacc.c:1646  */
    { show_log("VALUES %d", (yyvsp[-1].insr_node)); (yyval.insr_node) = (yyvsp[-4].insr_node) + 1; }
#line 2299 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 394 "pmysql.y" /* yacc.c:1646  */
    { (yyval.insr_node) = sql_insert_vals_node_create((yyvsp[0].expr_node), NULL, true); }
#line 2305 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 395 "pmysql.y" /* yacc.c:1646  */
    { show_log("DEFAULT"); (yyval.insr_node) = NULL; }
#line 2311 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 396 "pmysql.y" /* yacc.c:1646  */
    { (yyval.insr_node) = sql_insert_vals_node_create((yyvsp[0].expr_node), (yyvsp[-2].insr_node), false); }
#line 2317 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 397 "pmysql.y" /* yacc.c:1646  */
    { show_log("DEFAULT"); (yyval.insr_node) = NULL; }
#line 2323 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 403 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSERTASGN %d %d %s", (yyvsp[-5].intval), (yyvsp[-1].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 2329 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 408 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSERTSELECT %d %s", (yyvsp[-5].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 2335 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 413 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
       show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 2342 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 416 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
                 show_log("DEFAULT"); show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 2349 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 419 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-4].intval));
                 show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 2356 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 422 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-4].intval));
                 show_log("DEFAULT"); show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 2363 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 427 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].stmt_node);show_log("STMT"); }
#line 2369 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 432 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_cret_table_stmt_create((yyvsp[-3].strval), (yyvsp[-1].attr_node)); if ((yyval.stmt_node)==NULL) sql_free_attr_header_list((yyvsp[-1].attr_node)); show_log("CREATE %d %d %s", (yyvsp[-6].intval), (yyvsp[-4].intval), (yyvsp[-3].strval)); }
#line 2375 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 436 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATE %d %d %s.%s", (yyvsp[-8].intval), (yyvsp[-6].intval), (yyvsp[-5].strval), (yyvsp[-3].strval));
                          free((yyvsp[-5].strval)); free((yyvsp[-3].strval)); }
#line 2382 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 442 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d %s", (yyvsp[-7].intval), (yyvsp[-5].intval),(yyvsp[-4].strval)); free((yyvsp[-4].strval)); }
#line 2388 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 446 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d 0 %s", (yyvsp[-4].intval), (yyvsp[-2].intval), (yyvsp[-1].strval)); free((yyvsp[-1].strval)); }
#line 2394 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 450 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"Table\"is missing\n ");(yyval.stmt_node)=NULL;if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-3].strval));}
#line 2400 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 451 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"(\"is missing\n ");(yyval.stmt_node)=NULL;if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-2].strval));}
#line 2406 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 452 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\")\"is missing \n");(yyval.stmt_node)=NULL;if ((yyvsp[0].attr_node)) sql_free_attr_header_list((yyvsp[0].attr_node));free((yyvsp[-2].strval));}
#line 2412 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 453 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"%s\" should be CREATE\n ", (yyvsp[-7].strval));(yyval.stmt_node)=NULL;if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-7].strval));free((yyvsp[-3].strval));}
#line 2418 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 454 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"%s\" should be TABLE\n ", (yyvsp[-5].strval));(yyval.stmt_node)=NULL; if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-5].strval));free((yyvsp[-3].strval));}
#line 2424 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 458 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d 0 %s.%s", (yyvsp[-9].intval), (yyvsp[-7].intval), (yyvsp[-6].strval), (yyvsp[-4].strval));
                              free((yyvsp[-6].strval)); free((yyvsp[-4].strval)); }
#line 2431 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 463 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d 0 %s.%s", (yyvsp[-6].intval), (yyvsp[-4].intval), (yyvsp[-3].strval), (yyvsp[-1].strval));
                          free((yyvsp[-3].strval)); free((yyvsp[-1].strval)); }
#line 2438 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 467 "pmysql.y" /* yacc.c:1646  */
    {(yyval.attr_node)=sql_cret_def_handle(NULL, (yyvsp[0].cret_node)); sql_printf_attr((yyvsp[0].cret_node)->cret_def_info); }
#line 2444 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 468 "pmysql.y" /* yacc.c:1646  */
    { sql_recursive_printf_node((yyvsp[-2].attr_node)); (yyval.attr_node) = sql_cret_def_handle((yyvsp[-2].attr_node), (yyvsp[0].cret_node)); sql_printf_attr((yyval.attr_node));}
#line 2450 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 471 "pmysql.y" /* yacc.c:1646  */
    {printf("NULL column\n");}
#line 2456 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 472 "pmysql.y" /* yacc.c:1646  */
    {}
#line 2462 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 473 "pmysql.y" /* yacc.c:1646  */
    { (yyval.cret_node) = sql_cret_def_attr_declar_node_create((yyvsp[-2].strval), (yyvsp[-1].intval), (yyvsp[0].intval));/*show_log("COLUMNDEF %d %s", $3, $2); */ }
#line 2468 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 475 "pmysql.y" /* yacc.c:1646  */
    { (yyval.cret_node) = sql_cret_def_pk_def_node_create((yyvsp[-1].col_node)); show_log("PRIKEY %d", (yyvsp[-1].col_node)); }
#line 2474 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 476 "pmysql.y" /* yacc.c:1646  */
    { show_log("KEY %d", (yyvsp[-1].col_node)); }
#line 2480 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 477 "pmysql.y" /* yacc.c:1646  */
    { show_log("KEY %d", (yyvsp[-1].col_node)); }
#line 2486 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 478 "pmysql.y" /* yacc.c:1646  */
    { show_log("TEXTINDEX %d", (yyvsp[-1].col_node)); }
#line 2492 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 479 "pmysql.y" /* yacc.c:1646  */
    { show_log("TEXTINDEX %d", (yyvsp[-1].col_node)); }
#line 2498 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 482 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (1<<COL_ATTR_VALID); }
#line 2504 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 483 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR NOTNULL"); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2510 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 485 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT STRING %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2516 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 486 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT NUMBER %d", (yyvsp[0].intval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2522 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 487 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT FLOAT %g", (yyvsp[0].floatval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2528 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 488 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT BOOL %d", (yyvsp[0].intval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2534 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 489 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR AUTOINC"); (yyval.intval) = (yyvsp[-1].intval) + 1; }
#line 2540 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 490 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR UNIQUEKEY %d", (yyvsp[-1].col_node)); (yyval.intval) = 1<<((yyvsp[-4].intval) + 1); }
#line 2546 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 491 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR UNIQUEKEY"); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2552 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 492 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR PRIKEY"); (yyval.intval) = 1<<COL_ATTR_PRIKEY; }
#line 2558 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 493 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR PRIKEY"); (yyval.intval) = 1<<COL_ATTR_PRIKEY; }
#line 2564 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 494 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR COMMENT %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2570 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 497 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2576 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 498 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval); }
#line 2582 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 499 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-3].intval) + 1000*(yyvsp[-1].intval); }
#line 2588 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 506 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2594 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 507 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 1000; }
#line 2600 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 508 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 2000; }
#line 2606 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 512 "pmysql.y" /* yacc.c:1646  */
    { show_log("COLCHARSET %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2612 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 513 "pmysql.y" /* yacc.c:1646  */
    { show_log("COLCOLLATE %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2618 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 517 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = DATA_TYPE_INT;}
#line 2624 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 518 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = DATA_TYPE_VARCHAR + (yyvsp[-2].intval);}
#line 2630 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 555 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d", (yyvsp[-2].intval)); }
#line 2636 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 558 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2642 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 559 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2648 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 560 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2; }
#line 2654 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 563 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2660 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 564 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1;}
#line 2666 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 572 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].stmt_node); show_log("STMT"); sql_select_errchk_try((yyvsp[0].stmt_node));}
#line 2672 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 576 "pmysql.y" /* yacc.c:1646  */
    { show_log("SELECTNODATA %d %d", (yyvsp[-1].intval), (yyvsp[0].select_col_node)); }
#line 2678 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 580 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_select_stmt_create(STMT_TYPE_SELECT_TUPLE, (yyvsp[-8].select_col_node), (yyvsp[-6].select_table_node), (yyvsp[-5].expr_node)); show_log("SELECT %d %d %d", (yyvsp[-9].intval), (yyvsp[-8].select_col_node), (yyvsp[-6].select_table_node)); }
#line 2684 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 583 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = NULL;}
#line 2690 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 584 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[0].expr_node); show_log("WHERE"); }
#line 2696 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 588 "pmysql.y" /* yacc.c:1646  */
    { show_log("GROUPBYLIST %d %d", (yyvsp[-1].intval), (yyvsp[0].intval)); }
#line 2702 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 592 "pmysql.y" /* yacc.c:1646  */
    { show_log("GROUPBY %d",  (yyvsp[0].intval)); (yyval.intval) = 1; }
#line 2708 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 594 "pmysql.y" /* yacc.c:1646  */
    { show_log("GROUPBY %d",  (yyvsp[0].intval)); (yyval.intval) = (yyvsp[-3].intval) + 1; }
#line 2714 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 597 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2720 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 598 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2726 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 599 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2732 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 602 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2738 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 603 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2744 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 606 "pmysql.y" /* yacc.c:1646  */
    { show_log("HAVING"); }
#line 2750 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 608 "pmysql.y" /* yacc.c:1646  */
    { show_log("ORDERBY %d", (yyvsp[0].intval)); }
#line 2756 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 611 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIMIT 1"); }
#line 2762 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 612 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIMIT 2"); }
#line 2768 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 616 "pmysql.y" /* yacc.c:1646  */
    { show_log("INTO %d", (yyvsp[0].col_node)); }
#line 2774 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 619 "pmysql.y" /* yacc.c:1646  */
    { show_log("COLUMN %s", (yyvsp[0].strval)); (yyval.col_node) = sql_col_list_node_create((yyvsp[0].strval), NULL, true); }
#line 2780 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 620 "pmysql.y" /* yacc.c:1646  */
    { (yyval.col_node) = sql_col_list_node_create((yyvsp[0].strval), (yyvsp[-2].col_node), false);show_log("COLUMN %s", (yyvsp[0].strval));}
#line 2786 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 623 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2792 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 624 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 01) yyerror("duplicate ALL option"); (yyval.intval) = (yyvsp[-1].intval) | 01; }
#line 2798 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 625 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 02) yyerror("duplicate DISTINCT option"); (yyval.intval) = (yyvsp[-1].intval) | 02; }
#line 2804 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 626 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 04) yyerror("duplicate DISTINCTROW option"); (yyval.intval) = (yyvsp[-1].intval) | 04; }
#line 2810 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 627 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 010) yyerror("duplicate HIGH_PRIORITY option"); (yyval.intval) = (yyvsp[-1].intval) | 010; }
#line 2816 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 628 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 020) yyerror("duplicate STRAIGHT_JOIN option"); (yyval.intval) = (yyvsp[-1].intval) | 020; }
#line 2822 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 629 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 040) yyerror("duplicate SQL_SMALL_RESULT option"); (yyval.intval) = (yyvsp[-1].intval) | 040; }
#line 2828 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 630 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 0100) yyerror("duplicate SQL_BIG_RESULT option"); (yyval.intval) = (yyvsp[-1].intval) | 0100; }
#line 2834 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 631 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 0200) yyerror("duplicate SQL_CALC_FOUND_ROWS option"); (yyval.intval) = (yyvsp[-1].intval) | 0200; }
#line 2840 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 634 "pmysql.y" /* yacc.c:1646  */
    { (yyval.select_col_node) = sql_select_col_list_create((yyvsp[0].select_col_node), NULL, true, false); }
#line 2846 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 635 "pmysql.y" /* yacc.c:1646  */
    {(yyval.select_col_node) = sql_select_col_list_create((yyvsp[0].select_col_node), (yyvsp[-2].select_col_node), false, false); }
#line 2852 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 636 "pmysql.y" /* yacc.c:1646  */
    { show_log("SELECTALL"); (yyval.select_col_node) = sql_select_col_list_create(NULL, NULL, NULL,true); }
#line 2858 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 639 "pmysql.y" /* yacc.c:1646  */
    { (yyval.select_col_node) = sql_select_col_node_create((yyvsp[-1].expr_node), (yyvsp[0].alias_name)); }
#line 2864 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 641 "pmysql.y" /* yacc.c:1646  */
    { (yyval.select_table_node) = sql_select_table_list_create((yyvsp[0].select_table_node), NULL, true); }
#line 2870 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 642 "pmysql.y" /* yacc.c:1646  */
    {  (yyval.select_table_node) = sql_select_table_list_create((yyvsp[0].select_table_node), (yyvsp[-2].select_table_node), false); }
#line 2876 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 650 "pmysql.y" /* yacc.c:1646  */
    {(yyval.select_table_node) = sql_select_table_node_create((yyvsp[-2].strval), NULL, (yyvsp[-1].alias_name)); show_log("TABLE %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 2882 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 651 "pmysql.y" /* yacc.c:1646  */
    {(yyval.select_table_node) = sql_select_table_node_create((yyvsp[-2].strval), (yyvsp[-4].strval), (yyvsp[-1].alias_name)); show_log("TABLE %s.%s", (yyvsp[-4].strval), (yyvsp[-2].strval));
                               free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); }
#line 2889 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 653 "pmysql.y" /* yacc.c:1646  */
    { show_log("SUBQUERYAS %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2895 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 654 "pmysql.y" /* yacc.c:1646  */
    { show_log("TABLEREFERENCES %d", (yyvsp[-1].select_table_node)); }
#line 2901 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 661 "pmysql.y" /* yacc.c:1646  */
    { (yyval.alias_name) = strdup((yyvsp[0].strval)); show_log ("ALIAS %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2907 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 662 "pmysql.y" /* yacc.c:1646  */
    { (yyval.alias_name) = strdup((yyvsp[0].strval)); show_log ("ALIAS %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2913 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 663 "pmysql.y" /* yacc.c:1646  */
    { (yyval.alias_name) = NULL; }
#line 2919 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 668 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0100+(yyvsp[-3].intval)); }
#line 2925 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 670 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0200); }
#line 2931 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 672 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0200); }
#line 2937 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 674 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0300+(yyvsp[-4].intval)+(yyvsp[-3].intval)); }
#line 2943 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 676 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0400+(yyvsp[-2].intval)); }
#line 2949 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 679 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2955 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 680 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2961 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 681 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2; }
#line 2967 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 684 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2973 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 685 "pmysql.y" /* yacc.c:1646  */
    {(yyval.intval) = 4; }
#line 2979 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 688 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2985 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 689 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2; }
#line 2991 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 692 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1 + (yyvsp[0].intval); }
#line 2997 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 693 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2 + (yyvsp[0].intval); }
#line 3003 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 694 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3009 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 700 "pmysql.y" /* yacc.c:1646  */
    { show_log("ONEXPR"); }
#line 3015 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 701 "pmysql.y" /* yacc.c:1646  */
    { show_log("USING %d", (yyvsp[-1].col_node)); }
#line 3021 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 706 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEXHINT %d %d", (yyvsp[-1].intval), 010+(yyvsp[-3].intval)); }
#line 3027 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 708 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEXHINT %d %d", (yyvsp[-1].intval), 020+(yyvsp[-3].intval)); }
#line 3033 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 710 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEXHINT %d %d", (yyvsp[-1].intval), 030+(yyvsp[-3].intval)); }
#line 3039 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 714 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3045 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 715 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3051 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 718 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEX %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1; }
#line 3057 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 719 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEX %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3063 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 722 "pmysql.y" /* yacc.c:1646  */
    { show_log("SUBQUERY"); }
#line 3069 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 727 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3075 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 732 "pmysql.y" /* yacc.c:1646  */
    { show_log("DELETEONE %d %s", (yyvsp[-5].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3081 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 735 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) + 01; }
#line 3087 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 736 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) + 02; }
#line 3093 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 737 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) + 04; }
#line 3099 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 738 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3105 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 744 "pmysql.y" /* yacc.c:1646  */
    { show_log("DELETEMULTI %d %d %d", (yyvsp[-4].intval), (yyvsp[-3].intval), (yyvsp[-1].select_table_node)); }
#line 3111 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 746 "pmysql.y" /* yacc.c:1646  */
    { show_log("TABLE %s", (yyvsp[-1].strval)); free((yyvsp[-1].strval)); (yyval.intval) = 1; }
#line 3117 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 748 "pmysql.y" /* yacc.c:1646  */
    { show_log("TABLE %s", (yyvsp[-1].strval)); free((yyvsp[-1].strval)); (yyval.intval) = (yyvsp[-3].intval) + 1; }
#line 3123 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 756 "pmysql.y" /* yacc.c:1646  */
    { show_log("DELETEMULTI %d %d %d", (yyvsp[-5].intval), (yyvsp[-3].intval), (yyvsp[-1].select_table_node)); }
#line 3129 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 759 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3135 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 765 "pmysql.y" /* yacc.c:1646  */
    { show_log("REPLACEVALS %d %d %s", (yyvsp[-6].intval), (yyvsp[-1].insr_node), (yyvsp[-4].strval)); free((yyvsp[-4].strval)); }
#line 3141 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 771 "pmysql.y" /* yacc.c:1646  */
    { show_log("REPLACEASGN %d %d %s", (yyvsp[-5].intval), (yyvsp[-1].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3147 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 776 "pmysql.y" /* yacc.c:1646  */
    { show_log("REPLACESELECT %d %s", (yyvsp[-5].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3153 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 780 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3159 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 787 "pmysql.y" /* yacc.c:1646  */
    { show_log("UPDATE %d %d %d", (yyvsp[-6].intval), (yyvsp[-5].select_table_node), (yyvsp[-3].intval)); }
#line 3165 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 790 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3171 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 791 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 01 ; }
#line 3177 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 792 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 010 ; }
#line 3183 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 797 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
	 show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 3190 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 800 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-4].strval));
	 show_log("ASSIGN %s.%s", (yyvsp[-4].strval), (yyvsp[-2].strval)); free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 3197 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 803 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
	 show_log("ASSIGN %s.%s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 3204 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 806 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s.$s", (yyvsp[-4].strval), (yyvsp[-2].strval));
	 show_log("ASSIGN %s.%s", (yyvsp[-4].strval), (yyvsp[-2].strval)); free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 3211 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 813 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3217 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 817 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATEDATABASE %d %s", (yyvsp[-1].intval), (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3223 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 818 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATEDATABASE %d %s", (yyvsp[-1].intval), (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3229 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 821 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3235 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 822 "pmysql.y" /* yacc.c:1646  */
    { if(!(yyvsp[0].subtok))yyerror("IF EXISTS doesn't exist");
                        (yyval.intval) = (yyvsp[0].subtok); /* NOT EXISTS hack */ }
#line 3242 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 827 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3248 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 835 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad set to @%s", (yyvsp[-2].strval));
		 show_log("SET %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3255 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 837 "pmysql.y" /* yacc.c:1646  */
    { show_log("SET %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3261 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 842 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_NAME, 0, (yyvsp[0].strval), NULL);show_log("NAME %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3267 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 843 "pmysql.y" /* yacc.c:1646  */
    { show_log("USERVAR %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3273 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 844 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_PREFIX, 0, (yyvsp[0].strval), (yyvsp[-2].strval));show_log("FIELDNAME %s.%s", (yyvsp[-2].strval), (yyvsp[0].strval)); free((yyvsp[-2].strval)); free((yyvsp[0].strval)); }
#line 3279 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 845 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_VARCHAR, 0, (yyvsp[0].strval), NULL); show_log("STRING %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3285 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 846 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_INT, (yyvsp[0].intval), NULL, NULL); show_log("NUMBER %d", (yyvsp[0].intval)); }
#line 3291 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 847 "pmysql.y" /* yacc.c:1646  */
    { show_log("FLOAT %g", (yyvsp[0].floatval)); }
#line 3297 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 848 "pmysql.y" /* yacc.c:1646  */
    { show_log("BOOL %d", (yyvsp[0].intval)); }
#line 3303 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 851 "pmysql.y" /* yacc.c:1646  */
    { show_log("ADD"); }
#line 3309 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 852 "pmysql.y" /* yacc.c:1646  */
    { show_log("SUB"); }
#line 3315 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 853 "pmysql.y" /* yacc.c:1646  */
    { show_log("MUL"); }
#line 3321 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 854 "pmysql.y" /* yacc.c:1646  */
    { show_log("DIV"); }
#line 3327 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 855 "pmysql.y" /* yacc.c:1646  */
    { show_log("MOD"); }
#line 3333 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 856 "pmysql.y" /* yacc.c:1646  */
    { show_log("MOD"); }
#line 3339 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 857 "pmysql.y" /* yacc.c:1646  */
    { show_log("NEG"); }
#line 3345 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 858 "pmysql.y" /* yacc.c:1646  */
    {(yyval.expr_node) = sql_expr_logic_node_create(LGC_TYPE_AND, (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); show_log("AND"); }
#line 3351 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 859 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_logic_node_create(LGC_TYPE_OR, (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); show_log("OR"); }
#line 3357 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 860 "pmysql.y" /* yacc.c:1646  */
    { show_log("XOR"); }
#line 3363 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 861 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_comparison_node_create((yyvsp[-1].subtok), (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); show_log("CMP %d", (yyvsp[-1].subtok)); }
#line 3369 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 862 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPSELECT %d", (yyvsp[-3].subtok)); }
#line 3375 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 863 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPANYSELECT %d", (yyvsp[-4].subtok)); }
#line 3381 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 864 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPANYSELECT %d", (yyvsp[-4].subtok)); }
#line 3387 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 865 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPALLSELECT %d", (yyvsp[-4].subtok)); }
#line 3393 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 866 "pmysql.y" /* yacc.c:1646  */
    { show_log("BITOR"); }
#line 3399 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 867 "pmysql.y" /* yacc.c:1646  */
    { show_log("BITAND"); }
#line 3405 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 868 "pmysql.y" /* yacc.c:1646  */
    { show_log("BITXOR"); }
#line 3411 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 869 "pmysql.y" /* yacc.c:1646  */
    { show_log("SHIFT %s", (yyvsp[-1].subtok)==1?"left":"right"); }
#line 3417 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 870 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOT"); }
#line 3423 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 871 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOT"); }
#line 3429 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 872 "pmysql.y" /* yacc.c:1646  */
    { show_log("ASSIGN @%s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3435 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 875 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISNULL"); }
#line 3441 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 876 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISNULL"); show_log("NOT"); }
#line 3447 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 877 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISBOOL %d", (yyvsp[0].intval)); }
#line 3453 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 878 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISBOOL %d", (yyvsp[0].intval)); show_log("NOT"); }
#line 3459 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 881 "pmysql.y" /* yacc.c:1646  */
    { show_log("BETWEEN"); }
#line 3465 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 885 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3471 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 886 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1 + (yyvsp[0].intval); }
#line 3477 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 889 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3483 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 893 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISIN %d", (yyvsp[-1].intval)); }
#line 3489 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 894 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISIN %d", (yyvsp[-1].intval)); show_log("NOT"); }
#line 3495 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 895 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSELECT"); }
#line 3501 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 896 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSELECT"); show_log("NOT"); }
#line 3507 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 897 "pmysql.y" /* yacc.c:1646  */
    { show_log("EXISTS"); if((yyvsp[-3].subtok))show_log("NOT"); }
#line 3513 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 900 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL %d %s", (yyvsp[-1].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3519 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 904 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_aggregation_node_create(AGGR_TYPE_COUNT, true, NULL); show_log("COUNTALL"); }
#line 3525 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 905 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_aggregation_node_create(AGGR_TYPE_COUNT, false, (yyvsp[-1].expr_node)); show_log(" CALL 1 COUNT"); }
#line 3531 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 907 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_aggregation_node_create(AGGR_TYPE_SUM, true, NULL); show_log("SUMALL"); }
#line 3537 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 908 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_aggregation_node_create(AGGR_TYPE_SUM, false, (yyvsp[-1].expr_node)); show_log(" CALL 1 SUM"); }
#line 3543 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 910 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL %d SUBSTR", (yyvsp[-1].intval));}
#line 3549 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 911 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL 2 SUBSTR"); }
#line 3555 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 912 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL 3 SUBSTR"); }
#line 3561 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 913 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL %d TRIM", (yyvsp[-1].intval)); }
#line 3567 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 914 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL 3 TRIM"); }
#line 3573 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 917 "pmysql.y" /* yacc.c:1646  */
    { show_log("INT 1"); }
#line 3579 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 918 "pmysql.y" /* yacc.c:1646  */
    { show_log("INT 2"); }
#line 3585 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 919 "pmysql.y" /* yacc.c:1646  */
    { show_log("INT 3"); }
#line 3591 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 922 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL 3 DATE_ADD"); }
#line 3597 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 923 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL 3 DATE_SUB"); }
#line 3603 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 926 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 1"); }
#line 3609 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 927 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 2"); }
#line 3615 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 928 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 3"); }
#line 3621 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 929 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 4"); }
#line 3627 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 930 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 5"); }
#line 3633 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 931 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 6"); }
#line 3639 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 932 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 7"); }
#line 3645 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 933 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 8"); }
#line 3651 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 934 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 9"); }
#line 3657 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 937 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASEVAL %d 0", (yyvsp[-1].intval)); }
#line 3663 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 938 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASEVAL %d 1", (yyvsp[-3].intval)); }
#line 3669 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 939 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASE %d 0", (yyvsp[-1].intval)); }
#line 3675 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 940 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASE %d 1", (yyvsp[-3].intval)); }
#line 3681 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 943 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3687 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 944 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-4].intval)+1; }
#line 3693 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 947 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIKE"); }
#line 3699 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 948 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIKE"); show_log("NOT"); }
#line 3705 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 951 "pmysql.y" /* yacc.c:1646  */
    { show_log("REGEXP"); }
#line 3711 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 952 "pmysql.y" /* yacc.c:1646  */
    { show_log("REGEXP"); show_log("NOT"); }
#line 3717 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 955 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOW"); }
#line 3723 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 956 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOW");}
#line 3729 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 957 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOW"); }
#line 3735 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 960 "pmysql.y" /* yacc.c:1646  */
    { show_log("STRTOBIN"); }
#line 3741 "pmysql.tab.c" /* yacc.c:1646  */
    break;


#line 3745 "pmysql.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 963 "pmysql.y" /* yacc.c:1906  */

#ifdef LOG_TO_FILE
#define OUTPUT "log.txt"
#endif
extern void yyrestart (FILE *input_file  );
void
show_log(char *s, ...)
{
  extern int yylineno;
  FILE *output = NULL;
  va_list ap;
  va_start(ap, s);
#ifdef LOG_TO_FILE
  output = fopen(OUTPUT, "a");
#else
  output = stdout;
#endif
  vfprintf(output, s, ap);
#ifdef LOG_TO_FILE
  fprintf(output,"\n");
  fclose(output);
#endif
}

void
yyerror(char *s, ...)
{
 /*
 extern int yylineno;

  va_list ap;
  va_start(ap, s);

  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");*/
}

int main(int ac, char **av)
{
  extern FILE *yyin;
  bool parse_fail = false;
#ifdef LOG_TO_FILE
  FILE* output = fopen(OUTPUT, "wb");
  fprintf(output, "log start...\n");
  fclose(output);
#endif
  sql_init();
  int i =0;
  if(ac > 1 && !strcmp(av[1], "-d")) {
    yydebug = 1; ac--; av++;
  }

  if(ac > 1 && (yyin = fopen(av[1], "r")) == NULL) {
    perror(av[1]);
    exit(1);
  }
  printf("input file %s\n",av[1]);
  while (1){
  if(!yyparse())
    printf("SQL parse worked\n");
  else {
        if (yychar==YYEOF) {
            yyin = stdin;
            yyrestart(yyin);
        } else
            printf("SQL parse failed\n");
        //yyrestart(yyin);
    }
    }
} /* main */
