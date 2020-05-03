#include "hw_0425.h"
#include <stdio.h>
int main(int argc, char* argv[]){
    if(argc ==2){
        run(argv[1]);
    }else if(argc ==3){
        compare(argv[1],argv[2]);
    }else if(argc >3){
        char** fname;
        for(int i = 1;i<argc;i++){
            fname[i-1]=argv[i];
        }
        printfile(fname,argc);
    }
    return 0;
}