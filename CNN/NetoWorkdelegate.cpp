//
//  NetoWorkdelegate.cpp
//  CNN
//
//  Created by Eric on 8/6/14.
//  Copyright (c) 2014 cv. All rights reserved.
//

#include "NetoWorkdelegate.h"

void NetWorkDelegate::checkGradient(){
    
}

void NetWorkDelegate::forward(){
    
    for (int i = 1; i < layerCount; i++) {
        (this->layers + i)->calCulateFeatureMap(this->layers + i -1);
    }
}

void NetWorkDelegate::backward(){
    Mat *resultMat = new Mat[1];
    Mat *r_deltaMat = new Mat[1];
    
    // TODO: calculate output layer delta map
    
    for (int i = layerCount -1; i > 1; i --) {
        
        (this->layers + i)->calCulateDeltaMap(NULL, r_deltaMat, resultMat);
        
        (this->layers + i)->updateKernels(this->layers + i - 1, r_deltaMat, this->alpha);
        
        delete [] r_deltaMat;
        
        r_deltaMat = resultMat;
    }
}

void NetWorkDelegate::train(){
    for (int i = 0; i < this-> rounds; i ++) {
        for (int j = 0; j < this->batchSize; j++) {
            forward();
            backward();
        }
    }
}

void NetWorkDelegate::test(){
    
}

