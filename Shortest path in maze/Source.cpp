//TO  fIND SHORTEST   PATH IN MAZE
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;



class PATH_FINDER
{
private:

	int row_no;

	int column_no;
public:
	PATH_FINDER()
	{
		row_no = column_no = 0;

	}
	PATH_FINDER(int   n, int m)
	{
		row_no = n; column_no = m;
	}
	//_____SET AND GET FOR ROW
	int get_rows_no()
	{
		return row_no;
	}

	int set_rows_no(int input)
	{
		row_no = input;
		return row_no;
	}
	//_____SET AND GET FOR COLUMN
	int get_column_no()
	{
		return column_no;
	}

	int set_column_no(int input1)
	{
		column_no = input1;
		return column_no;
	}
	//_________________________________________________________


	void getting_values_from_file(int** a, int&, int&);

	void Printing_matrix(int** list, int& R_limit, int& C_limit);

	bool is_valid_path(int** a, int x, int y);

	bool shortest_path(int** a, int x, int y, int** matrix);

	void printing(int** a, int x, int y, int** matrix, int R_limit, int C_limit, int&);

	//_________________________________________________________


};

/* Function To Check The Path if Its 1 or 0*/

bool PATH_FINDER::is_valid_path(int** a, int x, int y)
{
	if (a[x][y] == 1)
	{
		return true;
	}
	return false;
}

bool PATH_FINDER::shortest_path(int** a, int x, int y, int** matrix)
{
	PATH_FINDER s;

	if (x == 6 && y == 4)		// According to the  Condition 6 Row And 4 Column Is The Destination 
	{
		matrix[x][y] = 1;
		return true;
	}
	if (s.is_valid_path(a, x, y))
	{
		matrix[x][y] = 1;

		if (shortest_path(a, x + 1, y, matrix))
		{
			return true;
		}
		if (shortest_path(a, x, y + 1, matrix))
		{
			return true;
		}
		if (shortest_path(a, x, y - 1, matrix))
		{
			return true;
		}
		if (shortest_path(a, x - 1, y, matrix))
		{
			return true;
		}
		matrix[x][y] = 0;
		return false;
	}
	return false;
}

void PATH_FINDER::printing(int** a, int x, int y, int** matrix, int R_limit, int C_limit, int& limit1)
{
	PATH_FINDER obj;
	if (obj.shortest_path(a, x, y, matrix))
	{
		for (int loop = 0; loop < R_limit; loop++)
		{
			for (int loop1 = 0; loop1 < C_limit; loop1++)
			{
				{
					cout << matrix[loop][loop1] << " ";
					if (matrix[loop][loop1] == 1)
					{
						limit1++;
					}

				}
			}
			cout << endl;
		}
	}
}

//Function to read  values from  the  file
void PATH_FINDER::getting_values_from_file(int** list, int& R_limit, int& C_limit)
{

	char File_name[20];
	cout << "\nENTER FILE NAME FOR GENERATING MATRIX:";
	cin.getline(File_name, 20);
	cout << "\nMATRIX CONSTRUCTED FROM USERS FILE:\n";
	ifstream output;
	output.open(File_name);	//FILE  NAME  FROM MAIN GIVEN  BY USER
	for (int loop = 0; loop < R_limit; loop++)
	{
		for (int loop1 = 0; loop1 < C_limit; loop1++)
		{
			output >> (list[loop][loop1]);
		}
	}
	Printing_matrix(list, R_limit, C_limit);
}

void  PATH_FINDER::Printing_matrix(int** list, int& R_limit, int& C_limit)
{
	cout << "\n MATRIX :\n";
	for (int loop = 0; loop < R_limit; loop++)
	{
		for (int loop1 = 0; loop1 < C_limit; loop1++)
		{
			cout << list[loop][loop1] << " ";
		}
		cout << endl;
	}
}



int main()
{
	PATH_FINDER s;

	s.set_rows_no(9);	//9...........as according to the matrix given
	s.set_column_no(10);	//10......as according to the matrix given
	cout << endl;
	cout << "THE ROW NUMBER IS" << s.get_rows_no();
	cout << endl;
	cout << "THE COLUMN NUMBER IS" << s.get_column_no();
	cout << endl;

	//________DYNAMIC_ALLOCATION_OF_TWO-D_ARRAY_________
	//INTIALIZING  MATRIX #1
	int** matrix_array1 = new int* [s.get_rows_no()];
	for (int loop = 0; loop < s.get_rows_no(); loop++)
	{
		matrix_array1[loop] = new int[s.get_column_no()];
	}
	//INTIALIZING  MATRIX #2
	int** matrix_array2 = NULL;
	matrix_array2 = new int* [s.get_rows_no()];
	for (int loop2 = 0; loop2 < s.get_rows_no(); loop2++)
	{
		matrix_array2[loop2] = new int[s.get_column_no()];
	}
	int R_limit = s.get_rows_no();
	int C_limit = s.get_column_no();

	cout << "matrix\n";
	for (int loop = 0; loop < R_limit; loop++)
	{
		for (int loop1 = 0; loop1 < C_limit; loop1++)
		{
			matrix_array2[loop][loop1] = 0;
		}
	}

	//FOR MATRIX 1.....as given in  question
	s.getting_values_from_file(matrix_array1, R_limit, C_limit);//Num_file.txt

	//________________________MENU____________________________

	int a = 0; int bb = 0;//source point
	int limit = 0;
	cout << endl;
	//Function displaying shortest path
	s.printing(matrix_array1, a, bb, matrix_array2, R_limit, C_limit, limit);
	//Path  will be -1  as we want path length from  source till  destination
	cout << "The Path Length  is :" << limit - 1;
	cout << endl << endl;


	delete[]matrix_array1;
	delete[]matrix_array2;

	return 0;
}