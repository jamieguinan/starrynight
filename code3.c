#include <stdio.h>
#include <math.h>
#define W 386
#define H 320
#define SZ (W*H)
unsigned char image[SZ*3];
void d(int R,int G,int B,int x,int y,int r)
{
  while (r) {
    float dp=1/(6.3*r);
    float p;
    for (p=0;p<6.3;p+=dp) {
      int xo=r*cos(p);
      int offset=x+xo+floor(y+r*sin(p))*W;
      if ((x+xo<W)&&offset>0&&offset<SZ) {
	image[offset*3]=R;
	image[offset*3+1]=G;
	image[offset*3+2]=B;
      }
    }
    r-=1;
    if (y-r>=H)return;
 }
}

int main(int argc, char * argv[]) {
  d(71,104,148,W/2,H/2,W);
  d(48,67,131,50,40,55);
  d(48,67,131,175,-240,300);
  d(162,162,162,130,171,25);
  d(129,143,120,28.,13,17);
  d(174,181,123,352,57,38);
  d(88,113,149,187,108,60);
  d(138,155,153,370,225,100);
  d(32,37,82,350,1400,1200);
  d(60,73,90,338,260,50);
  d(47,58,72,240,269,50);
  d(28,32,29,95,275,65);
  d(28,32,29,66,192,30);
  printf("P6\n386 320\n255\n");
  fwrite(image, sizeof(image), 1, stdout);
  return 0;
}
