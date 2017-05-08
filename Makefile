


CC = cc -g -O0
LEX = flex
YACC = bison
CFLAGS = -DYYDEBUG=1
CFLAGS +=-std=gnu99

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

OBJ := pmysql.tab.o pmysql.o sql_action.o dbwriter.o table.o treeIdx.o hashIdx.o cret_idx.o select_destroy.o

all: $(EXE)

$(EXE): $(OBJ)
	${CC} -o $@ $(OBJ) bplus.a -lpthread 

pmysql.tab.c pmysql.tab.h: pmysql.y
	${YACC} -vd --debug pmysql.y

pmysql.c: pmysql.l
	${LEX} -o $@ $<

pmysql.o: pmysql.c pmysql.tab.h

sql_action.o: sql_action.c node.h

dbwriter.o: dbwriter.c dbwriter.h 

treeIdx.o: treeIdx.c treeIdx.h bplus.a

hashIdx.o: hashIdx.c hashIdx.h libindex.a

cret_idx.o: cret_idx.c cret_idx.h

table.o: table.c 
	${CC} -c $< 

select_destroy.o: select_destroy.c select_destroy.h

clean:
	rm -f hltsql pmysql.tab.c pmysql.tab.h pmysql.c pmysql.tab.o pmysql.o pmysql.output sql_action.o table.o dbwriter.o treeIdx.o hashIdx.o cret_idx.o select_destroy.o

.SUFFIXES:	.l .y .c
	
