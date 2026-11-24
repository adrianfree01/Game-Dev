#include <stdio.h>
#include <stdlib.h>
#include "engine.h"


int main() {
    
    struct engineStruct engineWindow;
    if(!createWindow(500, 500, "Engine", &engineWindow))
        return 1;

    windowLoop(&engineWindow);
    
    destroyWindow(&engineWindow);
    return 0;
    


}