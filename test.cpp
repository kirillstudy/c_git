#include <iostream>
#include <cstdlib>
using namespace std;


char *resize(const char *str, unsigned size, unsigned new_size)
{
	char * n = new char[new_size];
    for(int i = 0; i < new_size; i++){
        n[i] = str[i];
    }
    delete [] str;
    return n;
}

char *getline(){
	char * my_char = new char[1];
	int last = 0;
	char c;
	for(int i = 1; cin.get(c) && c != '\n'; i++){
		my_char = resize(my_char, i, i + 1);
		my_char[i - 1] = c;
		last = i;
	}
	my_char[last] = '\0';
	return my_char;
}

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    
}

int main() {
	
}

/* example function for arrays

bool contains(int * m, int size, int value) {
	for(int i = 0; i != size; ++i) {
	if (m[i] == value) {
			return true;
		}
	}
}
*/
	//int * m = (int *)malloc(1000 * sizeof(int));
	//m = (int *)realloc(m, 2000 * sizeof(int));
	//free(m);
	//m = (int *)calloc(3000, sizeof(int));
}