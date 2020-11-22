#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
    unsigned char *fileName = (char*)malloc(100);
    strcpy(fileName,argv[1]+11);
    FILE *mp3;
    mp3 = fopen(fileName,"rb");
    unsigned char header[10];
    fgets(header,11,mp3);
    long long tagsSz = header[6]*256*256*256/2+header[7]*256*256/2+header[8]*256/2+header[9]%128;
    unsigned char *tags = (unsigned char*)malloc(tagsSz);
    fgets(tags,tagsSz,mp3);
    unsigned char *test = (unsigned char*)malloc(tagsSz);
    fgets(test,tagsSz,mp3);

    if(strcmp(argv[2],"--show")==0){
        int i = 0;
        while(i<tagsSz){
            unsigned char* tag[4] = {tags[i],tags[i+1],tags[i+2],tags[i+3]};
            
            printf("%c%c%c%c ",tags[i],tags[i+1],tags[i+2],tags[i+3]);
            i+=4;
            long long sz = 256*256*256*tags[i]+256*256*tags[i+1]+256*tags[i+2]+tags[i+3];
            i+=6;
            int j = i;
            for(i;i<j+sz;i++){
                printf("%c",tags[i]);
            }
            printf("\n");
        }
    }
    unsigned char * func = (char*)malloc(5*sizeof(char));
    strncpy(func,argv[2],5);
    if(strcmp(func,"--get")==0){
        int i = 0;
        unsigned char *find = (unsigned char*)malloc(4*sizeof(char));
        strncpy(find,argv[2]+6,4);
        int found = 0;
        while(i<tagsSz&&found==0){
            unsigned char* tag = (unsigned char*)malloc(4*sizeof(char));
            int j = i;
            for(i;i<j+4;i++){
                printf("%c\n",tags[i]);
                tag[i-j]=tags[i];
            }
            long long sz = 256*256*256*tags[i]+256*256*tags[i+1]+256*tags[i+2]+tags[i+3];
            i+=6;
            j = i;
            if(strcmp(tag,find)==0){
                for(i;i<j+sz;i++){
                    printf("%c",tags[i]);
                }
                printf("\n");
                found = 1;
            }else{
                i+=sz;
            }
        }
        if(found==0){
            printf("this tag does not exist");
        }
    }
    if(strcmp(func,"--set")==0){
        int i = 0;
        unsigned char *find = (unsigned char*)malloc(4*sizeof(char));
        strncpy(find,argv[2]+6,4);
        int found = 0;
        while(i<tagsSz&&found==0){
            unsigned char* tag = (unsigned char*)malloc(4*sizeof(char));
            int j = i;
            for(i;i<j+4;i++){
                printf("%c\n",tags[i]);
                tag[i-j]=tags[i];
            }
            int szI = i;
            long long sz = 256*256*256*tags[i]+256*256*tags[i+1]+256*tags[i+2]+tags[i+3];
            i+=6;
            j = i;
            if(strcmp(tag,find)==0&&found==0){
                found = 1;
                unsigned char *func1 =(unsigned char*)malloc(7);
                strncpy(func1,argv[3],7);
                if(strcmp(func1,"--value")==0){
                    int valueLen = strlen(argv[3]+8);
                    printf("%d\n",valueLen);
                    char *value = (unsigned char*)malloc(valueLen);
                    
                    strcpy(value,argv[3]+8);
                    printf("%s\n",value);
                    FILE *newFile = fopen("temp.mp3","wb");
                    fseek(mp3,0,SEEK_SET);
                    int k = 0;
                    while(k<6){
                        fputc(fgetc(mp3),newFile);
                        k++;
                    }
                    
                    long long int newSz = tagsSz+(valueLen-sz);
                    int ta = newSz%128;
                    newSz = newSz-ta;
                    newSz*=2;
                    newSz+=ta;
                    fputc(newSz/(256*256*256),newFile);
                    fputc(newSz/(256*256),newFile);
                    fputc(newSz/(256),newFile);
                    fputc(newSz,newFile);
                    fseek(mp3,4,SEEK_CUR);
                    while(k<szI+6){
                        fputc(fgetc(mp3),newFile);
                        k++;
                    }
                    fputc(valueLen/(256*256*256),newFile);
                    fputc(valueLen/(256*256),newFile);
                    fputc(valueLen/(256),newFile);
                    fputc(valueLen,newFile);
                    printf("%d\n",sz);
                    fseek(mp3,4,SEEK_CUR);
                    fputc(fgetc(mp3),newFile);
                    fputc(fgetc(mp3),newFile);
                    fputs(value,newFile);
                    fseek(mp3,sz,SEEK_CUR);
                    while(feof(mp3)==0){
                        fputc(fgetc(mp3),newFile);
                    }
                    remove(mp3);
                    rename("temp.mp3","Song.mp3");
                    fclose(newFile);
                }
            }else{
                i+=sz;
            }
        }
        if(found == 0){
            printf("this tag does not exist");
        }
        
    }
    fclose(mp3);
}