#include <stdio.h>
#include <math.h> // with flag -lm
// include "math.c" // to be implemented
include "PVectortest.c"

#define MAT matstack[mati]
typedef struct mat{ struct{double m00,m01,m02,m10,m11,m12;};}mat;
mat matstack[100];
int mati = 0;

mat matset(double m00,double m01, double m02, double m10, double m11, double m12){
  mat ret = {m00,m01,m02,m10,m11,m12};
  return ret;
}

void pushMatrix(){
 matstack[mati+1] = MAT;
 mati++;
}
void popMatrix(){mati--;}

void translate(double tx,double ty){
  MAT.m02 += tx * MAT.m00 + ty * MAT.m01;
  MAT.m12 += tx * MAT.m10 + ty * MAT.m12;
}

void rotate(double angle) {
    double s = sin(angle);
    double c = cos(angle);

    double temp1 = MAT.m00;
    double temp2 = MAT.m01;
    MAT.m00 =  c * temp1 + s * temp2;
    MAT.m01 = -s * temp1 + c * temp2;
    temp1 = MAT.m10;
    temp2 = MAT.m11;
    MAT.m10 =  c * temp1 + s * temp2;
    MAT.m11 = -s * temp1 + c * temp2;
  }
void scale(double s) {
    MAT.m00 *= s;  MAT.m01 *= s;
    MAT.m10 *= s;  MAT.m11 *= s;
  }
/*void scalexy(double sx, double sy) {
    MAT.m00 *= sx;  MAT.m01 *= sy;
    MAT.m10 *= sx;  MAT.m11 *= sy;
  }*/

PVector multmat(PVector PV) {
    PVector ret;
    ret.x = MAT.m00*PV.x + MAT.m01*PV.y + MAT.m02;
    ret.y = MAT.m10*PV.x + MAT.m11*PV.y + MAT.m12;
    return ret;
  }

void printMatrix(mat M){
printf("%lf %lf %lf\n%lf %lf %lf\n",M.m00,M.m01,M.m02,M.m10,M.m11,M.m12);
}

int main(){
MAT = matset(1,0,0, 0,1,0); // identity
rotate(3.14);
scale(2);
printMatrix(MAT);

PVector a, b;
a = new_PVector(4,5,0,0);
b = new_PVector(1,2,0,0);
a = multmat(a);
b = multmat(b);

print_PVector(a);
print_PVector(b);

}
