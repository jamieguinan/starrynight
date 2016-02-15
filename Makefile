run: cvalidate grayvalidate code5
	@echo -n "Byte count: ";	wc -c code5.c
	@./code5 optimize
	@ make code5
	@./code5
	@echo -n "Score: "; python validate.py output.ppm
#	@echo -n "Score: "; ./cvalidate output.pgm
#	@echo -n "Score: "; ./grayvalidate output.pgm
	@gimp output.ppm

code: code.c
	gcc code.c -o code -lm

code2: code2.c
	gcc code2.c -o code2 -lm

code3: code3.c
	gcc code3.c -o code3 -lm

code4: code4.c
	gcc -Wall -O2 code4.c -o code4 -lm

code5: code5.c v.i
	gcc -Wall -O2 code5.c -o code5 -lm

code6: code6.c
	gcc -Wall -O2 code6.c -o code6 -lm

cvalidate: validate.c
	gcc -Wall validate.c -o cvalidate

grayvalidate: grayvalidate.c
	gcc -Wall grayvalidate.c -o grayvalidate
