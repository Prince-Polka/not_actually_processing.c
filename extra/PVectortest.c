/* test it @ http://rextester.com/HWR73007 */
#include <stdio.h>
/* the data must be packed and aligned, otherwise assembly may cause sigsev */
typedef struct PVector {double x,y,z,w;} __attribute__ ((aligned (32),packed)) PVector;

/* AVX macro that makes a AT&T syntax*/
#define AVX(function,mnemonic) \
PVector static inline function \
(PVector A, PVector B){PVector ret; asm( \
"VMOVDQA %1,%%ymm1;\n" \
#mnemonic " %2,%%ymm1,%%ymm0;\n" \
"VMOVDQA %%ymm0,%0;\n" \
: "=m" (ret): "m" (A) ,"m" (B));return ret;}
/*
first argument name of funtion to be created by macro,
second argument the x86 mnemonic
mnemonics can be found at the right-hand side of this page
https://software.intel.com/sites/landingpage/IntrinsicsGuide/
*/

/* this makes functions for add subtract multiply and divide of doubles */
AVX(add,VADDPD)
AVX(sub,VSUBPD)
AVX(mult,VMULPD)
AVX(div,VDIVPD)

AVX(addsub,VADDSUBPD)
    
// AVX(sqrt,VSQRTPD) only one argument

AVX(min,VPMIND)
AVC(max,VPMAXD)
    
// bitwise
AVX(and,VANDPD)
AVX(andnot,VANDNPD)
AVX(xor,VORPD)
AVX(xor,VXORPD)
//AVX(ceil,VROUNDPD) imm8
//AVX(floor,VROUNDPD) imm8

    
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
    PVector a, b;
    a = new_PVector(4,5,6,7);
    b = new_PVector(1,2,3,4);
    
    print_PVector( add(a,b) );
    
    print_PVector( div(a,b) );
    
    print_PVector( mult(a,b) );
}
