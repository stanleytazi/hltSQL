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
#include "cret_idx.h"
void yyerror(char *s, ...);
void show_log(char *s, ...);
#if YYBISON
union YYSTYPE;
//int yylex(union YYSTYPE *, void *); //for re-entrant?
int yylex();
#endif

#line 81 "pmysql.tab.c" /* yacc.c:339  */

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
    CREATE_INDEX = 308,
    CROSS = 309,
    CURRENT_DATE = 310,
    CURRENT_TIME = 311,
    CURRENT_TIMESTAMP = 312,
    CURRENT_USER = 313,
    CURSOR = 314,
    DATABASE = 315,
    DATABASES = 316,
    DATE = 317,
    DATETIME = 318,
    DAY_HOUR = 319,
    DAY_MICROSECOND = 320,
    DAY_MINUTE = 321,
    DAY_SECOND = 322,
    DECIMAL = 323,
    DECLARE = 324,
    DEFAULT = 325,
    DELAYED = 326,
    DELETE = 327,
    DESC = 328,
    DESCRIBE = 329,
    DETERMINISTIC = 330,
    DISTINCT = 331,
    DISTINCTROW = 332,
    DIV = 333,
    DOUBLE = 334,
    DROP = 335,
    DUAL = 336,
    EACH = 337,
    ELSE = 338,
    ELSEIF = 339,
    ENCLOSED = 340,
    END = 341,
    ENUM = 342,
    ESCAPED = 343,
    EXISTS = 344,
    EXIT = 345,
    EXPLAIN = 346,
    FETCH = 347,
    FLOAT = 348,
    FOR = 349,
    FORCE = 350,
    FOREIGN = 351,
    FROM = 352,
    FULLTEXT = 353,
    GRANT = 354,
    GROUP = 355,
    HAVING = 356,
    HIGH_PRIORITY = 357,
    HOUR_MICROSECOND = 358,
    HOUR_MINUTE = 359,
    HOUR_SECOND = 360,
    IF = 361,
    IGNORE = 362,
    IMPORT = 363,
    INDEX = 364,
    INFILE = 365,
    INNER = 366,
    INOUT = 367,
    INSENSITIVE = 368,
    INSERT = 369,
    INT = 370,
    INTEGER = 371,
    INTERVAL = 372,
    INTO = 373,
    ITERATE = 374,
    JOIN = 375,
    KEY = 376,
    KEYS = 377,
    KILL = 378,
    LEADING = 379,
    LEAVE = 380,
    LEFT = 381,
    LIMIT = 382,
    LINES = 383,
    LOAD = 384,
    LOCALTIME = 385,
    LOCALTIMESTAMP = 386,
    LOCK = 387,
    LONG = 388,
    LONGBLOB = 389,
    LONGTEXT = 390,
    LOOP = 391,
    LOW_PRIORITY = 392,
    MATCH = 393,
    MEDIUMBLOB = 394,
    MEDIUMINT = 395,
    MEDIUMTEXT = 396,
    MINUTE_MICROSECOND = 397,
    MINUTE_SECOND = 398,
    MODIFIES = 399,
    NATURAL = 400,
    NO_WRITE_TO_BINLOG = 401,
    NULLX = 402,
    NUMBER = 403,
    ON = 404,
    ONDUPLICATE = 405,
    OPTIMIZE = 406,
    OPTION = 407,
    OPTIONALLY = 408,
    ORDER = 409,
    OUT = 410,
    OUTER = 411,
    OUTFILE = 412,
    PRECISION = 413,
    PRIMARY = 414,
    PROCEDURE = 415,
    PURGE = 416,
    QUICK = 417,
    READ = 418,
    READS = 419,
    REAL = 420,
    REFERENCES = 421,
    RELEASE = 422,
    RENAME = 423,
    REPEAT = 424,
    REPLACE = 425,
    REQUIRE = 426,
    RESTRICT = 427,
    RETURN = 428,
    REVOKE = 429,
    RIGHT = 430,
    ROLLUP = 431,
    SCHEMA = 432,
    SCHEMAS = 433,
    SECOND_MICROSECOND = 434,
    SELECT = 435,
    SENSITIVE = 436,
    SEPARATOR = 437,
    SET = 438,
    SHOW = 439,
    SMALLINT = 440,
    SOME = 441,
    SONAME = 442,
    SPATIAL = 443,
    SPECIFIC = 444,
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
#line 22 "pmysql.y" /* yacc.c:355  */

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

#line 381 "pmysql.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PMYSQL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 396 "pmysql.tab.c" /* yacc.c:358  */

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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1711

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  257
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  289
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  607

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
       0,   329,   329,   330,   333,   335,   336,   338,   340,   344,
     346,   349,   352,   358,   363,   368,   373,   374,   377,   378,
     379,   380,   381,   384,   384,   387,   388,   391,   392,   395,
     396,   397,   398,   401,   407,   413,   416,   419,   422,   429,
     432,   434,   437,   440,   445,   450,   455,   460,   461,   462,
     463,   464,   466,   472,   477,   478,   481,   482,   482,   485,
     486,   487,   488,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   506,   507,   508,   515,
     516,   517,   520,   521,   522,   526,   527,   564,   567,   568,
     569,   572,   573,   581,   584,   586,   592,   593,   595,   596,
     600,   602,   606,   607,   608,   611,   612,   615,   615,   617,
     617,   620,   620,   621,   624,   625,   628,   629,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   643,   644,   645,
     648,   649,   652,   653,   656,   657,   661,   662,   664,   665,
     668,   669,   672,   673,   674,   678,   680,   682,   684,   686,
     690,   691,   692,   695,   696,   699,   700,   703,   704,   705,
     708,   708,   711,   712,   716,   718,   720,   722,   725,   726,
     729,   730,   733,   738,   741,   746,   747,   748,   749,   752,
     757,   758,   762,   762,   764,   770,   773,   779,   785,   791,
     794,   801,   802,   803,   807,   810,   813,   816,   824,   828,
     829,   832,   833,   838,   841,   843,   843,   846,   848,   853,
     854,   855,   856,   857,   858,   859,   862,   863,   864,   865,
     866,   867,   868,   869,   870,   871,   872,   873,   874,   875,
     876,   877,   878,   879,   880,   881,   882,   883,   886,   887,
     888,   889,   892,   896,   897,   900,   901,   904,   905,   906,
     907,   908,   911,   915,   916,   918,   919,   921,   922,   923,
     924,   925,   928,   929,   930,   933,   934,   937,   938,   939,
     940,   941,   942,   943,   944,   945,   948,   949,   950,   951,
     954,   955,   958,   959,   962,   963,   966,   967,   968,   971
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
  "CREATE", "CREATE_INDEX", "CROSS", "CURRENT_DATE", "CURRENT_TIME",
  "CURRENT_TIMESTAMP", "CURRENT_USER", "CURSOR", "DATABASE", "DATABASES",
  "DATE", "DATETIME", "DAY_HOUR", "DAY_MICROSECOND", "DAY_MINUTE",
  "DAY_SECOND", "DECIMAL", "DECLARE", "DEFAULT", "DELAYED", "DELETE",
  "DESC", "DESCRIBE", "DETERMINISTIC", "DISTINCT", "DISTINCTROW", "DIV",
  "DOUBLE", "DROP", "DUAL", "EACH", "ELSE", "ELSEIF", "ENCLOSED", "END",
  "ENUM", "ESCAPED", "EXISTS", "EXIT", "EXPLAIN", "FETCH", "FLOAT", "FOR",
  "FORCE", "FOREIGN", "FROM", "FULLTEXT", "GRANT", "GROUP", "HAVING",
  "HIGH_PRIORITY", "HOUR_MICROSECOND", "HOUR_MINUTE", "HOUR_SECOND", "IF",
  "IGNORE", "IMPORT", "INDEX", "INFILE", "INNER", "INOUT", "INSENSITIVE",
  "INSERT", "INT", "INTEGER", "INTERVAL", "INTO", "ITERATE", "JOIN", "KEY",
  "KEYS", "KILL", "LEADING", "LEAVE", "LEFT", "LIMIT", "LINES", "LOAD",
  "LOCALTIME", "LOCALTIMESTAMP", "LOCK", "LONG", "LONGBLOB", "LONGTEXT",
  "LOOP", "LOW_PRIORITY", "MATCH", "MEDIUMBLOB", "MEDIUMINT", "MEDIUMTEXT",
  "MINUTE_MICROSECOND", "MINUTE_SECOND", "MODIFIES", "NATURAL",
  "NO_WRITE_TO_BINLOG", "NULLX", "NUMBER", "ON", "ONDUPLICATE", "OPTIMIZE",
  "OPTION", "OPTIONALLY", "ORDER", "OUT", "OUTER", "OUTFILE", "PRECISION",
  "PRIMARY", "PROCEDURE", "PURGE", "QUICK", "READ", "READS", "REAL",
  "REFERENCES", "RELEASE", "RENAME", "REPEAT", "REPLACE", "REQUIRE",
  "RESTRICT", "RETURN", "REVOKE", "RIGHT", "ROLLUP", "SCHEMA", "SCHEMAS",
  "SECOND_MICROSECOND", "SELECT", "SENSITIVE", "SEPARATOR", "SET", "SHOW",
  "SMALLINT", "SOME", "SONAME", "SPATIAL", "SPECIFIC", "SQLEXCEPTION",
  "SQLSTATE", "SQLWARNING", "SQL_BIG_RESULT", "SQL_CALC_FOUND_ROWS",
  "SQL_SMALL_RESULT", "SSL", "STARTING", "STRAIGHT_JOIN", "TABLE",
  "TEMPORARY", "TEST_SEL", "TEXT", "TERMINATED", "THEN", "TIME",
  "TIMESTAMP", "TINYBLOB", "TINYINT", "TINYTEXT", "TO", "TRAILING",
  "TRIGGER", "UNDO", "UNION", "UNIQUE", "UNLOCK", "UNSIGNED", "UPDATE",
  "USAGE", "USE", "USING", "UTC_DATE", "UTC_TIME", "UTC_TIMESTAMP",
  "VALUES", "VARBINARY", "VARCHAR", "VARYING", "WHEN", "WHERE", "WHILE",
  "WITH", "WRITE", "YEAR", "YEAR_MONTH", "ZEROFILL", "FSUBSTRING", "FTRIM",
  "FDATE_ADD", "FDATE_SUB", "FCOUNT", "FSUM", "';'", "'.'", "'('", "')'",
  "','", "$accept", "stmt_list", "stmt", "show_log_stmt",
  "import_file_stmt", "test_stmt", "insert_stmt", "opt_ondupupdate",
  "insert_opts", "opt_into", "opt_col_names", "insert_vals_list",
  "insert_vals", "insert_asgn_list", "create_index_stmt",
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

