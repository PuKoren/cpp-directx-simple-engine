#include "CThread.h"

CThread::CThread(JobStack* pStack){
    this->mRunning = true;
    this->mStack = pStack;
}

CThread::~CThread(){

}

void CThread::release(){
    this->mRunning = false;
}

void CThread::work(){
    while(this->mRunning){
        Job* job = this->mStack->getJob();
        if(job) {
            job->run();
            //delete job;
        }
    }
}
