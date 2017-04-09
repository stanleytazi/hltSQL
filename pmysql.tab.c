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
    TEXT = 456,
    TERMINATED = 457,
    THEN = 458,
    TIME = 459,
    TIMESTAMP = 460,
    TINYBLOB = 461,
    TINYINT = 462,
    TINYTEXT = 463,
    TO = 464,
    TRAILING = 465,
    TRIGGER = 466,
    UNDO = 467,
    UNION = 468,
    UNIQUE = 469,
    UNLOCK = 470,
    UNSIGNED = 471,
    UPDATE = 472,
    USAGE = 473,
    USE = 474,
    USING = 475,
    UTC_DATE = 476,
    UTC_TIME = 477,
    UTC_TIMESTAMP = 478,
    VALUES = 479,
    VARBINARY = 480,
    VARCHAR = 481,
    VARYING = 482,
    WHEN = 483,
    WHERE = 484,
    WHILE = 485,
    WITH = 486,
    WRITE = 487,
    YEAR = 488,
    YEAR_MONTH = 489,
    ZEROFILL = 490,
    FSUBSTRING = 491,
    FTRIM = 492,
    FDATE_ADD = 493,
    FDATE_SUB = 494,
    FCOUNT = 495
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
	//select_table_node_t *table_factor_node;//0401//0409
	select_table_node_t *select_table_node;//0401
	cret_def_node_t *cret_node;

#line 379 "pmysql.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PMYSQL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 394 "pmysql.tab.c" /* yacc.c:358  */

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
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1409

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  255
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  282
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  589

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   495

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    18,     2,     2,     2,    28,    22,     2,
     252,   253,    26,    24,   254,    25,   251,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   250,
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
     244,   245,   246,   247,   248,   249
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   327,   327,   328,   331,   333,   334,   336,   338,   342,
     345,   351,   356,   361,   366,   367,   370,   371,   372,   373,
     374,   377,   377,   380,   381,   384,   385,   388,   389,   390,
     391,   394,   400,   406,   409,   412,   415,   421,   424,   429,
     434,   439,   444,   445,   446,   447,   448,   450,   456,   461,
     462,   465,   466,   466,   469,   470,   471,   472,   473,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   491,   492,   493,   500,   501,   502,   505,   506,
     507,   511,   512,   549,   552,   553,   554,   557,   558,   566,
     569,   571,   577,   578,   580,   581,   585,   587,   591,   592,
     593,   596,   597,   600,   600,   602,   602,   605,   605,   606,
     609,   610,   613,   614,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   628,   629,   630,   633,   635,   636,   639,
     640,   644,   645,   647,   648,   651,   652,   655,   656,   657,
     661,   663,   665,   667,   669,   673,   674,   675,   678,   679,
     682,   683,   686,   687,   688,   691,   691,   694,   695,   699,
     701,   703,   705,   708,   709,   712,   713,   716,   721,   724,
     729,   730,   731,   732,   735,   740,   741,   745,   745,   747,
     753,   756,   762,   768,   774,   777,   784,   785,   786,   790,
     793,   796,   799,   807,   811,   812,   815,   816,   821,   824,
     826,   826,   829,   831,   836,   837,   838,   839,   840,   841,
     842,   845,   846,   847,   848,   849,   850,   851,   852,   853,
     854,   855,   856,   857,   858,   859,   860,   861,   862,   863,
     864,   865,   866,   869,   870,   871,   872,   875,   879,   880,
     883,   884,   887,   888,   889,   890,   891,   894,   898,   899,
     901,   902,   903,   904,   905,   908,   909,   910,   913,   914,
     917,   918,   919,   920,   921,   922,   923,   924,   925,   928,
     929,   930,   931,   934,   935,   938,   939,   942,   943,   946,
     947,   948,   951
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
  "STRAIGHT_JOIN", "TABLE", "TEMPORARY", "TEXT", "TERMINATED", "THEN",
  "TIME", "TIMESTAMP", "TINYBLOB", "TINYINT", "TINYTEXT", "TO", "TRAILING",
  "TRIGGER", "UNDO", "UNION", "UNIQUE", "UNLOCK", "UNSIGNED", "UPDATE",
  "USAGE", "USE", "USING", "UTC_DATE", "UTC_TIME", "UTC_TIMESTAMP",
  "VALUES", "VARBINARY", "VARCHAR", "VARYING", "WHEN", "WHERE", "WHILE",
  "WITH", "WRITE", "YEAR", "YEAR_MONTH", "ZEROFILL", "FSUBSTRING", "FTRIM",
  "FDATE_ADD", "FDATE_SUB", "FCOUNT", "';'", "'.'", "'('", "')'", "','",
  "$accept", "stmt_list", "stmt", "show_log_stmt", "import_file_stmt",
  "insert_stmt", "opt_ondupupdate", "insert_opts", "opt_into",
  "opt_col_names", "insert_vals_list", "insert_vals", "insert_asgn_list",
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
      59,    46,    40,    41,    44
};
# endif

#define YYPACT_NINF -350

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-350)))

