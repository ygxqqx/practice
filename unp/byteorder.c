#include <stdio.h>
//测试计算机是大端还是小端
int main(){

    union{
        short s;
        char c[sizeof(short)];
    }un;
    un.s = 0x0102;
    if(sizeof(short) == 2){
        if(un.c[0] == 1 && un.c[1] == 2){
            printf("big duan\n");
        }
        else if(un.c[0] == 2 && un.c[1] == 1){
            printf("little duan\n");
        }
        else{
            printf("unknow\n");
        }
    }
    else{
        printf("sizeof(short) = %d\n", sizeof(short));
    }
    return 0;
}
