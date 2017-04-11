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
#define YYLAST   1615

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  257
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  287
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  600

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
     627,   628,   629,   630,   631,   634,   635,   636,   639,   640,
     643,   644,   647,   648,   652,   653,   655,   656,   659,   660,
     663,   664,   665,   669,   671,   673,   675,   677,   681,   682,
     683,   686,   687,   690,   691,   694,   695,   696,   699,   699,
     702,   703,   707,   709,   711,   713,   716,   717,   720,   721,
     724,   729,   732,   737,   738,   739,   740,   743,   748,   749,
     753,   753,   755,   761,   764,   770,   776,   782,   785,   792,
     793,   794,   798,   801,   804,   807,   815,   819,   820,   823,
     824,   829,   832,   834,   834,   837,   839,   844,   845,   846,
     847,   848,   849,   850,   853,   854,   855,   856,   857,   858,
     859,   860,   861,   862,   863,   864,   865,   866,   867,   868,
     869,   870,   871,   872,   873,   874,   877,   878,   879,   880,
     883,   887,   888,   891,   892,   895,   896,   897,   898,   899,
     902,   906,   907,   909,   910,   912,   913,   914,   915,   916,
     919,   920,   921,   924,   925,   928,   929,   930,   931,   932,
     933,   934,   935,   936,   939,   940,   941,   942,   945,   946,
     949,   950,   953,   954,   957,   958,   959,   962
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

#define YYPACT_NINF -380

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-380)))

