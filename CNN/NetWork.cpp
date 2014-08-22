//
//  NetWork.cpp
//  CNN
//
//  Created by apple on 8/20/14.
//  Copyright (c) 2014 cv. All rights reserved.
//

#include "NetWork.h"

NetWork::NetWork(const int layerCount, const Layer *layers){
    this->layerCount = layerCount;
    this->layers = new Layer[this->layerCount];
    for (int i = 0; i < this->layerCount; i ++) {
        *(this->layers + i ) = *(layers + i);
    }
}
void NetWork::appendLayer(const Layer *nlayer){
    Layer *newlayers = new Layer[this->layerCount + 1];
    assert(newlayers != NULL);
    int i ;
    for ( i = 0; i < this->layerCount; i++) {
        *(newlayers + i) = *(this->layers + i);
    }
    delete [] this->layers;
    this->layerCount ++;
    *(newlayers + i) = *(nlayer);
    
    this->layers = newlayers;

}
