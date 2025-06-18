#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>

// Represents an observer that receives messages from the broker
class Subscriber
{
    std::string name;

public:
    Subscriber(const std::string &name);
    void receive(const std::string &topic, const std::string &message);
};

#endif
