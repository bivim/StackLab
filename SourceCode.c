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
		//���� ���� ������� � �����
		if ((buf = pop()) != -1) 
		{
			//���� ������� ����� ������ ��� ���� ����� ����� - �������� ���������� �� ����� �� ��� ������
			if (buf < arr[i])
			{
				arr[i - (++count)] = arr[i];
				while ((buf = pop()) != -1)
				{
					//���� �������� ����� � ����� ����� ������� ������ ������
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
				//���� ����� ����� �� ������ ������ - �� ���� ������ ��� ���� ����
				if (!push(buf) || !push(arr[i]))
					return 0;
			}
		}
		else
		if (!push(arr[i]))
			return 0;
	}
	count = 0;
	//���� � ����� �������� �������� - �������� �� ������
	while ((buf = pop()) != -1) 
	{
		if (buf != 0)
			arr[i - (++count)] = 0;
	}
	printf("\nResult:\n");
	print(arr, n);
	//������� ������
	free(arr);
	return 0;
}

