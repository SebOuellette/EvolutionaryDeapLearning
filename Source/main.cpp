#include <iostream>
#include "../Headers/Network.hpp"
#include "../Headers/Location.hpp"

int main() {
    Location target(10.f);

    Network evoNet(target);

    for(int i = 0; i < 100; i++) {
        printf("%d:\n", i+1);
        evoNet.train();
        printf("\n");
    }


    
    
    return 0;
}
