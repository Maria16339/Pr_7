#include <iostream> 
#include <float.h>  
#include <iomanip>
using namespace std;  
int main()
 {    
	setlocale(LC_ALL, "Russian");
   
double sum, max;    
int x, y;

cout << "¬ведите кол-во строк  в массиве  : ";

cin >> x;

cout << "¬ведите кол-во столбцов в массиве: ";

cin >> y;

cout << y << endl;



int** mat = new int* [x];

for (int i = 0; i < x; i++)

    mat[i] = new int[y];



cout << "ѕервоначальный массив: " << endl;

for (int i = 0; i < x; i++)

    for (int j = 0; j < y; j++)

        mat[i][j] = rand() % 21 - 10;



for (int i = 0; i < x; i++)

{

    for (int j = 0; j < y; j++)

        cout << setw(3) << mat[i][j] << " ";

    cout << endl;

}

sum = 0; 

for (int i = 0; i < x; i++)    
{         
	max = DBL_MIN;
	for (int j = 0; j < y; j++) 		
	{            
		if (mat[i][j] > max)                
			max = mat[i][j];  		
	}         	
		sum += max; 	
}     
cout.precision(2);     
cout << fixed << "—умма наибольших значений строк: " << sum << endl;     
for (int i = 0; i < y; i++)    
{        
	delete[] mat[i];    
}    
system("pause");     
return 0;
}