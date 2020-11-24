EXE		=
LIB		= .a
OBJ		= .o

MAKE		= make
AR		= ar
ARFLAGS		= -ruv
CAT		= cat
CCS		= gcc
CCP		= /home/mpich-install/bin/mpicc
CCD		= /home/mpich-install/bin/mpicc
#CCD		= my_sequential_cc -I/home/mpich-install/include
CFLAGS		= -O3 -DCOMMON_FILE_COMPRESS_GZ -DCOMMON_PTHREAD -DCOMMON_RANDOM_FIXED_SEED -DSCOTCH_RENAME -DSCOTCH_PTHREAD -Drestrict=__restrict -DIDXSIZE64 -DINTSIZE64
CLIBFLAGS	=
LDFLAGS		= -lz -lm -lrt -pthread
CP		= cp
LEX		= flex -Pscotchyy -olex.yy.c
LN		= ln
MKDIR		= mkdir
MV		= mv
RANLIB		= ranlib
YACC		= bison -pscotchyy -y -b y
