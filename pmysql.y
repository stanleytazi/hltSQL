/* reference to source code in book "flex & bison", published by O'Reilly
 */
/*
 * Parser for mysql subset
 */
%{
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
%}


%union {
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
	cret_def_node_t *cret_node;
}
	
	/* names and literal values */

%token <strval> NAME
%token <strval> STRING
%token <intval> INTNUM
%token <intval> BOOL
%token <floatval> APPROXNUM

       /* user @abc names */

%token <strval> USERVAR

       /* operators and precedence levels */

%right ASSIGN
%left OR
%left XOR
%left ANDOP
%nonassoc IN IS LIKE REGEXP
%left NOT '!'
%left BETWEEN
%left <subtok> COMPARISON /* = <> < > <= >= <=> */
%left '|'
%left '&'
%left <subtok> SHIFT /* << >> */
%left '+' '-'
%left '*' '/' '%' MOD
%left '^'
%nonassoc UMINUS

%token ADD
%token ALL
%token ALTER
%token ANALYZE
%token AND
%token ANY
%token AS
%token ASC
%token AUTO_INCREMENT
%token BEFORE
%token BETWEEN
%token BIGINT
%token BINARY
%token BIT
%token BLOB
%token BOTH
%token BY
%token CALL
%token CASCADE
%token CASE
%token CHANGE
%token CHAR
%token CHECK
%token COLLATE
%token COLUMN
%token COMMENT
%token CONDITION
%token CONSTRAINT
%token CONTINUE
%token CONVERT
%token CREATE
%token CROSS
%token CURRENT_DATE
%token CURRENT_TIME
%token CURRENT_TIMESTAMP
%token CURRENT_USER
%token CURSOR
%token DATABASE
%token DATABASES
%token DATE
%token DATETIME
%token DAY_HOUR
%token DAY_MICROSECOND
%token DAY_MINUTE
%token DAY_SECOND
%token DECIMAL
%token DECLARE
%token DEFAULT
%token DELAYED
%token DELETE
%token DESC
%token DESCRIBE
%token DETERMINISTIC
%token DISTINCT
%token DISTINCTROW
%token DIV
%token DOUBLE
%token DROP
%token DUAL
%token EACH
%token ELSE
%token ELSEIF
%token ENCLOSED
%token END
%token ENUM
%token ESCAPED
%token <subtok> EXISTS
%token EXIT
%token EXPLAIN
%token FETCH
%token FLOAT
%token FOR
%token FORCE
%token FOREIGN
%token FROM
%token FULLTEXT
%token GRANT
%token GROUP
%token HAVING
%token HIGH_PRIORITY
%token HOUR_MICROSECOND
%token HOUR_MINUTE
%token HOUR_SECOND
%token IF
%token IGNORE
%token IN
%token INDEX
%token INFILE
%token INNER
%token INOUT
%token INSENSITIVE
%token INSERT
%token INT
%token INTEGER
%token INTERVAL
%token INTO
%token ITERATE
%token JOIN
%token KEY
%token KEYS
%token KILL
%token LEADING
%token LEAVE
%token LEFT
%token LIKE
%token LIMIT
%token LINES
%token LOAD
%token LOCALTIME
%token LOCALTIMESTAMP
%token LOCK
%token LONG
%token LONGBLOB
%token LONGTEXT
%token LOOP
%token LOW_PRIORITY
%token MATCH
%token MEDIUMBLOB
%token MEDIUMINT
%token MEDIUMTEXT
%token MINUTE_MICROSECOND
%token MINUTE_SECOND
%token MOD
%token MODIFIES
%token NATURAL
%token NOT
%token NO_WRITE_TO_BINLOG
%token NULLX
%token NUMBER
%token ON
%token ONDUPLICATE
%token OPTIMIZE
%token OPTION
%token OPTIONALLY
%token OR
%token ORDER
%token OUT
%token OUTER
%token OUTFILE
%token PRECISION
%token PRIMARY
%token PROCEDURE
%token PURGE
%token QUICK
%token READ
%token READS
%token REAL
%token REFERENCES
%token REGEXP
%token RELEASE
%token RENAME
%token REPEAT
%token REPLACE
%token REQUIRE
%token RESTRICT
%token RETURN
%token REVOKE
%token RIGHT
%token ROLLUP
%token SCHEMA
%token SCHEMAS
%token SECOND_MICROSECOND
%token SELECT
%token SENSITIVE
%token SEPARATOR
%token SET
%token SHOW
%token SMALLINT
%token SOME
%token SONAME
%token SPATIAL
%token SPECIFIC
%token SQL
%token SQLEXCEPTION
%token SQLSTATE
%token SQLWARNING
%token SQL_BIG_RESULT
%token SQL_CALC_FOUND_ROWS
%token SQL_SMALL_RESULT
%token SSL
%token STARTING
%token STRAIGHT_JOIN
%token TABLE
%token TEMPORARY
%token TEXT
%token TERMINATED
%token THEN
%token TIME
%token TIMESTAMP
%token TINYBLOB
%token TINYINT
%token TINYTEXT
%token TO
%token TRAILING
%token TRIGGER
%token UNDO
%token UNION
%token UNIQUE
%token UNLOCK
%token UNSIGNED
%token UPDATE
%token USAGE
%token USE
%token USING
%token UTC_DATE
%token UTC_TIME
%token UTC_TIMESTAMP
%token VALUES
%token VARBINARY
%token VARCHAR
%token VARYING
%token WHEN
%token WHERE
%token WHILE
%token WITH
%token WRITE
%token XOR
%token YEAR
%token YEAR_MONTH
%token ZEROFILL

 /* functions with special syntax */
