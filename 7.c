#include<stdio.h>
enum embeddedOS{
    WindowsCE,
    EmbeddedLinux,
    BlackBerryOS,
    Symbian,
    JavaOS,
    QNX,
    VxWorks

};
struct square
{
    int Ax,Ay,Dx,Dy;
    
};
union printer{
    struct 
    {
        unsigned int ready : 1;
        unsigned int lowToner : 1;
        unsigned int corruptedDrum : 1;
        unsigned int noPaper : 1;
    }bits;
    unsigned int hex;
}  ; 
int main(){
    enum embeddedOS symbian;
    symbian = Symbian;
    printf("Symbian = %d\n",symbian);
    struct square example = {0, 3 , -1 , 7};
    int S = (example.Ax-example.Dx)*(example.Ax-example.Dx)+(example.Ay-example.Dy)*(example.Ay-example.Dy);
    int bits;
    scanf("%x",&bits);
    union printer printerExample;
    printerExample.hex = bits;
    printf("ready: %d\nlow toner: %d\ncorrupted drum: %d\nno paper: %d",printerExample.bits.ready, printerExample.bits.lowToner, printerExample.bits.corruptedDrum, printerExample.bits.noPaper );

}