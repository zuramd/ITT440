#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t x,y;
	int rv1,rv2;
	

	if(x=fork())
	{
		printf("PARENT: This is the parent process!\n");
		printf("PARENT: My PID is %d\n",getpid());
		printf("PARENT: My 1st child PID is %d\n", x);
		printf("PARENT: I'm now waiting for my 1st child to exit()...\n");
		wait(&rv1);
	}
	else
	{
		printf(" CHILD1: This is the child 1 process!\n");
		printf(" CHILD1: My PID is %d\n", getpid());
		printf(" CHILD1: My parent's PID is %d\n", getppid());
		printf(" CHILD1: Enter my exit status (make it small): ");
		scanf(" %d", &rv1);
		printf(" CHILD1: I'm outta here!\n");
		exit(rv1);
	}

    //child kedua
        if(y=fork())
        {
               printf("PARENT: I'm now waiting for my 2nd child to exit()...\n");
               wait(&rv2);
               printf("PARENT: My 1st child exit status is: %d\n", WEXITSTATUS(rv1));

               printf("PARENT: My 2nd child exit status is: %d\n", WEXITSTATUS(rv2));
               printf("PARENT: I'm outta here !\n");
         }
         else
         {
               printf(" CHILD2: This is the child 2 process!\n");
               printf(" CHILD2: My PID is %d\n", getpid());
               printf(" CHILD2: My parent's PID is %d\n", getppid());
               printf(" CHILD2: Enter my exit status (make it small): ");
               scanf(" %d", &rv2);
               printf(" CHILD2: I'm outta here!\n");
               exit(rv2);
          }
    //end child kedua

}
