/*

ᯓ▶︎ •၊၊||၊|။||||။‌‌‌‌‌၊|• 0:10

David Jayakumar
G00419108
04/02/2026
*/

#include <iostream>
#include "pathfinder.h"

PathFind::PathFind(int row, int col) : numRows(row), numCols(col) { // constructor to initialize rows and columns
	grid.resize(numRows, std::vector<int>(numCols, 0)); //initialised to 0, creating a grid of given rows and columns
}

void PathFind::printGrid() {	//function to print the grid
	for (int r = 0; r < numRows; r++) {
		for (int c = 0; c < numCols; c++) {
			if (r == startRow && c == startCol) {
				std::cout << "S "; //printing S for start
			}
			else if (r == goalRow && c == goalCol) {
				std::cout << "G "; //printing G for goal
			}
			else if (grid[r][c] == 0) {
				std::cout << ". "; //printing . for empty cell
			}
			else {
				std::cout << "# "; //printing # for obstacle
			}
		}
		std::cout << std::endl;
	}
}


void PathFind::setObstacle(int row, int col) {	//function to set obstacles in the grid
	if (row >= 0 && row < numRows && col >= 0 && col < numCols) { //checking if the row and column are within bounds
		grid[row][col] = 1; //setting the obstacle at specified position
	}
	else {
		std::cout << "Error: Out of bounds" << std::endl;
	}
}

void PathFind::setStart(int row, int col) {	//function to set the start point in the grid
	if (row >= 0 && row < numRows && col >= 0 && col < numCols) { //checking if the row and column are within bounds
		startRow = row; //setting the start row
		startCol = col; //setting the start column
	}
	else {
		std::cout << "Error: Start Out of bounds" << std::endl;
	}
}

void PathFind::setGoal(int row, int col) {	//function to set the end point in the grid
	if (row >= 0 && row < numRows && col >= 0 && col < numCols) { //checking if the row and column are within bounds
		goalRow = row; //setting the goal row
		goalCol = col; //setting the goal column
	}
	else {
		std::cout << "Error: Goal Out of bounds" << std::endl;
	}
}