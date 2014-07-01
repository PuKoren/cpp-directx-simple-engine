#pragma once
#include <vector>
#include <mutex>
#include "Job.h"

class JobStack{
public:
    JobStack();
    ~JobStack();
    void addJob(Job* pJob);
    Job* getJob();
private:
    std::vector<Job*> mJobs;
    std::mutex mMutex;
};
