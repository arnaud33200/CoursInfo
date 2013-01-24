<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<?php
	if( isset($_REQUEST['url']) )
		$url = $_REQUEST['url'];
	else
		$url = "pageAcceuil.php";
?>


<head>
	<meta content="text/html; charset=iso-8859-15" http-equiv="Content-Type" />
	<title>DECONNEXION</title>
</head>

<body>
	<?php
		
		session_start();
		if( isset($_SESSION['NOM_USER']) )
		{
			unset($_SESSION['Valide']);
			unset($_SESSION['NOM_USER']);
			unset($_SESSION['PRENOM_USER']);
			unset($_SESSION['LOGIN_USER']);
			unset($_SESSION['CODE_USER']);
		}
		
		$Loc = "Location: ".$url;
		header($Loc);	
			
	?>
</body>

</html>
