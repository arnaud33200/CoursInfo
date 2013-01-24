<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.text.SimpleDateFormat" %>
<%@ page import="java.util.Date" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		String nom = "";
		Integer numero = 0;
		SimpleDateFormat formatdate = new SimpleDateFormat("dd-MM-yyyy");
		Date today = new Date();
		String datenaissance = formatdate.format(today);
	%>
	Nom : <input type="text" name="nom" value="<%= nom%>" title="Saisissez votre nom"><br>
	Numero : <input type="text" name="numero" value="<%= numero%>" title="Saisissez votre numero"><br>
	Date Naissance ( JJ-MM-AAAA ) : <input type="text" name="date" value="<%= datenaissance%>" title="Saisissez votre date de naissance"><br>
	
</body>
</html>