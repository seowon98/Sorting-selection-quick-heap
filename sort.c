#include<stdio.h>
#include<stdlib.h>
#include<String.h>
#include <time.h>

#define STUDENTNUM 1000 //학생 수 바뀌면 여기만 바꾸면 됨
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t)) ///자리 바꾸는 메소드 함수

typedef struct  {
	int num[9]; //학번
	char name[10]; //이름
	int tel[11]; //번호

}Element; //학생 구조체

//함수 선언
void Set(Element *arr[]); //초기화 함수
void Show(Element *arr[]); //출력 함수
void selection_sort(Element *arr[], int n,int criteria); //선택 정렬
void quick_sort(Element *arr[], int left, int right, int criteria); //퀵 정렬
int partition(Element *arr[], int left, int right, int criteria); //분할 함수

int main() {

          int i, j; //제어변수
          clock_t start, finish; //시간, 끝 시간 저장
          double duration; //시간 측정 시 필요한 변수들
          Element *arr[STUDENTNUM];

          for (i = 0; i < STUDENTNUM; i++) {
		      arr[i] = (Element *)malloc(sizeof(Element));//동적 할당
	       }

        Set(arr); //학생 정보 초기화

		
		printf("<정렬 기준 : 학번>\n");

		printf("선택정렬\n");
		start = clock(); //시간 측정 시작

		selection_sort(arr, STUDENTNUM,0); ////////////////////선택 정렬	
		Show(arr); //출력

		finish = clock(); //시간 측정 끝
		duration = (double)(finish - start) / CLOCKS_PER_SEC; //시간 계산
		printf("\n걸린시간: %f 초\n", duration); //시간 출력


		printf("\n퀵 정렬\n");
		start = clock();
		
		
		quick_sort(arr, 0,STUDENTNUM-1,0);///////////////////////퀵 정렬
		Show(arr);

		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n걸린시간: %f 초\n", duration);

		////////////////////////////////////////////////////////////////////////////
		printf("\n\n\n<정렬 기준 : 이름>\n");

		printf("선택정렬\n");
		start = clock();

		selection_sort(arr, STUDENTNUM,1);///////////////////////선택 정렬
		Show(arr);

		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n걸린시간: %f 초\n", duration);

		printf("\n퀵 정렬\n");
		start = clock();

		quick_sort(arr, 0, STUDENTNUM-1,1);	//////////////////퀵 정렬	
		Show(arr);
		
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n걸린시간: %f 초\n", duration);



		printf("\n\n");



	
}

	void Set(Element *arr[]) { //학생 정보 초기화 함수
	
	int i,j; 

	srand(time(NULL));
	for (i = 0; i < STUDENTNUM; i++) {

		arr[i]->num[0]= 2;//학번
		arr[i]->num[1] = 0;
		arr[i]->num[2] = 1;
		arr[i]->num[3] = rand() % 7 + 3; //3~9 난수
		for (j = 4; j < 9; j++) arr[i]->num[j] = rand() % 10; //0~9 난수

		for (j = 0; j < 10; j++) arr[i]->name[j] = rand() % (90 - 65) + 65; //이름 영문 대문자 랜덤

		arr[i]->tel[0] = 0; //전화번호
		arr[i]->tel[1] = 1;
		arr[i]->tel[2] = 0;
		for(j=3;j<11;j++) arr[i]->tel[j] = rand() % 10; //0~9
		
	}
}

	void Show(Element *arr[]) { //정렬 결과 보여주기
		int i, j;

		for (i = 0; i < STUDENTNUM; i+=100) { //100단위로 출력
			printf("%3d번째 학생) ", i + 1);
			printf("학번: ");
			for (j = 0; j < 9; j++) printf("%d", arr[i]->num[j]);//학번

			printf(" 이름: ");
			for (j = 0; j < 10; j++) printf("%c", arr[i]->name[j]); //이름

			printf(" 번호: ");
			for (j = 0; j < 11; j++) printf("%d", arr[i]->tel[j]); //전화번호

			printf("\n");
		}
	}

	void selection_sort(Element *arr[], int n, int criteria) { //선택정렬
		int i, j, least;
		Element * temp;

		for (i = 0; i < n - 1; i++) {
			least = i; //맨 처음 비교 기준

			for (j = i + 1; j < n; j++)
				if (criteria == 0) { //기준이 학번일 때
					if (arr[j]->num[3] < arr[least]->num[3]) least = j; //3번 째 숫자부터 비교
				}
				else if(criteria==1) //기준이 이름일 때
				{
					if (arr[j]->name[0] < arr[least]->name[0]) least = j;
				}

			SWAP(arr[i], arr[least], temp);
		}
	}

	void quick_sort(Element *arr[], int left, int right,int criteria) { //퀵 정렬
		int a = criteria; //비교 기준 알려주는 변수

		if (left < right) {
			int q = partition(arr, left, right, a);
			quick_sort(arr, left, q - 1, a);
			quick_sort(arr, q + 1, right, a);
		}
	}

	int partition(Element *arr[], int left, int right, int criteria) { //분할 함수
		
		int low, high;
		Element * temp; //임시

		low = left;
		high = right + 1;

		if (criteria == 0) { //비교 기준 학번
			int pivot = arr[left]->num[3];

			do {
				do low++;
				while (low <= right && arr[low]->num[3] < pivot);
				do high--;
				while (high >= left && arr[high]->num[3] > pivot);
			} while (low < high);

		}


		else if (criteria == 1) { //비교 기준 이름이면
			char pivot = (arr[left]->name[0]); ///피봇을 문자형으로 선언

			do {
				do low++;
				while (low <= right && (arr[low]->name[0]) < pivot); //비교 용이하게!
				do high--;
				while (high >= left && (arr[high]->name[0]) > pivot);
			} while (low < high);
		}

		SWAP(arr[left], arr[high], temp); //자리 바꿔주기
		return high;

	}