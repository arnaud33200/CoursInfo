
-- #####################################################################
--		SCRIPT DE CREATION DE LA BASE
-- #####################################################################


-- Création des types
CREATE OR REPLACE TYPE Type_Adresse AS OBJECT (
  Ligne1 VARCHAR(80),
  Ligne2 VARCHAR(80),
  CodePostal VARCHAR(5),
  Ville VARCHAR(25) );
/
CREATE OR REPLACE TYPE Type_Categories AS OBJECT (
  numero_categorie NUMBER(3),
	intitule_categorie VARCHAR(16),
	desc_categorie VARCHAR(1024) );
/ 
CREATE OR REPLACE TYPE Type_SousCategories AS OBJECT (
	numero_sous_categorie NUMBER(3),
	intitule_sous_categorie VARCHAR(16),
	desc_sous_categorie VARCHAR(1024),
	categorie NUMBER(3) );
/
CREATE OR REPLACE TYPE Type_Marques AS OBJECT (
	numero_marque NUMBER(3),
	nom_marque VARCHAR(30),
	siteweb_marque URITYPE );
/  
CREATE OR REPLACE TYPE Type_Produits AS OBJECT (
	numero_produit NUMBER(6),
	nom_produit VARCHAR(30),
	desc_produit VARCHAR(1024),
	prix_produit NUMBER(4),
	sous_categorie NUMBER(3),
	marque NUMBER(3) );
/
CREATE OR REPLACE TYPE Type_Clients AS OBJECT (
	numero_client NUMBER(6),
	nom_client VARCHAR(16),
	prenom_client VARCHAR(16),
	anniversaire_client DATE,
  adresse_client Type_Adresse,
	email_client URITYPE );
/
CREATE OR REPLACE TYPE Type_Stores AS OBJECT (
	numero_store NUMBER(3),
	adresse_ville_store Type_Adresse );
/
CREATE OR REPLACE TYPE Type_ListeAchat AS OBJECT (
	numero_achat NUMBER(6),
	client NUMBER(6),
	store NUMBER(3),
	date_achat DATE );
/
CREATE OR REPLACE TYPE Type_ListeLocation AS OBJECT (
	numero_location NUMBER(6),
	client NUMBER(6),
	store NUMBER(3),
	date_debut_location DATE,
	date_fin_prevue_location DATE,
	date_fin_location DATE );
/

-- Definition des tables et des contraintes d'integrite
-- table des categories de produit
CREATE TABLE Categories OF Type_Categories(
	CONSTRAINT PK_Cat PRIMARY KEY (numero_categorie),
	CONSTRAINT UIntitule_Cat UNIQUE (intitule_categorie),
	CONSTRAINT EDesc_Cat CHECK (desc_categorie IS NOT NULL) );

-- table des sous categories de produit
CREATE TABLE SousCategories OF Type_SousCategories(
	CONSTRAINT PK_SousCat PRIMARY KEY (numero_sous_categorie),
	CONSTRAINT UIntitule_SousCat UNIQUE (intitule_sous_categorie),
	CONSTRAINT RCat_SousCat FOREIGN KEY (categorie) REFERENCES Categories ( numero_categorie ) );

-- table des marques
CREATE TABLE Marques OF Type_Marques(
	CONSTRAINT PK_Marque PRIMARY KEY (numero_marque),
	CONSTRAINT UNom_Marque UNIQUE (nom_marque) );

-- table des produits
CREATE TABLE Produits OF Type_Produits(
	CONSTRAINT PK_Prod PRIMARY KEY (numero_produit),
	CONSTRAINT ENom_Prod CHECK (nom_produit IS NOT NULL),
	CONSTRAINT EPrix_Prod CHECK (prix_produit IS NOT NULL),
	CONSTRAINT RSousCat_Prod FOREIGN KEY (sous_categorie) REFERENCES SousCategories ( numero_sous_categorie ),
	CONSTRAINT RMarque_Prod FOREIGN KEY (marque) REFERENCES Marques (numero_marque) );

-- table des clients
CREATE TABLE Clients OF Type_Clients(
	CONSTRAINT PK_Client PRIMARY KEY (numero_client),
	CONSTRAINT ENom_Client CHECK (nom_client IS NOT NULL),
	CONSTRAINT EPrenom_Client CHECK (prenom_client IS NOT NULL) );

