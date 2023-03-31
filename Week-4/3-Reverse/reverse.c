#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if(argc != 3){
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if(input == NULL){
        printf("Could not open input file.\n");
        return 1;
    }

    // Read header
    // TODO #3
    int headerSize = 44;
    WAVHEADER header[1];
    fread(header, headerSize, 1, input);

    // Use check_format to ensure WAV format
    // TODO #4
    const int isRightFormat = check_format(header[0]);

    if(!isRightFormat){
        printf("Wrong file format.\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not create output file.\n");
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(header, headerSize, 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    const int blockSize = get_block_size(header[0]);

    // Write reversed audio to file
    // TODO #8
    uint8_t buffer[blockSize];
    for(int i = 0; i < header[0].subchunk2Size / blockSize; i++){
        fseek(input, (i + 1) * blockSize * -1, SEEK_END);

        fread(&buffer, blockSize, 1, input);

        fwrite(&buffer, blockSize, 1, output);
    }

    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    const char expectedChars[] = {'W', 'A', 'V', 'E'};

    for(int i = 0; i < 4; i++){
        if(header.format[i] != expectedChars[i]){
            return 0;
        }
    }

    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    const int blockSize = header.numChannels * (header.bitsPerSample / 8);

    return blockSize;
}