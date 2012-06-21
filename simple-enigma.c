#include <ctype.h>
#include <stdio.h>
#include <string.h>

const char *rotors[] = {
//    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
//    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
//    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",

    "GDACBXHRZTNVUPLQWEYFMKIOSJ",
    "EDCZMHWLIXYBOJKNRSTFGPVAQU",
    "MQGFBZPLDUTIASOVHWXYEJRCNK",
};

typedef struct {
    int rotor1_index;
    int rotor2_index;
    int rotor3_index;
} rotor_set_t;

char
accept_char(const char input, const char *rotor, const int rotor_offset)
{
    int char_offset = ((input - 'A') + rotor_offset) % 25;
    return rotor[char_offset];
}

int
main(int argc, const char **argv)
{
    printf("simple-enigma v0:\n");

    int rotor_offsets[] = {
        0,
        0,
        0,
    };

    rotor_set_t rotor_state;
    memset(&rotor_state, 0x00, sizeof(rotor_state));

    char c = 0;
    while ((c = getc(stdin)))
    {
        if (c == '\n')
        {
            printf("%c", c);
            break;
        } else if (c < 'A' || c > 'z')
        {
            printf("%c", c);
            continue;
        }

        char uc = toupper(c);

        uc = accept_char(uc, rotors[0], rotor_offsets[0]);
        uc = accept_char(uc, rotors[1], rotor_offsets[1]);
        uc = accept_char(uc, rotors[2], rotor_offsets[2]);

        // only increment the first rotor (its broken, remember?)
        rotor_offsets[0]++;

        printf("%c", uc);
    }
    return 0;
}
