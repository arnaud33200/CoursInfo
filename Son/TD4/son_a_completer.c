#include "gnuplot_i.h"
#include <stdlib.h>
#include <math.h>

#define SAMPLING_RATE 44100.0
#define CHANNELS_NUMBER 1
// #define N 512
#define N 1024
#define NE 10000

char *RAW_FILE = "tmp-in.raw";

FILE * sound_file_open_read (char *sound_file_name)
{
  char cmd[256];

  snprintf (cmd, 256,
   "sox %s -c %d -r %d -b 16 %s",
   sound_file_name,
   CHANNELS_NUMBER, (int)SAMPLING_RATE, RAW_FILE);

  system (cmd);

  return fopen (RAW_FILE, "rb");
}

void sound_file_close_read (FILE *fp)
{
  fclose (fp);
}

int sound_file_read (FILE *fp, double *s)
{
  short t[N];
  int nbread = fread(t, sizeof(short), N, fp);
  int i;
  printf("Read %d bytes\n", nbread);
  for (i = 0; i < nbread; ++i)
  {
    s[i] = t[i] / 32768.0;
  }
  return nbread;
}

double trame_energy( double * s, int n )
{
  int i;
  double e = 0;
  for (i = 0; i < n; ++i)
  {
    double tmp = s[i];
    e += tmp*tmp;
  }
  return e;
}

double autocorrelation( double * s, int n, int t)
{
  int i;
  double c = 0;
  for (i = 0; i+t < n; ++i)
  {
    c += s[i] * s[i+t];
  }
  return c/n;
}

int main (int argc, char *argv[])
{
  FILE *input;
  double sound[N];
  double xaxis[N];
  double xaxise[NE];
  int n;
  gnuplot_ctrl *histo = gnuplot_init();
  gnuplot_setstyle(histo, "lines");
  // gnuplot_cmd(histo, "set yr [-1:1]");

  input = sound_file_open_read(argv[1]);

  for (n = 0; n < N; ++n)
  {
    xaxis[n] = n * 1.0 / SAMPLING_RATE;
  }

  for (n = 0; n < NE; ++n)
  {
    xaxise[n] = n * 1.0 / SAMPLING_RATE;
  }

/************** ENERGY ***********
  double energy[NE];
  int i = 0;
  while(n = sound_file_read (input, sound) && i < NE )
  {
    energy[i++] = trame_energy(sound, n);
  }

  gnuplot_plot_x(histo, energy, i, "Wave !");
  sleep(10);
***************************/

  int t;
  int i = 0;
  double autocor[NE];
  while(n = sound_file_read (input, sound) && i < NE )
  {
    double max = 0;
    for (t = 0; t < N; ++t)
    {
      double tmp = autocorrelation( sound, n, t);
      if ( n > 1 && tmp > max)
        max = tmp;
    }
    printf("max = %d\n", max );
    autocor[i++] = max;
  }

  for (n = 0; n < 10; ++n)
  {
    printf("[%d] - ", autocor[n] );
  }

  gnuplot_plot_x(histo, autocor, t, "Wave !");
  sleep(10);
  
  sound_file_close_read (input);
  exit (EXIT_SUCCESS);
}
