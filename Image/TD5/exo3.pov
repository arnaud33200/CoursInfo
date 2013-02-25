#include "colors.inc"

camera {
  location <10, 10, 5>
  look_at <0, 0, 2>
  angle 30
}

#declare demicylindre = object
{
	difference
	{
		cylinder{ <0,0,3> <0,2,3> 1 }
		box{ <0,-1,2> <1,3,4> }
		pigment {color < 1 , 0 , 0 > } 
	}
}

#declare demicercle = object
{
	difference
	{
		difference
		{
			sphere{ <0,1,0> 1 }
			sphere{ <0,1,0> 0.9 }	
			pigment {color < 0 , 1 , 0 > } 
		}
		box{ <0,-1,-1> <1,3,1> }
	}
}

demicercle
demicylindre

light_source{ <1000, 1000, -1000> White }
