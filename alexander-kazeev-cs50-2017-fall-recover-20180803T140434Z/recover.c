#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

typedef uint_least8_t  MYBYTE;

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    MYBYTE blockArray[BLOCK_SIZE];
    int jpegCount = 0;
    int isJpegOpen = 0;
    FILE *outptr = NULL;

    //Iterate until EOF
    while (fread(blockArray, BLOCK_SIZE, 1, inptr) == 1)
    {
        if (blockArray[0] == 0xff && blockArray[1] == 0xd8 && blockArray[2] == 0xff && (blockArray[3] & 0xf0) == 0xe0)
        {
            //Close previous jpeg
            if (isJpegOpen == 1)
            {
                fclose(outptr);
            }

            //Open new jpeg
            isJpegOpen = 1;
            char filename[8];
            sprintf(filename, "%03d.jpg", jpegCount);
            outptr = fopen(filename, "w");

            //change count
            jpegCount++;
        }

        //write block to jpeg
        if (isJpegOpen == 1)
        {
            fwrite(blockArray, BLOCK_SIZE, 1, outptr);
        }
    }

    //close last jpeg
    if (isJpegOpen == 1)
    {
        fclose(outptr);
    }

    // close infile
    fclose(inptr);

}