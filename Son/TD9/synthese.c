#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>  

#define FE 44100
#define DUREE 1
#define N DUREE*FE/2
#define ST FE/4

/* output */
static char *RAW_OUT = "tmp-out.raw";
static char *FILE_OUT = "out.wav";

static double notes[12] = { 261.625, 277.182, 293.664, 311.126, 
                            329.627, 349.228, 369.994, 391.995, 
                            415.304, 440.000, 466.163, 493.883 };
static double notes_stat[12] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }

FILE *
sound_file_open_write (void)
{
 return fopen (RAW_OUT, "wb");
}

void
sound_file_close_write (FILE *fp)
{
  char cmd[256];
  fclose (fp);
  snprintf(cmd, 256, "sox -c 1 -r %d -e signed-integer -b 16 %s %s", (int)FE, RAW_OUT, FILE_OUT);
  system (cmd);
}

void
sound_file_write (double *s, FILE *fp)
{
  int i;
  short tmp[N];
  for (i=0; i<N; i++)
  {
    tmp[i] = (short)(s[i]*32768);
  }
  fwrite (tmp, sizeof(short), N, fp);
}

void
sound_file_write_silence (FILE *fp)
{
  int i;
  short tmp[ST];
  for (i=0; i<ST; i++)
  {
    tmp[i] = 0.0;
  }
  fwrite (tmp, sizeof(short), ST, fp);
}

void oscillateur( double * s, double a, double f)
{
  int i;
  for (i=0; i<N; i++)
    s[i] = a * sin(2*M_PI*f*(1.0*i/FE));
}

void add_oscillateur( double * s, double a, double f)
{
  int i;
  for (i=0; i<N; i++)
   {   s[i] += a * sin(2*M_PI*f*(1.0*i/FE));
     s[i] /= 2;
   }
 }

 void mod_amp( double * s, double c, double f1, double a2, double f2)
 {
  double t;
  int i;
  for (i=0; i<N; i++)
  { 
    t = (1.0*i/FE);  
    s[i] = (c + a2 * sin(2*M_PI*f2*t)) * sin(2*M_PI*f1*t);
  }
}

void mod_freq( double * s, double c, double a1, double a2, double f2)
{
  double t;
  int i;
  for (i=0; i<N; i++)
  {
    t = (1.0*i/FE);   
    s[i] = a1 * sin(2*M_PI* (c + a2 * sin(2*M_PI*f2*t)) *t);
  }
}

void adsr(double * s)
{
  int i;
  int frame = N/16;
  for (i=0; i<(2*frame); i++)
  {
    s[i] = s[i]*(i/(2*frame*1.0));
  }

  for (i=2*frame; i<4*frame; i++)
    s[i] = s[i]/(i*-1.5/(4*frame*1.0));

  for (i=4*frame; i<10*frame; i++)
    s[i] = s[i]*0.5;

  for (i=10*frame; i<16*frame; i++)
    s[i] = s[i]/(i*-1/(6*frame*1.0));
}

double get_note_stat (double stat)
{

  if( stat < 1.0/12 ) return 261.625;
  else if( stat < 1.0/12*2 ) return 277.182;
  else if( stat < 1.0/12*3 ) return 293.664;
  else if( stat < 1.0/12*4 ) return 311.126;
  else if( stat < 1.0/12*5 ) return 329.627;
  else if( stat < 1.0/12*6 ) return 349.228;
  else if( stat < 1.0/12*7 ) return 369.994;
  else if( stat < 1.0/12*8 ) return 391.995;
  else if( stat < 1.0/12*9 ) return 415.304;
  else if( stat < 1.0/12*10 ) return 440.000;
  else if( stat < 1.0/12*11 ) return 466.163;
  else return 493.883;
}
double get_note (int i)
{
  return notes[i];
}

int
main (int argc, char *argv[])
{
  int i;
  FILE *output;
  double s[N];

  srand( time(NULL) );

  if (argc =! 1)
  {
    printf ("usage: %s\n", argv[0]);
    exit (EXIT_FAILURE);
  }

  output = sound_file_open_write ();

  for (i = 0; i < 10; ++i)
  {
    double x = (double)rand()/RAND_MAX; 
    printf("tire : %f\n", x);
    double note = get_note_stat(x);
    oscillateur( s, 1.0, note);
    sound_file_write (s, output); 
    sound_file_write_silence (output);

  }

  
  sound_file_close_write (output);
  exit (EXIT_SUCCESS);
}
