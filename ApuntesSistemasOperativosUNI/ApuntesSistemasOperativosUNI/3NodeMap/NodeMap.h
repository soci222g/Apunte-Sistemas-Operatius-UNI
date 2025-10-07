#pragma once
#include<vector>
#include<functional>
#include<list>
#include<mutex>

#include"Node.h"

class NodeMap
{
public:
	typedef std::vector<Node*> NodeColum;
	typedef std::vector<NodeColum*> NodeGrid;


	typedef std::function<void(Node* node)> SafePick;
	typedef std::function<void(std::list<Node*> nodes)> SafeMultipick ;

public:
	NodeMap(Vector2 size, Vector2 offcet);

	Vector2 getSize();

	void UnSafeDraw();
	void SafePickNode(Vector2 position, SafePick safePickAction);
	void SafeMultiPickNode(std::list<Vector2> positions, SafeMultipick safeMultiPickAction);


private:

	Vector2 _offcet;
	Vector2 _size;

	NodeGrid _grid;
	std::mutex _sizeMutex;
	std::mutex _gridMutex;

	std::mutex _safeMultiPcik;

	Node* UnSafeGetNode(Vector2 position);

};