#define YYPACT_NINF -382

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-382)))

#define YYTABLE_NINF -194

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-194)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1229,  -154,   -61,  -144,  -382,    55,  -382,  -382,  -382,    63,
      27,  -382,     0,   509,  -139,  -382,  -382,  -382,  -382,  -382,
    -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,   100,  -145,
      30,    30,     9,  -382,   158,    41,   -57,   100,   100,   353,
     205,   -89,  -382,  -382,  -382,    82,    15,  -382,   -22,  -382,
    -382,  -382,  -382,  -382,  -382,   189,    30,   139,   230,   244,
      30,    30,   249,  -382,  -194,    25,   270,  -382,  -382,  -382,
     -93,   278,   281,   286,    32,  -382,  -382,  -382,  -382,   284,
     901,   901,   901,  -382,  -382,   901,   477,  -382,  -382,  -382,
    -382,  -382,    44,  -382,  -382,  -382,  -382,  -382,    50,    56,
      76,    95,   118,   123,   -83,  -382,  1567,   901,   901,    63,
      17,    18,    13,    14,  -158,    31,  -382,  -382,   342,  -382,
     128,   313,  -382,  -382,  -382,   385,   392,   148,   273,   439,
     419,  -382,    73,   -86,    15,   447,  -382,  -159,   -99,   203,
     901,   901,    74,   316,   316,  -382,  -382,   901,  1249,   -60,
     265,   901,   403,   901,   901,   541,   612,    15,   928,  -382,
     901,   901,   901,   209,    21,   901,   901,   304,   901,   257,
     901,   901,   901,   901,   901,   901,   901,   901,   901,   901,
     469,  -382,  1643,  1643,  -382,   473,   -76,   210,    77,   475,
      15,  -382,  -382,  -382,   -78,  -382,    15,   364,   335,  -382,
     507,   158,   285,   269,   271,    42,    34,   521,  -382,  -382,
     901,   363,    15,  -190,    25,   525,    16,   525,  -125,  -382,
    -382,   990,  -382,   274,  1643,   527,  1352,   -56,   901,  -382,
     901,   276,    62,   277,  -382,  -382,  -382,   280,   901,  1042,
    1073,   282,  1143,   283,  1170,  -190,  -382,  1663,  1015,  1292,
     639,  -382,    20,  -382,  1681,  1681,   279,   901,   901,  1616,
     296,   297,   298,   265,   933,  1179,   339,   462,   386,   386,
     510,   510,   510,   510,  -382,  -382,    67,   409,   423,   424,
    -382,  -382,  -382,   -14,  -189,    31,   335,   335,   432,   404,
      15,  -382,   434,  -382,    92,   310,    34,    34,   102,  -382,
     311,   438,  -382,   566,    34,    97,  -382,   569,  -382,   342,
     119,   319,  1643,   529,   441,  -190,  -382,  -382,   554,  -106,
     310,   310,   666,  -100,   420,  -106,   310,   420,   901,  -382,
     901,   901,  -382,  1490,  1421,  -382,   901,  -382,  -382,  1469,
     452,   452,  -382,  -382,  -382,  -382,   471,   326,   327,  -382,
    -382,   639,  1681,  1681,   901,   265,   265,   265,   328,   -76,
     482,   482,   482,   901,   583,   584,   363,  -382,  -382,    15,
     901,  -129,    15,  -382,  -100,   135,   138,   334,   338,   158,
     340,   -20,   142,  -382,    34,   -94,   265,  -382,   158,   901,
     901,  -382,  -382,   735,   459,   590,  -382,  -100,  -100,  -382,
     144,  1643,   341,  -382,  -382,  -382,  -100,  -382,  -382,  1643,
    1511,  -382,   901,  1115,   901,   901,   343,   354,   549,   487,
    -382,  -382,   355,   356,   745,   357,   358,   359,  -382,  -382,
     479,   367,   368,   370,  1643,   605,   -13,   441,  -382,  1643,
     901,   373,  -382,  -382,  -129,  -382,  -382,  -382,   158,   158,
     149,   158,    34,  -382,   -68,  -382,   374,   377,  -382,  -382,
     167,   378,  1532,  1094,  -382,  1643,   406,   615,  -382,  -382,
    -382,   800,   666,  -382,  -382,  1643,   901,  -382,   381,  1228,
    -382,  -382,   901,   901,   363,  -382,  -382,  -382,  -382,  -382,
    -382,   637,   637,   637,   901,   901,   638,  -382,  1643,   158,
    -382,   169,   171,  -382,   174,   180,  -382,   643,  -382,   653,
     157,  -382,   901,  -382,  -382,  -382,   901,   525,   831,  -382,
    1643,   185,  1200,  -382,  -382,  -382,  -382,  -382,  -382,  -382,
    -382,  -382,  -382,   -33,  1643,   441,  -382,   192,   204,   206,
    1643,  1643,   640,   215,  -382,  -382,  -382,   -51,   219,   -19,
     408,   503,  -382,   657,   238,  -382,  -382,   535,  -108,  1532,
    1643,   410,  -382,  1643,  -382,  -382,   483,  -382,   540,  -382,
     672,  -382,  -382,   901,  -382,  -382,  -382,   674,  -382,  -382,
    -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,   158,
    -382,  -382,   158,  -382,  -382,  1643,   425,   170,   241,   429,
    -382,   489,   682,  -382,   683,  -382,  -382
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    18,    91,     0,   178,     0,    18,    18,   118,     0,
       0,    10,    18,     0,     0,     4,     7,     9,    11,    39,
      42,    93,   173,   185,   189,   198,   203,    92,    24,     0,
     201,   201,     0,    41,     0,     0,     0,    24,    24,     0,
       0,   204,   205,     5,     6,     0,     0,     1,     0,     2,
      20,    21,    22,    23,    19,     0,   201,     0,     0,     0,
     201,   201,     0,   116,     0,   182,     0,   177,   175,   176,
       0,     0,     0,     0,   209,   212,   213,   215,   214,   210,
       0,     0,     0,   129,   119,     0,     0,   287,   288,   286,
     120,   121,     0,   122,   125,   126,   124,   123,     0,     0,
       0,     0,     0,     0,    94,   127,   144,     0,     0,     0,
      22,    19,   144,     0,     0,   132,   134,   135,   141,     3,
      25,     0,   202,   199,   200,     0,     0,     0,     0,     0,
       0,   180,    96,     0,     0,     0,     8,    25,    25,     0,
     245,     0,   209,   235,   236,   222,   289,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   208,   207,   206,     0,   167,     0,     0,     0,
       0,   152,   151,   155,   159,   156,     0,     0,   153,   140,
       0,     0,     0,     0,     0,    56,    56,     0,   117,   183,
       0,   109,     0,    96,   182,     0,     0,     0,     0,   211,
     131,   243,   246,     0,   237,     0,     0,     0,     0,   278,
       0,     0,   243,     0,   264,   262,   263,     0,     0,     0,
       0,     0,     0,     0,     0,    96,   128,   224,   225,   223,
       0,   240,     0,   238,   282,   284,     0,     0,     0,     0,
       0,     0,     0,     0,   226,   231,   232,   234,   216,   217,
     218,   219,   220,   221,   233,   142,   144,     0,     0,     0,
     136,   172,   139,     0,    96,   133,   153,   153,     0,   146,
       0,   154,     0,   138,     0,     0,    56,    56,     0,    89,
       0,     0,    90,     0,    56,     0,    54,     0,    46,   141,
       0,     0,    97,     0,   111,    96,   179,   181,     0,    16,
       0,     0,     0,    16,    16,    16,     0,    16,     0,   252,
       0,     0,   276,     0,     0,   251,     0,   257,   260,     0,
       0,     0,   253,   254,   255,   256,    98,     0,     0,   241,
     239,     0,   283,   285,     0,     0,     0,     0,     0,   167,
     169,   169,   169,     0,     0,     0,   109,   157,   158,     0,
       0,   161,     0,    26,    16,     0,     0,     0,     0,     0,
       0,    88,    49,    48,    56,     0,     0,    47,     0,     0,
       0,   174,   184,     0,     0,     0,    33,    16,    16,    30,
       0,    29,     0,    14,    34,   187,    16,   188,   244,   280,
       0,   279,     0,     0,     0,     0,     0,     0,     0,   107,
     249,   247,     0,     0,   242,     0,     0,     0,   227,   137,
       0,     0,     0,     0,   194,     0,     0,   111,   149,   147,
       0,     0,   145,   160,     0,    13,    50,    51,     0,     0,
       0,     0,    56,    53,    88,    55,    76,     0,    63,    87,
       0,   110,   102,   112,    36,    35,     0,     0,    15,    12,
      27,     0,     0,   186,   277,   281,     0,   258,     0,     0,
     265,   266,     0,     0,   109,   250,   248,   230,   228,   229,
     168,     0,     0,     0,     0,     0,     0,   190,   162,     0,
     148,     0,     0,    60,     0,     0,    45,     0,    79,     0,
      58,    40,     0,   103,   104,   100,     0,     0,     0,    32,
      31,     0,     0,   261,   267,   268,   269,   270,   273,   274,
     275,   272,   271,   105,   108,   111,   170,     0,     0,     0,
     195,   196,     0,     0,    61,    62,    59,    88,     0,    85,
       0,     0,    70,     0,     0,    74,    65,     0,     0,   102,
     113,    17,    38,    37,    28,   259,     0,    99,   114,   166,
       0,   165,   164,     0,   163,    52,    77,     0,    80,    81,
      82,    64,    75,    66,    67,    69,    68,    73,    72,     0,
     101,   106,     0,    95,   171,   197,     0,    86,     0,   115,
      78,     0,     0,    71,     0,    84,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -382,  -382,   677,  -382,  -382,  -382,  -382,    60,   302,   461,
     376,  -126,   220,  -215,  -382,  -382,  -197,   309,  -382,  -382,
    -382,  -382,  -382,  -382,  -357,  -382,   692,   -98,    -4,  -382,
     213,   137,  -382,  -382,  -341,  -381,  -382,  -200,  -382,  -382,
     539,   122,   516,  -186,   390,  -101,  -382,  -382,   229,  -382,
    -382,  -382,   256,   348,   156,    29,  -382,  -382,  -382,   642,
     497,  -382,  -382,  -382,  -382,  -382,   245,  -382,  -382,   603,
     -39,  -147,  -382,  -382,   372,   570
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    16,    17,    18,   396,    28,    55,
     202,   323,   400,   319,    19,    20,   305,   306,   307,   510,
     508,   549,   597,   458,   308,   309,    29,    21,   211,   419,
     461,   515,   567,   484,   314,   391,   593,    64,    39,   104,
     105,   114,   115,   116,   200,   181,   117,   197,   292,   198,
     288,   442,   443,   280,   431,   537,   118,    22,    35,    70,
     131,    23,    24,    46,   284,    25,    58,    26,    41,    42,
     221,   222,   223,   238,   416,   149
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     106,   294,   325,  -191,   233,   237,   363,   495,    30,   310,
     289,   186,    60,   134,    33,   187,   159,   112,   112,   320,
    -193,  -192,   588,   157,   453,   437,   349,   251,   277,   440,
      43,   456,   228,   215,   189,   229,   331,   -57,   252,   332,
     278,   143,   144,   145,    65,   -57,   146,   148,   299,   210,
     210,   180,   231,   394,   -91,    27,   497,   286,    36,   394,
      44,   128,   129,    56,     8,   299,   190,   365,   182,   183,
     159,    40,   160,   161,   162,   163,   164,   165,   166,   167,
     -88,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   217,   191,   201,   299,   506,   190,   375,
     376,   441,   224,   348,   371,   180,   287,   382,   226,   326,
      34,   302,   232,    49,   239,   240,   242,   244,   324,   106,
     327,   247,   248,   249,    57,    31,   254,   255,   302,   259,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   298,   457,   535,   212,    57,   589,    66,    27,   298,
     395,   192,   347,   279,   568,   201,   402,    67,   299,   302,
    -150,    63,    50,   135,   300,   358,   193,   109,   336,   374,
     135,   312,   300,   158,   551,   359,   350,   253,   230,   450,
      50,   408,   230,   438,   -43,   194,   444,    68,   460,   333,
     575,   334,   120,    51,   397,   398,    71,   552,   110,   339,
     406,   -44,   301,     8,   423,     8,   219,   578,   566,   316,
     301,    51,    69,   553,   107,   195,    52,    61,   352,   353,
     377,   302,   601,   512,   602,   108,   579,    53,   111,   220,
     119,   -88,   378,   123,   452,   188,   554,   122,   196,   364,
     496,   346,   583,   584,   585,   586,    54,   124,   501,   502,
     321,   504,   127,   422,  -191,   505,   213,   425,   426,   427,
     142,    75,    76,    77,    78,    79,   185,   478,   113,   113,
     322,  -193,  -192,   132,    80,    81,    59,    62,   130,   245,
     366,   136,    82,   401,   137,   139,   140,   555,   459,   138,
     260,   409,   410,   141,   261,   303,   304,   413,   150,   543,
      85,   121,   561,  -182,   151,   125,   126,    86,    37,    38,
     152,   392,   210,   556,    45,   424,   203,   256,   328,   257,
     258,    87,    88,    89,   434,   557,   130,   225,   140,  -182,
     153,   439,   282,   190,   315,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   373,   129,   154,
     462,   463,   383,   384,   465,    92,    74,    75,    76,    77,
      78,    79,   172,   173,   174,   175,   176,   177,   178,   179,
      80,    81,   155,   475,   387,   384,   479,   156,    82,    83,
     199,   558,   201,   403,   404,   405,    84,   407,   204,   598,
     446,   384,   599,   447,   384,   205,    85,   454,   384,   470,
     471,   498,   206,    86,   503,   129,   142,    75,    76,    77,
      78,    79,   175,   176,   177,   178,   179,    87,    88,    89,
      80,    81,   511,   129,   544,   129,   545,   129,    82,   546,
     129,   207,   520,   401,   445,   547,   384,   522,    90,    91,
     564,   471,   208,   462,   534,   209,    85,   569,   570,   234,
     214,    92,   262,    86,     8,   540,   541,   468,   469,   571,
     570,   572,   570,   250,    93,   281,   473,    87,    88,    89,
     574,   129,   275,   559,   576,   577,   276,   560,   283,   563,
     142,    75,    76,    77,    78,    79,   173,   174,   175,   176,
     177,   178,   179,   290,    80,    81,   603,   129,    72,    73,
     291,    92,    82,    98,    99,   100,   101,   102,   103,    47,
     293,   263,     1,   216,   218,   367,   368,   432,   433,   295,
      85,   538,   539,   296,   311,   297,   313,    86,   318,   329,
     219,   335,   337,   351,   595,   338,   235,   342,   344,   360,
     179,    87,    88,    89,   142,    75,    76,    77,    78,    79,
     355,   356,   357,   361,   362,    94,    95,    96,    80,    81,
      97,   369,   370,   372,   322,   379,    82,   241,   380,   381,
       2,     3,   385,   388,   393,    92,   389,   390,   415,   394,
     418,   420,   421,   428,    85,   430,   435,   436,   448,   466,
       4,    86,   449,   467,   451,   472,   482,   483,   480,    98,
      99,   100,   101,   102,   103,    87,    88,    89,   490,   481,
     485,   486,   487,   488,   489,   142,    75,    76,    77,    78,
      79,   491,   492,   236,   493,   494,     5,   499,   507,    80,
      81,   509,     6,   517,   512,   518,   523,    82,   243,    92,
     536,   542,   142,    75,    76,    77,    78,    79,   548,    98,
      99,   100,   101,   102,   103,    85,    80,    81,   550,   581,
     573,   582,    86,   580,    82,   587,   395,   592,   591,   142,
      75,    76,    77,    78,    79,   594,    87,    88,    89,   596,
     600,   604,    85,    80,    81,   129,   605,   606,     7,    86,
      48,    82,   521,   455,    32,   533,   590,   246,     8,   386,
     500,     9,    10,    87,    88,    89,   285,   429,   133,    85,
      92,   317,   184,   417,     0,   147,    86,     0,   227,    11,
       0,     0,     0,    98,    99,   100,   101,   102,   103,     0,
      87,    88,    89,     0,     0,     0,    12,    92,   142,    75,
      76,    77,    78,    79,     0,   399,     0,     0,     0,     0,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,    92,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,     0,     0,    85,     0,
       0,     0,     0,     0,     0,    86,     0,    98,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,    87,
      88,    89,     0,   142,    75,    76,    77,    78,    79,     0,
       0,     0,     0,     0,   464,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    82,     0,     0,     8,     0,
       0,     0,     0,    92,   142,    75,    76,    77,    78,    79,
       0,     0,     0,    85,     0,     0,     0,     0,    80,    81,
      86,     0,     0,     0,     0,     0,    82,     0,    98,    99,
     100,   101,   102,   103,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,    85,     0,     0,     0,     0,   519,
       0,    86,     0,     0,     0,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,    87,    88,    89,    92,     0,
       0,     0,     0,     0,   142,    75,    76,    77,    78,    79,
     562,     0,    98,    99,   100,   101,   102,   103,    80,    81,
       0,     0,     0,     0,     0,     0,    82,     0,     0,    92,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
       0,     0,     0,     0,    85,    80,    81,     0,     0,     0,
       0,    86,     0,    82,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,     0,    87,    88,    89,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,    86,     0,
       0,    98,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,    87,    88,    89,     0,     0,     0,     0,    92,
     160,   161,   162,   163,   164,   165,   166,   167,     0,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,     0,     0,     0,     0,     0,    92,   162,   163,   164,
     165,   166,   167,     0,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,    98,    99,   100,   101,
     102,   103,   160,   161,   162,   163,   164,   165,   166,   167,
       0,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   160,   161,   162,   163,   164,   165,   166,
     167,     0,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   160,   161,   162,   163,   164,   165,
     166,   167,     0,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   160,   161,   162,   163,   164,
     165,   166,   167,     0,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,     0,    98,    99,   100,
     101,   102,   103,   160,   161,   162,   163,   164,   165,   166,
     167,     0,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,    98,    99,   100,   101,   102,   103,
     160,   161,   162,   163,   164,   165,   166,   167,     0,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     160,   161,   162,   163,   164,   165,   166,   167,   476,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,     0,     1,     0,     0,     0,     0,     0,   160,   161,
     162,   163,   164,   165,   166,   167,   328,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   160,
     161,   162,   163,   164,   165,   166,   167,     0,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     0,     0,     0,     0,     0,   340,     0,
       0,   524,   525,   526,   527,   163,   164,   165,   166,   167,
       4,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,     0,     0,     0,     0,     0,     0,   341,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,   529,   530,     0,     0,     0,     5,     0,     0,     0,
     516,     0,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   160,   161,   162,   163,   164,   165,   166,   167,
     477,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   343,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       0,     9,    10,     0,     0,   345,     0,     0,     0,     0,
       0,   160,   161,   162,   163,   164,   165,   166,   167,    11,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     0,     0,     0,   565,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   531,   532,     0,     0,     0,     0,     0,     0,   160,
     161,   162,   163,   164,   165,   166,   167,   147,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     160,   161,   162,   163,   164,   165,   166,   167,     0,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   160,   161,   162,   163,   164,   165,   166,   167,     0,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   160,   161,   162,   163,   164,   165,   166,   167,
       0,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,     0,     0,   330,     0,     0,     0,     0,
     159,   513,     0,     0,     0,   414,     0,   160,   161,   162,
     163,   164,   165,   166,   167,   411,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,   180,   474,     0,     0,     0,
       0,     0,     0,     0,   514,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   160,   161,   162,   163,
     164,   165,   166,   167,   412,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,     0,     0,     0,
       0,     0,   354,   160,   161,   162,   163,   164,   165,   166,
     167,     0,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   161,   162,   163,   164,   165,   166,
     167,     0,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,  -194,  -194,  -194,  -194,   167,     0,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179
};

