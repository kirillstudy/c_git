//Конструкторы и деструкторы
//https://stepik.org/lesson/546/step/1?unit=869

#include <iostream>
using namespace std;

int stepik(){
	struct Point {					//Конструктор Point
		Point(){
			x = y = 0;
		}
		Point(double x, double y){
			this -> x = x;
			this -> y = y;
		}
		double x;
		double y;
		Point(int x, int y, int z){
			this -> a = x;
			this -> b = y;
			this -> c = z;
			this -> sum_of_them = x + y + z;
		}
		int a;
		int b;
		int c;
		int sum_of_them;
	};

	Point p1;
	cout << p1.x << " " << p1.y << endl;   //0 0
	Point p2(3.14, 2.71);
	cout << p2.x << " " << p2.y << endl;   //3.14 2.71
	Point p3(42, 1984, 2017);
	cout << p3.a << " " << p3.b << " " << p3.c << endl; //42 1984 2017
	cout << "Sum: " << p3.sum_of_them << endl;          //4043

	struct Point2 {                        //Списки инициализации
		Point2() : x(0), y(0)
		{}
		Point2(double x, double y) : x(x), y(y)
		{}
		double x;
		double y;
	};

	Point2 p21(3.14, 2.71);
	cout << p21.x << " " << p21.y << endl; //3.14 2.71
	
	struct Point3 {                        //Параметры по умолчанию
		Point3(double x = 0, double y = 0)
			: x(x), y(y)
		{}
		double x;
		double y;
	};

	Point3 p31(3.14);
	cout << p31.x << " " << p31.y << endl; //3.14 0

	struct Segment {
		Segment()
		{}
		Segment (double length)
			: p2(length, 0)
		{}
		Point3 p1;
		Point3 p2;
	};

	Segment s1;
	cout << s1.p2.x << " " << s1.p2.y << endl; //0 0
	Segment s2(2.71);
	cout << s2.p2.x << " " << s2.p2.y << endl; //2.71 0

	struct IntArray {
		explicit IntArray(size_t size)
			: size(size), data(new int[size])
		{}

		~IntArray() {						   //Деструктор
			delete [] data;
		}

		size_t size;
		int * data;
	}
}

int main(){
	stepik();
	return 0;
}