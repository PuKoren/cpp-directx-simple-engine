#pragma once
#include "JobStack.h"

class CThread{
public:
    CThread(JobStack* pStack);
    ~CThread();
    void release();
    void work();
private:
    JobStack *mStack;
    bool mRunning;
};
