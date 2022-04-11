#include <iostream>
#include "../Headers/Network.hpp"
#include "../Headers/Location.hpp"

int main() {
    Location target(10.f);

    Network evoNet(target);

    bool keepTraining = false;
    for (int i=1; !keepTraining; i++) {
        printf("%d:\n", i+1);
        keepTraining = evoNet.train();
        printf("\n");
    }


    
    
    return 0;
}
