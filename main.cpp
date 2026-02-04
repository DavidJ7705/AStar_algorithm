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
	PathFind pf(4, 4); // creating an object of PathFind class with x rows and y columns
	pf.printGrid();

	std::cout << std::endl;
	std::cout << "Grid after setting obstacle:" << std::endl;

	pf.setObstacle(0, 0);


	pf.printGrid();

	return 0;
}