%token FSUBSTRING
%token FTRIM
%token FDATE_ADD FDATE_SUB
%token FCOUNT

%type <intval> select_opts select_expr_list
%type <intval> val_list opt_val_list case_list
%type <intval> groupby_list opt_with_rollup opt_asc_desc
%type <intval> table_references opt_inner_cross opt_outer
%type <intval> left_or_right opt_left_or_right_outer
%type <intval> index_list opt_for_join

%type <intval> delete_opts delete_list
%type <intval> insert_opts 
%type <intval> insert_asgn_list opt_if_not_exists update_opts update_asgn_list
%type <intval> opt_temporary opt_length opt_binary opt_uz enum_list
%type <intval> column_atts data_type opt_ignore_replace 
%type <attr_node> create_col_list
%type <col_node> column_list opt_col_names
%type <stmt_node> create_table_stmt insert_stmt stmt show_log_stmt
%type <expr_node> expr
%type <insr_node> insert_vals insert_vals_list
%type <cret_node> create_definition
%start stmt_list

%%

stmt_list: stmt ';' { sql_stmt_handle($1);}
  | stmt_list stmt ';'{sql_stmt_handle($2);}
  ;

stmt: show_log_stmt {$$=$1;}
    ;


show_log_stmt: SHOW NAME { $$ = sql_show_table_content($2); free($2);}
             | SHOW ALL  {$$ = sql_show_all_table();}
             ;
   /* statements: insert statement */

stmt: insert_stmt { $$ = $1 ;}
   ;

insert_stmt: INSERT insert_opts opt_into NAME
     opt_col_names
     VALUES insert_vals_list
     opt_ondupupdate { $$ = sql_insert_stmt_create($4, $5, $7);show_log("INSERTVALS %d %d %s", $2, $7, $4); }
   ;

insert_stmt: NAME insert_opts opt_into NAME
     opt_col_names
     VALUES insert_vals_list
     opt_ondupupdate { printf(" %s should be INSERT\n",$1);$$=NULL; free($4); }

insert_stmt: INSERT insert_opts opt_into NAME
     opt_col_names
     insert_vals_list
     opt_ondupupdate { printf(" \"VALUES\" is missing\n");$$=NULL; free($4); }

insert_stmt: INSERT insert_opts opt_into NAME
     opt_col_names
     NAME insert_vals_list
     opt_ondupupdate { printf(" \"%s\" should be VALUES\n", $6);$$=NULL; free($4);free($6); }

opt_ondupupdate: /* nil */
   | ONDUPLICATE KEY UPDATE insert_asgn_list { show_log("DUPUPDATE %d", $4); }
   ;

insert_opts: /* nil */ { $$ = 0; }
   | insert_opts LOW_PRIORITY { $$ = $1 | 01 ; }
   | insert_opts DELAYED { $$ = $1 | 02 ; }
   | insert_opts HIGH_PRIORITY { $$ = $1 | 04 ; }
   | insert_opts IGNORE { $$ = $1 | 010 ; }
   ;

opt_into: INTO | /* nil */
   ;

opt_col_names: /* nil */{ $$ = NULL ;}
   | '(' column_list ')' { $$ = $2; sql_print_col_node($2);show_log("INSERTCOLS %d", $2); }
   ;

insert_vals_list: '(' insert_vals ')' { $$ = $2; }
   | insert_vals_list ',' '(' insert_vals ')' { show_log("VALUES %d", $4); $$ = $1 + 1; }

insert_vals:
     expr { $$ = sql_insert_vals_node_create($1, NULL, true); }
   | DEFAULT { show_log("DEFAULT"); $$ = NULL; }
   | insert_vals ',' expr { $$ = sql_insert_vals_node_create($3, $1, false); }
   | insert_vals ',' DEFAULT { show_log("DEFAULT"); $$ = NULL; }
   ;

insert_stmt: INSERT insert_opts opt_into NAME
    SET insert_asgn_list
    opt_ondupupdate
     { show_log("INSERTASGN %d %d %s", $2, $6, $4); free($4); }
   ;

