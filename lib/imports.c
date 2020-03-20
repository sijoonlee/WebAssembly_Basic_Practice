#include <stdio.h>
#include <emscripten.h>

// wrapper
EM_JS(void, jsFunction, (int n), {
    console.log("call from EM_JS: " + n);
});

int main(){
    printf("ready!!!\n"); // need to be flushed by using \n

    // call JS function
    emscripten_run_script("console.log('helllllo!')");
    
    // Async JS
    emscripten_async_run_script("console.log('helllllo! async')", 2000);
    
    // get return value from JS
    int jsVal = emscripten_run_script_int("getNum()");
    printf("Val from getNum() %d\n", jsVal);

    char* jsStr = emscripten_run_script_string("getStr()");
    printf("String from getStr() %s\n", jsStr);

    jsFunction(111);

    return 1;
}