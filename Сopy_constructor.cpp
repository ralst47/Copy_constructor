#include <iostream>

using namespace std;

struct Sample
{
	int* ptr;
	int size;
	Sample(int n) : size(n), ptr(new int[n])
	{
		cout << "default" << endl;
		for (int i = 0; i < size; i++)
		{
			ptr[i] = i + 1;
			cout << ptr[i] << " ";
		}
		cout << endl << endl;
	}
	Sample(const Sample& copy) : size(copy.size), ptr(new int[copy.size])
	{
		for (int i = 0; i < copy.size; i++)
		{
			ptr[i] = copy.ptr[i];
		}
		cout << "copy" << endl;
		for (int c = 0; c < size; c++)
		{
			ptr[c] = c + 1;
			cout << ptr[c] << " ";
		}
		cout << endl << endl;
	}
	Sample& operator= (const Sample& copy)
	{
		cout << "operator =" << endl;
		delete[] ptr;
		size = copy.size;
		ptr = new int[size];
		for (int c = 0; c < size; c++)
		{
			ptr[c] = copy.ptr[c];
			cout << ptr[c] << ' ';
		}
		return *this;
	}
	~Sample()
	{
		delete[] ptr;
	}
};

int main()
{
	Sample s1(5);
	Sample s2 = s1;
	Sample s3(3);
	s2 = s3;
	cout << endl;
}