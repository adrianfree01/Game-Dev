#include "engine.h"


int main() {
    
    struct engine engineWindow;
    if(!createWindow(800, 600, "Engine", &engineWindow))
        return 1;

    windowLoop(&engineWindow);
    
    destroyWindow(&engineWindow);
    return 0;
    


}