static const yytype_int16 yycheck[] =
{
      39,   201,   217,     3,   151,   152,    20,    20,    69,   206,
     196,   112,     3,   106,   158,   113,     3,     3,     3,     3,
       3,     3,   130,   106,   381,   366,     6,     6,   104,   158,
       3,   125,    92,   192,   192,    95,    92,     3,    17,    95,
     116,    80,    81,    82,     3,     3,    85,    86,   116,   239,
     239,    38,   150,   159,   208,   209,   437,   135,     3,   159,
      33,   255,   256,   208,   189,   116,   256,   256,   107,   108,
       3,     8,    10,    11,    12,    13,    14,    15,    16,    17,
      38,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   192,    63,   254,   116,   454,   256,   296,
     297,   230,   141,   250,   290,    38,   184,   304,   147,   234,
     254,   179,   151,   252,   153,   154,   155,   156,   216,   158,
     218,   160,   161,   162,   115,   186,   165,   166,   179,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   107,   236,   484,   230,   115,   254,   106,   209,   107,
     256,   120,   250,   229,   535,   254,   256,   116,   116,   179,
     129,     3,    80,   256,   130,   263,   135,   256,   106,   295,
     256,   210,   130,   256,    17,   276,   156,   156,   238,   379,
      80,   328,   238,   369,   252,   154,   372,   146,   388,   228,
     547,   230,     3,   111,   320,   321,   253,    40,   116,   238,
     326,   252,   168,   189,   351,   189,     3,   226,   241,   213,
     168,   111,   171,    56,     9,   184,   116,   208,   257,   258,
     118,   179,    52,   256,    54,    20,   245,   127,   146,    26,
     252,   189,   130,     3,   254,   113,    79,    98,   207,   253,
     253,   245,     4,     5,     6,     7,   146,     3,   448,   449,
     234,   451,     3,   351,   254,   452,   134,   355,   356,   357,
       3,     4,     5,     6,     7,     8,   253,   414,   254,   254,
     254,   254,   254,     3,    17,    18,    31,    32,   253,   157,
     284,     3,    25,   322,     3,   253,   254,   130,   386,     3,
      33,   330,   331,     9,    37,   253,   254,   336,   254,   499,
      43,    56,   517,   230,   254,    60,    61,    50,     6,     7,
     254,   315,   239,   156,    12,   354,     3,    13,   256,    15,
      16,    64,    65,    66,   363,   168,   253,   253,   254,   256,
     254,   370,   255,   256,   212,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,   255,   256,   254,
     389,   390,   255,   256,   393,    98,     3,     4,     5,     6,
       7,     8,    23,    24,    25,    26,    27,    28,    29,    30,
      17,    18,   254,   412,   255,   256,   415,   254,    25,    26,
      38,   224,   254,   323,   324,   325,    33,   327,     3,   589,
     255,   256,   592,   255,   256,     3,    43,   255,   256,   255,
     256,   440,   254,    50,   255,   256,     3,     4,     5,     6,
       7,     8,    26,    27,    28,    29,    30,    64,    65,    66,
      17,    18,   255,   256,   255,   256,   255,   256,    25,   255,
     256,   158,   471,   472,   374,   255,   256,   476,    85,    86,
     255,   256,     3,   482,   483,    26,    43,   255,   256,    46,
       3,    98,   195,    50,   189,   494,   495,   397,   398,   255,
     256,   255,   256,   254,   111,   255,   406,    64,    65,    66,
     255,   256,     3,   512,   255,   256,     3,   516,     3,   518,
       3,     4,     5,     6,     7,     8,    24,    25,    26,    27,
      28,    29,    30,   129,    17,    18,   255,   256,    37,    38,
     165,    98,    25,   246,   247,   248,   249,   250,   251,     0,
       3,   254,     3,   137,   138,   286,   287,   361,   362,   234,
      43,   492,   493,   254,     3,   254,   163,    50,     3,   255,
       3,   255,   255,   254,   573,   255,   133,   255,   255,   130,
      30,    64,    65,    66,     3,     4,     5,     6,     7,     8,
     254,   254,   254,   130,   130,   202,   203,   204,    17,    18,
     207,   129,   158,   129,   254,   254,    25,    26,   130,     3,
      61,    62,     3,   254,    20,    98,    47,   136,   126,   159,
     109,   255,   255,   255,    43,   103,     3,     3,   254,   130,
      81,    50,   254,     3,   254,   254,    47,   110,   255,   246,
     247,   248,   249,   250,   251,    64,    65,    66,   129,   255,
     255,   255,   255,   255,   255,     3,     4,     5,     6,     7,
       8,   254,   254,   220,   254,    20,   117,   254,   254,    17,
      18,   254,   123,   227,   256,    20,   255,    25,    26,    98,
       3,     3,     3,     4,     5,     6,     7,     8,     5,   246,
     247,   248,   249,   250,   251,    43,    17,    18,     5,   156,
      20,     4,    50,   255,    25,   130,   256,   127,   185,     3,
       4,     5,     6,     7,     8,     3,    64,    65,    66,     5,
     255,   192,    43,    17,    18,   256,     4,     4,   179,    50,
      13,    25,   472,   384,     2,   482,   559,   158,   189,   309,
     444,   192,   193,    64,    65,    66,   190,   359,    66,    43,
      98,   214,   109,   341,    -1,   238,    50,    -1,   148,   210,
      -1,    -1,    -1,   246,   247,   248,   249,   250,   251,    -1,
      64,    65,    66,    -1,    -1,    -1,   227,    98,     3,     4,
       5,     6,     7,     8,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    98,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,   246,   247,   248,
     249,   250,   251,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,   189,    -1,
      -1,    -1,    -1,    98,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    17,    18,
      50,    -1,    -1,    -1,    -1,    -1,    25,    -1,   246,   247,
     248,   249,   250,   251,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    79,
      -1,    50,    -1,    -1,    -1,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,    64,    65,    66,    98,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      79,    -1,   246,   247,   248,   249,   250,   251,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    98,
      -1,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    17,    18,    -1,    -1,    -1,
      -1,    50,    -1,    25,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    64,    65,    66,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      -1,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    98,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    98,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,   246,   247,   248,   249,
     250,   251,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,   250,   251,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,   246,   247,   248,
     249,   250,   251,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,   246,   247,   248,   249,   250,   251,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      10,    11,    12,    13,    14,    15,    16,    17,   103,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,     3,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,   256,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    73,    74,    75,    76,    13,    14,    15,    16,    17,
      81,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,   114,    -1,    -1,    -1,   117,    -1,    -1,    -1,
     256,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
     255,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,
      -1,   192,   193,    -1,    -1,   255,    -1,    -1,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,   210,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,   255,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,   238,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,   213,    -1,    -1,    -1,    -1,
       3,    39,    -1,    -1,    -1,   106,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    95,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,   213,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    36,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,    61,    62,    81,   117,   123,   179,   189,   192,
     193,   210,   227,   258,   259,   260,   261,   262,   263,   271,
     272,   284,   314,   318,   319,   322,   324,   209,   265,   283,
      69,   186,   283,   158,   254,   315,     3,   265,   265,   295,
       8,   325,   326,     3,    33,   265,   320,     0,   259,   252,
      80,   111,   116,   127,   146,   266,   208,   115,   323,   323,
       3,   208,   323,     3,   294,     3,   106,   116,   146,   171,
     316,   253,   266,   266,     3,     4,     5,     6,     7,     8,
      17,    18,    25,    26,    33,    43,    50,    64,    65,    66,
      85,    86,    98,   111,   202,   203,   204,   207,   246,   247,
     248,   249,   250,   251,   296,   297,   327,     9,    20,   256,
     116,   146,     3,   254,   298,   299,   300,   303,   313,   252,
       3,   323,    98,     3,     3,   323,   323,     3,   255,   256,
     253,   317,     3,   316,   106,   256,     3,     3,     3,   253,
     254,     9,     3,   327,   327,   327,   327,   238,   327,   332,
     254,   254,   254,   254,   254,   254,   254,   106,   256,     3,
      10,    11,    12,    13,    14,    15,    16,    17,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      38,   302,   327,   327,   326,   253,   302,   284,   298,   192,
     256,    63,   120,   135,   154,   184,   207,   304,   306,    38,
     301,   254,   267,     3,     3,     3,   254,   158,     3,    26,
     239,   285,   230,   298,     3,   192,   267,   192,   267,     3,
      26,   327,   328,   329,   327,   253,   327,   332,    92,    95,
     238,   284,   327,   328,    46,   133,   220,   328,   330,   327,
     327,    26,   327,    26,   327,   298,   297,   327,   327,   327,
     254,     6,    17,   156,   327,   327,    13,    15,    16,   327,
      33,    37,   195,   254,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,     3,     3,   104,   116,   229,
     310,   255,   255,     3,   321,   299,   135,   184,   307,   300,
     129,   165,   305,     3,   294,   234,   254,   254,   107,   116,
     130,   168,   179,   253,   254,   273,   274,   275,   281,   282,
     273,     3,   327,   163,   291,   298,   285,   317,     3,   270,
       3,   234,   254,   268,   284,   270,   234,   284,   256,   255,
     213,    92,    95,   327,   327,   255,   106,   255,   255,   327,
     256,   256,   255,   255,   255,   255,   285,   284,   328,     6,
     156,   254,   327,   327,    36,   254,   254,   254,   284,   302,
     130,   130,   130,    20,   253,   256,   285,   305,   305,   129,
     158,   300,   129,   255,   268,   273,   273,   118,   130,   254,
     130,     3,   273,   255,   256,     3,   301,   255,   254,    47,
     136,   292,   285,    20,   159,   256,   264,   268,   268,    79,
     269,   327,   256,   264,   264,   264,   268,   264,   328,   327,
     327,    95,   213,   327,   106,   126,   331,   331,   109,   286,
     255,   255,   284,   328,   327,   284,   284,   284,   255,   310,
     103,   311,   311,   311,   327,     3,     3,   291,   300,   327,
     158,   230,   308,   309,   300,   264,   255,   255,   254,   254,
     294,   254,   254,   281,   255,   274,   125,   236,   280,   284,
     294,   287,   327,   327,    79,   327,   130,     3,   264,   264,
     255,   256,   254,   264,    95,   327,   103,   255,   328,   327,
     255,   255,    47,   110,   290,   255,   255,   255,   255,   255,
     129,   254,   254,   254,    20,    20,   253,   292,   327,   254,
     309,   294,   294,   255,   294,   273,   281,   254,   277,   254,
     276,   255,   256,    39,    82,   288,   256,   227,    20,    79,
     327,   269,   327,   255,    73,    74,    75,    76,   112,   113,
     114,   243,   244,   287,   327,   291,     3,   312,   312,   312,
     327,   327,     3,   294,   255,   255,   255,   255,     5,   278,
       5,    17,    40,    56,    79,   130,   156,   168,   224,   327,
     327,   270,    79,   327,   255,   255,   241,   289,   292,   255,
     256,   255,   255,    20,   255,   281,   255,   256,   226,   245,
     255,   156,     4,     4,     5,     6,     7,   130,   130,   254,
     288,   185,   127,   293,     3,   327,     5,   279,   294,   294,
     255,    52,    54,   255,   192,     4,     4
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   257,   258,   258,   259,   260,   260,   259,   261,   259,
     262,   259,   263,   263,   263,   263,   264,   264,   265,   265,
     265,   265,   265,   266,   266,   267,   267,   268,   268,   269,
     269,   269,   269,   263,   263,   270,   270,   270,   270,   259,
     271,   271,   259,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   273,   273,   274,   275,   274,   274,
     274,   274,   274,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   277,   277,   277,   278,
     278,   278,   279,   279,   279,   280,   280,   281,   282,   282,
     282,   283,   283,   259,   284,   284,   285,   285,   286,   286,
     287,   287,   288,   288,   288,   289,   289,   290,   290,   291,
     291,   292,   292,   292,   293,   293,   294,   294,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   296,   296,   296,
     297,   297,   298,   298,   299,   299,   300,   300,   300,   300,
     301,   301,   302,   302,   302,   303,   303,   303,   303,   303,
     304,   304,   304,   305,   305,   306,   306,   307,   307,   307,
     308,   308,   309,   309,   310,   310,   310,   310,   311,   311,
     312,   312,   313,   259,   314,   315,   315,   315,   315,   314,
     316,   316,   317,   317,   314,   259,   318,   318,   318,   259,
     319,   320,   320,   320,   321,   321,   321,   321,   259,   322,
     322,   323,   323,   259,   324,   325,   325,   326,   326,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   328,   328,   329,   329,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   330,   330,   330,   327,   327,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   327,   327,   327,   327,
     332,   332,   327,   327,   327,   327,   327,   327,   327,   327
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     1,     2,     2,     1,     4,     1,
       1,     1,     8,     8,     7,     8,     0,     4,     0,     2,
       2,     2,     2,     1,     0,     0,     3,     3,     5,     1,
       1,     3,     3,     7,     7,     3,     3,     5,     5,     1,
       9,     2,     1,     8,    10,     9,     6,     7,     7,     7,
       8,     8,    11,     8,     1,     3,     0,     0,     4,     5,
       4,     5,     5,     0,     3,     2,     3,     3,     3,     3,
       2,     5,     3,     3,     2,     3,     0,     3,     5,     0,
       2,     2,     0,     4,     3,     3,     5,     3,     0,     1,
       1,     0,     1,     1,     3,    11,     0,     2,     0,     4,
       2,     4,     0,     1,     1,     0,     2,     0,     2,     0,
       3,     0,     2,     4,     0,     2,     1,     3,     0,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     3,     1,
       2,     3,     1,     3,     1,     1,     3,     5,     3,     3,
       1,     0,     2,     1,     0,     5,     3,     5,     6,     5,
       0,     1,     1,     0,     1,     1,     1,     2,     2,     0,
       1,     0,     2,     4,     6,     6,     6,     0,     2,     0,
       1,     3,     3,     1,     7,     2,     2,     2,     0,     6,
       2,     4,     0,     2,     7,     1,     8,     7,     7,     1,
       8,     0,     2,     2,     3,     5,     5,     7,     1,     4,
       4,     0,     2,     1,     2,     1,     3,     3,     3,     1,
       1,     3,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     5,     6,     6,
       6,     3,     3,     3,     3,     2,     2,     3,     3,     4,
       3,     4,     5,     1,     3,     0,     1,     5,     6,     5,
       6,     4,     4,     4,     4,     4,     4,     4,     6,     8,
       4,     7,     1,     1,     1,     6,     6,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     6,     3,     5,
       4,     5,     3,     4,     3,     4,     1,     1,     1,     2
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
#line 329 "pmysql.y" /* yacc.c:1646  */
    { sql_stmt_handle((yyvsp[-1].stmt_node));}
#line 2187 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 330 "pmysql.y" /* yacc.c:1646  */
    {sql_stmt_handle((yyvsp[-1].stmt_node));}
#line 2193 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 333 "pmysql.y" /* yacc.c:1646  */
    {(yyval.stmt_node)=(yyvsp[0].stmt_node);}
#line 2199 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 335 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_show_table_content((yyvsp[0].strval)); free((yyvsp[0].strval));}
#line 2205 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 336 "pmysql.y" /* yacc.c:1646  */
    {(yyval.stmt_node) = sql_show_all_table();}
#line 2211 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 338 "pmysql.y" /* yacc.c:1646  */
    {(yyval.stmt_node)=(yyvsp[0].stmt_node);}
#line 2217 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 340 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node)= sql_import_file((yyvsp[-2].strval),(yyvsp[0].strval)); show_log("import\n");free((yyvsp[-2].strval));}
#line 2223 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 344 "pmysql.y" /* yacc.c:1646  */
    {(yyval.stmt_node)=(yyvsp[0].stmt_node);}
#line 2229 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 346 "pmysql.y" /* yacc.c:1646  */
    {select_stmt_t *test=sql_test_select();(yyval.stmt_node)=sql_sel_stmt_hdl(test);}
#line 2235 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 349 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].stmt_node) ;}
#line 2241 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 355 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_insert_stmt_create((yyvsp[-4].strval), (yyvsp[-3].col_node), (yyvsp[-1].insr_node));show_log("INSERTVALS %d %d %s", (yyvsp[-6].intval), (yyvsp[-1].insr_node), (yyvsp[-4].strval)); }
#line 2247 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 361 "pmysql.y" /* yacc.c:1646  */
    { printf(" %s should be INSERT\n",(yyvsp[-7].strval));(yyval.stmt_node)=NULL; free((yyvsp[-4].strval)); }
#line 2253 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 366 "pmysql.y" /* yacc.c:1646  */
    { printf(" \"VALUES\" is missing\n");(yyval.stmt_node)=NULL; free((yyvsp[-3].strval)); }
#line 2259 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 371 "pmysql.y" /* yacc.c:1646  */
    { printf(" \"%s\" should be VALUES\n", (yyvsp[-2].strval));(yyval.stmt_node)=NULL; free((yyvsp[-4].strval));free((yyvsp[-2].strval)); }
#line 2265 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 374 "pmysql.y" /* yacc.c:1646  */
    { show_log("DUPUPDATE %d", (yyvsp[0].intval)); }
#line 2271 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 377 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2277 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 378 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 01 ; }
#line 2283 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 379 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 02 ; }
#line 2289 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 380 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 04 ; }
#line 2295 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 381 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 010 ; }
#line 2301 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 387 "pmysql.y" /* yacc.c:1646  */
    { (yyval.col_node) = NULL ;}
#line 2307 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 388 "pmysql.y" /* yacc.c:1646  */
    { (yyval.col_node) = (yyvsp[-1].col_node); sql_print_col_node((yyvsp[-1].col_node));show_log("INSERTCOLS %d", (yyvsp[-1].col_node)); }
#line 2313 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 391 "pmysql.y" /* yacc.c:1646  */
    { (yyval.insr_node) = (yyvsp[-1].insr_node); }
#line 2319 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 392 "pmysql.y" /* yacc.c:1646  */
    { show_log("VALUES %d", (yyvsp[-1].insr_node)); (yyval.insr_node) = (yyvsp[-4].insr_node) + 1; }
#line 2325 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 395 "pmysql.y" /* yacc.c:1646  */
    { (yyval.insr_node) = sql_insert_vals_node_create((yyvsp[0].expr_node), NULL, true); }
#line 2331 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 396 "pmysql.y" /* yacc.c:1646  */
    { show_log("DEFAULT"); (yyval.insr_node) = NULL; }
#line 2337 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 397 "pmysql.y" /* yacc.c:1646  */
    { (yyval.insr_node) = sql_insert_vals_node_create((yyvsp[0].expr_node), (yyvsp[-2].insr_node), false); }
#line 2343 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 398 "pmysql.y" /* yacc.c:1646  */
    { show_log("DEFAULT"); (yyval.insr_node) = NULL; }
#line 2349 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 404 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSERTASGN %d %d %s", (yyvsp[-5].intval), (yyvsp[-1].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 2355 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 409 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSERTSELECT %d %s", (yyvsp[-5].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 2361 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 414 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
       show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 2368 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 417 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
                 show_log("DEFAULT"); show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 2375 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 420 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-4].intval));
                 show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 2382 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 423 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-4].intval));
                 show_log("DEFAULT"); show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 2389 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 429 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].stmt_node);show_log("STMT"); }
