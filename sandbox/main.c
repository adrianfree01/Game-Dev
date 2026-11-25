#include "engine.h"


int main() {
    
    struct engineStruct engineWindow;
    if(!createWindow(800, 600, "Engine", &engineWindow))
        return 1;

    windowLoop(&engineWindow);
    
    destroyWindow(&engineWindow);
    return 0;
    


}