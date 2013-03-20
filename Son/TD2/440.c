#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/soundcard.h>

#define DEVICE "/dev/dsp"
#define FORMAT AFMT_S16_LE
#define CHANNELS 2
#define SPEED 44100

#define LENGTH (20 * SPEED)

int
main (void)
{
  int i;
  double freq;

  int audio;  /* file descriptor */

  int format, channels, speed;

  /* open the sound device */

  audio = open (DEVICE, O_WRONLY);
  if (audio == -1) { exit (EXIT_FAILURE); }

  /* set up the sound card */

  format = FORMAT;  /* sample type */
  ioctl (audio, SOUND_PCM_SETFMT, &format);
  if (format != FORMAT) { close (audio); exit (EXIT_FAILURE); }

  channels = CHANNELS;  /* number of channels */
  ioctl (audio, SNDCTL_DSP_CHANNELS, &channels);
  if (channels != CHANNELS) { close (audio); exit (EXIT_FAILURE); }

  speed = SPEED;  /* sampling rate */
  ioctl (audio, SNDCTL_DSP_SPEED, &speed);
  if (speed != SPEED) { close (audio); exit (EXIT_FAILURE); }

  /* play the audio samples */

  freq = 150.0;
  double dir = 0.01;
  int ratio;
  for (i=0; i<LENGTH; i++)
    {
      short s[CHANNELS];
      ratio = SPEED/freq;
      if(i%ratio < ratio/2)
      {
        s[0] = 0;
        s[1] = 16000;
      }
      else
      {
        s[0] = 16000;
        s[1] = 0;
      }  
      write (audio, s, CHANNELS*sizeof(short));
      if(freq > 200.0 || freq < 10.0)
        dir*=-1;
        freq+=dir;
    }

  /* close the sound device */

  close (audio);

  exit (EXIT_SUCCESS);
}

/* End Of File */
