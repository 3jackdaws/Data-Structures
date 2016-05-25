//
//  ForwardIterator.h
//  List Iterator
//
//  Created by Ian Murphy on 2/19/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#ifndef ForwardIterator_h
#define ForwardIterator_h
#include "ListIterator.h"

template <typename T>
class ForwardIterator : public ListIterator<T>
{
public:
    ForwardIterator(DoubleLinkedList<T> & list);
    ForwardIterator(const ForwardIterator & cp);
    ForwardIterator & operator = (const ForwardIterator & rhs);
    ~ForwardIterator();
    void MoveNext();
    void Reset();
};

template <typename T>
ForwardIterator<T>::ForwardIterator(DoubleLinkedList<T> & list) : ListIterator<T>(list)
{
    
}

template <typename T>
ForwardIterator<T>::ForwardIterator(const ForwardIterator & cp) : ListIterator<T>(cp)
{
    
}

template <typename T>
ForwardIterator<T> & ForwardIterator<T>::operator = (const ForwardIterator & rhs)
{
    if(this != &rhs)
    {
        ListIterator<T>::_list = rhs.ListIterator<T>::_list;
        ListIterator<T>::_current_element = rhs.ListIterator<T>::_current_element;
    }
    return *this;
}

template <typename T>
ForwardIterator<T>::~ForwardIterator()
{
    
}

template <typename T>
void ForwardIterator<T>::MoveNext()
{
    if(!ListIterator<T>::IsDone())
    {
        ListIterator<T>::_current_element = ListIterator<T>::_current_element->GetNext();
    }
}

template <typename T>
void ForwardIterator<T>::Reset()
{
    ListIterator<T>::_current_element = ListIterator<T>::_list.getHead();
}


#endif /* ForwardIterator_h */
