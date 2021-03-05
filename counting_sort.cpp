#include<iostream>
using namespace std;

int array_max(int* a, int n)	//�ҳ����������Ԫ��
{
	int a_max = a[0];
	for (int i = 1; i < n; i++) if (a[i] > a_max) a_max = a[i];
	return a_max;
}
int array_min(int* a, int n)	//�ҳ���������СԪ��
{
	int a_min = a[0];
	for (int i = 1; i < n; i++) if (a[i] < a_min) a_min = a[i];
	return a_min;
}

int* counting_sort(int* a, int n)	//��������
{
	int a_max = array_max(a, n);
	int a_min = array_min(a, n);
	int* c = new int[a_max - a_min + 1];					//��������
	for (int i = 0; i < a_max - a_min + 1; i++)c[i] = 0;	//��������
	for (int i = 0; i < n; i++)c[a[i] - a_min]++;			//��a��Ԫ�س��ִ�������
	for (int i = 1; i < a_max - a_min + 1; i++)c[i] += c[i - 1];	//a��Ԫ�������ֵļ������
	int* b = new int[n];					//������
	for (int j = n - 1; j >= 0; j--)
	{	
		b[c[a[j] - a_min]-1] = a[j];		//�������-1�������ֵ�λ��
		c[a[j] - a_min]--;
	}
	return b;
}

int main()
{
	int n = 10;
	int* a = new int[n];
	a[0] = 5; a[1] = 2; a[2] = 9; a[3] = -3; a[4] = -7;
	a[5] = 1; a[6] = 4; a[7] = 5; a[8] = 5; a[9] = 1;
	cout << "����ǰ��";
	for (int i = 0; i < n; i++)cout << a[i] << " ";
	cout << endl;
	cout << "�����";
	int* b = counting_sort(a, n);
	for (int i = 0; i < n; i++)cout << b[i] << " ";
	cout << endl;
	return 0;
}