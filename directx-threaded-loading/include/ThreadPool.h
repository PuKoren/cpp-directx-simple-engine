#pragma once
#include <vector>
#include <thread>
#include "CThread.h"
#include "JobStack.h"

const unsigned int THREADS_COUNT = 3;

class ThreadPool{
public:
    ThreadPool();
    ~ThreadPool();
    bool init();
    void release();
    JobStack* getJobStack();
private:
    std::vector<CThread*> mThreads;
    std::vector<std::thread> mPthreads;
    JobStack* mStack;
};
