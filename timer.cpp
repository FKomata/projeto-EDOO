#include "timer.hpp"

Timer::Timer(int StartTime, int timLimit, int currentTime, bool activated) {
    this->startTime = StartTime;
    this->timeLimit = timLimit;
    this->currentTime = currentTime;
    this->activated = activated;
}

void Timer::SetTimerSeconds(int seconds){
    this->startTime = seconds;
    this->currentTime = startTime;
}

void Timer::addTimeSeconds(int seconds){
    this->currentTime += seconds;
}

int Timer::GetCurrentTimeSeconds() {
    return this->currentTime;
}

void Timer::ActivateTimer() {
    this->activated = true;
    this->currentTime = this->startTime;
}

void Timer::Ring() {
    if (this->currentTime <= 0) {
        this->activated = false;
    }

    cout << "Tempo Esgotado!" << endl;
}

void Timer:: printTimer() {
    cout << "Tempo Restante: " << this->startTime << " segundos" << endl;

}