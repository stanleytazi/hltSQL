/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 21 "pmysql.y" /* yacc.c:1909  */

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

#line 314 "pmysql.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PMYSQL_TAB_H_INCLUDED  */
