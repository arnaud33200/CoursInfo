<%@page import="java.util.HashMap"%>
<%@page import="contact.entities.*"%>
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
	<% List<Contact> contacts = (List<Contact>) request.getAttribute("contacts"); %>
	<ul>
	<% for(Contact c : contacts) { %>
	<li>Contact : <%= c.getName() %>
		<ul>
		<li><a href="./contact?action=view&name=<%= c.getName() %>"> View </a></li>
		<li><a href="./contact?action=edit&name=<%= c.getName() %>"> Edit </a></li>
		<li><a href="./contact?action=del&name=<%= c.getName() %>"> Delete </a></li>
		</ul>
	</li>
	<% } %>
	</ul>
</body>
</html>