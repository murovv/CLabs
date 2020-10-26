#include<stdio.h>
int gcd(int a, int b){
    if (b == 0){
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a*b/gcd(a,b);
}
int sumDigits(int n, int sum){
    if(n!=0){
        sum+=n%10;
        sumDigits(n/10,sum);
    }else{
        return sum;
    }

}
int main(){
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    printf("gcd: %d\nlcm: %d\nsum of digits: %d", gcd(a,b),lcm(a,b),sumDigits(n,0));

}