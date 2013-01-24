###############################################################################

SRC_CXX=Etudiant.cc
MAIN_CXX=main.cc
GST_CXX=gestion.cc


BIN_CXX=$(MAIN_CXX:.cc=)

CXX=g++
LDXX=g++

#------- Mettre en commentaires l'une des deux lignes suivantes --------------
#OPT_TRACE=
OPT_TRACE=-DTRACE_LISTE

###############################################################################

OBJ_CXX=$(SRC_CXX:.cc=.o)
MAIN_OBJ_CXX=$(MAIN_CXX:.cc=.o)
GST_OBJ=$(GST_CXX:.cc=.o)
ALL_OBJ_CXX=$(OBJ_CXX) $(MAIN_OBJ_CXX) $(GST_OBJ)

all: cxx-binaries
	@echo --- fini

cxx-binaries: $(BIN_CXX)

main: main.o $(OBJ_CXX) $(GST_OBJ)
	@echo --- Making $@
	@$(LDXX) $(LDXXFLAGS) $(OBJ_CXX) $< -o $@
	


%.o: %.cc
	@echo ----- Compiling $<
	@$(CXX) $(CXXFLAGS) $(OPT_TRACE) -c $<

clean:
	$(RM) $(BIN_CXX) $(ALL_OBJ_CXX) *~

