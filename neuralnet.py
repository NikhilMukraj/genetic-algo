import re
import wrapper


def checkValidArc(string):
    valid_arc = r'^(\d+i\|)(\d+[a-hj-zA-Z]\|)+$'
    if re.search(valid_arc, string):
        return True
    else:
        return False

def checkValidArcP(string):
    valid_arc_p = r'^(\d+i\|)$'
    if re.search(valid_arc_p, string):
        return True
    else:
        return False

class NeuralNetwork:
    def __init__(self, arc=None, randomized=False):
        if arc is not None:
            # use archetiture
            if randomized:
                # random init
                pass
            else:
                pass
        else:
            # init empty network
            pass
        raise NotImplementedError()

    def edit_layer(self, layer_number, layer_activation, layer_length):
        # edit layer
        raise NotImplementedError()

    def add_layer(self, layer_activation, layer_length, layer_input_length):
        # check if layer is first
        # edit layer if it is first
        raise NotImplementedError()

    def feedforward(self, input, timed=False):
        # use feedforward from c
        raise NotImplementedError()

    def __repr__(self):
        # format structure:
        # +--------------+
        # | nn.len:      |
        # +--------------+
        # | activation:  |
        # | layer input: |
        # | layer len:   |
        # +--------------+
        # repeat until gone through all layers
        raise NotImplementedError()