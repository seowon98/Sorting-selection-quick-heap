# Sorting-selection-quick-heap
data structure

# 선택 정렬/퀵 정렬/힙정렬
다음의 구성을 가진 데이터 5만 명분을 랜덤하게 생성한다.
- 학번(13-19년도에 입학한 학생의 9자리 숫자), 이름(10자 크기의 영문자 임의의 문자), 전화번호(010 으로 시작하는 11자리 숫자)

동일한 데이터에 대해 선택 정렬, 퀵 정렬, 힙 정렬을 수행한 후 결과를 비교하자.
정렬의 기준은 학번으로 1회, 이름으로 1회 한다. 정렬이 잘 되었는지 확인하자. 
5만 명의 데이터를 모두 화면에 출력하면 시간이 너무 오래 걸리니 정렬이 잘 되었음을 증명하는 방법을 알아보자(적당히 건너뛰며 100개만 표시한다든지).
정렬에 소요되는 시간이 얼마나 되는지 화면에 표시하자. 학번으로 정렬할 때와 이름으로 정렬할 때 각각 표시한다.

## 재귀 호출을 쓰지 않는 퀵 정렬 기능을 만들기
퀵 정렬을 만들되, 재귀 호출을 쓰지 않도록 만든다.
힌트 : 스택
(5)에 있는 퀵 정렬(재귀 호출)과 성능을 비교하자(학번으로 정렬하는 경우만 생각하자).
어느 것이 얼만큼 빠른지 결과를 비교하라.

해결 방법>
1. 학생 데이터 생성
 학번, 이름, 번호 배열로 구성된 구조체 생성
	구조체 포인터 배열 생성해서 접근
	데이터 양이 방대하고 모든 함수에서 접근 가능한 동적 할당
<div>
  <img width="500" src="https://user-images.githubusercontent.com/60779441/77488783-8a620800-6e79-11ea-97a9-95d2941aee84.png">
 </div>
2. 시간 측정 #include <time.h>
 start = clock(); //시간 측정 시작

실행할 코드

finish = clock(); //시간 측정 끝
duration = (double)(finish - start) / CLOCKS_PER_SEC; //시간 계산

3. 학생 정보 초기화 void Set(Element *arr[])
 구조체 포인터로 접근
 정해진 숫자는 직접 삽입, 나머지는 범위에 맞게 rand()함수로 난수 발생

★정렬 기준에 따라 정렬 함수 생성하면 비효율적! 그래서 정렬 기준을 알려주는 int criteria 를 선언하여 함수 매개변수로 함께 전달!! (0: 학번, 1: 이름)

4. 선택 정렬 void selection_sort(Element *arr[], int n, int criteria)
 처음 최솟값을 맨 앞 숫자로 생각: least = i ;
조건문으로 정렬 기준 변수 확인 후, 정렬 실행

5. 퀵 정렬 void quick_sort(Element *arr[], int left, int right,int criteria)
 비교 기준 변수
 분할 함수: int partition(Element *arr[], int left, int right, int criteria)
 비교 기준이 문자인 이름이면 피봇을 문자로 선언 후 비교!!


결과 화면>
<div>
  <img width="500" src="https://user-images.githubusercontent.com/60779441/77488693-4cfd7a80-6e79-11ea-9e24-b6bc21175ecc.png">
  <img width="500" src="https://user-images.githubusercontent.com/60779441/77488698-50910180-6e79-11ea-88cf-4a1fa068082b.png">
 </div>
 
