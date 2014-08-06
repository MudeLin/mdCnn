//
//  NetoWorkdelegate.h
//  CNN
//
//  Created by Eric on 8/6/14.
//  Copyright (c) 2014 cv. All rights reserved.
//

#ifndef __CNN__NetoWorkdelegate__
#define __CNN__NetoWorkdelegate__

#include <iostream>
#include "Layer.h"

class NetWorkDelegate {
public:
    int layerCount;
    Layer *layers;
    float alpha = 0.01;
    float numda = 0.0001;
    int batchSize = 1;
    int rounds = 10;
    
    NetWorkDelegate() {
        this->layerCount = 0;
        this->layers = new Layer[1];
    }
    
    NetWorkDelegate(const int _layerCount, const Layer *layers);
    
    void forward();
    void backward();
    
    void train();
    void test();
    
    void checkGradient();
    
    inline void setBatchSize(int size){
        this->batchSize = size;
    }
    inline void setRounds(int _rounds){
        this->rounds = _rounds;
    }
};
#endif /* defined(__CNN__NetoWorkdelegate__) */
