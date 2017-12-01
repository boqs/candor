all:
	gcc -o candor main.c monome_cache.c ficus/libficus.c ficus/rtqueue.c -llo -lsndfile -lasound -ljack -lpthread -lmonome -Ificus
install:
	cp candor /opt/bin/candor
uninstall:
	rm /opt/bin/candor
clean: 
	rm candor
tags:
	find . ../liblo/ ../libmonome -name "*.[ch]" | etags -
