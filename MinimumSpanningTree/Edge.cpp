/*****************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 05/03/15
*File: Edge.cpp
*Course: EECS560 - Data Structure
*Project: Lab9 - Minimum Spanning Tree
******************************************/


#include "Edge.h"


Edge::Edge()
{
	weight = 0;
	frontVertex = -1;
	backVertex = -1;
}


Edge::Edge(int newWeight, int newFrontVertex, int newBackVertex)
{
	weight = newWeight;
	frontVertex = newFrontVertex;
	backVertex = newBackVertex;
}


Edge::~Edge()
{
}


int Edge::getWeight()
{
	return weight;
}


void Edge::setWeight(int newWeight)
{
	weight = newWeight;
}


int Edge::getFrontVertex()
{
	return frontVertex;
}


void Edge::setFrontVertex(int newFrontVertex)
{
	frontVertex = newFrontVertex;
}


int Edge::getBackVertex()
{
	return backVertex;
}


void Edge::setBackVertex(int newBackVertex)
{
	backVertex = newBackVertex;
}
