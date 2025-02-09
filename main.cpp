#include <iostream>
#include <string>
using namespace std;

int getTotal(const int firstNumber, const int secondNumber) {
    const int total = firstNumber + secondNumber;
    return total;
}


string getGreeting(const string name) {
    const string greeting = "Hello " + name;
    return greeting;
}

void aneManda(const int age) {
    const int newAge = age + 10;
    cout << newAge << endl;

}

int main() {

    aneManda(20);
    return 0;

}
