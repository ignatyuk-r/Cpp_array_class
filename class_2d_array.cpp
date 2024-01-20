#include <iomanip>
#include <iostream>
using namespace std;

template <class A2_Type>
class Array2d
{
private:
	A2_Type** arr;
	int len;
	int wid;
public:
	Array2d();
	Array2d(int Lenght, int Width);
	~Array2d();
	void Rand(int Min, int Max); // ���������� ������� ���������� �������
	void Input(); // ���������� ������� � ����������
	void Output(); // ����� ������� � �������
	void To_arr(int* arr1); // ������� 2-������� ������� � 1-������
	void From_arr(int* arr1);// ������� 1 - ������� ������� � 2 - ������
	A2_Type Elem_sum(); // ���������� ����� ��������� �������
	A2_Type Elem_max(); // ���������� ������������� ��������� ������� �� ��������
	void String_insert(int string_num, int ins_arr[]); // ������� ������ � ������
	void Column_insert(int column_num, int ins_arr[]); // ������� ������� � ������
	void String_del(int string_num); // �������� ������ �� �������
	void Column_del(int column_num); // �������� ������� �� �������
	void Sort_string(int string_num); // ���������� ������� �� �������
	void Sort_column(int column_num); // ���������� ������� �� ��������
	void Full_sort(); // ���������� 2-������� ������� �������
	void Multip_arr2d(int** arr2); // ��������� ������� �� �������
	void String_multip(int string_num, int Multip); // ��������� ������ �� �����
	void String_div(int string_num, int div); // ������� ������ �� �����
	void Transposition(); // ���������������� �������
};

template <class A2_Type>
Array2d<A2_Type>::Array2d()
{
	len = 1;
	wid = 1;
	arr = new A2_Type * [len];
	for (int i = 0; i < wid; i++)
		arr[i] = new A2_Type[wid];
}

template <class A2_Type>
Array2d<A2_Type>::Array2d(int Lenght, int Width)
{
	len = Lenght;
	wid = Width;
	arr = new A2_Type * [len];
	for (int i = 0; i < wid; i++)
		arr[i] = new A2_Type[wid];
}

template <class A2_Type>
Array2d<A2_Type>::~Array2d()
{
	for (int i = 0; i < wid; i++)
		delete arr[i];
	delete[]arr;
}

template <class A2_Type>
void Array2d<A2_Type>::Rand(int Min, int Max) // ���������� ������� ���������� �������
{
	for (int i = 0; i < len; i++)
		for (int j = 0; j < wid; j++)
			arr[i][j] = Min + rand() % (Max - Min + 1);
}

template <class A2_Type>
void Array2d<A2_Type>::Input() // ���������� ������� � ����������
{
	for (int i = 0; i < len; i++)
		for (int j = 0; j < wid; j++)
			cin >> arr[i][j];
}

template <class A2_Type>
void Array2d<A2_Type>::Output() // ����� ������� � �������
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < wid; j++)
			cout << setw(6) << arr[i][j];
		cout << endl;
	}
}

template <class A2_Type>
void Array2d<A2_Type>::To_arr(int* arr1) // ������� 2-������� ������� � 1-������
{
	int k = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < 10; j++)
		{
			arr1[k] = arr[i][j];
			k++;
		}
}

template <class A2_Type>
void Array2d<A2_Type>::From_arr(int* arr1)// ������� 1 - ������� ������� � 2 - ������
{
	int k = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < wid; j++)
		{
			arr[i][j] = arr1[k];
			k++;
		}
}

template <class A2_Type>
A2_Type Array2d<A2_Type>::Elem_sum() // ���������� ����� ��������� �������
{
	int sum = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < wid; j++)
			sum += arr[i][j];
	return sum;
}

template <class A2_Type>
A2_Type Array2d<A2_Type>::Elem_max() // ���������� ������������� ��������
{
	int Max = 0;
	Max = arr[0][0];
	for (int i = 0; i < len; i++)
		for (int j = 0; j < 10; j++)
			if (arr[i][j] > Max)
				Max = arr[i][j];
	return Max;
}

