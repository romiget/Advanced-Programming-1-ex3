# Advanced Programming 1 Project - KNN classifier

This repository provides a multi-threaded server-side and a client-side system using TCP protocol that
implements the  [KNN algorithm](https://en.wikipedia.org/wiki/K-nearest_neighbors_algorithm),
using different metrics to classify new data, based on given data.

This assignment built on the previous assignments.

Here, you run a program for the server, and as many client program as you like (we will show how later).

## Table Of Contents
* [Installation](#Installation)
* [Executing The Program](#Executing-The-Program)
* [Design](#Design)

[Authors](#Authors)

### Installation

Clone the repository:
```bash
git clone 'https://github.com/romiget/Advanced-Programming-1-ex3'
```

### Executing The Program

Through the running of the program, you are going be asked to upload files, so the server will function as planned. Those instructions will be clear at the process' runtime.

To compile the server:

Open a terminal at the server side's location.

(You can use the ```cd``` and ```ls``` terminal commands to navigate between directories)

```cd X``` will navigate to the directory ```X``` and ```ls``` will show the current directory's existing files.

Now compile the server using:
```bash
g++ -o *.cpp 'KNN Algorithm'/*.cpp Commands/*.cpp IO/*.cpp Metrics/*.cpp a
```
#### Note:
you can write whatever you want instead of ```a```, you will just have to stick with this name when running this program.

Running the server:
```bash
./a
```
(and if you wrote something else instead of ```a``` let's say ```blabla``` so your command shall be ```./blabla```)

Compiling a Client:

```bash
g++ -o *.cpp Commands/*.cpp IO/*.cpp a
```

Running the client:
```bash
./a
```

## Design

As requested, we created 7 commands.

### Upload File
This command asks the client for a train and a test file, then the server informs the clients when the data arrived to the server side.

### Change Parameters

This command asks for new k value (for the k neighbors) and a new metric, so it can estimate differently the types of unclassified measurables.

However, this command might do nothing, if you won't supply k value between 1 - 10 or a non-existing metric.

### classify data

This command classifies the data given at the ```Upload File``` command, you can find more details about this part at the first assignment.

### ShowClassification

This command just writes to the screen the results from the ```classify data``` command.

### ShowClassificationFile

The same the previous, just provides it into a file instead of straight to the screen.

### ShowConfusionMatrix

As requested, we have created this command to calculate the accuracy of our algorithm.

We have implemented that using the classified objects we already had, comparing to the type our algorithm set for them after a classification.

### EndInteraction

This command deletes resources from the heap and closes the server-client connection.



### Additional functionality

As we mentioned earlier, our program is multi-threaded. Therefore, you can open as many terminals as you want and execute the code without being influenced by other clients' requests.

## Authors
[Ido Goldenberg](https://github.com/Idono12)  
[Romi Getreide](https://github.com/romiget)