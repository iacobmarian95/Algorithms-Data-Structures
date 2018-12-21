#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
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

Knapsack::Knapsack(string in = "rucsac.in", string out = "rucsac.out")
{
	input = ifstream(in);
	output = ofstream(out);

	ReadData();
}

void Knapsack::Allocate()
{
	V.resize(N);
	W.resize(N);
	P.resize(N + 1);
	for (int i = 0; i <= N; ++i)
		P[i].resize(G + 1);
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
	for(int i = 0; i <= N; ++i)
		for (int w = 0; w <= G; ++w)
		{
			if (!i || !w)
			{
				P[i][w] = 0;
				continue;
			}

			if (W[i - 1] > w)
			{
				P[i][w] = P[i - 1][w];
				continue;
			}

			P[i][w] = max(P[i - 1][w], P[i - 1][w - W[i  -1]] + V[i - 1]);
		}

	output << P[N][G];
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