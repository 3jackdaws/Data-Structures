#include "DynArray.h"
#include <iostream>
using std::cout;
using std::endl;


int main()
{
	DynArray<int> ar(10, 5);
    for (int i = 5; i<15; i++) {
        ar[i] = i;
    }
    for (int i = 5; i<15; i++) {
        cout<<ar[i]<<endl;
    }
    cout<<"Setting new length"<<endl;
    ar.setLength(5);
    
    for (int i = 5; i<10; i++) {
        cout<<ar[i]<<endl;
    }
    ar.setLength(10);
     cout<<"Setting new length 10"<<endl;
    
    for (int i = 5; i<15; i++) {
        cout<<ar[i]<<endl;
    }
	return 0;
}