#define YYTABLE_NINF -192

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-192)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     111,  -130,   -39,  -380,    33,  -380,  -380,  -380,    62,    57,
    -380,    15,   565,  -177,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,    95,  -108,    48,    48,
       6,    32,   -87,    95,    95,   310,   148,   -57,  -380,  -380,
    -380,   -24,    16,  -380,   -46,  -380,  -380,  -380,  -380,  -380,
    -380,   223,    48,   133,   234,   239,    48,    48,   247,    13,
     278,  -380,  -380,  -380,   -98,   132,   290,   306,   -18,  -380,
    -380,  -380,  -380,   303,   847,   847,   847,  -380,  -380,   847,
     383,  -380,  -380,  -380,  -380,  -380,    83,  -380,  -380,  -380,
    -380,  -380,   103,   107,   129,   131,   142,   158,   -80,  -380,
    1491,   847,   847,    62,    17,    18,    20,     8,  -104,    81,
    -380,  -380,   330,  -380,   162,   416,  -380,  -380,  -380,   418,
     422,   197,   445,  -380,    55,  -167,    16,   469,  -380,  -106,
    -103,   168,   847,   847,     0,   566,   566,  -380,  -380,   847,
    1214,   -40,   285,   847,   359,   847,   847,   478,   519,    16,
     870,  -380,   847,   847,   847,   224,    31,   847,   847,   261,
     847,     9,   847,   847,   847,   847,   847,   847,   847,   847,
     847,   847,   474,  -380,  1547,  1547,  -380,   476,   -32,   232,
      28,   487,    16,  -380,  -380,  -380,   -78,  -380,    16,   364,
     329,  -380,   491,   495,   265,   246,   248,    44,    50,  -380,
     847,   339,    16,  -159,    13,   512,     7,   512,    -6,  -380,
    -380,   976,  -380,   263,  1547,   513,  1269,   -30,   847,  -380,
     847,   264,   935,   275,  -380,  -380,  -380,   277,   847,   997,
    1031,   279,  1133,   280,  1154,  -159,  -380,  1567,   902,  1446,
     594,  -380,    25,  -380,  1585,  1585,   266,   847,   847,  1520,
     284,   286,   309,   285,   525,   946,   434,   481,   409,   409,
     499,   499,   499,   499,  -380,  -380,    54,   404,   410,   435,
    -380,  -380,  -380,   -15,   -75,    81,   329,   329,   438,   413,
      16,  -380,   439,  -380,  -380,    40,   317,    50,    50,   102,
    -380,   319,   320,   443,  -380,   573,    50,    45,  -380,   574,
    -380,   330,    78,  1547,   531,   446,  -159,  -380,  -380,   560,
     -96,   317,   317,   635,   -93,   455,   -96,   317,   455,   847,
    -380,   847,   847,  -380,  1370,  1310,  -380,   847,  -380,  -380,
    1349,   479,   479,  -380,  -380,  -380,  -380,   506,   348,   360,
    -380,  -380,   594,  1585,  1585,   847,   285,   285,   285,   362,
     -32,   516,   516,   516,   847,   617,   619,   339,  -380,  -380,
      16,   847,  -127,    16,  -380,   620,   -93,    84,    86,   370,
     371,   495,   495,   373,   -38,    89,  -380,    50,   -91,   285,
    -380,   847,   847,  -380,  -380,   658,   507,   625,  -380,   -93,
     -93,  -380,    93,  1547,   381,  -380,  -380,  -380,   -93,  -380,
    -380,  1547,  1391,  -380,   847,  1112,   847,   847,   391,   392,
     601,   540,  -380,  -380,   395,   396,   793,   399,   400,   401,
    -380,  -380,   539,   414,   415,   417,  1547,   650,   -14,   446,
    -380,  1547,   847,   419,  -380,  -380,  -127,  -380,  -380,  -380,
    -380,   495,   495,    96,   100,   495,    50,  -380,   -77,  -380,
     420,   423,  -380,  -380,   424,  1419,  1052,  -380,  1547,   452,
     652,  -380,  -380,  -380,   734,   635,  -380,  -380,  1547,   847,
    -380,   427,  1244,  -380,  -380,   847,   847,   339,  -380,  -380,
    -380,  -380,  -380,  -380,   681,   681,   681,   847,   847,   683,
    -380,  1547,   495,  -380,   115,   123,  -380,  -380,   126,   137,
    -380,   684,  -380,   685,   251,   847,  -380,  -380,  -380,   847,
     512,   783,  -380,  1547,   143,  1182,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,    34,  1547,   446,  -380,
     155,   172,   176,  1547,  1547,   668,   187,  -380,  -380,  -380,
     -34,   189,  -150,   437,   538,  -380,   690,   318,  -380,  -380,
     567,  -101,  1419,  1547,   441,  -380,  1547,  -380,  -380,   511,
    -380,   576,  -380,   700,  -380,  -380,   847,  -380,  -380,  -380,
     699,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,   495,  -380,  -380,   495,  -380,  -380,  1547,   450,
     138,   194,   451,  -380,   515,   705,  -380,   706,  -380,  -380
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    18,    89,   176,     0,    18,    18,   116,     0,     0,
      10,    18,     0,     0,     4,     7,     9,    11,    39,    91,
     171,   183,   187,   196,   201,    90,    24,     0,   199,   199,
       0,     0,     0,    24,    24,     0,     0,   202,   203,     5,
       6,     0,     0,     1,     0,     2,    20,    21,    22,    23,
      19,     0,   199,     0,     0,     0,   199,   199,     0,   180,
       0,   175,   173,   174,     0,     0,     0,     0,   207,   210,
     211,   213,   212,   208,     0,     0,     0,   127,   117,     0,
       0,   285,   286,   284,   118,   119,     0,   120,   123,   124,
     122,   121,     0,     0,     0,     0,     0,     0,    92,   125,
     142,     0,     0,     0,    22,    19,   142,     0,     0,   130,
     132,   133,   139,     3,    25,     0,   200,   197,   198,     0,
       0,     0,     0,   178,    94,     0,     0,     0,     8,    25,
      25,     0,   243,     0,   207,   233,   234,   220,   287,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,   206,   205,   204,     0,   165,     0,
       0,     0,     0,   150,   149,   153,   157,   154,     0,     0,
     151,   138,     0,     0,     0,     0,     0,    53,    53,   181,
       0,   107,     0,    94,   180,     0,     0,     0,     0,   209,
     129,   241,   244,     0,   235,     0,     0,     0,     0,   276,
       0,     0,   241,     0,   262,   260,   261,     0,     0,     0,
       0,     0,     0,     0,     0,    94,   126,   222,   223,   221,
       0,   238,     0,   236,   280,   282,     0,     0,     0,     0,
       0,     0,     0,     0,   224,   229,   230,   232,   214,   215,
     216,   217,   218,   219,   231,   140,   142,     0,     0,     0,
     134,   170,   137,     0,    94,   131,   151,   151,     0,   144,
       0,   152,     0,   136,   114,     0,     0,    53,    53,     0,
      87,     0,     0,     0,    88,     0,    53,     0,    51,     0,
      43,   139,     0,    95,     0,   109,    94,   177,   179,     0,
      16,     0,     0,     0,    16,    16,    16,     0,    16,     0,
     250,     0,     0,   274,     0,     0,   249,     0,   255,   258,
       0,     0,     0,   251,   252,   253,   254,    96,     0,     0,
     239,   237,     0,   281,   283,     0,     0,     0,     0,     0,
     165,   167,   167,   167,     0,     0,     0,   107,   155,   156,
       0,     0,   159,     0,    26,     0,    16,     0,     0,     0,
       0,     0,     0,     0,    86,    46,    45,    53,     0,     0,
      44,     0,     0,   172,   182,     0,     0,     0,    33,    16,
      16,    30,     0,    29,     0,    14,    34,   185,    16,   186,
     242,   278,     0,   277,     0,     0,     0,     0,     0,     0,
       0,   105,   247,   245,     0,     0,   240,     0,     0,     0,
     225,   135,     0,     0,     0,     0,   192,     0,     0,   109,
     147,   145,     0,     0,   143,   158,     0,   115,    13,    47,
      48,     0,     0,     0,     0,     0,    53,    50,    86,    52,
      74,     0,    61,    85,   108,   100,   110,    36,    35,     0,
       0,    15,    12,    27,     0,     0,   184,   275,   279,     0,
     256,     0,     0,   263,   264,     0,     0,   107,   248,   246,
     228,   226,   227,   166,     0,     0,     0,     0,     0,     0,
     188,   160,     0,   146,     0,     0,    58,    57,     0,     0,
      42,     0,    77,     0,    55,     0,   101,   102,    98,     0,
       0,     0,    32,    31,     0,     0,   259,   265,   266,   267,
     268,   271,   272,   273,   270,   269,   103,   106,   109,   168,
       0,     0,     0,   193,   194,     0,     0,    59,    60,    56,
      86,     0,    83,     0,     0,    68,     0,     0,    72,    63,
       0,     0,   100,   111,    17,    38,    37,    28,   257,     0,
      97,   112,   164,     0,   163,   162,     0,   161,    49,    75,
       0,    78,    79,    80,    62,    73,    64,    65,    67,    66,
      71,    70,     0,    99,   104,     0,    93,   169,   195,     0,
      84,     0,   113,    76,     0,     0,    69,     0,    82,    81
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -380,  -380,   702,  -380,  -380,  -380,  -380,    99,   218,   272,
     274,   -66,   250,  -206,  -380,  -194,   334,  -380,  -380,  -380,
    -380,  -380,  -380,  -352,  -380,   710,   -99,  -119,  -380,   241,
     165,  -380,  -380,  -308,  -379,  -380,  -303,  -380,  -380,   568,
     118,   537,  -156,   429,   -82,  -380,  -380,   178,  -380,  -380,
    -380,   295,   384,   114,   -17,  -380,  -380,  -380,   660,   529,
    -380,  -380,  -380,  -380,  -380,   302,  -380,  -380,   632,   -35,
    -141,  -380,  -380,   412,   605
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    17,   388,    26,    51,
     194,   314,   392,   310,    18,   297,   298,   299,   504,   502,
     542,   590,   452,   300,   301,    27,    19,   201,   411,   454,
     508,   560,   477,   305,   383,   586,   285,    35,    98,    99,
     108,   109,   110,   192,   173,   111,   189,   282,   190,   278,
     434,   435,   270,   423,   530,   112,    20,    31,    64,   123,
      21,    22,    42,   274,    23,    54,    24,    37,    38,   211,
     212,   213,   228,   408,   141
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     100,   316,   223,   227,   302,   354,   488,   126,   179,    56,
     311,   106,   134,    69,    70,    71,    72,    73,  -189,   106,
    -191,  -190,   447,   151,   178,   149,    74,    75,   581,    28,
     432,   340,   279,   450,    76,    59,    32,   241,   290,   135,
     136,   137,   250,   221,   138,   140,   251,   -54,   242,   429,
     490,   218,    79,   -54,   219,    46,   276,   151,   172,    80,
      39,   322,   386,   202,   323,   386,   174,   175,   443,   444,
      36,   267,    81,    82,    83,    45,   571,   290,   -89,    25,
     200,   290,   -86,   268,   307,   205,    47,   181,   207,   127,
      40,   104,   172,   367,   368,   572,   500,   182,   214,   339,
      52,   294,   375,   433,   216,   277,    86,   315,   222,   318,
     229,   230,   232,   234,     1,   100,   337,   237,   238,   239,
      53,   105,   244,   245,   362,   249,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,    60,   494,   495,
     294,   338,   498,   183,   294,   451,    29,    61,   193,   561,
     289,   193,   182,   582,   349,   357,   289,   101,   127,   290,
     387,   291,    53,   394,   200,   303,    65,   291,   102,   528,
      25,   209,     2,   292,    46,   -40,   150,    62,   400,   292,
     341,   356,     7,   324,   350,   325,   243,   384,   568,   536,
     594,     3,   595,   330,   210,     7,     7,   269,   220,   103,
     184,   415,    63,   252,   430,    47,   113,   436,   220,  -148,
      48,   293,   343,   344,    57,   185,   446,   293,   -41,   369,
     366,    49,   294,    33,    34,   180,   114,     4,   317,    41,
     116,   370,   -86,     5,   186,   131,   132,   117,   355,   489,
      50,   312,   118,   414,   203,   389,   390,   417,   418,   419,
     121,   398,   499,   215,   132,    92,    93,    94,    95,    96,
      97,   313,   107,   253,   187,   471,   122,   235,   544,  -189,
     107,  -191,  -190,   177,   246,   559,   247,   248,   393,   591,
     453,   124,   592,   272,   182,  -180,   401,   402,   188,     6,
     505,   545,   405,   129,   200,   364,   365,   295,   296,     7,
     376,   377,     8,     9,   554,    66,    67,   546,   122,   130,
     416,  -180,   133,    68,    69,    70,    71,    72,    73,   426,
     306,    10,   576,   577,   578,   579,   431,    74,    75,   547,
     128,    55,    58,   380,   377,    76,    77,   142,    11,   439,
     377,   440,   377,    78,   448,   377,   455,   456,   463,   464,
     458,   496,   365,    79,   115,   497,   365,   143,   119,   120,
      80,   144,   134,    69,    70,    71,    72,    73,   191,   468,
     537,   365,   472,    81,    82,    83,    74,    75,   538,   365,
     548,   539,   365,   145,    76,   146,   134,    69,    70,    71,
      72,    73,   540,   377,    84,    85,   147,   491,   557,   464,
      74,    75,    79,   206,   208,   224,   549,    86,    76,    80,
     562,   563,   148,   395,   396,   397,   193,   399,   550,   195,
      87,   196,    81,    82,    83,   197,    79,   564,   563,   513,
     393,   565,   563,    80,   515,   167,   168,   169,   170,   171,
     455,   527,   567,   365,   569,   570,    81,    82,    83,   596,
     365,   198,   533,   534,   358,   359,    86,   164,   165,   166,
     167,   168,   169,   170,   171,   438,   424,   425,   531,   532,
     552,   199,   204,     7,   553,   551,   556,   265,   240,   266,
      86,   134,    69,    70,    71,    72,    73,   271,   461,   462,
     273,   225,   280,   281,   283,    74,    75,   466,   284,   286,
     287,   304,   288,    76,   231,   165,   166,   167,   168,   169,
     170,   171,    88,    89,    90,   309,   209,    91,   320,   326,
     342,    79,   134,    69,    70,    71,    72,    73,    80,   171,
     328,   588,   329,   351,   333,   335,    74,    75,   346,   352,
     347,    81,    82,    83,    76,   233,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    92,    93,    94,    95,
      96,    97,    79,   348,   353,    43,   360,   363,     1,    80,
     361,   313,   373,   371,   372,    86,   374,   378,   381,   226,
     385,   382,    81,    82,    83,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   134,    69,    70,
      71,    72,    73,   412,   407,    92,    93,    94,    95,    96,
      97,    74,    75,   386,   410,   413,    86,   420,   422,    76,
     427,   139,   428,   437,   441,   442,     2,   445,   460,    92,
      93,    94,    95,    96,    97,   465,   459,    79,   134,    69,
      70,    71,    72,    73,    80,     3,   473,   474,   475,   476,
     478,   479,    74,    75,   480,   481,   482,    81,    82,    83,
      76,   134,    69,    70,    71,    72,    73,   483,   484,   485,
     487,   486,   511,   492,   501,    74,    75,   503,    79,   510,
     505,     4,   516,    76,   529,    80,   535,     5,   566,   541,
     543,    86,   573,   574,   575,   584,   580,   387,    81,    82,
      83,    79,   585,   587,   589,   593,   597,   365,    80,   598,
     599,   449,    30,   391,    44,   514,   526,   583,   236,   275,
     125,    81,    82,    83,    92,    93,    94,    95,    96,    97,
     379,   493,    86,   308,   421,   176,   457,   134,    69,    70,
      71,    72,    73,     6,   409,   217,     0,     0,     0,     0,
       0,    74,    75,     7,     0,    86,     8,     9,     0,    76,
       0,     0,     0,     0,     0,    92,    93,    94,    95,    96,
      97,     0,     0,     0,     0,    10,     0,    79,     0,     0,
       0,     0,     7,     0,    80,     0,   134,    69,    70,    71,
      72,    73,    11,     0,     0,     0,     0,    81,    82,    83,
      74,    75,     0,     0,     0,     0,     0,     0,    76,     0,
       0,     0,   512,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,     0,     0,    79,     0,     0,     0,
       0,    86,     0,    80,     0,     0,     0,     0,     0,     0,
      92,    93,    94,    95,    96,    97,    81,    82,    83,     0,
     134,    69,    70,    71,    72,    73,     0,     0,     0,     0,
       0,   555,     0,     0,    74,    75,     0,     0,     0,     0,
       0,     0,    76,    68,    69,    70,    71,    72,    73,     0,
      86,    92,    93,    94,    95,    96,    97,    74,    75,     0,
      79,     0,     0,     0,     0,    76,     0,    80,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      81,    82,    83,    79,   154,   155,   156,   157,   158,   159,
      80,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,    81,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,    86,   152,   153,   154,   155,   156,
     157,   158,   159,     0,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,     0,    86,   163,   164,
     165,   166,   167,   168,   169,   170,   171,     0,     0,     0,
      92,    93,    94,    95,    96,    97,   152,   153,   154,   155,
     156,   157,   158,   159,     0,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   152,   153,   154,
     155,   156,   157,   158,   159,     0,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,     0,    92,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
     327,   152,   153,   154,   155,   156,   157,   158,   159,     0,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   152,   153,   154,   155,   156,   157,   158,   159,
       0,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,    93,    94,    95,
      96,    97,   152,   153,   154,   155,   156,   157,   158,   159,
       0,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   152,   153,   154,   155,   156,   157,   158,
     159,     0,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   152,   153,   154,   155,   156,   157,
     158,   159,     0,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,     0,     0,     0,     0,
       0,   319,   152,   153,   154,   155,   156,   157,   158,   159,
       0,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,     0,   469,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   152,   153,   154,   155,   156,   157,
     158,   159,   319,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,     0,     0,     0,     0,
       0,     0,     0,   331,   152,   153,   154,   155,   156,   157,
     158,   159,     0,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,     0,     0,     0,   152,
     153,   154,   155,   156,   157,   158,   159,   332,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
       0,     0,     0,     0,     0,     0,     0,     0,   509,     0,
       0,     0,     0,     0,     0,     0,   517,   518,   519,   520,
     152,   153,   154,   155,   156,   157,   158,   159,     0,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   521,   522,   523,     0,   152,
     153,   154,   155,   156,   157,   158,   159,   470,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     152,   153,   154,   155,   156,   157,   158,   159,   334,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   152,   153,   154,   155,   156,   157,   158,   159,   336,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,     0,     0,     0,     0,     0,     0,     0,   152,
     153,   154,   155,   156,   157,   158,   159,   558,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
       0,     0,   139,     0,   406,     0,     0,     0,   506,   155,
     156,   157,   158,   159,   403,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,     0,     0,     0,
       0,     0,   321,     0,     0,   467,     0,   524,   525,     0,
       0,     0,     0,     0,   151,     0,     0,     0,     0,     0,
     507,   152,   153,   154,   155,   156,   157,   158,   159,     0,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,     0,   404,     0,     0,     0,     0,     0,   172,
     152,   153,   154,   155,   156,   157,   158,   159,     0,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,     0,     0,     0,     0,     0,   345,   152,   153,   154,
     155,   156,   157,   158,   159,     0,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   153,   154,
     155,   156,   157,   158,   159,     0,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,  -192,  -192,
    -192,  -192,   159,     0,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171
};

