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
weights = np.random.uniform(0,1,size=(layer.layer_len, layer.input_len))
layer.weights = w.double2ArrayToPointer(weights, (layer.layer_len, layer.input_len))
layer.biases = w.toCDoubleArray([1, 1, 1])
layer.activation = w.toCChar('r')

layer2 = w.LayerStruct()
layer2.input_len = w.toCInt(3)
layer2.layer_len = w.toCInt(3)
weights2 = np.random.uniform(0,1,size=(layer2.layer_len, layer2.input_len))
layer2.weights = w.double2ArrayToPointer(weights, (layer2.layer_len, layer2.input_len))
layer2.biases = w.toCDoubleArray([1, 1, 1])
layer2.activation = w.toCChar('s')

nn = w.NNStruct()
layers = (w.LayerStruct * 2)()
nn.layers = c.cast(layers, c.POINTER(w.LayerStruct))
nn.layers[0] = layer
nn.layers[1] = layer2

print(nn.layers[0].input_len, nn.layers[1].input_len)