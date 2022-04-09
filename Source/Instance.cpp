#include "../Headers/Instance.hpp"


Instance::Instance() {

}

Instance::Instance(Location startPoint): location(startPoint) {
    this->location = startPoint;

    for (int i=0;i<INPUT_COUNT * OUTPUT_COUNT;i++)
        this->weights.push_back(Instance::constrain(fmod(rand(), (float)ORIGINAL_WEIGHT_DISTRIBUTION_DIVISOR) - (float)ORIGINAL_WEIGHT_DISTRIBUTION_DIVISOR/2.f)); //generates random wights
    
    for (int i=0;i<OUTPUT_COUNT;i++)
        this->biases.push_back(0);
}

Instance::Instance(Location startPoint, Instance previousInstance, float dist): 
location(startPoint) {
    this->weights = previousInstance.weights;   //copy the weights from the previous instance
    this->biases = previousInstance.biases;
    
    for(int i = 0; i < INPUT_COUNT * OUTPUT_COUNT; i++)   //offset the weights by a small amount
        this->weights[i] += fmod(((float)rand() / 10000), dist/100) - dist/2/100; //constrains the weight offset to 1 and -1
    for(int i = 0; i < OUTPUT_COUNT; i++)
	this->biases[i] += fmod(((float)rand() / 10000), dist/100) - dist/2/100;
}

float Instance::constrain(float num) {
    return (1 / (1 + powf(e, -num))) * 2 - 1;
}


void Instance::run(Location targetLocation) {

    Location offset;

    // Matrix multiplication
    offset.setX(this->location.getX() * this->weights[0] + this->location.getX() * this->weights[2] + this->biases[0]);
    
    offset.setY(this->location.getY() * this->weights[1] + this->location.getY() * this->weights[3] + this->biases[1]);

    offset.setX(Instance::constrain(offset.getX()));
    offset.setY(Instance::constrain(offset.getY()));


    // Normalize offset
    float length = offset.distance(Location(0));
    offset.setX(offset.getX() / length);
    offset.setY(offset.getY() / length);

    this->location.move(offset);
}

Location Instance::getLocation() {
    return this->location;
}