static const yytype_int16 yycheck[] =
{
      35,   207,   143,   144,   198,    20,    20,   105,   107,     3,
       3,     3,     3,     4,     5,     6,     7,     8,     3,     3,
       3,     3,   374,     3,   106,   105,    17,    18,   129,    68,
     157,     6,   188,   124,    25,     3,     3,     6,   115,    74,
      75,    76,    33,   142,    79,    80,    37,     3,    17,   357,
     429,    91,    43,     3,    94,    79,   134,     3,    38,    50,
       3,    91,   158,   230,    94,   158,   101,   102,   371,   372,
       8,   103,    63,    64,    65,   252,   226,   115,   208,   209,
     239,   115,    38,   115,   203,   191,   110,   191,   191,   256,
      33,   115,    38,   287,   288,   245,   448,   256,   133,   240,
     208,   178,   296,   230,   139,   183,    97,   206,   143,   208,
     145,   146,   147,   148,     3,   150,   235,   152,   153,   154,
     114,   145,   157,   158,   280,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   105,   441,   442,
     178,   240,   445,    62,   178,   236,   185,   115,   254,   528,
     106,   254,   256,   254,   253,   274,   106,     9,   256,   115,
     256,   117,   114,   256,   239,   200,   253,   117,    20,   477,
     209,     3,    61,   129,    79,   252,   256,   145,   319,   129,
     155,   256,   188,   218,   266,   220,   155,   306,   540,   492,
      52,    80,    54,   228,    26,   188,   188,   229,   238,   256,
     119,   342,   170,   194,   360,   110,   252,   363,   238,   128,
     115,   167,   247,   248,   208,   134,   254,   167,   252,   117,
     286,   126,   178,     5,     6,   107,     3,   116,   234,    11,
      97,   129,   188,   122,   153,   253,   254,     3,   253,   253,
     145,   234,     3,   342,   126,   311,   312,   346,   347,   348,
       3,   317,   446,   253,   254,   246,   247,   248,   249,   250,
     251,   254,   254,   254,   183,   406,   253,   149,    17,   254,
     254,   254,   254,   253,    13,   241,    15,    16,   313,   582,
     379,     3,   585,   255,   256,   230,   321,   322,   207,   178,
     256,    40,   327,     3,   239,   255,   256,   253,   254,   188,
     255,   256,   191,   192,   510,    33,    34,    56,   253,     3,
     345,   256,     9,     3,     4,     5,     6,     7,     8,   354,
     202,   210,     4,     5,     6,     7,   361,    17,    18,    78,
     198,    29,    30,   255,   256,    25,    26,   254,   227,   255,
     256,   255,   256,    33,   255,   256,   381,   382,   255,   256,
     385,   255,   256,    43,    52,   255,   256,   254,    56,    57,
      50,   254,     3,     4,     5,     6,     7,     8,    38,   404,
     255,   256,   407,    63,    64,    65,    17,    18,   255,   256,
     129,   255,   256,   254,    25,   254,     3,     4,     5,     6,
       7,     8,   255,   256,    84,    85,   254,   432,   255,   256,
      17,    18,    43,   129,   130,    46,   155,    97,    25,    50,
     255,   256,   254,   314,   315,   316,   254,   318,   167,     3,
     110,     3,    63,    64,    65,     3,    43,   255,   256,   464,
     465,   255,   256,    50,   469,    26,    27,    28,    29,    30,
     475,   476,   255,   256,   255,   256,    63,    64,    65,   255,
     256,   254,   487,   488,   276,   277,    97,    23,    24,    25,
      26,    27,    28,    29,    30,   366,   352,   353,   485,   486,
     505,    26,     3,   188,   509,   224,   511,     3,   254,     3,
      97,     3,     4,     5,     6,     7,     8,   255,   389,   390,
       3,   132,   128,   164,     3,    17,    18,   398,     3,   234,
     254,   162,   254,    25,    26,    24,    25,    26,    27,    28,
      29,    30,   202,   203,   204,     3,     3,   207,   255,   255,
     254,    43,     3,     4,     5,     6,     7,     8,    50,    30,
     255,   566,   255,   129,   255,   255,    17,    18,   254,   129,
     254,    63,    64,    65,    25,    26,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,   246,   247,   248,   249,
     250,   251,    43,   254,   129,     0,   128,   128,     3,    50,
     157,   254,   129,   254,   254,    97,     3,     3,    47,   220,
      20,   135,    63,    64,    65,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     3,     4,     5,
       6,     7,     8,   255,   125,   246,   247,   248,   249,   250,
     251,    17,    18,   158,   108,   255,    97,   255,   102,    25,
       3,   238,     3,     3,   254,   254,    61,   254,     3,   246,
     247,   248,   249,   250,   251,   254,   129,    43,     3,     4,
       5,     6,     7,     8,    50,    80,   255,   255,    47,   109,
     255,   255,    17,    18,   255,   255,   255,    63,    64,    65,
      25,     3,     4,     5,     6,     7,     8,   128,   254,   254,
      20,   254,    20,   254,   254,    17,    18,   254,    43,   227,
     256,   116,   255,    25,     3,    50,     3,   122,    20,     5,
       5,    97,   255,   155,     4,   184,   129,   256,    63,    64,
      65,    43,   126,     3,     5,   255,   191,   256,    50,     4,
       4,   377,     2,    78,    12,   465,   475,   552,   150,   182,
      60,    63,    64,    65,   246,   247,   248,   249,   250,   251,
     301,   436,    97,   204,   350,   103,    78,     3,     4,     5,
       6,     7,     8,   178,   332,   140,    -1,    -1,    -1,    -1,
      -1,    17,    18,   188,    -1,    97,   191,   192,    -1,    25,
      -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   210,    -1,    43,    -1,    -1,
      -1,    -1,   188,    -1,    50,    -1,     3,     4,     5,     6,
       7,     8,   227,    -1,    -1,    -1,    -1,    63,    64,    65,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    78,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    97,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,   250,   251,    63,    64,    65,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,     3,     4,     5,     6,     7,     8,    -1,
      97,   246,   247,   248,   249,   250,   251,    17,    18,    -1,
      43,    -1,    -1,    -1,    -1,    25,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,   246,   247,   248,   249,   250,   251,
      63,    64,    65,    43,    12,    13,    14,    15,    16,    17,
      50,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    63,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    97,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
     246,   247,   248,   249,   250,   251,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,   246,
     247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,    -1,
     105,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,   250,   251,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
     250,   251,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,   256,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,   256,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,   256,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,   255,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      10,    11,    12,    13,    14,    15,    16,    17,   255,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    10,    11,    12,    13,    14,    15,    16,    17,   255,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,   255,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,   238,    -1,   105,    -1,    -1,    -1,    39,    13,
      14,    15,    16,    17,    94,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,   213,    -1,    -1,    94,    -1,   243,   244,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      81,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,   213,    -1,    -1,    -1,    -1,    -1,    38,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    36,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    11,    12,
      13,    14,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
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
       3,   253,   254,     9,     3,   326,   326,   326,   326,   238,
     326,   331,   254,   254,   254,   254,   254,   254,   254,   105,
     256,     3,    10,    11,    12,    13,    14,    15,    16,    17,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    38,   301,   326,   326,   325,   253,   301,   283,
     297,   191,   256,    62,   119,   134,   153,   183,   207,   303,
     305,    38,   300,   254,   267,     3,     3,     3,   254,    26,
     239,   284,   230,   297,     3,   191,   267,   191,   267,     3,
      26,   326,   327,   328,   326,   253,   326,   331,    91,    94,
     238,   283,   326,   327,    46,   132,   220,   327,   329,   326,
     326,    26,   326,    26,   326,   297,   296,   326,   326,   326,
     254,     6,    17,   155,   326,   326,    13,    15,    16,   326,
      33,    37,   194,   254,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,     3,     3,   103,   115,   229,
     309,   255,   255,     3,   320,   298,   134,   183,   306,   299,
     128,   164,   304,     3,     3,   293,   234,   254,   254,   106,
     115,   117,   129,   167,   178,   253,   254,   272,   273,   274,
     280,   281,   272,   326,   162,   290,   297,   284,   316,     3,
     270,     3,   234,   254,   268,   283,   270,   234,   283,   256,
     255,   213,    91,    94,   326,   326,   255,   105,   255,   255,
     326,   256,   256,   255,   255,   255,   255,   284,   283,   327,
       6,   155,   254,   326,   326,    36,   254,   254,   254,   283,
     301,   129,   129,   129,    20,   253,   256,   284,   304,   304,
     128,   157,   299,   128,   255,   256,   268,   272,   272,   117,
     129,   254,   254,   129,     3,   272,   255,   256,     3,   300,
     255,    47,   135,   291,   284,    20,   158,   256,   264,   268,
     268,    78,   269,   326,   256,   264,   264,   264,   268,   264,
     327,   326,   326,    94,   213,   326,   105,   125,   330,   330,
     108,   285,   255,   255,   283,   327,   326,   283,   283,   283,
     255,   309,   102,   310,   310,   310,   326,     3,     3,   290,
     299,   326,   157,   230,   307,   308,   299,     3,   264,   255,
     255,   254,   254,   293,   293,   254,   254,   280,   255,   273,
     124,   236,   279,   283,   286,   326,   326,    78,   326,   129,
       3,   264,   264,   255,   256,   254,   264,    94,   326,   102,
     255,   327,   326,   255,   255,    47,   109,   289,   255,   255,
     255,   255,   255,   128,   254,   254,   254,    20,    20,   253,
     291,   326,   254,   308,   293,   293,   255,   255,   293,   272,
     280,   254,   276,   254,   275,   256,    39,    81,   287,   256,
     227,    20,    78,   326,   269,   326,   255,    72,    73,    74,
      75,   111,   112,   113,   243,   244,   286,   326,   290,     3,
     311,   311,   311,   326,   326,     3,   293,   255,   255,   255,
     255,     5,   277,     5,    17,    40,    56,    78,   129,   155,
     167,   224,   326,   326,   270,    78,   326,   255,   255,   241,
     288,   291,   255,   256,   255,   255,    20,   255,   280,   255,
     256,   226,   245,   255,   155,     4,     4,     5,     6,     7,
     129,   129,   254,   287,   184,   126,   292,     3,   326,     5,
     278,   293,   293,   255,    52,    54,   255,   191,     4,     4
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
     294,   294,   294,   294,   294,   295,   295,   295,   296,   296,
     297,   297,   298,   298,   299,   299,   299,   299,   300,   300,
     301,   301,   301,   302,   302,   302,   302,   302,   303,   303,
     303,   304,   304,   305,   305,   306,   306,   306,   307,   307,
     308,   308,   309,   309,   309,   309,   310,   310,   311,   311,
     312,   259,   313,   314,   314,   314,   314,   313,   315,   315,
     316,   316,   313,   259,   317,   317,   317,   259,   318,   319,
     319,   319,   320,   320,   320,   320,   259,   321,   321,   322,
     322,   259,   323,   324,   324,   325,   325,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   327,   327,   328,   328,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     329,   329,   329,   326,   326,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   326,   326,   326,   326,   331,   331,
     326,   326,   326,   326,   326,   326,   326,   326
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
       2,     2,     2,     2,     2,     1,     3,     1,     2,     3,
       1,     3,     1,     1,     3,     5,     3,     3,     1,     0,
       2,     1,     0,     5,     3,     5,     6,     5,     0,     1,
       1,     0,     1,     1,     1,     2,     2,     0,     1,     0,
       2,     4,     6,     6,     6,     0,     2,     0,     1,     3,
       3,     1,     7,     2,     2,     2,     0,     6,     2,     4,
       0,     2,     7,     1,     8,     7,     7,     1,     8,     0,
       2,     2,     3,     5,     5,     7,     1,     4,     4,     0,
       2,     1,     2,     1,     3,     3,     3,     1,     1,     3,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     5,     6,     6,     6,     3,
       3,     3,     3,     2,     2,     3,     3,     4,     3,     4,
       5,     1,     3,     0,     1,     5,     6,     5,     6,     4,
       4,     4,     4,     4,     4,     4,     6,     8,     4,     7,
       1,     1,     1,     6,     6,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     6,     3,     5,     4,     5,
       3,     4,     3,     4,     1,     1,     1,     2
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
#line 2163 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 329 "pmysql.y" /* yacc.c:1646  */
    {sql_stmt_handle((yyvsp[-1].stmt_node));}
#line 2169 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 332 "pmysql.y" /* yacc.c:1646  */
    {(yyval.stmt_node)=(yyvsp[0].stmt_node);}
#line 2175 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 334 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_show_table_content((yyvsp[0].strval)); free((yyvsp[0].strval));}
#line 2181 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 335 "pmysql.y" /* yacc.c:1646  */
    {(yyval.stmt_node) = sql_show_all_table();}
#line 2187 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 337 "pmysql.y" /* yacc.c:1646  */
    {(yyval.stmt_node)=(yyvsp[0].stmt_node);}
#line 2193 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 339 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node)= sql_import_file((yyvsp[-2].strval)); show_log("import\n");free((yyvsp[-2].strval));}
#line 2199 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 343 "pmysql.y" /* yacc.c:1646  */
    {(yyval.stmt_node)=(yyvsp[0].stmt_node);}
#line 2205 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 345 "pmysql.y" /* yacc.c:1646  */
    {select_stmt_t *test=sql_test_select();(yyval.stmt_node)=sql_sel_stmt_hdl(test);}
#line 2211 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 348 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].stmt_node) ;}
#line 2217 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 354 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_insert_stmt_create((yyvsp[-4].strval), (yyvsp[-3].col_node), (yyvsp[-1].insr_node));show_log("INSERTVALS %d %d %s", (yyvsp[-6].intval), (yyvsp[-1].insr_node), (yyvsp[-4].strval)); }
#line 2223 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 360 "pmysql.y" /* yacc.c:1646  */
    { printf(" %s should be INSERT\n",(yyvsp[-7].strval));(yyval.stmt_node)=NULL; free((yyvsp[-4].strval)); }
#line 2229 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 365 "pmysql.y" /* yacc.c:1646  */
    { printf(" \"VALUES\" is missing\n");(yyval.stmt_node)=NULL; free((yyvsp[-3].strval)); }
#line 2235 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 370 "pmysql.y" /* yacc.c:1646  */
    { printf(" \"%s\" should be VALUES\n", (yyvsp[-2].strval));(yyval.stmt_node)=NULL; free((yyvsp[-4].strval));free((yyvsp[-2].strval)); }
#line 2241 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 373 "pmysql.y" /* yacc.c:1646  */
    { show_log("DUPUPDATE %d", (yyvsp[0].intval)); }
#line 2247 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 376 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2253 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 377 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 01 ; }
#line 2259 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 378 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 02 ; }
#line 2265 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 379 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 04 ; }
#line 2271 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 380 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 010 ; }
#line 2277 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 386 "pmysql.y" /* yacc.c:1646  */
    { (yyval.col_node) = NULL ;}
#line 2283 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 387 "pmysql.y" /* yacc.c:1646  */
    { (yyval.col_node) = (yyvsp[-1].col_node); sql_print_col_node((yyvsp[-1].col_node));show_log("INSERTCOLS %d", (yyvsp[-1].col_node)); }
#line 2289 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 390 "pmysql.y" /* yacc.c:1646  */
    { (yyval.insr_node) = (yyvsp[-1].insr_node); }
#line 2295 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 391 "pmysql.y" /* yacc.c:1646  */
    { show_log("VALUES %d", (yyvsp[-1].insr_node)); (yyval.insr_node) = (yyvsp[-4].insr_node) + 1; }
#line 2301 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 394 "pmysql.y" /* yacc.c:1646  */
    { (yyval.insr_node) = sql_insert_vals_node_create((yyvsp[0].expr_node), NULL, true); }
#line 2307 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 395 "pmysql.y" /* yacc.c:1646  */
    { show_log("DEFAULT"); (yyval.insr_node) = NULL; }
#line 2313 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 396 "pmysql.y" /* yacc.c:1646  */
    { (yyval.insr_node) = sql_insert_vals_node_create((yyvsp[0].expr_node), (yyvsp[-2].insr_node), false); }
#line 2319 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 397 "pmysql.y" /* yacc.c:1646  */
    { show_log("DEFAULT"); (yyval.insr_node) = NULL; }
#line 2325 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 403 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSERTASGN %d %d %s", (yyvsp[-5].intval), (yyvsp[-1].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 2331 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 408 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSERTSELECT %d %s", (yyvsp[-5].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 2337 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 413 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
       show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 2344 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 416 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
                 show_log("DEFAULT"); show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 2351 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 419 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-4].intval));
                 show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 2358 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 422 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-4].intval));
                 show_log("DEFAULT"); show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 2365 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 427 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].stmt_node);show_log("STMT"); }
