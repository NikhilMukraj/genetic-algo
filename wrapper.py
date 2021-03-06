import ctypes
import os
# all of this needs testing
# refactor with restype and argtype


def init_c():
    path = os.path.dirname(os.path.abspath(__file__))
    try:
        lib = ctypes.CDLL(path + '\\neuralnet.so')
    except OSError:
        try:
            lib = ctypes.CDLL(path + '/neuralnet.so')
        except:
            raise FileNotFoundError('Cannot find neuralnet.so')
    
    return lib

#https://stackoverflow.com/questions/24640817/python-ctypes-definition-for-c-struct
#https://doc.sagemath.org/html/en/thematic_tutorials/numerical_sage/ctypes_examples.html
#https://github.com/jima80525/ctypes_example/blob/master/tutorial2/testWrappedPoint.py
class layer(ctypes.Structure):
    _fields_ = [('input_len', ctypes.c_int),
                ('layer_len', ctypes.c_int),
                ('weights', ctypes.POINTER(ctypes.POINTER(ctypes.c_double))),
                ('biases', ctypes.POINTER(ctypes.c_double)),
                ('activation', ctypes.c_char)]

class nn(ctypes.Structure):
    _fields_ = [('layers', ctypes.POINTER(LayerStruct)),
                ('len', ctypes.c_int)]

def toCDouble(value):
    return ctypes.c_double(value)

def toCInt(value):
    return ctypes.c_int(value)

def toCChar(value):
    try:
        return ctypes.c_char(value)
    except TypeError:
        return ctypes.c_char(ord(value))

def CValtoPyValue(c_value):
    return c_value.value

def toCDoubleArray(arr):
    return (ctypes.c_double * len(arr))(*arr)

def CDoubletoPyArray(arr, length):
    py_arr = []
    for i in range(length):
        py_arr.append(arr[i])
    
    return py_arr

def doubleToArrayToPointer(arr, shape):
    """
    shape = (n, m)
    """
    ARR_DIMX = ctypes.c_double * arr.shape[1]
    ARR_DIMY = ctypes.POINTER(ctypes.c_double) * arr.shape[0]

    arr_ptr = ARR_DIMY()

    for i, row in enumerate(arr):
        arr_ptr[i] = ARR_DIMX()

        for j, val in enumerate(row):
            arr_ptr[i][j] = val

    return arr_ptr

def writeToLayer(layer, arr, shape):
    """
    shape = (n,m)
    """
    if layer.layer_len == n and layer.input_len == m:
        layer.weights = doubleToArrayToPointer(arr, shape)
    else:
        raise ValueError(f'Weights with shape of {shape}')

def init_weights(lib, layer, randomized):
    if randomized not in [0, 1]:
        raise ValueError(f'{randomized} is not a valid argument')
    lib.init_weights.argtype = [ctypes.POINTER(layer), ctypes.c_int]
    lib.init_weights(layer, randomized)

def init_biases(lib, layer, randomized):
    if randomized not in [0, 1]:
        raise ValueError(f'{randomized} is not a valid argument')
    lib.init_biases.argtype = [ctypes.POINTER(layer), ctypes.c_int]
    lib.init_biases(layer, randomized)

def output(lib, layer, inputs):
    lib.output.argtype = [ctypes.POINTER(layer), ctypes.POINTER(ctypes.c_double)]
    lib.output.restype = [ctypes.POINTER(ctypes.c_double)]
    return lib.output(layer, inputs)

def network_init(lib, nn, randomized):
    if randomized not in [0, 1]:
        raise ValueError(f'{randomized} is not a valid argument')
    lib.network_init.argtype = [ctypes.POINTER(nn), ctypes.c_int]
    lib.network_init(nn, randomized)

def layer_init(lib, nn, layer_num, randomized):
    if randomized not in [0, 1]:
        raise ValueError(f'{randomized} is not a valid argument')
    if layer_num >= nn.len or layer_num < 0:
        raise ValueError(f'{layer_num} is not a valid argument')
    lib.layer_init.argtype = [ctypes.POINTER(nn), ctypes.c_int, ctypes.c_int]
    lib.layer_init(nn, layer_num, randomized)

def create_nn(lib, arc):
    lib.create_nn.argtype = [ctypes.c_char_p]
    return lib.create_nn(arc.encode())

def add_layer(lib, nn, arc_part):
    lib.add_layer.argtype = [ctypes.POINTER(layer), ctypes.c_char_p]
    lib.add_layer(nn, arc_part.encode())

def feedforward(lib, nn, inputs):
    lib.feedforward.argtype = [ctypes.POINTER(layer), ctypes.c_char_p]
    lib.feedforward.restype = [ctypes.POINTER(ctypes.c_double)]
    return lib.feedforward(nn, toCDoubleArray(inputs))