#line 2395 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 433 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_cret_index_stmt_create((yyvsp[-3].strval), (yyvsp[-6].col_node), (yyvsp[-1].col_node)); printf("create index\n");}
#line 2401 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 434 "pmysql.y" /* yacc.c:1646  */
    {show_log("create index2\n");}
#line 2407 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 437 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].stmt_node);show_log("STMT"); }
#line 2413 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 442 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_cret_table_stmt_create((yyvsp[-3].strval), (yyvsp[-1].attr_node)); if ((yyval.stmt_node)==NULL) sql_free_attr_header_list((yyvsp[-1].attr_node)); show_log("CREATE %d %d %s", (yyvsp[-6].intval), (yyvsp[-4].intval), (yyvsp[-3].strval)); }
#line 2419 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 446 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATE %d %d %s.%s", (yyvsp[-8].intval), (yyvsp[-6].intval), (yyvsp[-5].strval), (yyvsp[-3].strval));
                          free((yyvsp[-5].strval)); free((yyvsp[-3].strval)); }
#line 2426 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 452 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d %s", (yyvsp[-7].intval), (yyvsp[-5].intval),(yyvsp[-4].strval)); free((yyvsp[-4].strval)); }
#line 2432 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 456 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d 0 %s", (yyvsp[-4].intval), (yyvsp[-2].intval), (yyvsp[-1].strval)); free((yyvsp[-1].strval)); }
#line 2438 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 460 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"Table\"is missing\n ");(yyval.stmt_node)=NULL;if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-3].strval));}
#line 2444 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 461 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"(\"is missing\n ");(yyval.stmt_node)=NULL;if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-2].strval));}
#line 2450 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 462 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\")\"is missing \n");(yyval.stmt_node)=NULL;if ((yyvsp[0].attr_node)) sql_free_attr_header_list((yyvsp[0].attr_node));free((yyvsp[-2].strval));}
#line 2456 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 463 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"%s\" should be CREATE\n ", (yyvsp[-7].strval));(yyval.stmt_node)=NULL;if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-7].strval));free((yyvsp[-3].strval));}
#line 2462 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 464 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"%s\" should be TABLE\n ", (yyvsp[-5].strval));(yyval.stmt_node)=NULL; if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-5].strval));free((yyvsp[-3].strval));}
#line 2468 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 468 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d 0 %s.%s", (yyvsp[-9].intval), (yyvsp[-7].intval), (yyvsp[-6].strval), (yyvsp[-4].strval));
                              free((yyvsp[-6].strval)); free((yyvsp[-4].strval)); }
