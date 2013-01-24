<%@page import="contact.entities.*"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>View Contact</title>
</head>
<body>
	<% 
		String mode = (String) request.getAttribute("mode");
		boolean add = false;
		if(mode != null) 
			add = mode.equals("add");
	
		String submitText = add ? "Add" : "Edit";
	%>
	
	<jsp:useBean id="contact" class="contact.entities.Contact" scope="session">
		<jsp:setProperty name="contact" property="*" />
	</jsp:useBean>
	

	<form action="./contact" method="post">	
		Nom : <input <% if (!add) { %> disabled="disabled" <%}%>  type="text" value="${contact.name}" name="name" /><br/>
		 
		Email : <input type="text" value="${contact.email}" name="email" /><br/> 
		BirthDay : <input type="text" value="1984-12-09" name="birthday" /> <br/>
		Phone : <input type="text" value="0689786756" name="phone" /> <br/>
		<input type="submit" value="<%= submitText %>" name="add" /><br/>
	</form>
	
</body>
</html>