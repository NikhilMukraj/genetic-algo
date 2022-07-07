import wrapper as w
import ctypes as c
import numpy as np


# gcc -fPIC -shared -rdynamic neuralnet.c -o neuralnet.so
lib = w.init_c()

'''
inputs = w.toCDoubleArray([1])
weights = w.toCDoubleArray([1])
bias = w.toCDouble(0)
length = w.toCInt(1)

sig = lib.a_sigmoid

sig.argtype = [c.POINTER(c.c_double), c.POINTER(c.c_double), c.c_double, c.c_int]
sig.restype = c.c_double

answer = sig(inputs, weights, bias, length)
print(answer)
'''

layer = w.LayerStruct()
layer.input_len = w.toCInt(1)
layer.layer_len = w.toCInt(3)
weights = np.random.uniform(0,1,size=(2,3))
layer.weights = w.double2ArrayToPointer(weights, (2,3))
layer.biases = w.toCDoubleArray([1, 1, 3])
layer.activation = w.toCChar('r')

for i in range(2):
    for j in range(3):
        print(layer.weights[i][j])