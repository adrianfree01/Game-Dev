
struct engineStruct {
    void* window;
};

void windowLoop(struct engineStruct*);
int createWindow(int width, int height, char* windowName, struct engineStruct*); 
void destroyWindow(struct engineStruct*);
