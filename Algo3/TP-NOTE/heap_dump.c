int max(int x, int y){
  if(x<y)
    return y;
  else
    return x;
}

/*********************************************************/
int tree_height(tree node)
{
  if(node == NULL)
    return 0;   /* the height of a void tree is 0. */
  return 1 + max(tree_height(node->left),tree_height(node->right));
}

int tree_size(tree node)
{
  if(node == NULL)
    return 0;   /* the height of a void tree is 0. */
  return 1 + tree_size(node->left)+tree_size(node->right);
}

void print_int(tree t, keyfunc f){
  if(t==NULL)
    printf("  ");
  else
    printf("%.2d", f(t->object));
}

int tree_dump(tree root, char* screen, int x0, int y0, int Xmax, int Ymax, int *posr){
  if(root == NULL)
    return x0;

  int i;
  int glop;
  if(root->left != NULL){
    x0=tree_dump(root->left, screen, x0, y0+2, Xmax, Ymax, &glop);
    screen[glop*4+2+(y0+1)*Xmax]='/';
    for(i=glop*4+3; i<=x0*4; i++)
      screen[i+y0*Xmax]='_';
  }

  *posr=x0;
  screen[x0*4+1+y0*Xmax]='0'+ (*(int*)root->object)/10;
  screen[x0*4+2+y0*Xmax]='0'+ (*(int*)root->object)%10;
  x0=tree_dump(root->right, screen, x0+1, y0+2, Xmax, Ymax, &glop);
  if(root->right!=NULL){
    screen[glop*4+1+(y0+1)*Xmax]='\\';
    for(i=*posr*4+3; i<=4*glop; i++)
      screen[i+y0*Xmax]='_';      
  }
  return x0;
}

void heap_dump(heap m){
  if(m == NULL)
    return;
  if(m->root == NULL){
    printf("|  |\n");
    return;
  }
  int xmax=tree_size(m->root);
  int Xmax=4*xmax;
  int ymax=tree_height(m->root);
  int Ymax=2*ymax-1;
  char* screen=malloc(sizeof(*screen)*Xmax*Ymax);

  int i, j;
  for(j=0; j<Ymax; j++)
    for(i=0; i<Xmax; i++)
      screen[i+j*Xmax]=' ';

  int glop;
  tree_dump(m->root, screen, 0,0, Xmax, Ymax, &glop);

  for(j=0; j<Ymax; j++){
    printf("|");
    for(i=0; i<Xmax; i++)
      printf("%c", screen[i+j*Xmax]);
    printf("|\n");
  }
  free(screen);
}

