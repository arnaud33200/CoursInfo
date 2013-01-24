CXX=g++
CXXFLAGS= -g -Wall -pedantic
LDFLAGS= -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
EXEC = editeur
EXECPATH = .
OBJ  = main.o GameModel.o GameView.o tile.o MenuView.o Button.o Element.o image.o event.o

all: $(EXEC)

editeur: $(OBJ)
	@echo "COMPILATION DE L'EDITEUR"
	@$(CXX) -o $(EXECPATH)/$@ $(OBJ) $(LDFLAGS)

main.o: main.cpp GameView.h GameModel.h
	@echo " ~~~~~~~~~ création de l'objet main"
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

tile.o: tile.cc tile.h
	@echo " ~~~~~~~~~ création de l'objet tile"
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

GameView.o: GameView.cc GameView.h
	@echo " ~~~~~~~~~ création de l'objet GameView"
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

GameModel.o: GameModel.cc GameModel.h
	@echo " ~~~~~~~~~ création de l'objet GameModel"
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

Button.o: Button.cc Button.h
	@echo " ~~~~~~~~~ création de l'objet Button"
	@$(CXX) -o $@ -c $< $(CXXFLAGS)
	
MenuView.o: MenuView.cc MenuView.h
	@echo " ~~~~~~~~~ création de l'objet MenuView"
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

Element.o: Element.cc Element.h
	@echo " ~~~~~~~~~ création de l'objet Element"
	@$(CXX) -o $@ -c $< $(CXXFLAGS)
	
image.o: image.cc image.h
	@echo " ~~~~~~~~~ création de l'objet image"
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

event.o: event.cc event.h
	@echo " ~~~~~~~~~ création de l'objet event"
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	@echo "SUPPRESSION DES FICHIERS OBJECTS"
	@rm -rf *.o

mrproper:
	@echo "SUPPRESSION DES FICHIERS OBJECTS ET EXECUTIF"
	@rm -rf *.o $(EXECPATH)/$(EXEC)
