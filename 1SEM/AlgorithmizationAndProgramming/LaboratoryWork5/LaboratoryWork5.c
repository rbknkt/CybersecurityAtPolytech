#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main(int argc, char* argv[]) {
    FILE* input_file = fopen(argv[1], "r");
    FILE* output_file = fopen(argv[4], "w");
    FILE* replace_file;
    FILE* replace_with_file;
    int c;
    int search_word;
    int replace_word;
    long input_pos = 0;
    while ((c = fgetc(input_file)) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            int word_check = 0;
            int replace_index = 0;
            replace_file = fopen(argv[2], "r");
            search_word = fgetc(replace_file);
            while (search_word != EOF && word_check == 0) {
                replace_with_file = fopen(argv[3], "r");
                word_check = 1;
                while (search_word != '\n' && search_word != EOF) {
                    if (c != search_word) {
                        word_check = 0;
                    }
                    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                        word_check = 0;
                    }
                    if (word_check == 1) {
                        c = fgetc(input_file);
                    }
                    search_word = fgetc(replace_file);
                }
                if (c == 'p') {
                    printf("");
                }
                if (word_check == 0) {
                    fseek(input_file, input_pos, SEEK_SET);
                    c = fgetc(input_file);
                    replace_index++;
                    fclose(replace_with_file);
                }
                else {
                    int j = 0;
                    while (j < replace_index) {
                        replace_word = fgetc(replace_with_file);
                        if (replace_word == '\n') {
                            j++;
                        }
                    }
                    replace_word = fgetc(replace_with_file);
                    while (replace_word != EOF && replace_word != '\n') {
                        fputc(replace_word, output_file);
                        replace_word = fgetc(replace_with_file);
                    }
                    if (c != 'z') {
                        fputc(c, output_file);
                    }
                    fclose(replace_with_file);
                }
                if (search_word != EOF) {
                    search_word = fgetc(replace_file);
                }
            }
            if (word_check == 0) {
                while ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                    fputc(c, output_file);
                    c = fgetc(input_file);
                }
                if (c != EOF && c != 'z') {
                    fputc(c, output_file);
                }
            }
        }
        else if (c != 'z') {
            fputc(c, output_file);
        }
        input_pos = ftell(input_file);
    }
    fclose(input_file);
    fclose(output_file);
    printf("great!\n");
    return 0;
}