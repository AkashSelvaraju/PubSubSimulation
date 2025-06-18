#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <string>
#include <functional>
#include "Broker.h"

// Simulates a sensor (Publisher) that sends data to a topic
class Publisher
{
    std::string topic;
    Broker &broker;
    std::function<std::string()> dataGenerator;

public:
    Publisher(Broker &broker, const std::string &topic, std::function<std::string()> generator);
    void startPublishing(int intervalMs, int count = 5);
};

#endif