insert_stmt: INSERT insert_opts opt_into NAME opt_col_names
    select_stmt
    opt_ondupupdate { show_log("INSERTSELECT %d %s", $2, $4); free($4); }
  ;

insert_asgn_list:
     NAME COMPARISON expr 
     { if ($2 != 4) yyerror("bad insert assignment to %s", $1);
       show_log("ASSIGN %s", $1); free($1); $$ = 1; }
   | NAME COMPARISON DEFAULT
               { if ($2 != 4) yyerror("bad insert assignment to %s", $1);
                 show_log("DEFAULT"); show_log("ASSIGN %s", $1); free($1); $$ = 1; }
   | insert_asgn_list ',' NAME COMPARISON expr
               { if ($4 != 4) yyerror("bad insert assignment to %s", $1);
                 show_log("ASSIGN %s", $3); free($3); $$ = $1 + 1; }
   | insert_asgn_list ',' NAME COMPARISON DEFAULT
               { if ($4 != 4) yyerror("bad insert assignment to %s", $1);
                 show_log("DEFAULT"); show_log("ASSIGN %s", $3); free($3); $$ = $1 + 1; }
   ;

   /** create table **/
stmt: create_table_stmt { $$ = $1;show_log("STMT"); }
   ;

create_table_stmt: CREATE opt_temporary TABLE opt_if_not_exists NAME
   '(' create_col_list ')' 
   { $$ = sql_cret_table_stmt_create($5, $7); if ($$==NULL) sql_free_attr_header_list($7); show_log("CREATE %d %d %s", $2, $4, $5); }
   ;

create_table_stmt: CREATE opt_temporary TABLE opt_if_not_exists NAME '.' NAME
   '(' create_col_list ')' { show_log("CREATE %d %d %s.%s", $2, $4, $5, $7);
                          free($5); free($7); }
   ;

create_table_stmt: CREATE opt_temporary TABLE opt_if_not_exists NAME
   '(' create_col_list ')'
create_select_statement { show_log("CREATESELECT %d %d %s", $2, $4,$5); free($5); }
    ;

create_table_stmt: CREATE opt_temporary TABLE opt_if_not_exists NAME
   create_select_statement { show_log("CREATESELECT %d %d 0 %s", $2, $4, $5); free($5); }
    ;
/*error status*/

create_table_stmt: CREATE opt_temporary opt_if_not_exists NAME '(' create_col_list')' {printf("CREATE TABLE FAIL:\"Table\"is missing\n ");$$=NULL;if ($6) sql_free_attr_header_list($6);free($4);};
create_table_stmt: CREATE opt_temporary TABLE opt_if_not_exists NAME create_col_list')' {printf("CREATE TABLE FAIL:\"(\"is missing\n ");$$=NULL;if ($6) sql_free_attr_header_list($6);free($5);};
create_table_stmt: CREATE opt_temporary TABLE opt_if_not_exists NAME '('create_col_list {printf("CREATE TABLE FAIL:\")\"is missing \n");$$=NULL;if ($7) sql_free_attr_header_list($7);free($5);};
create_table_stmt: NAME opt_temporary TABLE opt_if_not_exists NAME '('create_col_list')' {printf("CREATE TABLE FAIL:\"%s\" should be CREATE\n ", $1);$$=NULL;if ($7) sql_free_attr_header_list($7);free($1);free($5);};
create_table_stmt: CREATE opt_temporary NAME opt_if_not_exists NAME '('create_col_list')' {printf("CREATE TABLE FAIL:\"%s\" should be TABLE\n ", $3);$$=NULL; if ($7) sql_free_attr_header_list($7);free($3);free($5);};

create_table_stmt: CREATE opt_temporary TABLE opt_if_not_exists NAME '.' NAME
create_table_stmt: CREATE opt_temporary TABLE opt_if_not_exists NAME '.' NAME
   '(' create_col_list ')'
   create_select_statement  { show_log("CREATESELECT %d %d 0 %s.%s", $2, $4, $5, $7);
                              free($5); free($7); }
    ;

create_table_stmt: CREATE opt_temporary TABLE opt_if_not_exists NAME '.' NAME
   create_select_statement { show_log("CREATESELECT %d %d 0 %s.%s", $2, $4, $5, $7);
                          free($5); free($7); }
    ;

create_col_list: create_definition {$$=sql_cret_def_handle(NULL, $1); sql_printf_attr($1->cret_def_info); }
    | create_col_list ',' create_definition { sql_recursive_printf_node($1); $$ = sql_cret_def_handle($1, $3); sql_printf_attr($$);}
    ;

