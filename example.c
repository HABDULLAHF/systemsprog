#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void catchit(int);

int main(){
	struct sigaction sa;	// object sa created of structure sigaction
	sa.sa_handler = catchit();	// catchit func is called and returne
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);

	while(1){
		fprintf(stderr, "ZzzZZz...\t");
		sleep(2);
	}

	return 0;
}

void catchit(int sig){
	fprintf(stderr, "%d\n", sig);
}
