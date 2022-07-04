import ctypes
import os
# all of this needs testing


def init_c():
    # init so file
    pass

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
    _fields_ = []

def toCDoubleArray(arr):
    return (ctypes.c_double * len(arr))(*arr)

def toPyArray(arr, length):
    return ctypes.cast(length, ctypes.POINTER(ctypes.c_int * length)).contents # need to test

def getNetworkStruct(args):
    pass

def load_nn(filename):
    pass

def save_nn(filename):
    pass