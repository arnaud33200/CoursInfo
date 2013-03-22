#include "gnuplot_i.h"

#define SAMPLING_RATE 44100.0
#define CHANNELS_NUMBER 1
#define N 1024

char *RAW_FILE = "tmp-in.raw";

FILE *
sound_file_open_read (char *sound_file_name)
{
  char cmd[256];

  snprintf (cmd, 256,
	    "sox %s -c %d -r %d -b 16 %s",
	    sound_file_name,
	    CHANNELS_NUMBER, (int)SAMPLING_RATE, RAW_FILE);

  system (cmd);

  return fopen (RAW_FILE, "rb");
}

void
sound_file_close_read (FILE *fp)
{
  fclose (fp);
}

int
sound_file_read (FILE *fp, double *s)
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

int
main (int argc, char *argv[])
{
  FILE *input;
  double s[N];
  double xaxis[N];
  int n;
  gnuplot_ctrl *h = gnuplot_init();
  gnuplot_setstyle(h, "lines");
  gnuplot_cmd(h, "set yr [-1:1]");

  input = sound_file_open_read(argv[1]);

  for (n = 0; n < N; ++n)
  {
    xaxis[n] = n * 1.0 / SAMPLING_RATE;
  }
  
  while(n = sound_file_read (input, s))
    {

      // affichage
      gnuplot_resetplot(h);
      // gnuplot_plot_x(h, s, n, "Wave !");
      gnuplot_plot_xy(h, xaxis, s, n, "Wave !");
      usleep(N * 1000000.0 / SAMPLING_RATE);
    }
  
  sound_file_close_read (input);
  exit (EXIT_SUCCESS);
}