create_definition: /* nil*/ {printf("NULL column\n");} 
    | {} NAME data_type column_atts
                   { $$ = sql_cret_def_attr_declar_node_create($2, $3, $4);/*show_log("COLUMNDEF %d %s", $3, $2); */ }

    | PRIMARY KEY '(' column_list ')'    { $$ = sql_cret_def_pk_def_node_create($4); show_log("PRIKEY %d", $4); }
    | KEY '(' column_list ')'            { show_log("KEY %d", $3); }
    | INDEX '(' column_list ')'          { show_log("KEY %d", $3); }
    | FULLTEXT INDEX '(' column_list ')' { show_log("TEXTINDEX %d", $4); }
    | FULLTEXT KEY '(' column_list ')'   { show_log("TEXTINDEX %d", $4); }
    ;

column_atts: /* nil */ { $$ = (1<<COL_ATTR_VALID); }
    | column_atts NOT NULLX             { show_log("ATTR NOTNULL"); $$ = 1<<($1 + 1); }
    | column_atts NULLX
    | column_atts DEFAULT STRING        { show_log("ATTR DEFAULT STRING %s", $3); free($3); $$ = 1<<($1 + 1); }
    | column_atts DEFAULT INTNUM        { show_log("ATTR DEFAULT NUMBER %d", $3); $$ = 1<<($1 + 1); }
    | column_atts DEFAULT APPROXNUM     { show_log("ATTR DEFAULT FLOAT %g", $3); $$ = 1<<($1 + 1); }
    | column_atts DEFAULT BOOL          { show_log("ATTR DEFAULT BOOL %d", $3); $$ = 1<<($1 + 1); }
    | column_atts AUTO_INCREMENT        { show_log("ATTR AUTOINC"); $$ = $1 + 1; }
    | column_atts UNIQUE '(' column_list ')' { show_log("ATTR UNIQUEKEY %d", $4); $$ = 1<<($1 + 1); }
    | column_atts UNIQUE KEY { show_log("ATTR UNIQUEKEY"); $$ = 1<<($1 + 1); }
    | column_atts PRIMARY KEY { show_log("ATTR PRIKEY"); $$ = 1<<COL_ATTR_PRIKEY; }
    | column_atts KEY { show_log("ATTR PRIKEY"); $$ = 1<<COL_ATTR_PRIKEY; }
    | column_atts COMMENT STRING { show_log("ATTR COMMENT %s", $3); free($3); $$ = 1<<($1 + 1); }
    ;

opt_length: /* nil */ { $$ = 0; }
   | '(' INTNUM ')' { $$ = $2; }
   | '(' INTNUM ',' INTNUM ')' { $$ = $2 + 1000*$4; }
   ;

opt_binary: /* nil */ { $$ = 0; }
   | BINARY { $$ = 4000; }
   ;

opt_uz: /* nil */ { $$ = 0; }
   | opt_uz UNSIGNED { $$ = $1 | 1000; }
   | opt_uz ZEROFILL { $$ = $1 | 2000; }
   ;

opt_csc: /* nil */
   | opt_csc CHAR SET STRING { show_log("COLCHARSET %s", $4); free($4); }
   | opt_csc COLLATE STRING { show_log("COLCOLLATE %s", $3); free($3); }
   ;

data_type:
    INTEGER opt_length opt_uz { $$ = DATA_TYPE_INT;}
   | VARCHAR '(' INTNUM ')' opt_csc { $$ = DATA_TYPE_VARCHAR + $3;}
   /*
    | TINYINT opt_length opt_uz { $$ = 10000 + $2; }
   |  BIT opt_length { $$ = 10000 + $2; }
   | SMALLINT opt_length opt_uz { $$ = 20000 + $2 + $3; }
   | MEDIUMINT opt_length opt_uz { $$ = 30000 + $2 + $3; }
   | INT opt_length opt_uz { $$ = 40000 + $2 + $3; }
   | BIGINT opt_length opt_uz { $$ = 60000 + $2 + $3; }
   | REAL opt_length opt_uz { $$ = 70000 + $2 + $3; }
   | DOUBLE opt_length opt_uz { $$ = 80000 + $2 + $3; }
   | FLOAT opt_length opt_uz { $$ = 90000 + $2 + $3; }
   | DECIMAL opt_length opt_uz { $$ = 110000 + $2 + $3; }
   | DATE { $$ = 100001; }
   | TIME { $$ = 100002; }
   | TIMESTAMP { $$ = 100003; }
   | DATETIME { $$ = 100004; }
   | YEAR { $$ = 100005; }
   | CHAR opt_length opt_csc { $$ = 120000 + $2; }
   | BINARY opt_length { $$ = 140000 + $2; }
   | VARBINARY '(' INTNUM ')' { $$ = 150000 + $3; }
   | TINYBLOB { $$ = 160001; }
   | BLOB { $$ = 160002; }
   | MEDIUMBLOB { $$ = 160003; }
   | LONGBLOB { $$ = 160004; }
   | TINYTEXT opt_binary opt_csc { $$ = 170000 + $2; }
   | TEXT opt_binary opt_csc { $$ = 171000 + $2; }
   | MEDIUMTEXT opt_binary opt_csc { $$ = 172000 + $2; }
   | LONGTEXT opt_binary opt_csc { $$ = 173000 + $2; }
   | ENUM '(' enum_list ')' opt_csc { $$ = 200000 + $3; }
   | SET '(' enum_list ')' opt_csc { $$ = 210000 + $3; }
*/
;

