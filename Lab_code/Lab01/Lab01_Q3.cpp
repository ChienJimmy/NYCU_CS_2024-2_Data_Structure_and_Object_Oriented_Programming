#include <iostream>
using namespace std;
int main(){
    int input;
    cin >> input;
    for (int times = 0; times < input; times++){
        int i1, j1, i2,j2;
        int m1[1000][1000], m2[1000][1000];
        cin >> i1 >> j1;
        for (int i = 0; i < i1; i++){
            for (int j = 0; j < j1; j++){
                cin >> m1[i][j];
            }
        }
        cin >> i2 >> j2;
        for (int i = 0; i < i2; i++){
            for (int j = 0; j < j2; j++){
                cin >> m2[i][j];
            }
        }
        int op = 0;
        if (i1 == i2 && j1 == j2){
            op = 1;
            cout << "Addition:\n";
            for (int i = 0; i < i2; i++){
                for (int j = 0; j < j2; j++){
                    cout << (m1[i][j] + m2[i][j]) << " ";
                }
                cout << "\n";
            }
            cout << "Subtraction:\n";
            for (int i = 0; i < i2; i++){
                for (int j = 0; j < j2; j++){
                    cout << (m1[i][j] - m2[i][j]) << " ";
                }
                cout << "\n";
            }
        }
        if (j1 == i2){
            op = 1;
            cout << "Multiplication:\n";
            for (int i = 0; i < i1; i++){
                for (int j = 0; j < j2; j++){
                    int sum(0);
                    for (int k = 0; k < j1; k++){
                        sum += (m1[i][k] * m2[k][j]);
                    }
                    cout << sum << " ";
                }
                cout << "\n";
            }
        }
        if (op == 0){
            cout << "Can not do any operation.\n";
        }
        if (times != input -1){
            cout << "---------------\n";
        }
    }
}