
-- #####################################################################
--		SCRIPT D'INTERROGATION DE LA BASE
-- #####################################################################


--Cherche les produits de la marque YAMAHA moins cher que tout les produits de la marque KORG
SELECT NUMERO_PRODUIT
FROM PRODUITS
NATURAL JOIN marques
WHERE nom_marque = 'YAMAHA' and prix_produit < ANY ( SELECT prix_produit FROM PRODUITS NATURAL JOIN marques where nom_marque = 'KORG');

--Affiche le numero, nom et prix du produit le moin cher 
SELECT NUMERO_PRODUIT, NOM_PRODUIT, PRIX_PRODUIT
FROM PRODUITS
WHERE PRIX_PRODUIT = ( SELECT Min(PRIX_PRODUIT) FROM PRODUITS ); 
  
--Affiche les client qui on réaliser plus de trois achat
SELECT v.numero_client, v.prenom_client, v.nom_client, COUNT(*)
FROM Vue_ClientAchat v
GROUP BY v.numero_client, v.prenom_client, v.nom_client
HAVING COUNT(*) >= 3;

--Moyenne des prix des Ampli de la marque GIBSON
SELECT AVG(PRIX_PRODUIT)
FROM PRODUITS
NATURAL JOIN marques
NATURAL JOIN souscategories
WHERE NOM_MARQUE = 'GIBSON';

--Les clients qui ont loué et acheté 
SELECT CLIENT
FROM listeachat
INTERSECT
SELECT CLIENT
FROM LISTELOCATION;

--Utilisation du ROLLUP on obtient les cumuls pour chaque marque et pour tous
SELECT MARQUE, PRIX_PRODUIT, count(*)
FROM PRODUITS
GROUP BY ROLLUP( MARQUE, PRIX_PRODUIT);

--Utilisation du GROUPING SET on obtiens les cumuls pour chaque marque et pour chaque "prix_produit" mais pas pour le couple.
SELECT MARQUE, PRIX_PRODUIT, count(*)
FROM PRODUITS
GROUP BY GROUPING SETS( MARQUE, PRIX_PRODUIT);

--Affiche les produits qui ont le même prix qu'un autre produit
SELECT DISTINCT p.*
FROM produits p, produits p2
WHERE p.prix_produit = p2.prix_produit;

--Affiche le numero, nom et prix des produits avec un commentaire en fonction du prix
SELECT NUMERO_PRODUIT, NOM_PRODUIT, PRIX_PRODUIT, 
  CASE 
  WHEN PRIX_PRODUIT BETWEEN 0 and 1000 THEN 'Produit peu cher' 
  WHEN PRIX_PRODUIT > 1000 THEN 'Produit cher' 
  end Commentaire
from PRODUITS ;

-- document XML sur la liste complet des clients
SELECT XMLELEMENT("Client",
	XMLELEMENT("numero", numero_client),
	XMLELEMENT("prenom", prenom_client),
	XMLELEMENT("nom", nom_client),
	XMLELEMENT("adresse_postal", adresse_client),
	XMLELEMENT("adresse_electronique", email_client))
FROM Clients;
  
-- document XML sur les marques proposé avec chaque instruments associés
SELECT XMLELEMENT("Marque",
	XMLELEMENT("numero marque", m.numero_marque),
	XMLELEMENT("nom marque", m.nom_marque),
	XMLELEMENT("Instruments",
	XMLAGG( XMLELEMENT("Instrument",
		XMLELEMENT("numero instrument", p.numero_produit),
		XMLELEMENT("nom instrument", p.nom_produit),
		XMLELEMENT("prix", p.prix_produit))
		ORDER BY p.nom_produit)))
FROM Marques m
JOIN Produits p ON m.numero_marque = p.marque
GROUP BY m.numero_marque, m.nom_marque;
