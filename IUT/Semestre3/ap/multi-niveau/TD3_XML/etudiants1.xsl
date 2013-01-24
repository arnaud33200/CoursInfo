<?xml version="1.0" encoding="ISO-8859-1" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:output method="html"
	encoding="ISO-8859-1"/>
	
	<xsl:template match="/">
		<html>
			<head>
				<title> LISTE MOI C ETUDIANTS MALINS STP !!! </title>
			</head>
			<xsl:apply-templates/>
		</html>
	</xsl:template>
	
	<xsl:template match="PERSONNE">
		<body>
			<h1> LISTE PERSONNES 'SPECIAL' </h1>
			<table style="background-image:url('file://info/Etudiants/Home/aladouce/Desktop/105.jpg')">
				<th>nom</th>
				<th>adresse</th>
				<th>telephone</th>
				<th>scolarite</th>
				<xsl:apply-templates/>
			</table>
			
		</body>
	</xsl:template>
	
	<xsl:template match="ETUDIANT">
	<xsl:variable name="bb" select="child::ADRESSE/@popa"></xsl:variable>
	<xsl:if test="$bb='ouais'">
		<tr>
			<td> <xsl:value-of select="child::NOM"/> </td>
			<td> <xsl:value-of select="descendant::RUE"/> </td>
			<td> <xsl:value-of select="child::TELEPHONE"/> </td>
			<td> <xsl:value-of select="descendant::ETABLISSEMENT"/> </td>
		</tr>
	</xsl:if>
	</xsl:template>
	
	
	
	
</xsl:stylesheet>