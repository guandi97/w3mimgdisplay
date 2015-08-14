int intostr(char*,int,int);

int intostr(char *str,int dig,int pre) {
	int i;
	int p;

	for(i=1,p=0;dig/i!=0;i*=10,p++);
	i/=10;
	if(p>pre) return -1;

	int j=0,k;
	for(p=p;p<pre;p++,j++) *(str+j)=48;
	
	for(j=j,k=0;i!=0;i/=10,j++) {
		k=(dig/i);
		dig-=k*i;
		*(str+j)=k+48;
	}
	return j;
	
}
