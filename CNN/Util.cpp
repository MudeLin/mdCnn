//
//  Util.cpp
//  CNN
//
//  Created by imac06 on 14-8-28.
//  Copyright (c) 2014年 cv. All rights reserved.
//

#include "Util.h"
#include <stdio.h>

void Util::loadData(const string dataPath, Mat *inputDatamat,const char* sep, const int dataCount ){
    FILE *fp;
    fp = fopen(dataPath.c_str(), "r");
    char buf[10000];
    int width = inputDatamat->getSize(2);
    int height = inputDatamat->getSize(1);
    if (fp != NULL) {
        int i =0;
        fgets(buf, 10000, fp);
        while (fgets(buf, 4096, fp) != NULL ) {
            
            //;
            const char* tok;
            int count  = 0;
            int label = -1;
            for (tok = strtok(buf, sep);
                 tok && *tok;
                 tok = strtok(NULL, ","), count++)
            {
                if (label == -1) {
                    label = atoi(tok);
                    continue;
                }
                int grayValue = atoi(tok);
                int j = count / width;
                int k = count % width;
                inputDatamat->setDataAt(i, j, k, Datatype(grayValue));
            }
            inputDatamat->setDataAt(i, height, 0, Datatype(label));
            
            i++;
            
        }
        printf("%d",i);
        
    }else{
        printf("Cannot open file %s",dataPath.c_str());
        
    }
}
void Util::saveData(const Mat *outputDatamat, const string outputPath){
    FILE *fp;
    fp = fopen(outputPath.c_str(), "w");
    if (fp != NULL) {
        int count = outputDatamat->getSize(0);
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < outputDatamat->getSize(1); j++) {
                fprintf(fp, "%d,%d\n",int(outputDatamat->getDataAt(i,j, 0)),int(outputDatamat->getDataAt(i, j, 1)));
            }
        }
    }else{
        printf("Cannot open output file %s",outputPath.c_str());
    }
}