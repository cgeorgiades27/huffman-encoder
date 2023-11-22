#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_CHAR 128

void count_frequencies(FILE *, int *, size_t);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./huffman <filename>\n");
        return 1;
    }

    FILE *input_stream = fopen(argv[1], "r");
    if (!input_stream)
    {
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }

    int word_arr[MAX_CHAR];
    count_frequencies(input_stream, word_arr, MAX_CHAR);

    for (int i = 0; i < MAX_CHAR; ++i)
    {
        if (word_arr[i] > 0)
            printf("%c: %d\n", i, word_arr[i]);
    }

    fclose(input_stream);

    return 0;
}

void count_frequencies(FILE *input_stream, int *arr, size_t arr_size)
{
    int c;
    int count;
    c = count = 0;

    while ((c = fgetc(input_stream)) != EOF)
    {
        if (isalpha(c))
            arr[c]++;
    }
}
