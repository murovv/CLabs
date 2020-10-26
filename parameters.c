
#include "parameters.h"
#include<math.h>

double countP(triangle tr){
    return sqrt(pow(tr.x1-tr.x2,2)+pow(tr.y1-tr.y2,2))+sqrt(pow(tr.x1-tr.x3,2)+pow(tr.y1-tr.y3,2))+sqrt(pow(tr.x2-tr.x3,2)+pow(tr.y3-tr.y2,2));
}
double countS(triangle tr){
    double p = countP(tr)/2;
    double a = sqrt(pow(tr.x1-tr.x2,2)+pow(tr.y1-tr.y2,2));
    double b = sqrt(pow(tr.x1-tr.x3,2)+pow(tr.y1-tr.y3,2));
    double c = sqrt(pow(tr.x2-tr.x3,2)+pow(tr.y3-tr.y2,2));
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
