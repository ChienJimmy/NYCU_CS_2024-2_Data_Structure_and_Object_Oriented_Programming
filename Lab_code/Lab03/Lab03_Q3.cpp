#include <iostream>
#include <string>
using namespace std;

class Bucket {
protected:
    string name;
    int fish, bread;

public:
    //TODO
    static int totalf;
    static int totalb;
    

    Bucket(int fish_, int bread_, string name_) {
        //TODO
        this->fish = fish_;
        this->bread = bread_;
        totalf += fish;
        totalb += bread_;
        this->name = name_;
        this->show();
        this->showAll();
    }
    
    void SwitchFish(Bucket* b) {
        //TODO
        int tmp;
        tmp = b->fish;
        b->fish = this->fish;
        this->fish = tmp;
        this->show();
        b->show();
    }

    void SwitchBread(Bucket* b) {
        //TODO
        int tmp;
        tmp = b->bread;
        b->bread = this->bread;
        this->bread = tmp;
        this->show();
        b->show();
    }

    void ModifyResources(int fish_, int bread_) {
        //TODO
        this->fish += fish_;
        this->bread += bread_;
        totalf += fish_;
        totalb += bread_;
        this->show();
        this->showAll();
    }

    void show() {
        //TODO
        cout << this->name << " has " << this->fish << " fish and " << bread << " loaves of bread.\n";
    }

    void showAll() {
        //TODO
        cout << "In total, there are " << totalf << " fish and " << totalb << " loaves of bread.\n";
    }
};

//TODO
int Bucket::totalf = 0;
int Bucket::totalb = 0;



int main() {
    Bucket* c1 = new Bucket(1,2,"Bucket1"), *c2 = new Bucket(3,4,"Bucket2"), *c3 = new Bucket(5,6,"Bucket3");
/*
Bucket1 has 1 fish and 2 loaves of bread.
In total, there are 1 fish and 2 loaves of bread.
Bucket2 has 3 fish and 4 loaves of bread.
In total, there are 4 fish and 6 loaves of bread.
Bucket3 has 5 fish and 6 loaves of bread.
In total, there are 9 fish and 12 loaves of bread.
*/
    c1->ModifyResources(-1,4);
/*
Bucket1 has 0 fish and 6 loaves of bread.
In total, there are 8 fish and 16 loaves of bread.
*/
    c1->SwitchBread(c2);
/*
Bucket1 has 0 fish and 4 loaves of bread.
Bucket2 has 3 fish and 6 loaves of bread.
*/
    c3->ModifyResources(-2,-3);
/*
Bucket3 has 3 fish and 3 loaves of bread.
In total, there are 6 fish and 13 loaves of bread.
*/
    c3->SwitchFish(c1);
/*
Bucket3 has 0 fish and 3 loaves of bread.
Bucket1 has 3 fish and 4 loaves of bread.
*/
    c2->ModifyResources(10,13);
/*
Bucket2 has 13 fish and 19 loaves of bread.
In total, there are 16 fish and 26 loaves of bread.
*/
    c2->SwitchBread(c3);
/*
Bucket2 has 13 fish and 3 loaves of bread.
Bucket3 has 0 fish and 19 loaves of bread.
*/
    c1->ModifyResources(0,0);
/*
Bucket1 has 3 fish and 4 loaves of bread.
In total, there are 16 fish and 26 loaves of bread.
*/
    delete c1;
    delete c2;
    delete c3;
    return 0;
}