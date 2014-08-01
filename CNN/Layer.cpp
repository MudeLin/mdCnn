//
//  Layer.cpp
//  CNN
//
//  Created by Eric on 8/1/14.
//  Copyright (c) 2014 cv. All rights reserved.
//

#include "Layer.h"

Layer::Layer(const int feat_mNum,const Mat *feature_map, const int kernelNum, const Mat *kernels){
    this->feat_mapNum = feat_mNum;
    this->kernelNum = kernelNum;
    feature_map = new Mat[feat_mNum];
    
    kernels     = new Mat[kernelNum];
    for (int i = 0; i < this->feat_mapNum; i ++) {
        *(this->feature_map + i) = *(feature_map + i);
    }
    for (int i = 0; i < this->kernelNum; i ++) {
        *(this->kernels + i) = *(kernels + i);
    }
}

Layer::Layer(const int feat_mNum,const Size &feature_map_size, const int kernelNum, const Size &kernels_size){
    
}
