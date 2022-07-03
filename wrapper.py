import ctypes


#https://stackoverflow.com/questions/24640817/python-ctypes-definition-for-c-struct
class LayerStruct():
    pass

class NNStruct():
    pass

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