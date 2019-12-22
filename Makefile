CC=gcc
FLAGS= -Wall -g

all:libisort.so libtxtfind.so mainSortd mainTxtd

isortd:libisort.so

libisort.so:isort.o isort.h
	$(CC) -shared -o libisort.so isort.o

isort.o: isort.c isort.h 
	$(CC) -Wall -fPIC -c isort.c

mainSortd:mainSort.o libisort.so
	$(CC) $(FLAGS) -o isort mainSort.o ./libisort.so 

mainSort.o:mainSort.c isort.h
	$(CC) -Wall -c mainSort.c

txtfindd:libtxtfind.so

libtxtfind.so:txtfind.o	txtfind.h
	$(CC) -shared -o libtxtfind.so  txtfind.o

txtfind.o: txtfind.c txtfind.h 
	$(CC) -Wall -fPIC -c txtfind.c

mainTxtd:mainTxt.o libtxtfind.so
	$(CC) $(FLAGS) -o txtfind mainTxt.o ./libtxtfind.so 

mainTxt.o:mainTxt.c txtfind.h
	$(CC) -Wall -c mainTxt.c

.PHONY:clean all txtfindd isortd

clean:
	rm -f *.o  *.so isort txtfind
