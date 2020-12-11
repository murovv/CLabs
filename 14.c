#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[]){
    int param = 1;
    char *outputDir="NULL";
    int maxIter = 10;
    int dump_freq = 1;
    FILE *bmp;
    int **field;
    int width = 0;
    int height = 0;
    int bitCount = 0;
    int offset = 0;
    while(param<argc){
        if(strcmp(argv[param],"--output")==0){
            param++;
            outputDir = malloc(strlen(argv[param]));
            strcpy(outputDir,argv[param]);
            param++;
        }else if(strcmp(argv[param],"--input")==0){
            param++;
            bmp = fopen(argv[param],"rb");
            char B=fgetc(bmp);
            char M=fgetc(bmp);
            if(B!='B'||M!='M'){
                printf("file is not bmp!");
                break;
            }
            fseek(bmp,8,SEEK_CUR);
            offset = 0;
            for(int i = 0;i<4;i++){
                offset+=fgetc(bmp)<<(i*8);
            }
            printf("%d",offset);
            fseek(bmp,4,SEEK_CUR);
            width = 0;
            height = 0;
            for(int i = 0;i<4;i++){
                width+=fgetc(bmp)<<(i*8);
            }
            for(int i = 0;i<4;i++){
                height+=fgetc(bmp)<<(i*8);
            }
            fseek(bmp,2,SEEK_CUR);
            bitCount = 0;
            for(int i = 0;i<2;i++){
                bitCount+=fgetc(bmp)<<(i*8);
            }
            bitCount/=8;
            fseek(bmp,offset,SEEK_SET);
            field = (int**)malloc((height+2)*sizeof(int*));
            for(int i = 0;i<height+2;i++){
                field[i]=(int*)malloc((width+2)*sizeof(int));
            }
            for(int i = height;i>=1;i--){
                for(int j = 1;j<=width;j++){
                    int color = 0;
                    for(int k = 0;k<bitCount;k++){
                        color+=fgetc(bmp)<<(8*i);
                    }
                    if(color==0){
                        field[i][j]=1;
                    }
                }
            }
            param++;
        }else if(strcmp(argv[param],"--max_iter")==0){
            param++;
            maxIter = atoi(argv[param]);
            param++;
        }else if(strcmp(argv[param],"--dump_freq")==0){
            param++;
            dump_freq = atoi(argv[param]);
            param++;
        }
    }
    for(int iter = 0;iter<maxIter;iter++){
        if(width==0||height==0){
            printf("invalid image");
        }
        int **fieldCopy = (int**)malloc((height+2)*sizeof(int*));
        for(int i = 0;i<height+2;i++){
            fieldCopy[i]=(int*)malloc((width+2)*sizeof(int));
            for(int j = 0;j<width+1;j++){
                fieldCopy[i][j]=field[i][j];
            }
        }
        for(int i = 1;i<=height;i++){
            for(int j = 1;j<=width;j++){
                int alives = 0;
                for(int t1=-1;t1<=1;t1++){
                    for(int t2=-1;t2<=1;t2++){
                        if((t1!=0||t2!=0)&&fieldCopy[i+t1][j+t2]==1){
                            alives++;
                        }
                    }
                }
                if(fieldCopy[i][j]==1&&(alives==2||alives==3)){
                    field[i][j]=1;
                }else if(fieldCopy[i][j]==0&&(alives==3)){
                    field[i][j]=1;
                }else{
                    field[i][j]=0;
                }
            }
        }
        free(fieldCopy);
        if(iter%dump_freq==0){
            FILE *output;
            int length = snprintf( NULL, 0, "%d", iter );
            char* str = malloc( length + 1 );
            snprintf( str, length + 1, "%d", iter );
            char* name = "/state";
            strcat(name,str);
            strcat(outputDir,name);
            strcat(outputDir,".bmp");
            output = fopen("state.bmp","wb");
            long long sz = 54+width*height*bitCount;
            fseek(bmp,0,SEEK_SET);
            for(int i =0;i<2;i++){
                fputc(fgetc(bmp),output);
            }
            for(int i =0;i<4;i++){
                fputc(sz%256,output);
                sz = sz>>8;
            }
            fseek(bmp,4,SEEK_CUR);
            for(int i =0;i<12;i++){
                fputc(fgetc(bmp),output);
            }
            int twidth = width;
            int theight = height;
            for(int i =0;i<4;i++){
                fputc(twidth%256,output);
                twidth = twidth>>8;
            }
            for(int i =0;i<4;i++){
                fputc(theight%256,output);
                theight = theight>>8;
            }
            fseek(bmp,8,SEEK_CUR);
            for(int i =26;i<offset;i++){
                fputc(fgetc(bmp),output);
            }
            for(int i = height;i>=1;i--){
                for(int j = 1;j<=width;j++){
                    if(field[i][j]==0){
                        for(int k = 0;k<bitCount;k++){
                            fputc(255,output);
                        }
                    }else{
                        for(int k = 0;k<bitCount;k++){
                            fputc(0,output);
                        }
                    }
                }
            }
            fclose(output);
        }
        
    }
    fclose(bmp);
}