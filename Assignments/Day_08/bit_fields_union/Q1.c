#include <stdio.h>

// Define a structure with bit fields for Traffic Light status
struct TrafficLight {
    unsigned int red : 1;    // 1 bit for red light status (0 = off, 1 = on)
    unsigned int green : 1;  // 1 bit for green light status
    unsigned int orange : 1; // 1 bit for orange light status
};

int main() {
    struct TrafficLight trafficLight;
    
    // Set the status of the traffic light
    trafficLight.red = 1;    // Red light is ON
    trafficLight.green = 0;  // Green light is OFF
    trafficLight.orange = 1; // Orange light is ON

    // Display the traffic light status
    printf("Red Light: %s\n", trafficLight.red ? "ON" : "OFF");
    printf("Green Light: %s\n", trafficLight.green ? "ON" : "OFF");
    printf("Orange Light: %s\n", trafficLight.orange ? "ON" : "OFF");

    return 0;
}

