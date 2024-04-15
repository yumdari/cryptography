#include <stdio.h>
#include <stdlib.h>
#include "crc32.c"

void help(void);
void error(int);


int main(int argc, char* argv[]) {
    FILE* in;

    if (argc == 1) help();
    if ((in = fopen(argv[1], "rb")) == NULL) error(1);

    printf("%08lX: %s\n", getFileCRC(in), argv[1]);

    fcloseall();
    return 0;
}

void help(void) {
    printf("\n\tGet the CRC32 of a given file\n\n\tUsage: this_program_name <file_name>\n");
    exit(1);
}

void error(int number) {
    switch (number) {
    case 1: fputs("Cannot open input file.\n", stderr); break;
    }
    exit(number);
}