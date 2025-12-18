#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../header/Definition.h"

int lexer(Argument Args) {

}
int main (int c, char**v) {
    Argument *arg = CreateArgument(c,v);
    printf(" loading... \033[2J\033[H
 ");
    DestroyArgument(arg);
    sleep(1);
    printf("done\n");
    return 0;
}