#include "../Headers/Network.hpp"

#define GRID_SIZE 20

Network::Network(Location target): target(target) {
    srand(time(NULL));
    
    for (int i=0;i<INSTANCE_COUNT;i++) { //Create instances
        this->instances.push_back(Instance(Location(20)));
    }
}

void Network::draw() {
    for (int y=0;y<GRID_SIZE;y++) {
        for (int x=0;x<GRID_SIZE;x++) {

            int drewItem = 0;

            for (Instance i : this->instances) {
                if ((int)round(i.getLocation().getX()) == x && (int)round(i.getLocation().getY()) == y) {
                    drewItem++;
                }
            }
            
            if (!drewItem)
                printf("- ");
            else
                printf("%d ", drewItem);

        }
        printf("\n");
    }
}

void Network::train() {
    for (int l = 0; l < ITERATIONS; l++) {
        for(int i = 0; i < INSTANCE_COUNT; i++) {
            this->instances[i].run(this->target);
        }
    }

    this->draw();   //visually displays the iterations

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
        this->instances[i] = Instance(Location(20), closest);
    }
        
}
