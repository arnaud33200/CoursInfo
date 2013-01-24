int distance( int a, int b )
{
	if ( a > b )
		return a-b;
	else
		return b-a;
}

int main( int argc, char * argv[] )
{
	int a = argv[1];
	int b = argv[2];
	distance(a,b);
	
	return 0;
}
