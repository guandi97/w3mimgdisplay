#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct gif_info {
	int xx;
	int yy;
	int seq;	//number of images
	int delay;	//milliseconds
};

//query all commands from gifsicle
int gifsicleSet(char *gif,struct gif_info *gif_info_init) {
	int pfd[2];
	if(pipe(pfd)!=0) return 1;

	if(fork() {
		dup2(pdf[1],0);

		char **args=malloc(sizeof(sizeof(*char)*3);
		args[0]="gifsicle";
		args[1]="-I";
		args[2]=gif;
		args[3]=0;

		execv("/usr/bin/gifsicle",args);
		return 0;
	}

	char buf[2048];
	wait();
	
	int i=0;
	while(!(i+=read(pfd[0],&buff,2048-i)));
	
	{ 
		for(int c=0;c<2;c++) while(buff[i++]!=' ');
		int j=i;
		while(buffi++]!=' ');

		buff[i]=0;
		gif_info->seq=atoi(&buff[j]);
		buff[i]=' ';
	}

	for(i=i;i<2048;i++) {
		while(buff[i++]!=0x0a);
		
		switch(buff[i]) {

		case 'l':
			while(buff[i++]==' ');

			{
				for(int c=0;c<2;c++) while(buff[i++]!=' ');
				int j=i;
				while(buff[i++]!='x');
				buff[i]=0;
				gif_info->xx=atoi(buff[j]);
				buff[i]='x';

				j=++i;
				while(buff[i++]!='\n';
				buff[i]=0;
				gif_info->yy=atoi(buff[j]);
				buff[i]='\n';
			}
			
		case 'd': 
			while(buff[i++]==' ');

			{
				for(int c=0;c<4;c++) while(buff[i++]!=' ');
				int j=i;
				while(buff[i++]!='s');
				buff[i]=0;
				gif_info->delay=atoi(buff[j]);
				buff[i]='s';
				break;
			}
		}
	}
	
	
	return 0;
}
//check if gif, set up tmp, gifsicleSet, explode gif,simulate giphy call stack (0,4,3)
int gif_animate(char *gif,struct gif_info *gif_info_struct,int loop) {
	return 0;
}
int exeGif(char *gif) {
	//0
	DrawImage(gif,0);
	//4 - mod
	fflush(stdout);
	//3
	w_op->sync(w_op);
}

//test portion:
int main(int argc, char **argv) {
	int i;
	struct gif_info *gAnimate;
	gAnimate=malloc(sizeof(struct gif_info));
	
	if(i=gif_animate(*(argv+1),gAnimate)!=0) {
		return i;
	}

	printf("%d %d %d %d\n",gAnimate->xx,gAnimate->yy,gAnimate->seq,gAnimate->delay);

	return 0;
}
