# COMPILE OPTIONS

## html/js/wasm
emcc lib/demo.c -s WASM=1 -o public/demo.html
emcc lib/demo.c -s WASM=1 -o public/demo.js
emcc lib/demo.c -s WASM=1 -s SIDE_MODULE=1 -o public/demo.wasm

## optimize:shrink the size of .js and .wasm
emcc lib/demo.c -s WASM=1 -O2 -o public/demo.js

## Pre/Post
emcc lib/demo.c -s WASM=1 --post-js public/ready.js -o public/demo.js
emcc lib/demo.c -s WASM=1 --pre-js public/ready.js -o public/demo.js

## Export
emcc lib/demo.c -s WASM=1 -s EXPORTED_FUNCTIONS="['_getNum','_main']" -o public/demo.js
emcc lib/demo.c -s WASM=1 -s EXPORTED_FUNCTIONS="['_getNum','_main','_greet']" -o public/demo.js


# Preamble.js
https://emscripten.org/docs/api_reference/preamble.js.html

## ccall
Call a compiled C function from JavaScript
ccall(funcName, returnType, paramTypeList, paramValueList)
- ccall('greet') // 1034
- ccall('greet', 'string') // hello
- ccall('greet', 'string', ['string'], ['Joe']) // "Hello, Joe"

## cwrap
Returns a native JavaScript wrapper for a C function.
const greet = cwrap('greet', 'string', ['string'])

## memory
emcc lib/demo.c -s WASM=1 -s EXPORTED_FUNCTIONS="['_getNum','_main','_greet']" -s TOTAL_MEMORY=64MB -o public/demo.js
-> Module.HEAP32.buffer.byteLength : 67108864

## emrun
emcc lib/strings.c -s WASM=1 --emrun -o public/str.html
emrun --port 8000 --no_browser public/str.html