


CC = cc -g
LEX = flex
YACC = bison
CFLAGS = -DYYDEBUG=1

ifeq ($(strip $(LOG_TO_FILE)),1)
    LOG_TO_FILE_FLAGS = -DLOG_TO_FILE
    CFLAGS += $(LOG_TO_FILE_FLAGS)
    LDFLAGS += $(LOG_TO_FILE_FLAGS) 
endif

ifeq ($(strip $(SDEBUG)),1)
    SDBG_FLAGS = -DSDEBUG
    CFLAGS += $(SDBG_FLAGS)
    LDFLAGS += $(SDBG_FLAGS) 
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
	rm -f hltsql pmysql.tab.c pmysql.tab.h pmysql.c pmysql.tab.o pmysql.o pmysql.output

.SUFFIXES:	.l .y .c

