//Указатели в языке С++
//https://stepik.org/lesson/539/step/1

#include <iostream>
using namespace std;

//Указатель - типизированя переменная,
//хранящая адрес ячейки памяим.

int stepik(){
	int i = 2;   //переменная типа int
	int * p = 0; //указатель на пермененну типа int;
				 //нулевому указателю не соответствует
				 //никакая ячейка памяти

	cout << p + 1 << endl; //0x4 (int - 4 байта) 

	p = &i;             //оператор взятия адреса переменной
	cout << *p << endl; //оператор разыменования 

	*p = 10;			//переменная по адресу i принимает
						//значение 10
	cout << i << endl;  //10

	//указатели позволяют передвигаться по массивам
	int my_array[10] = {1, 42, 3, 4, 5, 6};
	int *array_pointer_start = &my_array[0]; //указатель на начало массива
	int *array_pointer_end = &my_array[9];   //указатель на конец массива

	//(array_pointer + k) - сдвиг на k ячеек вправо
	//(array_pointer - k) - сдвиг на k ячеек влево
	//(array_pointer_end - array_pointer_start) - ячеек между указателями
	//array_poiner[k] - эквивалентно *(array_poiner + k) 
	cout << array_pointer_end - array_pointer_start << endl; //9 
	cout << array_pointer_start[1] << endl;                  //42


	return 0;
}

bool contains(int * m, int * p, int value){ //проверка нахождения элемента в массиве
	while(m != p){
		if (*m == value){
			return true;
		}
		m++;
	}
	return false;
}

void swap(int * a, int * b){         //функция swap, использующая указатели
	int temp = *a;
	*a = *b;
	*b = temp;
} 

int max_element(int * m, int size){  //передача массива в функцию
	int max =  *m;
	for (int i = 1; i < size; i++){
		if(m[i] > max){
			max = m[i];
		}
	}
	return max;
}

int max_element_2(int * p, int * q){ //больше указателей!
	int max = *p;
	for(; p != q; p++){
		if (*p > max){
			max = *p;
		}
	}
	return max;
}

int * max_el_pointer(int * p, int * q){ //указатель на максимальный элемент
	//cout << "this is" << p << " " << *p << endl; //адрес p и его значение
	int * max_pointer = p;
	for(; p != q; p++){
		if (*p > *max_pointer){
			max_pointer = p; 
		}
	}
	return max_pointer;
}

bool max_element_3(int * p, int * q, int * res){ //записывает значение максимального
	if (p == q){								 //элемента в переменную res
		return false;
	}
	*res = *p;
	for(; p != q; p++){
		if(*p > *res){
			*res = *p;
		}
	}
	return true;
}

bool max_element_4(int * p, int * q, int ** res){ //записывает адрес максимального
	if (p == q){								  //элемента в переменную res
		return false;
	}
	*res = p;
	for(; p != q; p++){
		if(*p > **res){
			*res = p;
		}
	}
	return true;

}

int main(){
	stepik();

	int a = 1;
	int b = 2;
	swap(&a, &b);
	cout << "result of swapping: "<< a << " " << b << endl;         			 //2 1

	int my_array[10] = {21, 42, 3, 4, 5, 6};
	cout << "max element is " << max_element(my_array, 10) << endl;              //42  
	cout << "max element is " << max_element_2(my_array, &my_array[10]) << endl; //42

	int * address = max_el_pointer(my_array, my_array + 10);
	cout << address << " " << *address << endl;									 //address 42

	int my_max = 0;
	bool is_max_in = false;
	is_max_in = max_element_3(my_array, my_array + 10, &my_max);
	cout << is_max_in << " " << my_max << endl;									 //1 42
	cout << contains(&my_array[0], &my_array[10], 42) << endl;					 //1
	return 0;
}