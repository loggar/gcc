#makefile for hider_msg

hider_msg.o: hider_msg.c hider_msg.h encrypt.h
	gcc -c hider_msg.c

encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c

hider_msg: hider_msg.o encrypt.o
	gcc hider_msg.o encrypt.o -o hider_msg
