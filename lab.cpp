#include <iostream>
#include <vector>

using namespace std;

// A function to multiply two numbers represented as vectors
vector<int> multiply(vector<int> num1, vector<int> num2) {
    vector<int> result(num1.size() + num2.size(), 0);
    int carry = 0;
    for (int i = num2.size() - 1; i >= 0; i--) {
        carry = 0;
        for (int j = num1.size() - 1; j >= 0; j--) {
            int prod = num1[j] * num2[i] + carry + result[i + j + 1];
            carry = prod / 10;
            result[i + j + 1] = prod % 10;
        }
        result[i] = carry;
    }
    while (result.size() > 1 && result[0] == 0) {
        result.erase(result.begin());
    }
    return result;
}

// A function to calculate factorial of a number
vector<int> factorial(int n) {
    vector<int> result = {1};
    for (int i = 2; i <= n; i++) {
        vector<int> num(i / 10 + 1, 0);
        int j = i;
        int k = 0;
        while (j > 0) {
            num[k++] = j % 10;
            j /= 10;
        }
        result = multiply(result, num);
    }
    return result;
}

int main() {
    for (int i = 0; i <= 1000; i++) {
        vector<int> result = factorial(i);
        //cout << i << "! = ";
        //for (int j = 0; j < result.size(); j++) {
            //cout << result[j];
        //}
        //cout << endl;
    }
    return 0;
}
