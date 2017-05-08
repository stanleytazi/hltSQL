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
#line 22 "pmysql.y" /* yacc.c:1909  */

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
