<%@page import="java.util.ArrayList"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
	<%
		List<String> lists = new ArrayList<String>();
		lists.add("Vincent");
		lists.add("Toto");
		lists.add("Titi");
		lists.add("Tata");
	%>
	<p>Les personnes présentes dans la liste sont : </p>
	<% for(String name : lists) { %>
		<p><%= name  %> 
		<% if(name.equals("Vincent")) { %>
			est un super prof
		<% } else { %>
			est un étudiant
		<% } %>
		</p>
	<% } %>
	 
</body>
</html>