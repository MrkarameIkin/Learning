/*

Задача: «Дневник студента» 📚

Студент получил 5 оценок за неделю. Тебе нужно написать программу, которая:
- Попросит пользователя ввести 5 оценок (целые числа от 1 до 5) и сохранит их в массив.
- Выведет все оценки на экран.
- Посчитает средний балл (дробное число!).
- Отсортирует оценки по возрастанию (от худшей к лучшей).
- Выведет отсортированный список и средний балл.

*/

#include <iostream>
using namespace std;

void sort(int *grades)
{
    int buffer;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(grades[j] > grades[j+1])
            {
                buffer = grades[j];
                grades[j] = grades[j+1];
                grades[j+1] = buffer;
            }
        }
    }

    for(int i = 0; i < 5; i++) {cout << ' ' << grades[i];};
    cout << endl;
}

void gradeInput(int *grades)
{
    for(int i = 1, input; i <= 5; i++)
    {
        cout << "Оценка " << i << ": ";
        cin >> input;

        grades[i-1] = input;
    }
}

int main()
{
    int grades[5];
    float sum = 0.0f;

    cout << "Введите 5 оценок:\n";

    gradeInput(grades);

    cout << "\nВаши оценки: ";
    for(int i = 0; i < 5; i++) {cout << grades[i] << ' ';}

    cout << "\nСредний балл: ";
    for(int i = 0; i < 5; i++) {sum+=grades[i];}
    cout << sum/(sizeof(grades)/sizeof(grades[0])) << endl;

    cout << "\nСортируем...";
    cout << "\nОценки по возрастанию:";
    
    sort(grades);
}