#line 2475 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 473 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d 0 %s.%s", (yyvsp[-6].intval), (yyvsp[-4].intval), (yyvsp[-3].strval), (yyvsp[-1].strval));
                          free((yyvsp[-3].strval)); free((yyvsp[-1].strval)); }
#line 2482 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 477 "pmysql.y" /* yacc.c:1646  */
    {(yyval.attr_node)=sql_cret_def_handle(NULL, (yyvsp[0].cret_node)); sql_printf_attr((yyvsp[0].cret_node)->cret_def_info); }
#line 2488 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 478 "pmysql.y" /* yacc.c:1646  */
    { sql_recursive_printf_node((yyvsp[-2].attr_node)); (yyval.attr_node) = sql_cret_def_handle((yyvsp[-2].attr_node), (yyvsp[0].cret_node)); sql_printf_attr((yyval.attr_node));}
#line 2494 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 481 "pmysql.y" /* yacc.c:1646  */
    {printf("NULL column\n");}
#line 2500 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 482 "pmysql.y" /* yacc.c:1646  */
    {}
#line 2506 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 483 "pmysql.y" /* yacc.c:1646  */
    { (yyval.cret_node) = sql_cret_def_attr_declar_node_create((yyvsp[-2].strval), (yyvsp[-1].intval), (yyvsp[0].intval));/*show_log("COLUMNDEF %d %s", $3, $2); */ }
