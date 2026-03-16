/*

ᯓ▶︎ •၊၊||၊|။||||။‌‌‌‌‌၊|• 0:10

David Jayakumar
G00419108
*/

#include <iostream>
#include "pathfinder.h"
#include "heuristics.h"
#include "types.h"

PathFind::PathFind(int row, int col) : numRows_(row), numCols_(col) { // constructor to initialize rows and columns
	grid_.resize(numRows_, std::vector<int>(numCols_, 0)); //initialised to 0, creating a grid_ of given rows and columns
}

void PathFind::printGrid() {	//function to print the grid_
	for (int r = 0; r < numRows_; r++) {
		for (int c = 0; c < numCols_; c++) {
			if (r == startRow_ && c == startCol_) {
				std::cout << "S "; //printing S for start
			}
			else if (r == goalRow_ && c == goalCol_) {
				std::cout << "G "; //printing G for goal
			}
			else if (grid_[r][c] == 0) {
				std::cout << ". "; //printing . for empty cell
			}
			else {
				std::cout << "# "; //printing # for obstacle
			}
		}
		std::cout << std::endl;
	}
}


void PathFind::setObstacle(int row, int col) {	//function to set obstacles in the grid_
	if (row >= 0 && row < numRows_ && col >= 0 && col < numCols_) { //checking if the row and column are within bounds
		grid_[row][col] = 1; //setting the obstacle at specified position
	}
	else {
		throw std::out_of_range("SetObstacle: row out of bounds"); //throwing an error if the position is out of bounds
	}
}

void PathFind::setStart(int row, int col) {	//function to set the start point in the grid_
	if (row >= 0 && row < numRows_ && col >= 0 && col < numCols_) { //checking if the row and column are within bounds
		startRow_ = row; //setting the start row
		startCol_ = col; //setting the start column
	}
	else {
		throw std::out_of_range("setStart: row out of bounds"); //throwing an error if the position is out of bounds
	}
}

void PathFind::setGoal(int row, int col) {	//function to set the end point in the grid_
	if (row >= 0 && row < numRows_ && col >= 0 && col < numCols_) { //checking if the row and column are within bounds
		goalRow_ = row; //setting the goal row
		goalCol_ = col; //setting the goal column
	}
	else {
		throw std::out_of_range("SetGoal: row out of bounds"); //throwing an error if the position is out of bounds
	}
}

void PathFind::printPathGrid() {
	std::cout << "\nPath Grid:" << std::endl;
	for (int r = 0; r < numRows_; r++) {
		for (int c = 0; c < numCols_; c++) {
			if (r == startRow_ && c == startCol_) {
				std::cout << "S ";
			}
			else if (r == goalRow_ && c == goalCol_) {
				std::cout << "G ";
			}
			else if (grid_[r][c] == 1) {
				std::cout << "# ";
			}
			else if (grid_[r][c] == 2) {
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
	closedList.resize(numRows_, std::vector<int>(numCols_, 0));

	auto startNode = std::make_shared<Node>(startRow_, startCol_);
	startNode->h = calculateHeuristic(startNode->point, { goalRow_, goalCol_ });
	startNode->f = startNode->g + startNode->h;
	openList.push(startNode);

	std::vector<std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // up, down, left, right directions

	while (!openList.empty()) {
		// find lowest f cost node, priority queue handles ordering automatically
		auto current = openList.top();
		openList.pop();


		closedList[current->point.row][current->point.col] = 1;

		// goal reached
		if (current->point.row == goalRow_ && current->point.col == goalCol_) {

			// mark path on grid_
			auto trace = current;
			while (trace != nullptr) {
				if (!(trace->point.row == startRow_ && trace->point.col == startCol_) &&
					!(trace->point.row == goalRow_ && trace->point.col == goalCol_)) {
					grid_[trace->point.row][trace->point.col] = 2; // mark as path
				}
				trace = trace->parent;
			}
			printPathGrid();
			std::cout << "Path found! Total steps: " << current->g << std::endl;

			return;
		}

		// explore neighbours
		for (auto& direction : directions) {
			int newRow = current->point.row + direction.first;
			int newCol = current->point.col + direction.second;

			if (newRow < 0 || newRow >= numRows_ || newCol < 0 || newCol >= numCols_) continue;
			if (grid_[newRow][newCol] == 1) continue;
			if (closedList[newRow][newCol] == 1) continue;

			auto neighbour = std::make_shared<Node>(newRow, newCol);
			neighbour->g = current->g + 1;
			neighbour->h = calculateHeuristic(neighbour->point, { goalRow_, goalCol_ });
			neighbour->f = neighbour->g + neighbour->h;
			neighbour->parent = current; // track parent!
			openList.push(neighbour);
		}



	}
	std::cout << "No path found!" << std::endl;
}

void PathFind::setHeuristicType(HeuristicType heuristic_) {
	this->heuristic_ = heuristic_;
}

int PathFind::calculateHeuristic(Point p1, Point p2) {

	return Heuristics::calculate(heuristic_, p1, p2);
}

void PathFind::generateRandom(int obstacleDensity) {
	srand(static_cast<unsigned int>(time(nullptr)));

	// Clear the grid_ first
	for (int r = 0; r < numRows_; r++)
		for (int c = 0; c < numCols_; c++)
			grid_[r][c] = 0;

	startRow_ = rand() % (numRows_ / 2);
	startCol_ = rand() % (numCols_ / 2);

	goalRow_ = numRows_ / 2 + rand() % (numRows_ / 2);
	goalCol_ = numCols_ / 2 + rand() % (numCols_ / 2);

	// Random obstacles based on density %
	for (int r = 0; r < numRows_; r++) {
		for (int c = 0; c < numCols_; c++) {
			if (r == startRow_ && c == startCol_) continue;
			if (r == goalRow_ && c == goalCol_) continue;
			if ((rand() % 100) < obstacleDensity) {
				grid_[r][c] = 1;
			}
		}
	}
}
