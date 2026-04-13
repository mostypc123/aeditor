#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fputs("Usage: aeditor <file>\n", stderr);
        return 2;
    }

    FILE* fbuf = fopen(argv[1], "a");
    int ibuf;
    
    if (fbuf == NULL) {
        fputs("Cannot open file.\n", stderr);
        perror("aeditor");
        return 1;
    }

    fputs("Press Ctrl+D to close. Aeditor saves your file automatically.\n", stdout);
    while ((ibuf = getchar()) != EOF) {
        fputc(ibuf, fbuf);
    }
    fclose(fbuf);
    fputs("Goodbye!\n", stderr);
    return 0;
}
