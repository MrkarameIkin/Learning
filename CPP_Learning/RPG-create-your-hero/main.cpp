#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string name, className, strLevel, strGold;
    int level, gold;

    cout << "=== СОЗДАНИЕ ПЕРСОНАЖА ===\n";
    cout << "Введите имя героя: ";

    getline(cin, name);

    cout << "Введите класс (Воин/Маг/Разбойник): ";

    getline(cin, className);

    cout << "Введите уровень: ";

    getline(cin, strLevel);
    level = stoi(strLevel);

    cout << "Введите количество золота: ";

    getline(cin, strGold);
    gold = stoi(strGold);

    ofstream profileAdd("hero_profile.txt", ios::binary);
    profileAdd << name << '\n' << className << '\n' << level << '\n' << gold;
    profileAdd.close();

    cout << "\n[СИСТЕМА] Персонаж успешно сохранен в hero_profile.txt!\n\n";

    cout << "=== ЗАГРУЗКА ПЕРСОНАЖА ===\n";
    cout << "Чтение данных из файла...\n\n";

    cout << "---------------------------------\n";
    cout << "         ЛИСТ ПЕРСОНАЖА\n";
    cout << "---------------------------------\n";

    ifstream profileOutput("hero_profile.txt", ios::binary);

    if(profileOutput.is_open())
    {
        getline(profileOutput, name);
        getline(profileOutput, className);
        getline(profileOutput, strLevel);
        getline(profileOutput, strGold);

        cout << "Имя\t: ";
        cout << name << endl;

        cout << "Класс\t: ";
        cout << className << endl;

        cout << "Уровень\t: ";
        level = stoi(strLevel);
        cout << level << endl;
        
        cout << "Золото\t: ";
        gold = stoi(strGold);
        cout << gold << endl;

        cout << "---------------------------------\n";
    }
    else cout << "Ошибка открытия файла сохранения!";
}