#define YYTABLE_NINF -189

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-189)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     312,     6,   -14,  -350,    57,  -350,  -350,  -350,    83,   158,
       3,    95,  -241,  -350,  -350,  -350,  -350,  -350,  -350,  -350,
    -350,  -350,  -350,  -350,   387,  -145,   -21,   -21,    49,    59,
    -150,   387,   387,   326,   293,   -61,  -350,  -350,  -350,   154,
       4,  -350,   -26,  -350,  -350,  -350,  -350,  -350,  -350,   229,
     -21,   151,   235,   248,   -21,   -21,   265,    46,   271,  -350,
    -350,  -350,   -67,    86,   300,   313,    55,  -350,  -350,  -350,
    -350,   330,   729,   729,   729,  -350,  -350,   729,   399,  -350,
    -350,  -350,  -350,  -350,    76,  -350,  -350,  -350,  -350,  -350,
      90,    98,   109,   114,   120,   -55,  -350,  1324,   729,   729,
      83,     7,     8,    10,     2,   -87,   632,  -350,  -350,   336,
    -350,   125,   398,  -350,  -350,  -350,   409,   426,   183,   411,
    -350,    -2,    -4,     4,   438,  -350,   -44,    -5,   445,   729,
     729,   821,   821,  -350,  -350,   729,     5,   -35,   295,   729,
     350,   729,   729,   451,     4,   729,  -350,   729,   729,   729,
     241,    30,   729,   729,   349,   729,   133,   729,   729,   729,
     729,   729,   729,   729,   729,   729,   729,   492,  -350,  1361,
    1361,  -350,   502,    39,   254,    58,   518,     4,  -350,  -350,
    -350,   -70,  -350,     4,   395,   361,  -350,   533,   540,   314,
     309,   316,    40,    43,  -350,   729,   408,     4,    24,    46,
     580,     1,   580,    33,  -350,   808,  -350,   332,  1361,  1074,
       9,   729,  -350,   729,   333,    60,   334,  -350,  -350,  -350,
     335,   729,   864,   885,   338,   990,    24,  -350,  1031,  1254,
     943,   481,  -350,    45,  -350,  1379,  1379,   337,   729,   729,
    1225,   340,   341,   342,   295,   837,   915,   527,   635,   319,
     319,   570,   570,   570,   570,  -350,  -350,    96,   472,   474,
     475,  -350,  -350,  -350,    -8,    27,   632,   361,   361,   478,
     450,     4,  -350,   480,  -350,  -350,    82,   358,    43,    43,
     153,  -350,   365,   366,   490,  -350,   617,    43,   117,  -350,
     618,  -350,   336,   130,  1361,   587,   500,    24,  -350,  -350,
     619,   -41,   358,   358,   559,    23,   482,   -41,   358,   482,
     729,  -350,   729,   729,  -350,  1178,  1121,  -350,   729,  -350,
    -350,  1157,   513,   513,  -350,  -350,   535,   397,   400,  -350,
    -350,   481,  1379,  1379,   729,   295,   295,   295,   401,    39,
     550,   550,   550,   729,   652,   654,   408,  -350,  -350,     4,
     729,  -108,     4,  -350,   663,    23,   141,   144,   416,   418,
     540,   540,   439,   -60,   155,  -350,    43,   -56,   295,  -350,
     729,   729,  -350,  -350,   608,   561,   689,  -350,    23,    23,
    -350,   165,  1361,   441,  -350,  -350,  -350,    23,  -350,  -350,
    1361,  1204,  -350,   729,   969,   729,   729,   442,   448,   656,
     595,  -350,  -350,   453,   454,   655,   455,   462,   463,  -350,
    -350,   589,   466,   467,   468,  1361,   702,    -6,   500,  -350,
    1361,   729,   473,  -350,  -350,  -108,  -350,  -350,  -350,  -350,
     540,   540,   173,   186,   540,    43,  -350,   -19,  -350,   486,
     487,  -350,  -350,   488,  1289,   906,  -350,  1361,   514,   721,
    -350,  -350,  -350,   624,   559,  -350,  -350,  1361,   729,  -350,
     491,  1053,  -350,  -350,   729,   729,   408,  -350,  -350,  -350,
    -350,  -350,  -350,   740,   740,   740,   729,   729,   742,  -350,
    1361,   540,  -350,   192,   217,  -350,  -350,   219,   221,  -350,
     743,  -350,   745,   382,   729,  -350,  -350,  -350,   729,   580,
     706,  -350,  1361,   225,  1011,  -350,  -350,  -350,  -350,  -350,
    -350,  -350,  -350,  -350,  -350,  -187,  1361,   500,  -350,   227,
     238,   264,  1361,  1361,   732,   266,  -350,  -350,  -350,    38,
     273,    19,   504,   598,  -350,   751,   446,  -350,  -350,   629,
     -68,  1289,  1361,   505,  -350,  1361,  -350,  -350,   577,  -350,
     636,  -350,   760,  -350,  -350,   729,  -350,  -350,  -350,   759,
    -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,
    -350,   540,  -350,  -350,   540,  -350,  -350,  1361,   512,   272,
     281,   519,  -350,   576,   764,  -350,   770,  -350,  -350
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    16,    87,   173,     0,    16,    16,   114,     0,     0,
      16,     0,     0,     4,     7,     9,    37,    89,   168,   180,
     184,   193,   198,    88,    22,     0,   196,   196,     0,     0,
       0,    22,    22,     0,     0,   199,   200,     5,     6,     0,
       0,     1,     0,     2,    18,    19,    20,    21,    17,     0,
     196,     0,     0,     0,   196,   196,     0,   177,     0,   172,
     170,   171,     0,     0,     0,     0,   204,   207,   208,   210,
     209,   205,     0,     0,     0,   125,   115,     0,     0,   280,
     281,   279,   116,   117,     0,   118,   121,   122,   120,   119,
       0,     0,     0,     0,     0,    90,   123,   139,     0,     0,
       0,    20,    17,   139,     0,     0,   127,   129,   130,   136,
       3,    23,     0,   197,   194,   195,     0,     0,     0,     0,
     175,    92,     0,     0,     0,     8,    23,    23,     0,   240,
       0,   230,   231,   217,   282,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,   203,
     202,   201,     0,   162,     0,     0,     0,     0,   147,   146,
     150,   154,   151,     0,     0,   148,   135,     0,     0,     0,
       0,     0,    51,    51,   178,     0,   105,     0,    92,   177,
       0,     0,     0,     0,   206,   238,   241,     0,   232,     0,
       0,     0,   271,     0,     0,   238,     0,   257,   255,   256,
       0,     0,     0,     0,     0,     0,    92,   124,   219,   220,
     218,     0,   235,     0,   233,   275,   277,     0,     0,     0,
       0,     0,     0,     0,     0,   221,   226,   227,   229,   211,
     212,   213,   214,   215,   216,   228,   137,   139,     0,     0,
       0,   131,   167,   134,     0,    92,   128,   148,   148,     0,
     141,     0,   149,     0,   133,   112,     0,     0,    51,    51,
       0,    85,     0,     0,     0,    86,     0,    51,     0,    49,
       0,    41,   136,     0,    93,     0,   107,    92,   174,   176,
       0,    14,     0,     0,     0,    14,    14,    14,     0,    14,
       0,   247,     0,     0,   269,     0,     0,   246,     0,   250,
     253,     0,     0,     0,   248,   249,    94,     0,     0,   236,
     234,     0,   276,   278,     0,     0,     0,     0,     0,   162,
     164,   164,   164,     0,     0,     0,   105,   152,   153,     0,
       0,   156,     0,    24,     0,    14,     0,     0,     0,     0,
       0,     0,     0,    84,    44,    43,    51,     0,     0,    42,
       0,     0,   169,   179,     0,     0,     0,    31,    14,    14,
      28,     0,    27,     0,    12,    32,   182,    14,   183,   239,
     273,     0,   272,     0,     0,     0,     0,     0,     0,     0,
     103,   244,   242,     0,     0,   237,     0,     0,     0,   222,
     132,     0,     0,     0,     0,   189,     0,     0,   107,   144,
     142,     0,     0,   140,   155,     0,   113,    11,    45,    46,
       0,     0,     0,     0,     0,    51,    48,    84,    50,    72,
       0,    59,    83,   106,    98,   108,    34,    33,     0,     0,
      13,    10,    25,     0,     0,   181,   270,   274,     0,   251,
       0,     0,   258,   259,     0,     0,   105,   245,   243,   225,
     223,   224,   163,     0,     0,     0,     0,     0,     0,   185,
     157,     0,   143,     0,     0,    56,    55,     0,     0,    40,
       0,    75,     0,    53,     0,    99,   100,    96,     0,     0,
       0,    30,    29,     0,     0,   254,   260,   261,   262,   263,
     266,   267,   268,   265,   264,   101,   104,   107,   165,     0,
       0,     0,   190,   191,     0,     0,    57,    58,    54,    84,
       0,    81,     0,     0,    66,     0,     0,    70,    61,     0,
       0,    98,   109,    15,    36,    35,    26,   252,     0,    95,
     110,   161,     0,   160,   159,     0,   158,    47,    73,     0,
      76,    77,    78,    60,    71,    62,    63,    65,    64,    69,
      68,     0,    97,   102,     0,    91,   166,   192,     0,    82,
       0,   111,    74,     0,     0,    67,     0,    80,    79
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -350,  -350,   765,  -350,  -350,  -350,   203,   299,   355,   413,
      17,   321,  -201,  -350,  -135,   412,  -350,  -350,  -350,  -350,
    -350,  -350,  -326,  -350,   775,   -96,    11,  -350,   317,   239,
    -350,  -350,  -254,  -349,  -350,  -141,  -350,  -350,   637,    78,
     606,  -126,   494,   -80,  -350,  -350,   274,  -350,  -350,  -350,
     362,   449,   218,   105,  -350,  -350,  -350,   731,   591,  -350,
    -350,  -350,  -350,  -350,   268,  -350,  -350,   691,   -33,  -137,
    -350,  -350,   476,   659
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    15,   377,    24,    49,   189,
     305,   381,   301,    16,   288,   289,   290,   493,   491,   531,
     579,   441,   291,   292,    25,    17,   196,   400,   443,   497,
     549,   466,   296,   372,   575,   276,    33,    95,    96,   105,
     106,   107,   187,   168,   108,   184,   273,   185,   269,   423,
     424,   261,   412,   519,   109,    18,    29,    62,   120,    19,
      20,    40,   265,    21,    52,    22,    35,    36,   205,   206,
     207,   221,   397,   137
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      97,   307,   216,   220,   302,   103,  -186,   103,   174,    43,
    -188,  -187,   343,   146,   477,   147,   148,   149,   150,   151,
     152,   153,   154,   173,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   232,   436,   123,   131,
     132,   133,   214,   -52,   134,   136,   -52,   233,   167,   421,
     144,   329,    54,   548,    26,   281,   211,   270,   293,   212,
      30,   570,    57,    50,   267,   169,   170,   494,   439,   479,
     147,   148,   149,   150,   151,   152,   153,   154,   -84,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    34,   418,    51,   328,    41,   281,   208,     1,   146,
     313,    63,   209,   314,   176,   306,   215,   309,   222,   223,
     225,   489,    97,   268,   228,   229,   230,   375,   285,   235,
     236,   422,   240,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   167,   327,    66,    67,    68,    69,
      70,    71,   258,   356,   357,   351,   280,   200,   338,   280,
      72,    73,   364,   281,   259,   281,     2,   282,    74,   285,
     282,    37,   294,    51,    58,   318,   241,   177,   550,   283,
     242,    27,   283,   389,    59,     3,    77,   339,   315,   440,
     316,   375,   175,    78,   571,   234,   202,   124,   321,     7,
       7,    38,   435,   100,   404,    23,    79,    80,    81,   145,
     330,   198,   213,   557,    60,   332,   333,   284,   188,   298,
     284,     4,   517,   376,   -87,    23,   285,     5,   285,   432,
     433,     7,   226,   419,   110,   197,   425,  -177,   -84,    61,
      84,   -38,   111,    44,   303,   403,   195,   326,   114,   406,
     407,   408,   135,   344,   560,   478,   213,   188,   113,   119,
     124,   115,  -177,   304,   104,  -186,   104,    55,   460,  -188,
    -187,   172,   195,   561,    45,   195,   308,   260,   118,   101,
     358,   382,   442,     6,   121,   297,   346,   383,   177,   390,
     391,   345,   359,     7,   125,   394,     8,     9,   -39,   483,
     484,   286,   287,   487,   355,    53,    56,   119,   543,   102,
     488,   405,    98,   126,    31,    32,   128,   129,   373,    39,
     415,   263,   177,    99,   310,     1,   127,   420,   112,   378,
     379,    10,   116,   117,   583,   387,   584,   243,   138,    66,
      67,    68,    69,    70,    71,   353,   354,   444,   445,   130,
     525,   447,   139,    72,    73,   162,   163,   164,   165,   166,
     140,    74,    75,    66,    67,    68,    69,    70,    71,    76,
     457,   141,   237,   461,   238,   239,   142,    72,    73,    77,
     365,   366,   143,     2,   186,    74,    78,   188,    90,    91,
      92,    93,    94,   369,   366,   244,    64,    65,   480,    79,
      80,    81,     3,    77,   428,   366,   217,   429,   366,   533,
      78,   190,    66,    67,    68,    69,    70,    71,   437,   366,
      82,    83,   191,    79,    80,    81,    72,    73,   452,   453,
     502,   382,   534,    84,    74,   504,   485,   354,     4,   192,
     580,   444,   516,   581,     5,   193,    85,   194,   535,   486,
     354,   199,    77,   522,   523,   526,   354,    84,   204,    78,
     565,   566,   567,   568,    66,    67,    68,    69,    70,    71,
     536,   541,    79,    80,    81,   542,    44,   545,    72,    73,
     527,   354,   528,   354,   529,   366,    74,   224,   546,   453,
     551,   552,   218,     7,    66,    67,    68,    69,    70,    71,
       6,   553,   552,   231,    77,   256,    84,    45,    72,    73,
       7,    78,    46,     8,     9,   257,    74,   262,   384,   385,
     386,   537,   388,    47,    79,    80,    81,   554,   552,   556,
     354,   264,   577,   271,    77,   272,   558,   559,    86,    87,
      88,    78,    48,    89,   585,   354,   274,   538,    10,   201,
     203,   347,   348,   275,    79,    80,    81,   277,    84,   539,
     159,   160,   161,   162,   163,   164,   165,   166,   427,   413,
     414,   278,    66,    67,    68,    69,    70,    71,   279,   219,
     295,    90,    91,    92,    93,    94,    72,    73,    84,   520,
     521,   450,   451,   300,    74,   311,   317,   319,   320,   331,
     455,   324,   335,   336,   337,    90,    91,    92,    93,    94,
     166,   340,    77,   341,   342,   540,   349,   350,   352,    78,
     304,    66,    67,    68,    69,    70,    71,   360,   361,   362,
     363,   367,    79,    80,    81,    72,    73,    66,    67,    68,
      69,    70,    71,    74,   370,   371,   135,   380,   396,   374,
     375,    72,    73,   399,    90,    91,    92,    93,    94,    74,
     401,    77,   411,   402,   409,   416,    84,   417,    78,   160,
     161,   162,   163,   164,   165,   166,   426,    77,   430,     7,
     431,    79,    80,    81,    78,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   446,    79,    80,    81,
     448,   434,   449,   454,   178,   462,    90,    91,    92,    93,
      94,   463,   501,   464,   465,    84,   467,   468,   469,    66,
      67,    68,    69,    70,    71,   470,   471,   472,   473,   474,
     475,    84,   476,    72,    73,   481,    90,    91,    92,    93,
      94,    74,    66,    67,    68,    69,    70,    71,   490,   492,
     499,   500,   494,   518,   505,   524,    72,    73,   530,    77,
     532,   179,   555,   563,    74,   564,    78,   562,   569,   376,
    -145,   573,   574,   576,   578,   582,   180,   586,   587,    79,
      80,    81,    77,   354,   588,   503,    42,    28,   438,    78,
     572,   515,   227,   266,   544,   181,   368,   482,   410,   122,
     299,   171,    79,    80,    81,   210,     0,     0,     0,   398,
       0,     0,     0,    84,    90,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,   182,     0,     0,   147,   148,
     149,   150,   151,   152,   153,   154,    84,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   183,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,     0,    90,    91,    92,    93,    94,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,     0,    90,
      91,    92,    93,    94,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   147,   148,   149,   150,
     151,   152,   153,   154,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   158,   159,   160,
     161,   162,   163,   164,   165,   166,     0,     0,     0,     0,
       0,    90,    91,    92,    93,    94,   150,   151,   152,   153,
     154,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    90,    91,    92,    93,    94,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     147,   148,   149,   150,   151,   152,   153,   154,     0,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   148,   149,   150,   151,   152,   153,   154,     0,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   310,   147,   148,   149,   150,   151,   152,   153,
     154,   458,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   322,     0,
       0,     0,     0,     0,     0,   506,   507,   508,   509,     0,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   323,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,     0,     0,     0,     0,     0,     0,     0,     0,
     498,     0,     0,     0,   510,   511,   512,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   147,   148,
     149,   150,   151,   152,   153,   154,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,     0,
       0,     0,     0,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   459,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   147,   148,   149,   150,   151,
     152,   153,   154,   325,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,     0,     0,     0,     0,
       0,   334,   395,     0,   547,     0,   149,   150,   151,   152,
     153,   154,   392,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     0,   312,     0,     0,     0,
       0,     0,     0,     0,     0,   513,   514,     0,   456,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
       0,     0,     0,     0,     0,     0,     0,   146,   495,     0,
       0,     0,     0,   393,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     0,     0,     0,     0,     0,
       0,     0,   167,     0,     0,     0,     0,     0,     0,     0,
     496,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,  -189,  -189,  -189,  -189,   154,     0,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166
};

