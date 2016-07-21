#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdarg.h>

void *_ckalloc(size_t len, const char *file, const char *func, const int line) {
    
    char *ptr = malloc(len*sizeof(char *));
    fprintf(stdout, "[info] file: %s func: %s line: %d\n", file, func, (int)line);
    return ptr;
}

int main() {
    
    char **ch = (_ckalloc(10, __FILE__, __func__, __LINE__));
    char *ptr = (char *)(ch);
    ch[0] = strdup("666666666666");
    //strcpy(ch[0], "======++++++++++++++++++++======");
    printf("%s\n", ch[0]);
    return 0;
}
