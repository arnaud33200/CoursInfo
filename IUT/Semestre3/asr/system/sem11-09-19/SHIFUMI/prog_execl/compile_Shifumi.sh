#!/bin/bash


echo "COMPILATION DU SHIFUMI EXECL"
gcc prog_execl/shifumi.c -o prog_execl/shifumi
echo "COMPILATION DU JOUEUR EXECL"
gcc prog_execl/joueur.c -o prog_execl/joueur

echo "COMPILATION DU SHIFUMI FORK"
gcc prog_fork/shifumi.c -o prog_fork/shifumi

echo -e "\nCOMPILATION TERMINEE"