-- table des stores
CREATE TABLE Stores OF Type_Stores(
	CONSTRAINT PK_Store PRIMARY KEY (numero_store),
	CONSTRAINT EAdr_Store CHECK (adresse_ville_store IS NOT NULL) );

-- table de la relation d'achat entre un client et un store
CREATE TABLE ListeAchat OF Type_ListeAchat(
	-- liste achats sous quelle forme ?!
	CONSTRAINT PK_LAchat PRIMARY KEY (numero_achat),
	CONSTRAINT RClient_LAchat FOREIGN KEY (client) REFERENCES Clients ( numero_client ),
	CONSTRAINT RStore_LAchat FOREIGN KEY (store) REFERENCES Stores ( numero_store ),
	CONSTRAINT EDate_LAchat CHECK (date_achat IS NOT NULL) );

-- table de la relation de location entre un client et un store
CREATE TABLE ListeLocation OF Type_ListeLocation(
	CONSTRAINT PK_LLocation PRIMARY KEY (numero_location),
	CONSTRAINT RClient_LLocation FOREIGN KEY (client) REFERENCES Clients ( numero_client ),
	CONSTRAINT RStore_LLocation FOREIGN KEY (store) REFERENCES Stores ( numero_store ),
	CONSTRAINT EDateDebut_LLocation CHECK (date_debut_location IS NOT NULL),
	CONSTRAINT EDatePrevue_LLocation CHECK (date_fin_prevue_location IS NOT NULL) );

-- Vue 
CREATE OR REPLACE VIEW Vue_ClientAchat AS
SELECT C.numero_client, C.prenom_client, C.nom_client, C.anniversaire_client, C.email_client
FROM Clients C
JOIN ListeAchat ON C.numero_client = ListeAchat.client;

-- Index
CREATE INDEX Index_NomClient ON Clients ( nom_client ASC );
CREATE INDEX Index_NomProduit ON Produits ( nom_produit ASC );
CREATE INDEX Index_NomMarque ON Marques ( nom_marque ASC );

-- Fonction
CREATE OR REPLACE FUNCTION EstNumeroStore ( ns IN NUMBER ) -- ns = numéro du store à rechercher
RETURN NUMBER
IS
trouv NUMBER (1) ; -- le numéro du store est trouvé parmi les stores
BEGIN
  SELECT COUNT(*) INTO trouv FROM Stores WHERE numero_store = ns ;
  IF trouv = 0 THEN
    RETURN(0) ; -- n'est pas un store
  ELSE
    RETURN(1) ; -- est un store
  END IF ;
END ;

-- Procédure affichant l'âge qu'aura le client de numéro nc cette année
create or replace
PROCEDURE AfficherAge( nc IN NUMBER ) -- nc = numéro du client à âger
IS
trouv NUMBER (1) ; -- le numéro du client est trouvé parmi les clients
dc NUMBER ; -- la date courante
dn DATE ; -- la date de naissance du client
da NUMBER ; -- l'âge du client
BEGIN
  SELECT COUNT(*) INTO trouv FROM Clients WHERE numero_client = nc ;
    IF trouv = 0 THEN -- le client n'a pas été trouvé
      DBMS_OUTPUT.PUT_LINE('Impossible de donner un âge au client : client non trouvé') ;
    ELSE -- le client est trouvé
      dc := TO_NUMBER(TO_CHAR(CURRENT_DATE,'YYYY'));  -- on enregistre la date actuelle
      SELECT anniversaire_client INTO dn FROM Clients WHERE numero_client = nc ; -- on enregistre la date de naissance du client de numéro nc dans dn
      da := dc - TO_NUMBER(TO_CHAR(dn,'YYYY'));
      DBMS_OUTPUT.PUT_LINE('Le client ' || nc || ' est agé de ' || to_char(da)) ;
    END IF ;
END ;

-- Déclencheur
create or replace
TRIGGER trigDeleteMarque
BEFORE DELETE
ON Marques
BEGIN
  dbms_output.put_line('Marque supprimée') ;
END ;
