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

void PathFind::printGrid() {
	for (auto& row : grid) { //for range loop to print each element in the grid
		for (auto& element : row) {
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
}