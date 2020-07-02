#include"functions.h"
struct Stack
{
	int arr[N];
	int* p;
}stack;
void init()
{
	stack.arr[0] = -1;
	stack.p = stack.arr;
}
int pop() 
{
	if ((stack.p > stack.arr)) 
	{     //���� � ����� ������ ������ ��������
		stack.p--;   //��������� ���������
		return *(stack.p + 1);   //���������� ��������� ������� �����
	}
	else
		//���� � ����� ���� �������
	if (stack.p == stack.arr || (*stack.p != -1))
	{
		int buf = *stack.p;
		//����� ���� ���������� ������ �� ���������� ��� -1 �� ������ �������
		*stack.p = -1;
		return buf;
	}
	else
		return -1;
}
int push(int x) 
{
	//���� ���� �����
	if (stack.p < &stack.arr[N - 1])
	{
		//������ ��������� �� ��������� ������
		stack.p++;
		//������ �������� � ������
		*stack.p = x;
		return 1;
	}
	else
	{
		printf("stack over flow");
		return 0;
	}
}
void print(int* arr, int n) 
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
}