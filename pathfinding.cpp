#include "pathfinding.h"



pathfinding::pathfinding()
{
}


pathfinding::~pathfinding()
{
}

struct Edge
{
	pathfinding::Node* target;
	float distance = 100000;
};

pathfinding::Node* pathfinding::list(float distance)
{

	//Node* new_node = new Node;
	//if (new_node->connections.empty())
	//{
	//	// First node in the list
	//	new_node->parent = new_node;
	//	new_node->traversed = true;
	//	new_node->connections.push_back(new_node);
	//}
	//else
	//{
	//	// All subsequent nodes
	//	new_node->distance = distance;
	//	new_node->prev = .back();
	//	foo.push_back(new_node);

	//}


}

void pathfinding::search(Node* startNode, Node* endNode)
{
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


