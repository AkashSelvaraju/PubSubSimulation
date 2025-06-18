#include "Publisher.h"
#include <thread>
#include <chrono>

Publisher::Publisher(Broker &broker, const std::string &topic, std::function<std::string()> generator)
    : broker(broker), topic(topic), dataGenerator(generator) {}

// Starts publishing data periodically on a separate thread
void Publisher::startPublishing(int intervalMs, int count)
{
    std::thread([=]()
                {
        for (int i = 0; i < count; ++i) {
            std::string message = dataGenerator();
            broker.publish(topic, message);
            std::this_thread::sleep_for(std::chrono::milliseconds(intervalMs));
        } })
        .detach();
}
