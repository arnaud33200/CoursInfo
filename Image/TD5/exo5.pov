#include "colors.inc"#include "textures.inc"#include "glass.inc"#include "metals.inc"#include "woods.inc"camera{  perspective  location <0, 5, 10>  look_at <0, 0, 0>  angle 45}              #declare sphere0 = sphere {  <1, 0, 0>, 1.2  texture  {    pigment {color Blue}    finish     {      diffuse 0.6      ambient 0.2      brilliance 1      //crand 0.1      specular 0.4      roughness 0.1    }  }}// Exemples de differentes textures de materiaux           #declare sphere1 = sphere{  <-0.5, 0, 0>, 1.2  //texture {Silver3}  //texture {Gold_Nugget}  //texture {Bright_Bronze}  texture {   pigment {color <1,1.5,2>*.8 }   normal {agate}}   //texture {Aluminum}}#declare intensity = 1.0;light_source{  <1, 3, 3>  color intensity} object {sphere1}object {sphere0}