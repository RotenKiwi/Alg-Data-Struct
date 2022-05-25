//Algorith for vector sorting in increasing order

#include <bits/stdc++.h>
using namespace std;
int main()
{
vector < int > v { 21, 98, 77, 5, 19, 49, 32, 1, 27, 94 } ;
sort (v.begin () , v.end () ) ;
cout << " Here is the Sorted array \n " ;
for ( auto i : v )
cout << i << " " ;
return 0;
}