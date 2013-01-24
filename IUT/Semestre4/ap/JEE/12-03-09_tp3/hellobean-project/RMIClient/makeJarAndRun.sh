mvn clean compile
mvn assembly:single
java -jar target/TestRMIClient-1.0.0-jar-with-dependencies.jar


<!-- RESOLVING JACC javax.security issue : Downloaded the jar and runed : 
	mvn install:install-file -Dfile=javax.security.jar -DartifactId=jacc -DgroupId=javax.security 
	-Dversion=1.0 -Dpackaging=jar -->