enum_list: STRING { show_log("ENUMVAL %s", $1); free($1); $$ = 1; }
   | enum_list ',' STRING { show_log("ENUMVAL %s", $3); free($3); $$ = $1 + 1; }
   ;

create_select_statement: opt_ignore_replace opt_as select_stmt { show_log("CREATESELECT %d", $1); }
   ;

opt_ignore_replace: /* nil */ { $$ = 0; }
   | IGNORE { $$ = 1; }
   | REPLACE { $$ = 2; }
   ;

opt_temporary:   /* nil */ { $$ = 0; }
   | TEMPORARY { $$ = 1;}
   ;

   /**** set user variables ****/

   /** replace just like insert **/
   /* statements: select statement */

stmt: select_stmt { show_log("STMT"); }
   ;

select_stmt: SELECT select_opts select_expr_list
                        { show_log("SELECTNODATA %d %d", $2, $3); } ;
    | SELECT select_opts select_expr_list
     FROM table_references
     opt_where opt_groupby opt_having opt_orderby opt_limit
     opt_into_list { show_log("SELECT %d %d %d", $2, $3, $5); } ;
;

opt_where: /* nil */ 
   | WHERE expr { show_log("WHERE"); };

opt_groupby: /* nil */ 
   | GROUP BY groupby_list opt_with_rollup
                             { show_log("GROUPBYLIST %d %d", $3, $4); }
;

groupby_list: expr opt_asc_desc
                             { show_log("GROUPBY %d",  $2); $$ = 1; }
   | groupby_list ',' expr opt_asc_desc
                             { show_log("GROUPBY %d",  $4); $$ = $1 + 1; }
   ;

opt_asc_desc: /* nil */ { $$ = 0; }
   | ASC                { $$ = 0; }
   | DESC               { $$ = 1; }
    ;

opt_with_rollup: /* nil */  { $$ = 0; }
   | WITH ROLLUP  { $$ = 1; }
   ;

opt_having: /* nil */ | HAVING expr { show_log("HAVING"); };

opt_orderby: /* nil */ | ORDER BY groupby_list { show_log("ORDERBY %d", $3); }
   ;

opt_limit: /* nil */ | LIMIT expr { show_log("LIMIT 1"); }
  | LIMIT expr ',' expr             { show_log("LIMIT 2"); }
  ; 

opt_into_list: /* nil */ 
   | INTO column_list { show_log("INTO %d", $2); }
   ;

column_list: NAME { show_log("COLUMN %s", $1); $$ = sql_col_list_node_create($1, NULL, true); }
  | column_list ',' NAME  { $$ = sql_col_list_node_create($3, $1, false);show_log("COLUMN %s", $3); free($3); }
  ;

select_opts:                          { $$ = 0; }
| select_opts ALL                 { if($$ & 01) yyerror("duplicate ALL option"); $$ = $1 | 01; }
| select_opts DISTINCT            { if($$ & 02) yyerror("duplicate DISTINCT option"); $$ = $1 | 02; }
| select_opts DISTINCTROW         { if($$ & 04) yyerror("duplicate DISTINCTROW option"); $$ = $1 | 04; }
| select_opts HIGH_PRIORITY       { if($$ & 010) yyerror("duplicate HIGH_PRIORITY option"); $$ = $1 | 010; }
| select_opts STRAIGHT_JOIN       { if($$ & 020) yyerror("duplicate STRAIGHT_JOIN option"); $$ = $1 | 020; }
| select_opts SQL_SMALL_RESULT    { if($$ & 040) yyerror("duplicate SQL_SMALL_RESULT option"); $$ = $1 | 040; }
| select_opts SQL_BIG_RESULT      { if($$ & 0100) yyerror("duplicate SQL_BIG_RESULT option"); $$ = $1 | 0100; }
| select_opts SQL_CALC_FOUND_ROWS { if($$ & 0200) yyerror("duplicate SQL_CALC_FOUND_ROWS option"); $$ = $1 | 0200; }
    ;

select_expr_list: select_expr { $$ = 1; }
    | select_expr_list ',' select_expr {$$ = $1 + 1; }
    | '*' { show_log("SELECTALL"); $$ = 1; }
    ;

select_expr: expr opt_as_alias ;

table_references:    table_reference { $$ = 1; }
    | table_references ',' table_reference { $$ = $1 + 1; }
    ;

table_reference:  table_factor
  | join_table
;

