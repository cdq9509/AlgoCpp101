#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <utility> // for pair

using namespace std;

/*  OK: turns out it is not easy to sort map by value.
        
        1. it is sorted by key by default?
        
        2. I cannot really use sort 
        sort( roman.begin(), roman.end(), myCmp ) ; 
        b/c the compiler cannot resolve the type. The first/two argument are 
        itertoar type, but the comparator cannot? actually I can

    static bool myCmp( map<char, int>::iterator left, map<char, int>::iterator right ) 
    {
        return (left->second) < (right->second); 
    }
*/
class Solution {
public:
    void initRomanMap( map<char, int> & roman,  map<int, char> & roman2) 
    {
        roman['M'] = 1000;
        roman['D'] = 500;
        roman['C'] = 100;
        roman['L'] = 50;
        roman['X'] = 10;
        roman['V'] = 5;
        roman['I'] = 1;

        cout << roman.size() << endl;
        cout << roman2.size() << endl;

        map<char,int>::iterator rit; 
        for (rit = roman.begin(); rit != roman.end(); rit++ ) {
            cout << rit->first << "," << rit->second << endl; 
            roman2[rit->second] = rit->first; 
        }

        cout << roman.size() << endl;
        cout << roman2.size() << endl;
        
        cout << "####" << endl; 
        map<int,char>::iterator rit2; 
        for (rit2 = roman2.begin(); rit2 != roman2.end(); rit2++ ) {
            cout << rit2->first << "," << rit2->second << "*" << endl; 
        }
        return;         
    }
    
    //template< class T1, class T2> 

/*        map<char, int> roman; 
        map<int, char> roman2; 
        initRomanMap( roman, roman2 ); 
*/
        // Print out the map 
        // Note1: cannot use < roman.end(); must use !=. Perhaps no overload for it. 
        // Note2: cannot directly use cout << roman
        // Note3: first and second from iterator
        
        // Note4: 
        // c++ invalid use of non-static member function
        // A member function implicitly takes this as the first parameter.
        // cannot use sort: sort( roman.begin(), roman.end(), myCmp ) ; 
    
    string intToRoman(int num) {
        vector< pair<int, string> > roman; 
        roman.push_back( make_pair( 1000,  "M") ); 
        roman.push_back( make_pair( 900,  "CM") ); 
        roman.push_back( make_pair( 500,  "D") );
        roman.push_back( make_pair( 400,  "CD") );
        roman.push_back( make_pair( 100,  "C") );
        roman.push_back( make_pair( 90,  "XC") );
        roman.push_back( make_pair( 50,  "L") );
        roman.push_back( make_pair( 40,  "XL") );        
        roman.push_back( make_pair( 10,  "X") );
        roman.push_back( make_pair( 9,  "IX") );
        roman.push_back( make_pair( 5,  "V") );
        roman.push_back( make_pair( 4,  "IV") );
        roman.push_back( make_pair( 1,  "I") ) ;

        string res; 
        
        vector< pair<int, string> >::iterator rit; 
        rit = roman.begin(); 
        while ( num && rit != roman.end() ) {
            if ( num >= rit->first ) {
                res.append( rit->second ); 
                num -= rit->first; 
            } else {
                rit++; 
            }
        }
        
        return  res; 
    }
};


int main(void) 
{
    Solution sol; 
    int x;

    x = 100; 
    cout << x << ", " << sol.intToRoman( x ) << endl; 

    x = 151; 
    cout << x << ", " << sol.intToRoman( x ) << endl; 
    
    x = 4; // expect    "IV"
    cout << x << ", " << sol.intToRoman( x ) << endl; 
    
    
    return 0 ; 
}