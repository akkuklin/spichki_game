#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int n, i, k;
    int c = 0; // счетчик четности
    int r = 0; // сколько взял робот
    int bad[17]={ 1, 7, 13, 19, 25, 31, 37, 43, 49, 55, 61, 67, 73, 79, 85, 91, 97 };
    n = 7 + rand() % 93;
    while (n > 1){
        cout << "Спичек на столе = " << n << endl;
        cout << "Ваш ход.. ";
        cin >> i; // сколько взял игрок
        if (i > 5 || i < 1) { // проверка выбора спичек
            cout << "Вы выбрали неверное количество спичек!" << endl;
            i = 0;
        } else {
            n -= i;
            for (k = 16; r == 0; k--) // сколько спичек взять роботу
                if (n > bad[k] && n > 1)
                    r = n - bad[k];
                else if (n == bad[k] && n > 1)
                    r = 1 + rand() % 5;
            cout << "Спичек на столе: " << n << endl << "Я взял: " << r << endl;
            n -= r;
            r = 0;
            c += 1;
            cout << c << endl;
        }
    }
    cout << "Спичек на столе = " << n << endl;
    cout << "Ваш ход.. ";
    cin >> i;
    while (i != 1) { // проверка выбора последней спички
        cout << "Вы выбрали неверное количество спичек!" << endl;
        cout << "Спичек на столе = " << n << endl;
        cout << "Ваш ход.. ";
        cin >> i;
    }
    cout << "Ты проиграл!";
    return 0;
}