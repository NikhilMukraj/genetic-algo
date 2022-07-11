# genetic algorithm package written in c and python

uses c for speed with python interface
custom neural network architecture

## todo

- [x] make c modules with each type of activation
- [x] test activations
- [ ] droput
- [ ] test dropout
- [x] make c activations hook up into one another
- [x] test layers
- [x] create nn
- [x] test nn
- [x] create init function
- [x] test
- [x] add and edit layers
- [x] test
- [x] feedforward
- [x] test
- [ ] thread computation
- [ ] test
- [x] model archetirure with string
- [x] test
- [ ] create python wrapper
- [ ] create nn objection
- [ ] make everything interfaceable
- [ ] save and load nn in python
- [ ] test
- [ ] allow user to add activation functions
- [ ] rewrite ga from python into c
- [ ] test all python code
- [ ] code up some examples

## documentation

### C Structs and Functions

- Reminder most C structs and functions are accessible from Python

#### Activation Functions

- `a_relu(double *inputs, double *weights, double bias, int length)`
  - Returns the ReLU function of the given weights and biases as a `double`

- `a_sigmoid(double *inputs, double *weights, double bias, int length)`
  - Returns the sigmoid function of the given weights and biases as a `double`

- `double a_tanh(double *inputs, double *weights, double bias, int length)`
  - Returns the hyperbolic tangent function of the given weights and biases as a `double`

#### Layer Struct and Layer Functions

- `layer`
  - Struct
  - `int` input length
  - `int` length of the layer
  - `double` array of biases
  - 2 dimensional `double` array of weights
  - `char` representing activation type

- `init_weights(struct layer *sheet)`
  - Void
  - Generates a 2 dimensional empty array of `double`s for the `layer` struct

- `init_biases(struct layer *sheet)`
  - Void
  - Generates an empty array of `double`s for the `layer` struct

- `output(struct layer *sheet, double *inputs)`
  - Returns a double array
  - Uses activation from `layer` to calculate the output given an array of `double`s

#### Neural Network Struct and Functions

- `nn`
  - Array of `layer` structs
  - `int` length

- `network_init(struct nn *network, int randomized)`
  - Initializes empty arrays of weights and biases from array of `layer`s

- `struct nn create_nn(char *arc)`
  - Generates an `nn` struct based on a given string architecture
  - String architecture looks like the following:
    - `"xi|xa|"` where x is any `int` and a is any valid activation function
    - `"xa|"` is repeated for each layer in `nn` struct

- `add_layer(struct nn *network, char *arc_part)`
  - Adds a `layer` struct to `nn`'s array of `layer`s
  - `*arc_part` must be in the form of `"xa|"`

- `feedforward(struct nn *network, double *inputs)`
  - Calculates output of network given a set of inputs in a `double` array

### Python Classes and Methods

#### Neural Network Class

## helpful links

- create package: <https://stackoverflow.com/questions/47360113/compile-c-library-on-pip-install>
- more activations to add: <https://en.wikipedia.org/wiki/Activation_function>
- passing activation as function arg: <https://stackoverflow.com/questions/9410/how-do-you-pass-a-function-as-a-parameter-in-c#9413>
