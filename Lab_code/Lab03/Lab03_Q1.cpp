#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    string id;
    int grade;
    float score;
public:
    Student(){}
    Student(string name, string id, int grade, float score){
        // TODO
        this->name = name;
        this->id = id;
        this->grade = grade;
        this->score= score;
    }
    string getName(){
        // TODO
        return name;
    }
    string getId(){
        // TODO
        return id;
    }
    int getGrade(){
        // TODO
        return grade;
    }
    float getScore(){
        // TODO
        return score;
    }
};


int main() {
    // TODO
    int gr;
    float sc;
    string id, na;
    cin >> na >> id >> gr >> sc;
    Student st(na, id , gr, sc);
    cout << st.getName() << "'s ID is " << st.getId() << ", grade is " << st.getGrade() << ", and score is " << st.getScore() << ".";
    return 0;
}