#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// handlers have void return type.
void diediedie(int sig) // signal handler, OS passes the signal to the handler.
{
	puts("Bye\n");
	exit(1);
}

// this is the function to register a handler.
int catch_signal(int sig, void (*handler)(int))
{
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(sig, &action, NULL);
}

int main()
{
	if (catch_signal(SIGINT, handle_interrupt) == -1)
	{
		fprintf(stderr, "Can't map the handler");
		exit(2);
	}

	char name[30];
	printf("Enter your name: ");
	fgets(name, 30, stdin);
	printf("Hello %s\n", name);
	return 0;
}