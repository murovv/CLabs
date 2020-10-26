#include<stdio.h>
int main(){
    int len;
    scanf("%d", &len);
    char *str = (char*)malloc(len*sizeof(char));
    scanf("%s",str);
    int digits = 0;
    int capitals = 0;
    int smalls = 0;
    for(int i = 0;i<len;i++){
        char c = *(str+i);
        if(c>='0'&&c<='9'){
            digits++;
        }
        if(c>='A'&&c<='Z'){
            capitals++;
        }
        if(c>='a'&&c<='z'){
            smalls++;
        }
    }
    printf("digits: %d\ncapitals: %d\nsmalls: %d\n",digits,capitals,smalls);

    int last;
    scanf("%d", &last);
    int * isSimple = (int* )malloc((last+1)*sizeof(int));
    for(int i = 2;i*i<=last;i++){
        if(*(isSimple+i)==0){
            for(int j = 2*i;j<=last;j+=i){
                *(isSimple+j)=1;
            }
        }
    }
    for(int i = 0;i<=last;i++){
        if(*(isSimple+i)==0){
            printf("%d ", i);
        }
    }
}   