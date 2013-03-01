

varying vec3 eyepos, normal, lightDir;

void main (void)
{   

	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
	gl_FrontColor = gl_Color; 
	
	eyepos = normalize(vec3(gl_ModelViewMatrix * gl_Vertex)); // transformation dans le repère de la caméra 
	lightDir = normalize(vec3(gl_LightSource[0].position));
 	normal = normalize(gl_NormalMatrix * gl_Normal);	

	
}

