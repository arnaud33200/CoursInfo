<%@page import="iut.jee.Contact"%>
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
		Contact c = (Contact) request.getAttribute("contact");
		request.getSession().putValue("contact", c);
	%>
	
	<p>
		Nom :
		<%=c.getName()%></p>
	<p>
	<p>
		Email :
		<%=c.getEmail()%></p>
	<p>
		BirthDay :<%=c.getBirthday()%></p>
	<p>
		Phone :<%=c.getPhone()%></p>
	
	<a href="./EditContact.jsp"> Edit !</a>
</body>
</html>