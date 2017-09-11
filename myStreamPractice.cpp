#include <iostream>

using namespace std;

class myData {
  private: 
    int re, img;
  public:
    myData(int _re = -1, int _img = -2) {re = _re; img = _img;}
    friend ostream& operator << (ostream& out, const myData& dat);    
};

// because it is friend. so should be global.
ostream & operator << (ostream& out, const myData& dat) {
  out << "(" << dat.re << ", " << dat.img << ")";
  return out;
}

int main(void)
{
  myData dat;
  cout << "default" << dat << endl;
  
  myData dat2(2,4);
  cout << "nondefault" << dat2 << endl;
  return 0;
}