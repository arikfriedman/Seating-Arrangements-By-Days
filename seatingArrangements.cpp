#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//#define regular 1
//#define border 2
//#define corner 3

using namespace std;


//ifstream infile("graph.txt");
ofstream outfile("graph.txt");

int main()
{
	int rows, cols , type;
	//Read Graph
	cout << "making seating arrangements for my mom:" << endl;
	cout << "please enter number of rows and columns:" << endl;
	cin >> rows >> cols;

	int total_seats = rows * cols;
	outfile << total_seats << endl;

	int** matrix = new int*[total_seats];
	for (int i = 0; i < total_seats; ++i)
		matrix[i] = new int[total_seats]();

	for (int i = 0; i < total_seats; i++)
	{
		if (i - cols >= 0)
			matrix[i][i - cols] = 1;
		if (i - cols + 1 >= 0 && (i % cols) != cols - 1)
			matrix[i][i - cols + 1] = 1;
		if (i - cols -1  >= 0 && (i % cols) != 0)
			matrix[i][i - cols - 1 ] = 1;
		if (i + cols < total_seats)
			matrix[i][i + cols] = 1;
		if (i + cols - 1 < total_seats && (i % cols) != 0)
			matrix[i][i + cols - 1] = 1;
		if (i + cols + 1 < total_seats && (i % cols) != cols - 1)
			matrix[i][i + cols + 1] = 1;
		if ((i % cols) != 0)
			matrix[i][i - 1] = 1;
		if ((i % cols) != cols - 1)
			matrix[i][i + 1] = 1;
	}

	for (int i = 0; i < total_seats; i++)
	{
		for (int j = 0; j < total_seats; j++)
		{
			outfile <<" "<< matrix[i][j];
		}
	outfile <<  endl;
	}


	for (int i = 0; i < rows; ++i)
		delete[] matrix[i];
	delete[] matrix;

	system("pause");
	return 0;
}



