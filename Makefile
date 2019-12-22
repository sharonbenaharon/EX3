CC=gcc
FLAGS= -Wall -g

all:isortd mainSortd mainSorts isorts txtfindd mainTxtd mainTxts txtfinds

isorts:libisort.a

isortd:libisort.so

libisort.a:isort.o isort.h
	 ar rcs libisort.a isort.o isort.h

libisort.so:isort.o	isort.h
	$(CC) -shared -o libisort.so  isort.o

isort.o: isort.c isort.h 
	$(CC) -fPIC -c isort.c

mainSorts:mainSort.o libisort.a
	$(CC) $(FLAGS) -o  mainSorts mainSort.o libisort.a 

mainSortd:mainSort.o libisort.so
	$(CC) $(FLAGS) -o mainSortd mainSort.o ./libisort.so 

mainSort.o:mainSort.c isort.h
	$(CC) -c mainSort.c


txtfinds:libtxtfind.a

txtfindd:libtxtfind.so

libtxtfind.a:txtfind.o txtfind.h
	 ar rcs libtxtfind.a txtfind.o txtfind.h

libtxtfind.so:txtfind.o	txtfind.h
	$(CC) -shared -o libtxtfind.so  txtfind.o

txtfind.o: txtfind.c txtfind.h 
	$(CC) -fPIC -c txtfind.c

mainTxts:mainTxt.o libtxtfind.a
	$(CC) $(FLAGS) -o  mainTxts mainTxt.o libtxtfind.a 

mainTxtd:mainTxt.o libtxtfind.so
	$(CC) $(FLAGS) -o mainTxtd mainTxt.o ./libtxtfind.so 

mainTxt.o:mainTxt.c txtfind.h
	$(CC) -c mainTxt.c
.PHONY:clean 

clean:
	rm -f *.o *.a *.so mainSorts mainSortd f *.o *.a *.so mainTxts mainTxtd
