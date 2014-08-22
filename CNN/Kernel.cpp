//
//  Kernel.cpp
//  CNN
//
//  Created by Eric on 8/6/14.
//  Copyright (c) 2014 cv. All rights reserved.
//

#include "Kernel.h"
#include <cmath>

Kernel::Kernel(){
    this->conn_Num = 0;
    this->connectivity = new int[1];
}

Kernel::Kernel(const  int* connectivity,const int conn_Num){
    this->conn_Num = conn_Num;
    this->connectivity = new int[conn_Num];
    memccpy(this->connectivity, connectivity, conn_Num, sizeof(int) * (this->conn_Num));
}
Kernel::Kernel(const  int* connectivity,const int conn_Num,const Size &size){
    this->conn_Num = conn_Num;
    this->connectivity = new int[conn_Num];
    memccpy(this->connectivity, connectivity, conn_Num, sizeof(int) * (this->conn_Num));
    this->size = size;
    this->randomInitialized();
}

Kernel::Kernel(const Kernel &rhs){
    if (this != &rhs) {
        this->conn_Num = rhs.conn_Num;
        this->connectivity = new int[this->conn_Num];
        memcpy(this->connectivity, rhs.connectivity, sizeof(int) * (this->conn_Num));
    }
}

Kernel& Kernel::operator =(const Kernel &rhs){
    if (this != &rhs) {
        this->conn_Num = rhs.conn_Num;
        this->connectivity = new int[this->conn_Num];
        memcpy(this->connectivity, rhs.connectivity, sizeof(int) * (this->conn_Num));
    }
    return *this;
}

void Kernel::calculateFeatureMap(const Mat *pre_feat_maps, Mat *resultFeature_map,const int steps ){
    assert(pre_feat_maps != NULL);
    assert(resultFeature_map != NULL);
    assert(this->size.dim  == pre_feat_maps->size.dim ); //last dim save the connectivity
    
    Size m_size = Size(this->size.dim - 1)  ; //except the first dim
    for (int i = 0; i < m_size.dim; i ++) {
        int newSize = (pre_feat_maps->size.getSizeAtdim( i + 1 )) ;
        
        newSize = (newSize - (this->size.getSizeAtdim(i + 1)) ) / steps + 1;
        m_size.setSizeAtdim(i , newSize);
    }
    Size cur_map = Size(m_size.dim);
    resultFeature_map->setSize(m_size);
    
    //currently for 2 dim map  only
    assert(m_size.dim == 2);
    
    for (int i = 0; i < *(m_size.sizes + 0); i++) {
        for (int j =0 ; j < *(m_size.sizes + 1); j++) {
            int xoffset = i * steps;
            int yoffset = j * steps;
            Datatype sum = Datatype(0);
            for (int m = 0; m < *(this->size.sizes + 0); m++) {
                for (int n = 0; n < *(this->size.sizes + 1); n++) {
                    for (int k = 0; k < this->conn_Num; k++) {
                        int premapIndex = *(this->connectivity + k);
                        sum += this->getDataAt(k, m, n) * (pre_feat_maps->getDataAt(premapIndex, m + xoffset, n + yoffset));
                    }
                }
            }
            Datatype actValue = activationFunc(sum);
            resultFeature_map->setDataAt(i, j,actValue);
        }
    }
    
}
Datatype Kernel::activationFunc(const Datatype &sum) const {
    //Sigmoid funciton
    return Datatype(1.0) / (Datatype(1.0) + pow(m_e, -sum));
}
void Kernel::setConnectivity(const int *connectivity, const int conn_Num){
    delete [] connectivity;
    this->conn_Num = conn_Num;

    this->connectivity = new int[this->conn_Num];
    memcpy(this->connectivity, connectivity, sizeof(int)*(this->conn_Num));
            
}
void Kernel::testKernel(){
    Kernel k = Kernel();
    printf("Default constructure: %d", k.conn_Num);
    int conn[] = {1,2,3};
    Kernel b = Kernel(conn,3);
    printf("Param constructure: %d", b.conn_Num);
    Kernel *c = new Kernel(b);
    printf("Copy constructure: %d", c->conn_Num);
    
}






