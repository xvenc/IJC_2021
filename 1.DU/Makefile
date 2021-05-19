# 
#Makefile
# Řešení IJC-DU1, příklad a), b), 23.3.2020
# Autor: Václav Korvas ,VUT FIT 1BIT (xkorva03)
# Přeloženo: gcc 10.2.1
# Makefile pro preklad a linkovani jednotlivych souboru
#

CFLAGS= -Wall -O2 -Wextra -pedantic -std=c11 -g
LDFLAGS= -lm
.PHONY= all clean run zip
TARGET= primes primes-i steg-decode
SHELL= /bin/bash

all: $(TARGET)


primes: primes.o eratosthenes.o error.o bitset.o
	gcc $(CFLAGS) bitset.o primes.o error.o eratosthenes.o -o primes $(LDFLAGS) 

primes-i: primes-i.o eratosthenes.o error.o bitset.o
	gcc -DUSE_INLINE $(CFLAGS) bitset.o primes-i.o error.o eratosthenes.o -o  primes-i $(LDFLAGS) 

steg-decode: error.o ppm.o steg-decode.o bitset.o eratosthenes.o
	gcc $(CFLAGS) error.o ppm.o steg-decode.o bitset.o eratosthenes.o -o steg-decode $(LDFLAGS)
##########################################


error.o: error.h error.c
	gcc $(CFLAGS) -c error.c -o error.o

eratosthenes.o: eratosthenes.c bitset.h error.h eratosthenes.h
	gcc $(CFLAGS) -c eratosthenes.c -o eratosthenes.o 

primes.o: primes.c eratosthenes.h bitset.h error.h
	gcc $(CFLAGS) -c primes.c -o primes.o

primes-i.o: primes.c eratosthenes.h bitset.h error.h
	gcc -DUSE_INLINE $(CFLAGS) -c primes.c -o primes-i.o

bitset.o: bitset.c bitset.h
	gcc $(CFLAGS) -c bitset.c -o bitset.o

ppm.o: ppm.c ppm.h
	gcc $(CFLAGS) -c ppm.c -o ppm.o

steg-decode.o: steg-decode.c ppm.h error.h bitset.h eratosthenes.h
	gcc $(CFLAGS) -c steg-decode.c -o steg-decode.o $(LDFLAGS)
##############################################


clean:
	@echo "Removing all .o files and executable files"
	rm -f *.o $(TARGET)

run: primes primes-i 
	ulimit -s 70000 && ./primes
	ulimit -s 70000 && ./primes-i

zip: 
	zip xkorva03.zip *.c *.h Makefile
