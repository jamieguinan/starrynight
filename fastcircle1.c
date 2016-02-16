#include <stdio.h>
#define N 22
#define W 386
#define H 320
#define SZ (W*H)
unsigned char I[SZ*3];
void d(int R,int G,int B,int x,int y,int r)
{int xx,yy,idx;
for(xx=-r;xx<r;xx++)
for(yy=-r;yy<r;yy++){
if (xx*xx+yy*yy<r*r){idx=x+xx+(y+yy)*W;if((x+xx<W)&&idx>0&&idx<SZ){I[idx*3]=R;I[idx*3+1]=G;I[idx*3+2]=B;}}
}
}
int v[N*6] = {
#include "v2.i"
};
#include "optimizer.c"
int main(){
int i,*p;for(i=0;i<(23*6);i+=6){p=&v[i];d(p[0],p[1],p[2],p[3],p[4],p[5]);}
FILE *f=fopen("o.ppm","wb");fprintf(f,"P6\n386 320\n255\n");fwrite(I,sizeof(I),1,f);fclose(f);
return(0);}
