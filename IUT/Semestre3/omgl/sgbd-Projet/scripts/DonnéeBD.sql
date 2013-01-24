
-- #####################################################################
--		SCRIPT D'INSERTION DE DONNEES DANS LA BASE
-- #####################################################################


-- clients

INSERT INTO CLIENTS VALUES (1, 'HARDISON', 'JOHN' , to_date('10/03/1992'), Type_Adresse('36 AVENUE DES HEROS', ' ', ' 33560', 'BORDEAUX'), URIFACTORY.GETURI('hardisonjohn@caramail.com'));
COMMIT;
INSERT INTO CLIENTS VALUES (2, 'SMITH', 'JOHN' , to_date('10/03/1992'), Type_Adresse('38 AVENUE DES HEROS', ' ', ' 33560', 'BORDEAUX'), URIFACTORY.GETURI('hardisonjohn@caramail.com'));
COMMIT;
INSERT INTO CLIENTS VALUES (3, 'DOE', 'JOHN' , to_date('10/03/1992'), Type_Adresse('314 AVENUE DES HEROS', ' ', ' 33560', 'BORDEAUX'), URIFACTORY.GETURI('hardisonjohn@caramail.com'));
COMMIT;
INSERT INTO CLIENTS VALUES (4, 'MARLEY', 'BOB' , to_date('10/03/1992'), Type_Adresse('1337 AVENUE DES HEROS', ' ', ' 33560', 'BORDEAUX'), URIFACTORY.GETURI('hardisonjohn@caramail.com'));
COMMIT;
INSERT INTO CLIENTS VALUES (5, 'COBAIN', 'KURT' , to_date('10/03/1992'), Type_Adresse('18 AVENUE DES HEROS', ' ', ' 33560', 'BORDEAUX'), URIFACTORY.GETURI('hardisonjohn@caramail.com'));
COMMIT;
INSERT INTO CLIENTS VALUES (6, 'SPRINGSTEEN', 'BRUCE' , to_date('10/03/1992'), Type_Adresse('666 AVENUE DES HEROS', ' ', ' 33560', 'BORDEAUX'), URIFACTORY.GETURI('hardisonjohn@caramail.com'));
COMMIT;
INSERT INTO CLIENTS VALUES (7, 'CHARLES', 'RAY' , to_date('10/03/1992'), Type_Adresse('8 AVENUE DES HEROS', ' ', ' 33560', 'BORDEAUX'), URIFACTORY.GETURI('hardisonjohn@caramail.com'));
COMMIT;
INSERT INTO CLIENTS VALUES (8, 'BELLAMY', 'JAMES' , to_date('10/03/1992'), Type_Adresse('7 AVENUE DES HEROS', ' ', ' 33560', 'BORDEAUX'), URIFACTORY.GETURI('hardisonjohn@caramail.com'));
COMMIT;
INSERT INTO CLIENTS VALUES (9, 'ZIMMERMAN' , 'JOEL' , to_date('05/01/1981'), Type_Adresse('38 BOULEVARD MAU5TRAP', ' ', '33400', 'TALENCE'), URIFACTORY.GETURI('Deadmau5@mau5trap.com'));
COMMIT;
INSERT INTO CLIENTS VALUES (10, 'KUTCHER', 'ASHTON' , to_date('07/02/1978'), Type_Adresse('43 RUE EFFET PAPILLON', ' BATIMENT A PORTE 33 ', ' 19700', 'LAGRAULIERE'), URIFACTORY.GETURI('ashtonvip@gmail.com'));
COMMIT;
INSERT INTO CLIENTS VALUES (11, 'BANGALTER', 'THOMAS' , to_date('03/01/1973') , Type_Adresse('72 RUE ELECTROMA' , ' ' , ' 33124' , 'BOUQUEYRAN') , URIFACTORY.GETURI('thombang@hotmail.com'));
COMMIT;
INSERT INTO CLIENTS VALUES (12, 'DE HOMEM-CHRISTO', 'GUY-MANUEL' , to_date('08/02/1974'), Type_Adresse('44 RUE CARNOT', ' ', '75000', 'PARIS'), URIFACTORY.GETURI('daftpunkguymanu@brainwasher.com'));
COMMIT;
INSERT INTO CLIENTS VALUES (13, 'AUGE', 'GASPARD' , to_date('21/05/1979'), Type_Adresse('5 RUE DE LA JUSTICE', ' ', ' 35580','GUIGNEN'), URIFACTORY.GETURI('letstherebelight@dvno.com'));
COMMIT;
INSERT INTO CLIENTS VALUES (14, 'DE ROSNAY', 'XAVIER' , to_date('02/07/1982'), Type_Adresse('6 RUE DE LA JUSTICE', ' ', '35580', 'GUIGNEN'), URIFACTORY.GETURI('weareyourfriend@dvno.com'));
COMMIT;
INSERT INTO CLIENTS VALUES (15, 'LINDEMANN', 'TILL' , to_date('04/01/1963'), Type_Adresse('7 AVENUE ROSENROT', ' ', ' 01370','MEILLONAS'), URIFACTORY.GETURI('links234@rplus.com'));
COMMIT;

