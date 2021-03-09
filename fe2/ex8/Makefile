all: ex8 ex8.stat

ex8: ex8.c
		gcc ex8.c -o ex8.out

ex8.stat: ex8.c
		gcc -static ex8.c -o exe.stat

clean:
		rm -f *.out *.stat
