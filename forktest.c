#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {
	int x = 100;
	printf("x is declared 100 before fork.\n");
	pid_t rc = fork();
	
	if (rc == 0) {
		x *= 2;
		printf("CHILD: I changed x to %d.\n", x);
		printf("(Multiplied by two.)\n\n");
		exit(0);
	} else {
		x *= 3;
		int stat;
		(void) waitpid(rc, &stat, 0);
		printf("PARENT: I changed x to %d.\n", x);
		printf("(Multiplied by three.)\n\n");
	}
	return 0;
}
