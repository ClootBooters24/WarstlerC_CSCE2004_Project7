//---------------------------------------------------
// Purpose:     Implementation for the Cave class
// Author:      John Gauch (ADD YOUR NAME HERE)
//---------------------------------------------------
#include "cave.h"

Cave::Cave()
{
    count = 0;
}

Cave::~Cave()
{
}

int Cave::GetCount()
{
    return count;
}

bool Cave::ReadRooms(const string filename)
{
    // TO BE ADDED
    // Open input file
    ifstream din;
    din.open(filename.c_str());
    if (din.fail())
        return false;

    // Read room information
    while (!din.eof())
    {
        string name, treasure, creature, food, item, description, descriptionTotal;

        getline(din, name);
        cout << "Name: " << name << endl;
        rooms[count].SetName(name);

        getline(din, treasure);
        cout << "Treasure: " << treasure << endl;
        rooms[count].SetTreasure(stoi(treasure));

        getline(din, creature);
        cout << "Creature: " << creature << endl;
        rooms[count].SetCreature(creature);

        getline(din, food);
        cout << "Food: " << food << endl;
        rooms[count].SetFood(food);

        getline(din, item);
        cout << "Item: " << item << endl;
        rooms[count].SetItem(item);

        //Desciption won't print out correctly, will only print "#"
        cout << "Desciption: \n";
        while (description != "#")
        {
            getline(din, description);
            cout << description << endl;
            descriptionTotal.append(description);
            rooms[count].SetDescription(descriptionTotal);
        }
        count++;

        cout << endl;
    }

    // Close input file
    din.close();
    return true;
}

bool Cave::WriteRooms(const string filename)
{
    // TO BE ADDED
    ofstream dout;
    dout.open(filename.c_str());
    if (dout.fail())
        return false;

    for (int i = 0; i < count; i++)
    {
        dout << rooms[i].GetName() << endl;
        dout << rooms[i].GetTreasure() << endl;
        dout << rooms[i].GetCreature() << endl;
        dout << rooms[i].GetFood() << endl;
        dout << rooms[i].GetItem() << endl;
        dout << rooms[i].GetDescription() << endl;
    }

    //close output file
    dout.close();
    return true;
}

bool Cave::ReadMap(const string filename)
{
    // Open input file
    ifstream din;
    din.open(filename.c_str());
    if (din.fail())
        return false;

    // Read map information
    for (int room = 0; room < count; room++)
        for (int dir = 0; dir < MAX_DIRS; dir++)
            din >> map[room][dir];

    // Close input file
    din.close();
    return true;
}

bool Cave::WriteMap(const string filename)
{
    // Open output file
    ofstream dout;
    dout.open(filename.c_str());
    if (dout.fail())
        return false;

    // Write map information
    for (int room = 0; room < count; room++)
    {
        for (int dir = 0; dir < MAX_DIRS; dir++)
            dout << map[room][dir] << " ";
        dout << endl;
    }

    // Close output file
    dout.close();
    return true;
}

int Cave::VisitRoom(const int room, Player& player)
{
    // TO BE ADDED
    rooms[room].Print();

    //Go through each action in each room
    player.setHealth(player.getHealth() + rooms[room].EatFood());
    player.setHealth(player.getHealth() - rooms[room].FightCreature());
    player.addItem(rooms[room].PickupItem());
    player.setGold(player.getGold() + rooms[room].FindTreasure());

    return 0;
}

int Cave::NextRoom(const int room)
{
    // Error checking
    if (room < 0 || room >= count)
        return 0;

    // Prompt the user for direction
    cout << "\nWhat direction would you like to go (N,S,E,W): ";
    char direction;
    cin >> direction;
    direction = toupper(direction);
    while ((direction != 'N') && (direction != 'S') &&
        (direction != 'E') && (direction != 'W'))
    {
        cout << "Sorry, You can not go that way...\n";
        cout << "What direction would you like to go (N,S,E,W): ";
        cin >> direction;
        direction = toupper(direction);
    }

    // Return next room number
    int next = room;
    switch (direction)
    {
    case 'N': next = map[room][0]; break;
    case 'S': next = map[room][1]; break;
    case 'E': next = map[room][2]; break;
    case 'W': next = map[room][3]; break;
    }
    return next;
}

// Remove all white space from start and end of string
string Cave::trim(const string str)
{
    unsigned int start = 0;
    unsigned int end = str.length() - 1;
    while ((start < str.length()) && (isspace(str[start]))) start++;
    while ((end > start) && (isspace(str[end]))) end--;
    return str.substr(start, (end - start + 1));
}