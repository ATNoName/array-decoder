#include <stdlib.h>
#include <stdio.h>
#include "arr.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fputs("Usage: arr_demo filename\n", stderr);
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        char err[256];
        sprintf(err, "Cannot open %s for reading\n", argv[1]);
        fputs(err, stderr);
        return 2;
    }
    int lines;
    arr_readn(f, 1, &lines);
    char str[10];
    fgets(str, 10, f);
    for (int i = 0; i < lines; i++) {
        char *line = malloc(100);
        arr_readline(f, 100, line);
        size_t n = 0;
        int *arr = arr_fromstr(line, &n);
        size_t dec_len = 0;
        int *decode = arr_decode(n, arr, &dec_len);
        for (int j = 0; j < dec_len; j++) {
            if (*(decode+j) == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        free(line);
        free(arr);
        free(decode);
        printf("\n");
    }
    return 0;
}