#define _GNU_SOURCE
#include <stdio.h>

int main() {
	char **swat;
	int der=asprintf(swat,"%s%d\n","lolz",12);
	printf("%d\n",der);
	printf("%s\n",*swat);
}
