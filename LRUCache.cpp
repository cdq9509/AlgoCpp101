#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:

        list<std::pair<int, int> >  priorityList;
        unordered_map<int, list< std::pair<int,int> >::iterator> pageTable;
        int mSize;
public:
    LRUCache(int capacity) {
        mSize = capacity;

    }
    
    int get(int key) {
        unordered_map<int, list< std::pair<int,int> >::iterator>::iterator it; 
        it = pageTable.find(key);
        if (  it == pageTable.end() ) return -1;
        
        int value = it->second->second;
        
        priorityList.erase(it->second);
        priorityList.push_front(std::make_pair(key,value));
        it->second = priorityList.begin(); 
        
        return value; 
    }
    
    void put(int key, int value) {
        unordered_map<int, list< std::pair<int,int> >::iterator>::iterator it; 
        it = pageTable.find(key);
        if (get(key) != -1 )  // use get() to bump it to head
        { it->second->second=value; return;}
        
        if ( priorityList.size() >= (unsigned int) mSize) {
            
            int old_key = priorityList.back().first;
            
            pageTable.erase( pageTable.find(old_key) );
            
            priorityList.pop_back();
            
            priorityList.push_front( std::make_pair(key, value) );
            
            pageTable.insert( std::make_pair(key, priorityList.begin()) ); 
            
        } else {
            priorityList.push_front(std::make_pair(key,value));
            pageTable.insert(std::make_pair(key,priorityList.begin()));
        }
        
    }
};

int main(void)
{
    LRUCache cache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
    return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */