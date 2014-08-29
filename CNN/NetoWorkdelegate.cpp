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


void NetWorkDelegate::forward(const Mat *inputmat,const int index){
    //initialize the input layer's data
    Mat *feat = inputmat->getMatAt(index);
    (this->layers )->setFeatureMap(feat, 1);
    
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
    Util util = Util();
    Mat *inputDataMat = new Mat();
    int inputdim[] = {42010,29,28};
    inputDataMat->setSize(Size(3,inputdim));
    util.loadData("/Users/imac06/Downloads/train.csv", inputDataMat);
    util.saveData(inputDataMat, "/Users/imac06/Downloads/testWrite.csv");
    for (int index = 0;  index < this->totalTrainInstance; index += this->batchSize) {
        
        for (int i = 0; i < this-> rounds; i ++) {
            for (int j = 0; j < this->batchSize; j++) {
                forward(inputDataMat,index + j);
                //backward();
            }
        }
    }
}

void NetWorkDelegate::test(){
    
}

