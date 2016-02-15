#include <stdio.h>
#include <string.h>
#include <math.h>

#define W 386
#define H 320
#define SZ (W*H)

unsigned char image[SZ];
unsigned char value;

void disk(int v, int x, int y, int r)
{
  value = v;
  while (r) {
    float dp = 1/(6.3*r);
    float p;
    for (p=0; p < 6.3; p+=dp) {
      int xo = r*cos(p);
      int offset = x + xo + floor(y + r*sin(p))*W;
      if ((x+xo < W) && offset > 0 && offset < SZ) { image[offset] = value; }
    }
    r -= 1;
 }
}

int main(int argc, char * argv[]) {
  disk(113,W/2,H/2,W);
  disk(77,50,40,50);
  disk(162,130,171,25);
  disk(153,352,57,38);
  disk(70,300,1120,900);
  disk(42,95,275,40);
  
  printf("P5\n386 320\n255\n");
  fwrite(image, sizeof(image), 1, stdout);
  return 0;
}
