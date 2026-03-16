/*

ᯓ▶︎ •၊၊||၊|။||||။‌‌‌‌‌၊|• 0:10

David Jayakumar
G00419108
*/

#include <iostream>
#include "pathfinder.h"
#include "TestPathFind.h"

void RunTests(int argc, char** argv) {
    //TestNormalPath();
	//TestPathNoObstacles();
	//TestStartSameGoal();
	//TestNoPath();
    TestHeuristicComparison();
    //TestRandomPath();
}

void TestNormalPath() {
    std::cout << "\n***** Test Normal Path - Manhattan *****" << std::endl;
    PathFind pf(6, 6);
    pf.setStart(0, 0);
    pf.setGoal(5, 5);

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
    pf.setHeuristicType(HeuristicType::MANHATTAN);
    pf.findPath();

    std::cout << "\n***** Test Normal Path - Euclidean *****" << std::endl;
    PathFind pf2(6, 6);
    pf2.setStart(0, 0);
    pf2.setGoal(5, 5);
    pf2.setObstacle(1, 0);
    pf2.setObstacle(1, 1);
    pf2.setObstacle(1, 2);
    pf2.setObstacle(1, 3);
    pf2.setObstacle(1, 4);
    pf2.setObstacle(3, 1);
    pf2.setObstacle(3, 2);
    pf2.setObstacle(3, 3);
    pf2.setObstacle(3, 4);
    pf2.setObstacle(3, 5);
    pf2.setObstacle(5, 0);
    pf2.setObstacle(5, 1);
    pf2.setObstacle(5, 2);
    pf2.setObstacle(5, 3);
    pf2.setObstacle(5, 4);
    pf2.printGrid();
    pf2.setHeuristicType(HeuristicType::EUCLIDEAN);
    pf2.findPath();
}

void TestPathNoObstacles() {
    std::cout << "\n***** Test No Obstacles Pathh - Manhattan *****" << std::endl;
    PathFind pf(10, 10);
    pf.setStart(0, 0);
    pf.setGoal(9, 9);
    pf.printGrid();
    pf.setHeuristicType(HeuristicType::MANHATTAN);
    pf.findPath();

    std::cout << "\n***** Test No Obstacles Path - Euclidean *****" << std::endl;
    PathFind pf2(10, 10);
    pf2.setStart(0, 0);
    pf2.setGoal(9, 9);
    pf2.printGrid();
    pf2.setHeuristicType(HeuristicType::EUCLIDEAN);
    pf2.findPath();

    std::cout << "\n***** Test No Obstacles Path - Chebyshev *****" << std::endl;
    PathFind pf3(10, 10);
    pf3.setStart(0, 0);
    pf3.setGoal(9, 9);
    pf3.printGrid();
    pf3.setHeuristicType(HeuristicType::CHEBYSHEV);
    pf3.findPath();
}

void TestStartSameGoal() {
	std::cout << "\n\n***** Test Start Same Goal *****" << std::endl;
	PathFind pf(4, 4);
	pf.setStart(2, 2);
	pf.setGoal(2, 2);
	pf.printGrid();
	pf.findPath();
}

void TestNoPath() {
	std::cout << "\n\n***** Test No Path *****" << std::endl;
	PathFind pf(4, 4); 
	pf.setStart(0, 0); 
	pf.setGoal(3, 3); 
	pf.setObstacle(1, 0);
	pf.setObstacle(0, 1);
	pf.setObstacle(1, 1);
	pf.printGrid();
	pf.findPath(); 
}

void TestRandomPath() {
    std::cout << "\n***** Test Random Path *****" << std::endl;
    PathFind pf(10, 10);
    pf.setStart(0, 0);
    pf.setGoal(9, 9);
    pf.generateRandom(25); //obstacle density
    pf.printGrid();
    pf.setHeuristicType(HeuristicType::MANHATTAN);
    pf.findPath();
}


void TestHeuristicComparison() {
    std::cout << "\n***** Heuristic Comparison *****" << std::endl;

    auto runWithHeuristic = [](HeuristicType type, std::string name) {
        PathFind pf(6, 6);
        pf.setStart(0, 0);
        pf.setGoal(5, 5);
        pf.setObstacle(1, 0);
        pf.setObstacle(1, 4);
        pf.setObstacle(3, 1);
        pf.setObstacle(3, 2);
        pf.setObstacle(3, 4);
        pf.setObstacle(3, 5);
        pf.setObstacle(5, 0);
        pf.setObstacle(5, 2);
        pf.setObstacle(5, 3);
        pf.setHeuristicType(type);
        std::cout << "\n--- " << name << " ---" << std::endl;
        //pf.printGrid();
        pf.findPath();
        };

    runWithHeuristic(HeuristicType::MANHATTAN, "Manhattan");
    runWithHeuristic(HeuristicType::EUCLIDEAN, "Euclidean");
    runWithHeuristic(HeuristicType::CHEBYSHEV, "Chebyshev");
}