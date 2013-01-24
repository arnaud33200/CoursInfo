#!/bin/bash

# gestion des emprunts de livres 
# dans une bibliothèque

# attention, affichage en jeu de caractères ISO-LATIN-1 

# auteurs : Arnaud Ladoucette & Guillaume Dor
# groupe  : S1C




#############################################################
#
#  CONSTANTES
#
#############################################################

repertoire=EMPRUNTS
catalogue=$repertoire/catalogue.txt
emprunts=$repertoire/emprunts.txt


#############################################################
#
#  FONCTION
#
#############################################################

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# fait l'animation du debut de script
function animation_entre
{
	# creation du fichier logo.txt qui servira pour l'affichage animé
	cat > logo.txt << FIN
		 ______________________
		|                      |\\
		|     Bibliotheque     |\|
		|______________________|\|
		 \__\__\__\__\__\__\__\_\|
FIN

	echo -e "\033[01;33m" # debut couleur orange
	for i in 0 1 2 3 4 5 # selectionne les 5 morceaux d'animation
	do
		clear # efface pour laisse place à la nouvelle images
		tail -n $i logo.txt	# effet de descente 
		sleep 0.1s	# temps de pause entre les animations
	done
	
	echo -e "\033[00;00m" # fin couleur orange
	rm logo.txt # suppresion du fichier car il a un usage uniques
}

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# fait l'animation de fin de script
function animation_sortie
{
	cat > sortie.txt << FIN
                  _______________________
		 /__/__/__/__/__/__/__/_/|
		|                      |/|
		|      Aurevoir !      |/|
		|______________________|/
FIN

	echo -e "\033[33m" # debut couleur orange
	clear
	cat sortie.txt
	sleep 1.3s
	for i in 5 4 3 2 1 # selectionne les 5 morceaux d'animation
	do
		clear
		tail -n $i sortie.txt	# effet de descente 
		sleep 0.1s	# temps de pause entre les animations
	done
	echo -e "\033[00m" # fin couleur orange
	rm sortie.txt
}

# -----------------------------------------
# fonction qui permet d'enregistre dans la variable
# cptword la taille maximal du titre de livre present
# dans le catalogue
function greatersize
{
    cptword=0
    cptref=0
    while IFS=":" read ref titre auteur
    do
		if [ $(echo $titre | wc -m) -gt $cptword ]
		then
			cptword=$(echo $titre | wc -m)
		fi
		if [ $(echo $ref | wc -m) -gt $cptref ]
		then
			cptref=$(echo $ref | wc -m)
		fi	
    done < $catalogue
}


# -----------------------------------------
# efface toutes les donnees dans le dossier
# EMPRUNT
function reinitialiser
{
	echo -e "\n\033[07;31mREINITIALISER : \033[00m"
    echo "Effacer toutes les donnees o/n ?"
    read reponse
    if [ $reponse = o ]
    then
		[ -d $repertoire ] || mkdir $repertoire 
		rm -f $catalogue $emprunts
		touch $catalogue $emprunts
		echo -e "Ok Donnees effacees.\n"
    else
		echo -e "Abandon.\n"
    fi
}

# ----------------------------------------
# recharge tout les fichier texte : catalogue.txt
# et emprunts.txt avec des valeurs initials
function recharger_pour_tests
{
	echo -e "\n\033[07;31mRECHARGER DONNEES : \033[00m"
    read -p "Reinitialiser toutes les donnees o/n ? " reponse
    if [ $reponse = o ]
    then
		[ -d $repertoire ] || mkdir $repertoire 
		cat > $catalogue <<EOF
1:Fundamental Algorithms:Donald Knuth
2:Les bases de l'administration systeme:Aelen Frisch
3:Building Secure Servers:Michael D. Bauer
4:Servlets Java:Jason Hunter
5:CVS, configuration et mise en oeuvre:Fred Lepied
6:Java in a Nutshell:David Flanagan
EOF
		cat > $emprunts <<EOF
2:2010-11-03:mibillau
3:2010-12-01:fmekhald
5:2010-11-22:smoreaud
4:2011-01-01:mibillau
EOF
		echo -e "Ok. Donnees de test chargees\n"
    else
		echo -e "Abandon.\n"
    fi
}