#line 2512 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 485 "pmysql.y" /* yacc.c:1646  */
    { (yyval.cret_node) = sql_cret_def_pk_def_node_create((yyvsp[-1].col_node)); show_log("PRIKEY %d", (yyvsp[-1].col_node)); }
#line 2518 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 486 "pmysql.y" /* yacc.c:1646  */
    { show_log("KEY %d", (yyvsp[-1].col_node)); }
#line 2524 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 487 "pmysql.y" /* yacc.c:1646  */
    { show_log("TEXTINDEX %d", (yyvsp[-1].col_node)); }
#line 2530 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 488 "pmysql.y" /* yacc.c:1646  */
    { show_log("TEXTINDEX %d", (yyvsp[-1].col_node)); }
#line 2536 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 491 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (1<<COL_ATTR_VALID); }
#line 2542 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 492 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR NOTNULL"); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2548 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 494 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT STRING %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2554 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 495 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT NUMBER %d", (yyvsp[0].intval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2560 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 496 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT FLOAT %g", (yyvsp[0].floatval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2566 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 497 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT BOOL %d", (yyvsp[0].intval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2572 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 498 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR AUTOINC"); (yyval.intval) = (yyvsp[-1].intval) + 1; }
#line 2578 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 499 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR UNIQUEKEY %d", (yyvsp[-1].col_node)); (yyval.intval) = 1<<((yyvsp[-4].intval) + 1); }
#line 2584 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 500 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR UNIQUEKEY"); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2590 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 501 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR PRIKEY"); (yyval.intval) = 1<<COL_ATTR_PRIKEY; }
#line 2596 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 502 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR PRIKEY"); (yyval.intval) = 1<<COL_ATTR_PRIKEY; }
#line 2602 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 503 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR COMMENT %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2608 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 506 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2614 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 507 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval); }
#line 2620 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 508 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-3].intval) + 1000*(yyvsp[-1].intval); }
#line 2626 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 515 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2632 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 516 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 1000; }
#line 2638 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 517 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 2000; }
#line 2644 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 521 "pmysql.y" /* yacc.c:1646  */
    { show_log("COLCHARSET %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2650 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 522 "pmysql.y" /* yacc.c:1646  */
    { show_log("COLCOLLATE %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2656 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 526 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = DATA_TYPE_INT;}
#line 2662 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 527 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = DATA_TYPE_VARCHAR + (yyvsp[-2].intval);}
#line 2668 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 564 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d", (yyvsp[-2].intval)); }
#line 2674 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 567 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2680 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 568 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2686 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 569 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2; }
#line 2692 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 572 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2698 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 573 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1;}
#line 2704 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 581 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].stmt_node); show_log("STMT"); }
#line 2710 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 585 "pmysql.y" /* yacc.c:1646  */
    { show_log("SELECTNODATA %d %d", (yyvsp[-1].intval), (yyvsp[0].select_col_node)); }
#line 2716 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 589 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_select_stmt_create(STMT_TYPE_SELECT_TUPLE, (yyvsp[-8].select_col_node), (yyvsp[-6].select_table_node), (yyvsp[-5].expr_node)); show_log("SELECT %d %d %d", (yyvsp[-9].intval), (yyvsp[-8].select_col_node), (yyvsp[-6].select_table_node)); }
#line 2722 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 592 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = NULL;}
#line 2728 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 593 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[0].expr_node); show_log("WHERE"); }
#line 2734 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 597 "pmysql.y" /* yacc.c:1646  */
    { show_log("GROUPBYLIST %d %d", (yyvsp[-1].intval), (yyvsp[0].intval)); }
#line 2740 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 601 "pmysql.y" /* yacc.c:1646  */
    { show_log("GROUPBY %d",  (yyvsp[0].intval)); (yyval.intval) = 1; }
#line 2746 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 603 "pmysql.y" /* yacc.c:1646  */
    { show_log("GROUPBY %d",  (yyvsp[0].intval)); (yyval.intval) = (yyvsp[-3].intval) + 1; }
#line 2752 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 606 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2758 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 607 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2764 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 608 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2770 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 611 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2776 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 612 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2782 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 615 "pmysql.y" /* yacc.c:1646  */
    { show_log("HAVING"); }
#line 2788 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 617 "pmysql.y" /* yacc.c:1646  */
    { show_log("ORDERBY %d", (yyvsp[0].intval)); }
#line 2794 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 620 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIMIT 1"); }
#line 2800 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 621 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIMIT 2"); }
#line 2806 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 625 "pmysql.y" /* yacc.c:1646  */
    { show_log("INTO %d", (yyvsp[0].col_node)); }
#line 2812 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 628 "pmysql.y" /* yacc.c:1646  */
    { show_log("COLUMN %s", (yyvsp[0].strval)); (yyval.col_node) = sql_col_list_node_create((yyvsp[0].strval), NULL, true); }
#line 2818 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 629 "pmysql.y" /* yacc.c:1646  */
    { (yyval.col_node) = sql_col_list_node_create((yyvsp[0].strval), (yyvsp[-2].col_node), false);show_log("COLUMN %s", (yyvsp[0].strval));}
#line 2824 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 632 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2830 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 633 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 01) yyerror("duplicate ALL option"); (yyval.intval) = (yyvsp[-1].intval) | 01; }
#line 2836 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 634 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 02) yyerror("duplicate DISTINCT option"); (yyval.intval) = (yyvsp[-1].intval) | 02; }
#line 2842 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 635 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 04) yyerror("duplicate DISTINCTROW option"); (yyval.intval) = (yyvsp[-1].intval) | 04; }
#line 2848 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 636 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 010) yyerror("duplicate HIGH_PRIORITY option"); (yyval.intval) = (yyvsp[-1].intval) | 010; }
#line 2854 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 637 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 020) yyerror("duplicate STRAIGHT_JOIN option"); (yyval.intval) = (yyvsp[-1].intval) | 020; }
#line 2860 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 638 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 040) yyerror("duplicate SQL_SMALL_RESULT option"); (yyval.intval) = (yyvsp[-1].intval) | 040; }
#line 2866 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 639 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 0100) yyerror("duplicate SQL_BIG_RESULT option"); (yyval.intval) = (yyvsp[-1].intval) | 0100; }
#line 2872 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 640 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 0200) yyerror("duplicate SQL_CALC_FOUND_ROWS option"); (yyval.intval) = (yyvsp[-1].intval) | 0200; }
#line 2878 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 643 "pmysql.y" /* yacc.c:1646  */
    { (yyval.select_col_node) = sql_select_col_list_create((yyvsp[0].select_col_node), NULL, true, false); }
#line 2884 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 644 "pmysql.y" /* yacc.c:1646  */
    {(yyval.select_col_node) = sql_select_col_list_create((yyvsp[0].select_col_node), (yyvsp[-2].select_col_node), false, false); }
#line 2890 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 645 "pmysql.y" /* yacc.c:1646  */
    { show_log("SELECTALL"); (yyval.select_col_node) = sql_select_col_list_create(NULL, NULL, true, true); }
#line 2896 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 648 "pmysql.y" /* yacc.c:1646  */
    { (yyval.select_col_node) = sql_select_col_node_create((yyvsp[-1].expr_node), (yyvsp[0].alias_name), false); }
#line 2902 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 649 "pmysql.y" /* yacc.c:1646  */
    { (yyval.select_col_node) = sql_select_col_node_create(NULL, (yyvsp[-2].strval), true); show_log("NAME.*\n"); }
#line 2908 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 652 "pmysql.y" /* yacc.c:1646  */
    { (yyval.select_table_node) = sql_select_table_list_create((yyvsp[0].select_table_node), NULL, true); }
#line 2914 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 653 "pmysql.y" /* yacc.c:1646  */
    {  (yyval.select_table_node) = sql_select_table_list_create((yyvsp[0].select_table_node), (yyvsp[-2].select_table_node), false); }
#line 2920 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 661 "pmysql.y" /* yacc.c:1646  */
    {(yyval.select_table_node) = sql_select_table_node_create((yyvsp[-2].strval), NULL, (yyvsp[-1].alias_name)); show_log("TABLE %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 2926 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 662 "pmysql.y" /* yacc.c:1646  */
    {(yyval.select_table_node) = sql_select_table_node_create((yyvsp[-2].strval), (yyvsp[-4].strval), (yyvsp[-1].alias_name)); show_log("TABLE %s.%s", (yyvsp[-4].strval), (yyvsp[-2].strval));
                               free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); }
#line 2933 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 664 "pmysql.y" /* yacc.c:1646  */
    { show_log("SUBQUERYAS %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2939 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 665 "pmysql.y" /* yacc.c:1646  */
    { show_log("TABLEREFERENCES %d", (yyvsp[-1].select_table_node)); }
#line 2945 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 672 "pmysql.y" /* yacc.c:1646  */
    { (yyval.alias_name) = strdup((yyvsp[0].strval)); show_log ("ALIAS %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2951 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 673 "pmysql.y" /* yacc.c:1646  */
    { (yyval.alias_name) = strdup((yyvsp[0].strval)); show_log ("ALIAS %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2957 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 674 "pmysql.y" /* yacc.c:1646  */
    { (yyval.alias_name) = NULL; }
#line 2963 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 679 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0100+(yyvsp[-3].intval)); }
#line 2969 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 681 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0200); }
#line 2975 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 683 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0200); }
#line 2981 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 685 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0300+(yyvsp[-4].intval)+(yyvsp[-3].intval)); }
#line 2987 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 687 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0400+(yyvsp[-2].intval)); }
#line 2993 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 690 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2999 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 691 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3005 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 692 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2; }
#line 3011 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 695 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3017 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 696 "pmysql.y" /* yacc.c:1646  */
    {(yyval.intval) = 4; }
#line 3023 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 699 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3029 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 700 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2; }
#line 3035 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 703 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1 + (yyvsp[0].intval); }
#line 3041 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 704 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2 + (yyvsp[0].intval); }
#line 3047 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 705 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3053 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 711 "pmysql.y" /* yacc.c:1646  */
    { show_log("ONEXPR"); }
#line 3059 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 712 "pmysql.y" /* yacc.c:1646  */
    { show_log("USING %d", (yyvsp[-1].col_node)); }
#line 3065 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 717 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEXHINT %d %d", (yyvsp[-1].intval), 010+(yyvsp[-3].intval)); }
#line 3071 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 719 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEXHINT %d %d", (yyvsp[-1].intval), 020+(yyvsp[-3].intval)); }
#line 3077 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 721 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEXHINT %d %d", (yyvsp[-1].intval), 030+(yyvsp[-3].intval)); }
#line 3083 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 725 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3089 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 726 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3095 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 729 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEX %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1; }
#line 3101 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 730 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEX %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3107 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 733 "pmysql.y" /* yacc.c:1646  */
    { show_log("SUBQUERY"); }
#line 3113 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 738 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3119 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 743 "pmysql.y" /* yacc.c:1646  */
    { show_log("DELETEONE %d %s", (yyvsp[-5].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3125 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 746 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) + 01; }
#line 3131 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 747 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) + 02; }
#line 3137 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 748 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) + 04; }
#line 3143 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 749 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3149 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 755 "pmysql.y" /* yacc.c:1646  */
    { show_log("DELETEMULTI %d %d %d", (yyvsp[-4].intval), (yyvsp[-3].intval), (yyvsp[-1].select_table_node)); }
#line 3155 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 757 "pmysql.y" /* yacc.c:1646  */
    { show_log("TABLE %s", (yyvsp[-1].strval)); free((yyvsp[-1].strval)); (yyval.intval) = 1; }
#line 3161 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 759 "pmysql.y" /* yacc.c:1646  */
    { show_log("TABLE %s", (yyvsp[-1].strval)); free((yyvsp[-1].strval)); (yyval.intval) = (yyvsp[-3].intval) + 1; }
#line 3167 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 767 "pmysql.y" /* yacc.c:1646  */
    { show_log("DELETEMULTI %d %d %d", (yyvsp[-5].intval), (yyvsp[-3].intval), (yyvsp[-1].select_table_node)); }
#line 3173 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 770 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3179 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 776 "pmysql.y" /* yacc.c:1646  */
    { show_log("REPLACEVALS %d %d %s", (yyvsp[-6].intval), (yyvsp[-1].insr_node), (yyvsp[-4].strval)); free((yyvsp[-4].strval)); }
#line 3185 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 782 "pmysql.y" /* yacc.c:1646  */
    { show_log("REPLACEASGN %d %d %s", (yyvsp[-5].intval), (yyvsp[-1].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3191 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 787 "pmysql.y" /* yacc.c:1646  */
    { show_log("REPLACESELECT %d %s", (yyvsp[-5].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3197 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 791 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3203 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 798 "pmysql.y" /* yacc.c:1646  */
    { show_log("UPDATE %d %d %d", (yyvsp[-6].intval), (yyvsp[-5].select_table_node), (yyvsp[-3].intval)); }
#line 3209 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 801 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3215 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 802 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 01 ; }
#line 3221 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 803 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 010 ; }
#line 3227 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 808 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
	 show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 3234 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 811 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-4].strval));
	 show_log("ASSIGN %s.%s", (yyvsp[-4].strval), (yyvsp[-2].strval)); free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 3241 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 814 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
	 show_log("ASSIGN %s.%s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 3248 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 817 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s.$s", (yyvsp[-4].strval), (yyvsp[-2].strval));
	 show_log("ASSIGN %s.%s", (yyvsp[-4].strval), (yyvsp[-2].strval)); free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 3255 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 824 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3261 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 828 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATEDATABASE %d %s", (yyvsp[-1].intval), (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3267 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 829 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATEDATABASE %d %s", (yyvsp[-1].intval), (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3273 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 832 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3279 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 833 "pmysql.y" /* yacc.c:1646  */
    { if(!(yyvsp[0].subtok))yyerror("IF EXISTS doesn't exist");
                        (yyval.intval) = (yyvsp[0].subtok); /* NOT EXISTS hack */ }
#line 3286 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 838 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3292 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 846 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad set to @%s", (yyvsp[-2].strval));
		 show_log("SET %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3299 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 848 "pmysql.y" /* yacc.c:1646  */
    { show_log("SET %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3305 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 853 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_NAME, 0, (yyvsp[0].strval), NULL);show_log("NAME %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3311 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 854 "pmysql.y" /* yacc.c:1646  */
    { show_log("USERVAR %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3317 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 855 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_PREFIX, 0, (yyvsp[0].strval), (yyvsp[-2].strval));show_log("FIELDNAME %s.%s", (yyvsp[-2].strval), (yyvsp[0].strval)); free((yyvsp[-2].strval)); free((yyvsp[0].strval)); }
#line 3323 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 856 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_VARCHAR, 0, (yyvsp[0].strval), NULL); show_log("STRING %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3329 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 857 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_INT, (yyvsp[0].intval), NULL, NULL); show_log("NUMBER %d", (yyvsp[0].intval)); }
#line 3335 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 858 "pmysql.y" /* yacc.c:1646  */
    { show_log("FLOAT %g", (yyvsp[0].floatval)); }
#line 3341 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 859 "pmysql.y" /* yacc.c:1646  */
    { show_log("BOOL %d", (yyvsp[0].intval)); }
#line 3347 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 862 "pmysql.y" /* yacc.c:1646  */
    { show_log("ADD"); }
#line 3353 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 863 "pmysql.y" /* yacc.c:1646  */
    { show_log("SUB"); }
#line 3359 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 864 "pmysql.y" /* yacc.c:1646  */
    { show_log("MUL"); }
#line 3365 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 865 "pmysql.y" /* yacc.c:1646  */
    { show_log("DIV"); }
#line 3371 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 866 "pmysql.y" /* yacc.c:1646  */
    { show_log("MOD"); }
#line 3377 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 867 "pmysql.y" /* yacc.c:1646  */
    { show_log("MOD"); }
#line 3383 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 868 "pmysql.y" /* yacc.c:1646  */
    { show_log("NEG"); }
#line 3389 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 869 "pmysql.y" /* yacc.c:1646  */
    {(yyval.expr_node) = sql_expr_logic_node_create(LGC_TYPE_AND, (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); show_log("AND"); }
#line 3395 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 870 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_logic_node_create(LGC_TYPE_OR, (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); show_log("OR"); }
#line 3401 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 871 "pmysql.y" /* yacc.c:1646  */
    { show_log("XOR"); }
#line 3407 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 872 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_comparison_node_create((yyvsp[-1].subtok), (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); show_log("CMP %d", (yyvsp[-1].subtok)); }
#line 3413 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 873 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPSELECT %d", (yyvsp[-3].subtok)); }
#line 3419 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 874 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPANYSELECT %d", (yyvsp[-4].subtok)); }
#line 3425 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 875 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPANYSELECT %d", (yyvsp[-4].subtok)); }
#line 3431 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 876 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPALLSELECT %d", (yyvsp[-4].subtok)); }
#line 3437 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 877 "pmysql.y" /* yacc.c:1646  */
    { show_log("BITOR"); }
#line 3443 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 878 "pmysql.y" /* yacc.c:1646  */
    { show_log("BITAND"); }
#line 3449 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 879 "pmysql.y" /* yacc.c:1646  */
    { show_log("BITXOR"); }
#line 3455 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 880 "pmysql.y" /* yacc.c:1646  */
    { show_log("SHIFT %s", (yyvsp[-1].subtok)==1?"left":"right"); }
#line 3461 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 881 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOT"); }
#line 3467 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 882 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOT"); }
#line 3473 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 883 "pmysql.y" /* yacc.c:1646  */
    { show_log("ASSIGN @%s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3479 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 886 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISNULL"); }
#line 3485 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 887 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISNULL"); show_log("NOT"); }
#line 3491 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 888 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISBOOL %d", (yyvsp[0].intval)); }
#line 3497 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 889 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISBOOL %d", (yyvsp[0].intval)); show_log("NOT"); }
#line 3503 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 892 "pmysql.y" /* yacc.c:1646  */
    { show_log("BETWEEN"); }
#line 3509 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 896 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3515 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 897 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1 + (yyvsp[0].intval); }
#line 3521 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 900 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3527 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 904 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISIN %d", (yyvsp[-1].intval)); }
#line 3533 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 905 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISIN %d", (yyvsp[-1].intval)); show_log("NOT"); }
#line 3539 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 906 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSELECT"); }
#line 3545 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 907 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSELECT"); show_log("NOT"); }
#line 3551 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 908 "pmysql.y" /* yacc.c:1646  */
    { show_log("EXISTS"); if((yyvsp[-3].subtok))show_log("NOT"); }
#line 3557 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 911 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL %d %s", (yyvsp[-1].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3563 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 915 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_aggregation_node_create(AGGR_TYPE_COUNT, true, NULL); show_log("COUNTALL "); }
#line 3569 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 916 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_aggregation_node_create(AGGR_TYPE_COUNT, false, (yyvsp[-1].expr_node)); show_log(" CALL 1 COUNT"); }
#line 3575 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 918 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_aggregation_node_create(AGGR_TYPE_SUM, true, NULL); show_log("SUMALL"); }
#line 3581 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 919 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_aggregation_node_create(AGGR_TYPE_SUM, false, (yyvsp[-1].expr_node)); show_log(" CALL 1 SUM"); }
#line 3587 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 921 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL %d SUBSTR", (yyvsp[-1].intval));}
#line 3593 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 922 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL 2 SUBSTR"); }
#line 3599 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 923 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL 3 SUBSTR"); }
#line 3605 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 924 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL %d TRIM", (yyvsp[-1].intval)); }
#line 3611 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 925 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL 3 TRIM"); }
#line 3617 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 928 "pmysql.y" /* yacc.c:1646  */
    { show_log("INT 1"); }
#line 3623 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 929 "pmysql.y" /* yacc.c:1646  */
    { show_log("INT 2"); }
#line 3629 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 930 "pmysql.y" /* yacc.c:1646  */
    { show_log("INT 3"); }
#line 3635 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 933 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL 3 DATE_ADD"); }
#line 3641 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 934 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL 3 DATE_SUB"); }
#line 3647 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 937 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 1"); }
#line 3653 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 938 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 2"); }
#line 3659 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 939 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 3"); }
#line 3665 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 940 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 4"); }
#line 3671 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 941 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 5"); }
#line 3677 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 942 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 6"); }
#line 3683 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 943 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 7"); }
#line 3689 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 944 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 8"); }
#line 3695 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 945 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 9"); }
#line 3701 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 948 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASEVAL %d 0", (yyvsp[-1].intval)); }
#line 3707 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 949 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASEVAL %d 1", (yyvsp[-3].intval)); }
#line 3713 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 950 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASE %d 0", (yyvsp[-1].intval)); }
#line 3719 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 951 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASE %d 1", (yyvsp[-3].intval)); }
#line 3725 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 954 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3731 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 955 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-4].intval)+1; }
#line 3737 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 958 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIKE"); }
#line 3743 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 959 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIKE"); show_log("NOT"); }
#line 3749 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 962 "pmysql.y" /* yacc.c:1646  */
    { show_log("REGEXP"); }
#line 3755 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 963 "pmysql.y" /* yacc.c:1646  */
    { show_log("REGEXP"); show_log("NOT"); }
#line 3761 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 966 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOW"); }
#line 3767 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 967 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOW");}
#line 3773 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 968 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOW"); }
#line 3779 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 971 "pmysql.y" /* yacc.c:1646  */
    { show_log("STRTOBIN"); }
#line 3785 "pmysql.tab.c" /* yacc.c:1646  */
    break;


#line 3789 "pmysql.tab.c" /* yacc.c:1646  */
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
#line 974 "pmysql.y" /* yacc.c:1906  */

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
