#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
  private:
    enum state_e {
      INIT,
      PROCESS,
      DONE
    };
    bool checkOverflow(long long num, bool is_pos) 
    {
      if (is_pos && num >= INT_MAX) return true;
      else if (!is_pos && num >= ((long long)(-1))*(INT_MIN)) return true; 
      else return false; 
    }
  public:
    int myAtoi(string str) {
      long long num = 0; 
      enum state_e state = INIT;
      bool is_pos = true; 
      bool is_overflow = false; 

      for (int i = 0; i < str.size(); ++i) {
        char c = str.at(i);
        //cout << "state = " << (int)state << endl;

        if (state == INIT) {
          if (c == ' ') { continue;}

          bool is_bad = false;
          if (c == '+') { is_pos = true; }
          else if ( c == '-') { is_pos = false; }
          else if ( c >= '0' && c <= '9') { num = c - '0'; }
          else { is_bad = true; }

          if (is_bad) { state = DONE;}
          else {state = PROCESS;}          
        }
        else if (state == PROCESS) {
          if ( c >= '0' && c <= '9') {
            num = (num *10) + ( c - '0'); 
            is_overflow = checkOverflow(num, is_pos);
            if (is_overflow) {
              if (is_pos)  num = INT_MAX;
              else num = ((long long)(-1))*INT_MIN;
            }
          } else {
            state = DONE;
          }
        } // end of state machine

        if ( state == DONE ) { break; }
      }

      if (is_pos) return num;
      if (!is_pos) return -1*num;
    }// end of func
};


int main(void){
  int num;
  Solution sol;

  string str = " b11228552307";  
  num = sol.myAtoi(str);
  cout << num << endl;

  str = "123";
  num = sol.myAtoi(str);
  cout << num << endl;

  str = "+-2";
  num = sol.myAtoi(str);
  cout << num << endl;

  str = "9223372036854775809";
  num = sol.myAtoi(str);
  cout << num << endl;

  str = "      -11919730356x";
  num = sol.myAtoi(str);
  cout << num << endl;  
  
  str = "9223372036854775809";
  num = sol.myAtoi(str);
  cout << num << endl;    
}
