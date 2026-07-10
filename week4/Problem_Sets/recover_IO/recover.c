#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BUFFER_SIZE 512
typedef uint8_t BYTE; 

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("\nUsage: ./recover [file]\n\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("\nCould not open %s.\n\n", argv[1]);
        return 1;
    }

    BYTE buffer[BUFFER_SIZE];
    FILE *img = NULL;
    int jpeg_count = 0;

    while (fread(buffer, 1, BUFFER_SIZE, card) == BUFFER_SIZE)
    {
        // Look for beginning of a JPEG
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL) fclose(img);

            char filename[8];
            sprintf(filename, "%03i.jpg", jpeg_count);
            img = fopen(filename, "wb");
            if (img == NULL)
            {
                printf("Could not create %s.\n\n", filename);
                fclose(card);
                return 1;
            }

            jpeg_count++;
        }

        if (img != NULL) fwrite(buffer, 1 , BUFFER_SIZE, img);
    }

    if (img != NULL) fclose(img);

    fclose(card);
    return 0;
}