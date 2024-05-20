#include "Set.h"
#include "SetITerator.h"

//complexity: o(1)
Set::Set() {
	//TODO - Implementation
	this->length = 0;
	this->capacity = 11;
	//the list is empty
	this->head = -1;
	this->arr = new TElem[capacity];
	this->nextLink = new int[capacity];
	for (int i = 0; i < this->capacity - 1; i++)
		this->nextLink[i] = i + 1;
	this->nextLink[this->capacity - 1] = this->capacity;
	//the first empty position
	this->firstEmpty = 0;
}

//complexity: o(n)
void Set::resize()
{
	this->capacity *= 2;
	TElem* newarr = new TElem[this->capacity];
	int* newnext = new int[this->capacity];
	for (int i = 0; i < this->length; i++)
	{
		newarr[i] = this->arr[i];
		newnext[i] = this->nextLink[i];
	}
	for (int i = this->length; i < this->capacity - 1; i++)
		newnext[i] = i + 1;
	newnext[this->capacity - 1] = this->capacity;
	delete[] this->arr;
	delete[] this->nextLink;
	this->arr = newarr;
	this->nextLink = newnext;
}

//complexity: o(1)
int Set::allocate() {
	//we delete the first empty position from the list of empty positions
	int i = this->firstEmpty;
	this->firstEmpty = this->nextLink[this->firstEmpty];
	return i;
}

//complexity: o(1)
void Set::deallocate(int i) {
	//we add the position at index i at the beginning of the list of empty positions
	this->nextLink[i] = this->firstEmpty;
	this->firstEmpty = i;
}

//complexity: BEST:theta(1) WORST:theta(n) AVG:o(n)
int Set::createNode(TElem elem) {
	//Create one node having e as the useful information
	int i = allocate();
	this->length++;
	if (i != -1) {
		if (this->length == this->capacity)
			resize();
		this->arr[i] = elem;
		this->nextLink[i] = -1;
	}
	return i;
}

//complexity: o(n)
bool Set::add(TElem elem) {
	//TODO - Implementation
	//check if the element is already in the set
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
		//we have to remove the element at index current
		if (prev == -1)
			this->head = this->nextLink[this->head];
		else
			this->nextLink[prev] = this->nextLink[current];
		this->length = this->length - 1;
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
	return (this->head == -1);
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


