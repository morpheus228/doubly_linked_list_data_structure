#include "node.h"

//Node::Node(const Circle circle) {
//	this->m_Data = circle;
//	this->pPrev = NULL;
//	this->pNext = NULL;
//}

Node::Node() {
	this->m_Data = NULL;
	this->pPrev = NULL;
	this->pNext = NULL;
}

Node::Node(const Circle* pc)
{
	this->m_Data = new Circle(*pc);
	this->pPrev = NULL;
	this->pNext = NULL;
}

Node::~Node() {
	if (this->m_Data != NULL) {
		pPrev->pNext = this->pNext;
		pNext->pPrev = this->pPrev;
		delete this->m_Data;
	}
}

void Node::swapWithNext() {
	Node* first = this->pPrev;
	Node* second = this;
	Node* third = this->pNext;
	Node* fourth = this->pNext->pNext;

	first->pNext = third;
	fourth->pPrev = second;
	
	second->pPrev = third;
	second->pNext = fourth;
	
	third->pPrev = first;
	third->pNext = second;
}
