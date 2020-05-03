#ifndef HW_0425_H
#define HW_0425_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void lower(){
    int c;
    while((c = getchar()) != EOF && c != '\n'){
        putchar(tolower(c));
    }
    return;
}

void upper(){
    int c;
    while((c = getchar()) != EOF && c!='\n'){
        putchar(toupper(c));
    }
    return;
}

void run(char * s){
    if(strcmp(s,"upper")==0){
        upper();
        return;
    }else if(strcmp(s,"lower")==0){
        lower();
        return;
    }else{
        printf("input invalid\n");
    }
}

void compare(char* left, char * right){
    FILE* lfp;
    if ((lfp = fopen(left,"r"))==NULL) { printf("file '%s' not found", left); return; }
    int lc,rc; char* s[512]; char* sp; sp=s;
    while((lc = getc(lfp))!=EOF){
        *sp++= lc;
    }
    fclose(lfp);

    FILE* rfp;
    if ((rfp = fopen(right,"r"))==NULL) { printf("file '%s' not found", right); return;}
    sp=s; char* temp[512]; char*tp = temp;
    while((rc=getc(rfp))!=EOF){
        *tp = rc;
        if(*sp++ != *tp++){
            while((rc=getc(rfp))!='\n'){
                *tp++=rc;
            }
            printf("%s\n",temp);
            return;
        }
        if(rc=='\n'){
            memset(temp,0,sizeof(temp));
            tp=temp;
        }
    }
    fclose(rfp);
}

void printfile(char ** fname,int size){
    FILE* fp; int pc=1; int c;
    for(int i = 1;i<size;i++){
        printf("file name : %s page : %d\n",fname[i-1],pc);
        fp= fopen(fname[i-1],"r");
        while((c=getc(fp))!= EOF){
            putchar(c);
        }
        printf("\n");
        fclose(fp);
        ++pc;
    }
}

#endif //HW_0425_H