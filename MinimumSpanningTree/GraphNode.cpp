/*****************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 05/03/15
*File: GraphNode.cpp
*Course: EECS560 - Data Structure
*Project: Lab9 - Minimum Spanning Tree
******************************************/

#include "GraphNode.h"


GraphNode::GraphNode()
{
	item = -1;
	rank = 0;
	parentPtr = NULL;
}


GraphNode::GraphNode(int newItem, int newRank)
{
	item = newItem;
	rank = newRank;
	parentPtr = NULL;
}


GraphNode::GraphNode(int newItem, int newRank, GraphNode* newParentPtr)
{
	item = newItem;
	rank = newRank;
	parentPtr = newParentPtr;
}


GraphNode::~GraphNode()
{
}


int GraphNode::getItem()
{
	return item;
}


void GraphNode::setItem(int newItem)
{
	item = newItem;
}


int GraphNode::getRank()
{
	return rank;
}


void GraphNode::setRank(int newRank)
{
	rank = newRank;
}


GraphNode* GraphNode::getParent()
{
	return parentPtr;
}


void GraphNode::setParent(GraphNode* newParentPtr)
{
	parentPtr = newParentPtr;
}