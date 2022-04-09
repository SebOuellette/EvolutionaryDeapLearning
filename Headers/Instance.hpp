#pragma once

#include <vector>
#include <cmath>
#include <random>
#include "../Headers/Location.hpp"

#define INPUT_COUNT 2
#define OUTPUT_COUNT 2

#define MUTATE_DIVISOR 1
#define ORIGINAL_WEIGHT_DISTRIBUTION_DIVISOR 6

#define e 2.71828182846

class Instance {
private:
    Location location;
    std::vector<float> weights;
    std::vector<float> biases;

public:
    Instance();
    Instance(Location);
    Instance(Location, Instance);
    Location getLocation();

    void run(Location);

    static float constrain(float);
};