static const yytype_int16 yycheck[] =
{
      33,   202,   139,   140,     3,     3,     3,     3,   104,   250,
       3,     3,    20,     3,    20,    10,    11,    12,    13,    14,
      15,    16,    17,   103,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     6,   363,   105,    72,
      73,    74,   138,     3,    77,    78,     3,    17,    38,   157,
     105,     6,     3,   240,    68,   115,    91,   183,   193,    94,
       3,   129,     3,   208,   134,    98,    99,   254,   124,   418,
      10,    11,    12,    13,    14,    15,    16,    17,    38,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     8,   346,   114,   231,     0,   115,   130,     3,     3,
      91,   251,   135,    94,   191,   201,   139,   203,   141,   142,
     143,   437,   145,   183,   147,   148,   149,   158,   178,   152,
     153,   229,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    38,   231,     3,     4,     5,     6,
       7,     8,   103,   278,   279,   271,   106,   191,   244,   106,
      17,    18,   287,   115,   115,   115,    61,   117,    25,   178,
     117,     3,   195,   114,   105,   105,    33,   254,   517,   129,
      37,   185,   129,   310,   115,    80,    43,   257,   211,   235,
     213,   158,   104,    50,   252,   155,   191,   254,   221,   188,
     188,    33,   252,   254,   331,   209,    63,    64,    65,   254,
     155,   123,   237,   529,   145,   238,   239,   167,   252,   198,
     167,   116,   466,   254,   208,   209,   178,   122,   178,   360,
     361,   188,   144,   349,   250,   229,   352,   229,   188,   170,
      97,   250,     3,    79,   233,   331,   238,   226,     3,   335,
     336,   337,   237,   251,   225,   251,   237,   252,    97,   251,
     254,     3,   254,   252,   252,   252,   252,   208,   395,   252,
     252,   251,   238,   244,   110,   238,   233,   228,     3,   115,
     117,   304,   368,   178,     3,   197,   265,   254,   254,   312,
     313,   254,   129,   188,   198,   318,   191,   192,   250,   430,
     431,   251,   252,   434,   277,    27,    28,   251,   499,   145,
     435,   334,     9,     3,     5,     6,   251,   252,   297,    10,
     343,   253,   254,    20,   254,     3,     3,   350,    50,   302,
     303,   226,    54,    55,    52,   308,    54,   194,   252,     3,
       4,     5,     6,     7,     8,   253,   254,   370,   371,     9,
     481,   374,   252,    17,    18,    26,    27,    28,    29,    30,
     252,    25,    26,     3,     4,     5,     6,     7,     8,    33,
     393,   252,    13,   396,    15,    16,   252,    17,    18,    43,
     253,   254,   252,    61,    38,    25,    50,   252,   245,   246,
     247,   248,   249,   253,   254,   252,    31,    32,   421,    63,
      64,    65,    80,    43,   253,   254,    46,   253,   254,    17,
      50,     3,     3,     4,     5,     6,     7,     8,   253,   254,
      84,    85,     3,    63,    64,    65,    17,    18,   253,   254,
     453,   454,    40,    97,    25,   458,   253,   254,   116,     3,
     571,   464,   465,   574,   122,   252,   110,    26,    56,   253,
     254,     3,    43,   476,   477,   253,   254,    97,     3,    50,
       4,     5,     6,     7,     3,     4,     5,     6,     7,     8,
      78,   494,    63,    64,    65,   498,    79,   500,    17,    18,
     253,   254,   253,   254,   253,   254,    25,    26,   253,   254,
     253,   254,   132,   188,     3,     4,     5,     6,     7,     8,
     178,   253,   254,   252,    43,     3,    97,   110,    17,    18,
     188,    50,   115,   191,   192,     3,    25,   253,   305,   306,
     307,   129,   309,   126,    63,    64,    65,   253,   254,   253,
     254,     3,   555,   128,    43,   164,   253,   254,   202,   203,
     204,    50,   145,   207,   253,   254,     3,   155,   226,   126,
     127,   267,   268,     3,    63,    64,    65,   233,    97,   167,
      23,    24,    25,    26,    27,    28,    29,    30,   355,   341,
     342,   252,     3,     4,     5,     6,     7,     8,   252,   219,
     162,   245,   246,   247,   248,   249,    17,    18,    97,   474,
     475,   378,   379,     3,    25,   253,   253,   253,   253,   252,
     387,   253,   252,   252,   252,   245,   246,   247,   248,   249,
      30,   129,    43,   129,   129,   223,   128,   157,   128,    50,
     252,     3,     4,     5,     6,     7,     8,   252,   252,   129,
       3,     3,    63,    64,    65,    17,    18,     3,     4,     5,
       6,     7,     8,    25,    47,   135,   237,    78,   125,    20,
     158,    17,    18,   108,   245,   246,   247,   248,   249,    25,
     253,    43,   102,   253,   253,     3,    97,     3,    50,    24,
      25,    26,    27,    28,    29,    30,     3,    43,   252,   188,
     252,    63,    64,    65,    50,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    78,    63,    64,    65,
     129,   252,     3,   252,    62,   253,   245,   246,   247,   248,
     249,   253,    78,    47,   109,    97,   253,   253,   253,     3,
       4,     5,     6,     7,     8,   253,   253,   128,   252,   252,
     252,    97,    20,    17,    18,   252,   245,   246,   247,   248,
     249,    25,     3,     4,     5,     6,     7,     8,   252,   252,
     226,    20,   254,     3,   253,     3,    17,    18,     5,    43,
       5,   119,    20,   155,    25,     4,    50,   253,   129,   254,
     128,   184,   126,     3,     5,   253,   134,   191,     4,    63,
      64,    65,    43,   254,     4,   454,    11,     2,   366,    50,
     541,   464,   145,   177,    78,   153,   292,   425,   339,    58,
     199,   100,    63,    64,    65,   136,    -1,    -1,    -1,   323,
      -1,    -1,    -1,    97,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    97,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,   207,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,   245,   246,   247,   248,   249,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,   245,
     246,   247,   248,   249,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,   245,   246,   247,   248,   249,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,   245,   246,   247,   248,   249,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    11,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   254,    10,    11,    12,    13,    14,    15,    16,
      17,   102,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,   254,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,   111,   112,   113,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,   253,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    10,    11,    12,    13,    14,
      15,    16,    17,   253,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    36,   105,    -1,   253,    -1,    12,    13,    14,    15,
      16,    17,    94,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,   212,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   242,   243,    -1,    94,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    39,    -1,
      -1,    -1,    -1,   212,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,    61,    80,   116,   122,   178,   188,   191,   192,
     226,   256,   257,   258,   259,   260,   268,   280,   310,   314,
     315,   318,   320,   209,   262,   279,    68,   185,   279,   311,
       3,   262,   262,   291,     8,   321,   322,     3,    33,   262,
     316,     0,   257,   250,    79,   110,   115,   126,   145,   263,
     208,   114,   319,   319,     3,   208,   319,     3,   105,   115,
     145,   170,   312,   251,   263,   263,     3,     4,     5,     6,
       7,     8,    17,    18,    25,    26,    33,    43,    50,    63,
      64,    65,    84,    85,    97,   110,   202,   203,   204,   207,
     245,   246,   247,   248,   249,   292,   293,   323,     9,    20,
     254,   115,   145,     3,   252,   294,   295,   296,   299,   309,
     250,     3,   319,    97,     3,     3,   319,   319,     3,   251,
     313,     3,   312,   105,   254,   198,     3,     3,   251,   252,
       9,   323,   323,   323,   323,   237,   323,   328,   252,   252,
     252,   252,   252,   252,   105,   254,     3,    10,    11,    12,
      13,    14,    15,    16,    17,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    38,   298,   323,
     323,   322,   251,   298,   280,   294,   191,   254,    62,   119,
     134,   153,   183,   207,   300,   302,    38,   297,   252,   264,
       3,     3,     3,   252,    26,   238,   281,   229,   294,     3,
     191,   264,   191,   264,     3,   323,   324,   325,   323,   323,
     328,    91,    94,   237,   280,   323,   324,    46,   132,   219,
     324,   326,   323,   323,    26,   323,   294,   293,   323,   323,
     323,   252,     6,    17,   155,   323,   323,    13,    15,    16,
     323,    33,    37,   194,   252,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,     3,     3,   103,   115,
     228,   306,   253,   253,     3,   317,   295,   134,   183,   303,
     296,   128,   164,   301,     3,     3,   290,   233,   252,   252,
     106,   115,   117,   129,   167,   178,   251,   252,   269,   270,
     271,   277,   278,   269,   323,   162,   287,   294,   281,   313,
       3,   267,     3,   233,   252,   265,   280,   267,   233,   280,
     254,   253,   212,    91,    94,   323,   323,   253,   105,   253,
     253,   323,   254,   254,   253,   253,   281,   280,   324,     6,
     155,   252,   323,   323,    36,   252,   252,   252,   280,   298,
     129,   129,   129,    20,   251,   254,   281,   301,   301,   128,
     157,   296,   128,   253,   254,   265,   269,   269,   117,   129,
     252,   252,   129,     3,   269,   253,   254,     3,   297,   253,
      47,   135,   288,   281,    20,   158,   254,   261,   265,   265,
      78,   266,   323,   254,   261,   261,   261,   265,   261,   324,
     323,   323,    94,   212,   323,   105,   125,   327,   327,   108,
     282,   253,   253,   280,   324,   323,   280,   280,   280,   253,
     306,   102,   307,   307,   307,   323,     3,     3,   287,   296,
     323,   157,   229,   304,   305,   296,     3,   261,   253,   253,
     252,   252,   290,   290,   252,   252,   277,   253,   270,   124,
     235,   276,   280,   283,   323,   323,    78,   323,   129,     3,
     261,   261,   253,   254,   252,   261,    94,   323,   102,   253,
     324,   323,   253,   253,    47,   109,   286,   253,   253,   253,
     253,   253,   128,   252,   252,   252,    20,    20,   251,   288,
     323,   252,   305,   290,   290,   253,   253,   290,   269,   277,
     252,   273,   252,   272,   254,    39,    81,   284,   254,   226,
      20,    78,   323,   266,   323,   253,    72,    73,    74,    75,
     111,   112,   113,   242,   243,   283,   323,   287,     3,   308,
     308,   308,   323,   323,     3,   290,   253,   253,   253,   253,
       5,   274,     5,    17,    40,    56,    78,   129,   155,   167,
     223,   323,   323,   267,    78,   323,   253,   253,   240,   285,
     288,   253,   254,   253,   253,    20,   253,   277,   253,   254,
     225,   244,   253,   155,     4,     4,     5,     6,     7,   129,
     129,   252,   284,   184,   126,   289,     3,   323,     5,   275,
     290,   290,   253,    52,    54,   253,   191,     4,     4
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   255,   256,   256,   257,   258,   258,   257,   259,   257,
     260,   260,   260,   260,   261,   261,   262,   262,   262,   262,
     262,   263,   263,   264,   264,   265,   265,   266,   266,   266,
     266,   260,   260,   267,   267,   267,   267,   257,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   269,
     269,   270,   271,   270,   270,   270,   270,   270,   270,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   273,   273,   273,   274,   274,   274,   275,   275,
     275,   276,   276,   277,   278,   278,   278,   279,   279,   257,
     280,   280,   281,   281,   282,   282,   283,   283,   284,   284,
     284,   285,   285,   286,   286,   287,   287,   288,   288,   288,
     289,   289,   290,   290,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   292,   292,   292,   293,   294,   294,   295,
     295,   296,   296,   296,   296,   297,   297,   298,   298,   298,
     299,   299,   299,   299,   299,   300,   300,   300,   301,   301,
     302,   302,   303,   303,   303,   304,   304,   305,   305,   306,
     306,   306,   306,   307,   307,   308,   308,   309,   257,   310,
     311,   311,   311,   311,   310,   312,   312,   313,   313,   310,
     257,   314,   314,   314,   257,   315,   316,   316,   316,   317,
     317,   317,   317,   257,   318,   318,   319,   319,   257,   320,
     321,   321,   322,   322,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   324,   324,
     325,   325,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   326,   326,   326,   323,   323,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   323,
     323,   323,   323,   328,   328,   323,   323,   323,   323,   323,
     323,   323,   323
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     1,     2,     2,     1,     4,     1,
       8,     8,     7,     8,     0,     4,     0,     2,     2,     2,
       2,     1,     0,     0,     3,     3,     5,     1,     1,     3,
       3,     7,     7,     3,     3,     5,     5,     1,     8,    10,
       9,     6,     7,     7,     7,     8,     8,    11,     8,     1,
       3,     0,     0,     4,     5,     4,     4,     5,     5,     0,
       3,     2,     3,     3,     3,     3,     2,     5,     3,     3,
       2,     3,     0,     3,     5,     0,     2,     2,     0,     4,
       3,     3,     5,     3,     0,     1,     1,     0,     1,     1,
       3,    11,     0,     2,     0,     4,     2,     4,     0,     1,
       1,     0,     2,     0,     2,     0,     3,     0,     2,     4,
       0,     2,     1,     3,     0,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     3,     1,     2,     1,     3,     1,
       1,     3,     5,     3,     3,     1,     0,     2,     1,     0,
       5,     3,     5,     6,     5,     0,     1,     1,     0,     1,
       1,     1,     2,     2,     0,     1,     0,     2,     4,     6,
       6,     6,     0,     2,     0,     1,     3,     3,     1,     7,
       2,     2,     2,     0,     6,     2,     4,     0,     2,     7,
       1,     8,     7,     7,     1,     8,     0,     2,     2,     3,
       5,     5,     7,     1,     4,     4,     0,     2,     1,     2,
       1,     3,     3,     3,     1,     1,     3,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     5,     6,     6,     6,     3,     3,     3,     3,
       2,     2,     3,     3,     4,     3,     4,     5,     1,     3,
       0,     1,     5,     6,     5,     6,     4,     4,     4,     4,
       4,     6,     8,     4,     7,     1,     1,     1,     6,     6,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       6,     3,     5,     4,     5,     3,     4,     3,     4,     1,
       1,     1,     2
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
#line 327 "pmysql.y" /* yacc.c:1646  */
    { sql_stmt_handle((yyvsp[-1].stmt_node));}
#line 2116 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 328 "pmysql.y" /* yacc.c:1646  */
    {sql_stmt_handle((yyvsp[-1].stmt_node));}
#line 2122 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 331 "pmysql.y" /* yacc.c:1646  */
    {(yyval.stmt_node)=(yyvsp[0].stmt_node);}
#line 2128 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 333 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_show_table_content((yyvsp[0].strval)); free((yyvsp[0].strval));}
#line 2134 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 334 "pmysql.y" /* yacc.c:1646  */
    {(yyval.stmt_node) = sql_show_all_table();}
#line 2140 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 336 "pmysql.y" /* yacc.c:1646  */
    {(yyval.stmt_node)=(yyvsp[0].stmt_node);}
#line 2146 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 338 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node)= sql_import_file((yyvsp[-2].strval)); show_log("import\n");free((yyvsp[-2].strval));}
#line 2152 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 342 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].stmt_node) ;}
#line 2158 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 348 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_insert_stmt_create((yyvsp[-4].strval), (yyvsp[-3].col_node), (yyvsp[-1].insr_node));show_log("INSERTVALS %d %d %s", (yyvsp[-6].intval), (yyvsp[-1].insr_node), (yyvsp[-4].strval)); }
#line 2164 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 354 "pmysql.y" /* yacc.c:1646  */
    { printf(" %s should be INSERT\n",(yyvsp[-7].strval));(yyval.stmt_node)=NULL; free((yyvsp[-4].strval)); }
#line 2170 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 359 "pmysql.y" /* yacc.c:1646  */
    { printf(" \"VALUES\" is missing\n");(yyval.stmt_node)=NULL; free((yyvsp[-3].strval)); }
#line 2176 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 364 "pmysql.y" /* yacc.c:1646  */
    { printf(" \"%s\" should be VALUES\n", (yyvsp[-2].strval));(yyval.stmt_node)=NULL; free((yyvsp[-4].strval));free((yyvsp[-2].strval)); }
#line 2182 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 367 "pmysql.y" /* yacc.c:1646  */
    { show_log("DUPUPDATE %d", (yyvsp[0].intval)); }
#line 2188 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 370 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2194 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 371 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 01 ; }
#line 2200 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 372 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 02 ; }
#line 2206 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 373 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 04 ; }
#line 2212 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 374 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 010 ; }
#line 2218 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 380 "pmysql.y" /* yacc.c:1646  */
    { (yyval.col_node) = NULL ;}
#line 2224 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 381 "pmysql.y" /* yacc.c:1646  */
    { (yyval.col_node) = (yyvsp[-1].col_node); sql_print_col_node((yyvsp[-1].col_node));show_log("INSERTCOLS %d", (yyvsp[-1].col_node)); }
#line 2230 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 384 "pmysql.y" /* yacc.c:1646  */
    { (yyval.insr_node) = (yyvsp[-1].insr_node); }
#line 2236 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 385 "pmysql.y" /* yacc.c:1646  */
    { show_log("VALUES %d", (yyvsp[-1].insr_node)); (yyval.insr_node) = (yyvsp[-4].insr_node) + 1; }
#line 2242 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 388 "pmysql.y" /* yacc.c:1646  */
    { (yyval.insr_node) = sql_insert_vals_node_create((yyvsp[0].expr_node), NULL, true); }
#line 2248 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 389 "pmysql.y" /* yacc.c:1646  */
    { show_log("DEFAULT"); (yyval.insr_node) = NULL; }
#line 2254 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 390 "pmysql.y" /* yacc.c:1646  */
    { (yyval.insr_node) = sql_insert_vals_node_create((yyvsp[0].expr_node), (yyvsp[-2].insr_node), false); }
#line 2260 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 391 "pmysql.y" /* yacc.c:1646  */
    { show_log("DEFAULT"); (yyval.insr_node) = NULL; }
#line 2266 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 397 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSERTASGN %d %d %s", (yyvsp[-5].intval), (yyvsp[-1].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 2272 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 402 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSERTSELECT %d %s", (yyvsp[-5].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 2278 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 407 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
       show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 2285 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 410 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
                 show_log("DEFAULT"); show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 2292 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 413 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-4].intval));
                 show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 2299 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 416 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-4].intval));
                 show_log("DEFAULT"); show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 2306 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 421 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].stmt_node);show_log("STMT"); }
