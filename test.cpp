#include <iostream>
<<<<<<< HEAD
using namespace std;
int main(){
    cout << "Test Successful\n";
=======

int main() {
    int times;
    std::cin >> times;
    for (int i = 0; i < times; i++) {
        int sides;
        std::cin >> sides;
        long long lengthsum = 0, maxlength = 0, sidelength;
        for (int j = 0; j < sides; j++) {
            std::cin >> sidelength;
            lengthsum += sidelength;
            if (maxlength < sidelength) maxlength = sidelength;
        }
        if (lengthsum > 2 * maxlength) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
>>>>>>> d6507e7 (Initial commit)
    return 0;
}