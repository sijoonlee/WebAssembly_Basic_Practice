#include <stdio.h>
#include <emscripten.h>

char* str = "test";

char* strFromC(){
    return str;
}

int debuggerInside(){
    int n = 123;

    // debugging break point
    // emscripten_debugger(); 
    
    // logging : https://emscripten.org/docs/api_reference/emscripten.h.html#logging-utilities
    if(n<1000){
        emscripten_log(EM_LOG_WARN, "test warning: n<1000");
    }

    return n;
}

int main(){

    printf("wasm ready\n");
    return 1;
}