-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
-- INSERTION DES MAGASINS
INSERT INTO STORES VALUES ( '1' ,Type_Adresse('2 rue des peupliers' , '', '22150' , 'LANGAST'));
COMMIT;
INSERT INTO STORES VALUES ( '2' ,Type_Adresse('12 avenue du chevreuil' , '', '77500' , 'CHELLES'));
COMMIT;
INSERT INTO STORES VALUES ( '3' ,Type_Adresse('25 allée Pablo Neruda' ,'', '84100' , 'ORANGE'));
COMMIT;
INSERT INTO STORES VALUES ( '4' ,Type_Adresse('44 rue Saint André' ,'', '33400' , 'TALENCE'));
COMMIT;
INSERT INTO STORES VALUES ( '5' ,Type_Adresse('6 Route de Lyons' ,'', '76000' , 'ROUEN'));
COMMIT;
INSERT INTO STORES VALUES ( '6' ,Type_Adresse('33 Route d Oberhausbergen' ,'', '67000' , 'STRASBOURG'));
COMMIT;
INSERT INTO STORES VALUES ( '7' ,Type_Adresse('65 Bd René Dubois' , '44500' ,'', 'LA BAULE-ESCOUBLAC'));
COMMIT;


-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
-- INSERTION DES TROIS CATEGORIES
 
INSERT INTO Categories VALUES ( 1, 'INSTRUMENT', 'INSTRUMENT A CORDE DU MAGASIN');
	-- test sur la contrainte "EDesc_Cat"
INSERT INTO Categories VALUES ( 2, 'AMPLIFICATEUR', '' );
INSERT INTO Categories VALUES ( 2, 'AMPLIFICATEUR', 'MATERIEL POUR AMPLIFIER LE SON D INSTRUMENT ELECTRIQUE' );
INSERT INTO Categories VALUES ( 3, 'ACCESSOIRE', 'ACCESSOIRE EN TOUT GENRE POUR JOUEUR D INSTRUMENT');
COMMIT
 
-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
-- INSERTION DES SOUS CATEGORIES POUR CHAQUE CATEGORIES
 
-- INSERTION DES SOUCATEGORIES POUR LES ACCESSOIRES
INSERT INTO SousCategories VALUES ( 1, 'GTE', 'GUITAR ELECTRIQUE', 1 );
INSERT INTO SousCategories VALUES ( 2, 'GTEDN', 'GUITAR ELECTRIQUE A 2 NECKS', 1 );
INSERT INTO SousCategories VALUES ( 3, 'GTE7C', 'GUITAR ELECTRIQUE A 7 CORDE', 1 );
INSERT INTO SousCategories VALUES ( 4, 'GTA', 'GUITAR ACOUSTIQUE', 1 );
INSERT INTO SousCategories VALUES ( 5, 'GTF', 'GUITAR FOLK', 1 );
INSERT INTO SousCategories VALUES ( 6, 'GTAE12C', 'GUITAR ACOUSTIQUE A 12 CORDES', 1 );
INSERT INTO SousCategories VALUES ( 7, 'BE', 'BASS ELECTRIQUE', 1 );
INSERT INTO SousCategories VALUES ( 8, 'BE5C', 'BASS ELECTRIQUE A 5 CORDES', 1 );
INSERT INTO SousCategories VALUES ( 9, 'BE6C', 'BASS ELECTRIQUE A 6 CORDES', 1 );
INSERT INTO SousCategories VALUES ( 10, 'BA', 'BASS ACOUSTIQUE', 1 );
INSERT INTO SousCategories VALUES ( 11, 'UKLL', 'UKULELE', 1 );
COMMIT
 
