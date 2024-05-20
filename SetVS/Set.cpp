#include "Set.h"
#include "SetITerator.h"

//complexity: o(n)
Set::Set() {
	//TODO - Implementation
	//the list is empty
	head = -1;
	arr = new TElem[capacity];
	//we initialize the list as an empty list
	for (int i = 0; i < capacity - 1; i++)
		nextLink[i] = -1;
	nextLink[capacity - 1] = -1;
	//the first empty position
	firstEmpty = 0;
}

//complexity: o(n)
int Set::allocate() {
	int i = firstEmpty;
	firstEmpty++;//we go on the next position to check if it is empty
	while(nextLink[firstEmpty] != -1) {
		firstEmpty++; //we go to the last pos in the list
	}
	firstEmpty++; //the last pos should have an elemet so the first empty is the next one
	return i;
}

//complexity: o(1)
void Set::deallocate(int i) {
	nextLink[i] = firstEmpty;
	firstEmpty = i;
}

//complexity: o(1)
int Set::createNode(TElem elem) {
	arr[firstEmpty] = elem;
	int i = 0;
	while (nextLink[i] != -1)
		i++;
	firstEmpty = i;
}

//revede add pe creere de linkuri DON'T COPYPASTA
bool Set::add(TElem elem) {
	//TODO - Implementation
	if(search(elem))
		return false;
	int i = this->createNode(elem);
	if (i != -1) {
		nextLink[i] = head;
		head = i;
	}
	return true;
}

//complexity: o(n)
bool Set::remove(TElem elem) {
	//TODO - Implementation
	bool found = false;
	int current = this->head;
	int prev = -1;
	while (current != -1 && !found)
		if (this->arr[current] == elem)
			found = true;
		else {
			prev = current;
			current = this->nextLink[current];
		}
	if (!found)
		return false;
	else {
		if (prev == -1)
			this->head = this->nextLink[this->head];
		else
			this->nextLink[prev] = this->nextLink[current];
		deallocate(current);
		return true;
	}
}
//complexity: o(n)
bool Set::search(TElem elem) const {
	//TODO - Implementation
	int current = this->head;
	while (current != -1)
		if (this->arr[current] == elem)
			return true;
		else
			current = this->nextLink[current];
	return false;
}

//complexity: o(n)
int Set::size() const {
	//TODO - Implementation
	int n = 0;
	int current = this->head;
	while (current != -1) {
		n++;
		current = this->nextLink[current];
	}
	return n;
}

//complexity: o(1)
bool Set::isEmpty() const {
	//TODO - Implementation
	return (head == -1);
}

//complexity: o(1)
Set::~Set() {
	//TODO - Implementation
	delete[] this->arr;
	delete[] this->nextLink;
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


