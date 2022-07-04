import wrapper as w


# gcc -fPIC -shared -rdynamic neuralnet.c -o neuralnet.so
c_func = w.init_c()
c_func.a_tanh()