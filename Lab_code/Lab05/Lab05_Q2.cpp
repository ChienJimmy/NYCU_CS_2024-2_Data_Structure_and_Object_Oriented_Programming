#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Character{ 
private:
    string name = "goblin";
    int power = -1;
public:
    void ShowStasus(){
        // Print the name and the power
        cout << "name: ";
        // TODO
        cout << ShowName() << " power: " << ShowPower() << "\n";
    }
    // TODO
    string ShowName(){
        return name;
    }
    int ShowPower(){
        return power;
    }
    void SetName(string name_){
        name = name_;
    }
    void SetPower(int power_){
        power = power_;
    }
};

class Monster : public Character{
private:
    int hp = -1;
public:
    Monster(string name, int power){
        // TODO
        this->SetName(name);
        this->SetPower(power);
        hp = 100;
    }
    void ShowMonsterStasus(){
        ShowStasus();
        // TODO
        // Print the hp
        cout << "hp: " << ShowHP() << "\n";
    }
    // TODO block start
    // The monster attack the player
    void AttackPlayer(){

    }
    // The monster is attacked by the player
    // Modify the hp of the monster
    void AttackByPlayer(int damage){
		if (damage >= hp){
			hp = 0;
            return;
		}
        hp -= damage;
    }
    // TODO block end here
    // TODO
    int ShowHP(){
        return hp;
    }
};

class Player : public Character{
    private:
        int heart = -1;
        int def = -1;
    public:
        Player(string name, int power, int def){
            // TODO
            this->SetName(name);
            this->SetPower(power);
            SetDef(def);
            heart = 2;
        }
        void ShowPlayerStasus(){
            ShowStasus();
            // TODO
            cout << "heart: " << ShowHeart() << " def: " << ShowDef() << "\n";
        // Print the heart and the def
        }
        // TODO block start
        // The player attack the monster
        void AttackMonster(){
            
        }
        // The player is attacked by the monster
        // Modify the heart of the player
        void AttackByMonster(){
            if (heart <= 0){
                heart == 0;
            }
            heart -= 1;
            return;
        }
        // TODO block end here
        // TODO
        int ShowHeart(){
            return heart;
        }
        int ShowDef(){
            return def;
        }
        void SetDef(int def_){
            def = def_;
        }
};

void attack(Monster &monster, Player &player1, Player &player2) {
    // The monster start attacking the alive players first.
    // If the player's def < monster's power, the player's heart will be reduced by 1.
    // Then, if the player's heart > 0 (alive), the players will start attacking the monster.
    // The monster's HP will be reduced by the power of each alive player.
    // Use AttackMonster(), AttackByMonster(), AttackPlayer(), AttackByPlayer()
    // TODO
    if (player1.ShowHeart() >= 1){
        if (player1.ShowDef() < monster.ShowPower()){
            player1.AttackByMonster();
        }
        monster.AttackByPlayer(player1.ShowPower());
    }
    if (player2.ShowHeart() >= 1){
        if (player2.ShowDef() < monster.ShowPower()){
            player2.AttackByMonster();
        }
        monster.AttackByPlayer(player2.ShowPower());
    }
    monster.ShowMonsterStasus();
    player1.ShowPlayerStasus();
    player2.ShowPlayerStasus();
}

// TODO

int main(){
    // Each player has 2 heart when the game starts.
    // The monster's HP is 100 when the game starts.
    string name1, name2, name3;
    int power1, power2, def2, power3, def3, part2;
    cin >> name1 >> power1;
    cin >> name2 >> power2 >> def2;
    cin >> name3 >> power3 >> def3;
    cin >> part2;

    Monster M1(name1, power1);
    M1.ShowMonsterStasus();

    Player P1(name2, power2, def2);
    P1.ShowPlayerStasus();

    Player P2(name3, power3, def3);
    P2.ShowPlayerStasus();

    if (part2 == 1){
        // Call attack() to start one round of attack.
        // The monster start attacking the players first.
        // If the player's def < monster's power, the player's heart will -1.
        // Then, if the player's heart > 0 (alive), the players will start attacking the monster.
        // The monster's HP will be reduced by the power of each alive player.
        // Stop calling attack() if the monster dies (monster's hp = 0) or all the players die (player's heart = 0).
        // Otherwise, you need to call attack() again to start a new round
        
        // TODO
        while (true){
            attack(M1, P1, P2);
            if (P1.ShowHeart() <= 0 && P2.ShowHeart() <= 0){
                cout << "All the players die.\n";
                break;
            }
            if (M1.ShowHP() <= 0){
                cout << "The players win.\n";
                break;
            }
        }
        
    }
    return 0;
}