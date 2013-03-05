#include <stdio.h>
#include "midifile.h"

void read_midi(char * midifile);
void histogramme_sonore(char * midifile);

int main (int argc, char *argv[])
{
	// read_midi(argv[1]);
	histogramme_sonore(argv[1]);
}

void read_midi(char * midifile)
{
	MidiFileEvent_t event;
	unsigned char *data;
	MidiFile_t md = MidiFile_load(midifile);

	event = MidiFile_getFirstEvent(md);

  /* boucle principale */
	while(event)
	{
		if (MidiFileEvent_isNoteStartEvent(event))
		{
	  /* note start */

	  // Channel
			int chan = MidiFileNoteStartEvent_getChannel(event);

	  // Attention channel 10 !!
			if (chan != 10)
			{
	      // Pitch
				printf("Note jouee : %d, ", MidiFileNoteStartEvent_getNote(event));
	      // Duration
				printf("durée %d\n", MidiFileEvent_getTick(MidiFileNoteStartEvent_getNoteEndEvent(event))-MidiFileEvent_getTick(event));

			}
		}

		event = MidiFileEvent_getNextEventInFile(event);
	}
}

void histogramme_sonore(char * midifile)
{
	int hist[12];
	int i;
	for (i = 0; i < 12; ++i)
	{
		hist[i] = 0;
	}
	MidiFileEvent_t event;
	unsigned char *data;
	MidiFile_t md = MidiFile_load(midifile);

	event = MidiFile_getFirstEvent(md);

	while(event)
	{
		if (MidiFileEvent_isNoteStartEvent(event))
		{
			int chan = MidiFileNoteStartEvent_getChannel(event);

			if (chan != 10)
			{
				int note = MidiFileNoteStartEvent_getNote(event);
				hist[note%12] += 1;
			}
		}
		event = MidiFileEvent_getNextEventInFile(event);
	}

	for (i = 0; i < 12; ++i)
	{
		printf("%2s%3d%2s|","", i, "");
	}
	printf("\n");
	for (i = 0; i < 12; ++i)
	{
		printf("%2s%3d%2s|","", hist[i], "");
	}
	printf("\n");
}
