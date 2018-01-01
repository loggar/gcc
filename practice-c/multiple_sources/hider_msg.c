#include <stdio.h>

#include "hider_msg.h"
#include "encrypt.h"

int main() {
	char msg[80] = "This is a sample message.";

	encrypt(msg);
	printf("%s", msg);

	test1();
}

void test1() {
	printf("%s", "test1");
}

/*
λ gcc hider_msg.c encrypt.c -o hider_msg

λ hider_msg
Kwvl?vl?~?l~rosz?rzll~xz1
*/
