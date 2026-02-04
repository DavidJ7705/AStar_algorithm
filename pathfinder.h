/*

ᯓ▶︎ •၊၊||၊|။||||။‌‌‌‌‌၊|• 0:10

David Jayakumar
G00419108
04/02/2026
*/


#pragma once

#ifndef PATH_FIND_H
#define PATH_FIND_H

#include <vector> // vector

class PathFind {
	public:
		PathFind(int row, int col); //constructor to take in rows and columns parameters
		void printGrid();	 //function to print the grid
		void setObstacle(int row, int col); //function to set obstacles in the grid

	private:
		std::vector<std::vector<int>> grid; //2D vector to represent the grid 
		int numRows;
		int numCols;
};


#endif

