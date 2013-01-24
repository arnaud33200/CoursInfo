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
