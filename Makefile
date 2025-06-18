CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

OBJS = main.o Broker.o Publisher.o Subscriber.o

mqtt_simulator: $(OBJS)
	$(CXX) $(CXXFLAGS) -o mqtt_simulator $(OBJS)

main.o: main.cpp Broker.h Publisher.h Subscriber.h
Broker.o: Broker.cpp Broker.h Subscriber.h
Publisher.o: Publisher.cpp Publisher.h Broker.h
Subscriber.o: Subscriber.cpp Subscriber.h

clean:
	rm -f *.o mqtt_simulator
