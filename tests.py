import wrapper as w
import ctypes as c


# gcc -fPIC -shared -rdynamic neuralnet.c -o neuralnet.so
lib = w.init_c()

inputs = w.toCDoubleArray([1])
weights = w.toCDoubleArray([1])
bias = w.toCDouble(0)
length = w.toCInt(1)

sig = lib.a_sigmoid

sig.argtype = [c.POINTER(c.c_double), c.POINTER(c.c_double), c.c_double, c.c_int]
sig.restype = c.c_double

answer = sig(inputs, weights, bias, length)
print(answer)