#include "../Headers/Network.hpp"

#define GRID_SIZE 20

Network::Network(Location target): target(target) {
    srand(time(NULL));
    
    for (int i=0;i<INSTANCE_COUNT;i++) { //Create instances
        this->instances.push_back(Instance(Location(20)));
    }
}

Location Network::getTarget() {
    return this->target;
}

void Network::setTarget(Location target) {
    this->target = target;
}

bool Network::draw() {
    bool returnValue = false;

    for (int y=0;y<GRID_SIZE;y++) {
        for (int x=0;x<GRID_SIZE;x++) {

            int drewItem = 0;

            for (Instance i : this->instances) {
                if ((int)round(i.getLocation().getX()) == x && (int)round(i.getLocation().getY()) == y) {
                    drewItem++;
                }
                if (drewItem == INSTANCE_COUNT && i.getLocation() == this->target)
                    returnValue = true;
            }
            
            if (!drewItem)
                printf("- ");
            else
                printf("%d ", drewItem);

        }
        printf("\n");
    }

    return returnValue;
}

bool Network::train() {
    for (int l = 0; l < ITERATIONS; l++) {
        for(int i = 0; i < INSTANCE_COUNT; i++) {
            this->instances[i].run(this->target);
        }
    }

    bool returnVal = this->draw();   //visually displays the iterations

    float smallestDist = -1;
    Instance closest;

    for (Instance i : this->instances) {
        float thisDist = this->target.distance(i.getLocation());

        if (thisDist < smallestDist || smallestDist == -1) {
            smallestDist = thisDist;
            closest = i;
        }
    }

    for (int i=0;i<INSTANCE_COUNT;i++) { //Create instances
        this->instances[i] = Instance(Location(20), closest, smallestDist);
    }

    return returnVal;
        
}
