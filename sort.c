#include<stdio.h>
#include<stdlib.h>
#include<String.h>
#include <time.h>

#define STUDENTNUM 1000 //�л� �� �ٲ�� ���⸸ �ٲٸ� ��
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t)) ///�ڸ� �ٲٴ� �޼ҵ� �Լ�

typedef struct  {
	int num[9]; //�й�
	char name[10]; //�̸�
	int tel[11]; //��ȣ

}Element; //�л� ����ü

//�Լ� ����
void Set(Element *arr[]); //�ʱ�ȭ �Լ�
void Show(Element *arr[]); //��� �Լ�
void selection_sort(Element *arr[], int n,int criteria); //���� ����
void quick_sort(Element *arr[], int left, int right, int criteria); //�� ����
int partition(Element *arr[], int left, int right, int criteria); //���� �Լ�

int main() {

          int i, j; //�����
          clock_t start, finish; //�ð�, �� �ð� ����
          double duration; //�ð� ���� �� �ʿ��� ������
          Element *arr[STUDENTNUM];

          for (i = 0; i < STUDENTNUM; i++) {
		      arr[i] = (Element *)malloc(sizeof(Element));//���� �Ҵ�
	       }

        Set(arr); //�л� ���� �ʱ�ȭ

		
		printf("<���� ���� : �й�>\n");

		printf("��������\n");
		start = clock(); //�ð� ���� ����

		selection_sort(arr, STUDENTNUM,0); ////////////////////���� ����	
		Show(arr); //���

		finish = clock(); //�ð� ���� ��
		duration = (double)(finish - start) / CLOCKS_PER_SEC; //�ð� ���
		printf("\n�ɸ��ð�: %f ��\n", duration); //�ð� ���


		printf("\n�� ����\n");
		start = clock();
		
		
		quick_sort(arr, 0,STUDENTNUM-1,0);///////////////////////�� ����
		Show(arr);

		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n�ɸ��ð�: %f ��\n", duration);

		////////////////////////////////////////////////////////////////////////////
		printf("\n\n\n<���� ���� : �̸�>\n");

		printf("��������\n");
		start = clock();

		selection_sort(arr, STUDENTNUM,1);///////////////////////���� ����
		Show(arr);

		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n�ɸ��ð�: %f ��\n", duration);

		printf("\n�� ����\n");
		start = clock();

		quick_sort(arr, 0, STUDENTNUM-1,1);	//////////////////�� ����	
		Show(arr);
		
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n�ɸ��ð�: %f ��\n", duration);



		printf("\n\n");



	
}

	void Set(Element *arr[]) { //�л� ���� �ʱ�ȭ �Լ�
	
	int i,j; 

	srand(time(NULL));
	for (i = 0; i < STUDENTNUM; i++) {

		arr[i]->num[0]= 2;//�й�
		arr[i]->num[1] = 0;
		arr[i]->num[2] = 1;
		arr[i]->num[3] = rand() % 7 + 3; //3~9 ����
		for (j = 4; j < 9; j++) arr[i]->num[j] = rand() % 10; //0~9 ����

		for (j = 0; j < 10; j++) arr[i]->name[j] = rand() % (90 - 65) + 65; //�̸� ���� �빮�� ����

		arr[i]->tel[0] = 0; //��ȭ��ȣ
		arr[i]->tel[1] = 1;
		arr[i]->tel[2] = 0;
		for(j=3;j<11;j++) arr[i]->tel[j] = rand() % 10; //0~9
		
	}
}

	void Show(Element *arr[]) { //���� ��� �����ֱ�
		int i, j;

		for (i = 0; i < STUDENTNUM; i+=100) { //100������ ���
			printf("%3d��° �л�) ", i + 1);
			printf("�й�: ");
			for (j = 0; j < 9; j++) printf("%d", arr[i]->num[j]);//�й�

			printf(" �̸�: ");
			for (j = 0; j < 10; j++) printf("%c", arr[i]->name[j]); //�̸�

			printf(" ��ȣ: ");
			for (j = 0; j < 11; j++) printf("%d", arr[i]->tel[j]); //��ȭ��ȣ

			printf("\n");
		}
	}

	void selection_sort(Element *arr[], int n, int criteria) { //��������
		int i, j, least;
		Element * temp;

		for (i = 0; i < n - 1; i++) {
			least = i; //�� ó�� �� ����

			for (j = i + 1; j < n; j++)
				if (criteria == 0) { //������ �й��� ��
					if (arr[j]->num[3] < arr[least]->num[3]) least = j; //3�� ° ���ں��� ��
				}
				else if(criteria==1) //������ �̸��� ��
				{
					if (arr[j]->name[0] < arr[least]->name[0]) least = j;
				}

			SWAP(arr[i], arr[least], temp);
		}
	}

	void quick_sort(Element *arr[], int left, int right,int criteria) { //�� ����
		int a = criteria; //�� ���� �˷��ִ� ����

		if (left < right) {
			int q = partition(arr, left, right, a);
			quick_sort(arr, left, q - 1, a);
			quick_sort(arr, q + 1, right, a);
		}
	}

	int partition(Element *arr[], int left, int right, int criteria) { //���� �Լ�
		
		int low, high;
		Element * temp; //�ӽ�

		low = left;
		high = right + 1;

		if (criteria == 0) { //�� ���� �й�
			int pivot = arr[left]->num[3];

			do {
				do low++;
				while (low <= right && arr[low]->num[3] < pivot);
				do high--;
				while (high >= left && arr[high]->num[3] > pivot);
			} while (low < high);

		}


		else if (criteria == 1) { //�� ���� �̸��̸�
			char pivot = (arr[left]->name[0]); ///�Ǻ��� ���������� ����

			do {
				do low++;
				while (low <= right && (arr[low]->name[0]) < pivot); //�� �����ϰ�!
				do high--;
				while (high >= left && (arr[high]->name[0]) > pivot);
			} while (low < high);
		}

		SWAP(arr[left], arr[high], temp); //�ڸ� �ٲ��ֱ�
		return high;

	}