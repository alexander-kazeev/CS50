// Helper functions for music

#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int firstDigit = atoi(&fraction[0]);
    int secondDigit = atoi(&fraction[2]);
    return (8 / secondDigit * firstDigit);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char currNote = note[0];
    string notes[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G"};
    int octaveDigit = atoi(&note[strlen(note) - 1]);
    int semitoneShift = 0;
    for (int i = 0; i < 11; i++)
    {
        char currNotes = *notes[i];
        if (currNote == currNotes)
        {
            //octave shift
            if (i <= 2)
            {
                semitoneShift += (octaveDigit - 4) * 12;
            }
            else
            {
                semitoneShift += (octaveDigit - 4 - 1) * 12;
            }

            //note shift
            semitoneShift += i;

            //semitone shift
            if (note[1] == '#')
            {
                semitoneShift++;
            }
            else if (note[1] == 'b')
            {
                semitoneShift--;
            }

            //loop end
            break;
        }
    }
    return (int) round(pow(2, (double) semitoneShift / 12) * 440);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return (strcmp(s, "") == 0);
}
