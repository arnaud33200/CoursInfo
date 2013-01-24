<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<?php
	if( isset($_REQUEST['num']) )
		$num = $_REQUEST['num'];
?>

<head>
	<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
	<title>INFO CHANSON</title>
	<script type="text/javascript" src="javascript/ajax.js" ></script>
	<script type="text/javascript">
		function loadajax()
		{

			var numb = <?php  echo $num; ?>;
			connectAv(numb);

/*
			connectAv();
*/
		}
	</script>
	<link href="style2.css" rel="stylesheet" type="text/css" />
	<style type="text/css">
	</style>
</head>

<body onload="loadajax()">	
	
<!--####################################################################################
		BANIERE
#################################################################################### -->

	<div id="baniere">
		<a href="pageAcceuil.php"><img src="image/logo.png" /></a>
	</div>
	
		
<!--####################################################################################
		PANNEAU
#################################################################################### -->

	<div id="panneau">
		
		<div id="affichage">
			<h1>Information Musique</h1>
			<hr/>
			<p></p>
			<div id="com">
			</div>
			
		</div>
	</div>


</body>

</html>
