#include <iostream>
#include <cmath>
using namespace std;

double P0(const double K, const double N);
double P1(const double K, const double N, const int i);
double P2(const double K, const double N, const int i);
double P3(const double K, const double N, const int i, double t);
double P4(const double K, const double N, const int i, double t);

int main()
{
	int K = 1;
	int N = 15;

	cout << "(iter) P0 = " << P0(K, N) << endl;
	cout << "(rec up ++) P1 = " << P1(K, N, K) << endl;
	cout << "(rec up --) P2 = " << P2(K, N, N) << endl;
	cout << "(rec down ++) P3 = " << P3(K, N, K, 0) << endl;
	cout << "(rec down --) P4 = " << P4(K, N, N, 0) << endl;
}
double P0(const double K, const double N)
{
	double p = 0;
	for (int i = K; i <= N; i++) 
		p += (pow(sin(i), 2) + pow(cos(1 / i), 2)) / i * i;
	return p;
}
double P1(const double K, const double N, const int i) 
{
	if (i > N)
		return 0;
	else
		return ((pow(sin(i), 2) + pow(cos(1 / i), 2)) / i * i) + P1(K, N, i+1);
}
double P2(const double K, const double N, const int i)
{
	if (i < K)
		return 0;
	else
		return ((pow(sin(i), 2) + pow(cos(1 / i), 2)) / i * i) + P2(K, N, i-1);
}
double P3(const double K, const double N, const int i, double t)
{
	t = t + ((pow(sin(i), 2) + pow(cos(1 / i), 2)) / i * i);
	if (i >= N)
		return t;
	else
		return P3(K, N, i+1, t);
}
double P4(const double K, const double N, const int i, double t)
{
	t = t + ((pow(sin(i), 2) + pow(cos(1 / i), 2)) / i * i);
	if (i <= K)
		return t;
	else
		return P4(K, N, i - 1, t);
}