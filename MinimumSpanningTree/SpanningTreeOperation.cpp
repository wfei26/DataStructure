/*****************************************
*Name: Wei Fei
*KUID: 2538810
*Date: 05/03/15
*File: SpanningTreeOperation.cpp
*Course: EECS560 - Data Structure
*Project: Lab9 - Minimum Spanning Tree
******************************************/

#include "SpanningTreeOperation.h"
using namespace std;

SpanningTreeOperation::SpanningTreeOperation()
{
	graphCount = 0;
	//edgeCount = 0;
	nodeCount = 0;
	bufferArray = NULL;
	myEdge = NULL;
}


SpanningTreeOperation::~SpanningTreeOperation()
{
}


void SpanningTreeOperation::readfile()
{
	ifstream file;
	file.open("data.txt");
	if (!file)
	{
		cout << "Error! File does not exist." << endl;
	}
	else
	{
		int newEntry = 0;
		int itemValue = 0;
		int edgeCount = 0;
		int tempCount = 0;
		int round = 1;
		//int cost[50][50];
		//int visit[50];
		//int des[50], point[50];
		nodeCount = 0;
		if (file >> newEntry)
		{
			graphCount = newEntry;
		}

		while (file >> newEntry)
		{
			cout << "\nGraph" << round << ": " << endl;
			nodeCount = newEntry;
			edgeCount = 0;
			tempCount = 0;
			Edge* bufEdge = new Edge[nodeCount * nodeCount];

			/*
			for (int i = 0; i <= nodeCount; i++)
			{
				for (int j = 0; j <= nodeCount; j++)
				{
					cost[i][j] = 0;
				}
			}
			for (int i = 0; i < nodeCount; i++)
			{
				point[i] = visit[i] = 0;
				des[i] = 10000;
			}
			*/

			for (int i = 0; i < nodeCount; i++)
			{
				for (int j = 0; j < nodeCount; j++)
				{
					primBuf[i][j] = 0;
				}
			}

			for (int i = 0; i < nodeCount; i++)
			{
				for (int j = 0; j < i; j++)
				{
					if (file >> newEntry)
					{
						itemValue = newEntry;
					}
					primBuf[i][j] = itemValue;
				}
				for (int j = i; j < nodeCount; j++)
				{
					if (file >> newEntry)
					{
						itemValue = newEntry;
					}
					primBuf[i][j] = itemValue;
					if (itemValue != 0)
					{
						bufEdge[edgeCount].setFrontVertex(i);
						bufEdge[edgeCount].setBackVertex(j);
						bufEdge[edgeCount].setWeight(itemValue);
						//cost[i][j] = cost[j][i] = itemValue;
						edgeCount++;
						//cout << itemValue << " ";
					}
				}
			}
			sortEdge(bufEdge, edgeCount);

			/*
			for (int i = 0; i < nodeCount; i++)
			{
				for (int j = 0; j < nodeCount; j++)
				{
					cout << cost[i][j] << " ";
				}
				cout << endl;
			}
			*/
			/*
			for (int i = 0; i < nodeCount; i++)
			{
				for (int j = 0; j < nodeCount; j++)
				{
					cout << primBuf[i][j] << " ";
				}
				cout << endl;
			}
			*/
			
			/*
			for (int a = 0; a < edgeCount; a++)
			{
				cout << bufEdge[a].getWeight() << " ";
			}
			*/
			//cout << "\nBreak Point!" << endl;

			bufferArray = new GraphNode*[nodeCount];
			for (int i = 0; i < nodeCount; i++)
			{
				bufferArray[i] = new GraphNode(i, 0);
				bufferArray[i]->setParent(bufferArray[i]);
			}
			kruskalAlgorithm(bufEdge, nodeCount, edgeCount);
			primAlgorithm(primBuf, nodeCount, round);
			round++;
		}
	}
	file.close();
}


void SpanningTreeOperation::sortEdge(Edge* newEdge, int n)
{
	int temp = 1;
	bool sort = false;
	while (!sort && (temp < n))
	{
		sort = true;
		for (int i = 0; i < (n - temp); i++)
		{
			int tempIndex = i + 1;
			if (newEdge[i].getWeight() > newEdge[tempIndex].getWeight())
			{
				swap(newEdge[i], newEdge[tempIndex]);
				sort = false;
			}
		}
		temp++;
	}

}


int SpanningTreeOperation::findItem(int index)
{
	int tempCount = 0;
	GraphNode** tempArr = new GraphNode*[nodeCount];
	GraphNode* tempNode = bufferArray[index];
	
	while (tempNode->getParent() != tempNode)
	{
		GraphNode* nextPtr = tempNode->getParent();
		tempArr[tempCount] = tempNode;
		tempCount++;
		tempNode = nextPtr;
	}
	for (int i = 0; i < tempCount; i++)
	{
		tempArr[i]->setParent(tempNode);
	}
	return tempNode->getItem();
}


