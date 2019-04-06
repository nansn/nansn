#include <unistd.h>  
#include <stdio.h>
#include <stdlib.h>

void func()
{
	int i = 0;
	for ( ; i < 18; i++)
		sleep(1);

	printf("child done\n");

}

int main ()   
{   
	pid_t fpid; 
	int count = 0;
#define NUM 6

	for ( ; count < NUM; count++) {
		fpid=fork();   
		if (fpid < 0) {   
			perror("error in fork!");
			exit(0);

		} else if (fpid == 0) {
			func();
			exit(0);
		}  
	}

	printf("main done\n");

	return 0;  
}  

