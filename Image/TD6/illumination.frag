varying vec3 eyepos, normal, lightDir;

void main()
{
	

  // calcul du cosinus de l'angle entre la normale et le rayon lumineux : 
  // correspond au produit scalaire puisque les vecteurs sont normalises
  float cosinusD = max(dot(normal, lightDir), 0.0);
 
  // calcul du cosinus de l'angle entre le vecteur relechi et le rayon de la camera
  vec3 eyepos = normalize(vec3(gl_ModelViewMatrix * gl_Vertex)); // transformation dans le repère de la caméra 
  vec3 reflectvec = normalize(reflect(lightDir, normal));
  float cosinusS = max(dot(eyepos,reflectvec),0.0); 
	
  gl_FragColor = 
   gl_FrontMaterial.ambient * gl_LightModel.ambient  +
    gl_FrontMaterial.ambient * gl_LightSource[0].ambient +
    gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse * cosinusD +//couleur de la lumiere diffuse * coefficient de diffusion * cosinus 
  gl_FrontMaterial.specular * gl_LightSource[0].specular * pow(cosinusS,gl_FrontMaterial.shininess) ; //couleur de la lumiere speculaire * coefficient speculaire * cosinus 
	
}
