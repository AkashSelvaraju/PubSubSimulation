#include "Broker.h"
#include "Publisher.h"
#include "Subscriber.h"
#include <cstdlib>
#include <ctime>
#include <thread>

int main()
{
    std::srand(std::time(nullptr)); // Seed for random number generation

    Broker broker;

    // Create subscribers and subscribe them to topics
    Subscriber speedSub("SpeedLogger");
    Subscriber tempSub("TempMonitor");

    broker.subscribe("speed", &speedSub);
    broker.subscribe("temperature", &tempSub);

    // Create publishers that simulate sensor data
    Publisher speedSensor(broker, "speed", []()
                          {
        int speed = rand() % 100;
        return "Speed: " + std::to_string(speed) + " km/h"; });

    Publisher tempSensor(broker, "temperature", []()
                         {
        int temp = 20 + rand() % 15;
        return "Temp: " + std::to_string(temp) + " °C"; });

    // Start publishing
    speedSensor.startPublishing(1000); // 1 second interval
    tempSensor.startPublishing(1500);  // 1.5 seconds

    // Allow simulation to run for 10 seconds
    std::this_thread::sleep_for(std::chrono::seconds(10));

    return 0;
}
