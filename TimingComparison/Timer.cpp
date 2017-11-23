/********************************************************************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 04/23/15
*File: Timer.cpp
*Course: EECS560 - Data Structure
*Project: Lab10 - Comparing the performance of Binomial queue with Leftist Heap and Skew Heap
*********************************************************************************************/

#include "Timer.h"


Timer::Timer()
{
}


Timer::~Timer()
{
}

void Timer::start()
{
	//gettimeofday(&startTime, NULL);
}

double Timer::stop()
{
	long seconds, nseconds;
	double duration;

	//gettimeofday(&endTime, NULL);

	seconds = endTime.tv_sec - startTime.tv_sec;
	nseconds = endTime.tv_usec - startTime.tv_usec;

	duration = seconds + nseconds / 1000000.0;

	return duration;
}

void Timer::printTime(double duration)
{
	printf("%5.6f seconds\n", duration);
}