table_factor:
    NAME opt_as_alias index_hint { show_log("TABLE %s", $1); free($1); }
  | NAME '.' NAME opt_as_alias index_hint { show_log("TABLE %s.%s", $1, $3);
                               free($1); free($3); }
  | table_subquery opt_as NAME { show_log("SUBQUERYAS %s", $3); free($3); }
  | '(' table_references ')' { show_log("TABLEREFERENCES %d", $2); }
  ;

opt_as: AS 
  | /* nil */
  ;

opt_as_alias: AS NAME { show_log ("ALIAS %s", $2); free($2); }
  | NAME              { show_log ("ALIAS %s", $1); free($1); }
  | /* nil */
  ;

join_table:
    table_reference opt_inner_cross JOIN table_factor opt_join_condition
                  { show_log("JOIN %d", 0100+$2); }
  | table_reference STRAIGHT_JOIN table_factor
                  { show_log("JOIN %d", 0200); }
  | table_reference STRAIGHT_JOIN table_factor ON expr
                  { show_log("JOIN %d", 0200); }
  | table_reference left_or_right opt_outer JOIN table_factor join_condition
                  { show_log("JOIN %d", 0300+$2+$3); }
  | table_reference NATURAL opt_left_or_right_outer JOIN table_factor
                  { show_log("JOIN %d", 0400+$3); }
  ;

opt_inner_cross: /* nil */ { $$ = 0; }
   | INNER { $$ = 1; }
   | CROSS  { $$ = 2; }
;

opt_outer: /* nil */  { $$ = 0; }
   | OUTER {$$ = 4; }
   ;

left_or_right: LEFT { $$ = 1; }
    | RIGHT { $$ = 2; }
    ;

opt_left_or_right_outer: LEFT opt_outer { $$ = 1 + $2; }
   | RIGHT opt_outer  { $$ = 2 + $2; }
   | /* nil */ { $$ = 0; }
   ;

opt_join_condition: join_condition | /* nil */ ;

join_condition:
    ON expr { show_log("ONEXPR"); }
    | USING '(' column_list ')' { show_log("USING %d", $3); }
    ;

index_hint:
     USE KEY opt_for_join '(' index_list ')'
                  { show_log("INDEXHINT %d %d", $5, 010+$3); }
   | IGNORE KEY opt_for_join '(' index_list ')'
                  { show_log("INDEXHINT %d %d", $5, 020+$3); }
   | FORCE KEY opt_for_join '(' index_list ')'
                  { show_log("INDEXHINT %d %d", $5, 030+$3); }
   | /* nil */
   ;

opt_for_join: FOR JOIN { $$ = 1; }
   | /* nil */ { $$ = 0; }
   ;

index_list: NAME  { show_log("INDEX %s", $1); free($1); $$ = 1; }
   | index_list ',' NAME { show_log("INDEX %s", $3); free($3); $$ = $1 + 1; }
   ;

table_subquery: '(' select_stmt ')' { show_log("SUBQUERY"); }
   ;

   /* statements: delete statement */

stmt: delete_stmt { show_log("STMT"); }
   ;

delete_stmt: DELETE delete_opts FROM NAME
    opt_where opt_orderby opt_limit
                  { show_log("DELETEONE %d %s", $2, $4); free($4); }
;

delete_opts: delete_opts LOW_PRIORITY { $$ = $1 + 01; }
   | delete_opts QUICK { $$ = $1 + 02; }
   | delete_opts IGNORE { $$ = $1 + 04; }
   | /* nil */ { $$ = 0; }
   ;

delete_stmt: DELETE delete_opts
    delete_list
    FROM table_references opt_where
            { show_log("DELETEMULTI %d %d %d", $2, $3, $5); }

delete_list: NAME opt_dot_star { show_log("TABLE %s", $1); free($1); $$ = 1; }
   | delete_list ',' NAME opt_dot_star
            { show_log("TABLE %s", $3); free($3); $$ = $1 + 1; }
   ;

opt_dot_star: /* nil */ | '.' '*' ;

delete_stmt: DELETE delete_opts
    FROM delete_list
    USING table_references opt_where
            { show_log("DELETEMULTI %d %d %d", $2, $4, $6); }
;

stmt: replace_stmt { show_log("STMT"); }
   ;

replace_stmt: REPLACE insert_opts opt_into NAME
     opt_col_names
     VALUES insert_vals_list
     opt_ondupupdate { show_log("REPLACEVALS %d %d %s", $2, $7, $4); free($4); }
   ;

replace_stmt: REPLACE insert_opts opt_into NAME
    SET insert_asgn_list
    opt_ondupupdate
     { show_log("REPLACEASGN %d %d %s", $2, $6, $4); free($4); }
   ;

replace_stmt: REPLACE insert_opts opt_into NAME opt_col_names
    select_stmt
    opt_ondupupdate { show_log("REPLACESELECT %d %s", $2, $4); free($4); }
  ;

/** update **/
stmt: update_stmt { show_log("STMT"); }
   ;

