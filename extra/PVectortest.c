/* test it @ http://rextester.com/LBLM44761 */
#include <stdio.h>
/* the data must be packed and aligned, otherwise assembly may cause sigsev */
typedef struct PVector {double x,y,z,w;} __attribute__ ((aligned (32),packed)) PVector;

/* AVX macro that makes a AT&T syntax*/

/*
first argument name of funtion to be created by macro,
second argument the x86 mnemonic
mnemonics can be found at the right-hand side of this page
https://software.intel.com/sites/landingpage/IntrinsicsGuide/
*/

/* only one pvector argument */

#define AVXA(function,mnemonic) \
PVector static inline function \
(PVector A){PVector ret; asm( \
#mnemonic " %1,%%ymm0;\n" \
"VMOVDQA %%ymm0,%0;\n" \
: "=m" (ret): "m" (A));return ret;}

AVXA(pvsqrt,VSQRTPD) 

/* one pvector and value 0-3, round floor ceil trunc*/

#define AVXR(function,imm8) \
PVector static inline function \
(PVector A){PVector ret; char imm = 1;  asm( \
"VROUNDPD $" #imm8 ",%1,%%ymm0;\n" \
"VMOVDQA %%ymm0,%0;\n" \
: "=m" (ret): "m" (A), "i" (imm) );return ret;}

AVXR(pvround,0)
AVXR(pvfloor,1)
AVXR(pvceil,2)
AVXR(pvtrunc,3)

/* two pvector argument */

#define AVXAB(function,mnemonic) \
PVector static inline function \
(PVector A, PVector B){PVector ret; asm( \
"VMOVDQA %1,%%ymm1;\n" \
#mnemonic " %2,%%ymm1,%%ymm0;\n" \
"VMOVDQA %%ymm0,%0;\n" \
: "=m" (ret): "m" (A) ,"m" (B));return ret;}

AVXAB(add,VADDPD)
AVXAB(sub,VSUBPD)
AVXAB(mult,VMULPD)
AVXAB(div,VDIVPD)

//untested
//AVXAB(addsub,VADDSUBPD)
//AVXAB(min,VPMIND)
//AVXAB(max,VPMAXD)
// bitwise
//AVXAB(pvand,VANDPD)
//AVXAB(pvandnot,VANDNPD)
//AVXAB(pvor,VORPD)
//AVXAB(pvxor,VXORPD)

/* convenience function to make or set a PVector */
PVector new_PVector(double X,double Y,double Z, double W){
    PVector ret;
    ret.x = X;
    ret.y = Y;
    ret.z = Z;
    ret.w = W;
    return ret;
}

/* convenience function to printf a PVEctor */

void print_PVector(PVector PV){
    printf("%lf %lf %lf %lf\n",PV.x,PV.y,PV.z,PV.w);
}

int main(void){
    PVector a, b, c;
    a = new_PVector(4,5,6,7);
    b = new_PVector(1,2,3,4);
    
    print_PVector( add(a,b) );
    
    print_PVector( div(a,b) );
    
    print_PVector( mult(a,b) );

    print_PVector( pvsqrt(b) );
    
    c = new_PVector(-1.1, 2.3, -3.6, 4.7);
    
    print_PVector( pvround(c) );
    print_PVector( pvfloor(c) );
    print_PVector( pvceil(c) );
    print_PVector( pvtrunc(c) );
}
