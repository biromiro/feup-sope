all: ex12 ex12.stat

ex12: ex12.c
		gcc ex12.c -o ex12.out

ex12.stat: ex12.c
		gcc -static ex12.c -o exe.stat

clean:
		rm -f *.out *.stat
