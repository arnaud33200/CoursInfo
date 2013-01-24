
-- #####################################################################
--		SCRIPT DE DESTRUCTION DE LA BASE
-- #####################################################################


-- Permet de vider la DB
DROP TABLE ListeLocation;
DROP TABLE ListeAchat;
DROP TABLE Stores;
DROP TABLE Clients;
DROP TABLE Produits;
DROP TABLE Marques;
DROP TABLE SousCategories;
DROP TABLE Categories;
DROP TYPE Type_Clients;
DROP TYPE Type_Stores;
DROP TYPE Type_Categories;
DROP TYPE Type_ListeLocation;
DROP TYPE Type_ListeAchat;
DROP TYPE Type_Marques;
DROP TYPE Type_Produits;
DROP TYPE Type_SousCategories;
DROP TYPE Type_Adresse;
DROP INDEX Index_NomClient;
DROP INDEX Index_NomProduit;
DROP TRIGGER trigDeleteMarque;
DROP PROCEDURE AfficherAge;
DROP FUNCTION EstNumeroStore;
DROP VIEW Vue_ClientAchat;
