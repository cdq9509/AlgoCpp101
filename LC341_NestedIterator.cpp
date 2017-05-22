/********************************************************************************/
/* VERSION 1: already 2.5 hours and did not get it right                        */
/********************************************************************************/
// In addition to checking boundary condition, 
// my biggest chanllene turns out to be 
// advancing next iterator, b/c if the next element
// is an empty list, then nit->hasNext has a tough time:
// if returning empty, then we think the iteration is done;
// if returning not empty, then next operation will be call, but there is nothing to be returned.
// 
// advancing it needs to skip through empty list: now empty list can have empty list, so, need to 
// do recursive.
// Online using stack. I can argue mine is better for large amount of data. 
// 
class NestedIterator {
private:
    vector<NestedInteger>::iterator it;
    vector<NestedInteger>::iterator end;
    
    // Note that I have to use pointer here.
    // NestedIterator nit does NOT compile b/c it lack complete definition. 
    NestedIterator * nit; 
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        it = nestedList.begin(); 
        end = nestedList.end(); 
        if ( it != end && !it->isInteger() ) {
             nit = new NestedIterator(it->getList()); 
        }
        cout << "init again?";

    }
    int next() {
        int ret; 
        if ( it->isInteger() ) {
            ret = it->getInteger(); 
            it++;
            if ( it != end && !it->isInteger() ) {
                nit = new NestedIterator(it->getList());
            }
        } else {
            ret = nit->next(); 
        }
        cout << "val =" << ret << ";"; 
        return ret; 
    }

    bool hasNext() {
        bool ret;
        
        // This should be obvious, but it takes me 2 hours to realize
        // that I need to handle it here. 
        if ( it == end ) return false;
        
        if ( !it->isInteger() ) {
            if ( nit->hasNext() ) ret = true;
            else { 
                it++; 
                if (it == end ) ret = false;
                else {
                    if ( !it->isInteger() ) {
                        nit = new NestedIterator(it->getList());
                    }
                    ret = true; 
                }
            }
        }
        cout << "has next " << ret << ";"; 
        return ret; 
    }
};



/********************************************************************************/
/* VERSION 2: 7:07 am 03/03/2017  -- 7:52 am: compile and pass runcode; also submit and get accepted                     */
/********************************************************************************/
// HMM: runtime seems to be slow: 365ms. Avg is 20 ms. 
class NestedIterator {
private:
    vector<NestedInteger>::iterator it;
    vector<NestedInteger>::iterator end;
    
    // Note that I have to use pointer here.
    // NestedIterator nit does NOT compile b/c it lack complete definition. 
    NestedIterator * nit; 
    
    // Advanced it (only at current level)
    // return false if we are at the end
    bool advIt() {
        bool ret = true; 
        if (nit != NULL) { delete nit; nit = NULL; }
        if (it == end) { ret = false; return ret; }
        ++it;
        if ( it != end && !it->isInteger()) {
            nit = new NestedIterator(it->getList());
        }
        return (it != end); 
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        it = nestedList.begin(); 
        end = nestedList.end();
        nit = NULL;
        if ( it != end && !it->isInteger() ) {
             nit = new NestedIterator(it->getList()); 
        } 
        cout << "constructor called;";

    }
    ~NestedIterator() {
        cout << "destructor called;"; 
    }
    int next() {
        int ret; 
        if ( it->isInteger() ) {
            ret = it->getInteger(); 
            advIt(); 
        } else {
            ret = nit->next(); 
        }
        cout << "val =" << ret << ";"; 
        return ret; 
    }

    bool hasNext() {
        bool ret;
        // emtpy list, begin = end
        if ( it == end ) return false;
        
        if ( it->isInteger() ) ret = true;
        else {
            ret = true; 
            if ( !nit->hasNext() ) {
                if ( ! advIt() ) { ret = false; }
                else { ret = hasNext(); }
            }
        }
        cout << "hasNext " << ret << ";"; 
        return ret; 
    }
};
