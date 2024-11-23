/* DESCRIPTION: Program to read a file and use threads to count words in each line.
   Date: 2024-11-23
   Name: Tirupati Pavani
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Structure to hold line and word count
typedef struct {
    char *line;
    int word_count;
} LineData;

// Thread function to count words in a line
void *count_words(void *arg) {
    LineData *data = (LineData *)arg;
    char *line = data->line;
    int count = 0;
    char *token = strtok(line, " \t\n");

    // Tokenize the line by space and count words
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \t\n");
    }

    data->word_count = count;
    return NULL;
}

// Function to create threads for each line
void create_threads(FILE *file, pthread_t **threads, LineData **line_data, int *line_count) {
    char line[MAX_LINE_LENGTH];
    int i = 0;

    // Read lines from file and create threads for each line
    while (fgets(line, sizeof(line), file)) {
        (*line_count)++;
        *line_data = realloc(*line_data, sizeof(LineData) * (*line_count));
        *threads = realloc(*threads, sizeof(pthread_t) * (*line_count));

        if (*line_data == NULL || *threads == NULL) {
            perror("Failed to allocate memory for threads or line_data");
            exit(EXIT_FAILURE);  // Exit on memory allocation failure
        }

        // Ensure the line is properly copied using strdup and check for NULL
        (*line_data)[i].line = strdup(line);
        if ((*line_data)[i].line == NULL) {
            perror("Failed to allocate memory for line");
            exit(EXIT_FAILURE);  // Exit on memory allocation failure
        }
        
        printf("Creating thread for line: %s\n", (*line_data)[i].line);  // Debugging line
        pthread_create(&(*threads)[i], NULL, count_words, &(*line_data)[i]);
        i++;
    }
}

// Function to process the file using threads
void process_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    pthread_t *threads = NULL;
    LineData *line_data = NULL;
    int line_count = 0;

    create_threads(file, &threads, &line_data, &line_count);

    // Wait for all threads to finish and display the results
    for (int i = 0; i < line_count; i++) {
        pthread_join(threads[i], NULL);
        printf("Line: \"%sWord Count: %d\n", line_data[i].line, line_data[i].word_count);
        free(line_data[i].line);  // Free memory for each line
    }

    free(threads);
    free(line_data);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_file(argv[1]);
    return EXIT_SUCCESS;
}

