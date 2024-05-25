#include <iostream>
#include <vector>
using namespace std ;

double recursiveExpression(const std::vector<double>& a, int n) {
    if (n == 1) {
        return a[0]; 
    }
    double lastTerm = a[n - 1];
    double previousResult = recursiveExpression(a, n - 1);
    if (n % 2 == 0) {
        return lastTerm;
    } else {
        return previousResult * lastTerm;
    }
}

int main() {
    std::vector<double> a = {1.0, 2.0, 3.0, 4.0, 5.0}; 
    int n = a.size();
    double result = recursiveExpression(a, n);
    std::cout << "result :" << result << std::endl;
    return 0;
}














