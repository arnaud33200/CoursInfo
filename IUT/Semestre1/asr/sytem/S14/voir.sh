#!/bin/bash

case $1 in
    *.jpg )
	echo "c'est un fichier image"
	;;
    * )
	echo je sais pas
	clear
	echo "et j'efface ton ecran ;)"
	;;
esac
