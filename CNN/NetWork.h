//
//  NetWork.h
//  CNN
//
//  Created by apple on 8/20/14.
//  Copyright (c) 2014 cv. All rights reserved.
//

#ifndef __CNN__NetWork__
#define __CNN__NetWork__

#include <iostream>
#include "Layer.h"

class NetWork{
protected:
    int layerCount;
    Layer *layers;
public:
    NetWork() {
        this->layerCount = 0;
        this->layers = new Layer[1];
    }
    
    NetWork(const int _layerCount, const Layer *layers);
    void appendLayer(const Layer *nlayer);
    
};
#endif /* defined(__CNN__NetWork__) */
