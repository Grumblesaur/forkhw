#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {
	int x = 100;
	printf("x is declared 100 before fork.\n");
	int rc = fork();
	
	if (rc == 0) {
		x *= 2;
		printf("CHILD: I changed x to %d.\n", x);
		printf("(Multiplied by two.)\n\n");
		exit(0);
	} else {
		x *= 3;
		printf("PARENT: I changed x to %d.\n", x);
		printf("(Multiplied by three.)\n\n");
	}
	return 0;
}
