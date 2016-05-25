//
//  AbstractIterator.hpp
//  List Iterator
//
//  Created by Ian Murphy on 2/19/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#ifndef AbstractIterator_hpp
#define AbstractIterator_hpp

#include <stdio.h>

template <typename T>
class AbstractIterator
{
public:
    virtual void MoveNext() = 0;
    virtual void Reset() = 0;
    virtual bool IsDone() = 0;
    virtual T& GetCurrent() = 0;
    
private:
    
};

#endif /* AbstractIterator_hpp */
