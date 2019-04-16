//
// Created by piotr on 27.03.19.
//

#include "cFigura.h"

cFigura::cFigura(double x, double y):x_(0),y_(0) {

}

void cFigura::przesun(double dx, double dy) {
    x_ += dx;
    y_ += dy;

}
