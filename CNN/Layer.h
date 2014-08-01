//
//  Layer.h
//  CNN
//
//  Created by Eric on 8/1/14.
//  Copyright (c) 2014 cv. All rights reserved.
//

#ifndef __CNN__Layer__
#define __CNN__Layer__

#include <iostream>
#include "Mat.h"

class Layer {
public:
    Mat *feature_map;
    Mat *kernels;
    int kernelNum;
    int feat_mapNum;
    Layer(){
        kernelNum = 0;
        feat_mapNum = 0;
        feature_map = new Mat();
        kernels = new Mat();
        
    }
    Layer(const int feat_mNum,const Mat *feature_map, const int kernelNum, const Mat *kernels);
    //Layer(const int feat_mNum,const Size *feature_map_sizes, const int kernelNum, const Size *kernels_sizes);
    
    Layer(const int feat_mNum,const Size &feature_map_size, const int kernelNum, const Size &kernels_size);
    
    ~Layer(){
        delete feature_map;
        delete kernels;
    }
};
#endif /* defined(__CNN__Layer__) */
