# proposed structure

## c backend

### neural network

- - -

- first create activation functions
- activation will have 3 parameters
  - weights, bias, input
- activation functions will make up layers
- layer is a struct that takes size of layer and weights/biases
- neural network is composed of these layers

### genetic algorithm

- - -

- crossover function
- mutation
  - allow for activation to be mutated
- allow for early stopping by analyzing rate of change

### threading

- - -

- compatible with windows or posix
- standardize functions between the two
- use within genetic algo population

### c main

- - -

- take all components
- place them into a singular file
  - leave potential for more languages to be used (r, julia maybe)
- remove testing code

## py wrapper

- wrapper converts python vars into c types
- wrapper handles errors
- wrapper allows for more activation functions to be created
- allows save/load

## py main

- allows for neural network to be initialized in c
- lets user run genetic algo
- allows for parameterization
- lets user create neural network as an python class
