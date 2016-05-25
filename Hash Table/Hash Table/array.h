//
//  array.hpp
//  Hash Table
//
//  Created by Ian Murphy on 3/9/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#ifndef array_hpp
#define array_hpp

#define LARGE_BLOCK 4096
#define MEDIUM_BLOCK 1024
#define SMALL_BLOCK 256

#include <string>
using std::string;
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <functional>


template <typename V>
class assoc_array
{
    
    struct pair
    {
        string key;
        V value;
    };
public:
    assoc_array(unsigned int block_size = MEDIUM_BLOCK);
    assoc_array(const assoc_array & cp);
    ~assoc_array();
    assoc_array & operator = (const assoc_array & rhs);
    
    V & operator [] (string key);
    assoc_array & operator [] (assoc_array & rhs);
    assoc_array & operator = (assoc_array & rhs);
    bool add(string key, V value);
    bool remove(string key);
    unsigned int count();
    

    void DebugListCollisions();
private:
    void _resize();
    int _check_size();
    //unsigned int hash(K key);
    
    std::vector<std::list<pair>> m_table;
    int _reallocate_block_size;
    int m_size;
    int m_capacity;
};

template < typename V>
assoc_array<V>::assoc_array(unsigned int block_size) : m_size(0), m_capacity(block_size), _reallocate_block_size(block_size)
{
    std::list<pair> default_list;
    m_table.assign(m_capacity, default_list);
}

template < typename V>
assoc_array<V>::assoc_array(const assoc_array<V> & cp) : m_size(cp.m_size), m_table(cp.m_table), m_capacity(cp.m_capacity)
{
    
}

template < typename V>
assoc_array<V>::~assoc_array()
{
    m_size = 0;
    m_capacity = 0;
}

template < typename V>
assoc_array< V> & assoc_array<V>::operator=(const assoc_array< V> &rhs)
{
    if(this != &rhs)
    {
        m_size = rhs.m_size;
        m_table = rhs.m_table;
        m_capacity = rhs.m_capacity;
    }
    return *this;
}

template < typename V>
V & assoc_array<V>::operator[](string key)
{
    V * value = nullptr;
    int index = std::hash<string>{}(key)%m_capacity;
    for(pair & element : m_table[index])
    {
        if(element.key == key)
        {
            value = &element.value;
        }
    }
    return *value;
}

template < typename V>
bool assoc_array<V>::remove(string key)
{
    typename std::list<pair>::iterator iter, indexof;
    std::list<typename std::list<pair>::iterator> remove_list;

    int index = std::hash<string>{}(key)%m_capacity;
    for(iter = m_table[index].begin(); iter != m_table[index].end(); iter++)
    {
        if( iter->key == key )
        {
            remove_list.push_back(iter);
        }
    }
    for(typename std::list<pair>::iterator rm : remove_list)
    {
        m_table[index].erase(rm);
        m_size--;
        if(m_size < m_capacity-_reallocate_block_size)
        {
            m_capacity -= _reallocate_block_size;
            _resize();
        }
    }
    return true;
}


template < typename V>
bool assoc_array<V>::add(string key, V value)
{
    m_table[std::hash<string>{}(key.c_str())%m_capacity].push_front(pair{key, value});
    m_size++;
    if(m_size >= m_capacity)
    {
        if(m_size > m_capacity + _reallocate_block_size)
        {
            m_capacity+=_reallocate_block_size;
            _resize();
        }
        
    }
    return true;
}


template < typename V>
void assoc_array<V>::_resize()
{
    std::vector<std::list<pair>> old_vector(m_table);
    m_table.clear();
    m_table.resize(m_capacity);
    m_size = 0;
    for(std::list<pair> & old_list : old_vector)
    {
        for(pair & old_pair : old_list)
        {
            add(old_pair.key, old_pair.value);
        }
    }
}

template <typename V>
void assoc_array<V>::DebugListCollisions()
{
    int i = 0;
    for(std::list<pair> list : m_table)
    {
        cout<<"Index " <<i<<", Size: " << list.size()<<endl;
        i++;
    }
}

template <typename V>
unsigned int assoc_array<V>::count()
{
    return m_size;
}

#endif /* assoc_array_hpp */
