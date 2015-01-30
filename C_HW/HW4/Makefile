trietest: trie.c trie.h trietest.c
	gcc -g -o $@ -Wall -pedantic -std=c11 $(filter %.c,$^) || rm $@


.phony: clean
clean: 
	-rm trietest

