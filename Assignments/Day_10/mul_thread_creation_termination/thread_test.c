#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

// Define the structure for thread arguments
typedef struct {
    unsigned long long large_serial_number;
    const char *my_name;
    pthread_t caller_thread;
} fun_thread_args_t;

#define NUM_LOOPS 5u

// Thread function to perform the desired work
static void* _fun_thread_run(void *arg) {
    // Get our thread args from the dynamically allocated thread args passed-in
    fun_thread_args_t *thread_args = (fun_thread_args_t *)arg;

    unsigned int counter = 0;
    bool done = false;

    while (!done) {
        // Use args here in your thread loop
        counter++;
        printf("My name is: '%s', my number is: %llX, loop count: %u\n",
               thread_args->my_name,
               thread_args->large_serial_number,
               counter);

        if (counter >= NUM_LOOPS) {
            printf("'%s' is sooooo done.\n", thread_args->my_name);
            done = true;
        } else {
            sleep(1u);
        }
    }

    // Free incoming args pointer before exiting the thread loop.
    free(arg);
    return NULL;
}

// Function to launch a thread with the provided arguments
static pthread_t *_launch_fun_thread(pthread_t *thread, unsigned long long serial_number, const char *name) {
    // Allocate memory and prepare args for the thread
    fun_thread_args_t *args = (fun_thread_args_t *)calloc(1, sizeof(fun_thread_args_t));

    // Check for memory allocation failure
    if (args == NULL) {
        perror("Failed to allocate memory for thread arguments");
        return NULL;
    }

    // Initialize the arguments
    args->caller_thread = pthread_self();
    args->large_serial_number = serial_number;
    args->my_name = name;

    // Create the thread
    int rc = pthread_create(thread, NULL, &_fun_thread_run, args);

    // If thread creation fails, free the allocated memory and return NULL
    if (rc != 0) {
        perror("Thread creation failed");
        free(args);  // Free memory on failure
        return NULL;
    }

    return thread;
}

int main(void) {
    puts("The fun we are having!");

    pthread_t fun_thread1;
    pthread_t fun_thread2;

    // Launch first thread
    if (_launch_fun_thread(&fun_thread1, 0xABCDEF12345678ULL, "super FUN thread 1") == NULL) {
        return EXIT_FAILURE;
    }

    usleep(500UL * 1000UL);  // Sleep for 500ms

    // Launch second thread
    if (_launch_fun_thread(&fun_thread2, 0xDEADBEEF55AA55ULL, "super FUN thread 2") == NULL) {
        return EXIT_FAILURE;
    }

    // Wait for both threads to finish
    pthread_join(fun_thread1, NULL);
    pthread_join(fun_thread2, NULL);

    puts("We are done having fun :(");

    return EXIT_SUCCESS;
}

