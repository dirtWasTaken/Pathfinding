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
		Node* prev = nullptr;
		float distance = 100000;
	};

	std::list<Node*> foo;

	void list(float distance);

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