#line 2371 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 432 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_cret_table_stmt_create((yyvsp[-3].strval), (yyvsp[-1].attr_node)); if ((yyval.stmt_node)==NULL) sql_free_attr_header_list((yyvsp[-1].attr_node)); show_log("CREATE %d %d %s", (yyvsp[-6].intval), (yyvsp[-4].intval), (yyvsp[-3].strval)); }
#line 2377 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 436 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATE %d %d %s.%s", (yyvsp[-8].intval), (yyvsp[-6].intval), (yyvsp[-5].strval), (yyvsp[-3].strval));
                          free((yyvsp[-5].strval)); free((yyvsp[-3].strval)); }
#line 2384 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 442 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d %s", (yyvsp[-7].intval), (yyvsp[-5].intval),(yyvsp[-4].strval)); free((yyvsp[-4].strval)); }
#line 2390 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 446 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d 0 %s", (yyvsp[-4].intval), (yyvsp[-2].intval), (yyvsp[-1].strval)); free((yyvsp[-1].strval)); }
#line 2396 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 450 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"Table\"is missing\n ");(yyval.stmt_node)=NULL;if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-3].strval));}
#line 2402 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 451 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"(\"is missing\n ");(yyval.stmt_node)=NULL;if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-2].strval));}
#line 2408 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 452 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\")\"is missing \n");(yyval.stmt_node)=NULL;if ((yyvsp[0].attr_node)) sql_free_attr_header_list((yyvsp[0].attr_node));free((yyvsp[-2].strval));}
#line 2414 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 453 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"%s\" should be CREATE\n ", (yyvsp[-7].strval));(yyval.stmt_node)=NULL;if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-7].strval));free((yyvsp[-3].strval));}
#line 2420 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 454 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"%s\" should be TABLE\n ", (yyvsp[-5].strval));(yyval.stmt_node)=NULL; if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-5].strval));free((yyvsp[-3].strval));}
#line 2426 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 458 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d 0 %s.%s", (yyvsp[-9].intval), (yyvsp[-7].intval), (yyvsp[-6].strval), (yyvsp[-4].strval));
                              free((yyvsp[-6].strval)); free((yyvsp[-4].strval)); }
