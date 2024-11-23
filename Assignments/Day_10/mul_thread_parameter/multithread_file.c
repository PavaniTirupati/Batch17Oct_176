/* DESCRIPTION : program to process a file using threads to count words in lines
   Date : 2024-11-23
   Name : Tirupati Pavani
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LINE_LENGTH 1024

// Structure to hold the result from each thread
typedef struct {
    char *line;          // Processed line
    int word_count;      // Count of words in the line
} ThreadResult;

// Thread function to process a single line
void *thread_proc(void *arg) {
    char *line = (char *)arg;
    int count = 0;

    // Count words in the line
    char *token = strtok(line, " \t\n");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \t\n");
    }

    // Allocate memory for the result
    ThreadResult *result = (ThreadResult *)malloc(sizeof(ThreadResult));
    result->line = strdup(line);  // Copy the processed line
    result->word_count = count;

    return (void *)result;
}

// Function to create threads
pthread_t *createthreads(int thread_count) {
    // Allocate memory for the thread array
    pthread_t *threads = (pthread_t *)malloc(thread_count * sizeof(pthread_t));
    if (threads == NULL) {
        fprintf(stderr, "Error allocating memory for threads.\n");
        exit(EXIT_FAILURE);
    }
    return threads;
}

// Function to process the file and assign each line to a thread
void process_file(const char *filename, pthread_t *threads, int thread_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int thread_index = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Duplicate the line for thread processing
        char *line_copy = strdup(line);
        if (line_copy == NULL) {
            fprintf(stderr, "Error allocating memory for line.\n");
            exit(EXIT_FAILURE);
        }

        // Create a thread to process the line
        if (pthread_create(&threads[thread_index], NULL, thread_proc, (void *)line_copy) != 0) {
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }

        thread_index++;
        if (thread_index == thread_count) {
            break;  // Stop if we have created the maximum allowed threads
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < thread_index; i++) {
        ThreadResult *result;
        pthread_join(threads[i], (void **)&result);

        // Display the results
        printf("Line: \"%s\", Word Count: %d\n", result->line, result->word_count);

        // Free memory allocated by the thread
        free(result->line);
        free(result);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <thread_count>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    int thread_count = atoi(argv[2]);
    if (thread_count <= 0) {
        fprintf(stderr, "Thread count must be a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    // Create threads
    pthread_t *threads = createthreads(thread_count);

    // Process the file
    process_file(filename, threads, thread_count);

    // Free allocated memory for threads
    free(threads);

    return 0;
}

