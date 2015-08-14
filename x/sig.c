#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	char buff[12];
	int fd=open("209.gif",O_RDONLY);
	int err=read(fd,buff,3);
	printf("%c%c%c %d\n",buff[0],buff[1],buff[2],err);

	return 0;
}
