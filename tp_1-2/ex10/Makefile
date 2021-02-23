all: ex10 ex10.stat

ex10: ex10.c
		gcc ex10.c -o ex10.out

ex10.stat: ex10.c
		gcc -static ex10.c -o exe.stat

clean:
		rm -f *.out *.stat
