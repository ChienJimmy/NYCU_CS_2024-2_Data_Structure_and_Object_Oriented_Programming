#include <iostream>
using namespace std;

class Character{
    public:
        // Don't modify the Character constructor and destructor
        Character(const string& name_, const int health_): name(name_), health(health_){cout << "Creating character, ...., ";}
        virtual ~Character(){}
        //Todo. Add the functions you need. 
        virtual void displayStatus(){}
        bool isAlive(){return (health>0);}
        virtual void attack(Character &B){}
        void remainHealth(){
            cout << name << " health: " << health << "\n";
        }
        string getname(){
            return name;
        }
        void attack(int attackamount){
            health -= attackamount;
        }
        
    protected:
        string name;
        int health;
    
};

class Monster:public Character{
    public:
        // Todo, Complete the constructor and destructor.
        // Add the functions you need.
        Monster(const string& name, const int health, const int power_, const int attack_num_): Character(name, health) {
            this->power = power_ ;
            this->attack_num = attack_num_;
            cout << name << " is constructed.\n";
        }
        virtual ~Monster() override{
            cout << name << " is delete.\n"; }
        virtual void displayStatus() override{
            cout << "Name: " << name << ", Health: " << health << ", Power: " << power << ", Number of attack: " << attack_num << "\n";
        }
        virtual void attack(Character &B) override{
            B.attack(power * attack_num);
            cout << this->getname() << " attack " << B.getname() << "\n" << B.getname() << " take " << power * attack_num << " damage\n";
        }

        

        
    private:
        int power;
        int attack_num;

};

class Player:public Character{
    public:
        // Todo, Complete the constructor and destructor.
        // Add the functions you need.
        Player(const string& name, const int health, const int power_): Character(name, health) {
            this->power = power_ ;
            cout << name << " is constructed.\n";
        }
        virtual ~Player() override{
            cout << name << " is delete.\n";
        }
        virtual void displayStatus() override{
            cout << "Name: " << name << ", Health: " << health << ", Power: " << power << "\n";
        }
        virtual void attack(Character &B) override{
            B.attack(power);
            cout << this->getname() << " attack " << B.getname() << "\n" << B.getname() << " take " << power << " damage\n";
        }   

        
    private:
        int power;

};


int main(){
    int test = 1;
    cin >> test;
    //constructor
    cout << "-----Create Game ------" << endl;
    string name;
    int health, attack, numAttack;
    cin >> name >> health >> attack >> numAttack;
    Character* M = new Monster(name, health, attack, numAttack);
    cin >> name >> health >> attack;
    Character* P = new Player(name, health, attack);

    
    //character info
    cout << endl << "-----Character Info------" << endl;
    M->displayStatus();
    P->displayStatus();

    if (test >= 3){
        //start game
        cout << endl << "-----Play Info------" << endl;
        bool player_term = false;
        while(M->isAlive() && P->isAlive()){
            if(player_term) P->attack(*M);
            else M->attack(*P);
            M->remainHealth();
            P->remainHealth();
            player_term = !player_term;
            cout << "------------" << endl;
        }
        //declare winner
        if (P->isAlive()) cout << P->getname() << " Win !!!" << endl;
        else cout << M->getname() << " Win !!!" << endl;
    }
    
    if(test >= 2){
        //destructor
        cout << endl << "-----End Game ------" << endl;
        delete M;
        delete P;
    }
    
    return 0;
}