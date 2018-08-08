#include <iostream>
#include <queue>
#include <list>
#pragma once
class pathfinding
{
public:
	pathfinding();
	~pathfinding();
	


	struct Node
	{
		bool traversed = false;
		Node* parent;
		std::list<Edge> connections;
	};

	void search(Node* startNode, Node* endNode);

	Node* list(float distance);

	void traverse();

	void shutdown();

private:



#define mySAFE_DELETE(ptr_)     \
{                               \
    if (ptr_)                   \
    {                           \
        delete ptr_;            \
        ptr_ = nullptr;         \
    }                           \
}

};
