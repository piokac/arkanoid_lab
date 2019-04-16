//
// Created by piotr on 27.03.19.
//

#ifndef FREEGLUT_CSCENA_H
#define FREEGLUT_CSCENA_H
#include "cProstokat.h"
#include <vector>

//bindingi dla callbacków
void resize_binding(int width, int height);
void idle_binding();
void display_binding();
void key_binding(unsigned char key, int x, int y);
void timer_binding(int i);

class cScena {
    std::vector<cFigura*> figury_;
    int active_id_;
    cProstokat* pilka_;
public:
    cScena();
    ~cScena();
    void resize(int width, int height);
    void timer();
    void display();
    void init(int argc, char *argv[], const char* window_name);
    void set_callbacks();
    void key(unsigned char key, int x, int y);

};


#endif //FREEGLUT_CSCENA_H
