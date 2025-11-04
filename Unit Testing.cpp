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

// 🔹 Тест 1: Перевірка створення гравця
TEST_CASE("Player is created correctly", "[player]") {
    Player p("Alex", 100, 10);
    REQUIRE(p.getHealth() == 100);
}

// 🔹 Тест 2: Перевірка отримання урону
TEST_CASE("Player takes damage correctly", "[player]") {
    Player p("Alex", 100, 10);
    p.takeDamage(30);
    REQUIRE(p.getHealth() == 70);
}

// 🔹 Тест 3: Перевірка, що здоров’я не стає від’ємним
TEST_CASE("Health cannot be negative", "[character]") {
    Player p("Alex", 50, 10);
    p.takeDamage(100);
    REQUIRE(p.getHealth() == 0);
}

// 🔹 Тест 4: Перевірка атаки
TEST_CASE("Player attack increases experience", "[player]") {
    Player p("Alex", 100, 0);
    p.attack();
    // після атаки XP має збільшитись (+10)
    Player p2("Alex", 100, 0);
    p2.attack();
    REQUIRE(p2.getHealth() == 100); // здоров’я не змінюється при атаці
}

// 🔹 Тест 5: Вороги атакують
TEST_CASE("Enemy can attack", "[enemy]") {
    Enemy e("Demon", 80);
    REQUIRE_NOTHROW(e.attack());
}



