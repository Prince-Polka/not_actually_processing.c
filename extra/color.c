/*
something like this may work, have not tested in tcc
https://stackoverflow.com/questions/11761703/overloading-macro-on-number-of-arguments/

color_3 (a,b,c) {puts("3");}
color_2 (a,b){puts("2");}
color_1 (a){puts("1");}
color_0 (void){puts("0");}

typedef union color{
struct {char b,g,r,a;}; // change to  a,b,g,r for opengl
signed int i;
unsigned int u;
}color;

#define GET_MACRO(_0,_1,_2,_3,NAME,...) NAME
#define color(x...) GET_MACRO(_0,## x , color_3 , color_2 , color_1 , color_0 )(x)

int main(void){
color foo;
foo.r = 25;
printf("%d\n",foo.r);
color();
color(1);
color(2,2);
color(3,3,3);
}

*/

/*
https://processing.org/reference/color_.html
colors in processing java are signed integers

Although processing is almost Java, it's not exactly java,
and although Java is C-like Java isn't C

To implement exactly the same syntax in C is tricky for multiple reasons


here it is a 'union'

Syntax that is valid in processing but not here;

valid in processing java
color mycolor = 12345;
color mycolor = 0xFF010203;
color mycolor = #A59B4A;
color mycolor = color(1);
color mycolor = color(1,1);
color mycolor = color(1,1,1);
color mycolor = color(1,1,1,1);

VALID syntax
color mycolor = {.i=5};

*/
#define INTT_COLOR(r,g,b,a){b,g,r,a}
/*
Shuffles initializer supplied in order r,g,b,a to order b,g,r,a

*/
int constrain(int x,int min, int max){

// int temp = min*(x<min) + max*(x>max);
// return temp + x * !temp;
// Above code works (for most inputs) and is branchless, but fails if min or max = 0
// Naive implementation works for that edge case but may be slow? (haven't looked at generated assembly)
if(x<min) return min; 
if(x>max) return max;
return x;
}

#define GRAY(v){v,v,v,255}
#define GRAYALPHA(v,a){v,v,v,a}
#define RGB(r,g,b){b,g,r,255}
#define HEX(x){.i = 0xFF##x}
#define UINT(x){.i = x}

#define CLAMP(val,min,max)(val<min?min:val>max?max:val)
#define LERP(A,B,C,D)((A*(D-C)+B*C)/D)

typedef union color{
struct {char b,g,r,a;};
signed int i;
unsigned int u;
}color;

color gray(int v){
  v,v,v,255
  color ret = INTT_COLOR(v,v,v,255);
}
#define GRAYALPHA(v,a){v,v,v,a}
#define RGB(r,g,b){b,g,r,255}
#define RGBA(r,g,b,a){b,g,r,a}
#define HEX(x){.intvalue = 0xFF##x}
#define UINT(x){.intvalue = x}


color hsb(int H, int S, int V) {
  int R, G, B;
  H *= 17;
  R = -1020+abs(H-3060);
  G =  2040-abs(H-2040);
  B =  2040-abs(H-4080);
  R = constrain(R, 0, 1020)-1020;
  G = constrain(G, 0, 1020)-1020;
  B = constrain(B, 0, 1020)-1020;

  R = ((R*S+102000)*V)/40000;
  G = ((G*S+102000)*V)/40000;
  B = ((B*S+102000)*V)/40000;

  color ret = {B,G,R,255};
  return ret;
}

main(){
color mycolor = HSB(240,100,100); // 360 100 100
printf("%x",mycolor);
}
