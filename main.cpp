/*

ᯓ▶︎ •၊၊||၊|။||||။‌‌‌‌‌၊|• 0:10

David Jayakumar
G00419108
04/02/2026
*/

#include <iostream> // input and output
#include <vector> // vector 
#include "pathfinder.h" // header file
#include "TestPathFind.h"

int main(int argc, char** argv) {
	
	try {
		RunTests(argc, argv);
	}
	catch (std::out_of_range& e) {
		std::cerr << std::endl << e.what() << std::endl;
		return -1;
	}

	return 0;
}