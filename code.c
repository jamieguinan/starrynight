#include <stdio.h>
#include <string.h>
#include <math.h>

#define W 386
#define H 320
#define SZ (W*H)

unsigned char image[SZ];
unsigned char value;
float m,x,y,dm,dx,dy;
float K=8;
float dk=1;
void segment()
{
  int i;
  for (i=0; i < K; i++) {
    int offset = x + (i*dx) + floor(y +(i*dy)) * W;
    //fprintf(stderr, "offset=%d dx=%.2f dy=%.2f\n", offset, dx, dy);
    if (offset > 0 && offset < SZ) { image[offset] = value; }
  }
  x += dx*(K+1+dm);
  y += dy*(K+1+dm);
  K *= dk;
}

void swirl(int n)
{
  if (n) {
    dx = cos(m);
    dy = sin(m);
    segment();
    m += dm;
    dm *= 0.9965;
    swirl(n-1);
  }
}

int main(int argc, char * argv[]) {
  memset(image, 98, sizeof(image));
  
  value=162;
  m=0.5;dm=0.7;x=130;y=171-10;
  swirl(200);

  K=2;dk=1.0005;m=0.5;dm=0.7;x=129;y=170;
  swirl(280);
  
  printf("P5\n386 320\n255\n");
  fwrite(image, sizeof(image), 1, stdout);
  return 0;
}
