/*
ᯓ▶︎ •၊၊||၊|။||||။‌‌‌‌‌၊|• 0:10
David Jayakumar
G00419108
*/
#include "heuristics.h"

int Heuristics::manhattan(Point p1, Point p2) {
    return std::abs(p1.row - p2.row) + std::abs(p1.col - p2.col);
}

double Heuristics::euclidean(Point p1, Point p2) {
    int rowDiff = p1.row - p2.row;
    int colDiff = p1.col - p2.col;
    return std::sqrt((rowDiff * rowDiff) + (colDiff * colDiff));
}

int Heuristics::chebyshev(Point p1, Point p2) {
    int rowDiff = std::abs(p1.row - p2.row);
    int colDiff = std::abs(p1.col - p2.col);
    return std::max(rowDiff, colDiff);
}

int Heuristics::calculate(HeuristicType type, Point p1, Point p2) {
    if (type == HeuristicType::EUCLIDEAN) {
        return (int)euclidean(p1, p2);
    }
    else if (type == HeuristicType::CHEBYSHEV) {
        return chebyshev(p1, p2);
    }
    else {
        return manhattan(p1, p2);
    }
}