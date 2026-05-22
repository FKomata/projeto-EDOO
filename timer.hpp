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
        Timer(int StartTime, int timLimit, int currentTime, bool activated);

        void SetTimerSeconds(int seconds);
        void addTimeSeconds(int seconds);
        int GetCurrentTimeSeconds();
        void ActivateTimer();
        void Ring();

        void printTimer();
        
};