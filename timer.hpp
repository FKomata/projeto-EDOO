#pragma once
#include <iostream>
using namespace std;

class Timer{
    private:
        int startTime;
        int timeLimit;
        int currentTime;
        bool activated;
    public:
        Timer(){};

        void SetTimerSeconds(int seconds){ this->startTime = seconds; };

        void addTimeSeconds(int seconds){ this->timeLimit += seconds; };

        int GetCurrentTimeSeconds(){ return this->currentTime; };

        void ActivateTimer(){ 
            this->activated = true;
            this->currentTime = this->startTime;
        };

        void Ring(){ if (this->currentTime <= 0) { this->activated = false; } };
        
};