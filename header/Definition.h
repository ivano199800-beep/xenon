#ifndef DEFINE
#define DEFINE
typedef struct 
{
    char** value;
    int count;
} Argument;

Argument* CreateArgument(int count, char** value) {
    Argument* arg = malloc(sizeof *arg);
    if (!arg) return NULL;

    arg->count = count;
    arg->value = malloc(sizeof(char*) * arg->count);
    if (!arg->value) {
        free(arg);
        return NULL;
    }

    return arg;
}
void DestroyArgument(Argument *arg){
    for (int i = 0;i<=arg->count;i++) {
        free(arg->value[i]);
    }
    if (arg->value == NULL) {
        free(arg->value);
    }
    free(arg);
}

#endif