#line 2312 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 426 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_cret_table_stmt_create((yyvsp[-3].strval), (yyvsp[-1].attr_node)); if ((yyval.stmt_node)==NULL) sql_free_attr_header_list((yyvsp[-1].attr_node)); show_log("CREATE %d %d %s", (yyvsp[-6].intval), (yyvsp[-4].intval), (yyvsp[-3].strval)); }
#line 2318 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 430 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATE %d %d %s.%s", (yyvsp[-8].intval), (yyvsp[-6].intval), (yyvsp[-5].strval), (yyvsp[-3].strval));
                          free((yyvsp[-5].strval)); free((yyvsp[-3].strval)); }
#line 2325 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 436 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d %s", (yyvsp[-7].intval), (yyvsp[-5].intval),(yyvsp[-4].strval)); free((yyvsp[-4].strval)); }
#line 2331 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 440 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d 0 %s", (yyvsp[-4].intval), (yyvsp[-2].intval), (yyvsp[-1].strval)); free((yyvsp[-1].strval)); }
#line 2337 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 444 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"Table\"is missing\n ");(yyval.stmt_node)=NULL;if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-3].strval));}
#line 2343 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 445 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"(\"is missing\n ");(yyval.stmt_node)=NULL;if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-2].strval));}
#line 2349 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 446 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\")\"is missing \n");(yyval.stmt_node)=NULL;if ((yyvsp[0].attr_node)) sql_free_attr_header_list((yyvsp[0].attr_node));free((yyvsp[-2].strval));}
#line 2355 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 447 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"%s\" should be CREATE\n ", (yyvsp[-7].strval));(yyval.stmt_node)=NULL;if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-7].strval));free((yyvsp[-3].strval));}
#line 2361 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 448 "pmysql.y" /* yacc.c:1646  */
    {printf("CREATE TABLE FAIL:\"%s\" should be TABLE\n ", (yyvsp[-5].strval));(yyval.stmt_node)=NULL; if ((yyvsp[-1].attr_node)) sql_free_attr_header_list((yyvsp[-1].attr_node));free((yyvsp[-5].strval));free((yyvsp[-3].strval));}
