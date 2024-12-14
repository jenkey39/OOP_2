#ifndef APPLICATION_H
#define APPLICATION_H

#include "array.h"
#include <iostream>

class Application {
private:
    Array array;

public:
    Application();
    void run();
    void print_menu();
    void handle_input();
    void handle_mean_and_stddev();
    void handle_sort(bool ascending);
    void handle_resize();
    void handle_modify_element();
    void handle_output();
};

#endif
