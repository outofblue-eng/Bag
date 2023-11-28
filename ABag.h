#pragma once	

#include "book.h"
#include "bagADT.h"
template <typename E>
class ABag : public Bag<E> {
public:
	//constructor
	ABag(int size=defaultSize)
	{
		items = 0;
		maxSize = size;
	}

	//destructor
	~ABag() {};
	
	// the addItem function adds an item to the bag that returns true when item add was successful and false when operation fails
	bool addItem(const E& item) override
	{
		if (items < maxSize)
		{
			bag[items] = item;
			items++;
			return true;
		}
		else {
			return false;
		}
	}
	
	//the remove function finds the item in the bag and if the item is found updates sets the item to the value and removes from the bag, return true 
	//else, return false and keep the same key
	bool remove(E& item) override
	{
		if (numItems() > 0)
		{
			for (int i = 0;i < numItems();i++)
			{
				if (bag[i] == item)
				{
					item = bag[i];
					items--;
					for (int j = i;j < numItems();j++)
					{
						bag[j] = bag[j++];
					}
					return true;
				}
			}
		}
		else
		{
			return false;
		}
	}
	
	//the removeTop function goes to the top record of the bag and moves it and makes it the return value while returning false
	//if the bag is empty, return false
	bool removeTop(E& returnValue) override
	{
		if (items > 0) {
			items--;
			returnValue = bag[items];
			return true;
		}
		else {
			return false;
		}
		
	}
	
	//the find function finds the item, sets the return value to the value and returns true. If successful, return true, if not, return false
	bool find(E& returnValue) const override
	{
		for (int i = 0; i < items;i++) {
			if (bag[i] == returnValue)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

	}
	
	//the inspectTop function looks at the top of the bag and updates the item to the top content of the bag. return true if there are items in the bag
	//returns false if there are no items in the bag
	bool inspectTop(E& item) const override
	{
		if (items <= 0)
		{
			return false;
		}
		else
		{
			item = bag[items-1];
		}
	}
	
	//the function emptyBag makes the bag empty	
	void emptyBag() override {
		items = 0;
	}
	
	//the += adds items to the bag
	bool operator+=(const E& addend) override
	{

		if (addItem(addend))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//the numItems function returns number of items in the bag
	int numItems() const override {
			return items;
		}
	//the bagCapacity function returns size of bag
	int bagCapacity() const override {
		return (maxSize);	
	}
private:
	E bag[15];//holds the bag elements
	int maxSize;//maximum size of bag
	int items;//number of items in the bag
};