# -----------------------------------------
# ajouter un livre au catalogue en verifiant
# qu'il n'est pas deja present
function ajouter_livre
{
	echo -e "\n\033[07;32mAJOUTER UN LIVRE : \033[00m\n"
	numero_livre=$( tail -n 1 $catalogue | cut -d ":" -f 1) # recuperation du dernier numero
	let numero_livre=numero_livre+1 # ajout + 1 pour creer un numero de livre
	read -p "nom du livre ? :  " livre
	read -p "nom de l'auteur ? :  " auteur
	if ! test=$(cut -f 2 -d ":" $catalogue | grep "$livre") # verifie si le livre n'est pas deja present
	then
		echo -e "enregistré : \033[01;33m$livre \033[00m/ \033[04;32m$auteur\033[00m ?"
		read -p "reponse (o/n) : " reponse
		if [ $reponse = o ]
		then
			echo $numero_livre:$livre:$auteur >> $catalogue # enregistre le nouveau livre dans le format du catalogue
			echo -e "ajout du livre effectue...\n"
		else
			echo -e "Abandon...\n"
		fi
	else
		echo -e "livre deja present dans le catalogue\n"
	fi
}
	
	
# -----------------------------------------
# retire un livre du catalogue
# en verifiant que le livre n'est pas deja emprunte
function retirer_livre
{
	echo -e "\n\033[07;31mRETIRER LIVRE : \033[00m"
	read -p "quel livre voulez vous retirer du catalogue ? : " recherche
	
	livre=$(cut -f 2 -d ":" $catalogue | grep -i "$recherche") # pour avoir le titre du livre precis
	ref_livre=$(cut -f 1-2 -d ":" $catalogue |grep -i "$livre" | cut -f 1 -d ":") # recuperer la reference du livre rechercher
	
	if [ $(echo $ref_livre | wc -w) = 1 ] # si la recherche concerne un unique livre
	then
		login=$( grep -i ^"$ref_livre" $emprunts | cut -f 3 -d ":") # login de l'emprunteuriu	
		if [ -z "$login" ]
		then
			echo -e "etes vous sure de vouloir retirer le livre :\n\033[01;33m$livre\033[00m ? "
			read -p "reponse (o/n) : " reponse
			if [ $reponse = o ] # confirmation de suppression
			then
				grep -vi "$ref_livre" $catalogue > tmp.txt # affichage du catalogue sans le livre cherche
				cat tmp.txt > $catalogue # enregistrement du nouveau catalogue
				rm tmp.txt
				echo -e "effacement effectue ... \n"
			else
				echo -e "Abandon...\n"
			fi
		else
			nom_entier=$(ldapsearch -x -h dagobah.iut.bx1 -b dc=iut,dc=bx1 cn=$login displayName | grep displayName: | cut -d ":" -f 2)
			echo -e "suppression annulee : livre emprunte par \033[01;36m$nom_entier\033[00m ...\n"
		fi
	elif [ $(echo $ref_livre | wc -w) -gt 1 ] # si la recherche concerne plusieur livre
	then
		echo -e "recherche pas assez precise, regardez le catalogue ... \n"
	else # si la recherche concerne aucun livre
		echo -e "livre innexistant dans le catalogue.\n"
	fi
}		
                                                                                                                                                                                                                                                                                                                                                                                                                                                                       	
		

