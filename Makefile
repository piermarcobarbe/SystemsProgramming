
CFLAGS=-Wall -g
#.PHONY: all


.PHONY :
	test
	reset
	clean


clean:
	rm tests/test_arrayListString
	rm tests/test_readFile
	rm tests/test_stringsUtils
	rm tests/test_writeFile

reset:
	rm -rf txts/
	unzip -o txts.zip;


test:
	cc tests/test_arrayListString.c arrayListString.c stringsUtils.c -o tests/test_arrayListString;
	./tests/test_arrayListString;

	cc tests/test_stringsUtils.c stringsUtils.c arrayListString.c -o tests/test_stringsUtils;
	./tests/test_stringsUtils;

	cc tests/test_readFile.c arrayListString.c stringsUtils.c readFile.c writeFile.c -o tests/test_readFile;
	./tests/test_readFile;

	cc tests/test_writeFile.c arrayListString.c stringsUtils.c readFile.c writeFile.c -o tests/test_writeFile;
	./tests/test_writeFile;



