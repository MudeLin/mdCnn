//
//  Util.h
//  CNN
//
//  Created by imac06 on 14-8-28.
//  Copyright (c) 2014年 cv. All rights reserved.
//

#ifndef __CNN__Util__
#define __CNN__Util__

#include <iostream>
#include <string>
#include "Size.h"
#include "Layer.h"
#include "Mat.h"

using namespace std;

class Util{
public:
    Util(){
        
    }
    void loadData(const string dataPath, Mat *inputDatamat,const char* sep = ",",const int dataCount = -1);
    void saveData(const Mat *outputDatamat, const string outputPath);
};

#endif /* defined(__CNN__Util__) */
