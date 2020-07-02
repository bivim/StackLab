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
	{     //Если в стеке больше одного элемента
		stack.p--;   //уменьшаем указатель
		return *(stack.p + 1);   //возвращаем последний элемент стека
	}
	else
		//Если в стеке один элемент
	if (stack.p == stack.arr || (*stack.p != -1))
	{
		int buf = *stack.p;
		//когда стек становится пустым мы обозначаем это -1 на первой позиции
		*stack.p = -1;
		return buf;
	}
	else
		return -1;
}
int push(int x) 
{
	//Если есть место
	if (stack.p < &stack.arr[N - 1])
	{
		//Ставим указатель на свободную ячейку
		stack.p++;
		//кладем значение в ячейку
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