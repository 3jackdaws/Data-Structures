//
//  main.cpp
//  List Iterator
//
//  Created by Ian Murphy on 2/19/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;
#include "LinkedList.hpp"
#include "ForwardIterator.h"
#include "BackwardIterator.h"
//#include "BackwardIterator.h"

int main(int argc, const char * argv[]) {
    DoubleLinkedList<int> myList;
    
    ForwardIterator<int> fiter(myList);
    for (int i = 0; i<20; i++)
    {
        myList.Append(i);
    }
    myList.Extract(10);
    fiter.GetCurrent();
    for (fiter.Reset(); !fiter.IsDone(); fiter.MoveNext())
    {
        cout<<fiter.GetCurrent()<<endl;
    }
    cout<<endl;
    BackwardIterator<int> backward_iter(myList);
    for (backward_iter.Reset(); !backward_iter.IsDone(); backward_iter.MoveNext())
    {
        cout<<backward_iter.GetCurrent()<<endl;
    }
    cout<<"Testing edge cases"<<endl;
    backward_iter.Reset();
    cout<<backward_iter.GetCurrent()<<endl;
    myList.Extract(19);
    //myList.PrintForwards();
    cout<<backward_iter.GetCurrent()<<endl;
    
    myList.Purge();
    
    
    ForwardIterator<int> iter2(fiter);
    BackwardIterator<int> iter3(backward_iter);
    backward_iter = iter3;
    iter2.Reset();
    fiter = iter2;
    iter3.MoveNext();
    iter3 = backward_iter;
    
    return 0;
}
