#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	pid_t pid; //pid_t 선언

	pid = fork(); //fork 발생
	if(pid == -1) { //-1 이면 fork생성 에러
		printf("can't fork, erro\n");
		exit(0);
	}
    printf("start : ============================================\n");
    printf("pid = %d\n",pid);
	if(pid == 0) { //0이면 자식 프로세스
		int j;
		for(j = 0; j < 10; j++) {
			printf("child: %d\n", j);
		}
        // sleep(5);
        printf("child pid = %d\n",pid);
	} else { //부모프로세스
		int i;
		for(i = 0; i < 10; i++) {
			printf("parent : %d\n", i);
            // sleep(1);
		}
        printf("why?\n");
        printf("parent pid = %d\n",pid);
	}
    printf("pid = %d\n",pid);
    printf("end : ============================================\n");
	return 0;
}