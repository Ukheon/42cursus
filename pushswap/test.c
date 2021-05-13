#include <stdio.h>
 #include <time.h>
  // time 함수가 포함되어 있는 헤더파일
   #include <stdlib.h>
 void printarr(int *arr, int num)
    { for (int i=0; i < num; i++)
			printf("%d ", arr[i]);
	 printf("\n");
	} // 배열을 섞는 함수
	 void shuffle(int *arr, int num)
	  {
		  srand(time(NULL));
		  int temp;
		  int rn;
		  for (int i=0; i < num-1; i++)
		   { rn = rand() % (num - i) + i;
		   temp = arr[i]; arr[i] = arr[rn]; arr[rn] = temp; } }

int main(void) {
	int num;
	 int *arr;
	  printf("Input size of array : ");
	  scanf("%d", &num);
	   // 배열의 크기를 입력받음
	    arr = (int *)malloc(sizeof(int) * num);
		 // 입력받은 배열의 크기만큼 메모리 할당
		  for (int i=0; i < num; i++) arr[i] = i+1;
		   // 배열을 1부터 num 까지의 요소로 초기화
		   shuffle(arr, num);
		    printarr(arr, num); free(arr); return 0; }
