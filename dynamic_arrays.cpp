//Динамические массивы
//https://stepik.org/lesson/543/step/1

#include <iostream>
using namespace std;

int stepik(){
	//Многомерные массивы
	int m2d[2][3] = { {1, 2, 3}, {4, 5, 6}};
	for(size_t i = 0; i < 2; i++){
		for(size_t j = 0; j < 3; j++){
			cout << m2d[i][j] << " ";
		}
	}
	cout << endl;

	//Выделение одномерного динамического массива
	int * m1d = new int[100];

	//Выделение двумерного динамического массива 5x5
	int ** m = new int * [5];
	for (size_t i = 0; i < 5; i++){
		m[i] = new int[40];
	}

	//Более эффективный способ выделения памяти
	int ** n = new int * [5];
	n[0] = new int [5 * 5];
	for (size_t i = 1; i < 5; i++){
		n[i] = n[i - 1] + 4;
	}

	return 0;
}

int ** create_array2d(size_t a, size_t b){
	int ** m = new int * [a];
	for (size_t i = i; i < a; i++){
		m[i] = new int[b];
	}
	return m;
}

void delete_array2d(int ** m, size_t a, size_t b){
	for (size_t i = 0; i < a; i++){
		delete [] m[i];
	}
	delete [] m;
}



int main(){
	stepik();
	return 0;
}