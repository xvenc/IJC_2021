# 
# Makefile
# Solution for IJC-DU2, assignment a), b), 9.4.2020
# Author: Václav Korvas ,VUT FIT 1BIT (xkorva03)
# Compiled: gcc 10.2.1
# Makefile for compilin and linking files
#


.PHONY=all clean
CFLAGS=-std=c99 -pedantic -Wall -Wextra -g
CC=gcc
TARGET=tail wordcount wordcount-dynamic libhtab.a libhtab.so
HEADER_F=htab.h htab_and_item_structures.h
HTAB_OBJECT_F=htab_init.o htab_clear.o htab_free.o htab_hash_function.o htab_lookup_add.o htab_bucket_count.o htab_size.o htab_find.o htab_erase.o htab_move.o htab_for_each.o


all: $(TARGET)
################ FILES TO BE RUN ######################

tail: tail.o
	$(CC) -o $@ $^

wordcount: wordcount.c io.c libhtab.a
	$(CC) -static $^ -L. -lhtab -o $@

wordcount-dynamic: wordcount.c io.c libhtab.so
	$(CC) $^ -Wl,-rpath,'.' -L. -lhtab -o $@

############### STATIC LIBRARY ########################

libhtab.a: $(HTAB_OBJECT_F)
	ar rcs libhtab.a $(HTAB_OBJECT_F)

############### DYNAMIC LIBRARY ########################

libhtab.so: $(HTAB_OBJECT_F) 
	$(CC) -fPIC -shared $(HTAB_OBJECT_F) -o libhtab.so

############### OBJECT FILES ###########################

tail.o: tail.c
	$(CC) $(CFLAGS) -c  $^

htab_init.o: htab_init.c $(HEADER_F)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_lookup_add.o: htab_lookup_add.c $(HEADER_F)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_hash_function.o: htab_hash_function.c $(HEADER_F)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_free.o: htab_free.c $(HEADER_F)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_clear.o: htab_clear.c $(HEADER_F)
	$(CC) $(CFLAGS) -fPIC  -c $<

htab_size.o: htab_size.c $(HEADER_F)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_bucket_count.o: htab_bucket_count.c $(HEADER_F)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_find.o: htab_find.c $(HEADER_F)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_erase.o: htab_erase.c $(HEADER_F)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_move.o: htab_move.c $(HEADER_F)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_for_each.o: htab_for_each.c $(HEADER_F)
	$(CC) $(CFLAGS) -fPIC -c $<

io.o: io.c io.h
	$(CC) $(CFLAGS) -c $<


wordcount.o: wordcount.c htab.h io.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)

zip:
	zip xkorva03.zip *.c *.h Makefile
