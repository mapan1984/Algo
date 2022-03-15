default: run

word_frequency.o: word_frequency.c
	gcc -c -Wall -Werror word_frequency.c

word_frequency: word_frequency.o
	gcc -Wall -o word_frequency word_frequency.c

.PHONY: clean run

run: word_frequency
	./word_frequency

clean:
	rm -rf *.o *.so .tags word_frequency
