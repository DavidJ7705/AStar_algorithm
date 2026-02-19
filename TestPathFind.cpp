#include <iostream>
#include "pathfinder.h"
#include "TestPathFind.h"

void RunTests(int argc, char** argv) {
    TestNormalPath();
}

void TestNormalPath() {
    std::cout << "\n***** Test Normal Path *****" << std::endl;
	std::cout << "Initial Grid:" << std::endl;
	PathFind pf(6, 6); // creating an object of PathFind class with x rows and y columns
	pf.setStart(0, 0); // setting the start point at (0, 0)
	pf.setGoal(5, 5); // setting the goal point at (5, 5)

	pf.printGrid();

	std::cout << std::endl;
	std::cout << "Grid after setting obstacle:" << std::endl;

	pf.setObstacle(1, 0);
	pf.setObstacle(1, 1);
	pf.setObstacle(1, 2);
	pf.setObstacle(1, 3);
	pf.setObstacle(1, 4);
	pf.setObstacle(3, 1);
	pf.setObstacle(3, 2);
	pf.setObstacle(3, 3);
	pf.setObstacle(3, 4);
	pf.setObstacle(3, 5);
	pf.setObstacle(5, 0);
	pf.setObstacle(5, 1);
	pf.setObstacle(5, 2);
	pf.setObstacle(5, 3);
	pf.setObstacle(5, 4);

	pf.printGrid();

	pf.findPath(); // finding the path from start to goal using A* algorithm
}
