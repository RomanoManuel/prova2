#include<iostream>
#include<cstdlib>
#include <fstream>
#include <string>
#include<cstdio>

using namespace std;

class Hanoi{
public:
Hanoi() : count(1) {}

void TOH(int n, int source, int dest, int aux, int m, int k, ofstream& out) {

    if(n == 0) return;

    TOH(n - 1, source, aux, dest, m, k, out);
        int s = source, d = dest;

        if(count >= m && count<=k) {
        out<< s << " " << d <<" ";
        }	
        if(count>k)
        	return;
        count++;
    TOH(n - 1, aux, dest, source, m, k, out);
    
}
private:
int count;
};

int main()
{
    ifstream input("input.txt", ios::in);
	ofstream output("output.txt", ios::out);

    int N, H, K;
    for(int i=0; i<100; i++)
    {
    input >> N >> H >> K;
    Hanoi h;
    h.TOH(N,1,3,2,H, K, output);
    output << endl;
    }
    return 0;
}
