//
// Created by rohit on 1/15/26.
//

#include "core.h"

App::App() {
    running=true;
}

bool App::isRunning() const {
    return running;
}

void App::exit() {
    running=false;
}
