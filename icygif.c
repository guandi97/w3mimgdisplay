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
int gifsicleSet(struct gif_info *gif_info_init) {
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
