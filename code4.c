#include <stdio.h>
#include <math.h>
#define W 386
#define H 320
#define SZ (W*H)
unsigned char img[SZ*3];
void d(int R,int G,int B,int x,int y,int r)
{
 while (r) {
  float p;
  for (p=0;p<6.3;p+=(1/(6.3*r))) {
   int xo=r*cos(p);
   int idx=x+xo+floor(y+r*sin(p))*W;
   if ((x+xo<W)&&idx>0&&idx<SZ) {
    img[idx*3]=R;
    img[idx*3+1]=G;
    img[idx*3+2]=B;
   }
  }
  r-=1;
  if (y-r>=H)return;
 }
}

#include <stdlib.h>
int delta = 0;
int target_line = 0;
int _tweak(int value, int line)
{
  fprintf(stderr, "%d\n", line);
  if (line == target_line) {
    return value + delta;
  }
  else {
    return value;
  }
}

#define f(x) (x)
#define g(x) _tweak(x, __LINE__)

int main(int argc, char * argv[]) {
  if (argc == 3) {
    target_line = atoi(argv[1]);
    delta = atoi(argv[2]);
  }
  d(
    (89),
    g(114),
    (142),
    W/2,H/2,W);
  d(
    (57),
    g(72),
    (131),
    (50),
    (40),
    (51));
  d(
    (60),
    g(77),
    (131),
    (175),
    -(240),
    (300));
  d(
    (158),
    g(168),
    (162),
    (130),
    (171),
    (24));
  d(
    (118),
    g(133),
    (120),
    (28),
    (13),
    (18));
  d((129),
    g(133),
    (120),
    (81),
    (56),
    (14));
  d((156),
    g(171),
    (123),
    (352),
    (57),
    (42));
  d((184),
    g(164),
    (45),
    (353),
    (57),
    (22));
  d((183),
    g(181),
    (123),
    (360),
    (52),
    (15));
  d((89),
    g(113),
    (149),
    (187),
    (108),
    (60));
  d((134),
    g(155),
    (153),
    (370),
    (225),
    (100));
  d((47),
    g(40),
    (55),
    (370),
    (220),
    (55));
  d((50),
    g(37),
    (82),
    (350),
    (1400),
    (1203));
  d((61),
    g(72),
    (90),
    (361),
    (269),
    (77));
  d((50),
    g(58),
    (72),
    (240),
    (269),
    (60));
  d((33),
    g(32),
    (29),
    (95),
    (275),
    (65));
  d((37),
    g(32),
    (29),
    (66),
    (191),
    (29));
  d((41),
    g(32),
    (29),
    (65),
    (143),
    (20));
  d((39),
    g(32),
    (29),
    (67),
    (110),
    (12));
  d((108),
    g(127),
    (124),
    (232),
    (29),
    (19));
  printf("P6\n386 320\n255\n");
  fwrite(img, sizeof(img), 1, stdout);
  return 0;
}
