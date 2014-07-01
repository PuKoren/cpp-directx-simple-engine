#pragma once
#include <iostream>

class Job{
public:
    Job();
    virtual ~Job();
    virtual void run() = 0;
private:
};
