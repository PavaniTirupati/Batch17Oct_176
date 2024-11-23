#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void main_function(const char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();       // Returns Process ID
    tid = pthread_self(); // Returns Thread ID
    printf("%s PID: %lu TID: %lu (0x%lx)\n", s, (unsigned long)pid,
           (unsigned long)tid, (unsigned long)tid);
}

// Thread function to read username
void *startroutine1(void *arg)
{
    // Allocate memory for username on the heap
    char *username = (char *)malloc(100 * sizeof(char));
    if (username == NULL)
    {
        perror("Memory allocation failed");
        pthread_exit((void *)1);
    }

    // Read username from the user
    printf("Enter your username: ");
    fgets(username, 100, stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove newline character

    // Display thread information
    main_function("New thread:");

    // Return the username to the caller
    pthread_exit((void *)username);
}

int main(void)
{
    int retval;
    pthread_t threadid;
    char *thread_result;

    // Create a new thread
    retval = pthread_create(&threadid, NULL, startroutine1, NULL);
    if (retval != 0)
    {
        perror("Can't create thread");
        exit(1);
    }

    // Display main thread information
    main_function("Main thread:");

    // Wait for the child thread to complete and retrieve the result
    retval = pthread_join(threadid, (void **)&thread_result);
    if (retval != 0)
    {
        perror("Can't join thread");
        exit(1);
    }

    // Display the username returned by the thread
    printf("Username returned by the new thread: %s\n", thread_result);

    // Free the allocated memory
    free(thread_result);

    // Exit the program
    exit(0);
}

