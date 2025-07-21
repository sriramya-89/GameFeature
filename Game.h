// GameFeature.h

#ifndef GAMEFEATURE_H
#define GAMEFEATURE_H

#include <string>
#include <vector>

class Item {
private:
    std::string name;
    int value;
    float weight;

public:
    Item(const std::string& name, int value, float weight);
    
    std::string getName() const;
    int getValue() const;
    float getWeight() const;
};

class Inventory {
private:
    std::vector<Item> items;

public:
    void addItem(const Item& item);
    void removeItem(const std::string& itemName);
    int getItemCount() const;
    void displayItems() const;
};

class Player {
private:
    std::string name;
    int health;
    int level;
    Inventory inventory;

public:
    Player(const std::string& name);
    
    void takeDamage(int amount);
    void heal(int amount);
    void levelUp();
    void addItemToInventory(const Item& item);
    
    int getHealth() const;
    std::string getName() const;
};

class Enemy {
private:
    std::string type;
    int health;
    int attackPower;

public:
    Enemy(const std::string& type, int health, int attackPower);
    
    void attack(Player& player);
    void takeDamage(int amount);
    bool isDefeated() const;
};

class GameWorld {
private:
    std::vector<Enemy> enemies;
    Player* player;

public:
    GameWorld(Player* player);
    
    void spawnEnemy(const Enemy& enemy);
    void removeDefeatedEnemies();
    void updateWorldState();
};

class Quest {
private:
    std::string description;
    bool isCompleted;

public:
    Quest(const std::string& description);
    
    void completeQuest();
    bool getStatus() const;
    std::string getDescription() const;
};

class QuestManager {
private:
    std::vector<Quest> activeQuests;

public:
    void addQuest(const Quest& quest);
    void completeQuest(const std::string& description);
    void displayQuests() const;
};

#endif // GAMEFEATURE_H
