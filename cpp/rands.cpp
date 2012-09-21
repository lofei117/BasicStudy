#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>

using namespace std;

int bigrand()
{
	return RAND_MAX*rand()+rand();
}

void gensets(int m, int n)
{
	set<int> S;
	while (S.size()<m)
	{
		S.insert(bigrand()%n);
	}
	set<int>::iterator i;
	for(i=S.begin(); i != S.end(); ++i)
		cout <<*i<<endl;
}
int main(int argc, char **args)
{
	srand((unsigned)time(NULL));
	gensets(1000000, 20000000);
	return 0;
}
