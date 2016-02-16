#include <stdio.h>

unsigned char original[500000];
unsigned char sample[500000];
int main(int argc, char * argv[])
{
  if (argc != 2) {
    fprintf(stderr, "Usage: %s file.ppm\n", argv[0]);
    return 1;
  }
  char line[256];
  int i;
  long int score = 0;
  FILE * f = fopen("ORIGINAL.ppm", "r");
  fgets(line, sizeof(line), f);
  fgets(line, sizeof(line), f);
  fgets(line, sizeof(line), f);
  fread(original, 386*320*3, 1, f);
  fclose(f);

  f = fopen(argv[1], "r");
  fgets(line, sizeof(line), f);
  fgets(line, sizeof(line), f);
  fgets(line, sizeof(line), f);
  fread(sample, 386*320*3, 1, f);
  fclose(f);

  for (i=0; i < 386*320*3; i++) {
    int c = (int)(original[i]) - (int)(sample[i]);
    // printf("%ld %d %d\n", score, c, c*c);
    score += (c*c);
  }

  float fscore = score/(255.0*255.0);

  printf("%f\n", fscore);
    
  return 0;
}
