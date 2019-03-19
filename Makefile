.PHONY :
	stringUtils
	test
	objects

clean :
	rm main_writeFile
	rm stringsUtils.o

objects :
	make stringsUtils

stringsUtils :
	cc -c stringsUtils.c -o stringsUtils.o

test_stringsUtils :
	cc stringsUtils.o tests/test_stringsUtils.c -o tests/test_stringsUtils
	./tests/test_stringsUtils

test :
	make stringsUtils
	make tests
	make clean

writeFile :
	cc

tests :
	make writeFile
	cd ./tests/
	make test_stringsUtils
	cd ..
