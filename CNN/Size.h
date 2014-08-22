//
//  Size.h
//  CNN
//
//  Created by Eric on 8/1/14.
//  Copyright (c) 2014 cv. All rights reserved.
//

#ifndef __CNN__Size__
#define __CNN__Size__

#include <iostream>
#include <cassert>
class Size {
public:
    int dim;
    int *sizes;
    Size(){
        this->dim = 0;
        this->sizes = new int[1];
    }
    Size(const int dim){
        this->dim = dim;
        this->sizes = new int[this->dim];
        memset(this->sizes, 0, sizeof(int) * (this->dim));
    }
    Size(const int dim, const int *sizes){
        assert(sizes != NULL);
        this->dim = dim;
        this->sizes = new int[dim];
        assert(this->sizes != NULL);
        memcpy(this->sizes, sizes, (this->dim) * sizeof(int));
    }
    Size(const Size &rhs){
        this->dim = rhs.dim;
        this->sizes = new int[dim];
        memcpy(this->sizes, rhs.sizes, (this->dim) * sizeof(int));
    }
    Size& operator =(const Size &rhs){
        if (this != &rhs) {
            this->dim = rhs.dim;
            delete [] this->sizes;
            this->sizes = new int[dim ];
            memcpy(this->sizes, rhs.sizes, (this->dim) * sizeof(int));
        }
        return *this;
    }
    void setSizeAtdim(int dim, int newSize){
        assert(dim >=0 && dim < this -> dim);
        *(this->sizes + dim) = newSize;
    }
    inline int getSizeAtdim(int dim) const {
        assert(dim >=0 && dim < this -> dim);
        return *(this->sizes + dim);
    }
    ~Size(){
        std::cout << "Size destructed! " << std::endl;
        delete [] sizes;
    }
};

inline bool operator==(const Size &lhs,const Size &rhs){
    if (lhs.dim != rhs.dim) {
        return false;
    }
    for (int i = 0; i < lhs.dim; i ++ ) {
        if (*(lhs.sizes + i) != *(rhs.sizes + i)) {
            return false;
        }
    }
    return true;
}
inline bool operator != (const Size &lhs,const Size &rhs){
    return !(lhs == rhs);
}
static void testSize(){
    Size size = Size();
    std::cout <<"size dim"<< size.dim << std::endl;
    int sizes[] = {1,2,3};
    Size size2 = Size(3,sizes);
    std::cout << "sizeb dim"<< size2.dim <<std::endl;
    for(int i = 0;i < size2.dim; i ++){
        std::cout <<"dim "<<i << ":" << *(size2.sizes + i) << std::endl;
    }
    size = size2;
    std::cout << "copy size2 dim"<< size.dim <<std::endl;
    for(int i = 0;i < size.dim; i ++){
        std::cout <<"dim "<<i << ":" << *(size.sizes + i) << std::endl;
    }
    Size size3(size2);
    std::cout << "copy structure dim"<< size3.dim <<std::endl;
    for(int i = 0;i < size3.dim; i ++){
        std::cout <<"dim "<<i << ":" << *(size3.sizes + i) << std::endl;
    }
    Size *size4 = new Size();
    std::cout << size4->dim << std::endl;
    std::cout << "Equal operator == "<< int(size == size2) << std::endl;
    std::cout << "Equal operator == "<< int(size != size2) << std::endl;
}




#endif /* defined(__CNN__Size__) */
