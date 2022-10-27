#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class FGame : public olc::PixelGameEngine
{
public:
	FGame()
	{
		sAppName = "Path Finding";
	}
private:
	struct FNode
	{
		bool bIsObstacle = false;
		bool bIsVisited = false;
		float GlobalGoal;
		float LocalGoal;
		int x;
		int y;
		std::vector<FNode*> Neighbours;
		FNode *Parent;
	};

	FNode* Nodes = nullptr;
	int MapWidth = 16;
	int MapHeight = 16;

	FNode* NodeStart = nullptr;
	FNode* NodeEnd = nullptr;

protected:
	virtual bool OnUserCreate() override
	{
		// Create a 2D array of nodes - this is for convenience of rendering and construction
		// and is not required for the algorithm to work - the nodes could be placed anywhere
		// in any space, in multiple dimensions...

		Nodes = new FNode[MapWidth * MapHeight];
		for(int x = 0; x < MapWidth; x++)
			for (int y = 0; y < MapHeight; y++)
			{
				Nodes[y * MapWidth + x].x = x;
				Nodes[y * MapWidth + x].y = y;
				Nodes[y * MapWidth + x].bIsObstacle = false;
				Nodes[y * MapWidth + x].Parent = nullptr;
				Nodes[y * MapWidth + x].bIsVisited = false;
			}

		//Manuelly position to start and end markrs
		NodeStart = &Nodes[(MapHeight / 2) * MapWidth + 1];
		NodeEnd = &Nodes[(MapHeight / 2) * MapWidth + MapWidth - 2];

		return true;
	}

	//----------------------------------------------------------------------------------------------
	void Solve_AStar()
	{
		//Reset Navigation Graph 
		for (int x = 0; x < MapWidth; x++)
			for (int y = 0; y < MapHeight; y++)
			{
				Nodes[y * MapWidth + x].GlobalGoal = INFINITY;
				Nodes[y * MapWidth + x].LocalGoal = INFINITY;
				Nodes[y * MapWidth + x].Parent = nullptr; //No parents
				Nodes[y * MapWidth + x].bIsVisited = false;
			}

		auto Distance = [](FNode* NodeA, FNode* NodeB) //For Distance
		{
			return sqrtf((NodeA->x - NodeB->x) * (NodeA->x - NodeB->x) + (NodeA->y - NodeB->y) * (NodeA->y - NodeB->y));
		};

		auto Heuristic = [Distance](FNode* NodeA, FNode* NodeB)
		{
			return Distance(NodeA, NodeB);
		};

		//setup starting conditions
		FNode* CurrentNode = NodeStart;
		NodeStart->GlobalGoal = 0.0f;
		NodeStart->LocalGoal = Heuristic(NodeStart, NodeEnd);

		// Add start node to not tested list - this will ensure it gets tested.
		// As the algorithm progresses, newly discovered nodes get added to this
		// list, and will themselves be tested later
		std::list<FNode*> listNotTestedNodes;
		listNotTestedNodes.push_back(NodeStart);

		while (!listNotTestedNodes.empty() && CurrentNode != NodeEnd)
		{
			// Sort Untested nodes by global goal, so lowest is first
			listNotTestedNodes.sort([](const FNode* Lhs, const FNode* Rhs) {return Lhs->GlobalGoal < Rhs->GlobalGoal; });


			// Front of listNotTestedNodes is potentially the lowest distance node. Our
			// list may also contain nodes that have been visited, so ditch these...
			while (!listNotTestedNodes.empty() && listNotTestedNodes.front()->bIsVisited)
				listNotTestedNodes.pop_front();

			//or abort because there are no valid nodes left to test
			if (listNotTestedNodes.empty())
				break;

			CurrentNode = listNotTestedNodes.front();
			CurrentNode->bIsVisited = true; //We only explore a node once

			//check each of this node´s neigbour
			for (auto NeighbourNode : CurrentNode->Neighbours)
			{
				//and only if the neighbour is not visited and is not an obstacle, add it to notTested List
				if (!NeighbourNode->bIsVisited && NeighbourNode->bIsObstacle == 0)
					listNotTestedNodes.push_back(NeighbourNode);

				//calculate the neighbours 
				float PossiblyLowelGoal = CurrentNode->LocalGoal + Distance(CurrentNode, NeighbourNode);


				// If choosing to path through this node is a lower distance than what 
				// the neighbour currently has set, update the neighbour to use this node
				// as the path source, and set its distance scores as necessary
				if (PossiblyLowelGoal < NeighbourNode->LocalGoal)
				{
					NeighbourNode->Parent = CurrentNode;
					NeighbourNode->LocalGoal = PossiblyLowelGoal;

					// The best path length to the neighbour being tested has changed, so
					// update the neighbour's score. The heuristic is used to globally bias
					// the path algorithm, so it knows if its getting better or worse. At some
					// point the algo will realise this path is worse and abandon it, and then go
					// and search along the next best path.

					NeighbourNode->GlobalGoal = NeighbourNode->LocalGoal + Heuristic(NeighbourNode, NodeEnd);
				}
			}
		}
	}

	virtual bool OnUserUpdate(float fElapsedTime)
	{
		int NodeSize = 9;
		int NodeBorder = 2;

		//Use Integer duvisor to nicely get cursor position in node space
		int SelectedNodeX = GetMouseX() / NodeSize;
		int SelectedNodeY = GetMouseY() / NodeSize;

		if (GetMouse(0).bReleased) // use mouse to draw maze
		{
			if (SelectedNodeX >= 0 && SelectedNodeX < MapWidth)
				if (SelectedNodeY >= 0 && SelectedNodeY < MapHeight)
				{
					if (GetKey(olc::Key::SHIFT).bHeld)
						NodeStart = &Nodes[SelectedNodeY * MapWidth + SelectedNodeX];
					else if (GetKey(olc::Key::CTRL).bHeld)
						NodeEnd = &Nodes[SelectedNodeY * MapWidth + SelectedNodeX];
					else
					Nodes[SelectedNodeY * MapWidth + SelectedNodeX].bIsObstacle = !Nodes[SelectedNodeY * MapWidth + SelectedNodeX].bIsObstacle;

					Solve_AStar();
				}
		}
		//Screen
		FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::BLACK);

		//Draw deconections
		FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::BLACK);
		for (int x = 0; x < MapWidth; x++)
			for (int y = 0; y < MapHeight; y++)
			{
				for (auto Node : Nodes[y * MapWidth + x].Neighbours)
				{
					DrawLine(x * NodeSize + NodeSize / 2, y * NodeSize + NodeSize / 2, Node->x * NodeSize + NodeSize / 2, Node->y * NodeSize + NodeSize / 2, olc::DARK_BLUE);
				}
			}

		//Create conections - in this case node are on a regular grid
		for (int x = 0; x < MapWidth; x++)
			for (int y = 0; y < MapHeight; y++)
			{
				if (y > 0)
					Nodes[y * MapWidth + x].Neighbours.push_back(&Nodes[(y - 1) * MapWidth + (x + 0)]);
				if (y < MapHeight - 1)
					Nodes[y * MapWidth + x].Neighbours.push_back(&Nodes[(y + 1) * MapWidth + (x + 0)]);
				if (x > 0)
					Nodes[y * MapWidth + x].Neighbours.push_back(&Nodes[(y + 0) * MapWidth + (x - 1)]);
				if (x < MapWidth - 1)
					Nodes[y * MapWidth + x].Neighbours.push_back(&Nodes[(y + 0) * MapWidth + (x + 1)]);
			}


		//Draw Nodes On Top
		for (int x = 0; x < MapWidth; x++)
			for (int y = 0; y < MapHeight; y++)
			{
				FillRect(x * NodeSize + NodeBorder, y * NodeSize + NodeBorder, NodeSize - NodeBorder, NodeSize - NodeBorder, Nodes[y * MapWidth + x].bIsObstacle ? olc::WHITE : olc::DARK_BLUE);

				if (Nodes[y * MapWidth + x].bIsVisited)
					FillRect(x * NodeSize + NodeBorder, y * NodeSize + NodeBorder, NodeSize - NodeBorder, NodeSize - NodeBorder, olc::BLUE);

				if (&Nodes[y * MapWidth + x] == NodeStart)
					FillRect(x * NodeSize + NodeBorder, y * NodeSize + NodeBorder, NodeSize - NodeBorder, NodeSize - NodeBorder, olc::GREEN);

				if (&Nodes[y * MapWidth + x] == NodeEnd)
					FillRect(x * NodeSize + NodeBorder, y * NodeSize + NodeBorder, NodeSize - NodeBorder, NodeSize - NodeBorder, olc::RED);
			}

		if (NodeEnd != nullptr)
		{
			FNode *p = NodeEnd;
			while (p->Parent != nullptr)
			{
				DrawLine(p->x * NodeSize + NodeSize / 2, p->y * NodeSize + NodeSize / 2, p->Parent->x * NodeSize + NodeSize / 2, p->Parent->y * NodeSize + NodeSize / 2, olc::YELLOW);
				// Set Next node to this Node's Parnt
				p = p->Parent;
			}
		}

		return true;
	}
};

int main()
{

	FGame Game;
	Game.Construct(160, 160, 6, 6);
	Game.Start();
	return 0;
}