update_stmt: UPDATE update_opts table_references
    SET update_asgn_list
    opt_where
    opt_orderby
opt_limit { show_log("UPDATE %d %d %d", $2, $3, $5); }
;

update_opts: /* nil */ { $$ = 0; }
   | insert_opts LOW_PRIORITY { $$ = $1 | 01 ; }
   | insert_opts IGNORE { $$ = $1 | 010 ; }
   ;

update_asgn_list:
     NAME COMPARISON expr 
       { if ($2 != 4) yyerror("bad insert assignment to %s", $1);
	 show_log("ASSIGN %s", $1); free($1); $$ = 1; }
   | NAME '.' NAME COMPARISON expr 
       { if ($4 != 4) yyerror("bad insert assignment to %s", $1);
	 show_log("ASSIGN %s.%s", $1, $3); free($1); free($3); $$ = 1; }
   | update_asgn_list ',' NAME COMPARISON expr
       { if ($4 != 4) yyerror("bad insert assignment to %s", $3);
	 show_log("ASSIGN %s.%s", $3); free($3); $$ = $1 + 1; }
   | update_asgn_list ',' NAME '.' NAME COMPARISON expr
       { if ($6 != 4) yyerror("bad insert assignment to %s.$s", $3, $5);
	 show_log("ASSIGN %s.%s", $3, $5); free($3); free($5); $$ = 1; }
   ;


   /** create database **/

stmt: create_database_stmt { show_log("STMT"); }
   ;

create_database_stmt: 
     CREATE DATABASE opt_if_not_exists NAME { show_log("CREATEDATABASE %d %s", $3, $4); free($4); }
   | CREATE SCHEMA opt_if_not_exists NAME { show_log("CREATEDATABASE %d %s", $3, $4); free($4); }
   ;

opt_if_not_exists:  /* nil */ { $$ = 0; }
   | IF EXISTS           { if(!$2)yyerror("IF EXISTS doesn't exist");
                        $$ = $2; /* NOT EXISTS hack */ }
   ;


stmt: set_stmt { show_log("STMT"); }
   ;

set_stmt: SET set_list ;

set_list: set_expr | set_list ',' set_expr ;

set_expr:
      USERVAR COMPARISON expr { if ($2 != 4) yyerror("bad set to @%s", $1);
		 show_log("SET %s", $1); free($1); }
    | USERVAR ASSIGN expr { show_log("SET %s", $1); free($1); }
    ;

   /**** expressions ****/

expr: NAME          { $$ = sql_expr_basic_data_node_create(DATA_TYPE_NAME, 0, $1);show_log("NAME %s", $1); free($1); }
   | USERVAR         { show_log("USERVAR %s", $1); free($1); }
   | NAME '.' NAME { show_log("FIELDNAME %s.%s", $1, $3); free($1); free($3); }
   | STRING        { $$ = sql_expr_basic_data_node_create(DATA_TYPE_VARCHAR, 0, $1); show_log("STRING %s", $1); free($1); }
   | INTNUM        { $$ = sql_expr_basic_data_node_create(DATA_TYPE_INT, $1, NULL); show_log("NUMBER %d", $1); }
   | APPROXNUM     { show_log("FLOAT %g", $1); }
   | BOOL          { show_log("BOOL %d", $1); }
   ;

expr: expr '+' expr { show_log("ADD"); }
   | expr '-' expr { show_log("SUB"); }
   | expr '*' expr { show_log("MUL"); }
   | expr '/' expr { show_log("DIV"); }
   | expr '%' expr { show_log("MOD"); }
   | expr MOD expr { show_log("MOD"); }
   | '-' expr %prec UMINUS { show_log("NEG"); }
   | expr ANDOP expr { show_log("AND"); }
   | expr OR expr { show_log("OR"); }
   | expr XOR expr { show_log("XOR"); }
   | expr COMPARISON expr { show_log("CMP %d", $2); }
   | expr COMPARISON '(' select_stmt ')' { show_log("CMPSELECT %d", $2); }
   | expr COMPARISON ANY '(' select_stmt ')' { show_log("CMPANYSELECT %d", $2); }
   | expr COMPARISON SOME '(' select_stmt ')' { show_log("CMPANYSELECT %d", $2); }
   | expr COMPARISON ALL '(' select_stmt ')' { show_log("CMPALLSELECT %d", $2); }
   | expr '|' expr { show_log("BITOR"); }
   | expr '&' expr { show_log("BITAND"); }
   | expr '^' expr { show_log("BITXOR"); }
   | expr SHIFT expr { show_log("SHIFT %s", $2==1?"left":"right"); }
   | NOT expr { show_log("NOT"); }
   | '!' expr { show_log("NOT"); }
   | USERVAR ASSIGN expr { show_log("ASSIGN @%s", $1); free($1); }
   ;    

