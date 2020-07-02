#define _CRT_SECURE_NO_WARNINGS
#include"functions.h"
#include<stdlib.h>
int main()
{
	init();
	int n, i, buf, count;
	printf("Enter the number of numbers\n");
	scanf("%d", &n);
	int *arr = (int*)malloc(sizeof(int)* n);
	printf("\nEnter the numbers\n");
	for (i = 0; i < n; i++)
	{
		count = 0;
		scanf("%d", &arr[i]);
		//Если есть элемент в стеке
		if ((buf = pop()) != -1) 
		{
			//Если элемент стека меньше чем наше новое число - заменяем предыдущие на новое тк оно больше
			if (buf < arr[i])
			{
				arr[i - (++count)] = arr[i];
				while ((buf = pop()) != -1)
				{
					//Учет ситуации когда в стеке лежит элемент больше нашего
					if (buf != 0) 
					{
						if (arr[i] > buf)
						{
							arr[i - (++count)] = arr[i];
							if (!push(arr[i]))
								return 0;
						}
						else 
						{
							if (!push(buf) || !push(arr[i]))
								return 0;
							while (count >= 0)
							{
								count--;
								if (!push(0))
									return 0;
							}
						}
					}
				}
			}
			else
			{
				//Если новое число не больше старых - то ищем замену для него тоже
				if (!push(buf) || !push(arr[i]))
					return 0;
			}
		}
		else
		if (!push(arr[i]))
			return 0;
	}
	count = 0;
	//Если в стеке остались значения - заменяем их нулями
	while ((buf = pop()) != -1) 
	{
		if (buf != 0)
			arr[i - (++count)] = 0;
	}
	printf("\nResult:\n");
	print(arr, n);
	//очистка памяти
	free(arr);
	return 0;
}

