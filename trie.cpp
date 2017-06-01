/* Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z. 
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
#define SZ ( 'z' - 'a' + 1 )
#if 0     
// This works
    class Node {
      public:
      class Node * children[SZ];
      string path; 
      
      // I made a mistake here: memset is w.r.t to bytes.
      Node() { memset(children, 0,sizeof(children)); }
    };
#endif
// The below also compiles
    typedef struct Node_s {
      struct Node_s * children[SZ];
      string path; 
      
      // I made a mistake here: memset is w.r.t to bytes.
      Node_s() { memset(children, 0,sizeof(children)); }
    } Node;
    
    Node * root; 
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * r = root; 
        for (int i = 0; i < word.size(); ++i) {
          char c = word.at(i);
          int pathIdx = c - 'a';
          if ( r->children[pathIdx] == NULL ) {
            r->children[pathIdx] = new Node();
          }
          r = r->children[pathIdx];
        }
        r->path = word; 
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * r = root;
        for (int i = 0; i < word.size(); ++i) {
          char c = word.at(i);
          int pathIdx = c - 'a';
          if (  r->children[pathIdx] == NULL ) return false;
          r = r->children[pathIdx]; 
        }
        if (r->path != word) return false;
        else return true; 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      Node * r = root;
      for (int i = 0; i < prefix.size(); ++i) {
        int pathIdx = prefix.at(i) - 'a';
        if ( r->children[pathIdx] == NULL ) return false;
        r = r->children[pathIdx];
      }
      if (r != NULL) return true;
      else return false; 
    }
};

int main(void)
{
  Trie trie;
  return 0;
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */