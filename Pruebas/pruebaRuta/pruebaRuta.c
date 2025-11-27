#include <stdio.h>
#include <direct.h>

int main() {
    char cwd[256];
    _getcwd(cwd, 256);
    printf("\nPrograma ejecutado desde: %s\n", cwd);
    return 0;
}
