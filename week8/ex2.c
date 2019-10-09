#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

#define MB 1048576

int main() {
	char *k;
	for (int i = 0; i < 10; i++) {
		k = (char*)malloc(10 * MB);
		memset(k, 0, 10 * MB);
		sleep(1);
	}
	return 0;
}