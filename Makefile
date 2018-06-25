HEADERS = headers.h

server: main.o find_file_type.o response_function.o respond.o headers.h
	gcc -o server main.o find_file_type.o response_function.o respond.o

find_file_type.o: find_file_type.c
	gcc -c find_file_type.c

response_function.o: response_function.c
	gcc -c response_function.c

respond.o: respond.c
	gcc -c respond.c

main.o: main.c
	gcc -c main.c

clean:
	rm server *.o
