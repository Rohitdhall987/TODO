//
// Created by rohit on 1/15/26.
//

#ifndef TODO_CODE_H
#define TODO_CODE_H

class App {
    bool running=false;
    public:
        App();
        bool isRunning() const;
        void exit();
};

#endif //TODO_CODE_H