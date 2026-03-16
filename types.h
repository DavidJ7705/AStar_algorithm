#pragma once
#ifndef TYPES_H
#define TYPES_H

struct Point {
    int row;
    int col;
};

enum class HeuristicType {
    MANHATTAN,
    EUCLIDEAN,
    CHEBYSHEV
};

#endif