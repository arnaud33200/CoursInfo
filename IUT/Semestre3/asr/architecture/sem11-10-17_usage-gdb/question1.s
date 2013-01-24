r3 : int a
r4 : int b

~~~~~~~~~~~~~~~~~~~~~~~~

cmpw 7, 3, 4
bgt+ 7, L4
subf 3, 4, 3
blr

L4:
subf 3, 3, 4
blr
	
