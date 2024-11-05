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

		void inputc2()
		{
			cout << "\ninput string: ";
			getline(cin, s);
		}

		void outputc2()
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

class CThree : public CTwo
{
	private:

		int number;

	public:
		//по умолчанию
		CThree() : CTwo(), number(0) {}

		//с параметрами
		CThree(const string s, const COne &obj, int num) : number(num) {}

		//копирования
		CThree(const CThree& other) : CTwo(other), number(other.number) {}

		//оператор присваивания
		CThree& operator=(const CThree& other)
		{
			if (this == &other)
			{
				return *this;
			}

			number = other.number;

			return *this;
		}

		void inputc3()
		{
			inputc2();
			cout << "\nEnter number: ";
			cin >> number;
			cout << endl;
		}

		void outputc3()
		{
			outputc2(); //
			cout << "\n number: " << number << endl;	
		}

		int get_number()
		{
			return number;
		}
};

int main()
{
	COne t1;

	t1.input();

	t1.output();


	CTwo t2("ctwo", t1);

	t2.inputc2();

	t2.outputc2();


	CThree t3;

	//t3.inputc3();

	t3.outputc3();

	return 0;
}