#line 2367 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 452 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d 0 %s.%s", (yyvsp[-9].intval), (yyvsp[-7].intval), (yyvsp[-6].strval), (yyvsp[-4].strval));
                              free((yyvsp[-6].strval)); free((yyvsp[-4].strval)); }
#line 2374 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 457 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d %d 0 %s.%s", (yyvsp[-6].intval), (yyvsp[-4].intval), (yyvsp[-3].strval), (yyvsp[-1].strval));
                          free((yyvsp[-3].strval)); free((yyvsp[-1].strval)); }
#line 2381 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 461 "pmysql.y" /* yacc.c:1646  */
    {(yyval.attr_node)=sql_cret_def_handle(NULL, (yyvsp[0].cret_node)); sql_printf_attr((yyvsp[0].cret_node)->cret_def_info); }
#line 2387 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 462 "pmysql.y" /* yacc.c:1646  */
    { sql_recursive_printf_node((yyvsp[-2].attr_node)); (yyval.attr_node) = sql_cret_def_handle((yyvsp[-2].attr_node), (yyvsp[0].cret_node)); sql_printf_attr((yyval.attr_node));}
#line 2393 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 465 "pmysql.y" /* yacc.c:1646  */
    {printf("NULL column\n");}
#line 2399 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 466 "pmysql.y" /* yacc.c:1646  */
    {}
