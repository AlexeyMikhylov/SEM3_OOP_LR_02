#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

//33

using namespace std;

class COne
{
	private:

		float f;
		char *ps;

		void copy()
		{
			//do smth
		}

		void alloc()
		{
			//get string size
		}

	public:
		//конструктор по умолчанию
		COne() : f(1)
		{
			int size = (int)f;
			ps = new char[size];
		}

		//Консруктор с заданными параматрами
		COne(float a) : f(a)
		{
			int size = (int)f;
			ps = new char [size];
		}

		//Конструктор копирования
		COne(const COne& other) : f(other.f), ps(other.ps) {}

		//Оператор присваивания
		COne& operator=(const COne& other)
		{
			if (this == &other)
			{
				return *this;
			}

			delete[] ps;

			f = other.f;
			ps = other.ps;

			return *this;
		}

		void input()
		{
			cin >> ps;
		}

		void output()
		{
			cout << "\n" << f << endl;
			cout << "\n" << ps << endl;
		}

		float get_f()
		{
			return f;
		}

		char* get_ps()
		{
			return ps;
		}

		//Деструктор
		~COne()
		{
			delete[] ps;
		}
};

class CTwo
{
	private:

		string s;
		COne obj;

	public:
		//конструктор по умолчанию
		CTwo() : s("0"), obj(0) {}

		//Консруктор с заданными параматрами
		CTwo(string str, COne exmpl) : s(str), obj(exmpl) {}

		//Конструктор копирования
		CTwo(const CTwo& other) : s(other.s), obj(other.obj) {}

		//Оператор присваивания
		CTwo& operator=(const CTwo& other)
		{
			if (this == &other)
			{
				return *this;
			}

			s = other.s;
			obj = other.obj;

			return *this;
		}

		void input()
		{
			cin >> s;
		}

		void output()
		{
			cout << "\n" << s << endl;
			obj.output();
		}

		string get_s()
		{
			return s;
		}

		COne get_obj()
		{
			return obj;
		}

		//Деструктор
		~CTwo() {}
};

int main()
{
	COne test1(4);

	cout << "\n\nCOne class: \n" << endl;

	test1.input();
	test1.output();

	CTwo test2("CTwo", test1);

	cout << "\n\nCTwo class: \n" << endl;
	
	test2.output();

	return 0;
}