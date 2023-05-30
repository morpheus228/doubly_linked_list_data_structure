#include "list.h"
#include <iostream>

using namespace std;


List::List() {
	this->Head = Node();
	this->Tail = Node();
	this->m_size = 0;

	Head.pNext = &Tail;
	Tail.pPrev = &Head;
}

List::~List() {
	Node* cur_node = Head.pNext;

	while (cur_node != &Tail) {
		Node* tmp = cur_node->pNext;
		delete cur_node;
		cur_node = tmp;
	}
}

void List::apptop(const Circle& circle) {
	Node* new_node = new Node(&circle);

	new_node->pPrev = &Head;
	new_node->pNext = Head.pNext;
	Head.pNext->pPrev = new_node;
	Head.pNext = new_node;

	m_size++;
}

void List::append(const Circle& circle) {
	Node* new_node = new Node(&circle);
	
	new_node->pNext = &Tail;
	new_node->pPrev = Tail.pPrev;

	Tail.pPrev->pNext = new_node;
	Tail.pPrev = new_node;

	m_size++;
}

bool List::pop(const Circle& circle) {
	Node* cur_node = Head.pNext;

	while (cur_node != &Tail) {
		if (*(cur_node->m_Data) == circle) {
			delete cur_node;
			m_size--;
			return true;
		}

		cur_node = cur_node->pNext;
	}
	return false;
}

unsigned int List::remove(const Circle& circle) {
	unsigned int count = 0;
	Node* cur_node = Head.pNext;

	while (cur_node != &Tail) {
		if (*(cur_node->m_Data) == circle) {
			Node* tmp = cur_node; 
			cur_node = cur_node->pNext;
			delete tmp;
			count++;
		}
		else cur_node = cur_node->pNext;
	}
	m_size -= count;
	return count;
}

void List::clear() {
	Node* cur_node = Head.pNext;

	while (cur_node != &Tail) {
		Node* tmp = cur_node;
		cur_node = cur_node->pNext;
		delete tmp;
	}
	m_size = 0;
}


void List::sort(bool ascending) {
	if (m_size > 1) {

		for (int i = 0; i < m_size - 1; i++) {
			Node* cur_node = Head.pNext;
			while (cur_node->pNext != &Tail) {

				if (ascending) {
					if (cur_node->m_Data->getArea() > cur_node->pNext->m_Data->getArea()) cur_node->swapWithNext();
					else cur_node = cur_node->pNext;
				}

				else {
					if (cur_node->m_Data->getArea() < cur_node->pNext->m_Data->getArea()) cur_node->swapWithNext();
					else cur_node = cur_node->pNext;
				}
			}
		}
	}
}

void List::debug_print() {
	Node* cur_node = &Head;

	while (cur_node != NULL) {
		cout << "Prev =  " << cur_node->pPrev << endl;
		cout << "Address: " << cur_node << endl;
		cout << "Next =  " << cur_node->pNext << endl;
		cout << endl;

		cur_node = cur_node->pNext;
	}
}

size_t List::getLen() {
	return m_size;
}


std::ostream& operator<<(std::ostream& out, const List& list) {
	Node* cur_node = list.Head.pNext;
	while (true) {
		if (cur_node != &(list.Tail)) {
			out << *(cur_node->m_Data);

			if (cur_node->pNext != &(list.Tail)) {
				out << endl;
				cur_node = cur_node->pNext;
			}
			else break;
		}
		else break;
	}
	return out;
};


std::istream& operator>>(std::istream& in, List& list) {
	if (in.peek() != '\n') {
		int x, y, r;
		while (!in.eof()) {
			in.ignore(8);
			in >> x;
			in.ignore(2);
			in >> y;
			in.ignore(9);
			in >> r;
			in.ignore();
			list.append(Circle(x, y, r));
		}
	}
	return in;
}

