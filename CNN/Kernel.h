//
//  Kernel.h
//  CNN
//
//  Created by Eric on 8/6/14.
//  Copyright (c) 2014 cv. All rights reserved.
//

#ifndef __CNN__Kernel__
#define __CNN__Kernel__

#include <iostream>
#include "Mat.h"

class Kernel : public Mat {
public:
    int kernelNum;
    int* connectivity;
    int conn_Num;
    Kernel();
    Kernel(const int kernelNum, const  int* connectivity,const int conn_Num);
    Kernel(const Kernel &rhs);
    Kernel& operator =(const Kernel &rhs);
    
    ~Kernel(){
        delete [] connectivity;
    }
};

#endif /* defined(__CNN__Kernel__) */
