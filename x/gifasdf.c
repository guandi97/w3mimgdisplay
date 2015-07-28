#include <unistd.h>
#include <stdio.h>

int childprocess(int fd);

int main() {
	int pipefd[2];
	pipe(pipefd);

	int pid=fork();
	if (pid!=0) {
		//first redirect std input to pipe
		dup2(pipefd[1],0);
		return childprocess(pipefd[1]);
	}
	//redirect pipe output to stdout
	dup2(pipefd[0],1);

	//test if need?
	//fsync(1);
	return 0;
}
int childprocess(int fd) {
	
	return execl("./bigboom.sh","bigboom.sh");
}
