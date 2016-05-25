//
//  main.cpp
//  Hash Table
//
//  Created by Ian Murphy on 3/9/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
#include "array.h"
#include <string>
using std::string;

#include <chrono>


typedef struct Book
{
    string m_title;
    string m_author;
    int m_pages;
} Book;

void read_words(std::vector<string> & list)
{
    std::ifstream fin("20k.txt");
    string buffer;
    for (int i = 0; i<10000; i++)
    {
        std::getline(fin, buffer);
        list.push_back(buffer);
    }
}

int main(int argc, const char * argv[])
{
    assoc_array<string> userids(LARGE_BLOCK);
    std::vector<string> words;
    read_words(words);
    auto begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i<10000; i++)
    {
        userids.add(words[i], words[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count();
    //userids.DebugListCollisions();
    cout<<"Time to insert 10,000 elements: "<<duration<<endl;
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i<10000; i++)
    {
        if(userids[words[i]] != words[i])
        {
            cout<<"error"<<endl;
        }
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();
    cout<<"Time to access 10,000 elements: "<<duration<<endl;
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i<10000; i++)
    {
        userids.remove(words[i]);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count();
    cout<<"Time to delete 10,000 elements: "<<duration<<endl;
    cout<<"Current size: "<< userids.count()<<endl;
    return 0;
}
