/*

ᯓ▶︎ •၊၊||၊|။||||။‌‌‌‌‌၊|• 0:10

David Jayakumar
G00419108
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

int PathFind::manhattanDistance(Point p1, Point p2) {
	return std::abs(p1.row - p2.row) + std::abs(p1.col - p2.col);
}

void PathFind::printPathGrid() {
	std::cout << "\nPath Grid:" << std::endl;
	for (int r = 0; r < numRows; r++) {
		for (int c = 0; c < numCols; c++) {
			if (r == startRow && c == startCol) {
				std::cout << "S ";
			}
			else if (r == goalRow && c == goalCol) {
				std::cout << "G ";
			}
			else if (grid[r][c] == 1) {
				std::cout << "# ";
			}
			else if (grid[r][c] == 2) {
				std::cout << "* ";
			}
			else {
				std::cout << ". ";
			}
		}
		std::cout << std::endl;
	}
}

void PathFind::findPath() {
	std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, CompareNode> openList;
	std::vector<std::vector<int>> closedList;
	closedList.resize(numRows, std::vector<int>(numCols, 0));

	auto startNode = std::make_shared<Node>(startRow, startCol);
	startNode->h = manhattanDistance(startNode->point, { goalRow, goalCol });
	startNode->f = startNode->g + startNode->h;
	openList.push(startNode);

	int rowDir[] = { -1, 1, 0, 0 };
	int colDir[] = { 0, 0, -1, 1 };

	while (!openList.empty()) {
		// find lowest f cost node, priority queue handles ordering automatically
		auto current = openList.top();
		openList.pop();


		closedList[current->point.row][current->point.col] = 1;

		// goal reached
		if (current->point.row == goalRow && current->point.col == goalCol) {

			// mark path on grid
			auto trace = current;
			while (trace != nullptr) {
				if (!(trace->point.row == startRow && trace->point.col == startCol) &&
					!(trace->point.row == goalRow && trace->point.col == goalCol)) {
					grid[trace->point.row][trace->point.col] = 2; // mark as path
				}
				trace = trace->parent;
			}
			printPathGrid();
			std::cout << "Path found! Total steps: " << current->g << std::endl;

			return;
		}

		// explore neighbours
		for (int i = 0; i < 4; i++) {
			int newRow = current->point.row + rowDir[i];
			int newCol = current->point.col + colDir[i];

			if (newRow < 0 || newRow >= numRows || newCol < 0 || newCol >= numCols) continue;
			if (grid[newRow][newCol] == 1) continue;
			if (closedList[newRow][newCol] == 1) continue;

			auto neighbour = std::make_shared<Node>(newRow, newCol);
			neighbour->g = current->g + 1;
			neighbour->h = manhattanDistance(neighbour->point, { goalRow, goalCol });
			neighbour->f = neighbour->g + neighbour->h;
			neighbour->parent = current; // track parent!
			openList.push(neighbour);
		}



	}
	std::cout << "No path found!" << std::endl;
}