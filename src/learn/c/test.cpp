#include <iostream>
#include <string>

using namespace std;

int &max(int &a, int &b);
ostream &operator+(string s, ostream &oo);

class SmartArray {
    public:
	int *A;
	int error = -99;
	SmartArray()
	{
		A = new int[10];
		A[5] = 9;
	}
	int& operator[](int p)
	{
		if (p > 9)
			return error;
		return A[p];
	}
};

int main(void)
{
	int x = 10;
	int y = 15;
	max(x, y) = 7;
	cout << y << endl;
	"International Baccalaureate\n" + ("Sandy" + ("Quantum" + cout));

	SmartArray a;
	a[5] = 6;
	cout << a[5] << endl;
	cout << a[15] << endl;
}







ostream &operator+(string s, ostream &oo)
{
	cout << s;
	return oo;
}

int &max(int &a, int &b)
{
	return (a > b) ? a : b;
}
