#include "SetIterator.h"
#include "Set.h"
#include <exception>


SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation
	this->current = this->set.head;
}


void SetIterator::first() {
	//TODO - Implementation
	this->current = this->set.head;
}


void SetIterator::next() {
	//TODO - Implementation
	if (!valid())
		throw std::exception();
	else
		this->current = this->set.nextLink[this->current];
}


TElem SetIterator::getCurrent()
{
	//TODO - Implementation
	if(!valid())
		throw std::exception();
	else
		return this->set.arr[this->current];
}

bool SetIterator::valid() const {
	//TODO - Implementation
	return (this->set.arr[this->current] != -1);
}



