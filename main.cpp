/*

ᯓ▶︎ •၊၊||၊|။||||။‌‌‌‌‌၊|• 0:10

David Jayakumar
G00419108
04/02/2026
*/

#include <iostream> // input and output
#include <vector> // vector 
#include "pathfinder.h" // header file


int main() {
	
	std::cout << "Initial Grid:" << std::endl;
	PathFind pf(6, 6); // creating an object of PathFind class with x rows and y columns
	pf.setStart(0, 0); // setting the start point at (0, 0)
	pf.setGoal(5, 5); // setting the goal point at (5, 5)

	pf.printGrid();

	std::cout << std::endl;
	std::cout << "Grid after setting obstacle:" << std::endl;

	pf.setObstacle(1, 0);
	pf.setObstacle(2, 3);
	pf.setObstacle(3, 0);



	pf.printGrid();

	return 0;
}