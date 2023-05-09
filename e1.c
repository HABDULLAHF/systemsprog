#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	pid = fork();

	switch(pid){
	case -1:
		perror("Error calling fork");
		exit(1);
	case 0:
		printf("\nThis is the child running with PID: %d\n\n", getpid()); 
		exit(0);
	default:
		printf("\nThis is the parent running with PID: %d\n", getpid());
		sleep(1);
		execlp("ps", "ps", "-l", (char *)NULL);
	}
}
