#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

//33

using namespace std;

class COne
{
	private:

		float f;
		char *ps;

	public:
		//конструктор по умолчанию
		COne() : f(1), ps(nullptr) {}

		//Консруктор с заданными параматрами
		COne(float a, char str[1024]) : f(a), ps(str)
		{
			ps = new char[strlen(str) + 1];
			strcpy(ps, str);
		}

		//Конструктор копирования
		COne(const COne& other) : f(other.f), ps(other.ps)
		{
			if (other.ps)
			{
				ps = new char[strlen(other.ps) + 1];
				strcpy(ps, other.ps);
			}
			else
			{
				ps = nullptr;
			}
		}

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
			cout << "Input float number: ";
			cin >> f;

			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			char buffer[1024];
			cout << "\nInput string: ";
			cin.getline(buffer, 1024);

			ps = new char[strlen(buffer) + 1];
			strcpy(ps, buffer);
		}

		void output()
		{
			cout << "\nf: " << f << endl;
			cout << "\n*ps: " << ps << endl;
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
		CTwo() : s(""), obj() {}

		//Консруктор с заданными параматрами
		CTwo(const string &str, const COne &exmpl) : s(str), obj(exmpl) {}

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
			cout << "\ninput string: ";
			getline(cin, s);
		}

		void output()
		{
			cout << "\nCTwo string: " << s << "\nCOne object: (" << endl;
			
			obj.output();

			cout << "\n);" << endl;
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
	COne t1;

	t1.input();

	t1.output();

	CTwo t2("ctwo", t1);

	t2.input();

	t2.output();

	return 0;
}