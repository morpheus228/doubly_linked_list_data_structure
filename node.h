#include "circle.h"


class Node {
	Circle* m_Data;
	Node* pPrev;
	Node* pNext;

public:
	Node();
	Node(const Circle*);
	~Node();

	void swapWithNext();

	friend class List;
	friend std::ostream& operator<<(std::ostream& os, const List& list);
};
