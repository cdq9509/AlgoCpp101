/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
#include <cstddef> 
 
  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    void helper(ListNode* head, ListNode* l1, ListNode* l2, int carry) {
      int l =0,r = 0,s = 0, newCarry = 0;
      ListNode * l1Next = NULL, * l2Next = NULL; 
      if (l1 != NULL) { l =l1->val; l1Next = l1->next; }
      if (l2 != NULL) { r = l2->val; l2Next = l2->next;}
      s= l + r + carry;
      if (s>9) {newCarry = 1; s= s - 10;}; 
      
      head->val = s; 
      
      if ( (l1Next!= NULL) || (l2Next != NULL) || newCarry > 0 ) {
        ListNode* newHead = new ListNode(0);
        head->next = newHead; 
        helper(newHead, l1Next, l2Next, newCarry);
      }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
      ListNode * head = new ListNode(0);       
      helper( head, l1, l2, 0 );
      return head;     
    }  
};

int main(void)
{
  Solution sol;
  return 0;
}