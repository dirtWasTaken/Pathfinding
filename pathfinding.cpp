#include "pathfinding.h"



pathfinding::pathfinding()
{
}


pathfinding::~pathfinding()
{
}

void pathfinding::list(float distance)
{

	Node* new_node = new Node;
	if (foo.empty())
	{
		// First node in the list
		new_node->prev = new_node;
		new_node->traversed = true;
		new_node->distance = 0;
		foo.push_back(new_node);
	}
	else
	{
		// All subsequent nodes
		new_node->distance = distance;
		new_node->prev = foo.back();
		new_node->prev->traversed = true;
		foo.push_back(new_node);

	}

}

void pathfinding::traverse()
{

}

void pathfinding::shutdown()
{
	if (!foo.empty())
	{
		foo.clear();
	}

}


