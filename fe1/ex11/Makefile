all: ex11 ex11.stat

ex11: ex11.c
		gcc ex11.c -o ex11.out

ex11.stat: ex11.c
		gcc -static ex11.c -o exe.stat

clean:
		rm -f *.out *.stat
