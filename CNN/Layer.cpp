//
//  Layer.cpp
//  CNN
//
//  Created by Eric on 8/1/14.
//  Copyright (c) 2014 cv. All rights reserved.
//

#include "Layer.h"

Layer::Layer(const int kernelNum, const Kernel *_kernels){
    int feat_mNum = 0;
    this->kernelNum = kernelNum;
    kernels     = new Kernel[kernelNum];
    assert(_kernels != NULL);
    
    for (int i = 0; i < this->kernelNum; i ++) {
        *(this->kernels + i) = *(_kernels + i);
        feat_mNum += (this->kernels + i)->kernelNum;
    }
    
    this->feat_mapNum = feat_mNum;
    feature_maps = new Mat[feat_mNum];
}

Layer::Layer(const Layer & rhs){
    if (&rhs != this) {
        this->kernelNum = rhs.kernelNum;
        this->kernels = new Kernel[this->kernelNum];
        for (int i = 0; i < this->kernelNum; i++) {
            *(this->kernels + i) = *(rhs.kernels + i);
        }
        this->feat_mapNum = rhs.feat_mapNum;
        this->feature_maps = new Kernel[this->feat_mapNum];
        this->setFeatureMap(rhs.feature_maps, rhs.feat_mapNum);
    }
}

Layer& Layer::operator = (const Layer &rhs){
    if (&rhs != this) {
        this->kernelNum = rhs.kernelNum;
        delete [] this->kernels;
        this->kernels = new Kernel[this->kernelNum];
        for (int i = 0; i < this->kernelNum; i++) {
            *(this->kernels + i) = *(rhs.kernels + i);
        }
        this->feat_mapNum = rhs.feat_mapNum;
        delete [] this->feature_maps;
        this->feature_maps = new Kernel[this->feat_mapNum];
        this->setFeatureMap(rhs.feature_maps, rhs.feat_mapNum);
    }
    return *this;
}

void Layer::calCulateFeatureMap(const Layer *lhs){
    assert(lhs != NULL);
    Mat *l_f_maps = lhs->feature_maps;
    //TODO: FINISH CNN
}


void Layer::calCulateDeltaMap(const Layer *rhs, const Mat *rdeltaMap, Mat *resultDeltaMap){
    switch (this->type) {
        case ConvolLayer:
            //TODO:
            break;
            
        case PoolingLayer:
            //TODO:
            break;
        
        case FullLayer:
            //TODO:
            break;
            
        case SoftMaxLayer:
            break;
        
        default:
            printf("Error, Needn't caculate the deltamap for input layer");
            break;
    }
}


void Layer::setFeatureMap(const Mat *feature_maps,const int feature_mapNum){
    assert(feature_maps != NULL);
    assert(feature_mapNum == this->feat_mapNum);
    for (int i = 0; i < this->feat_mapNum; i++) {
        *(this->feature_maps + i) = *(feature_maps + i);
    }
}

void Layer::updateKernels(const Layer *lhs, const Mat *rdeltaMap,const float alpha){
    
}

void Layer::testLayer(){
    
}

