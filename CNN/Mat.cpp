//
//  Mat.cpp
//  CNN
//
//  Created by Eric on 8/1/14.
//  Copyright (c) 2014 cv. All rights reserved.
//

#include "Mat.h"
#include <stdlib.h>

Mat::Mat(const Size &_size){
    this->size = Size();
    this->initSize(_size);
}

Mat::Mat(const Mat &mat){
    if(this != &mat){
        this->size = Size();
        this->initSize(mat.size);
        assert(data != NULL);
        memcpy(data, mat.data, totalCount * sizeof(Datatype));
    }
}

Mat::Mat(const Size &_size,const Datatype *_data){
    this->size = Size();
    this->initSize(_size);
    this->setData(_data, _size);
}
void Mat::setData(const Datatype *_data, const Size &_size) {
    assert(_data != NULL);
    assert(this->size == _size);
    if (this->totalCount == 0) {
        this->data = new Datatype[this->totalCount];
        assert(this->data != NULL);
    }
    
    assert(data != NULL);
    memcpy(this->data, _data, totalCount * sizeof(Datatype));
    
}
void Mat::initSize(const Size &_size){
    this->size = _size;
    unsigned int totalCount = 0;
    for (int i = 0; i < this->size.dim;  i ++ ) {
        int dimSize = *((this->size).sizes + i);
        assert(dimSize > 0);
        if (i == 0) {
            totalCount = dimSize;
        }else{
            totalCount *= dimSize;
        }
        
    }
    //feed data
    this->totalCount = totalCount;
    this->data = new Datatype[totalCount];
    assert(this->data != NULL);
    memset(this->data, 0, totalCount * sizeof(Datatype));
}

void Mat::setSize(const Size &_size){
    if (this->totalCount > 0) {
        delete [] this->data;
    }
    this->size = _size;
    unsigned int totalCount = 0;
    for (int i = 0; i < this->size.dim;  i ++ ) {
        int dimSize = *((this->size).sizes + i);
        assert(dimSize >= 0);
        if (i == 0) {
            totalCount = dimSize;
        }else{
            totalCount *= dimSize;
        }
    }
    this->totalCount = totalCount;
    
    this->data = new Datatype[totalCount];
    assert(this->data != NULL);
    memset(data, 0, totalCount * sizeof(Datatype));
}

Datatype Mat::getDataAt(const int x, const int y, const int z) const{
    assert(this->size.dim == 3);
    unsigned int index = x * (this->size.getSizeAtdim(1))*(this->size.getSizeAtdim(2)) + y*(this->size.getSizeAtdim(2)) + z ;
    assert(index < totalCount);
    
    return *(this->data + index);
}

Mat* Mat::getMatAt(const int index) const {
    int nsize[] = {this->size.getSizeAtdim(1) - 1 ,this->getSize(2)};
    
    Mat *row = new Mat(Size(2, nsize));
    
    return row;
}

void Mat::setDataAt(const int x, const int y, const Datatype &newValue){
    assert(this->size.dim == 2);
    unsigned int index = x * (this->size.getSizeAtdim(1)) + y;
    assert(index < totalCount);
    
    *(this->data + index) = newValue;
    
}
void Mat::setDataAt(const int x, const int y,const int z, const Datatype &newValue){
    assert(this->size.dim == 3);
    unsigned int index = x * (this->size.getSizeAtdim(1))*(this->size.getSizeAtdim(2)) + y*(this->size.getSizeAtdim(2)) + z ;
    assert(index < totalCount);
    
    *(this->data + index) = newValue;
    
}
Mat& Mat::operator=(const Mat &mat){
    if(this != &mat){
        this->setSize(mat.size);
        assert(data != NULL);
        memcpy(data, mat.data, totalCount * sizeof(Datatype));
    }
    return *this;
}


void Mat::randomInitialized(){
    srand(1000);
    assert(this->data != NULL);
    Datatype tmp;
    int max = 1000;
    int mean = 500;
    for (int i = 0; i < this->totalCount; i++) {
        tmp = (Datatype)(rand()%max - mean)/(max*10);
        *(this->data + i) = tmp;
    }
}
