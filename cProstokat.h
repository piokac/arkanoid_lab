//
// Created by piotr on 27.03.19.
//

#ifndef FREEGLUT_CPROSTOKAT_H
#define FREEGLUT_CPROSTOKAT_H
#include <GL/freeglut.h>
#include "cFigura.h"

class cProstokat : public cFigura{
double a_,b_;

public:
    cProstokat(double a, double b, double x, double y);
    void rysuj();
    void ustaw_rozmiar(double a, double b);

};


#endif //FREEGLUT_CPROSTOKAT_H
