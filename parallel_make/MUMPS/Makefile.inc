#  This file is part of MUMPS 5.0.2, released
#  on Fri Jul 15 09:12:54 UTC 2016
#
#Begin orderings

# NOTE that PORD is distributed within MUMPS by default. If you would like to
# use other orderings, you need to obtain the corresponding package and modify
# the variables below accordingly.
# For example, to have Metis available within MUMPS:
#          1/ download Metis and compile it
#          2/ uncomment (suppress # in first column) lines
#             starting with LMETISDIR,  LMETIS
#          3/ add -Dmetis in line ORDERINGSF
#             ORDERINGSF  = -Dpord -Dmetis
#          4/ Compile and install MUMPS
#             make clean; make   (to clean up previous installation)
#
#          Metis/ParMetis and SCOTCH/PT-SCOTCH (ver 6.0 and later) orderings are now available for MUMPS.
#

SCOTCHDIR  = /home/Parallel/scotch
ISCOTCH    = -I$(SCOTCHDIR)/include  # Should be provided for pt-scotch (not needed for Scotch)
#
# You have to choose one among the following two lines depending on
# the type of analysis you want to perform. If you want to perform only
# sequential analysis choose the first (remember to add -Dscotch in the ORDERINGSF
# variable below); for both parallel and sequential analysis choose the second 
# line (remember to add -Dptscotch in the ORDERINGSF variable below)

LSCOTCH    = -L$(SCOTCHDIR)/lib -lptesmumps -lptscotch -lptscotcherr -lscotch


LPORDDIR = $(topdir)/PORD/lib/
IPORD    = -I$(topdir)/PORD/include/
LPORD    = -L$(LPORDDIR) -lpord

LMETISDIR = /home/Parallel/parmetis/metis
IMETIS    = $(LMETISDIR)/include # should be provided if you use parmetis, to access parmetis.h

LPARMETISDIR = /home/Parallel/parmetis
IPARMETIS    = $(LPARMETISDIR)/include

# You have to choose one among the following two lines depending on
# the type of analysis you want to perform. If you want to perform only
# sequential analysis choose the first (remember to add -Dmetis in the ORDERINGSF
# variable below); for both parallel and sequential analysis choose the second 
# line (remember to add -Dparmetis in the ORDERINGSF variable below)

LMETIS    = -L$(LMETISDIR)/lib -lmetis
LPARMETIS = -L$(LPARMETISDIR)/lib -lparmetis

# The following variables will be used in the compilation process.
# Please note that -Dptscotch and -Dparmetis imply -Dscotch and -Dmetis respectively.
ORDERINGSF = -Dscotch -Dmetis -Dpord -Dptscotch -Dparmetis
ORDERINGSC  = $(ORDERINGSF)

LORDERINGS = $(LPARMETIS) $(LMETIS) $(LPORD) $(LSCOTCH)
IORDERINGSF = $(ISCOTCH)
IORDERINGSC = $(IPARMETIS) $(IMETIS) $(IPORD) $(ISCOTCH)

#End orderings
########################################################################
################################################################################

PLAT    =
LIBEXT  = .a
OUTC    = -o 
OUTF    = -o 
RM = /bin/rm -f
CC      = /home/mpich-install/bin/mpicc
FC      = /home/mpich-install/bin/mpif90
FL      = /home/mpich-install/bin/mpif90
AR = ar vr 
#RANLIB = ranlib
RANLIB  = echo

INCPAR  = -L/home/mpich-install/include

# scaLAPACK library
LIBPAR = /home/Parallel/scalapack/libscalapack.a /home/Parallel/mpiblacs/BLACS/LIB/blacs_MPI-LINUX-0.a /home/Parallel/mpiblacs/BLACS/LIB/blacsCinit_MPI-LINUX-0.a /home/Parallel/mpiblacs/BLACS/LIB/blacs_MPI-LINUX-0.a /home/Parallel/mpiblacs/BLACS/LIB/blacsF77init_MPI-LINUX-0.a /home/Parallel/mpiblacs/BLACS/LIB/blacs_MPI-LINUX-0.a /home/Parallel/lapack/liblapack.a -L/home/mpich-install/lib -lmpi -lmpifort

# Intel MKL library
# LIBPAR =  $(MKLROOT)/lib/intel64/libmkl_blas95_ilp64.a $(MKLROOT)/lib/intel64/libmkl_lapack95_ilp64.a \
        -L$(MKLROOT)/lib/intel64 -lmkl_scalapack_ilp64 -lmkl_intel_ilp64 -lmkl_sequential -lmkl_core \
        -lmkl_blacs_intelmpi_ilp64 -lpthread -lm -ldl

LIBBLAS = /home/Parallel/blas/BLAS-3.8.0/blas_LINUX.a 

#Preprocessor defs for calling Fortran from C (-DAdd_ or -DAdd__ or -DUPPER)
CDEFS   = -DAdd_

#Begin Optimized options
OPTF    = -O -DALLOW_NON_INIT -fopenmp # or -qopenmp for most recent compilers
OPTL    = -O -fopenmp
OPTC    = -O -fopenmp
#End Optimized options
INCS = $(INCPAR)
LIBS = $(LIBPAR)
LIBSEQNEEDED =


