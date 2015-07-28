#include <unistd.h>
#include <stdlib.h>

int main() {
	char **args=malloc(sizeof(char*)*4);
	args[0]="gifsicle";
	args[1]="-I";
	args[2]="/home/derpy/Pictures/giphy/209.gif";
	args[3]=0;
	
	return execv("/usr/bin/gifsicle",args);
}
