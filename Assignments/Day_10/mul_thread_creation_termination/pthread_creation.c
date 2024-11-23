#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

// Define a buffer size for input string
#define MAX_STR_LEN 1024

// Global variables to hold the results
int word_count = 0;
int char_count = 0;

// Function to count the words in the input string
void *startroutine1(void *thr_p)
{
    char *input_str = (char *)thr_p;
    int count = 0;
    char *token = strtok(input_str, " "); // Split the string by spaces

    // Count words by splitting the string
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, " ");
    }

    word_count = count; // Store the word count globally
    pthread_exit((void *)&word_count);
}

// Function to count characters in the input string
void *startroutine2(void *thr_p)
{
    char *input_str = (char *)thr_p;
    int count = strlen(input_str); // Use strlen to count the characters, including spaces

    char_count = count; // Store the character count globally
    pthread_exit((void *)&char_count);
}

// Function to be executed by the main thread, which creates two child threads
void *threadproc(void *thr_p)
{
    pthread_t tid1, tid2;
    int retval;
    char *input_str = (char *)thr_p;

    printf("Input string: %s\n", input_str); // Debugging statement

    // Create the first thread to count words
    retval = pthread_create(&tid1, NULL, startroutine1, (void *)input_str);
    if (retval != 0)
    {
        perror("Thread creation failed for counting words");
        pthread_exit(NULL);
    }

    // Create the second thread to count characters
    retval = pthread_create(&tid2, NULL, startroutine2, (void *)input_str);
    if (retval != 0)
    {
        perror("Thread creation failed for counting characters");
        pthread_exit(NULL);
    }

    int *word_result, *char_result;

    // Wait for the threads to complete and retrieve their results
    retval = pthread_join(tid1, (void **)&word_result);
    if (retval != 0)
    {
        perror("pthread_join failed for word count thread");
    }

    retval = pthread_join(tid2, (void **)&char_result);
    if (retval != 0)
    {
        perror("pthread_join failed for character count thread");
    }

    // Display the results
    printf("Word Count: %d\n", *word_result);
    printf("Character Count: %d\n", *char_result);

    pthread_exit(NULL);
}

// Main function to read input and start the threadproc
int main()
{
    char input[MAX_STR_LEN]; // Buffer to read input

    // Read a line of text from the user
    printf("Enter a line of text: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character if it exists
    input[strcspn(input, "\n")] = 0;

    // Call threadproc to handle word and character counting
    threadproc((void *)input);

    return 0;
}

