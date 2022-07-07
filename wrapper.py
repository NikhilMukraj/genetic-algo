import ctypes
import os
# all of this needs testing


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
class LayerStruct(ctypes.Structure):
    _fields_ = [('input_len', ctypes.c_int),
                ('layer_len', ctypes.c_int),
                ('weights', ctypes.POINTER(ctypes.POINTER(ctypes.c_double))),
                ('biases', ctypes.POINTER(ctypes.c_double)),
                ('activation', ctypes.c_char)]

class NNStruct(ctypes.Structure):
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

def double2ArrayToPointer(arr, shape):
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

def getNetworkStruct(args):
    pass

def load_nn(filename):
    pass

def save_nn(filename):
    pass