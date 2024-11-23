#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define SLEEP_INTERVAL 2 // Time interval for health check (in seconds)
#define NUM_INTERVAL 3   // Time interval for printing numbers (in seconds)

pthread_t thread1, thread2, thread3;

// Function for Thread 1: Print "Health OK" every 2 seconds
void *thread1_func(void *arg) {
    struct timespec ts;
    while (1) {
        clock_gettime(CLOCK_REALTIME, &ts);
        printf("[%ld] Health OK\n", ts.tv_sec);
        sleep(SLEEP_INTERVAL);
    }
    return NULL;
}

// Function for Thread 2: Print numbers starting from 1000 every 3 seconds
void *thread2_func(void *arg) {
    int count = 1000;
    struct timespec ts;
    while (1) {
        clock_gettime(CLOCK_REALTIME, &ts);
        printf("[%ld] %lu %d\n", ts.tv_sec, pthread_self(), count);
        count += 2;
        sleep(NUM_INTERVAL);
    }
    return NULL;
}

// Function for Thread 3: Print numbers starting from 2000 every 3 seconds
void *thread3_func(void *arg) {
    int count = 2000;
    struct timespec ts;
    while (1) {
        clock_gettime(CLOCK_REALTIME, &ts);
        printf("[%ld] %lu %d\n", ts.tv_sec, pthread_self(), count);
        count += 2;
        sleep(NUM_INTERVAL);
    }
    return NULL;
}

int main() {
    // Create and configure thread 1
    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_detach(thread1);  // Detach thread 1
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);  // Disable cancellation for thread 1

    // Create and configure thread 2
    pthread_create(&thread2, NULL, thread2_func, NULL);
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);  // Enable cancellation for thread 2
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL); // Deferred cancellation for thread 2

    // Create and configure thread 3
    pthread_create(&thread3, NULL, thread3_func, NULL);
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);  // Enable cancellation for thread 3
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL); // Asynchronous cancellation for thread 3

    // Sleep for 3 minutes before canceling threads
    sleep(3 * 60);

    // Cancel all threads after 3 minutes
    pthread_cancel(thread1);
    pthread_cancel(thread2);
    pthread_cancel(thread3);

    // Join threads to ensure they clean up
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("All threads have been canceled\n");

    return 0;
}

