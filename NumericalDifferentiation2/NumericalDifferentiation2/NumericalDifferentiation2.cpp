// NumericalDifferentiation2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double h = 0.0001;

double F(vector<double> x)
{
	//return x[0] * x[0] + x[1] * x[1];
	return pow(x[0], 2) + pow(x[1], 2) + pow(x[2], 2) + pow(x[3], 2);
	//return pow(x[0], 2) + pow(x[1], 2);
	//return (x[0] + 2) * (x[0] + 2) + (x[1] + 5) * (x[1] + 5) + (x[2] + 6) * (x[2] + 6) + (x[3] + 10) * (x[3] + 10);
}

double** dFXY(vector<double> x)
{
	double** res;
	vector<double> temp(x.size());
	vector<double> temp2(x.size());
	vector<double> temp3(x.size());
	vector<double> temp4(x.size());
	int i, j, k, n;
	n = x.size();

	res = new double* [n];
	for (i = 0; i < n; i++)
	{
		res[i] = new double[n];
	}

	for (i = 0; i < n; i++)//i - Элемент по которому берем частную производную первого порядка
	{
		for (j = i; j < n; j++)//j - Элемент по которому берем второй раз частную проивзодную
		{
			if (i == j)
			{
				for (k = 0; k < n; k++)
				{
					if (k == j)
					{
						temp[k] = x[k] + h;
						temp2[k] = x[k] - h;
					}
					else
					{
						temp[k] = x[k];
						temp2[k] = x[k];
					}
				}
				res[i][j] = (F(temp) - 2 * F(x) + F(temp2)) / (h * h);
			}
			else
			{
				for (k = 0; k < n; k++)
				{
					if (k == i)
					{
						temp[k] = x[k] + h;
						temp2[k] = x[k] + h;
						temp3[k] = x[k] - h;
						temp4[k] = x[k] - h;
					}
					else if (k == j)
					{
						temp[k] = x[k] + h;
						temp2[k] = x[k] - h;
						temp3[k] = x[k] + h;
						temp4[k] = x[k] - h;
					}
					else
					{
						temp[k] = x[k];
						temp2[k] = x[k];
						temp3[k] = x[k];
						temp4[k] = x[k];
					}
				}
				res[i][j] = (F(temp) - F(temp2) - F(temp3) + F(temp4))  / (4 * h * h);
				res[j][i] = (F(temp) - F(temp2) - F(temp3) + F(temp4))  / (4 * h * h);
			}
		}
	}
	return res;
}

int main()
{
	double** df1;
	vector<double> function;
	int n, i, j;
	double point;
	cout << "n: ";
	cin >> n;
	cout << "Point: ";
	for (i = 0; i < n; i++)
	{
		cin >> point;
		function.push_back(point);
	}

	df1 = dFXY(function);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << df1[i][j] << "\t";
		}
		cout << endl;
	}


	return 0;
}
