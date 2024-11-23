#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_WORDS 5

// Structure to pass data to each thread
typedef struct {
    char *word;
    int thread_num;
    char *modified_word;
} thread_data_t;

// Function to append "_ed" to the word and return it
void *process_word(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    
    // Allocate memory for the modified word
    data->modified_word = (char *)malloc(strlen(data->word) + 4); // "_ed" = 3 chars
    if (data->modified_word == NULL) {
        perror("Memory allocation failed");
        pthread_exit(NULL);
    }
    
    // Append "_ed" to the word
    strcpy(data->modified_word, data->word);
    strcat(data->modified_word, "_ed");
    
    pthread_exit(NULL); // Thread exits
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > MAX_WORDS + 1) {
        fprintf(stderr, "Usage: %s word1 [word2] [word3] ... [word5]\n", argv[0]);
        return 1;
    }

    pthread_t threads[MAX_WORDS];
    thread_data_t thread_data[MAX_WORDS];

    // Create threads for each word
    for (int i = 1; i < argc; ++i) {
        thread_data[i - 1].word = argv[i];
        thread_data[i - 1].thread_num = i;

        // Create a new thread for each word
        if (pthread_create(&threads[i - 1], NULL, process_word, (void *)&thread_data[i - 1]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for each thread to finish and retrieve the result
    for (int i = 0; i < argc - 1; ++i) {
        pthread_join(threads[i], NULL);

        // Print the result
        printf("Thread %d: %s\n", thread_data[i].thread_num, thread_data[i].modified_word);
        
        // Free the allocated memory
        free(thread_data[i].modified_word);
    }

    return 0;
}

