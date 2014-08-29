//
//  Mat.h
//  CNN
//
//  Created by Eric on 8/1/14.
//  Copyright (c) 2014 cv. All rights reserved.
//

#ifndef __CNN__Mat__
#define __CNN__Mat__

#include <iostream>
#include "Size.h"


typedef float Datatype;
const Datatype m_e = 2.718281828459;
class Mat{
private:
    inline void initSize(const Size &size);
public:
    Size size;
    Datatype *data;
    unsigned int totalCount;
    Mat(){
        size = Size();
        totalCount = 0;
        data = new Datatype[totalCount];
    }
    
    Mat(const Size &_size);
    Mat(const Size &_size,const Datatype *_data);
    Mat(const Mat &mat);
    Mat& operator = (const Mat &mat);
    ~Mat(){
        if(totalCount > 0){
            delete [] data;
        }
        std::cout << "Mat destructed" <<std::endl;
    }
    inline void setData(const Datatype *_data,const Size &_size);
     void setSize(const Size &_size);
    
     Datatype getDataAt(const int x,const int y, const int z) const;
    inline Datatype getDataAt(const int x,const int y) const;
    inline Datatype getDataAt(const int ref[], const int refCount) const;
    
    Mat *getMatAt(const int index) const;
    void setDataAt(const int x,const int y, const int z,const Datatype &newValue ) ;
    void setDataAt(const int x,const int y,const Datatype &newValue) ;
    inline void setDataAt(const int ref[], const int refCount,const Datatype &newValue) ;
    
    
    inline int getSize(const int atDim) const {
        assert(atDim < this->size.dim);
        return *(this->size.sizes + atDim);
    }
    void randomInitialized();
    
};

static void  testMat(){
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
    
    Datatype data[] = {1,2,3,4};
    int sz[2] = {2,2};
    Size s = Size(2, sz);
    Mat mat6 = Mat(s, data);
    std::cout << "Data set " << *(mat6.data + 0) <<std::endl;

    
}
#endif /* defined(__CNN__Mat__) */
