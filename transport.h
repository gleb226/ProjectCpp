#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>
#include <vector>

struct Transport {
    int id;
    std::string name;
};

extern std::vector<Transport> transports;

void createTransport(const std::string& name);
Transport* getTransportById(int id);
void updateTransport(int id, const std::string& newName);
void deleteTransport(int id);

#endif
