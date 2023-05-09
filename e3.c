#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	sigset_t set;
	sigaddset(&set, SIGINT);	// Blocks SIGINT signal i.e CTRL-C
	//sigaddset(&set, SIGTSTP);	// Blocks SIGTSTP signal i.e CTRL-Z

	if(sigprocmask(SIG_SETMASK, &set, NULL) == -1) // Returns -1 if unsuccessfull in blocking
		perror("sigprocmask");

	while(1){
		fprintf(stderr, "ZzzZZz...\t");        // Only terminates when CTRL-\ signal is sent
		sleep(2);
	}

	return 0;

}
