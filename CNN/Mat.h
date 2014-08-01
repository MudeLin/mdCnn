//
//  Mat.h
//  CNN
//
//  Created by Eric on 8/1/14.
//  Copyright (c) 2014 cv. All rights reserved.
//

#ifndef __CNN__Mat__
#define __CNN__Mat__

#include <iostream>
#include "Size.h"

typedef float Datatype;
class Mat{
public:
    Size size;
    Datatype *data;
    int totalCount;
    Mat(){
        size = Size();
        data = new Datatype[1];
        totalCount = 0;
    }
    Mat(const Size &size);
    Mat(const Mat &mat);
    Mat& operator = (const Mat &mat);
    ~Mat(){
        delete [] data;
        std::cout << "Mat destructed" <<std::endl;
    }
    static void testMat();
    inline int getSize(const int atDim) const {
        assert(atDim < this->size.dim);
        return *(this->size.sizes + atDim);
    }
    void randomInitialized();
};
#endif /* defined(__CNN__Mat__) */
