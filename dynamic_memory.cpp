//Динамическая память
//https://stepik.org/lesson/542/step/1

#include <iostream>
#include <cstdlib>   //Управление паматью в стиле C
using namespace std;

int stepik(){
	//Функции библиотеки cstdlib
	//void * malloc (size_t size)               :Выделяет неициалирированную область памяти >= size
	//void free (void * ptr)					:Выделяет массив элементов nmemb размера size. Данные инициализируются нулем
	//void * calloc (size_t nmemb, size_t size) :Изменяет размер области памяти по указателю ptr на size 
	//void * realloc(void * ptr, size_t size)   :Освобождает область памяти

	//size_t - специальный беззнаковый тип, способный
	//вместить в себя размер любого типа в байтах, использующийся
	//для указания размеров типов данных, для индексации массивов и пр.

	//void * - указатель на нетипизированную память

	//Создание массива из 100 int
	int * m = (int *)malloc(1000 * sizeof(int)); //(int *) - приведение типа указателя
	m[10] = 42;
	cout << m[10] << endl; //42

	//Изменение размера массива до 200
	m = (int *)realloc(m, 200 * sizeof(int));

	//Освобождение памяти
	free(m);									//wut

	//Создание массива нулей
	m = (int * )calloc(100, sizeof(int));
	cout << m[10] << endl;
	free(m);


	//Работа с памятью в стиле С++
	//new и delete - для одиночных значений
	//new[] и delete[] - для массивов

	//Выделение памяти под один int
	int * n = new int(5);
	cout << *n << endl; //5
	delete n;
	cout << *n << endl; //0

	//Выделение памяти под массив int
	n = new int[5];
	delete [] m;
	
	return 0;
}

int main(){
	stepik();
	return 0;
}