#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
printf("PPID: %d", getppid());
return 0;
}
