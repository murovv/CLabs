#include<stdio.h>
char * strncat(char *string1,char *string2,int n){
    int len1 = 0;
    while(*(string1+len1)!='\0'){
        len1++;
    }
    int len2 = 0;
    while(*(string2+len2)!='\0'){
        len2++;
    }
    if(n<len2){
        len2 = n;
    }
    char *returnArray = malloc((len1+len2)*sizeof(char));
    for(int i = 0;i<len1;i++){
        *(returnArray+i) = *(string1+i);
    }
    for(int i = 0;i<len2;i++){
        *(returnArray+len1+i) = *(string2+i);
    }
    return returnArray;
}
char * strrchr(char *string , char find){
    char *adress;
    int isContains = 0;
    int i = 0;
    while(*(string+i)!='\0'){
        if(*(string+i)==find){
            adress = string+i;
            isContains = 1;
        }
        i++;
    }
    if(isContains==1){
        return adress;
    }else{
        return NULL;
    }
}
char * strcpy(char *destination, char *source){
    int  i= 0;
    while(*(source+i)!='\0'){
        *(destination+i) = *(source+i);
        i++;
    }
    *(destination+i) = '\0';
    return destination;
}
char * strncpy(char *destination, char *source, int n){
    int  i= 0;
    while((*(source+i)!='\0')&&(i<=n)){
        *(destination+i) = *(source+i);
        i++;
    }
    return destination;

}
int contains(char *str, char c){
    int i = 0;
    int isContains = 0;
    while(*(str+i)!='\0'){
        if(*str+i==c){
            isContains = 1;
            break; 
        }
        i++;
    }
    return isContains;
}
int strcspn(char *string , char *symbols){
    int len = 0;
    while(contains(symbols,*(string+len))==0){
        len++;
    }
    return len;
}
int main(){
    int len1,len2,n;
    scanf("%d%d%d",&len1,&len2,&n);
    char *string1 = (char*)malloc(len1+1); 
    char *string2 = (char*)malloc(len2+1);
    scanf("%s",string1);
    scanf("%s",string2);
    char* ans1 = strncat(string1,string2,n);
    printf("%s",ans1);

    int lenDest,lenSource;
    scanf("%d%d",&lenDest,&lenSource);
    char *destination = (char*)malloc(lenDest+1);
    char *source = (char*)malloc(lenSource+1);
    scanf("%s",source);
    destination = strcpy(destination,source);
    printf("%s",destination);

    int lenNDest,lenNSource, n;
    scanf("%d%d%d",&lenNDest,&lenNSource,&n);
    char *nDestination = (char*)malloc(lenNDest+1);
    char *nSource = (char*)malloc(lenNSource+1);
    scanf("%s",nSource);
    nDestination = strcpy(destination,source);
    printf("%s",nDestination);

    char find;
    int lenFind;
    scanf("%c%d",&find,&lenFind);
    char *stringFind = (char*)malloc(lenFind+1);
    scanf("%s",stringFind);
    char *adress = strrchr(stringFind,find);
    printf("%p\n",stringFind);
    printf("%p",adress);

    int lenStringTask5,lenSymTask5;
    scanf("%d%d",&lenStringTask5,&lenSymTask5);
    char *stringTask5 = (char*)malloc(lenStringTask5+1);
    char *symTask5= (char*)malloc(lenSymTask5+1);
    scanf("%s",stringTask5);
    scanf("%s",symTask5);
    int uniqueLen = strcspn(stringTask5,symTask5);
    printf("%d",uniqueLen);

}