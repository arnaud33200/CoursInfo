###############################################################################
SRC_CXX=
MAIN_CXX=main.cc

BIN_CXX=$(MAIN_CXX:.cc=)

CXX=g++

###############################################################################

OBJ_CXX=$(SRC_CXX:.cc=.o)
MAIN_OBJ_CXX=$(MAIN_CXX:.cc=.o)
ALL_OBJ_CXX=$(OBJ_CXX) $(MAIN_OBJ_CXX)

all: cxx-binaries
	@echo --- fini

cxx-binaries: $(BIN_CXX)

main: main.o $(OBJ_CXX)
	@echo --- Making $@
	@$(CXX) $(OBJ_CXX) $< -o $@

%.o: %.cc
	@echo ----- Compiling $<
	@$(CXX) $(CXXFLAGS) $(OPT_TRACE) -c $<

clean:
	$(RM) $(BIN_CXX) $(ALL_OBJ_CXX) *~