void SpanningTreeOperation::unionTree(int tree1, int tree2)
{
	GraphNode* tempNode1 = bufferArray[tree1];
	GraphNode* tempNode2 = bufferArray[tree2];
	
	if (tempNode1->getRank() < tempNode2->getRank())
	{
		tempNode1->setParent(tempNode2);
	}
	else if (tempNode1->getRank() > tempNode2->getRank())
	{
		tempNode2->setParent(tempNode1);
	}
	else
	{
		tempNode2->setParent(tempNode1);
		tempNode1->setRank(tempNode1->getRank() + 1);
	}
}


void SpanningTreeOperation::kruskalAlgorithm(Edge* bufEdge, int nodeCount, int edgeCount)
{
	int tempCount = 0;
	Edge* tempEdge = new Edge[nodeCount - 1];
	for (int i = 0; (tempCount != nodeCount - 1) && (i < edgeCount); i++)
	{
		Edge bufEdge2 = bufEdge[i];
		if (findItem(bufEdge2.getFrontVertex()) != findItem(bufEdge2.getBackVertex()))
		{
			tempEdge[tempCount] = bufEdge2;
			unionTree(findItem(bufEdge2.getFrontVertex()), findItem(bufEdge2.getBackVertex()));
			tempCount++;
		}
	}
	printKruskalAlgorithm(nodeCount, tempCount, tempEdge);
}


void SpanningTreeOperation::primAlgorithm(int newPrimBuf[][100], int nodeNum, int temp)
{
	/*
	for (int i = 0; i < nodeNum; i++)
	{
		for (int j = 0; j < nodeNum; j++)
		{
			cout << newPrimBuf[i][j] << " ";
		}
		cout << endl;
	}
	*/

	int tempNum1 = 0, tempNum2 = 0, buf1 = 0, buf2 = 0, buf3 = 2, buf4 = 0, round = 0;
	int tempBuf[100];
	Edge* primEdgeBuf = new Edge[nodeNum];
	tempBuf[0] = 1;
	while (round < nodeNum - 1)
	{
		int minNum = 10000;
		for (int i = 0; i < nodeNum; i++)
		{
			if (tempBuf[i] == 1)
			{
				for (int j = 0; j < nodeNum;)
				{
					if (newPrimBuf[i][j] >= minNum || newPrimBuf[i][j] == 0)
					{
						j++;
					}
					else if (newPrimBuf[i][j] < minNum)
					{
						minNum = newPrimBuf[i][j];
						tempNum1 = i;
						tempNum2 = j;
					}
				}
			}

		}
		tempBuf[tempNum2] = 1;
		buf1 = 3; buf2 = 4;
		primEdgeBuf[round].setFrontVertex(tempNum1);
		primEdgeBuf[round].setBackVertex(tempNum2);
		primEdgeBuf[round].setWeight(minNum);

		if (temp == buf1)
		{
			if (primEdgeBuf[round].getFrontVertex() == buf3 && primEdgeBuf[round].getBackVertex() == buf2)
			{
				primEdgeBuf[round].setFrontVertex(buf1);
				primEdgeBuf[round].setBackVertex(buf2);
			}
			if (primEdgeBuf[round].getFrontVertex() == buf4 && primEdgeBuf[round].getBackVertex() == buf3)
			{
				primEdgeBuf[round].setFrontVertex(buf3);
				primEdgeBuf[round].setBackVertex(buf2);
			}
		}
		/*
		QueueOperation myEdgeQueue;
		Edge* tempM;
		for (int i = 0; i < nodeNum - 1; i++) {
			for (int j = 0; j < nodeNum - i - 1; j++) {
				if (primEdge[j + 1] == NULL || primEdge[j]->getWeight() > primEdge[j + 1]->getWeight()) {
					tempM = primEdge[j];
					primEdge[j] = primEdge[j + 1];
					primEdge[j + 1] = tempM;
				}
			}
		}
		*/
		newPrimBuf[tempNum2][tempNum1] = 10000;
		newPrimBuf[tempNum1][tempNum2] = newPrimBuf[tempNum2][tempNum1];
		round++;
	}
	printPrimAlgorithm(primEdgeBuf, nodeNum);
}


void SpanningTreeOperation::printKruskalAlgorithm(int numNode, int numTemp, Edge* newEdge)
{
	cout << "Kruskal: ";
	if (numTemp == numNode - 1)
	{
		for (int i = 0; i < numTemp; i++)
		{
			cout << "(" << newEdge[i].getFrontVertex() << ", " << newEdge[i].getBackVertex() << ") ";
		}
		cout << endl;
	}
}


void SpanningTreeOperation::printPrimAlgorithm(Edge* primEdgeBuf, int nodeNum)
{
	cout << "Prim: ";
	for (int i = 0; i < nodeNum - 1; i++)
	{
		if (primEdgeBuf[i].getFrontVertex() > primEdgeBuf[i].getBackVertex())
		{
			int temp = 0;
			temp = primEdgeBuf[i].getFrontVertex();
			primEdgeBuf[i].setFrontVertex(primEdgeBuf[i].getBackVertex());
			primEdgeBuf[i].setBackVertex(temp);
		}
		cout << "(" << primEdgeBuf[i].getFrontVertex() << ", " << primEdgeBuf[i].getBackVertex() << ") ";
	}
	cout << endl;	
}


void SpanningTreeOperation::finalOutput()
{
	cout << "Output:" << endl;
	readfile();
}