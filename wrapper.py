import ctypes


def toCDoubleArray(arr):
    return (ctypes.c_double * len(arr))(*arr)

def toPyArray(arr, length):
    return ctypes.cast(length, ctypes.POINTER(ctypes.c_int * length)).contents # need to test

def getNetworkStruct(args):
    pass