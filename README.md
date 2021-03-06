# starrynight
Entry for http://codegolf.stackexchange.com/questions/69930/paint-starry-night-objectively-in-1kb-of-code/

I didn't win the contest, but I'm happy with the score I got, and I subjectively like the resulting image:

<img src="code6.png">

I'm putting this in a public GIT repository for fun, and as an exercise. I've used GIT a lot over the past few years, but never had reason to publish anything.

There are several versions of `code.c` that show the evolution of my solution, 2 of which are worth noting.

`code5.c` contains the "scaffolding" code that I mention in my entry description. It includes the file `v.i` with the R,G,B,x,y,r values, modifies whichever fields are uncommented, iterating values {-10,10}, saving the values that produced the lowest score, then writes a new version of the array to `v.i`. Re-compile and repeat.

`code6.c` is my final entry, weighing in at 999 bytes.

`validate.py` is the original validator by the post author.

`cvalidate.c` is a C version of the validator that I wrote for speed.

StackExchange user @neocpp pointed out a faster filled-circle algorithm in a comment, and I found an example of it here,

http://stackoverflow.com/a/1237519/488095

So I wrote a new version using this other algorithm, and not only does it run 170 times faster than my trig function version, it is smaller and made room to add 1 more circle. So there are now 2 additional versions.

`fastcircle1.c` includes `optimizer.c` and regnerates `v2.i`.

`fastcircle2.c` is the standalone version, and the contents of `v2.i` should be pasted into the `v[]` array.

Here's the general idea of how it works,

    $ make cvalidate
    $ make fastcircle1 && ./fastcircle1 && ./cvalidate o.ppm
    $ ./fastcircle1 optimize
    $ make fastcircle1 && ./fastcircle1 optimize && ./cvalidate o.ppm

Repeating the last line will tick down the score slightly with each pass, up to a point where people better at maths than me would say it reaches "local minima".
