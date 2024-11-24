/************************************************************************
*    FILENAME     : main.c
*    DESCRIPTION  : Read data from input file, stores in Hash Table,
*                   resolves collision using chaining, and displays
*                   contents of Hash Table.
**************************************************************************/
#include "header.h"

int main(int argc, char *argv[]) {
    FILE *in_file, *out_file;
    HT_node *hash_table[HASH_TABLE_SIZE] = {0};
    int ret_val;

    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return FAILURE;
    }

    if ((ret_val = Fopen(&in_file, argv[1], "r")) == FAILURE) {
        printf("Failed to open input file: %s\n", argv[1]);
        return FAILURE;
    }

    if ((ret_val = read_file(in_file, hash_table)) == FAILURE) {
        free_hash(hash_table);
        return FAILURE;
    }

    Fclose(&in_file);

    if ((ret_val = Fopen(&out_file, argv[2], "w")) == FAILURE) {
        free_hash(hash_table);
        return FAILURE;
    }

    if ((ret_val = write_file(out_file, hash_table)) == FAILURE) {
        free_hash(hash_table);
        return FAILURE;
    }

    Fclose(&out_file);
    free_hash(hash_table);

    printf("Output written to %s\n", argv[2]);
    return SUCCESS;
}

