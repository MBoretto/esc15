#
#  USAGE:
#     make          ... to build the program
#     make test     ... to run the default test case
#

include make.def

EXES=hello$(EXE) pi$(EXE) pi_recur$(EXE) mandel$(EXE)  \
         mm_testbed$(EXE) jac_solv$(EXE) stencil$(EXE)  

MM_OBJS  = mm_testbed.$(OBJ) mm_utils.$(OBJ) mm_ijk.$(OBJ) mm_tst_cases.$(OBJ)

STN_OBJS  = stencil.$(OBJ)  

JAC_OBJS  = jac_solv.$(OBJ) mm_utils.$(OBJ) 

all: $(EXES)

jac_solv$(EXE): $(JAC_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o jac_solv$(EXE) $(JAC_OBJS) $(LIBS)

mm_testbed$(EXE): $(MM_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o mm_testbed$(EXE) $(MM_OBJS) $(LIBS)

hello$(EXE): hello.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o hello hello.$(OBJ) $(LIBS)

pi$(EXE): pi.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o pi pi.$(OBJ) $(LIBS)

pi_recur$(EXE): pi_recur.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o pi_recur pi_recur.$(OBJ) $(LIBS)

mandel$(EXE):  mandel.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o mandel mandel.$(OBJ) $(LIBS)

stencil$(EXE): $(STN_OBJS) 
	$(CLINKER) $(CFLAGS) -o stencil$(EXE) $(STN_OBJS) $(LIBS)

test: $(EXES)
	for i in $(EXES); do \
            $(PRE)$$i; \
        done

clean:
	$(RM) $(EXES) *.$(OBJ)

.SUFFIXES:
.SUFFIXES: .c .cpp .$(OBJ)

.c.$(OBJ):
	$(CC) $(CFLAGS) -c $<

.cpp.$(OBJ):
	$(CC) $(CFLAGS) -c $<
