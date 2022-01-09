# :space_invader: Conways-Game-of-Life
Simple implementation of Conway's Game of Life using C

Run the program in the same folder as the .conway files. 

The program will prompt user input:
- Filename: i.e. gliders
- Simulation steps: i.e. 200
- Delay in ms: i.e. 80

Once these values are entered, it will run a simulaiton of Conway's Game of Life from a starting point defined by the specified file. 
- conway.c reads from a .conway file that has the format:
> Height

> Width

> Cells

For gliders.conway:

38

38

000000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000101000000000000000000000000011000000110000000000001100000000000001000100001100000000000011001100000000100000100011000000000000000011000000001000101100001010000000000000000000000010000010000000100000000000 0000000000001000100000000000000000000000000000000001100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

This results in a starting point shown below: 

![alt text](https://github.com/JackFujita/Conways-Game-of-Life/blob/main/EgGliderStartingState.jpg)

The simulation will then progress for the specified number of steps with the specified delay, and then terminate. 