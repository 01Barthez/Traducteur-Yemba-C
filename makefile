all:
	gcc -o traducteur *.c

run:
	./traducteur

clean:
	rm -f traducteur