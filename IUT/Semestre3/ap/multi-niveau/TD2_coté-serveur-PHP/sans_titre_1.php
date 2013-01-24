<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
<title>sans titre 1</title>
</head>

<body>

	<ul>
		<?php
			for ( $i = 1; $i <= 10; $i++ )
			{
				echo "<li>";
				echo "numero $i";
				echo "</li>";
			}
			
			echo 'nom du serveur' . getenv("COMPUTERNAME") . "<br>";
			echo 'nom du serveur' . getenv("SERVER_NAME") . "<br>";
			
			
		?>
	</ul>

	<form method="POST" action="formulario.php">
		<p> votre prenom : <input type="text" size="20" name="prenom"/></p>
		<p> plutot du genre : <select name="quiqui">
								<option value="Monsieur" selected="selected">MONSIEUR</option>
								<option value="Madame">MADAME</option>
								<option value="Mademoiselle">MADEMOISELLE</option>
							</select> </p>
		<p> le permis ? : <input type="checkbox" size="50" name="permi"/></p>
		
		<br><hr><br>
		<p> Initial de l'auteur : <input type="text" size="1" name="ini"/></p>
		<p><input type="submit" value="LETS GO"/></p>
	</form>

</body>

</html>
