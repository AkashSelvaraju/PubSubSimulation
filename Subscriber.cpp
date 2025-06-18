#include "Subscriber.h"
#include <iostream>

Subscriber::Subscriber(const std::string &name) : name(name) {}

// Called when a message is received on a topic
void Subscriber::receive(const std::string &topic, const std::string &message)
{
    std::cout << "[Subscriber: " << name << "] Received on topic '" << topic << "': " << message << std::endl;
}
