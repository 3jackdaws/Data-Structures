#pragma once

template <typename T>
class DynArray
{
	T * m_array;
	int m_length;
	int m_start_index;
public:
	DynArray();
	DynArray(int length, int start_index);
	DynArray(const DynArray & copy);

	~DynArray();

	DynArray<T> & operator = (const DynArray & rhs);
	T & operator [] (int index);
	int getStartIndex();
	void setStartIndex(int index);
	int getLength();
	void setLength(int len);
};

template <typename T>
DynArray<T>::DynArray() :m_array(nullptr), m_length(0), m_start_index(0)
{
	
}

template <typename T>
DynArray<T>::DynArray(int length, int start_index) : m_length(length), m_start_index(start_index)
{
	m_array = new T[length];
}

template <typename T>
DynArray<T>::DynArray(const DynArray<T> & cp)
{
	setLength(cp->m_length);
	setStartIndex(cp->m_start_index);
	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = cp[i+m_start_index];
	}
}

template <typename T>
DynArray<T>::~DynArray()
{
    if(m_length > 1)
        delete[] m_array;
    else
        delete m_array;
}

template <typename T>
DynArray<T> & DynArray<T>::operator = (const DynArray<T> & rhs)
{
	for (int i = 0; i < m_length; i++)
	{
		delete m_array[i];
	}
	this->m_length = rhs->m_length;
	this->m_start_index = rhs->m_start_index;
	this->m_array = rhs->m_array;
}

template <typename T>
T & DynArray<T>::operator [] (int index)
{
	if (index >= m_start_index + m_length || index < m_start_index)
	{
		throw "Oh noes";
	}
	return m_array[index - m_start_index];
}

template <typename T>
int DynArray<T>::getStartIndex()
{
	return m_start_index;
}

template <typename T>
void DynArray<T>::setStartIndex(int index)
{
	m_start_index = index;
}

template <typename T>
int DynArray<T>::getLength()
{
	return m_length;
}

template <typename T>
void DynArray<T>::setLength(int new_len)
{
    T * hold = new T[new_len];
    int i = 0;
    for (i = 0; i < m_length; i++)
    {
        hold[i] = m_array[i];
        
    }
    for (i = m_length; i<new_len; i++) {
        hold[i] = 0;
    }
    delete m_array;
    m_array = hold;
	m_length = new_len;
}

