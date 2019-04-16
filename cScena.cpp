//
// Created by piotr on 27.03.19.
//

#include "cScena.h"
#include <iostream>
#include <chrono>
cScena::cScena() : active_id_(0) {



    pilka_ = new cProstokat(0.5, 0.5, 0, 2);
    pilka_->ustaw_predkosc(3e-4, 50);
    pilka_->ustaw_fizyka(9.81*1E-6, -90);

    //paletka
    figury_.push_back(pilka_);
    figury_.push_back(new cProstokat(4, .5, 0, -2.0));
    figury_.push_back(new cProstokat(0.5, 4, 2, 0));
    figury_.push_back(new cProstokat(0.5, 4, -2, 0));
    //pPaletka = new Prostokat(0, -15, 10, 1, 3);

}

void cScena::resize(int width, int height) {
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void cScena::timer() {

    //int current_time = getTickCount();
    //auto current_time = std::chrono::high_resolution_clock::now();

    //std::cout<<current_time<<std::endl;
    //std::cout.flush();
    for(auto itr = figury_.begin()+1; itr!=figury_.end(); ++itr){
        if (pilka_->kolizja(*(*itr))){
        //if((*itr)->kolizja(*pilka_)){
            std::cout<<"kolizja"<<std::endl;
        }

    }
    pilka_->aktualizuj(GetTickCount());



    glutPostRedisplay();
    glutTimerFunc(40, timer_binding, 0);
}

void cScena::display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    {
        for (auto &el: figury_)
            el->rysuj();
    }
    glPopMatrix();

    glutSwapBuffers();
}


void cScena::set_callbacks() {
    glutReshapeFunc(resize_binding);
    glutDisplayFunc(display_binding);
    //glutIdleFunc(idle_binding);
    glutTimerFunc(40, timer_binding, 0);
    glutKeyboardFunc(key_binding);
}

void cScena::init(int argc, char **argv, const char *window_name) {

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(40, 40);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

    glutCreateWindow(window_name);

    // set white as the clear colour
    glClearColor(1, 1, 1, 1);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    set_callbacks();

    // start GLUT event loop. It ends when user close the window.
    glutMainLoop();
}

void cScena::key(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            figury_[active_id_]->przesun(0, 0.1);
            break;
        case 's':
            figury_[active_id_]->przesun(0, -0.1);
            break;
        case 'z': {

        }
    }


}

cScena::~cScena() {
    for (auto &el : figury_)
        delete el;
}
