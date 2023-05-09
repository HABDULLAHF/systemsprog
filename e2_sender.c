#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#define fifo "fifo_file"

// run this in separate terminal with reciever
// writer

int main(){
	int fd;
	char buf[BUFSIZ];

	memset(buf, 0, BUFSIZ);

	mkfifo(fifo, 0777);

	fd = open(fifo, O_WRONLY);

	strcpy(buf, "Ubuntu 7.10");

	write(fd, buf, strlen(buf));

	return 0;
}
