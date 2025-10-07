#pragma once
#include "Vector2.h"
#include "INodeContent.h"
#include <mutex>
class Node
{
public:

	Node(Vector2 position);

	INodeContent* GetContent();

	template <typename T, typename = typename std::enable_if<std::is_base_of<INodeContent, T>::value>::type>
	T* GetContent() {
		T* contentCasted = dynamic_cast<T*>(_content);
		return contentCasted;
	}
	void setContent(INodeContent* newContent);
	void DrawContent(Vector2 offset);

	void lock();
	void unlock();

private:

	Vector2 _position;
	INodeContent* _content;
	std::mutex _classMutex;

};

