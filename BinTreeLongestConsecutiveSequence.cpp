/*
Given a binary tree, find the length of the longest consecutive sequence path.

 

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,

   1
    \
     3
    / \
   2   4
        \
         5

Longest consecutive sequence path is 3-4-5, so return 3.

   2
    \
     3
    / 
   2    
  / 
 1

Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
*/

// my thought: do a DFS, record the path along the way, convert this path to an array, find the longest increase sequence on this, which is not diffcult. 
// I may not need to record the entire path, just a couple 