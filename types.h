#pragma once
#ifndef TYPES_H
#define TYPES_H

#include <iostream>



struct Point {
    int row;
    int col;
    
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << "(" << p.row << ", " << p.col << ")";
	}
};

enum class HeuristicType {
    MANHATTAN,
    EUCLIDEAN,
    CHEBYSHEV
};

#endif