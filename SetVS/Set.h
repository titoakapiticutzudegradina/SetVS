#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111
typedef int TElem;
class SetIterator;

class Set {
	//DO NOT CHANGE THIS PART
	friend class SetIterator;

    private:
		//TODO - Representation
        static const int capacity = 180000; //fixed capacity number
        TElem *arr; //array of elements;
        int nextLink[capacity]; //array of next links;
        int head; //head of the list;
        int firstEmpty; //first empty position in the array;

        int allocate(); //allocates a new position in the array;
        void deallocate(int i); //deallocates a position in the array;
        int createNode(TElem e); //creates a new node with the element e;

    public:
        //implicit constructor
        Set();

        //adds an element to the set
		//returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
        bool add(TElem e);

        //removes an element from the set
		//returns true if e was removed, false otherwise
        bool remove(TElem e);

        //checks whether an element belongs to the set or not
        bool search(TElem elem) const;

        //returns the number of elements;
        int size() const;

        //check whether the set is empty or not;
        bool isEmpty() const;

        //return an iterator for the set
        SetIterator iterator() const;

        // destructor
        ~Set();

};





