
#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    string surname;
    string midlename;
    string groupname;
    int age;
    int marks[5];
    int countMarks = 5;

public:
    Student()
    {
        name = "no name";
        surname = "no name";
        midlename = "no name";
        groupname = "no name";
        age = 0;

        for (int i = 0; i < 5; i++)
            marks[i] = 0;
    }

    Student(string n, string s, string m, string g, int a, int marks[])
    {
        name = n;
        surname = s;
        midlename = m;
        groupname = g;
        age = a;

        for (int i = 0; i < 5; i++)
            this->marks[i] = marks[i];
    }

    void Print()
    {
        cout << "Name = " << name << endl;
        cout << "Surname = " << surname << endl;
        cout << "MidleName = " << midlename << endl;
        cout << "Groupname = " << groupname << endl;
        cout << "Age = " << age << endl;

        cout << "Marks = ";
        for (int i = 0; i < countMarks; i++)
            cout << marks[i] << " ";

        cout << endl;
    }

    void AvarageMarks()
    {
        int sum = 0;

        for (int i = 0; i < countMarks; i++)
            sum += marks[i];

        double average = (double)sum / countMarks;

        if (average < 6)
            cout << "Student is expelled!" << endl;
        else
            cout << "Student continues studying!" << endl;
    }
};

class Aspirant : public Student
{
private:
    string theme;
    int pages;

public:
    Aspirant(string n, string s, string m, string g,
        int a, int marks[], string t)
        : Student(n, s, m, g, a, marks)
    {
        theme = t;
        pages = 0;
    }

    void WriteDissertation()
    {
        int newPages;

        cout << "Enter pages = ";
        cin >> newPages;

        pages += newPages;

        cout << "Written pages = " << pages << endl;
    }

    void DefendDissertation()
    {
        cout << "Theme: " << theme << endl;
        cout << "Pages: " << pages << endl;

        if (pages >= 500)
            cout << "You can defend your dissertation!" << endl;
        else
            cout << "Not enough pages to defend!" << endl;
    }
};

int main()
{
    cout << "/=============== University ===============\\" << endl;

    int marks[5] = { 10, 8, 5, 11, 4 };

    Aspirant aspirant(
        "Oleksyi",
        "Kozubovskyi",
        "Mukitovich",
        "Pd621",
        18,
        marks,
        "Artificial Intelligence"
    );

    aspirant.Print();

    aspirant.WriteDissertation();
    aspirant.WriteDissertation();

    aspirant.DefendDissertation();
}





//class Enemy
//{
//protected:
//    string name;
//    int health;
//    float strength;
//    static const int maxHealalth = 100;
//public:
//    Enemy():name("no name"),health(0),strength(0) {}
//    Enemy(string name, float s):name("no name"),health(maxHealalth),strength(s) {}
//    void Print()const
//    {
//        cout << "Name " << name << endl;
//        cout << "Health " << health << endl;
//        cout << "Strenght " << strength << endl;
//    }
//    void DecreaseHealth(int value)
//    {
//        if (health - value <= 0)
//            health = 0;
//        else
//            health -= value;
//     
//    }
//    bool isAlive()const
//    {
//        return health > 0;
//    }
//    void Fight(int damage)
//    {
//        cout << "Getting damage " << damage << "%" << endl;
//        DecreaseHealth(damage);
//        cout << "Health after damage " << health << "%" << endl;
//    }
//
//    float Attack()
//    {
//        cout << "Attacking with strength " << strength << endl;
//        return strength;
//    }
//};
//class Dragon :public Enemy
//{
//    float armor;
//public:
//    Dragon():armor(0), Enemy() {}
//    Dragon(string n,  float s, float a) :armor(a), Enemy(n,s){}
//
//    void Fight(int damage)
//    {
//        Enemy::Fight(damage - armor);
//    }
//    void Print()const
//    {
//        cout << "============== Dragon ==============" << endl;
//        Enemy::Print();
//        cout << "Armor " << armor << endl;
//    }
//};
//class Wizard : public Enemy
//{
//    float turbo_attack;
//public:
//    Wizard(): turbo_attack(0), Enemy(){}
//    Wizard(string n, float s, float a) : turbo_attack(a), Enemy(n, s) {}
//    float Attack()
//    {
//        cout << "Attacking with turbo power " << turbo_attack << endl;
//        return turbo_attack+strength;
//    }
//    void Fight(int damage)
//    {
//        Enemy::Fight(damage);
//    }
//    void Print()const
//    {
//        cout << "============== Wizard ==============" << endl;
//        Enemy::Print();
//        cout << "Turbo attack power" << turbo_attack<< endl;
//    }
//};
//
//
//
//int main()
//{
//    Dragon dragon("Leftarion",5,2);
//    Dragon boss("Rightarion",7,4);
//    dragon.Print();
//    boss.Print();
//    int i = 1;
//    do
//    {
//        cout << "----------------------Round " << i << "----------------------" << endl;
//        dragon.Fight(boss.Attack());
//        boss.Fight(dragon.Attack());
//        i++;
//        cout << endl;
//
//    } while (boss.isAlive()&&dragon.isAlive());
//
//    dragon.Print();
//    boss.Print();
//
//    i = 0;
//    Wizard wizard("Chaklun", 4, 4);
//    do
//    {
//        cout << "----------------------Round " << i << "----------------------" << endl;
//        wizard.Fight(boss.Attack());
//        boss.Fight(wizard.Attack());
//        i++;
//        cout << endl;
//
//    } while (boss.isAlive()&&wizard.isAlive());
//    wizard.Print();
//    boss.Print();
//}
