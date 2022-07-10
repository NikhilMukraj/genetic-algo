import re
import wrapper


def checkValidArc(string):
    valid_arc = r'^(\d+i\|)(\d+[a-hj-zA-Z]\|)+$'
    if re.search(valid_arc, string):
        return
    else:
        raise ValueError(f'{string} is an invalid architecture')

def checkValidArcP(string):
    valid_arc_p = r'^(\d+i\|)$'
    if re.search(valid_arc_p, string):
        return
    else:
        raise ValueError(f'{string} is an invalid architecture')

class Layer:
    def __init__(self, arc=None, randomized=False):
        if arc is not None:
            checkValidArcP(arc)
            # use archetiture
            if randomized:
                # random init
                pass
            else:
                pass
        else:
            # init empty layer
            pass
        raise NotImplementedError()

    def __repr__(self):
        # +--------------+
        # | activation:  |
        # | layer input: |
        # | layer len:   |
        # +--------------+
        raise NotImplementedError()

class NeuralNetwork:
    def __init__(self, arc=None, randomized=False):
        if arc is not None:
            checkValidArc(arc)
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

    def edit_activation(self, layer_number, layer_activation):
        # edit layer activation
        raise NotImplementedError()

    def add_layer(self, layer_activation=None, layer_length=None, layer_input_length=None, restr=None):
        if restr and all(i is None for i in [layer_activation, length, layer_input_length]):
            checkValidArcP(restr)
            # use restr directly
            pass
        elif restr is None and not all(i is None for i in [layer_activation, length, layer_input_length]):
            # use args
            pass
        else:
            raise ValueError()
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

    def load(self, filename):
        raise NotImplementedError

    def save(self, filename):
        raise NotImplementedError