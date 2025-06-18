#ifndef BROKER_H
#define BROKER_H

#include <string>
#include <map>
#include <vector>
#include <mutex>

class Subscriber; // Forward declaration

// Simulates an MQTT-like broker that manages topic subscriptions
class Broker
{
    std::map<std::string, std::vector<Subscriber *>> topicSubscribers;
    std::mutex mtx;

public:
    void subscribe(const std::string &topic, Subscriber *subscriber);
    void publish(const std::string &topic, const std::string &message);
};

#endif
