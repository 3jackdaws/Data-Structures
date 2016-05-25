//
//  BackwardIterator.h
//  List Iterator
//
//  Created by Ian Murphy on 2/23/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#ifndef BackwardIterator_h
#define BackwardIterator_h

template <typename T>
class BackwardIterator : public ListIterator<T>
{
public:
    BackwardIterator(DoubleLinkedList<T> & list);
    BackwardIterator(const BackwardIterator & cp);
    BackwardIterator & operator = (const BackwardIterator & rhs);
    ~BackwardIterator();
    void MoveNext();
    void Reset();
};


template <typename T>
BackwardIterator<T>::BackwardIterator(DoubleLinkedList<T> & list) : ListIterator<T>(list)
{
    
}

template <typename T>
BackwardIterator<T>::BackwardIterator(const BackwardIterator & cp) : ListIterator<T>(cp){
    
}

template <typename T>
BackwardIterator<T> & BackwardIterator<T>::operator = (const BackwardIterator & rhs)
{
    if(this != &rhs)
    {
        ListIterator<T>::_list = rhs.ListIterator<T>::_list;
        ListIterator<T>::_current_element = rhs.ListIterator<T>::_current_element;
    }
    return *this;
}



template <typename T>
BackwardIterator<T>::~BackwardIterator()
{
    
}

template <typename T>
void BackwardIterator<T>::MoveNext()
{
    if(!ListIterator<T>::IsDone())
    {
        ListIterator<T>::_current_element = ListIterator<T>::_current_element->GetPrev();
    }
}

template <typename T>
void BackwardIterator<T>::Reset()
{
    ListIterator<T>::_current_element = ListIterator<T>::_list.getTail();
}

#endif /* BackwardIterator_h */
