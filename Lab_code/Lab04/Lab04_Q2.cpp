#include <iostream>
using namespace std;
#include <string>
/*
    Each monster has three variables: evolution time, attack, and name.
    evolution time: Record how many times this monster evolves (+=).
    attack: The attack power of this monster, using for comparison (<).
    name: The name of this monster.
*/
class Monster{
    public:
        void Create(int attack_, string name_){ attack=attack_; evolution_time=1; name = name_;}
        double Attack() const{return attack;}
        //ToDo get infomation: evolution_time, attack
        string GetName() const{return name;}
        int GetEvolutiontime() const{return evolution_time;}
        double GetAttack() const{return attack;}
        

        bool operator<(const Monster &rhs) const;
        const Monster operator + (const Monster &rhs) const;
        Monster & operator += (const int value);
        Monster & operator += (const Monster &rhs);

    private:
        int evolution_time = 0;
        double attack = 0;
        string name;

};

bool Monster::operator < (const Monster &rhs) const{
    //Todo
    bool result = this->attack < rhs.attack;
    return result;
}

Monster & Monster::operator += (const Monster &rhs){
    //Todo
    this->attack += rhs.attack;
    this->evolution_time += rhs.evolution_time;
    return *this;
}

Monster & Monster::operator += (const int value){
    //Todo
    this->attack += value;
    this->evolution_time += 1;
    return *this;
}

const Monster Monster::operator + (const Monster &rhs) const{
    //Todo
    Monster temp;
    temp.attack = this->attack + rhs.attack;
    temp.evolution_time = this->evolution_time + rhs.evolution_time;
    return temp;
}   

ostream& operator<<(ostream& out, const Monster &rhs){
    //Todo
    out << "This Monster is " << rhs.GetName() << ", attack = " << rhs.GetAttack() << ", evolution time = " << rhs.GetEvolutiontime();
    return out;
}

int main(){
    Monster Werewolf, Vampire, Slime, Ghost, Goblin;
    int att1, att2, att3, att4, att5;
    int test;
    cin >> test;
    cin >> att1 >> att2 >> att3 >> att4 >> att5;
    Werewolf.Create(att1, "Werewolf");
    Vampire.Create(att2, "Vampire");
    Slime.Create(att3, "Slime");
    Ghost.Create(att4, "Ghost");
    Goblin.Create(att5, "Goblin");

    if(test >= 1){
        if (Werewolf < Vampire) {
            cout << "Vampire is powerful." << endl;
        } 
    } 
    
    if(test >= 2){
        (Werewolf += Slime) += 20;
        if (Vampire < Werewolf) {
            cout << "Werewolf gets strong." << endl;
        } 
    }

    if(test >= 3){
        if (Werewolf < Vampire + Goblin) { 
            cout << "Unity makes strength." << endl;
        }
        if (Werewolf < Vampire) {
            cout << "Wrong answer." << endl;
        }
        if (Vampire < Goblin + Slime + Ghost){
            cout << "Three monsters are better than one." << endl;
        }
    }

    if(test >= 4){
        cout << Werewolf << endl;
        cout << Slime << endl;
        cout << Vampire << endl;
        cout << Ghost << ", " << Goblin << endl;
    }

    return 0;
}