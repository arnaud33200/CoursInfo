#~ ###############################################################################
#~ SRC_CXX=Pile.cxx
#~ MAIN_CXX=main.cc
#~ 
#~ BIN_CXX=$(MAIN_CXX:.cc=)
#~ 
#~ CXX=g++
#~ 
#~ ###############################################################################
#~ 
#~ OBJ_CXX=$(SRC_CXX:.cc=.o)
#~ MAIN_OBJ_CXX=$(MAIN_CXX:.cc=.o)
#~ ALL_OBJ_CXX=$(OBJ_CXX) $(MAIN_OBJ_CXX)
#~ 
#~ all: cxx-binaries
	#~ @echo --- fini
#~ 
#~ cxx-binaries: $(BIN_CXX)
#~ 
#~ main: main.o $(OBJ_CXX)
	#~ @echo --- Making $@
	#~ @$(CXX) $(OBJ_CXX) $< -o $@
#~ 
#~ %.o: %.cc
	#~ @echo ----- Compiling $<
	#~ @$(CXX) $(CXXFLAGS) $(OPT_TRACE) -c $<
	
gestionPile: main.o Pile.o
	g++ $^ -o $@
	
main.o: main.cc Pile.h
	g++ -c $<

Pile.o: Pile.cxx Pile.h
	g++ -c $<

clean:
	$(RM) $(BIN_CXX) $(ALL_OBJ_CXX) *~