# -----------------------------------------
# affiche le catalogue de livre
function afficher_catalogue 
{ 
    echo -e "\n\033[07;32mCATALOGUE DES LIVRES : \033[00m"
    greatersize # pour avoir la plus grand taille de livre et de la reference
    printf "\033[37m\n %-"$cptref"s | %-"$cptword"s  |  AUTEUR\n" "RF" "TITRE LIVRE"
	printf " %-"$cptref"s | %-"$cptword"s  |  ------\n\033[00m" "--" "-----------"
    
    while IFS=":" read ref titre auteur
    do
		printf " %-"$cptref"s \033[37m| \033[01;33m%-"$cptword"s  \033[00;37m|  \033[00mpar \033[04;32m%s\033[00m\n" $ref "$titre" "$auteur"
    done < $catalogue
    echo -e "\n"
}


# -----------------------------------------
# affiche les emprunts de chaque livre
function afficher_emprunts 
{
    echo -e "\n\033[07;32mLES EMPRUNTS : \033[00m"
    greatersize
    printf "\n %-"$cptref"s | %-10s | %12s \n" "RF" "DATE" "PRENOM / NOM"
    printf " %-"$cptref"s | %-10s | %12s \n" "--" "----" "------------"
    while IFS=":" read ref date login
    do
    	nom_entier=$(ldapsearch -x -h dagobah.iut.bx1 -b dc=iut,dc=bx1 cn=$login displayName | grep displayName: | cut -d ":" -f 2)
		printf " %-"$cptref"s | %s | \033[01;36m%12s\033[00m \n" "$ref" "$date" "$nom_entier"
    done < $emprunts
    echo -e "\n"
}

# ----------------------------------------
# affiche les retards de plus de 3 semaines
function afficher_retards
{
	echo -e "\n\033[07;31mEMPRUNTS EN RETARD !\033[00m"
	currentdate=$(date -d "-3 weeks" +"%Y-%m-%d") # date d'il y a 3 semaine sous forme : "YYYY:mm:dd"
	greatersize # appel a la plus grande taille de livre
	printf "\n %-"$cptword"s |  %s \n" "TITRE LIVRE" "EMPRUNTEUR"
	printf " %-"$cptword"s |  %s \033[00m\n" "-----------" "----------"
	while IFS=":" read ref date login
	do
		# boucle pour qui permet de compare la date d'emprunt de chaque lecteur
		# avec la date d'il y a 3 semaines
		# on compare annees avec annees, mois avec mois et jours avec jours
		# si date d'emprunt est inferieur, on arrete la verification et on l'affiche comme non rendu
		for i in 1 2 3 
		do
			date_emprunt=$(echo $date | cut -d "-" -f $i) # annees, mois et jours d'emprunt
			date_retour=$(echo $currentdate | cut -d "-" -f $i ) # annees, mois et jours d'il y a 3 semaines
			if [ $date_retour -gt $date_emprunt ] # si l'emprunt depasse la limite de date de retour
			then
				livre=$(grep $ref $catalogue | cut -d ":" -f 2)
				nom_entier=$(ldapsearch -x -h dagobah.iut.bx1 -b dc=iut,dc=bx1 cn=$login displayName | grep displayName: | cut -d ":" -f 2)
				printf " \033[01;33m%-"$cptword"s \033[00m|  \033[01;36m%s \033[00m\n" "$livre" "$nom_entier"
				break # arret de la verification
			elif [ $date_retour -lt $date_emprunt ] # sinon c'est l'emprunt est en regle
			then
				break # arrete la verification
			fi
		done
	done < $emprunts
	echo " "
}

