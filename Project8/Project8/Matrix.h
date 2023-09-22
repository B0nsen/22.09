#pragma once

template<class T = int>
class Matrix
{
private:
	T** arr;
	int size1, size2;
public:
	Matrix();
	Matrix(Matrix& a);
	Matrix(Matrix&& a);
	void Print();
	void Input();
	void Random();
	~Matrix();
};

template<class T>
inline Matrix<T>::Matrix()
{
	arr = nullptr;
}

template<class T>
Matrix<T>::Matrix(Matrix& a)
{
	arr = new T * [a.size1];
	for (int i = 0; i < a.size2; i++)
	{
		arr[i] = new T * [size2];
	}
	for (int i = 0; i < a.size1; i++)
	{
		for (int j = 0; j < a.size1; j++)
		{
			arr[i][j] = a.arr[i][j];
		}
	}
}

template<class T>
Matrix<T>::Matrix(Matrix&& a)
{
	arr = new T * [a.size1];
	for (int i = 0; i < a.size2; i++)
	{
		arr[i] = new T * [size2];
	}
	for (int i = 0; i < a.size1; i++)
	{
		for (int j = 0; j < a.size1; j++)
		{
			arr[i][j] = a.arr[i][j];
		}
	}
	a.arr = nullptr;
	a.size1 = 0;
}

template<class T>
void Matrix<T>::Print()
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			std::cout << arr[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

template<class T>
void Matrix<T>::Input()
{
	std::cout << "Enter size1: ";
	std::cin >> size1;
	std::cout << "Enter size2: ";
	std::cin >> size2;
	if (arr != nullptr)
	{
		for (int i = 0; i < size1; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
	arr = new T * [size1];
	for (int i = 0; i < size1; i++)
	{
		arr[i] = new T[size2];
	}
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			std::cin >> arr[i][j];
		}
	}
}

template<class T>
void Matrix<T>::Random()
{
	std::cout << "Enter size1: ";
	std::cin >> size1;
	std::cout << "Enter size2: ";
	std::cin >> size2;
	if (arr != nullptr)
	{
		for (int i = 0; i < size1; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
	arr = new T * [size1];
	for (int i = 0; i < size1; i++)
	{
		arr[i] = new T[size2];
	}
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			arr[i][j] = 1;
		}
	}
}

template<class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < size1; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

