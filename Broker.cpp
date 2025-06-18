#include "Broker.h"
#include "Subscriber.h"
#include <thread>
#include <iostream>

void Broker::subscribe(const std::string &topic, Subscriber *subscriber)
{
    std::lock_guard<std::mutex> lock(mtx);
    topicSubscribers[topic].push_back(subscriber);
}

// Publishes a message to all subscribers asynchronously
void Broker::publish(const std::string &topic, const std::string &message)
{
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "[Broker] Publishing to topic '" << topic << "': " << message << std::endl;

    if (topicSubscribers.find(topic) != topicSubscribers.end())
    {
        for (auto *sub : topicSubscribers[topic])
        {
            // Deliver message asynchronously using a new thread
            std::thread([=]()
                        { sub->receive(topic, message); })
                .detach();
        }
    }
}
