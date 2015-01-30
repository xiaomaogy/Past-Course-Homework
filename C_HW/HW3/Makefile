all: analyse

.phony: clean
clean:
	-rm analyse

analyse: analyse.c
	gcc -g -o $@ -Wall -Werror -pedantic -std=c11 $^


