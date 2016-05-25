//
//  LLNode.hpp
//  DoubleLL
//
//  Created by Ian Murphy on 1/6/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#ifndef LLNode_hpp
#define LLNode_hpp

#include <stdio.h>

template <typename T> class DoubleLinkedList; //forward declare

template <typename T>
class LLNode{
public:
    friend class DoubleLinkedList<T>;     //friend class when types match
    

    
    
    
    LLNode(T);
    LLNode(const LLNode<T> &);
    ~LLNode();
    LLNode<T> & operator = (const LLNode<T> &);
    
    T & GetData();
    void SetData(T);
    LLNode<T> * GetNext();
    LLNode<T> * GetPrev();
    void SetNext(LLNode *);
    void SetPrev(LLNode *);
private:
    LLNode<T> * _next;
    LLNode<T> * _prev;
    T _data;
};

template <typename T>
LLNode<T>::LLNode(T data) : _next(nullptr), _prev(nullptr)
{
    _data = data;       
}

template <typename T>
LLNode<T>::LLNode(const LLNode<T> & cp) : _next(nullptr), _prev(nullptr)
{
    _data = cp._data;
}

template <typename T>
LLNode<T>::~LLNode()
{
    _next = nullptr;
    _prev = nullptr;
}

template <typename T>
LLNode<T> & LLNode<T>::operator = (const LLNode<T> & rhs)
{
    //I can't think of a time this would ever be used.
    _data = rhs._data;
    _next = nullptr;
    _prev = nullptr;
}

template <typename T>
LLNode<T> * LLNode<T>::GetNext()
{
    return _next;
}

template <typename T>
LLNode<T> * LLNode<T>::GetPrev()
{
    return _prev;
}

template <typename T>
T & LLNode<T>::GetData()
{
    return _data;
}

template <typename T>
void LLNode<T>::SetData(T data)
{
    _data = data;
}


#endif /* LLNode_hpp */
