#ifndef PARAMETERS_H
#define PARAMETERS_H
typedef struct {
    int x1,x2,x3,y1,y2,y3;
}triangle;
double countP(triangle tr);
double countS(triangle tr);
#endif