# ----------------------------------------
# affiche les livre emprunte la date d'emprunts
# d'un lecteur
function afficher_lecteur
{
	printf "\n\033[07;32mINFO LECTEUR : \033[00m\n"
	# boucle while pour afficher tous les lecteurs
	# on s'interesse qu'au lecteur qui ont deja emrpunte
	while IFS=":" read ref date login 
	do
		echo "$login" >> tmp_login.txt # liste les logins pour evite les repetitions
		apparu=$(grep $login tmp_login.txt | wc -l)
		if [ $apparu -lt 2 ] # seulement si il le login a pas deja ete rencontre
		then
			printf " %s  / " "$login"
		fi
	done < $emprunts
	rm tmp_login.txt # supprime le fichier temporaire
	
	echo -e "\n\ninfo sur quel utilisateur ?"
	read -p "login : " login
	grep $login $emprunts > tmp_livre.txt
	nblivre=$(cat tmp_livre.txt | wc -l)
	nom_entier=$(ldapsearch -x -h dagobah.iut.bx1 -b dc=iut,dc=bx1 cn=$login displayName | grep displayName: | cut -d ":" -f 2)
	printf "\n\033[01;36m%s\n\033[00ma emprunte \033[01m%s \033[00mlivre(s) \n " "$nom_entier" "$nblivre :"
	
	while IFS=":" read ref date login
	do
		livre=$(grep $ref $catalogue | cut -f 2 -d ":")
		printf "\t- \033[00m%s : \033[01;33m%s \033[00m\n" "$date" "$livre"
	done < tmp_livre.txt
		
	rm tmp_livre.txt # suppression du fichier tmp.txt
	echo -e "\n"
}

# ----------------------------------------

function enregistrer_emprunt
{
	echo -e "\n\033[07;32mENREGISTRER EMPRUNT : \033[00m"
	read -p "Votre identifiant : " login
	identifiant=$(ldapsearch -x -h dagobah.iut.bx1 -b dc=iut,dc=bx1 cn=$login displayName | grep numEntries: | wc -l) 
# le login est correct seulement si apparait "numEntries" dans la commande ldaspsearch
# du coup on compte les lignes du grep avec wc, et la variable identifiant prend 1 si login est correct, sinon prend 0
	if [ $identifiant = 1 ] 
	then
		read -p "Quel livre voulez-vous empruntrer? : " reponse
		
		livre=$(grep -i "$reponse" $catalogue | cut -f 2 -d ":") # pour avoir le titre du livre precis
		ref_livre=$(grep -i "$livre" $catalogue | cut -c 1) # recuperer la reference du livre rechercher
		
		if [ $(echo $ref_livre | wc -w) = 1 ] # si la recherche concerne un unique livre
		then

			if livre=$(cut -d ":" -f 1-2 "$catalogue" | grep -i "$reponse") # on verifie si le livre est bien dans le catalogue
			then
				numero_livre=$(echo $livre | cut -d ":" -f 1)
				if !(grep ^$numero_livre $emprunts) && [ $(cut -f 3 -d ":" $emprunts | grep $login | wc -l) -le 5 ]
				# verifie si le livre est pas deja emprunte et si l'utilisateur n'a pas deja 5 livres d'empruntes
				then
					printf "Etes vous sur de vouloir enregistrer cet emprunts :\n\t\033[01;33m$livre\033[00m ?\n"
					read -p "reponse (o/n) ? : " reponse
					if [ $reponse = o ] # on demande une confirmation
					then
						date=$(date -d now +"%Y-%m-%d")
						echo "$numero_livre:$date:$login" >> $emprunts
						echo -e "enregistrement effectue ...\n"
					else
						echo -e "Abandon... \n" # lors d'un refus de confirmation
					fi
				else
					echo -e "Livre deja emprunte...\n" # lors d'un emprunt deja effectue
				fi
				
			else
				echo -e "livre inexistant, regardez le catalogue\n" # lorsqu'un livre et inconnu
			fi

		elif [ $(echo $ref_livre | wc -w) -gt 1 ] # si la recherche concerne plusieur livre
		then
			echo -e "recherche pas assez precise, regardez le catalogue ... \n"
		else # si la recherche concerne aucun livre
			echo -e "livre innexistant dans le catalogue.\n"
		fi
	else
		echo -e "identifiant non reconnu ... \n"
	fi
}

# ----------------------------------------

