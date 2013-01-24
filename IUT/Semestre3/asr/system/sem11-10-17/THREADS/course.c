#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <pthread.h>

#define NB_THREADS 10
#define MAX 20000

int cpt;
pthread_mutex_t mutex_verrou;

void *f_thread(void *arg)
{
  int id=(int)arg;
  int i;
  for(i=0;i<MAX;i++)
  {
	  pthread_mutex_lock(&mutex_verrou);
	  cpt++;
	  pthread_mutex_unlock(&mutex_verrou);
	  
  }

  return (void*)id;
}

int main(int argc, char**argv)
{
 	pthread_t tid[NB_THREADS];

  
	if ( pthread_mutex_init( &mutex_verrou, NULL) )		// creation du mutex
   {
		printf("ERREUR dans la creation du mutex");
		exit(1);
	}


  cpt=0;
  int i;
  for(i=0;i<NB_THREADS;i++) 
  {
    int ret = pthread_create(&tid[i], NULL, f_thread, (void*)i);
    if(ret) 
    {
      fprintf(stderr, "Impossible de créer le thread %d\n", i);
      return 1;
    }
  }
  
  void *ret_val;
  for(i=0;i<NB_THREADS;i++) 
  {
		int ret = pthread_join(tid[i], &ret_val);
		if(ret) 
		{
			fprintf(stderr, "Erreur lors de l'attente du thread %d\n", i);
			return 1;
		}
  }
  printf("cpt vaut %d\n", cpt);
  
  pthread_mutex_destroy(&mutex_verrou);
  return 0;
}
