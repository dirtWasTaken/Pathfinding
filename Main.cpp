#include <list>
#include <assert.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

// Forward dec
struct Node;

struct Edge
{
	Edge(Node *target_, float cost_) : target(target_), cost(cost_) {}

	Node* target = nullptr;
	float cost;
};

struct Node
{
	Node(int id_) : id(id_) {}

	int id;
	float x = 0;
	float y = 0;
	bool traversed = false;
	bool isStart = false;
	float gScore = 0;
	Node *parent = nullptr;
	std::vector< Edge > connections;

	bool operator == (Node* other)
	{
		return this->id == other->id;
	}
};

bool compareNodes(const Node* first, const Node* second)
{

	return first->gScore < second->gScore;
}

std::list<Node*> findPath(Node* start, Node* end)
{
	//declaratin of lists used throughout the pathfinding algorithm
	std::list<Node*> openList;
	std::list<Node*> closedList;
	
	//allows the identification of the start Node
	start->isStart = true;
	start->parent = nullptr;
	//pushes the start node onto our list
	openList.push_back(start);
	
	while (!openList.empty())
	{
		//sorts the distances (gScore) of all the nodes as the are allocated
		openList.sort(compareNodes);

		//sets the current Node pointer based upon the open list 
		Node* currNode = openList.front();

		//breaks the loop once the loop has reached the end node (this can be and mouse input click for something like an rts or moba game)
		if (currNode == end)
		{
			break;
		}
		//removes the current node on the open list and places it onto the closed list, closed list is full of traversed nodes
		openList.erase(openList.begin());
		closedList.push_back(currNode);

		//ranged for loop 
		for (auto c : currNode->connections)
		{
			assert(c.target);
			//std::find used to locate the targert node within the closed list of the current node 
			if (std::find(closedList.begin(), closedList.end(), c.target) == closedList.end())
			{
				//then pushed the target node onto out open list 
				openList.push_back(c.target);
			}
			//sets the target nodes gScore to the current gScore plus the edge cost
			c.target->gScore = currNode->gScore + c.cost;
			//sets the parent of target to the current node
			c.target->parent = currNode;
		}
	}

	//the declation of another list which will only contain the shortest path
	std::list<Node*> path;

	Node* currNode = end;

	while (currNode->isStart == false)
	{
		//pushing back all the nodes that aren't the start node based on the bool we set at the start 
		path.push_back(currNode);
		//changes the current node to it's own parent pointed
		currNode = currNode->parent;
	}
	//the pushes the last node which will always be the start node 
	path.push_back(currNode);
	//returns the path
	return path;
}

void startApp()
{

}


int main()
{
	std::vector <Node*> graph;
	// Create all nodes in  the graph
	graph.push_back(new Node(0));
	graph.push_back(new Node(1));
	graph.push_back(new Node(2));
	graph.push_back(new Node(3));
	graph.push_back(new Node(4));
	graph.push_back(new Node(5));

	// Connect all nodes
	graph[0]->connections.push_back(Edge(graph[1], 2));
	graph[0]->connections.push_back(Edge(graph[5], 5));

	graph[1]->connections.push_back(Edge(graph[2], 3));

	graph[2]->connections.push_back(Edge(graph[3], 1));
	graph[2]->connections.push_back(Edge(graph[0], 3));

	graph[3]->connections.push_back(Edge(graph[5], 4));
	graph[3]->connections.push_back(Edge(graph[4], 4));

	graph[5]->connections.push_back(Edge(graph[4], 6));

	//using Node pointers
	std::list<Node*> path = findPath(graph[0], graph[4]);

	system("pause");
}



