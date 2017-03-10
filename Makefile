# $Header: /home/johnl/flnb/code/sql/RCS/Makefile,v 2.1 2009/11/08 02:53:39 johnl Exp $
# Companion source code for "flex & bison", published by O'Reilly
# Media, ISBN 978-0-596-15597-1
# Copyright (c) 2009, Taughannock Networks. All rights reserved.
# See the README file for license conditions and contact info.

CC = cc -g
LEX = flex
YACC = bison
CFLAGS = -DYYDEBUG=1

PROGRAMS4 = pmysql
#PROGRAMS8 = lpmysql
#PROGRAMS9 = glrmysql

all:	${PROGRAMS4}

# chapter 4

pmysql:	pmysql.tab.o pmysql.o  sql_action.o
	${CC} -o $@ pmysql.tab.o pmysql.o sql_action.o

pmysql.tab.c pmysql.tab.h:	pmysql.y
	${YACC} -vd --debug pmysql.y

pmysql.c:	pmysql.l
	${LEX} -o $@ $<

pmysql.o:	pmysql.c pmysql.tab.h

sql_action.o: sql_action.c node.h
# chapter 8


clean:
	rm -f pmysql pmysql.tab.c pmysql.tab.h pmysql.c pmysql.tab.o pmysql.o \
	lpmysql	lpmysql.tab.o lpmysql.o lpmysql.tab.c lpmysql.tab.h lpmysql.c \
	glrmysql glrmysql.tab.o glrmysql.o glrmysql.tab.c glrmysql.tab.h \
	glrmysql.c glrmysql.output lpmysql.output pmysql.output

.SUFFIXES:	.l .y .c

