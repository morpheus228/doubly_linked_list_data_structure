#include "node.h"

class List {
	Node Head;
	Node Tail;
	size_t m_size;

public:
	List();
	~List();

	void apptop(const Circle& circle);
	void append(const Circle& circle);
	bool pop(const Circle& circle);
	unsigned int remove(const Circle& circle);
	void clear();
	void sort(bool ascending = true);

	void debug_print();
	size_t getLen(); // const

	friend std::ostream& operator<<(std::ostream& out, const List& list);
	friend std::istream& operator>>(std::istream& in, List& list);

};