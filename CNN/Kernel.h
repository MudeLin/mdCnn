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
    
    int* connectivity;
    // connectivities number
    int conn_Num;
    
    Kernel();
    Kernel( const  int* _connectivity,const int _conn_Num);
    Kernel( const  int* _connectivity,const int _conn_Num,const Size &size);
    Kernel(const Kernel &rhs);
    void setConnectivity(const int*_connectivity,const int _conn_Num);
    Kernel& operator =(const Kernel &rhs);
    void calculateFeatureMap(const Mat *pre_feat_maps,Mat *resultFeature_map,const int steps = 1);
    Datatype activationFunc(const Datatype &sum) const;
    
    static void testKernel();
    
    ~Kernel(){
        delete [] connectivity;
    }
};

#endif /* defined(__CNN__Kernel__) */
