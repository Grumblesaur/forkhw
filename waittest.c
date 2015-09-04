#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {
	pid_t rc = fork();
	
	if (rc == 0) {
		printf("CHILD: Hello!\n");
		exit(0);
	} else {
		int status;
		wait(NULL);
		printf("PARENT: Goodbye.\n");
	}
	
	return 0;
}
