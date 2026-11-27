
struct engine {
    void* window;
};

struct engine_struct_EngineConfig {
    int windowWidth;
    int windowHeight;
    char* windowName;
    int vsyncStatus; // 0 or 1
};

struct engine_struct_EngineApp {
    void (*onStart)(void);
    void (*onUpdate)(float);
    void (*onRender)(void);
    void (*onShutdown)(void);
    void* (*userData)(void);
};

void windowLoop(struct engine*);
int createWindow(int width, int height, char* windowName, struct engine*); 
void destroyWindow(struct engine*);
