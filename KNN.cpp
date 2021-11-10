#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#define MAX 100
using namespace std;


struct Point{
	int val; // class cua point
	float x, y;
	float distance;
};

int phanLopKnn(Point arr[], int n, int k, Point p)
{
	for (int i = 0; i <n; i++)
	{
		arr[i].distance = sqrt(((arr[i].x - p.x)*(arr[i].x - p.x)) + ((arr[i].y - p.y)*(arr[i].y - p.y)));
	}

	for (int i = 0; i<n - 1; i++)
	{
		for (int j = i + 1; j<n; j++)
		{
			if (arr[i].distance  > arr[j].distance)
			{
				swap(arr[i], arr[j]);
			}
		}
	}

	int dem1 = 0;
	int dem2 = 0;

	for (int i = 0; i<k; i++)
	{
		if (arr[i].val == 0)
		{
			dem1++;
		}
		else if (arr[i].val == 1)
		{
			dem2++;
		}
	}
	if (dem1 > dem2)
	{
		return 0;
	}
	else{
		return 1;
	}
}

void nhap(Point a[], int &n){
	for (int i = 0; i < n; i++){
		printf("\t---Nhap pt thu a[%d]",i+1);
		printf("\n");
		printf("x: " );
		scanf_s("%f", &a[i].x);
		printf("y: ");
		scanf_s("%f", &a[i].y);
		printf("nhan: ");
		scanf_s("%d", &a[i].val);
		printf("\n");
	}
}

void xuat(Point a[], int n){
	for (int i = 0; i < n; i++){		
		printf("x: %0.2f ; y: %0.2f ; Nhan: %d \n", a[i].x, a[i].y, a[i].val);
	}
}

void main()
{
	int n;
	Point a[MAX];
	Point b;
	int k;
	printf("Nhap k: ");
	scanf_s("%d", &k);
	printf("Nhap so luong phan tu: ");
	scanf_s("%d", &n);
	nhap(a, n);
	xuat(a, n);

		/*Nhập điểm cần tính */
	printf("\t ------Nhap diem can tinh-----\n");
	printf("x: ");
	scanf_s("%f", &b.x);
	printf("y: ");
	scanf_s("%f", &b.y);

	int nhom = phanLopKnn(a, n, k, b);
	printf("Nhom :%d ", nhom);

	_getch();
}

