CXX = g++
source = Element.cc Button.cc Slider.cc Unite.cc Cellule.cc Virus.cc GrilleCellule.cc GroupeVirus.cc image.cc main.cc util.cc event.cc enum.cc GameModel.cc GameSave.cc GameView.cc MenuView.cc Intro.cc 
LDXXFLAGS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
objet = $(source:.cc=.o)

#########################################################

../jeuDeLaVie : $(objet)
	@ echo " "
	@ echo \"JEU DE LA VIE\" CREATED !
	@$(CXX) $(LDXXFLAGS) $^ -o $@

Element.o : Element.cc Element.h
	@echo - ELEMENT OBJECTS :
	@$(CXX) -c $<

Button.o : Button.cc Button.h image.h Element.h
	@echo "~~~~~~~ BUTTON"
	@$(CXX) -c $<
			

Slider.o : Slider.cc Slider.h Element.h image.h util.h
	@echo "~~~~~~~ SLIDER"
	@$(CXX) -c $<

Unite.o : Unite.cc Unite.h
	@ echo - UNITE OBJECTS :
	@$(CXX) -c $< 		

Cellule.o : Cellule.cc Cellule.h Unite.h enum.h util.h
	@echo "~~~~~~~ CELLULE"
	@$(CXX) -c  $<
	
Virus.o : Virus.cc Virus.h Unite.h util.h
	@echo "~~~~~~~ VIRUS"
	@$(CXX) -c $<

GrilleCellule.o : GrilleCellule.cc GrilleCellule.h Cellule.h Unite.h enum.h util.h
	@echo "~~~~~~~ GRILLE CELLULE"
	@$(CXX) -c $<

GroupeVirus.o : GroupeVirus.cc GroupeVirus.h Virus.h
	@echo "~~~~~~~ GROUPE VIRUS"
	@$(CXX) -c $<

util.o : util.cc util.h enum.h
	@ echo - UTIL FONCTIONS 
	@$(CXX) -c $<
	
image.o : image.cc image.h enum.h Element.h Button.h Slider.h Unite.h Element.h GameModel.h
	@echo "~~~~~~~ IMAGE"
	@$(CXX) -c $<

event.o : event.cc event.h Button.h Element.h Slider.h
	@echo "~~~~~~~ EVENT"
	@$(CXX) -c $<
	
enum.o : enum.cc enum.h
	@echo "~~~~~~~ ENUM"
	@$(CXX) -c $<

GameModel.o : GameModel.cc GameModel.h GameSave.h Unite.h GrilleCellule.h GroupeVirus.h enum.h event.h
	@echo - CONTROL / VIEW OBJECTS
	@echo "~~~~~~~ GAMEMODEL"
	@$(CXX) -c $<

GameSave.o : GameSave.cc GameSave.h GrilleCellule.h GroupeVirus.h
	@echo "~~~~~~~ GAMESAVE"
	@$(CXX) -c $<

GameView.o : GameView.cc GameView.h GameModel.h MenuView.h Element.h Button.h image.h util.h event.h
	@echo "~~~~~~~ GAMEVIEW"
	@$(CXX) -c $<

main.o : main.cc GameModel.h GameView.h MenuView.h util.h Intro.h
	@echo "~~~~~~~ MAIN"
	@$(CXX) -c $<

MenuView.o : MenuView.cc MenuView.h image.h Element.h Button.h Slider.h GameModel.h event.h
	@echo "~~~~~~~ MENUVIEW"
	@$(CXX) -c $<
	
Intro.o : Intro.cc Intro.h Button.h event.h image.h
	@$(CXX) -c $<


########### CLEAN ###########

clean : 
	@rm -f *~ *.o
	@echo -- ALL FILES .O ARE REMOVED
	@ echo " "

########### MRPROPER ###########

mrproper : 
	@rm -f *~ *.o ../jeuDeLaVie
	@echo -- ALL FILES .O AND EXE ARE REMOVED
	@ echo " "

########### OPEN ###########

open : 
	geany *.cc *.h Makefile &

########### DOC ############

doc :
	doxygen Doxyfile
	@cd ../doc/latex && make
	@cd ../doc/ && mv latex/refman.pdf Doc-JeuDeLaVie.pdf
	
	

	