expr:  expr IS NULLX     { show_log("ISNULL"); }
   |   expr IS NOT NULLX { show_log("ISNULL"); show_log("NOT"); }
   |   expr IS BOOL      { show_log("ISBOOL %d", $3); }
   |   expr IS NOT BOOL  { show_log("ISBOOL %d", $4); show_log("NOT"); }
   ;

expr: expr BETWEEN expr AND expr %prec BETWEEN { show_log("BETWEEN"); }
   ;


val_list: expr { $$ = 1; }
   | expr ',' val_list { $$ = 1 + $3; }
   ;

opt_val_list: /* nil */ { $$ = 0; }
   | val_list
   ;

expr: expr IN '(' val_list ')'       { show_log("ISIN %d", $4); }
   | expr NOT IN '(' val_list ')'    { show_log("ISIN %d", $5); show_log("NOT"); }
   | expr IN '(' select_stmt ')'     { show_log("INSELECT"); }
   | expr NOT IN '(' select_stmt ')' { show_log("INSELECT"); show_log("NOT"); }
   | EXISTS '(' select_stmt ')'      { show_log("EXISTS"); if($1)show_log("NOT"); }
   ;

expr: NAME '(' opt_val_list ')' {  show_log("CALL %d %s", $3, $1); free($1); }
   ;

  /* functions with special syntax */
expr: FCOUNT '(' '*' ')' { show_log("COUNTALL"); }
   | FCOUNT '(' expr ')' { show_log(" CALL 1 COUNT"); } 

expr: FSUBSTRING '(' val_list ')' {  show_log("CALL %d SUBSTR", $3);}
   | FSUBSTRING '(' expr FROM expr ')' {  show_log("CALL 2 SUBSTR"); }
   | FSUBSTRING '(' expr FROM expr FOR expr ')' {  show_log("CALL 3 SUBSTR"); }
| FTRIM '(' val_list ')' { show_log("CALL %d TRIM", $3); }
   | FTRIM '(' trim_ltb expr FROM val_list ')' { show_log("CALL 3 TRIM"); }
   ;

trim_ltb: LEADING { show_log("INT 1"); }
   | TRAILING { show_log("INT 2"); }
   | BOTH { show_log("INT 3"); }
   ;

expr: FDATE_ADD '(' expr ',' interval_exp ')' { show_log("CALL 3 DATE_ADD"); }
   |  FDATE_SUB '(' expr ',' interval_exp ')' { show_log("CALL 3 DATE_SUB"); }
   ;

interval_exp: INTERVAL expr DAY_HOUR { show_log("NUMBER 1"); }
   | INTERVAL expr DAY_MICROSECOND { show_log("NUMBER 2"); }
   | INTERVAL expr DAY_MINUTE { show_log("NUMBER 3"); }
   | INTERVAL expr DAY_SECOND { show_log("NUMBER 4"); }
   | INTERVAL expr YEAR_MONTH { show_log("NUMBER 5"); }
   | INTERVAL expr YEAR       { show_log("NUMBER 6"); }
   | INTERVAL expr HOUR_MICROSECOND { show_log("NUMBER 7"); }
   | INTERVAL expr HOUR_MINUTE { show_log("NUMBER 8"); }
   | INTERVAL expr HOUR_SECOND { show_log("NUMBER 9"); }
   ;

expr: CASE expr case_list END           { show_log("CASEVAL %d 0", $3); }
   |  CASE expr case_list ELSE expr END { show_log("CASEVAL %d 1", $3); }
   |  CASE case_list END                { show_log("CASE %d 0", $2); }
   |  CASE case_list ELSE expr END      { show_log("CASE %d 1", $2); }
   ;

case_list: WHEN expr THEN expr     { $$ = 1; }
         | case_list WHEN expr THEN expr { $$ = $1+1; } 
   ;

expr: expr LIKE expr { show_log("LIKE"); }
   | expr NOT LIKE expr { show_log("LIKE"); show_log("NOT"); }
   ;

expr: expr REGEXP expr { show_log("REGEXP"); }
   | expr NOT REGEXP expr { show_log("REGEXP"); show_log("NOT"); }
   ;

expr: CURRENT_TIMESTAMP { show_log("NOW"); }
   | CURRENT_DATE	{ show_log("NOW");}
   | CURRENT_TIME	{ show_log("NOW"); };
   ;

expr: BINARY expr %prec UMINUS { show_log("STRTOBIN"); }
   ;

%%
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
  extern int yylineno;

  va_list ap;
  va_start(ap, s);

  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
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
  if(ac > 1 && !strcmp(av[1], "-d")) {
    yydebug = 1; ac--; av++;
  }

  if(ac > 1 && (yyin = fopen(av[1], "r")) == NULL) {
    perror(av[1]);
    exit(1);
  }
  while (1) {
  if(!yyparse())
    printf("SQL parse worked\n");
  else {
        printf("SQL parse failed\n");
        yyrestart(yyin);
    }
  }
} /* main */
