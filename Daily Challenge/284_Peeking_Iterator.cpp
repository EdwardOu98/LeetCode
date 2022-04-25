#include <iterator>

using namespace std;

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    int _next;
    bool _hasNext;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    _hasNext = Iterator::hasNext();
        if(_hasNext) {
            _next = Iterator::next();
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return _next;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int t = _next;
        _hasNext = Iterator::hasNext();
        if(_hasNext) {
            _next = Iterator::next();
        }
        return t;
	}
	
	bool hasNext() const {
	    return _hasNext;
	}
};