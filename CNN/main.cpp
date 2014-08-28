//
//  main.cpp
//  CNN
//
//  Created by Eric on 8/1/14.
//  Copyright (c) 2014 cv. All rights reserved.
//

#include <iostream>
#include "Size.h"
#include "Mat.h"
#include "Layer.h"
#include "NetoWorkdelegate.h"
#include "Util.h"
void initializedNetwork(NetWorkDelegate *delegate);

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    
    Util util = Util();
    Mat *inputDataMat = new Mat();
    int inputdim[] = {42010,29,28};
    inputDataMat->setSize(Size(3,inputdim));
    util.loadData("/Users/imac06/Downloads/train.csv", inputDataMat);
    util.saveData(inputDataMat, "/Users/imac06/Downloads/testWrite.csv");
    /*NetWorkDelegate *delegate = new NetWorkDelegate();
    initializedNetwork(delegate);
    
    testSize();
    testMat();
    testLayer();
    */
    return 0;
}

void initializedNetwork(NetWorkDelegate *delegate){
    
    Layer *layer = new Layer();
    
    //add input layer
    layer->setType(InputLayer);
    delegate->appendLayer(layer);
    delete layer;
    
    //add first conv layer
    
    int connectivities[] = {0};
    int sizes[] = {5,5};
    
    Kernel *kernels = new Kernel[6];
    for(int i = 0;i < 6; i++){
        (kernels + i)->setConnectivity(connectivities, 1);
        (kernels + i)->setSize(Size(2,sizes));
    }
    layer = new Layer(6,kernels);
    delete [] kernels;
    
    delegate->appendLayer(layer);
    delete layer;
    //add the pooling layer
    layer = new Layer();
    
    layer->setType(PoolingLayer);
    //TODO: more on average pooling or max pooling
    delegate->appendLayer(layer);
    delete layer;
    
    kernels = new Kernel[16];
    for(int i = 0;i < 16; i++){
        int *connectivities;
        if (i <= 5) {
            connectivities = new int[3];
            for (int j = 0; j < 3;j ++) {
                *(connectivities + j) = (i + j) % 6;
            }
            (kernels + i)->setConnectivity(connectivities, 3);
            
        }else if ( i <= 11){
            connectivities = new int[4];
            for (int j = 0; j < 4; j ++) {
                *(connectivities + j) = (i + j ) % 6;
            }
            (kernels + i)->setConnectivity(connectivities, 4);
            
        }else if(i == 12){
            connectivities = new int[4];
            *(connectivities + 0) = 0;
            *(connectivities + 1) = 1;
            *(connectivities + 2) = 3;
            *(connectivities + 3) = 4;
            (kernels + i)->setConnectivity(connectivities, 4);
            
        }else if(i == 13){
            connectivities = new int[4];
            *(connectivities + 0) = 1;
            *(connectivities + 1) = 2;
            *(connectivities + 2) = 4;
            *(connectivities + 3) = 5;
            (kernels + i)->setConnectivity(connectivities, 4);
            
        }else if(i == 14){
            connectivities = new int[4];
            *(connectivities + 0) = 0;
            *(connectivities + 1) = 2;
            *(connectivities + 2) = 3;
            *(connectivities + 3) = 5;
            (kernels + i)->setConnectivity(connectivities, 4);
            
        }else {
            connectivities = new int[6];
            for (int j = 0; j  < 6;j ++){
                *(connectivities + j) = j;
            }
            (kernels + i)->setConnectivity(connectivities, 6);
            
        }
        
        (kernels + i)->setSize(Size(2,sizes));
    }
    layer = new Layer(16,kernels);
    delete [] kernels;
    delegate->appendLayer(layer);
    delete layer;
    
    //add pooling layer
    layer = new Layer();
    layer->setType(PoolingLayer);
    delegate->appendLayer(layer);
    delete layer;
    
    //add full connection 1 layer
    layer = new Layer();
    layer->setType(FullLayer);
    //TODO: do more on middle layer size
    delegate->appendLayer(layer);
    delete layer;
    
    //add full connection 2 layer
    layer = new Layer();
    layer->setType(FullLayer);
    //TODO: do more on middle layer size
    delegate->appendLayer(layer);
    delete layer;
    
    //add softmax output layer
    layer = new Layer();
    layer->setType(SoftMaxLayer);
    //TODO: do more on softmax layer size
    delegate->appendLayer(layer);
    delete layer;
}

