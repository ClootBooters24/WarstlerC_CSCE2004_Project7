//---------------------------------------------------
// Purpose:     Header file for the Room class
// Author:      John Gauch
//---------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

class Room
{
private:
    string Name;
    string Description;
    int Treasure;
    string Creature;
    string Food;
    string Item;

public:
    Room();
    ~Room();

    void SetName(const string name);
    void SetDescription(const string description);
    void SetTreasure(const int treasure);
    void SetCreature(const string creature);
    void SetFood(const string food);
    void SetItem(const string item);

    string GetName() const;
    string GetDescription() const;
    int GetTreasure() const;
    string GetCreature() const;
    string GetFood() const;
    string GetItem();

    void Set(const string name, const string description, const int treasure,
        const string creature, const string food, const string item);
    void Get(string& name, string& description, int& treasure,
        string& creature, string& food, string& item) const;

    int FindTreasure() const;
    int FightCreature() const;
    int EatFood() const;
    string PickupItem() const;
    void Print() const;
};