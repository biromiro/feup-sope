all: ex5 ex5.stat

ex5: ex5.c
		gcc ex5.c -o ex5.out

ex5.stat: ex5.c
		gcc -static ex5.c -o exe.stat

clean:
		rm -f *.out *.stat
