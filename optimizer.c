void render(void)
{
  FILE * f = fopen("o.ppm", "wb");
  int i; for(i=0;i<(N*6);i+=6){d(v[i],v[i+1],v[i+2],v[i+3],v[i+4],v[i+5]);}
  fprintf(f,"P6\n386 320\n255\n");
  fwrite(I,sizeof(I),1,f);
  fclose(f);
}

float validate(void)
{
  float d;
  char buffer[256];
  FILE * p = popen("./cvalidate o.ppm", "r");
  if (fgets(buffer, sizeof(buffer), p) == NULL) perror("fgets");
  pclose(p);
  sscanf(buffer, "%f", &d);
  return d;
}

float score = 20000;
char * strs[] = {"red", "green", "blue", "x", "y", "radius"};
void optimize(int n)
{
  int i;
  float tmp;
  int v0, vbest;
  fprintf(stderr, "optimizing value at offset %d (%s)\n", n, strs[n%6]);
  vbest = v0 = v[n];
  for (i=-10;i<10;i+=1) {
    v[n] = v0+i;
    render();
    tmp=validate();
    //fprintf(stderr, "score [%d] = %f\n", i, tmp);
    if (tmp < score) {
      score = tmp;
      vbest = v0+i;
    }
  }
  v[n] = vbest;
  fprintf(stderr, "best score = %f, value %d\n", score, vbest);
}

void dump(void)
{
  int i;
  FILE * f = fopen("v2.i", "w");
  for (i=0; i<N*6; i+=6) {
    fprintf(f, "%d,%d,%d,%d,%d,%d,\n",
	    v[i],v[i+1],v[i+2],v[i+3],v[i+4],v[i+5]);   
  }
  fclose(f);
}

#include <string.h>
int main(int argc, char * argv[]) {
  if (argc == 2 && strcmp(argv[1], "optimize")==0) {
    int i;
    for(i=0*6; i < N*6; i+=6) {
      optimize(i+0);		/* red */
      optimize(i+1);		/* green */
      optimize(i+2);		/* blue */
      optimize(i+3);		/* x */
      optimize(i+4);		/* y */
      optimize(i+5);		/* radius */
    }
    dump();
  }
  render();
  return 0;
}

/* Ignore next declaration of main() */
#define main notmain
