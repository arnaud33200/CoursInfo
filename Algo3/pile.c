
const int BLOCK = 10;

struct Pile
{
	int * array;
	int length;
	int last;
};

Pile createPile()
{
	struct Pile mp;
	mp.array = malloc(sizeof(int)*BLOCK);
	mp.length = BLOCK;
	mp.last = 0;
	return mp;
}

void pushPile(struct Pile * p, void * o)
{
	if(p->last == p->length - 1)
		growPile(p);
	p->last++;
	p->array[last] = o;
} 

void growPile(struct Pile * p)
{
	int i;
	int ns = p->length + BLOCK;
	int * na = malloc(sizeof(int) * ns);
	for(i=0; i<p->length; i++)
		na[i] = p->array[i];
	free(p->array);
	
	p->array = na;
	p->length = ns;
}

int main()
{
	return 0;
}
