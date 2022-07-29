import re
import wrapper


def checkValidArc(string):
    valid_arc = r'^(\d+i\|)(\d+[a-hj-zA-Z]\|)+$'
    if re.search(valid_arc, string):
        return
    else:
        raise ValueError(f'{string} is an invalid architecture')

def checkValidArcP(string):
    valid_arc_p = r'^(\d+[a-hj-zA-Z]\|)$'
    if re.search(valid_arc_p, string):
        return
    else:
        raise ValueError(f'{string} is an invalid architecture')

class Layer:
    def __init__(self, arcp=None, randomized=False):
        if arcp is not None:
            checkValidArcP(arcp)
            # use architecture
            if randomized:
                # random init
                pass
            else:
                pass
        else:
            # init empty layer
            pass
        raise NotImplementedError()
    
    def getLayerStructFromArc(self, arcp):
        raise NotImplementedError()
    
    def getLayerStructFromSpecs(self, input_len, layer_len, activation):
        raise NotImplementedError()

    def __repr__(self):
        # +--------------+
        # | activation:  |
        # | layer input: |
        # | layer len:   |
        # +--------------+
        rep = ''
        keys = {'activation: ': self.layer.activation,
                'layer input: ': self.layer.layer_input,
                'layer len: ': self.layer.layer_len}

        max_len = max([i + str(j) for i, j in keys.items()], key=len)
        bounds = '+' + ((max_len + 2) * '-') + '+'
        rep += bounds + '\n'
        for i in keys.items():
            rep += f'| {i[0]}{i[1]} |\n'
        rep += bounds + '\n'

        return rep

        # needs testing

class NeuralNetwork:
    def __init__(self, arc=None, randomized=False):
        if arc is not None:
            checkValidArc(arc)
            # use architecture
            if randomized:
                # random init
                pass
            else:
                pass
        else:
            # init empty network
            pass
        raise NotImplementedError()

    def getNetworkStructFromArc(self, arc):
        raise NotImplementedError 

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
        # use feedforward from c wrapper
        raise NotImplementedError()

    def __repr__(self):
        # format structure:
        # +--------------+
        # | nn length:   |
        # +--------------+
        # | activation:  |
        # | layer input: |
        # | layer len:   |
        # +--------------+
        # repeat until gone through all layers
        rep = '+' + ('-' * (len('nn length: ') + len(str(self.len)) + 2)) + '+\n'
        rep += f'| nn length: {self.len} |\n'
        for n in range(self.len):
            keys = {'activation: ': self.layer.activation,
                    'layer input: ': self.layer.layer_input,
                    'layer len: ': self.layer.layer_len}

            max_len = max([i + str(j) for i, j in keys.items()], key=len)
            bounds = '+' + ((max_len + 2) * '-') + '+'
            rep += bounds + '\n'
            for i in keys.items():
                rep += f'| {i[0]}{i[1]} |\n'
            rep += bounds + '\n'

        return rep

    def load(self, filename):
        raise NotImplementedError

    def save(self, filename):
        raise NotImplementedError