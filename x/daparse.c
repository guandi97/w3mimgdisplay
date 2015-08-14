#include <stdio.h>

int main() {
	char str[]="7;1;0;0;300;100;;;;;209.gif\n3;";
	printf("%s\n",str);

	int i,g;
	for(i=0;str[i]!=0 && str[i]!='\n';i++) if(str[i]==';') printf("%d\n",i);
	printf("%d\n",i);

	return 0;
}
