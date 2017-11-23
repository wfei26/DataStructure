/********************************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/23/15
*File: Timer.h
*Course: EECS560 - Data Structure
*Project: Lab10 - Comparing the performance of Binomial queue with Leftist Heap and Skew Heap
*********************************************************************************************/


#ifndef TIMER_H_
#define TIMER_H_

#include <stdio.h>
#include <stdlib.h>
//#include <sys/time.h>
#include <time.h>
#include <windows.h>

using namespace std;

class Timer {
private:
	timeval startTime;
	timeval endTime;

public:
	Timer();

	~Timer();

	void start();

	double stop();

	void printTime(double duration);
};
#endif