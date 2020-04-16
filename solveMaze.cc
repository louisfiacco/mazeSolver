/*****************************************************************
 *  Name: Louis Fiacco
 *  Date: 03/27/2019
 *  Course: CSCI 132,  Prof. Kadady
 *  Assignment: Assignment 5
 *  Program: solveMaze.cc
 *  Purpose: Draws a random maze and solves it using recursion
 ****************************************************************/
 
#include "maze.h"

bool solve(Maze &, int, int);
bool isWallAbove(Maze &, int, int);
bool isWallBelow(Maze &, int, int);
bool isWalltoLeft(Maze &, int, int);
bool isWalltoRight(Maze &, int, int);

int main()  {
	int width, height;
	char answer;
	
	cout << "Do you want me to solve a maze (y/n)? ";
	cin >> answer;

	while (answer == 'y') {
		cout << "Enter number for width of maze: " ;
		cin >> width;
		cout  << "Enter number for height of maze: ";
		cin >> height;

		Maze myMaze(width, height);
		cout << "Maze to be solved: " << endl;
		myMaze.print_maze();
		if (!solve(myMaze, 0, 0)) {
			cout << "Couldn't solve this maze!" << endl;
		} //if maze not solved
		
		cout << "Do you want me to solve another maze (y/n)? ";
		cin >> answer;
        cout << answer << endl;
	} // while solving another maze
		
	return 0;
} //end main program

bool solve(Maze &theMaze, int x, int y)
/***************************************************************
 * Pre: inputs the maze and the x and y coordinates
 * Post: recursively solves the maze from position x, y 
 *   
 *****************************************************************/
{
    if (theMaze.get_position(x,y) == 2){
        theMaze.print_maze();
        return true;
    }
    
    if (theMaze.get_position(x,y) == 1){
        return false;
    }
    
    if (theMaze.get_position(x,y) == 0){
        theMaze.set_position(x,y,1);
        if (!isWallAbove(theMaze, x, y)){
            solve(theMaze, x, y-1);
        }
        if (!isWallBelow(theMaze, x, y)){
            solve(theMaze, x, y+1);
        }
        if (!isWalltoLeft(theMaze, x, y)){
            solve(theMaze, x-1, y);
        }
        if (!isWalltoRight(theMaze, x, y)){
            solve(theMaze, x+1, y);
        }
       
        theMaze.set_position(x,y,0);
        return true;
      
    }
    return false;
} //end solve


bool isWallAbove(Maze &theMaze, int x, int y)
/***************************************************************
 * Pre: inputs the maze and the x and y coordinates
 * Post: returns true if there is a wall above position x, y 
 *   
 *****************************************************************/
{
    if (theMaze.is_horizontal_wall(x, y)){
        return true;
    }else{
        return false;
    }
} //end isWallAbove


bool isWallBelow(Maze &theMaze, int x, int y)
/***************************************************************
 * Pre: inputs the maze and the x and y coordinates
 * Post: returns true if there is a wall below position x, y 
 *   
 *****************************************************************/
{
    if (theMaze.is_horizontal_wall(x, y+1)){
        return true;
    }else{
        return false;
    }
} //end isWallBelow


bool isWalltoLeft(Maze &theMaze, int x, int y)
/***************************************************************
 * Pre: inputs the maze and the x and y coordinates
 * Post: returns true if there is a wall to the left of position x, y 
 *   
 *****************************************************************/
{
    if (theMaze.is_vertical_wall(x,y)){
        return true;
    }else{
        return false;
    }
} //end isWalltoLeft


bool isWalltoRight(Maze &theMaze, int x, int y)
/***************************************************************
 * Pre: inputs the maze and the x and y coordinates
 * Post: returns true if there is a wall to the right of position x, y 
 *   
 *****************************************************************/
{
    if (theMaze.is_vertical_wall(x+1,y)){
        return true;
    }else{
        return false;
    }
} //end isWalltoRight