function enregistrer_retour
{
	echo -e "\n\033[07;32mENREGISTRER RETOUR : \033[00m"
	read -p "quel livre a retourner ? : " reponse
	
	livre=$(grep -i "$reponse" $catalogue | cut -f 2 -d ":") # pour avoir le titre du livre precis
	ref_livre=$(grep -i "$livre" $catalogue | cut -c 1) # recuperer la reference du livre rechercher
	
	if [ $(echo $ref_livre | wc -w) = 1 ] # si la recherche concerne un unique livre
	then
		login=$(grep ^$ref_livre $emprunts | cut -f 3 -d ":")
		if [ -n "$login" ]
		then
			nom_entier=$(ldapsearch -x -h dagobah.iut.bx1 -b dc=iut,dc=bx1 cn=$login displayName | grep displayName: | cut -d ":" -f 2)
			echo -e "livre emprunte par \033[01;36m$nom_entier\033[00m"
			read -p "le livre est bien retourne (o/n) ? " reponse
			
			if [ $reponse = o ]
			then
				grep -vi "$ref_livre" $emprunts > tmp.txt # affichage du emprunts.txt sans le livre retourner
				cat tmp.txt > $emprunts # enregistrement du nouveau emprunts.txt
				rm tmp.txt
				echo -e "effacement effectue ... \n"
			else
				echo -e "Abandon... \n" # lors d'un refus de confirmation
			fi
		else
			echo -e "ce livre n'est pas emprunte"
		fi
	elif [ $(echo $ref_livre | wc -w) -gt 1 ] # si la recherche concerne plusieur livre
	then
		echo -e "recherche pas assez precise, regardez le catalogue ... \n"
	else # si la recherche concerne aucun livre
		echo -e "livre innexistant dans le catalogue.\n"
	fi
}

# Quitter l'application
function quitter 
{
	echo -e "\n\033[07;31mQUITTER \033[00m"
	read -p "etes vous sure ? (o/n) " reponse
	if [ $reponse = o ]
	then
		animation_sortie
		clear
		exit 0
	else
		echo " "
	fi
}


# -------------------------------
# affiche le menu
# << OEF remplace par des printf car
# permet la couleur
function afficher_menu
{
	printf "\n\033[01;07;37mCommandes: \033[00m\n"
	printf "    \033[32mAC \033[00mafficher catalogue    \033[32mAE \033[00mafficher emprunts\n"
	printf "    \033[32mAL \033[00majouter livre         \033[32mRL \033[00mretirer livre\n"
	printf "    \033[32mAR \033[00mafficher retards       \033[32mL \033[00mafficher infos lecteur\n"
	printf "     \033[32mE \033[00memprunt d'un livre     \033[32mR \033[00mretour d'un livre\n"
	printf "     \033[32mQ \033[00mquitter                \033[32mM \033[00mafficher le menu\n"
	printf "     \033[32mX \033[00mreinitialiser         \033[32mRT \033[00mrecharger donnees de test\n\n"
}

# ----------------------------------------
# gestion des commandes entres par l'utilisateur
function dialoguer
{
	animation_entre # affichage du logo anime
	
	afficher_menu
	while true
	do
		read -p "Commande: " reponse
		case "$reponse" in
			AC) afficher_catalogue ;; 
			AL) ajouter_livre      ;;
			RL) retirer_livre      ;;
			AE) afficher_emprunts  ;;
			AR) afficher_retards   ;;
			L)  afficher_lecteur    ;;
			E)  enregistrer_emprunt ;;
			R)  enregistrer_retour  ;;
			Q)  quitter             ;;
			X)  reinitialiser       ;;
			RT) recharger_pour_tests ;;
			M)  afficher_menu ;;
			*) echo -e "\033[31mCommande inconnue.\033[00m"
			echo -e "tapez \033[33mM\033[00m pour voir le menu\n" ;;
		esac
	done
}

#############################################################
#
#  MAIN
#
#############################################################

dialoguer

# ---------------------- - fin - du - script -
