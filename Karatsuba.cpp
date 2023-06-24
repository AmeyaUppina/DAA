#include <iostream>
#include<string>
#include<cmath>
using namespace std;

long long int karatsuba(int x, int y) {
    if (to_string(x).length() == 1 || to_string(y).length() == 1) {
        return x*y;
    }
    else {
        int n = max(to_string(x).length(), to_string(y).length());
        int nby2 = n / 2;
        int a = x / pow(10, nby2);
        int b = x % (int)pow(10, nby2);
        int c = y / pow(10, nby2);
        int d = y % (int)pow(10, nby2);
        int ac = karatsuba(a, c);
        int bd = karatsuba(b, d);
        int ad_plus_bc = karatsuba(a+b, c+d) - ac - bd;
        return ac * (int)pow(10, 2*nby2) + (ad_plus_bc * (int)pow(10, nby2)) + bd;
    }
}


int main() {
    cout<<"Ans: "<<karatsuba(1219253, 100000)<<"\n";
    return 0;
}
