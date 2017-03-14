


CC = cc -g
LEX = flex
YACC = bison
CFLAGS = -DYYDEBUG=1

ifeq ($(strip $(LOG_TO_FILE)),1)
    LOG_TO_FILE_FLAGS = -DLOG_TO_FILE
    CFLAGS += $(LOG_TO_FILE_FLAGS)
    LDFLAGS += $(LOG_TO_FILE_FLAGS) 
endif

EXE = hltsql

OBJ := pmysql.tab.o pmysql.o sql_action.o
all: $(EXE)


$(EXE): $(OBJ)
	${CC} -o $@ pmysql.tab.o pmysql.o sql_action.o

pmysql.tab.c pmysql.tab.h: pmysql.y
	${YACC} -vd --debug pmysql.y

pmysql.c: pmysql.l
	${LEX} -o $@ $<

pmysql.o: pmysql.c pmysql.tab.h

sql_action.o: sql_action.c node.h


clean:
	rm -f pmysql pmysql.tab.c pmysql.tab.h pmysql.c pmysql.tab.o pmysql.o \
	lpmysql	lpmysql.tab.o lpmysql.o lpmysql.tab.c lpmysql.tab.h lpmysql.c \
	glrmysql glrmysql.tab.o glrmysql.o glrmysql.tab.c glrmysql.tab.h \
	glrmysql.c glrmysql.output lpmysql.output pmysql.output

.SUFFIXES:	.l .y .c

