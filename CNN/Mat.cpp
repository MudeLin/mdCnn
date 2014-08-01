//
//  Mat.cpp
//  CNN
//
//  Created by Eric on 8/1/14.
//  Copyright (c) 2014 cv. All rights reserved.
//

#include "Mat.h"
#include <stdlib.h>

Mat::Mat(const Size &size){
    this->size = size;
    int totalCount = 0;
    for (int i = 0; i < this->size.dim;  i ++ ) {
        int dimSize = *((this->size).sizes + i);
        assert(dimSize > 0);
        totalCount += dimSize;
    }
    this->totalCount = totalCount;
    data = new Datatype[totalCount];
    memset(data, 0, totalCount * sizeof(Datatype));
}

Mat::Mat(const Mat &mat){
    if(this != &mat){
        this->size = mat.size;
        int totalCount = 0;
        for (int i = 0; i < this->size.dim;  i ++ ) {
            int dimSize = *((this->size).sizes + i);
            assert(dimSize > 0);
            totalCount += dimSize;
        }
        this->totalCount = totalCount;
        data = new Datatype[totalCount];
        assert(data != NULL);
        memcpy(data, mat.data, totalCount * sizeof(Datatype));
    }
}
Mat& Mat::operator=(const Mat &mat){
    if(this != &mat){
        this->size = mat.size;
        int totalCount = 0;
        for (int i = 0; i < this->size.dim;  i ++ ) {
            int dimSize = *((this->size).sizes + i);
            assert(dimSize > 0);
            totalCount += dimSize;
        }
        this->totalCount = totalCount;
        delete [] data;
        
        data = new Datatype[totalCount];
        
        assert(data != NULL);
        memcpy(data, mat.data, totalCount * sizeof(Datatype));
    }
    return *this;
}
void Mat::testMat(){
    int dim = 3;
    int sizes[] = {2,2,3};
    Size ts = Size(dim,sizes);
    Mat mat = Mat(ts);
    std::cout << "Mat constructed: "<< mat.size.dim << std::endl;
    Mat mat2 = Mat(mat);
    std::cout << "Mat copy constructed: "<< mat2.size.dim << std::endl;
    Mat mat4;
    mat4 = mat2;
    std::cout << "Mat copy constructed: "<< mat4.size.dim << std::endl;
    Mat *mat5 = new Mat(mat2);
    std::cout << "Mat copy constructed: "<< mat5->size.dim << std::endl;
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
