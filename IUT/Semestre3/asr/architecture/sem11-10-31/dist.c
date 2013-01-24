int distance(int a, int b)
{
	asm( "subf 0,4,3" );
	asm( "cmpw 7,3,4" );
	asm( "bgt- 7,.L1" );
	asm( "subf 0,3,4" );
	asm( ".L1:" );
	asm( "mr 3,0" );
	asm( "blr" );
}
