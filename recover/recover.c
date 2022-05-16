#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //open memory card
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }

    BYTE *buffer = malloc(512);
    char *filename = malloc(sizeof(char) * 8);
    int m = 0;

    //Read data from memory card
    while (fread(buffer, 1, 512, file) == 512)
    {
        //?JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (m == 0)
            {
                //Making a new JPEG
                sprintf(filename, "%03i.jpg", m);
                FILE *img = fopen(filename, "w");
                fwrite(buffer, 1, 512, img);
                fclose(img);
                m += 1;
            }

            else
            {
                sprintf(filename, "%03i.jpg", m);
                FILE *img = fopen(filename, "w");
                fwrite(buffer, 1, 512, img);
                fclose(img);
                m += 1;
            }
        }
        //Writing to files
        else
        {
            if (m > 0)
            {
                FILE *img = fopen(filename, "a");
                fwrite(buffer, 1, 512, img);
                fclose(img);
            }
        }
    }
    free(buffer);
    free(filename);

    //Pseudocode is followed as it can be seen
}