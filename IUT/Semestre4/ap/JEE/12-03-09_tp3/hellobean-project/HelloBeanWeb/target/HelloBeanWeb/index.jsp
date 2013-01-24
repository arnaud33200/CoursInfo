<%@page import="java.util.Date"%>
<html>
<body>
	<h2>Hello World!</h2>
	
	<!--  Les liens -->
	<p> Les actions possible </p>
	<ul>
	<li><a href="./EditContact.jsp">Add Contact</a></li>
	<li><a href="./contact?action=viewAll">View All contacts</a></li>
	</ul>
	
	<!-- Java vs JavaScript -->
	<p>En Java Script :</p>
	<script type="text/javascript">
		var date = new Date();
		document.write(date);
	</script>

	<p>En Java :</p>
	<%
		Date d = new Date();
		out.println(d);
	%>

</body>
</html>