template <class A2_Type>
void Array2d<A2_Type>::String_insert(int string_num, int ins_arr[]) // ������� ������ � ������
{
	int k = 0;
	for (int i = len - 1; i >= string_num; i--)
		for (int j = 0; i < wid; j++)
			arr[i][j] = arr[i - 1][j];

	for (int j = 0; j < wid; j++)
	{
		arr[string_num - 1][j] = ins_arr[k];
		k++;
	}
}

template <class A2_Type>
void Array2d<A2_Type>::Column_insert(int column_num, int ins_arr[]) // ������� ������� � ������
{
	int k = 0;
	for (int i = 0; i < len; i++)
		for (int j = wid - 1; j >= column_num; j--)
			arr[i][j] = arr[i][j - 1];

	for (int i = 0; i < len; i++)
	{
		arr[i][column_num - 1] = ins_arr[k];
		k++;
	}
}

template <class A2_Type>
void Array2d<A2_Type>::String_del(int string_num) // �������� ������ �� �������
{
	for (int i = string_num - 1; i < len - 1; i++)
		for (int j = 0; j < wid; j++)
			arr[i][j] = arr[i + 1][j];

	for (int j = 0; j < wid; j++)
		arr[len - 1][j] = 0;
}

template <class A2_Type>
void Array2d<A2_Type>::Column_del(int column_num) // �������� ������� �� �������
{
	for (int i = 0; i < len; i++)
		for (int j = column_num - 1; j < wid - 1; j++)
			arr[i][j] = arr[i][j + 1];

	for (int i = 0; i < wid; i++)
		arr[i][wid - 1] = 0;
}

template <class A2_Type>
void Array2d<A2_Type>::Sort_string(int string_num) // ���������� ������� �� �������
{
	int i = 0;
	int temp;
	while (i < len)
	{
		if (i == 0 || arr[string_num][i - 1] <= arr[string_num][i])
			i++;
		else
		{
			temp = arr[string_num][i];
			arr[string_num][i] = arr[string_num][i - 1];
			arr[string_num][i - 1] = temp;
			i--;
		}

	}
}

template <class A2_Type>
void Array2d<A2_Type>::Sort_column(int column_num) // ���������� ������� �� ��������
{
	int i = 0;
	int temp;
	while (i < wid)
	{
		if (i == 0 || arr[i - 1][column_num] <= arr[i][column_num])
			i++;
		else
		{
			temp = arr[i][column_num];
			arr[i][column_num] = arr[i - 1][column_num];
			arr[i - 1][column_num] = temp;
			i--;
		}

	}
}

template <class A2_Type>
void Array2d<A2_Type>::Full_sort() // ���������� 2-������� ������� �������
{
	int j = 0;
	int i = 0;
	int temp;
	while (i < len)
	{
		if (i == 0 && j == 0)
			j++;
		else if (j == 0 && arr[i][j] >= arr[i - 1][wid - 1])
			j++;
		else if (j != 0 && arr[i][j] >= arr[i][j - 1])
		{
			if (j < wid - 1)
				j++;
			else
			{
				i++;
				j = 0;
			}
		}
		else
		{
			if (j == 0)
			{
				temp = arr[i][j];
				arr[i][j] = arr[i - 1][wid - 1];
				arr[i - 1][wid - 1] = temp;
				i--;
				j = wid - 1;
			}
			else
			{
				temp = arr[i][j];
				arr[i][j] = arr[i][j - 1];
				arr[i][j - 1] = temp;
				j--;
			}
		}

	}
}

template <class A2_Type>
void Array2d<A2_Type>::Multip_arr2d(int** arr2) // ��������� ������� �� �������
{
	for (int i = 0; i < len; i++)
		for (int j = 0; j < wid; j++)
			arr[i][j] *= arr2[i][j];
}

template <class A2_Type>
void Array2d<A2_Type>::String_multip(int string_num, int Multip) // ��������� ������ �� �����
{
	for (int j = 0; j < wid; j++)
		arr[string_num][j] *= Multip;
}

template <class A2_Type>
void Array2d<A2_Type>::String_div(int string_num, int div) // ������� ������ �� �����
{
	for (int j = 0; j < wid; j++)
		arr[string_num][j] /= div;
}

template <class A2_Type>
void Array2d<A2_Type>::Transposition() // ���������������� �������
{
	int temp = 0;
	for (int i = 0; i < len; ++i)
	{
		for (int j = i; j < wid; ++j)
		{
			temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
}