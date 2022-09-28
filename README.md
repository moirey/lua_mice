# lua_mice

用lua讀取mouse event的example, 我用luajit的ffi來呼叫用c實做的open/read/close event function.

gcc -shared -fPIC -o libmice.so mice.c