#line 2405 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 467 "pmysql.y" /* yacc.c:1646  */
    { (yyval.cret_node) = sql_cret_def_attr_declar_node_create((yyvsp[-2].strval), (yyvsp[-1].intval), (yyvsp[0].intval));/*show_log("COLUMNDEF %d %s", $3, $2); */ }
#line 2411 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 469 "pmysql.y" /* yacc.c:1646  */
    { (yyval.cret_node) = sql_cret_def_pk_def_node_create((yyvsp[-1].col_node)); show_log("PRIKEY %d", (yyvsp[-1].col_node)); }
#line 2417 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 470 "pmysql.y" /* yacc.c:1646  */
    { show_log("KEY %d", (yyvsp[-1].col_node)); }
#line 2423 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 471 "pmysql.y" /* yacc.c:1646  */
    { show_log("KEY %d", (yyvsp[-1].col_node)); }
#line 2429 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 472 "pmysql.y" /* yacc.c:1646  */
    { show_log("TEXTINDEX %d", (yyvsp[-1].col_node)); }
#line 2435 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 473 "pmysql.y" /* yacc.c:1646  */
    { show_log("TEXTINDEX %d", (yyvsp[-1].col_node)); }
#line 2441 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 476 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (1<<COL_ATTR_VALID); }
#line 2447 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 477 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR NOTNULL"); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2453 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 479 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT STRING %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2459 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 480 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT NUMBER %d", (yyvsp[0].intval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2465 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 481 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT FLOAT %g", (yyvsp[0].floatval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2471 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 482 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR DEFAULT BOOL %d", (yyvsp[0].intval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2477 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 483 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR AUTOINC"); (yyval.intval) = (yyvsp[-1].intval) + 1; }
#line 2483 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 484 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR UNIQUEKEY %d", (yyvsp[-1].col_node)); (yyval.intval) = 1<<((yyvsp[-4].intval) + 1); }
#line 2489 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 485 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR UNIQUEKEY"); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2495 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 486 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR PRIKEY"); (yyval.intval) = 1<<COL_ATTR_PRIKEY; }
#line 2501 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 487 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR PRIKEY"); (yyval.intval) = 1<<COL_ATTR_PRIKEY; }
#line 2507 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 488 "pmysql.y" /* yacc.c:1646  */
    { show_log("ATTR COMMENT %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1<<((yyvsp[-2].intval) + 1); }
#line 2513 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 491 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2519 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 492 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval); }
#line 2525 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 493 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-3].intval) + 1000*(yyvsp[-1].intval); }
#line 2531 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 500 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2537 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 501 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 1000; }
#line 2543 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 502 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 2000; }
#line 2549 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 506 "pmysql.y" /* yacc.c:1646  */
    { show_log("COLCHARSET %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2555 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 507 "pmysql.y" /* yacc.c:1646  */
    { show_log("COLCOLLATE %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2561 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 511 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = DATA_TYPE_INT;}
#line 2567 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 512 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = DATA_TYPE_VARCHAR + (yyvsp[-2].intval);}
#line 2573 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 549 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATESELECT %d", (yyvsp[-2].intval)); }
#line 2579 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 552 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2585 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 553 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2591 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 554 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2; }
#line 2597 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 557 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2603 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 558 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1;}
#line 2609 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 566 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].stmt_node); show_log("STMT"); }
#line 2615 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 570 "pmysql.y" /* yacc.c:1646  */
    { show_log("SELECTNODATA %d %d", (yyvsp[-1].intval), (yyvsp[0].select_col_node)); }
#line 2621 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 574 "pmysql.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = sql_select_stmt_create(STMT_TYPE_SELECT_TUPLE, (yyvsp[-8].select_col_node), (yyvsp[-6].select_table_node), (yyvsp[-5].expr_node)); show_log("SELECT %d %d %d", (yyvsp[-9].intval), (yyvsp[-8].select_col_node), (yyvsp[-6].select_table_node)); }
#line 2627 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 577 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = NULL;}
#line 2633 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 578 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[0].expr_node); show_log("WHERE"); }
#line 2639 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 582 "pmysql.y" /* yacc.c:1646  */
    { show_log("GROUPBYLIST %d %d", (yyvsp[-1].intval), (yyvsp[0].intval)); }
#line 2645 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 586 "pmysql.y" /* yacc.c:1646  */
    { show_log("GROUPBY %d",  (yyvsp[0].intval)); (yyval.intval) = 1; }
#line 2651 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 588 "pmysql.y" /* yacc.c:1646  */
    { show_log("GROUPBY %d",  (yyvsp[0].intval)); (yyval.intval) = (yyvsp[-3].intval) + 1; }
#line 2657 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 591 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2663 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 592 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2669 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 593 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2675 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 596 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2681 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 597 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2687 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 600 "pmysql.y" /* yacc.c:1646  */
    { show_log("HAVING"); }
#line 2693 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 602 "pmysql.y" /* yacc.c:1646  */
    { show_log("ORDERBY %d", (yyvsp[0].intval)); }
#line 2699 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 605 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIMIT 1"); }
#line 2705 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 606 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIMIT 2"); }
#line 2711 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 610 "pmysql.y" /* yacc.c:1646  */
    { show_log("INTO %d", (yyvsp[0].col_node)); }
#line 2717 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 613 "pmysql.y" /* yacc.c:1646  */
    { show_log("COLUMN %s", (yyvsp[0].strval)); (yyval.col_node) = sql_col_list_node_create((yyvsp[0].strval), NULL, true); }
#line 2723 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 614 "pmysql.y" /* yacc.c:1646  */
    { (yyval.col_node) = sql_col_list_node_create((yyvsp[0].strval), (yyvsp[-2].col_node), false);show_log("COLUMN %s", (yyvsp[0].strval));}
#line 2729 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 617 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2735 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 618 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 01) yyerror("duplicate ALL option"); (yyval.intval) = (yyvsp[-1].intval) | 01; }
#line 2741 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 619 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 02) yyerror("duplicate DISTINCT option"); (yyval.intval) = (yyvsp[-1].intval) | 02; }
#line 2747 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 620 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 04) yyerror("duplicate DISTINCTROW option"); (yyval.intval) = (yyvsp[-1].intval) | 04; }
#line 2753 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 621 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 010) yyerror("duplicate HIGH_PRIORITY option"); (yyval.intval) = (yyvsp[-1].intval) | 010; }
#line 2759 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 622 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 020) yyerror("duplicate STRAIGHT_JOIN option"); (yyval.intval) = (yyvsp[-1].intval) | 020; }
#line 2765 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 623 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 040) yyerror("duplicate SQL_SMALL_RESULT option"); (yyval.intval) = (yyvsp[-1].intval) | 040; }
#line 2771 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 624 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 0100) yyerror("duplicate SQL_BIG_RESULT option"); (yyval.intval) = (yyvsp[-1].intval) | 0100; }
#line 2777 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 625 "pmysql.y" /* yacc.c:1646  */
    { if((yyval.intval) & 0200) yyerror("duplicate SQL_CALC_FOUND_ROWS option"); (yyval.intval) = (yyvsp[-1].intval) | 0200; }
#line 2783 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 628 "pmysql.y" /* yacc.c:1646  */
    { (yyval.select_col_node) = sql_select_col_list_create((yyvsp[0].select_col_node), NULL, true, false); }
#line 2789 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 629 "pmysql.y" /* yacc.c:1646  */
    {(yyval.select_col_node) = sql_select_col_list_create((yyvsp[0].select_col_node), (yyvsp[-2].select_col_node), false, false); }
#line 2795 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 630 "pmysql.y" /* yacc.c:1646  */
    { show_log("SELECTALL"); (yyval.select_col_node) = sql_select_col_list_create(NULL, NULL, NULL,true); }
#line 2801 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 633 "pmysql.y" /* yacc.c:1646  */
    { (yyval.select_col_node) = sql_select_col_node_create((yyvsp[-1].expr_node), (yyvsp[0].alias_name)); }
#line 2807 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 635 "pmysql.y" /* yacc.c:1646  */
    { (yyval.select_table_node) = sql_select_table_list_create((yyvsp[0].select_table_node), NULL, true); }
#line 2813 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 636 "pmysql.y" /* yacc.c:1646  */
    {  (yyval.select_table_node) = sql_select_table_list_create((yyvsp[0].select_table_node), (yyvsp[-2].select_table_node), false); }
#line 2819 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 644 "pmysql.y" /* yacc.c:1646  */
    {(yyval.select_table_node) = sql_select_table_node_create((yyvsp[-2].strval), NULL, (yyvsp[-1].alias_name)); show_log("TABLE %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 2825 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 645 "pmysql.y" /* yacc.c:1646  */
    {(yyval.select_table_node) = sql_select_table_node_create((yyvsp[-2].strval), (yyvsp[-4].strval), (yyvsp[-1].alias_name)); show_log("TABLE %s.%s", (yyvsp[-4].strval), (yyvsp[-2].strval));
                               free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); }
#line 2832 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 647 "pmysql.y" /* yacc.c:1646  */
    { show_log("SUBQUERYAS %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2838 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 648 "pmysql.y" /* yacc.c:1646  */
    { show_log("TABLEREFERENCES %d", (yyvsp[-1].select_table_node)); }
#line 2844 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 655 "pmysql.y" /* yacc.c:1646  */
    { (yyval.alias_name) = strdup((yyvsp[0].strval)); show_log ("ALIAS %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2850 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 656 "pmysql.y" /* yacc.c:1646  */
    { (yyval.alias_name) = strdup((yyvsp[0].strval)); show_log ("ALIAS %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2856 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 657 "pmysql.y" /* yacc.c:1646  */
    { (yyval.alias_name) = NULL; }
#line 2862 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 662 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0100+(yyvsp[-3].intval)); }
#line 2868 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 664 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0200); }
#line 2874 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 666 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0200); }
#line 2880 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 668 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0300+(yyvsp[-4].intval)+(yyvsp[-3].intval)); }
#line 2886 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 670 "pmysql.y" /* yacc.c:1646  */
    { show_log("JOIN %d", 0400+(yyvsp[-2].intval)); }
#line 2892 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 673 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2898 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 674 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2904 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 675 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2; }
#line 2910 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 678 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2916 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 679 "pmysql.y" /* yacc.c:1646  */
    {(yyval.intval) = 4; }
#line 2922 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 682 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2928 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 683 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2; }
#line 2934 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 686 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1 + (yyvsp[0].intval); }
#line 2940 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 687 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 2 + (yyvsp[0].intval); }
#line 2946 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 688 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2952 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 694 "pmysql.y" /* yacc.c:1646  */
    { show_log("ONEXPR"); }
#line 2958 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 695 "pmysql.y" /* yacc.c:1646  */
    { show_log("USING %d", (yyvsp[-1].col_node)); }
#line 2964 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 700 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEXHINT %d %d", (yyvsp[-1].intval), 010+(yyvsp[-3].intval)); }
#line 2970 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 702 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEXHINT %d %d", (yyvsp[-1].intval), 020+(yyvsp[-3].intval)); }
#line 2976 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 704 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEXHINT %d %d", (yyvsp[-1].intval), 030+(yyvsp[-3].intval)); }
#line 2982 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 708 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2988 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 709 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2994 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 712 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEX %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1; }
#line 3000 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 713 "pmysql.y" /* yacc.c:1646  */
    { show_log("INDEX %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3006 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 716 "pmysql.y" /* yacc.c:1646  */
    { show_log("SUBQUERY"); }
#line 3012 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 721 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3018 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 726 "pmysql.y" /* yacc.c:1646  */
    { show_log("DELETEONE %d %s", (yyvsp[-5].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3024 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 729 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) + 01; }
#line 3030 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 730 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) + 02; }
#line 3036 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 731 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) + 04; }
#line 3042 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 732 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3048 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 738 "pmysql.y" /* yacc.c:1646  */
    { show_log("DELETEMULTI %d %d %d", (yyvsp[-4].intval), (yyvsp[-3].intval), (yyvsp[-1].select_table_node)); }
#line 3054 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 740 "pmysql.y" /* yacc.c:1646  */
    { show_log("TABLE %s", (yyvsp[-1].strval)); free((yyvsp[-1].strval)); (yyval.intval) = 1; }
#line 3060 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 742 "pmysql.y" /* yacc.c:1646  */
    { show_log("TABLE %s", (yyvsp[-1].strval)); free((yyvsp[-1].strval)); (yyval.intval) = (yyvsp[-3].intval) + 1; }
#line 3066 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 750 "pmysql.y" /* yacc.c:1646  */
    { show_log("DELETEMULTI %d %d %d", (yyvsp[-5].intval), (yyvsp[-3].intval), (yyvsp[-1].select_table_node)); }
#line 3072 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 753 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3078 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 759 "pmysql.y" /* yacc.c:1646  */
    { show_log("REPLACEVALS %d %d %s", (yyvsp[-6].intval), (yyvsp[-1].insr_node), (yyvsp[-4].strval)); free((yyvsp[-4].strval)); }
#line 3084 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 765 "pmysql.y" /* yacc.c:1646  */
    { show_log("REPLACEASGN %d %d %s", (yyvsp[-5].intval), (yyvsp[-1].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3090 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 770 "pmysql.y" /* yacc.c:1646  */
    { show_log("REPLACESELECT %d %s", (yyvsp[-5].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3096 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 774 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3102 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 781 "pmysql.y" /* yacc.c:1646  */
    { show_log("UPDATE %d %d %d", (yyvsp[-6].intval), (yyvsp[-5].select_table_node), (yyvsp[-3].intval)); }
#line 3108 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 784 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3114 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 785 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 01 ; }
#line 3120 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 786 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 010 ; }
#line 3126 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 791 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
	 show_log("ASSIGN %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 3133 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 794 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-4].strval));
	 show_log("ASSIGN %s.%s", (yyvsp[-4].strval), (yyvsp[-2].strval)); free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 3140 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 797 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[-2].strval));
	 show_log("ASSIGN %s.%s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 3147 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 800 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad insert assignment to %s.$s", (yyvsp[-4].strval), (yyvsp[-2].strval));
	 show_log("ASSIGN %s.%s", (yyvsp[-4].strval), (yyvsp[-2].strval)); free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 3154 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 807 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3160 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 811 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATEDATABASE %d %s", (yyvsp[-1].intval), (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3166 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 812 "pmysql.y" /* yacc.c:1646  */
    { show_log("CREATEDATABASE %d %s", (yyvsp[-1].intval), (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3172 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 815 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3178 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 816 "pmysql.y" /* yacc.c:1646  */
    { if(!(yyvsp[0].subtok))yyerror("IF EXISTS doesn't exist");
                        (yyval.intval) = (yyvsp[0].subtok); /* NOT EXISTS hack */ }
#line 3185 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 821 "pmysql.y" /* yacc.c:1646  */
    { show_log("STMT"); }
#line 3191 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 829 "pmysql.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) yyerror("bad set to @%s", (yyvsp[-2].strval));
		 show_log("SET %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3198 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 831 "pmysql.y" /* yacc.c:1646  */
    { show_log("SET %s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3204 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 836 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_NAME, 0, (yyvsp[0].strval), NULL);show_log("NAME %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3210 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 837 "pmysql.y" /* yacc.c:1646  */
    { show_log("USERVAR %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3216 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 838 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_PREFIX, 0, (yyvsp[0].strval), (yyvsp[-2].strval));show_log("FIELDNAME %s.%s", (yyvsp[-2].strval), (yyvsp[0].strval)); free((yyvsp[-2].strval)); free((yyvsp[0].strval)); }
#line 3222 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 839 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_VARCHAR, 0, (yyvsp[0].strval), NULL); show_log("STRING %s", (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3228 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 840 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_basic_data_node_create(DATA_TYPE_INT, (yyvsp[0].intval), NULL, NULL); show_log("NUMBER %d", (yyvsp[0].intval)); }
#line 3234 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 841 "pmysql.y" /* yacc.c:1646  */
    { show_log("FLOAT %g", (yyvsp[0].floatval)); }
#line 3240 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 842 "pmysql.y" /* yacc.c:1646  */
    { show_log("BOOL %d", (yyvsp[0].intval)); }
#line 3246 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 845 "pmysql.y" /* yacc.c:1646  */
    { show_log("ADD"); }
#line 3252 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 846 "pmysql.y" /* yacc.c:1646  */
    { show_log("SUB"); }
#line 3258 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 847 "pmysql.y" /* yacc.c:1646  */
    { show_log("MUL"); }
#line 3264 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 848 "pmysql.y" /* yacc.c:1646  */
    { show_log("DIV"); }
#line 3270 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 849 "pmysql.y" /* yacc.c:1646  */
    { show_log("MOD"); }
#line 3276 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 850 "pmysql.y" /* yacc.c:1646  */
    { show_log("MOD"); }
#line 3282 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 851 "pmysql.y" /* yacc.c:1646  */
    { show_log("NEG"); }
#line 3288 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 852 "pmysql.y" /* yacc.c:1646  */
    {(yyval.expr_node) = sql_expr_logic_node_create(LGC_TYPE_AND, (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); show_log("AND"); }
#line 3294 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 853 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_logic_node_create(LGC_TYPE_OR, (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); show_log("OR"); }
#line 3300 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 854 "pmysql.y" /* yacc.c:1646  */
    { show_log("XOR"); }
#line 3306 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 855 "pmysql.y" /* yacc.c:1646  */
    { (yyval.expr_node) = sql_expr_comparison_node_create((yyvsp[-1].subtok), (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); show_log("CMP %d", (yyvsp[-1].subtok)); }
#line 3312 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 856 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPSELECT %d", (yyvsp[-3].subtok)); }
#line 3318 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 857 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPANYSELECT %d", (yyvsp[-4].subtok)); }
#line 3324 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 858 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPANYSELECT %d", (yyvsp[-4].subtok)); }
#line 3330 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 859 "pmysql.y" /* yacc.c:1646  */
    { show_log("CMPALLSELECT %d", (yyvsp[-4].subtok)); }
#line 3336 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 860 "pmysql.y" /* yacc.c:1646  */
    { show_log("BITOR"); }
#line 3342 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 861 "pmysql.y" /* yacc.c:1646  */
    { show_log("BITAND"); }
#line 3348 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 862 "pmysql.y" /* yacc.c:1646  */
    { show_log("BITXOR"); }
#line 3354 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 863 "pmysql.y" /* yacc.c:1646  */
    { show_log("SHIFT %s", (yyvsp[-1].subtok)==1?"left":"right"); }
#line 3360 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 864 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOT"); }
#line 3366 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 865 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOT"); }
#line 3372 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 866 "pmysql.y" /* yacc.c:1646  */
    { show_log("ASSIGN @%s", (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3378 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 869 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISNULL"); }
#line 3384 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 870 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISNULL"); show_log("NOT"); }
#line 3390 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 871 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISBOOL %d", (yyvsp[0].intval)); }
#line 3396 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 872 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISBOOL %d", (yyvsp[0].intval)); show_log("NOT"); }
#line 3402 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 875 "pmysql.y" /* yacc.c:1646  */
    { show_log("BETWEEN"); }
#line 3408 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 879 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3414 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 880 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1 + (yyvsp[0].intval); }
#line 3420 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 883 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3426 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 887 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISIN %d", (yyvsp[-1].intval)); }
#line 3432 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 888 "pmysql.y" /* yacc.c:1646  */
    { show_log("ISIN %d", (yyvsp[-1].intval)); show_log("NOT"); }
#line 3438 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 889 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSELECT"); }
#line 3444 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 890 "pmysql.y" /* yacc.c:1646  */
    { show_log("INSELECT"); show_log("NOT"); }
#line 3450 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 891 "pmysql.y" /* yacc.c:1646  */
    { show_log("EXISTS"); if((yyvsp[-3].subtok))show_log("NOT"); }
#line 3456 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 894 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL %d %s", (yyvsp[-1].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3462 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 898 "pmysql.y" /* yacc.c:1646  */
    { show_log("COUNTALL"); }
#line 3468 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 899 "pmysql.y" /* yacc.c:1646  */
    { show_log(" CALL 1 COUNT"); }
#line 3474 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 901 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL %d SUBSTR", (yyvsp[-1].intval));}
#line 3480 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 902 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL 2 SUBSTR"); }
#line 3486 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 903 "pmysql.y" /* yacc.c:1646  */
    {  show_log("CALL 3 SUBSTR"); }
#line 3492 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 904 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL %d TRIM", (yyvsp[-1].intval)); }
#line 3498 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 905 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL 3 TRIM"); }
#line 3504 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 908 "pmysql.y" /* yacc.c:1646  */
    { show_log("INT 1"); }
#line 3510 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 909 "pmysql.y" /* yacc.c:1646  */
    { show_log("INT 2"); }
#line 3516 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 910 "pmysql.y" /* yacc.c:1646  */
    { show_log("INT 3"); }
#line 3522 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 913 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL 3 DATE_ADD"); }
#line 3528 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 914 "pmysql.y" /* yacc.c:1646  */
    { show_log("CALL 3 DATE_SUB"); }
#line 3534 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 917 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 1"); }
#line 3540 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 918 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 2"); }
#line 3546 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 919 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 3"); }
#line 3552 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 920 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 4"); }
#line 3558 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 921 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 5"); }
#line 3564 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 922 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 6"); }
#line 3570 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 923 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 7"); }
#line 3576 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 924 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 8"); }
#line 3582 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 925 "pmysql.y" /* yacc.c:1646  */
    { show_log("NUMBER 9"); }
#line 3588 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 928 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASEVAL %d 0", (yyvsp[-1].intval)); }
#line 3594 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 929 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASEVAL %d 1", (yyvsp[-3].intval)); }
#line 3600 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 930 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASE %d 0", (yyvsp[-1].intval)); }
#line 3606 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 931 "pmysql.y" /* yacc.c:1646  */
    { show_log("CASE %d 1", (yyvsp[-3].intval)); }
#line 3612 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 934 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3618 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 935 "pmysql.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-4].intval)+1; }
#line 3624 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 938 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIKE"); }
#line 3630 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 939 "pmysql.y" /* yacc.c:1646  */
    { show_log("LIKE"); show_log("NOT"); }
#line 3636 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 942 "pmysql.y" /* yacc.c:1646  */
    { show_log("REGEXP"); }
#line 3642 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 943 "pmysql.y" /* yacc.c:1646  */
    { show_log("REGEXP"); show_log("NOT"); }
#line 3648 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 946 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOW"); }
#line 3654 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 947 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOW");}
#line 3660 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 948 "pmysql.y" /* yacc.c:1646  */
    { show_log("NOW"); }
#line 3666 "pmysql.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 951 "pmysql.y" /* yacc.c:1646  */
    { show_log("STRTOBIN"); }
#line 3672 "pmysql.tab.c" /* yacc.c:1646  */
    break;


#line 3676 "pmysql.tab.c" /* yacc.c:1646  */
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
#line 954 "pmysql.y" /* yacc.c:1906  */

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
  while (i<10){
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
    i++;
    }
} /* main */
