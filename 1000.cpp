#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>
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
class Sorting
{
public:
	vector<int> v;

	void remove(std::vector<int>& v)
	{
		auto end = v.end();
		for (auto it = v.begin(); it != end; ++it) {
			end = std::remove(it + 1, end, *it);
		}

		v.erase(end, v.end());
	}

	void Ascending()
	{
		
		ifstream read("c:\\tmp\\DEC1000.txt"); // open DEC
		string nums;

		while (getline(read, nums)) {

			int integers = stoi(nums);
			v.push_back(integers);
		}
		sort(v.begin(), v.end());
		ofstream f("c:\\tmp\\s.ascending1000.txt");
		f << "Sorted (ascending): " << "\n";
		remove(v);
		for (auto x : v) {
			f << x << "\n";
		}
	}
	void Descending()
	{
		ifstream read("c:\\tmp\\DEC1000.txt"); // open DEC
		string nums;
		
		while (getline(read, nums)) {
			int integers = stoi(nums);
			v.push_back(integers);
		}
		sort(v.begin(), v.end(), greater<int>());

		ofstream f2("c:\\tmp\\s.descending1000.txt");
		f2 << "Sorted (descending): " << "\n";
		remove(v);
		for (auto x : v) {
			f2 << x << "\n";
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
	Sorting d;
	d.Ascending();
	d.Descending();
	return 0;
