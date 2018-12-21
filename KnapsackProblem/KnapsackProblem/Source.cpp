#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

class Knapsack
{
	public:
		Knapsack(string, string);
		~Knapsack();
		void Solve();

	protected:
		ifstream input;
		ofstream output;

	private:
		void Allocate();
		void Deacllocate();
		void ReadData();

		int N;
		int G;
		vector<int> V;
		vector<int> W;
		vector< vector<int> > P;
};

Knapsack::Knapsack(string in = "knapsack.in", string out = "knapsack.out")
{
	input = ifstream(in);
	output = ofstream(out);

	ReadData();
}

void Knapsack::Allocate()
{
	V.resize(N);
	W.resize(N);
	P.resize(N);
	for (int i = 0; i < N; ++i)
		P[i].resize(G);
}

void Knapsack::Deacllocate()
{
	vector<int>().swap(V);
	vector<int>().swap(W);
	vector<vector<int>>().swap(P);
}

void Knapsack::ReadData()
{
	input >> N >> G;
	Allocate();
	for (int i = 0; i < N; ++i)
		input >> W[i] >> V[i];
}

void Knapsack::Solve()
{
	
}

Knapsack::~Knapsack()
{
	input.close();
	output.close();
	Deacllocate();
}

int main()
{
	Knapsack obj;
	obj.Solve();

	return 0;
}