-- INSERTION DES SOUCATEGORIES POUR LES AMPLIFICATEUR
INSERT INTO SousCategories VALUES ( 12, 'CL', 'AMPLI COMBO A LAMPE', 2 );
INSERT INTO SousCategories VALUES ( 13, 'CT', 'AMPLI COMBO A TRANSISTOR', 2 );
INSERT INTO SousCategories VALUES ( 14, 'CH', 'AMPLI COMBO HYBRIDE', 2 );
INSERT INTO SousCategories VALUES ( 15, 'TBL', 'AMPLI TETE BAFLE A LAMPE', 2 );
INSERT INTO SousCategories VALUES ( 16, 'TBT', 'AMPLI TETE BAFLE A TRANSISTOR', 2 );
INSERT INTO SousCategories VALUES ( 17, 'TBH', 'AMPLI TETE BAFLE HYBRIDE', 2 );
COMMIT
 
-- INSERTION DES SOUCATEGORIES POUR LES ACCESSOIRES
INSERT INTO SousCategories VALUES ( 18, 'SG', 'SANGLE POUR GUITARE', 3 );
INSERT INTO SousCategories VALUES ( 19, 'SB', 'SANGLE POUR BASSE', 3 );
INSERT INTO SousCategories VALUES ( 20, 'MG', 'MEDIATOR GUITARE', 3 );
INSERT INTO SousCategories VALUES ( 21, 'MB', 'MEDIATOR BASSE', 3 );
INSERT INTO SousCategories VALUES ( 22, 'PE', 'PRODUIT D ENTRETIENT', 3 );
INSERT INTO SousCategories VALUES ( 23, 'SPG', 'SUPPORT POUR GUITARE', 3 );
INSERT INTO SousCategories VALUES ( 24, 'SPB', 'SUPPORT POUR BASS', 3 );
INSERT INTO SousCategories VALUES ( 25, 'JK', 'JACK POUR INSTRUMENT ELECTRIQUE', 3 );
INSERT INTO SousCategories VALUES ( 26, 'AEA', 'ALIMENTATION ELECTRIQUE POUR AMPLI', 3 );
INSERT INTO SousCategories VALUES ( 27, 'CEG', 'CORDE EN METAL POUR GUITAR ELECTRIQUE ET FOLK', 3 );
INSERT INTO SousCategories VALUES ( 28, 'CNG', 'CORDE NYLON POUR GUITAR ACOUSTIQUE', 3 );
INSERT INTO SousCategories VALUES ( 29, 'CB', 'CORDE POUR BASS', 3 );
-- on test ici la contrainte d'unicité "UIntitule_SousCat"
INSERT INTO SousCategories VALUES ( 30, 'MG', 'MICRO POUR GUITARE ELECTRIQUE', 3 );
INSERT INTO SousCategories VALUES ( 30, 'MICG', 'MICRO POUR GUITARE ELECTRIQUE', 3 );
INSERT INTO SousCategories VALUES ( 31, 'MICB', 'MICRO POUR BASSE ELECTRIQUE ELECTRIQUE', 3 );
INSERT INTO SousCategories VALUES ( 32, 'PEE', 'PEDALE A EFFET POUR INSTRUMENT ELECTRIQUE', 3 );
COMMIT



-- Insertion des Marques
INSERT INTO Marque VALUES ( 1, 'FENDER' , URIFACTORY.GETURI('http://www.fender.com/') );
INSERT INTO Marque VALUES ( 2, 'GIBSON' , URIFACTORY.GETURI('http://www2.gibson.com/') );
	-- test sur la contrainte de clé primaire PK_Marque
