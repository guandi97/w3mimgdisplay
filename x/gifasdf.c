#include <unistd.h>

int childprocess(int fd);

int main() {
	int pipefd[2];
	int pipe(*pipefd);

	int pid=fork();
	if (pid!=0) {
		//first redirect std output to pipe
		return childprocess(pipefd[1]);
	}
	//redirect pipe output to stdout
	return 0;
}
int childprocess(int fd) {
	return execl(./bigboom.sh,"bigboom.sh");
}
