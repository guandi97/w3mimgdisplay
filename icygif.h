#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct _gif_info {
	int xx;
	int yy;
	int seq;	//number of images
	int delay;	//milliseconds
} gif_info;


int gifsicleSet(char*,gif_info*);
int gif_animate(char*,gif_info*,int);
int intostr(char*,int,int);
int execGif(int,gif_info*);
int gifStack(char*);

//query all commands from gifsicle
int gifsicleSet(char *gif,gif_info *gif_info_init) {
	int pfd[2];
	if(pipe(pfd)!=0) return 1;

	if(fork()) {
		printf("fork\n");
		dup2(pfd[1],1);

		char **args=malloc(sizeof(sizeof(char*)*4));
		args[0]="gifsicle";
		args[1]="-I";
		args[2]=gif;
		args[3]=0;

		execv("/usr/bin/gifsicle",args);
		return 0;
	}

	char buff[2048];
	int stat_lock;
	wait(&stat_lock);
	
	int i=0;
	while(!(i+=read(pfd[0],&buff,2048-i)));
	
	{ 
		for(int c=0;c<2;c++) while(buff[i++]!=' ');
		int j=i;
		while(buff[i++]!=' ');

		buff[i]=0;
		gif_info_init->seq=atoi(&buff[j]);
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
				gif_info_init->xx=atoi(&buff[j]);
				buff[i]='x';

				j=++i;
				while(buff[i++]!='\n');
				buff[i]=0;
				gif_info_init->yy=atoi(&buff[j]);
				buff[i]='\n';
			}
			
		case 'd': 
			while(buff[i++]==' ');

			{
				for(int c=0;c<4;c++) while(buff[i++]!=' ');
				int j=i;
				while(buff[i++]!='s');
				buff[i]=0;
				gif_info_init->delay=(int)atof(&buff[j])*100;
				buff[i]='s';
				break;
			}
		}
	}
	
	return 0;
}
//check if gif, set up tmp, gifsicleSet, explode gif,simulate giphy call stack (0,4,3)
int gif_animate(char *str,gif_info *gif_info_struct,int loop) {
	//gif name parse
	char *gif=calloc(sizeof(char)*96,1);
	{
		int i;
		int g;
		for(i=0;str[i]!=0 && str[i]!='\n';i++) if(str[i]==';') g=i;

		memcpy(gif,&str[g+1],i-g-1);
	}

	//check gif
	int fd=open(gif,O_RDONLY);
	char buff[3];
	if(read(fd,buff,3)==-1) return errno;
	printf("%c%c%c\n",buff[0],buff[1],buff[2]);
	if(buff[0]!='G' && buff[1]!='I' && buff[2]!='F') return 1;
	printf("animate\n");

	//make tmp dir
	if(!mkdir("/tmp/gifsicle",S_IRWXU) && errno!=EEXIST) return errno;

	uid_t uid=getuid();
	char gdir[]="/tmp/gifsicle/xxxxxxxxxxxxxxxx";
	int d=sizeof(gdir)-16;
	d+=intostr(&gdir[d],uid,0)+1;
	gdir[d]=0;
	
	if(!mkdir(gdir,S_IRWXU)) return errno;

	//gifsicleSet
	
	{
		int err;
		if(!(err=gifsicleSet(gif,gif_info_struct))) return err;
	}

	//chdir
	char gpath[48]={0};
	memcpy(gpath,gdir,d);
	memcpy(&gpath[d],"imgseq",6);

	if(!symlink(gif,gpath)) return errno;
	if(!chdir(gdir)) return errno;
	
	//explode gif
	char **args=malloc(sizeof(char*)*4);
	args[0]="gifsicle";
	args[1]="-e";
	args[2]=gpath;
	args[3]=0;

	execv("/usr/bin/gifsicle",args);

	{
		int err;
		if(!(err=execGif(loop,gif_info_struct))) return err;
	}
	
	return 0;
}
int execGif(int loop,gif_info *ginfo) {
	//opti: push stack
	int seq=ginfo->seq;
	int delay=ginfo->delay;

	char **imgseq=malloc(sizeof(char*)*seq);
	imgseq[0]="imgseq.000";

	for(int i=1;i<seq;i++) {
		imgseq[i]=malloc(11);
		memcpy(imgseq[i],imgseq[0],11);
		intostr(&imgseq[i][8],i,3);
	}

	for(int i=0;i<loop;i++) {
		gifStack(imgseq[i]);
		usleep(delay);
	}
	
	while(loop) {
		for(int i=0;i<seq;i++) {
			gifStack(imgseq[i]);
			usleep(delay);
		}
	}

	return 0;
}
int gifStack(char *gif) {
	printf("stack\n");
	//0
	DrawImage(gif,0);
	//4 - mod
	fflush(stdout);
	//3
	w_op->sync(w_op);

	return 0;
}
int intostr(char *str,int dig,int pre) {
	int i;
	int p;

	for(i=1,p=0;dig/i!=0;i*=10,p++);
	i/=10;
	if(p>pre || pre!=0) return -1;

	int j=0,k;
	for(p=p;p<pre;p++,j++) *(str+j)=48;
	
	for(j=j,k=0;i!=0;i/=10,j++) {
		k=(dig/i);
		dig-=k*i;
		*(str+j)=k+48;
	}
	return j;
	
}