#line 2433 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 463 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d 0 %s.%s", (yyvsp[-6].intval), (yyvsp[-4].intval), (yyvsp[-3].strval), (yyvsp[-1].strval));
                          free((yyvsp[-3].strval)); free((yyvsp[-1].strval)); }
#line 2440 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 467 "pmysql.y" /* yacc.c:1646  */
    {(yyval.attr_node)=sql_cret_def_handle(NULL, (yyvsp[0].cret_node)); sql_printf_attr((yyvsp[0].cret_node)->cret_def_info); }
#line 2446 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 468 "pmysql.y" /* yacc.c:1646  */
    { sql_recursive_printf_node((yyvsp[-2].attr_node)); (yyval.attr_node) = sql_cret_def_handle((yyvsp[-2].attr_node), (yyvsp[0].cret_node)); sql_printf_attr((yyval.attr_node));}
#line 2452 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 471 "pmysql.y" /* yacc.c:1646  */
    {printf("NULL column\n");}
#line 2458 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 472 "pmysql.y" /* yacc.c:1646  */
    {}
#line 2464 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 473 "pmysql.y" /* yacc.c:1646  */
    { (yyval.cret_node) = sql_cret_def_attr_declar_node_create((yyvsp[-2].strval), (yyvsp[-1].intval), (yyvsp[0].intval));/*show_log("COLUMNDEF %d %s", $3, $2); */ }
