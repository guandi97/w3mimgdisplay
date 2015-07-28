#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char buff[1024];
	int i=0;
	while(!(i+=read(0,buff,1024-i)));
	buff[i]=0;

	//first test: read
	printf("%s\n%d\n",buff,i);

	//2nd test: parse, and positioning

	
	return 0;
}
