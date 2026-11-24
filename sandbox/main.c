#include <stdio.h>
#include <stdlib.h>
#include "engine.h"


int main(void*) {
    int width = 500;
    int height = 500;
    char* winName = "Engine";

    if(!createWindow(width, height, winName))
        return 1;
    return 0;
    


}