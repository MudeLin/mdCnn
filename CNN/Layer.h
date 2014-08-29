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
#include "Kernel.h"

enum LayerType {
    
    InputLayer,
    ConvolLayer,
    PoolingLayer,
    SoftMaxLayer,
    FullLayer
};

class Layer {
public:
    Mat *feature_maps;
    Kernel *kernels;
    
    int kernelNum;
    
    int feat_mapNum;
    LayerType type = LayerType::ConvolLayer;
    
    Layer(){
        kernelNum = 0;
        feat_mapNum = 0;
        feature_maps = new Mat[1];
        kernels = new Kernel[1];
    }
    
    Layer(const int kernelNum, const Kernel *kernels);
    //Layer(const int feat_mNum,const Size *feature_map_sizes, const int kernelNum, const Size *kernels_sizes);
    Layer(const Layer &rhs);
    Layer& operator = (const Layer &rhs);
    
    void calCulateFeatureMap(const Layer *lhs);
    
    void calCulateDeltaMap(const Layer *rhs, const Mat *rdeltaMap, Mat *resultDeltaMap);
    
    void updateKernels(const Layer *lhs, const Mat* rdeltaMap, const float alpha);
    
    void setFeatureMap(const Mat *feature_ms,const int _feature_mapNum);
    
    inline void setType(LayerType type){
        this->type = type;
    }
    
    
    ~Layer(){
        delete [] feature_maps;
        delete [] kernels;
    }
};

static void testLayer(){
    Layer l = Layer();
    std::cout << l.kernelNum << std::endl;
    
}

#endif /* defined(__CNN__Layer__) */
