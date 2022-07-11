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

- `a_relu(double *inputs, double *weights, double bias, int length)` Returns the ReLU function of the given weights and biases as a `double`

- `a_sigmoid(double *inputs, double *weights, double bias, int length)` Returns the sigmoid function of the given weights and biases as a `double`

- `double a_tanh(double *inputs, double *weights, double bias, int length)` Returns the hyperbolic tangent function of the given weights and biases as a `double`

#### Layer Struct and Layer Functions

#### Neural Network Struct and Functions

### Python Classes and Methods

#### Neural Network Class

## helpful links

- create package: <https://stackoverflow.com/questions/47360113/compile-c-library-on-pip-install>
- more activations to add: <https://en.wikipedia.org/wiki/Activation_function>
- passing activation as function arg: <https://stackoverflow.com/questions/9410/how-do-you-pass-a-function-as-a-parameter-in-c#9413>
