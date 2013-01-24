<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<?php
	setcookie("cptbibu",'0',time()*66*24*30*30);	
?>
<html xmlns="http://www.w3.org/1999/xhtml">

<head>JAI SUIS LA TETE</head>
<body>
	<h1>BONJOUR A TOI</h1>
	<?php
		if (isset($_COOKIE["cptbibu"]) )
		{
			echo "<p> nombre \"de\" visite aujourd'hui : $_COOKIE[cptbibu]</p>";
			$val = $_COOKIE["cptbibu"] + 1;
			setcookie("cptbibu",$val,time()*66*24*30*30);
		}
	?>		
</body>
</html>