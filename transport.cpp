#include "transport.h"
#include <algorithm>

std::vector<Transport> transports;
static int currentId = 1;

void createTransport(const std::string &name) {
    Transport t;
    t.id = currentId++;
    t.name = name;
    transports.push_back(t);
}

Transport *getTransportById(int id) {
    for (auto &t: transports) {
        if (t.id == id) return &t;
    }
    return nullptr;
}

void updateTransport(int id, const std::string &newName) {
    Transport *t = getTransportById(id);
    if (t) {
        t->name = newName;
    }
}

void deleteTransport(int id) {
    transports.erase(std::remove_if(transports.begin(), transports.end(),
                                    [id](const Transport &t) { return t.id == id; }), transports.end());
}
