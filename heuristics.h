/*
ᯓ▶︎ •၊၊||၊|။||||။‌‌‌‌‌၊|• 0:10
David Jayakumar
G00419108
*/
#pragma once
#ifndef HEURISTICS_H
#define HEURISTICS_H

#include <cmath>
#include "pathfinder.h"
#include "types.h"

class Heuristics {
public:
    static int manhattan(Point p1, Point p2);
    static double euclidean(Point p1, Point p2);
    static int chebyshev(Point p1, Point p2);
    static int calculate(HeuristicType type, Point p1, Point p2);
};

#endif