#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/resource.h>

#define MB 1048576

int main() {
	char *k;
	struct rusage r;
	for (int i = 0; i < 10; i++) {
		k = (char*)malloc(10 * MB);
		memset(k, 0, 10 * MB);

		getrusage(RUSAGE_SELF, &r);
        printf("*****************************\n");
		printf("Max Resident Set Size: %ld\n", r.ru_maxrss);
		printf("Integral Shared Text Memory Size: %ld\n", r.ru_ixrss);
		printf("Integral Unshared Data Size: %ld\n", r.ru_idrss);
		printf("Integral Unshared Stack Size: %ld\n", r.ru_isrss);
		printf("Page Reclaims: %ld\n", r.ru_minflt);
		printf("Page Faults: %ld\n", r.ru_majflt);
        printf("Swaps %ld\n", r.ru_nswap);
        printf("Block Input Operations %ld\n", r.ru_inblock);
        printf("Block Output Operations %ld\n", r.ru_oublock);
        printf("Messages Sent %ld\n", r.ru_msgsnd);
        printf("Messages Received %ld\n", r.ru_msgrcv);
        printf("Signals Received %ld\n", r.ru_nsignals);
        printf("Voluntary Context Switches %ld\n", r.ru_nvcsw);
        printf("Involuntary Context Switches %ld\n", r.ru_nivcsw);
        printf("*****************************\n");
		
        sleep(1);
	}
	return 0;
}