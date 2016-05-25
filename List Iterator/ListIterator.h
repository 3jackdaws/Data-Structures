//
//  ListIterator.h
//  List Iterator
//
//  Created by Ian Murphy on 2/19/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#ifndef ListIterator_h
#define ListIterator_h
#include "AbstractIterator.hpp"
#include "LinkedList.hpp"

template <typename T>
class ListIterator : public AbstractIterator<T>
{
public:
    ListIterator(DoubleLinkedList<T> & list);
    ListIterator(const ListIterator & cp);
    virtual ~ListIterator();
    ListIterator<T> & operator = (const ListIterator & rhs);
    virtual void MoveNext() = 0;
    virtual void Reset() = 0;
    virtual bool IsDone();
    virtual T& GetCurrent();
protected:
    LLNode<T> * _current_element;
    DoubleLinkedList<T> & _list;
};

template <typename T>
ListIterator<T>::ListIterator(DoubleLinkedList<T> & list) : _list(list), _current_element(nullptr)
{
    
}

template <typename T>
ListIterator<T>::ListIterator(const ListIterator<T> & cp) : _list(cp._list), _current_element(cp._current_element)
{
    
}

template <typename T>
ListIterator<T> & ListIterator<T>::operator = (const ListIterator<T> & rhs)
{
    if(this != &rhs)
    {
        _list = rhs._list;
        _current_element = rhs._current_element;
    }
    return *this;
}

template <typename T>
ListIterator<T>::~ListIterator()
{
    _current_element = nullptr;
}

template <typename T>
bool ListIterator<T>::IsDone()
{
    if(!_current_element)
    {
        return true;
    }
    return false;
}

template <typename T>
T & ListIterator<T>::GetCurrent()
{
    if(!IsDone())
        return _current_element->GetData();
    T rval;
    return rval;
}
#endif /* ListIterator_h */
