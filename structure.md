# proposed structure

## c backend

- neural network:
  - first create activation functions
  - activation will have 3 parameters
    - weights, bias, input
  - activation functions will make up layers
  - layer is a struct that takes size of layer and weights/biases
  - neural network is composed of these layers
- genetic algorithm:
  - crossover function
  - mutation
    - allow for activation to be mutated
  - allow for population to be threaded
  - allow for early stopping by analyzing rate of change

## py wrapper

- wrapper converts python vars into c types
- wrapper handles errors
- wrapper allows for more activation functions to be created

## py main

- allows for neural network to be initialized in c
- lets user run genetic algo
- allows for parameterization
- lets user create neural network as an python class
