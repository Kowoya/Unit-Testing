#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
using namespace std;

// Базовий клас
class Character {
protected:
    string name;
    int health;

public:
    Character(string n, int h) : name(n), health(h) {}

    virtual void attack() = 0;

    void takeDamage(int amount) {
        health -= amount;
        if (health < 0) health = 0;
        cout << name << " takes " << amount << " damage. Health = " << health << endl;
    }

    int getHealth() const { return health; }
};

// Підклас Player
class Player : public Character {
private:
    int experience;

public:
    Player(string n, int h, int xp) : Character(n, h), experience(xp) {}

    void attack() override {
        cout << name << " attacks with a sword!" << endl;
        experience += 10;
    }

    void castSpell() {
        cout << name << " casts a protective spell!" << endl;
    }

    void showStatus() const {
        cout << "Player: " << name << ", Health: " << health << ", XP: " << experience << endl;
    }
};

// Підклас Enemy
class Enemy : public Character {
public:
    Enemy(string n, int h) : Character(n, h) {}

    void attack() override {
        cout << name << " strikes viciously!" << endl;
    }
};

int main() {
    Player p("Alex", 100, 5);  
    p.showStatus();            
    p.attack();                
    p.takeDamage(20);          
    p.castSpell();             
}

//Unit testing
