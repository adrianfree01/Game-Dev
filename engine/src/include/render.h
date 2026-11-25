typedef void (*ProcFn)(void); //pointer to a function with no args
typedef ProcFn (*LoadFn)(const char*); //pointer to a function that takes a name, and returns a ProcFn

int initGlad(LoadFn load, int width, int height);
void renderScreen(void);
void resizeViewport(int width, int height);