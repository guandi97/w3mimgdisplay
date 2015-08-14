#include <stdio.h>
#include "der.h"

int main() {
	char der[32]={0};
	intostr(der,1234,6);
	printf("%s\n",der);
	
	return 0;
}
