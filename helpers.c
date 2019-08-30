// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include "helpers.h"
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator = fraction[0] - '0';
    int denominator = fraction[2] - '0';
    return numerator * (8 / denominator);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double heartz = 440.0; //initializes frequency in heartz
    int octave = note[strlen(note) - 1] - 48; //initliazies octave
    char letter = note[0]; //initializes the letter component of the note

    int keydifference = letter - 'A'; //establishes how many white keys ahead from A is the note
    float semitones = 0.0; //establishes semitones

//converts keys to semitones
    if (keydifference == 1)
    {
        semitones = keydifference * 2;
    }
    else if (keydifference > 1 & keydifference <= 4)
    {
        semitones = (keydifference * 2) - 1;
    }
    else if (keydifference > 4)
    {
        semitones = (keydifference * 2) - 2;
    }

//detects if there is an accidental present, if so adjusts semitones
    if (strlen(note) == 3)
    {
        if (note[1] == '#')
        {
            semitones ++;
        }
        else if (note[1] == 'b')
        {
            semitones --;
        }
    }

//detects octave and adjusts frequency depending on octave
    if (octave > 4)
    {
        heartz *= (2 * (octave - 4));
    }
    else if (octave < 4)
    {
        heartz /= (2 * (4 - octave));
    }


//adjust frequency by semitones from A
    if (letter >= 67)
    {
        heartz *= pow(2, (semitones / 12));
        heartz /= 2;
    }
    else
    {
        heartz *= pow(2, (semitones / 12));
    }

    return round(heartz);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] == '\0') //checks if empty line
    {
        return true;
    }
    else
    {
        return false;
    }
}
