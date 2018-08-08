#include <list>
#include <queue>
#include <vector>
#include <iostream>

// Forward dec
struct Node;
std::vector <Node*> graph;
std::vector <Node*> queue;
float totalTraversalCost;

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
	float gScore = 1000;
	Node *parent = nullptr;
	std::vector< Edge > connections;
};


//void findPath(int start, int end)
//{
//	graph[start]->parent = graph[start];
//	graph[start]->gScore = 0;
//	float currentGscore = 0;
//
//	while (!graph.empty())
//	{
//		for (size_t i = start; i < end; i++)
//		{
//			graph[i]->traversed = true;
//
//			for (size_t c = 0; c < graph[i]->connections.size(); c++)
//			{
//				if (graph[end]->traversed == false)
//				{
//					currentGscore = graph[i]->gScore + graph[i]->connections[c].cost;
//
//					if (currentGscore < graph[end]->gScore)
//					{
//						graph[end]->parent = graph[i];
//						graph[end]->gScore = currentGscore;
//						std::cout << currentGscore << "\n\n";
//					}
//				}
//			}
//
//		}
//	}
//}


//void findPath(Node* start, Node* end)
//{
//	queue.push_back(start);
//	start->parent = start;
//	start->gScore = 0;
//
//	while (!graph.empty())
//	{
//		for (size_t i = start->id; i <= end->id; i++)
//		{
//
//
//			if (!graph.empty())
//			{
//			graph.erase(graph.begin());
//			queue.push_back(graph.front());
//			}
//
//			queue[i]->traversed = true;
//
//				for (size_t c = 0; c < queue.back()->connections.size(); c++)
//				{
//					if (end->traversed == false)
//					{
//						queue[i]->connections[c].target->gScore += queue[i]->connections[c].cost;
//
//						if (queue[i]->gScore < end->gScore)
//						{
//							end->parent = queue[i];
//							end->gScore += queue[i]->gScore;
//							std::cout << queue[i]->gScore << "\n\n";
//
//							//if (i == 0)
//							//{
//							//	queue.push_back(end);    
//							//}
//							if (i == 4)
//							{
//								break;
//								queue.clear();
//							}
//						}
//						else
//						{
//							break;
//						}
//					}
//				}
//		}
//	}
//}

void findPath(Node* start, Node* end)
{
	queue.push_back(start);
	start->parent = start;
	start->gScore = 0;

	while (!graph.empty())
	{ 
			graph.erase(graph.begin());
			queue.back()->traversed = true;
			
			for (size_t c = 0; c < queue.back()->connections.size(); c++)
			{
				if (end->traversed == false)
				{
					queue.back()->connections[c].target->gScore = queue.back()->connections[c].cost;

					if (queue.back()->connections[c].target->gScore < end->gScore)
					{
						end->parent = queue.back();
						end->gScore += queue.back()->connections[c].target->gScore;
						std::cout << "current node gScore:  " << queue.back()->id <<"   "<<queue.back()->connections[c].target->gScore << "\n\n";
						std::cout << "end gScore:  " << end->gScore - 1000 << "\n\n";
					}
				}
			}

			if (!graph.empty())
			{
				queue.push_back(graph.front());
			}
	}

}
						//if (i == 0)
						//{
						//	queue.push_back(end);    
						//}
						//if (i == 4)
						//{
						//	break;
						//	queue.clear();
						//}
				/*		else
						{
							break;
						}*/



		/*
		{
			if (i > 0)
			{
				queue.push_back(graph[i]);
			}
			queue[i]->traversed = true;

			for (size_t c = 0; c < queue[i]->connections.size(); c++)
			{
 				if (end->traversed == false)
				{
					start->gScore = queue[i]->gScore + queue[i]->connections[c].cost;

					if (queue[i]->connections[c].cost < end->gScore)
					{
						end->parent = queue[i];
						end->gScore = start->gScore;
						totalTraversal += end->gScore;
						std::cout << totalTraversal << "\n\n";
					}
				}
			}

		}
	}*/

void startApp()
{

}


int main()
{
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
	//using an int
	//findPath(0, 5);

	//using Node pointers
	findPath(graph[0], graph[4]);

	system("pause");
}



