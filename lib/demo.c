#include <stdio.h>
#include <string.h>

int main(){
    printf("ready!!!\n"); // need to be flushed by using \n
    return 1;
}

int getNum(){
    return 5;
}

char* greet(char* name){
    return strcat("Hello, ", name);
}