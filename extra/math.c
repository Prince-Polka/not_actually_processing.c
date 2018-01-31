/*
Some math is implemented with macros rather than functions
Any line starting with symbol '#' is a macro,
however in this context whenever I refer to macro '#define macro" is implied

Macro IDENTIFIERS ARE CAPITALIZED by convention

#define IDENTIFIER (token) expression

Macros turns into strings and are inlined into sourcecode by the preprocessor BEFORE it's sent to the compiler

Macros will be explained with intuitive pseudo-code function comments
*/



#define MAX0(x)(x-(x<0)*x)
/*
takes integer OR float x
gives integer OR float
if x > 0 return x
else return 0
}
*/
#define ABS(x)(x*((x>0)*2-1))
/*
takes integer OR float x
gives integer OR float
if x < 0 return -x
if x == 0 return 0
if x > 0 return x
}
*/
#define SIGN(x)((x>0)*2-1)
/*
takes integer OR float x
gives integer
if x < 0  return -1
if x == 0 return 0
if x > 0  return 1
*/

double inline sin(double x){asm("fldl %0;\nFSIN;\nfstpl %0;\n":"+m"(x));return x;}
double inline cos(double x){asm("fldl %0;\nFCOS;\nfstpl %0;\n":"+m"(x));return x;}
double inline sqrt(double x){asm("fldl %0;\nFSQRT;\nfstpl %0;\n":"+m"(x));return x;}
//double inline atan(double x){asm("fldl %0;\nFPATAN;\nfstpl %0;\n":"+m"(x));return x;}


clamp(int x,int min, int max){
int temp = min*(x<min) + max*(x>max);
return temp + x * !temp;
}

#define PI 3.14159265359L
#define TWO_PI 6.28318530718L
#define ABS(x)(x*((x>0)*2-1))
#include <stdio.h>

double fastmod(double a, double b){return a - b*((long long int)(a/b));}

const double
 invfact3 = - 1.0L / 6.0L,
 invfact5 =   1.0L / 120.0L,
 invfact7 = - 1.0L / 5040.0L,
 invfact9 =   1.0L / 362880.0L;

double fastsin(double x){

double x0,x1,x2,D;
x0 = fastmod(x,TWO_PI);
x = fastmod(x,PI),
x2 = x*x;
x1=x*x2;
D = 6.0L;
int i = 4;

x -= x1 / D; D*=i*i+i; x1*=x2; i+=2;
x += x1 / D; D*=i*i+i; x1*=x2; i+=2;
x -= x1 / D; D*=i*i+i; x1*=x2; i+=2;
x += x1 / D; D*=i*i+i; x1*=x2; i+=2;
x -= x1 / D; D*=i*i+i; x1*=x2; i+=2;
x += x1 / D; D*=i*i+i; x1*=x2; i+=2;
x -= x1 / D; D*=i*i+i; x1*=x2; i+=2;
x += x1 / D; D*=i*i+i; x1*=x2; i+=2;

if(ABS(x0)>PI){ x=-x; }
return x;
}
