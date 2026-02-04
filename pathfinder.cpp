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
	for (auto& row : grid) { //for range loop to print each element in the grid
		for (auto& element : row) {
			if(element == 0)
				std::cout << ". "; //printing . for empty cell
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