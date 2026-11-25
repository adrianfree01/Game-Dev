typedef void (*ProcFn)(void); //pointer to a function with no args
typedef ProcFn (*LoadFn)(const char*); //pointer to a function that takes a name, and returns a ProcFn

void initGlad(LoadFn load);