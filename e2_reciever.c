#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#define fifo "fifo_file"

// run this in a separate terminal together with sender
// reader

int main(){
	int fd;
	char buf[BUFSIZ];

	memset(buf, 0, BUFSIZ);

	fd = open(fifo, O_RDONLY);

	read(fd, buf, sizeof buf);

	fprintf(stderr, "Msg from writer : %s\n", buf);

	return 0;
}
