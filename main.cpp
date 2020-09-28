#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

double myfun(double x) {
    return (cos(x)*tan(x));
}

double myfun_sin5x(double x) {
    return sin(5 * x) * myfun(x);
}

int N_count(double q, double P) {
    return (ceil(log(1. - P) / log(1. - q)));
}

double Random(int a, int b)
{
    return a + (1.*rand()/RAND_MAX)*(b - a);   // (1.*rand()/RAND_MAX)-генерация числа от 0 до 1
}

int main() {
    int a = -2;
    int b = 0;
    int N;
    double MAX_DOUBLE = 1.7976931348623158*pow(10, 308);;
    double x;
    double q = 0.005;
    for (int i = 0; i < 20; i++) {
        double p = 0.9;
        for (int j = 0; j < 10; j++) {
            N = N_count(q, p);
            double min = MAX_DOUBLE;
            for (auto k = 0; k < N; k++) {
                x = Random(a, b);
                if (myfun(x) < min) min = myfun(x);
            }
            cout << "P = " << p << " q = " << q
                      << " N = " << N << " min: " << min << endl;
            p+=0.01;
        }
        q+=0.005;
    }
    cout << endl;
    q = 0.005;
    for (auto i = 0; i < 20; i++) {
        double p = 0.9;
        for (auto j = 0; j < 10; j++) {
            N = N_count(q, p);
            double min = MAX_DOUBLE;
            for (auto k = 0; k < N; k++) {
                x = Random(a, b);
                if (myfun_sin5x(x) < min) min = myfun_sin5x(x);
            }
            cout << "P = " << p << " q = " << q
                      << " N = " << N << " min: " << min << endl;
            p+=0.01;
        }
        q+=0.005;
    }
    return 0;
}