#line 2470 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 475 "pmysql.y" /* yacc.c:1646  */
    { (yyval.cret_node) = sql_cret_def_pk_def_node_create((yyvsp[-1].col_node)); show_log("PRIKEY %d", (yyvsp[-1].col_node)); }
#line 2476 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 476 "pmysql.y" /* yacc.c:1646  */
    { show_log("KEY %d", (yyvsp[-1].col_node)); }
#line 2482 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 477 "pmysql.y" /* yacc.c:1646  */
    { show_log("KEY %d", (yyvsp[-1].col_node)); }
#line 2488 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 478 "pmysql.y" /* yacc.c:1646  */
    { show_log("TEXTINDEX %d", (yyvsp[-1].col_node)); }
#line 2494 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 479 "pmysql.y" /* yacc.c:1646  */
    { show_log("TEXTINDEX %d", (yyvsp[-1].col_node)); }
#line 2500 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 482 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (1<<COL_ATTR_VALID); }
#line 2506 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 483 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR NOTNULL"); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2512 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 485 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT STRING %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2518 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 486 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT NUMBER %d", (yyvsp[0].intval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2524 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 487 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT FLOAT %g", (yyvsp[0].floatval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2530 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 488 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT BOOL %d", (yyvsp[0].intval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2536 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 489 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR AUTOINC"); (yyval.intval) = (yyvsp[-1].intval) + 1; }
#line 2542 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 490 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR UNIQUEKEY %d", (yyvsp[-1].col_node)); (yyval.intval) = 1<<((yyvsp[-4].intval) + 1); }
#line 2548 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 491 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR UNIQUEKEY"); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2554 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 492 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR PRIKEY"); (yyval.intval) = 1<<COL_ATTR_PRIKEY; }
#line 2560 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 493 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR PRIKEY"); (yyval.intval) = 1<<COL_ATTR_PRIKEY; }
#line 2566 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 494 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR COMMENT %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2572 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 497 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2578 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 498 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval); }
#line 2584 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 499 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-3].intval) + 1000*(yyvsp[-1].intval); }
#line 2590 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 506 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2596 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 507 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 1000; }
#line 2602 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 508 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 2000; }
#line 2608 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 512 "pmysql.y" /* yacc.c:1646  */
    { show_log("COLCHARSET %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2614 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 513 "pmysql.y" /* yacc.c:1646  */
    { show_log("COLCOLLATE %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2620 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 517 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = DATA_TYPE_INT;}
#line 2626 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 518 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = DATA_TYPE_VARCHAR + (yyvsp[-2].intval);}
#line 2632 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 555 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d", (yyvsp[-2].intval)); }
#line 2638 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 558 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2644 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 559 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2650 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 560 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2; }
#line 2656 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 563 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2662 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 564 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1;}
#line 2668 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 572 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].stmt_node); show_log("STMT"); }
#line 2674 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 576 "pmysql.y" /* yacc.c:1646  */
    { show_log("SELECTNODATA %d %d", (yyvsp[-1].intval), (yyvsp[0].select_col_node)); }
#line 2680 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 580 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_select_stmt_create(STMT_TYPE_SELECT_TUPLE, (yyvsp[-8].select_col_node), (yyvsp[-6].select_table_node), (yyvsp[-5].expr_node)); show_log("SELECT %d %d %d", (yyvsp[-9].intval), (yyvsp[-8].select_col_node), (yyvsp[-6].select_table_node)); }
#line 2686 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 583 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = NULL;}
#line 2692 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 584 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[0].expr_node); show_log("WHERE"); }
#line 2698 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 588 "pmysql.y" /* yacc.c:1646  */
    { show_log("GROUPBYLIST %d %d", (yyvsp[-1].intval), (yyvsp[0].intval)); }
#line 2704 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 592 "pmysql.y" /* yacc.c:1646  */
    { show_log("GROUPBY %d",  (yyvsp[0].intval)); (yyval.intval) = 1; }
#line 2710 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 594 "pmysql.y" /* yacc.c:1646  */
    { show_log("GROUPBY %d",  (yyvsp[0].intval)); (yyval.intval) = (yyvsp[-3].intval) + 1; }
#line 2716 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 597 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2722 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 598 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2728 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 599 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2734 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 602 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2740 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 603 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2746 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 606 "pmysql.y" /* yacc.c:1646  */
    { show_log("HAVING"); }
#line 2752 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 608 "pmysql.y" /* yacc.c:1646  */
    { show_log("ORDERBY %d", (yyvsp[0].intval)); }
#line 2758 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 611 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIMIT 1"); }
#line 2764 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 612 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIMIT 2"); }
#line 2770 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 616 "pmysql.y" /* yacc.c:1646  */
    { show_log("INTO %d", (yyvsp[0].col_node)); }
#line 2776 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 619 "pmysql.y" /* yacc.c:1646  */
    { show_log("COLUMN %s", (yyvsp[0].strval)); (yyval.col_node) = sql_col_list_node_create((yyvsp[0].strval), NULL, true); }
#line 2782 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 620 "pmysql.y" /* yacc.c:1646  */
    { (yyval.col_node) = sql_col_list_node_create((yyvsp[0].strval), (yyvsp[-2].col_node), false);show_log("COLUMN %s", (yyvsp[0].strval));}
#line 2788 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 623 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2794 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 624 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 01) yyerror("duplicate ALL option"); (yyval.intval) = (yyvsp[-1].intval) | 01; }
#line 2800 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 625 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 02) yyerror("duplicate DISTINCT option"); (yyval.intval) = (yyvsp[-1].intval) | 02; }
#line 2806 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 626 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 04) yyerror("duplicate DISTINCTROW option"); (yyval.intval) = (yyvsp[-1].intval) | 04; }
#line 2812 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 627 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 010) yyerror("duplicate HIGH_PRIORITY option"); (yyval.intval) = (yyvsp[-1].intval) | 010; }
#line 2818 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 628 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 020) yyerror("duplicate STRAIGHT_JOIN option"); (yyval.intval) = (yyvsp[-1].intval) | 020; }
#line 2824 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 629 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 040) yyerror("duplicate SQL_SMALL_RESULT option"); (yyval.intval) = (yyvsp[-1].intval) | 040; }
#line 2830 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 630 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 0100) yyerror("duplicate SQL_BIG_RESULT option"); (yyval.intval) = (yyvsp[-1].intval) | 0100; }
#line 2836 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 631 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 0200) yyerror("duplicate SQL_CALC_FOUND_ROWS option"); (yyval.intval) = (yyvsp[-1].intval) | 0200; }
#line 2842 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 634 "pmysql.y" /* yacc.c:1646  */
    { (yyval.select_col_node) = sql_select_col_list_create((yyvsp[0].select_col_node), NULL, true, false); }
#line 2848 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 635 "pmysql.y" /* yacc.c:1646  */
    {(yyval.select_col_node) = sql_select_col_list_create((yyvsp[0].select_col_node), (yyvsp[-2].select_col_node), false, false); }
#line 2854 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 636 "pmysql.y" /* yacc.c:1646  */
    { show_log("SELECTALL"); (yyval.select_col_node) = sql_select_col_list_create(NULL, NULL, true, true); }
#line 2860 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 639 "pmysql.y" /* yacc.c:1646  */
    { (yyval.select_col_node) = sql_select_col_node_create((yyvsp[-1].expr_node), (yyvsp[0].alias_name), false); }
#line 2866 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 640 "pmysql.y" /* yacc.c:1646  */
    { (yyval.select_col_node) = sql_select_col_node_create(NULL, (yyvsp[-2].strval), true); show_log("NAME.*\n"); }
#line 2872 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 643 "pmysql.y" /* yacc.c:1646  */
    { (yyval.select_table_node) = sql_select_table_list_create((yyvsp[0].select_table_node), NULL, true); }
#line 2878 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 644 "pmysql.y" /* yacc.c:1646  */
    {  (yyval.select_table_node) = sql_select_table_list_create((yyvsp[0].select_table_node), (yyvsp[-2].select_table_node), false); }
#line 2884 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 652 "pmysql.y" /* yacc.c:1646  */
    {(yyval.select_table_node) = sql_select_table_node_create((yyvsp[-2].strval), NULL, (yyvsp[-1].alias_name)); show_log("TABLE %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 2890 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 653 "pmysql.y" /* yacc.c:1646  */
    {(yyval.select_table_node) = sql_select_table_node_create((yyvsp[-2].strval), (yyvsp[-4].strval), (yyvsp[-1].alias_name)); show_log("TABLE %s.%s", (yyvsp[-4].strval), (yyvsp[-2].strval));
                               free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); }
#line 2897 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 655 "pmysql.y" /* yacc.c:1646  */
    { show_log("SUBQUERYAS %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2903 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 656 "pmysql.y" /* yacc.c:1646  */
    { show_log("TABLEREFERENCES %d", (yyvsp[-1].select_table_node)); }
#line 2909 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 663 "pmysql.y" /* yacc.c:1646  */
    { (yyval.alias_name) = strdup((yyvsp[0].strval)); show_log ("ALIAS %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2915 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 664 "pmysql.y" /* yacc.c:1646  */
    { (yyval.alias_name) = strdup((yyvsp[0].strval)); show_log ("ALIAS %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2921 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 665 "pmysql.y" /* yacc.c:1646  */
    { (yyval.alias_name) = NULL; }
#line 2927 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 670 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0100+(yyvsp[-3].intval)); }
#line 2933 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 672 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0200); }
#line 2939 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 674 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0200); }
#line 2945 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 676 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0300+(yyvsp[-4].intval)+(yyvsp[-3].intval)); }
#line 2951 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 678 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0400+(yyvsp[-2].intval)); }
#line 2957 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 681 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2963 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 682 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2969 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 683 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2; }
#line 2975 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 686 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2981 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 687 "pmysql.y" /* yacc.c:1646  */
    {(yyval.intval) = 4; }
#line 2987 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 690 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2993 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 691 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2; }
#line 2999 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 694 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1 + (yyvsp[0].intval); }
#line 3005 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 695 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2 + (yyvsp[0].intval); }
#line 3011 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 696 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3017 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 702 "pmysql.y" /* yacc.c:1646  */
    { show_log("ONEXPR"); }
#line 3023 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 703 "pmysql.y" /* yacc.c:1646  */
    { show_log("USING %d", (yyvsp[-1].col_node)); }
#line 3029 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 708 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEXHINT %d %d", (yyvsp[-1].intval), 010+(yyvsp[-3].intval)); }
#line 3035 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 710 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEXHINT %d %d", (yyvsp[-1].intval), 020+(yyvsp[-3].intval)); }
#line 3041 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 712 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEXHINT %d %d", (yyvsp[-1].intval), 030+(yyvsp[-3].intval)); }
#line 3047 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 716 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3053 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 717 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3059 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 720 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEX %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1; }
#line 3065 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 721 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEX %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3071 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 724 "pmysql.y" /* yacc.c:1646  */
    { show_log("SUBQUERY"); }
#line 3077 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 729 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3083 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 734 "pmysql.y" /* yacc.c:1646  */
    { show_log("DELETEONE %d %s", (yyvsp[-5].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3089 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 737 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) + 01; }
#line 3095 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 738 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) + 02; }
#line 3101 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 739 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) + 04; }
#line 3107 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 740 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3113 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 746 "pmysql.y" /* yacc.c:1646  */
    { show_log("DELETEMULTI %d %d %d", (yyvsp[-4].intval), (yyvsp[-3].intval), (yyvsp[-1].select_table_node)); }
#line 3119 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 748 "pmysql.y" /* yacc.c:1646  */
    { show_log("TABLE %s", (yyvsp[-1].strval)); free((yyvsp[-1].strval)); (yyval.intval) = 1; }
#line 3125 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 750 "pmysql.y" /* yacc.c:1646  */
    { show_log("TABLE %s", (yyvsp[-1].strval)); free((yyvsp[-1].strval)); (yyval.intval) = (yyvsp[-3].intval) + 1; }
#line 3131 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 758 "pmysql.y" /* yacc.c:1646  */
    { show_log("DELETEMULTI %d %d %d", (yyvsp[-5].intval), (yyvsp[-3].intval), (yyvsp[-1].select_table_node)); }
#line 3137 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 761 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3143 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 767 "pmysql.y" /* yacc.c:1646  */
    { show_log("REPLACEVALS %d %d %s", (yyvsp[-6].intval), (yyvsp[-1].insr_node), (yyvsp[-4].strval)); free((yyvsp[-4].strval)); }
#line 3149 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 773 "pmysql.y" /* yacc.c:1646  */
    { show_log("REPLACEASGN %d %d %s", (yyvsp[-5].intval), (yyvsp[-1].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3155 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 778 "pmysql.y" /* yacc.c:1646  */
    { show_log("REPLACESELECT %d %s", (yyvsp[-5].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3161 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 782 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3167 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 789 "pmysql.y" /* yacc.c:1646  */
    { show_log("UPDATE %d %d %d", (yyvsp[-6].intval), (yyvsp[-5].select_table_node), (yyvsp[-3].intval)); }
#line 3173 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 792 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3179 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 793 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 01 ; }
#line 3185 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 794 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 010 ; }
#line 3191 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 799 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
	 show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 3198 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 802 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-4].strval));
	 show_log("ASSIGN %s.%s", (yyvsp[-4].strval), (yyvsp[-2].strval)); free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 3205 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 805 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
	 show_log("ASSIGN %s.%s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 3212 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 808 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s.$s", (yyvsp[-4].strval), (yyvsp[-2].strval));
	 show_log("ASSIGN %s.%s", (yyvsp[-4].strval), (yyvsp[-2].strval)); free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 3219 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 815 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3225 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 819 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATEDATABASE %d %s", (yyvsp[-1].intval), (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3231 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 820 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATEDATABASE %d %s", (yyvsp[-1].intval), (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3237 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 823 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3243 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 824 "pmysql.y" /* yacc.c:1646  */
    { if(!(yyvsp[0].subtok))yyerror("IF EXISTS doesn't exist");
                        (yyval.intval) = (yyvsp[0].subtok); /* NOT EXISTS hack */ }
#line 3250 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 829 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3256 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 837 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad set to @%s", (yyvsp[-2].strval));
		 show_log("SET %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3263 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 839 "pmysql.y" /* yacc.c:1646  */
    { show_log("SET %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3269 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 844 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_NAME, 0, (yyvsp[0].strval), NULL);show_log("NAME %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3275 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 845 "pmysql.y" /* yacc.c:1646  */
    { show_log("USERVAR %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3281 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 846 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_PREFIX, 0, (yyvsp[0].strval), (yyvsp[-2].strval));show_log("FIELDNAME %s.%s", (yyvsp[-2].strval), (yyvsp[0].strval)); free((yyvsp[-2].strval)); free((yyvsp[0].strval)); }
#line 3287 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 847 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_VARCHAR, 0, (yyvsp[0].strval), NULL); show_log("STRING %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3293 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 848 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_INT, (yyvsp[0].intval), NULL, NULL); show_log("NUMBER %d", (yyvsp[0].intval)); }
#line 3299 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 849 "pmysql.y" /* yacc.c:1646  */
    { show_log("FLOAT %g", (yyvsp[0].floatval)); }
#line 3305 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 850 "pmysql.y" /* yacc.c:1646  */
    { show_log("BOOL %d", (yyvsp[0].intval)); }
#line 3311 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 853 "pmysql.y" /* yacc.c:1646  */
    { show_log("ADD"); }
#line 3317 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 854 "pmysql.y" /* yacc.c:1646  */
    { show_log("SUB"); }
#line 3323 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 855 "pmysql.y" /* yacc.c:1646  */
    { show_log("MUL"); }
#line 3329 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 856 "pmysql.y" /* yacc.c:1646  */
    { show_log("DIV"); }
#line 3335 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 857 "pmysql.y" /* yacc.c:1646  */
    { show_log("MOD"); }
#line 3341 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 858 "pmysql.y" /* yacc.c:1646  */
    { show_log("MOD"); }
#line 3347 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 859 "pmysql.y" /* yacc.c:1646  */
    { show_log("NEG"); }
#line 3353 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 860 "pmysql.y" /* yacc.c:1646  */
    {(yyval.expr_node) = sql_expr_logic_node_create(LGC_TYPE_AND, (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); show_log("AND"); }
#line 3359 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 861 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_logic_node_create(LGC_TYPE_OR, (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); show_log("OR"); }
#line 3365 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 862 "pmysql.y" /* yacc.c:1646  */
    { show_log("XOR"); }
#line 3371 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 863 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_comparison_node_create((yyvsp[-1].subtok), (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); show_log("CMP %d", (yyvsp[-1].subtok)); }
#line 3377 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 864 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPSELECT %d", (yyvsp[-3].subtok)); }
#line 3383 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 865 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPANYSELECT %d", (yyvsp[-4].subtok)); }
#line 3389 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 866 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPANYSELECT %d", (yyvsp[-4].subtok)); }
#line 3395 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 867 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPALLSELECT %d", (yyvsp[-4].subtok)); }
#line 3401 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 868 "pmysql.y" /* yacc.c:1646  */
    { show_log("BITOR"); }
#line 3407 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 869 "pmysql.y" /* yacc.c:1646  */
    { show_log("BITAND"); }
#line 3413 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 870 "pmysql.y" /* yacc.c:1646  */
    { show_log("BITXOR"); }
#line 3419 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 871 "pmysql.y" /* yacc.c:1646  */
    { show_log("SHIFT %s", (yyvsp[-1].subtok)==1?"left":"right"); }
#line 3425 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 872 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOT"); }
#line 3431 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 873 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOT"); }
#line 3437 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 874 "pmysql.y" /* yacc.c:1646  */
    { show_log("ASSIGN @%s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3443 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 877 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISNULL"); }
#line 3449 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 878 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISNULL"); show_log("NOT"); }
#line 3455 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 879 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISBOOL %d", (yyvsp[0].intval)); }
#line 3461 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 880 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISBOOL %d", (yyvsp[0].intval)); show_log("NOT"); }
#line 3467 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 883 "pmysql.y" /* yacc.c:1646  */
    { show_log("BETWEEN"); }
#line 3473 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 887 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3479 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 888 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1 + (yyvsp[0].intval); }
#line 3485 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 891 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3491 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 895 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISIN %d", (yyvsp[-1].intval)); }
#line 3497 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 896 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISIN %d", (yyvsp[-1].intval)); show_log("NOT"); }
#line 3503 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 897 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSELECT"); }
#line 3509 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 898 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSELECT"); show_log("NOT"); }
#line 3515 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 899 "pmysql.y" /* yacc.c:1646  */
    { show_log("EXISTS"); if((yyvsp[-3].subtok))show_log("NOT"); }
#line 3521 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 902 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL %d %s", (yyvsp[-1].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3527 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 906 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_aggregation_node_create(AGGR_TYPE_COUNT, true, NULL); show_log("COUNTALL "); }
#line 3533 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 907 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_aggregation_node_create(AGGR_TYPE_COUNT, false, (yyvsp[-1].expr_node)); show_log(" CALL 1 COUNT"); }
#line 3539 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 909 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_aggregation_node_create(AGGR_TYPE_SUM, true, NULL); show_log("SUMALL"); }
#line 3545 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 910 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_aggregation_node_create(AGGR_TYPE_SUM, false, (yyvsp[-1].expr_node)); show_log(" CALL 1 SUM"); }
#line 3551 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 912 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL %d SUBSTR", (yyvsp[-1].intval));}
#line 3557 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 913 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL 2 SUBSTR"); }
#line 3563 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 914 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL 3 SUBSTR"); }
#line 3569 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 915 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL %d TRIM", (yyvsp[-1].intval)); }
#line 3575 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 916 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL 3 TRIM"); }
#line 3581 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 919 "pmysql.y" /* yacc.c:1646  */
    { show_log("INT 1"); }
#line 3587 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 920 "pmysql.y" /* yacc.c:1646  */
    { show_log("INT 2"); }
#line 3593 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 921 "pmysql.y" /* yacc.c:1646  */
    { show_log("INT 3"); }
#line 3599 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 924 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL 3 DATE_ADD"); }
#line 3605 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 925 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL 3 DATE_SUB"); }
#line 3611 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 928 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 1"); }
#line 3617 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 929 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 2"); }
#line 3623 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 930 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 3"); }
#line 3629 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 931 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 4"); }
#line 3635 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 932 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 5"); }
#line 3641 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 933 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 6"); }
#line 3647 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 934 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 7"); }
#line 3653 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 935 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 8"); }
#line 3659 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 936 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 9"); }
#line 3665 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 939 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASEVAL %d 0", (yyvsp[-1].intval)); }
#line 3671 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 940 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASEVAL %d 1", (yyvsp[-3].intval)); }
#line 3677 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 941 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASE %d 0", (yyvsp[-1].intval)); }
#line 3683 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 942 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASE %d 1", (yyvsp[-3].intval)); }
#line 3689 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 945 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3695 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 946 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-4].intval)+1; }
#line 3701 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 949 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIKE"); }
#line 3707 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 950 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIKE"); show_log("NOT"); }
#line 3713 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 953 "pmysql.y" /* yacc.c:1646  */
    { show_log("REGEXP"); }
#line 3719 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 954 "pmysql.y" /* yacc.c:1646  */
    { show_log("REGEXP"); show_log("NOT"); }
#line 3725 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 957 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOW"); }
#line 3731 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 958 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOW");}
#line 3737 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 959 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOW"); }
#line 3743 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 962 "pmysql.y" /* yacc.c:1646  */
    { show_log("STRTOBIN"); }
#line 3749 "pmysql.tab.c" /* yacc.c:1646  */
    break;


#line 3753 "pmysql.tab.c" /* yacc.c:1646  */
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
#line 965 "pmysql.y" /* yacc.c:1906  */

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
