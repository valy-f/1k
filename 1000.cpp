#include <iostream>
#include <fstream>
#include <string>
#include <random>
using namespace std;

class Bin
{
public:
	void Generate(int N)
	{
		srand(time(NULL));
		ofstream file("c:\\tmp\\BIN1000.txt");
		for (int i = 0; i <= 1000; i++)
		{
			string s = "";
			for (int j = 0; j < N; j++)
			{
				int x = (rand() % 2);
				s += to_string(x);
			}
			file << s << "\n";
		}
		file.close();
	}
};
class Dec 
{
public:
	void Output()
	{
		ifstream readfile("c:\\tmp\\BIN1000.txt"); // open BIN
		string content;
		ofstream file("c:\\tmp\\DEC1000.txt"); // create DEC
		cout << content << "\n";
		while (getline(readfile, content)) {
			unsigned long long decimal = stoull(content, 0, 2);
			file << decimal << "\n";
		}
		file.close();
	} 
};
class Test
{
public:
	void Comparison()
	{
		ifstream readfile1("c:\\tmp\\BIN1000.txt"); // open BIN
		string conbin;
		ifstream readfile2("c:\\tmp\\DEC1000.txt"); // open DEC
		string condec;
		getline(readfile1, conbin);
		unsigned long long dec1 = stoull(conbin, 0, 2);
		getline(readfile2, condec);
		unsigned long long dec2 = stoi(condec);
		if (dec1 == dec2) {
			cout << "Numbers are equal, everything is correct.\n";
		}
		else {
			cout << "Numbers are not equal, something is wrong.\n";
		}
	}
};
int main()
{
	Bin a;
	a.Generate(8);
	Dec b;
	b.Output();
	Test c;
	c.Comparison();
	return 0;
}