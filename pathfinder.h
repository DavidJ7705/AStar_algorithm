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
#include <memory> // for smart pointers
#include <queue> // for priority queue
#include <cmath> // for sqrt and abs

#include <cstdlib>  // for rand
#include <ctime>    // for time

struct Point {
	int row;
	int col;
};
struct Node {
	Point point;
	int g; // Cost from start to current node
	int h; // Heuristic cost from current node to goal
	int f; // Total cost (g + h)

	std::shared_ptr<Node> parent; // Pointer to parent node for path reconstruction
	Node(int r, int c):g(0), h(0), f(0), parent(nullptr) {
		point = { r, c };
	}
};

struct CompareNode {
	bool operator()(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
		return a->f > b->f; // higher f cost has lower priority
	}
};

enum class HeuristicType {
	MANHATTAN,
	EUCLIDEAN,
	CHEBYSHEV
};

class PathFind {
	public:
		PathFind(int row, int col); //constructor to take in rows and columns parameters
		void printGrid();	 //function to print the grid
		void setObstacle(int row, int col); //function to set obstacles in the grid
		void setStart(int row, int col); //function to set the start point in the grid
		void setGoal(int row, int col); //function to set the end point in the grid
		void findPath(); //function to find the path from start to goal using A* algorithm
		void printPathGrid();
		void setHeuristicType(HeuristicType heuristic_);
		void generateRandom(int obstacleDensity = 30); // density = % of cells that are obstacles

	private:
		std::vector<std::vector<int>> grid; //2D vector to represent the grid 
		int numRows_;
		int numCols_;
		int startRow_, startCol_;
		int goalRow_, goalCol_;
		HeuristicType heuristic_ = HeuristicType::MANHATTAN; // default heuristic_
		int manhattanDistance(Point p1, Point p2);
		double euclideanDistance(Point p1, Point p2);
		int chebyshevDistance(Point p1, Point p2);
		int calculateHeuristic(Point p1, Point p2);

};


#endif

