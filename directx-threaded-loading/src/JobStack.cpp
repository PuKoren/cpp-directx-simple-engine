#include "JobStack.h"

JobStack::JobStack(){
    //this->mJobs = std::vector<Job*>();
}

JobStack::~JobStack(){
    if(!this->mJobs.empty()){
        for(unsigned int i = 0; i < this->mJobs.size(); i++){
            delete this->mJobs[i];
        }
    }
    this->mJobs.clear();
}

void JobStack::addJob(Job *pJob){
    this->mJobs.push_back(pJob);
}

Job* JobStack::getJob(){
    Job* job = NULL;
    mMutex.lock();
    if(!this->mJobs.empty()){
        job = *(this->mJobs.begin());
        this->mJobs.erase(this->mJobs.begin());
    }
    mMutex.unlock();
    return job;
}
