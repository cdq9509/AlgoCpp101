/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True

Example 2:

Input: 14
Returns: False
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
		if (num == 1 || num == 0) return true; 
		
        for (int i = 0; i <= num/2; i++){
			int ss = i * i; 
			if ( ss == num ) return true;
			else if ( ss > num ) return false;  
		}
		return false; 
    }
};