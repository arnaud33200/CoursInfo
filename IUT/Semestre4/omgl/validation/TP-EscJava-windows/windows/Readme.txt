#
#   TP Esc/Java
#

L'installation du paquetage se fait sous cygwin.

Après avoir décompressé le paquetage dans un répertoire de votre choix
(noté <REPERTOIRE_TP>).

1] Vérifiez que <REPERTOIRE_TP> ne comporte pas d'espace. Si c'est le
cas, déplacez le, par exemple dans C:\Temp.

2] Editez le fichier <REPERTOIRE_TP>/EscJava/bin/escjava.bat, et
remplacez la chaîne de caractère <REPERTOIRE_TP> par le nom complet
réel du répertoire.

L'installation est finie.

3] dans le terminal cygwin, tapez la commande suivante:
> export PATH=$PATH;<REPERTOIRE_TP>/EscJava/bin

4] Test:
Placez-vous dans le répertoire <REPERTOIRE_TP>/Exemples/Bag/A/
Tapez la commande suivante:
> escjava.bat -loopSafe Bag.java
Le système analyse le fichier Bag.java, ça marche !

Lisez maintenant le fichier <REPERTOIRE_TP>/Exemples/Bag/Readme.txt
pour la suite.
