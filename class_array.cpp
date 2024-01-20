#include <iomanip>
#include <iostream>
using namespace std;

template <class A_Type>
class Array
{
private:
	A_Type* arr;
	int size;
public:
	Array();

	Array(int Size); // создание массива с нулями

	~Array();

	void Rand(int Min, int Max); // заполнение массива случайными числами
	A_Type Elem_sum(int FirstElem, int LastElem); // вычисление суммы элементов
	A_Type	Elem_multip(int FirstElem, int LastElem); //вычисление произведения элементов
	void Elem_add(int Num, int NewElem); //вставка элемента
	void Elem_del(int Num); //удаление элемента массива
	void Sort(); //гномья сортировка
	A_Type Elem_min(); //поиск минимального элемента массива
	A_Type Elem_max(); //поиск максимального элемента массива
	void Input();//заполнение массива с клавиатуры
	void Output();//вывод массива в консоль
};

template <class A_Type>
Array<A_Type>::Array()
{
	size = 1;
	arr = new A_Type[size];
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}

template <class A_Type>
Array<A_Type>::Array(int Size) // создание массива с нулями
{
	size = Size;
	arr = new A_Type[size];
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}

template <class A_Type>
Array<A_Type>::~Array()
{
	delete[]arr;
}

template <class A_Type>
void Array<A_Type>::Rand(int Min, int Max) // заполнение массива случайными числами
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = Min + rand() % (Max - Min + 1);
	}
}

template <class A_Type>
A_Type Array<A_Type>::Elem_sum(int FirstElem, int LastElem) // вычисление суммы элементов
{
	A_Type Sum = 0;
	for (int i = FirstElem - 1; i < LastElem; i++)
		Sum += arr[i];
	return Sum;
}

template <class A_Type>
A_Type Array<A_Type>::Elem_multip(int FirstElem, int LastElem) //вычисление произведения элементов
{
	A_Type multip = 1;
	for (int i = FirstElem - 1; i < LastElem; i++)
		multip += arr[i];
	return multip;
}

template <class A_Type>
void Array<A_Type>::Elem_add(int Num, int NewElem) //вставка элемента
{
	if (Num <= size)
	{
		for (int i = size; i > Num; i -= 1)
			arr[i] = arr[i - 1];
		arr[Num - 1] = NewElem;
	}
}

template <class A_Type>
void Array<A_Type>::Elem_del(int Num) //удаление элемента массива
{
	for (int i = Num - 1; i < size - 1; i++)
		arr[i] = arr[i + 1];
	arr[size - 1] = 0;
}

template <class A_Type>
void Array<A_Type>::Sort() //гномья сортировка
{
	int i = 0;
	int temp;
	while (i < size)
	{
		if (i == 0 || arr[i - 1] <= arr[i])
			i++;
		else
		{
			temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;
			i--;
		}
	}
}

template <class A_Type>
A_Type Array<A_Type> ::Elem_min() //поиск минимального элемента массива
{
	A_Type Min = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] < Min)
			Min = arr[i];
	return Min;
}

template <class A_Type>
A_Type Array<A_Type>::Elem_max() //поиск максимального элемента массива
{
	A_Type Max = arr[0];
	for (int i = 1; i < size; i++)
		if (abs(arr[i]) > abs(Max))
			Max = arr[i];
	return Max;
}

template <class A_Type>
void Array<A_Type>::Input()//заполнение массива с клавиатуры
{
	for (int i = 0; i < size; i++)
		cin >> arr[i];
}

template <class A_Type>
void Array<A_Type>::Output()//вывод массива в консоль
{
	for (int i = 0; i < size; i++)
		cout << endl << arr[i];
	cout << endl;
}