INSERT INTO Marque VALUES ( 2, 'IBANEZ' , URIFACTORY.GETURI('http://www.ibanez.com/') );
INSERT INTO Marque VALUES ( 3, 'IBANEZ' , URIFACTORY.GETURI('http://www.ibanez.com/') );
INSERT INTO Marque VALUES ( 4, 'WARWICK' , URIFACTORY.GETURI('http://www.warwick.de') );
INSERT INTO Marque VALUES ( 5, 'MARSHALL' , URIFACTORY.GETURI('http://www.marshall.com/') );
INSERT INTO Marque VALUES ( 6, 'RANDALL' , URIFACTORY.GETURI('http://www.marshall.com/') );
INSERT INTO Marque VALUES ( 7, 'DUNLOP' , URIFACTORY.GETURI('http://www.dunlop.com/') );
INSERT INTO Marque VALUES ( 8, 'MESABOUGIE' , URIFACTORY.GETURI('http://www.mesa.com/') );
INSERT INTO Marque VALUES ( 9, 'SKULL STRING' , URIFACTORY.GETURI('http://www.skullstring.com/' );
INSERT INTO Marque VALUES ( 10, 'BOSS' , URIFACTORY.GETURI('http://www.bossguitar.com/') );
INSERT INTO Marque VALUES ( 11, 'PEAVEY' , URIFACTORY.GETURI('http://www.peaveyamp.com/') );
INSERT INTO Marque VALUES ( 12, 'DEAN' , URIFACTORY.GETURI('http://www.deanguitar.com/') );
INSERT INTO Marque VALUES ( 13, 'BILLLAWRENCE' , URIFACTORY.GETURI('http://www.billlawrencepickups.com/') );
INSERT INTO Marque VALUES ( 14, 'ERNIEBALL' , URIFACTORY.GETURI('http://www.ernieball.com/') );
INSERT INTO Marque VALUES ( 15, 'JACKSON' , URIFACTORY.GETURI('http://www.jacksonguitars.com/') );
COMMIT;

-- INSERTION DES PRODUITS
INSERT INTO Produits VALUES( 1 , 'ASSMNBLK', 'American Standard Stratocaster MN BLK' , 1115 , 1 , 1 );
INSERT INTO Produits VALUES( 2 , 'AST6609', 'American Standard Telecaster 6609' , 1206 , 1 , 1 );
INSERT INTO Produits VALUES( 3 , 'SGSFWE', 'SG STANDARD FADED WORN EBONY' , 749 , 7 , 2);
INSERT INTO Produits VALUES( 4 , 'SSWA1SB', 'STAGG SWA1SB' , 214 , 4 , 8);
INSERT INTO Produits VALUES( 5 , 'RRG100', 'RANDALL RG 100' , 560 , 14 , 6);
INSERT INTO Produits VALUES( 6 , 'P5150', 'PEAVEY 5150' , 800 , 15 , 11);
INSERT INTO Produits VALUES( 7 , 'PR15B', 'PEAVEY RAGE 15B' , 130 , 13 , 11);
INSERT INTO Produits VALUES( 8 , 'DML79', 'DEAN ML 79' , 650 , 1 , 12);
INSERT INTO Produits VALUES( 9 , 'BLAW', 'BILL LAWRENCE USA' , 85 , 30 , 13);
INSERT INTO Produits VALUES( 10 , 'GTPL', 'GUITAR POLISH' , 10 , 22 , 14);
	-- test sur la contrainte "EPrix_Prod"
INSERT INTO Produits VALUES( 11 , 'DMJ3', 'DUNLOP MEDIATOR JAZZ III' ,  , 20 , 7);
INSERT INTO Produits VALUES( 11 , 'DMJ3', 'DUNLOP MEDIATOR JAZZ III' , 1 , 20 , 7);
INSERT INTO Produits VALUES( 12, 'DSWI', 'DUNLOP STRAP WARRIOR INSIDE' , 15 , 18 , 7);
INSERT INTO Produits VALUES( 13, 'DWWP', 'DUNLOP WHAWHA PEDAL' , 98 , 32 , 7);
INSERT INTO Produits VALUES( 14, 'SKDC1158', 'SKULL STRING DROP C 11 58' , 11 , 27 , 9);
INSERT INTO Produits VALUES( 15, 'JRR1T', 'JACKSON RANDY RHOADS 1T' , 780 , 1 , 15);
INSERT INTO Produits VALUES( 16, 'JRR1T', 'JACKSON RANDY RHOADS 1T' , 780 , 1 , 15);
INSERT INTO Produits VALUES( 17, 'JWRXMG', 'JACKSON WARRIOR XMG' , 860 , 1 , 15);
COMMIT;

ories VALUES ( 4, 'BASS ACOUSTIQUE', 'BASS AVEC UN CAISSON EN BOIS' );
