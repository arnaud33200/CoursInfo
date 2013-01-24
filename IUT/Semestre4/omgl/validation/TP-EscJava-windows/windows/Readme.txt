#
#   TP Esc/Java
#

L'installation du paquetage se fait sous cygwin.

Apr�s avoir d�compress� le paquetage dans un r�pertoire de votre choix
(not� <REPERTOIRE_TP>).

1] V�rifiez que <REPERTOIRE_TP> ne comporte pas d'espace. Si c'est le
cas, d�placez le, par exemple dans C:\Temp.

2] Editez le fichier <REPERTOIRE_TP>/EscJava/bin/escjava.bat, et
remplacez la cha�ne de caract�re <REPERTOIRE_TP> par le nom complet
r�el du r�pertoire.

L'installation est finie.

3] dans le terminal cygwin, tapez la commande suivante:
> export PATH=$PATH;<REPERTOIRE_TP>/EscJava/bin

4] Test:
Placez-vous dans le r�pertoire <REPERTOIRE_TP>/Exemples/Bag/A/
Tapez la commande suivante:
> escjava.bat -loopSafe Bag.java
Le syst�me analyse le fichier Bag.java, �a marche !

Lisez maintenant le fichier <REPERTOIRE_TP>/Exemples/Bag/Readme.txt
pour la suite.
