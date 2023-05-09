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
		perror("\nError calling fork");
		exit(1);
	case 0:
		printf("\nThis is the child running with PID: %d\n", getpid());
		sleep(3);
		execlp("ps", "ps", "-f", (char *)NULL);
		exit(1);
	default:
		int init_pid = getppid();
		printf("\ninit process PID: %d", init_pid);

		printf("\n\nThis is the parent running executing execlp with PID: %d\n", getpid());
		exit(0);
	}
}
