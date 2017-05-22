/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome. 
*/
class Solution {
public:
    bool isPalindrome(string s) {
		
		if ( s.size() <= 1) return true; 
		
        int head = 0;
		int tail = s.size() - 1; 
		
		while ( tail >= head ) {
			char c0, c1; 
			
			if ( ( s.at(head) >= 'a' && s.at(head) <= 'z' ) ||  
			     ( s.at(head) >= '0' && s.at(head) <= '9' ) ) c0=s.at(head);
			else if (s.at(head) >= 'A' && s.at(head) <= 'Z') c0=s.at(head) - ('A'-'a');
			else { ++head; continue;}
			
			if ( ( s.at(tail) >= 'a' && s.at(tail) <= 'z' ) || 
			     ( s.at(tail) >= '0' && s.at(tail) <= '9' ) ) c1=s.at(tail);
			else if (s.at(tail) >= 'A' && s.at(tail) <= 'Z') c1=s.at(tail) - ('A'-'a');
			else { --tail; continue;}
			
			if ( c0 != c1 ) return false; 
			
			--tail;
			++head;
		}
		return true;
    }
};