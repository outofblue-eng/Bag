#pragma once
#include "ABag.h"
#include "dictionaryADT.h"
#include "kvpair.h"

template <typename Key, typename E>
class BDictionary : public Dictionary<Key, E> {
public:
	//constructor
	BDictionary(int size = defaultSize) {
		dict = new ABag<KVpair<Key, E>>(size);
	}          

	~BDictionary() {} // Base destructor

	//empty out the dictionary
	void clear() override
	{
		dict->emptyBag();
	}

	//insert a record where k is the key and e is the value
	// if successful, return true, else, return false
	bool insert(const Key& k, const E& e) override
	{
		KVpair<Key, E> KeyVal(k, e);
		if (dict->addItem(KeyVal))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//removes a record where k is the key and e is the value
	// updates rtnVal with new value
	//if successful, return true, else return false
	bool remove(const Key& k, E& rtnVal) override
	{
		KVpair<Key, E> KeyVal(k, rtnVal);
		if (dict->remove(KeyVal)) {
			rtnVal = KeyVal.value();
			return true;
		}
		else
		{
			return false;
		}
	}

	//takes any record and changes returnValue to that.
	//if successful, return true, else return false
	bool removeAny(E& returnValue) override
	{
		KVpair<Key, E> KeyVal;
		if (dict->removeTop(KeyVal)) {
			returnValue = KeyVal.value();
			return true;
		}
		else
		{
			return false;
		}
	}

	//finds a record where k is the key and e is the value
	//if successful, return true, else return false
	bool find(const Key& k, E& returnValue) const override
	{
		KVpair<Key, E>KeyVal(k, returnValue);
		if (dict->find(KeyVal)) {
			returnValue = KeyVal.value();
			return true;
		}
		else
		{
			return false;
		}
	}

	//returns size
	int size() const override
	{
		return dict->numItems();
	}
private:
	ABag<KVpair<Key, E>>* dict;
};

