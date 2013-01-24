/*select distinct TitreOeuvre, DuréeOeuvre, TypeOeuvre
from OEUVRE
join INTERPRETER On OEUVRE.CodeOeuvre = INTERPRETER.CodeOeuvre
order by TitreOeuvre;*/

/*select LIEU.NomLieu
from LIEU
	join ( CONCERT
		join ( PARTICIPER
			join ARTISTE on PARTICIPER.CodeArtiste = ARTISTE.CodeArtiste )
		on CONCERT.CodeConcert = PARTICIPER.CodeConcert )
	on CONCERT.CodeLieu = LIEU.CodeLieu
where NomArtiste = 'Quatuor Diotima';*/
/*
select LIEU.NomLieu
from LIEU
	join ( ARTISTE
		join ( CONCERT
			join PARTICIPER on CONCERT.CodeConcert =PARTICIPER.CodeConcert )
		on ARTISTE.CodeArtiste = PARTICIPER.CodeArtiste )
	on CONCERT.CodeLieu = LIEU.CodeLieu	
where NomArtiste = 'Quatuor Diotima';*/

/*select *
from ARTISTE
where CodeArtiste not in (
	select CodeArtiste
	from INTERPRETER
		join OEUVRE on INTERPRETER.CodeOeuvre = OEUVRE.CodeOeuvre
	where TypeOeuvre = 'concerto');
	
select OEUVRE.CodeOeuvre, ARTISTE.CodeArtiste, COUNT(*)
from OEUVRE
	join INTERPRETER on OEUVRE.CodeOeuvre = INTERPRETER.CodeOeuvre
group by OEUVRE.CodeOeuvre, ARTISTE.CodeArtiste;*/

/*select OEUVRE.CodeOeuvre, CodeArtiste, COUNT(*)
from OEUVRE
	join INTERPRETER on OEUVRE.CodeOeuvre = INTERPRETER.CodeOeuvre
group by OEUVRE.CodeOeuvre, CodeArtiste
having COUNT(*) > 1;*/

/*select LIEU.NomLieu
from LIEU
where LIEU.NomLieu not in (
	select LIEU.NomLieu
	from LIEU
		join ( CONCERT 
			join ( PARTICIPER
				join ARTISTE on PARTICIPER.CodeArtiste = ARTISTE.CodeArtiste )
			on CONCERT.CodeConcert = PARTICIPER.CodeConcert )
		on LIEU.CodeLieu = CONCERT.CodeLieu
	where NomArtiste = 'Orchestre National de Jazz' );*/


/*select LIEU.NomLieu
from LIEU
except
select LIEU.NomLieu
from LIEU
	join ( CONCERT 
		join ( PARTICIPER
			join ARTISTE on PARTICIPER.CodeArtiste = ARTISTE.CodeArtiste )
		on CONCERT.CodeConcert = PARTICIPER.CodeConcert )
	on LIEU.CodeLieu = CONCERT.CodeLieu
where NomArtiste = 'Orchestre National de Jazz';*/


/*select LIEU.NomLieu
from LIEU
	left outer join ( CONCERT 
		join ( PARTICIPER
			join ARTISTE on PARTICIPER.CodeArtiste = ARTISTE.CodeArtiste )
		on CONCERT.CodeConcert = PARTICIPER.CodeConcert 
			and NomArtiste = 'Orchestre National de Jazz' )
	on LIEU.CodeLieu = CONCERT.CodeLieu
where NomArtiste is NULL;*/

/*select *
from PARTICIPER
where CONVERT(char,CodeConcert) + '-' + CONVERT(char, OrdrePassage) in (
	select CONVERT(char,CodeConcert) + '-' + CONVERT(char, max(OrdrePassage))
	from PARTICIPER
	group by CodeConcert );*/
	
/*select A.*
from PARTICIPER as A, PARTICIPER as B
where A.CodeConcert = B.CodeConcert
group by A.CodeArtiste, A.CodeConcert, A.OrdrePassage
having A.OrdrePassage = MAX(B.OrdrePassage);*/

/*select A.*
from PARTICIPER AS A
join ( select CodeConcert, MAX(OrdrePassage) as OPMax
		from PARTICIPER
		group by CodeConcert ) as B on A.CodeConcert = B.CodeConcert
where A.OrdrePassage = B.OPMax;*/


-- 8/
/*SELECT A.CodeArtiste, A.NomArtiste
FROM PARTICIPER P
	JOIN ARTISTE A ON P.CodeArtiste = A.CodeArtiste;*/
	
-- 9/
/*SELECT CodeArtiste, NomArtiste
FROM ARTISTE
WHERE 0 = 1;*/

-- 10/
SELECT Distinct O.CodeOeuvre, 0
FROM INTERPRETER I
	INNER JOIN OEUVRE O ON I.CodeOeuvre = O.CodeOeuvre
WHERE O.DuréeOeuvre > 100
UNION
SELECT Distinct A.CodeArtiste, COUNT(*) 
FROM ARTISTE A
	INNER JOIN PARTICIPER P ON A.CodeArtiste = P.CodeArtiste
WHERE P.OrdrePassage < 10
GROUP BY A.CodeArtiste;

-- 11/
--CREATE OR REPLACE 


-- 12 /
/*
create trigger ~~~~
ON CONCERT 
For update, insert, as
	if update(reservation) or update(codelieu)
		"procedurePI"
		
create trigger ~~~~
on lieu
for update as
	if update(capacitelieu)
		"procedurePI"
		
create procedure procedurePI as
if exists( Select 214
	from concer
	join lieu
	where resever > capacite )
begin
	raizeError( ~~~~)*/
	

-- 13 /
/*
create assertion and check (
	not exists( Select 214
	from concer
	join lieu
	where resever > capacite ) )