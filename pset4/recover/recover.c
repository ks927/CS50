#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover file\n");
        return 1;
    }

    char *file = argv[1];
    // Open card.raw
    FILE *jpeg_ptr = fopen(file, "r");
    if (jpeg_ptr == NULL)
    {
        fprintf(stderr, "Could not read given %s\n", file);
        return 2;
    }

    // Read 512 bytes at a time into card
    // declare a BYTE as buffer
    BYTE buffer[512];
    bool found_first_jpg = false;
    FILE *new_jpeg_ptr;
    int jpeg_count = 0;
    // While we are not at the EOF
    while(fread(buffer, 1, 512, jpeg_ptr) != 0x00)
    {
        // If we find jpg headers
        if(buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
             buffer[2] == 0xff &&
              (buffer[3] & 0xf0) == 0xe0)
              {
                  // if we have found first jpg
                    if (!found_first_jpg)
                    {
                        // set bool to true
                        found_first_jpg = true;

                        // Open new file and write bytes into it
                        char filename[8];
                        sprintf(filename, "%03i.jpg", jpeg_count++);
                        new_jpeg_ptr = fopen(filename, "w");
                        if (new_jpeg_ptr == NULL)
                            return 3;
                        fwrite(buffer, 1, 512, new_jpeg_ptr);
                    }
                    else
                    {
                        if (found_first_jpg)
                        {
                            // close previous file
                            fclose(new_jpeg_ptr);

                            // write bytes into a new file
                            char filename[8];
                            sprintf(filename, "%03i.jpg", jpeg_count++);
                            new_jpeg_ptr = fopen(filename, "w");
                            if (new_jpeg_ptr == NULL)
                                return 3;
                            fwrite(buffer, 1, 512, new_jpeg_ptr);
                        }
                    }
              }
    }
    // close all files
    fclose(new_jpeg_ptr);
    fclose(jpeg_ptr);
}