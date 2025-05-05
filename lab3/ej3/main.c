#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size) {
    FILE *file = fopen(path, "r");
    unsigned int i=0, index_aux;
    char letters_aux;
    int scanfres;

    while (feof(file) == 0 && i < max_size) {
        /*if (items_read >= max_size){
            fprintf(stderr, "Max ammount of indexes/letters reached\n");
            exit(EXIT_FAILURE);
        }*/

        scanfres = fscanf(file, "%u -> *%c*\n", &index_aux, &letters_aux);

        if (scanfres == EOF) {
            fprintf(stderr, "Invalid format\n");
            exit(EXIT_FAILURE);
        }
        
        if (index_aux >= max_size) {
            fprintf(stderr, "Inserted index is bigger than the max allowed size\n");
            exit(EXIT_FAILURE);
        }

        indexes[i] = index_aux;
        letters[i] = letters_aux;

        i++;
    }
    fclose(file);

    return i;
}

void prhase_sorted (char sorted[], char letters[], unsigned int indexes[], unsigned int length) {
    unsigned int j;
    for (unsigned int i = 0; i < length; ++i) {
        j = 0;
        while (indexes[j] != i) {
            j++;
        }
        sorted[i] = letters[j];
    }
    
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;
    filepath = parse_filepath(argc, argv);

    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0;

    length = data_from_file(filepath, indexes, letters, MAX_SIZE);

    prhase_sorted(sorted, letters, indexes, length);

    dump(sorted, length);

    return EXIT_SUCCESS;
}