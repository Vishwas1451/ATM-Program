a : ATM.o server.o
	gcc ATM.o server.o

ATM.o : ATM.c server.h
	gcc -c atm.c
	
server.o : server.c server.h
	gcc -c server.c