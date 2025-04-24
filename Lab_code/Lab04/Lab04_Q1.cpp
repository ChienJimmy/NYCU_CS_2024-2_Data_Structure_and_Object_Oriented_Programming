#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class Calculator {
// TODO
public:
    int add(int a, int b);
    double add(double a, double b);
    string add(string a, string b);
    int subtract(int a, int b);
    double subtract(double a, double b);
    string subtract(string a, string b);
    int multiply(int a, int b);
    double multiply(double a, double b);
    string multiply(string a, string b);
    int divide(int a, int b);
    double divide(double a, double b);
    string divide(string a, string b);
};

// TODO
template <typename T>
int Calculator<T>::add(int a, int b){
    return a + b;
}
template <typename T>
double Calculator<T>::add(double a, double b){
    return a + b;
}
template <typename T>
string Calculator<T>::add(string a, string b){
    return a + b;
}

template <typename T>
int Calculator<T>::subtract(int a, int b){
    return a - b;
}
template <typename T>
double Calculator<T>::subtract(double a, double b){
    return a - b;
}
template <typename T>
string Calculator<T>::subtract(string a, string b){
    return "Subtraction is not supported for strings.";
}

template <typename T>
int Calculator<T>::multiply(int a, int b){
    return a * b;
}
template <typename T>
double Calculator<T>::multiply(double a, double b){
    return a * b;
}
template <typename T>
string Calculator<T>::multiply(string a, string b){
    return "Multiplication is not supported for strings.";
}

template <typename T>
int Calculator<T>::divide(int a, int b){
    if (b == 0){
        return -100;
    }
    return a / b;
}
template <typename T>
double Calculator<T>::divide(double a, double b){
    if (b == 0){
        return -100;
    }
    return a / b;
}
template <typename T>
string Calculator<T>::divide(string a, string b){
    return "Division is not supported for strings.";
}


int main(){
    int intone, inttwo;
    double doubleone, doubletwo;
    string stringone, stringtwo;
    cin >> intone >> inttwo;
    cin >> doubleone >> doubletwo;
    cin >> stringone >> stringtwo;

    Calculator<int> intCalc;
    int intadd, intsubstract, intmultiply, intdivide;
    intadd = intCalc.add(intone, inttwo);
    intsubstract = intCalc.subtract(intone, inttwo);
    intmultiply = intCalc.multiply(intone, inttwo);
    intdivide = intCalc.divide(intone, inttwo);

    Calculator<double> doubleCalc;
    double doubleadd, doublesubstract, doublemultiply, doubledivide;
    doubleadd = doubleCalc.add(doubleone, doubletwo);
    doublesubstract = doubleCalc.subtract(doubleone, doubletwo);
    doublemultiply = doubleCalc.multiply(doubleone, doubletwo);
    doubledivide = doubleCalc.divide(doubleone, doubletwo);

    Calculator<std::string> stringCalc;
    string stringadd, stringsubstract, stringmultiply, stringdivide;
    stringadd = stringCalc.add(stringone, stringtwo);
    stringsubstract = stringCalc.subtract(stringone, stringtwo);
    stringmultiply = stringCalc.multiply(stringone, stringtwo);
    stringdivide = stringCalc.divide(stringone, stringtwo);

    // TODO
    cout << intadd << "\n" << intsubstract << "\n" << intmultiply << "\n";
    if (intdivide == -100){
        cout << "Division by zero is not allowed.\n";
    } else {
        cout << intdivide << "\n";
    }
    printf("%.2f\n%.2f\n%.2f\n", doubleadd, doublesubstract, doublemultiply);
    if (doubledivide == -100){
        cout << "Division by zero is not allowed.\n";
    } else {
        printf("%.2f\n", doubledivide);
    }
    cout << stringadd << "\n" << stringsubstract << "\n" << stringmultiply << "\n" << stringdivide << "\n";

    return 0;
}