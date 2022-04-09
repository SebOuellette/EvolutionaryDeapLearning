#pragma once

#include <vector>
#include <ctime>
#include "../Headers/Instance.hpp"

// 100 iterations per training session
#define ITERATIONS 100
#define INSTANCE_COUNT 100

class Network {
private:
    Location target;
    std::vector<Instance> instances;

public:
    Network(Location);

    void train();
    void draw();
};