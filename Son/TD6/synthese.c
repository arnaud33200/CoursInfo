#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FE 44100
#define DUREE 5
#define N DUREE*FE

/* output */
static char *RAW_OUT = "tmp-out.raw";
static char *FILE_OUT = "out.wav";

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

int
main (int argc, char *argv[])
{
  int i;
  FILE *output;
  double s[N];

  if (argc != 1)
  {
    printf ("usage: %s\n", argv[0]);
    exit (EXIT_FAILURE);
  }

  output = sound_file_open_write ();

  // oscillateur(s, 1.0, 666);
  // mod_amp(s, 0.5, 440, 0.5, 660);
  mod_freq(s, 1.0, 0.5, 0.5, 660);
  adsr(s);

  sound_file_write (s, output);
  sound_file_close_write (output);
  exit (EXIT_SUCCESS);
}
