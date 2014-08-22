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
#include "NetWork.h"

class NetWorkDelegate: public NetWork {
private:
    float alpha = 0.01;
    float numda = 0.0001;
    int batchSize = 1;
    int rounds = 10;
    
public:
    NetWorkDelegate(){
        
    }
    NetWorkDelegate(const int layerCount, const Layer *layers):NetWork(layerCount,layers){
    }
    
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
