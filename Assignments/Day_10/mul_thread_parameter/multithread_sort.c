/* DESCRIPTION : program to sort words in lines using multithreading
   Date : 2024-11-23
   Name : Tirupati Pavani
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LINE_LENGTH 256
#define NUM_LINES 3

typedef struct {
    char line[MAX_LINE_LENGTH];
    char sorted_line[MAX_LINE_LENGTH];
} ThreadData;

// Function to sort words in a line
void sort_words(char *line, char *sorted_line) {
    char *words[MAX_LINE_LENGTH];
    int count = 0;

    // Make a copy of the line to tokenize
    char temp_line[MAX_LINE_LENGTH];
    strcpy(temp_line, line);

    // Tokenize the line into words
    char *token = strtok(temp_line, " ");
    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    // Sort the words
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Reconstruct the sorted line
    sorted_line[0] = '\0'; // Initialize empty sorted_line
    for (int i = 0; i < count; i++) {
        strcat(sorted_line, words[i]);
        if (i < count - 1) {
            strcat(sorted_line, " ");
        }
    }
}

// Thread function
void *thread_function(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    sort_words(data->line, data->sorted_line);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s \"line1\\nline2\\nline3\"\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert \\n to \n in the input string
    char *input = argv[1];
    char processed_input[MAX_LINE_LENGTH];
    int pi_index = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\\' && input[i + 1] == 'n') {
            processed_input[pi_index++] = '\n';
            i++; // Skip 'n' in \\n
        } else {
            processed_input[pi_index++] = input[i];
        }
    }
    processed_input[pi_index] = '\0';

    // Split the input into lines
    char *lines[NUM_LINES];
    int line_count = 0;

    char *token = strtok(processed_input, "\n");
    while (token != NULL && line_count < NUM_LINES) {
        lines[line_count++] = token;
        token = strtok(NULL, "\n");
    }

    if (line_count != NUM_LINES) {
        fprintf(stderr, "Error: Exactly 3 lines are required.\n");
        return EXIT_FAILURE;
    }

    // Initialize thread data
    pthread_t threads[NUM_LINES];
    ThreadData thread_data[NUM_LINES];

    for (int i = 0; i < NUM_LINES; i++) {
        strcpy(thread_data[i].line, lines[i]);
        if (pthread_create(&threads[i], NULL, thread_function, &thread_data[i]) != 0) {
            perror("Error creating thread");
            return EXIT_FAILURE;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_LINES; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print sorted lines
    printf("Sorted Lines:\n");
    for (int i = 0; i < NUM_LINES; i++) {
        printf("%s\n", thread_data[i].sorted_line);
    }

    return EXIT_SUCCESS;
}

