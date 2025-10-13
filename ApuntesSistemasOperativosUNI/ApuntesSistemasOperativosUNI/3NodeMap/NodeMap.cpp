#include "NodeMap.h"

NodeMap::NodeMap(Vector2 size, Vector2 offcet)
{
	_size = size;
	_offcet = offcet;

	for (int x = 0; x < _size.X; x++) {
		NodeColum* column = new NodeColum();
		for (int y = 0; y < _size.X; y++) {

			column->push_back(new Node(Vector2(x, y)));
		}
		_grid.push_back(column);
	}
}

Vector2 NodeMap::getSize()
{
	_sizeMutex.lock();
	Vector2 size = _size;
	_sizeMutex.unlock();



	return _size;
}

void NodeMap::UnSafeDraw()
{
	for (NodeColum* Column : _grid) {
		for (Node* node : *Column) {
			node->DrawContent(_offcet);
		}

	}
}

void NodeMap::SafePickNode(Vector2 position, SafePick safePickAction)
{
	_sizeMutex.lock();
	_gridMutex.lock();

	Node* node = UnSafeGetNode(position);

	_sizeMutex.unlock();
	_gridMutex.unlock();

	node->lock();
	safePickAction(node);
	node->unlock();

}

void NodeMap::SafeMultiPickNode(std::list<Vector2> positions, SafeMultipick safeMultiPickAction)
{
	std::list<Node*> nodes = std::list<Node*>();


	_sizeMutex.lock();
	_gridMutex.lock();

	for (Vector2 pos : positions){

		nodes.push_back(UnSafeGetNode(pos));

	}

	_sizeMutex.unlock();
	_gridMutex.unlock();

	_safeMultiPcik.lock();
	for (Node* node : nodes) {
		if (node != nullptr) {
			node->lock();
		}
	}

	_safeMultiPcik.unlock();

	safeMultiPickAction(nodes);

	for (Node* node : nodes) {
		if (node != nullptr) {
			node->unlock();
		}
	}

}



Node* NodeMap::UnSafeGetNode(Vector2 position)
{
	if (position.X >= _size.X || position.Y >= _size.Y|| position.X < 0||position.Y < 0) {
		return nullptr;
	}
	NodeColum* column = _grid[position.X];
	Node* node = (*column)[position.Y];

	return node;
}
