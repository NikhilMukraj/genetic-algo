import wrapper as w


# gcc -fPIC -shared -rdynamic neuralnet.c -o neuralnet.so
lib = w.init_c()

inputs = w.toCDoubleArray([0, 0])
weights = w.toCDoubleArray([0, 0])
bias = w.toCDouble(bias)
length = w.toCInt(length)

answer = lib.sigmoid(inputs, weights, bias, length)
print(w.CDoubletoPyArray(answer, length))