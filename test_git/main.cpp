#include <iostream>
#include <cstring>
#include <cmath>

class Barrel {
    int cnt;              // Количество шаров в барабане
    char *balls;          // Дин. массив из cnt символов (буквы на шарах в порядке по часовой стрелке)
    
public:
    Barrel(char *str = NULL);     // Заполнить барабан шарами-буквами из строчки str
    ~Barrel();
    
    int count();           // Получить количество шаров в барабане
    
    void clockwise(int x); // Сдвинуть барабан на x шаров по часовой стрелке
    void countercw(int x); // Сдвинуть барабан на x шаров против часовой стрелки
    char extract();        // Извлечь первый шар из барабана
    void print();          // Вывести на экран все мячики
};

Barrel::Barrel(char* str)
{
    cnt = int(strlen(str));
    balls = new char [cnt];
    strncpy(balls, str, cnt);
}

Barrel::~Barrel()
{
    delete [] balls;
}

int Barrel::count()
{
    return cnt;
}

void Barrel::clockwise(int x)
{
    for (int j = 0; j < x; ++j) {
        char tmp1 = balls[cnt-1];
        char tmp2 = {};
        for (int i = 0; i < cnt; ++i)
        {
            tmp2 = balls[i];
            balls[i] = tmp1;
            tmp1 = tmp2;
        }
    }
}

void Barrel::countercw(int x)
{
    for(int i = 0; i < x; ++i) {
        char tmp1 = balls[0];
        char tmp2 = {};
        for (int j = cnt-1; j >= 0; --j)
        {
            tmp2 = balls[j];
            balls[j] = tmp1;
            tmp1 = tmp2;
        }
    }
}

void Barrel::print()
{
    for(int i = 0; i < cnt; ++i)
    {
        std::cout << balls[i];
    }
    std::cout << std::endl;
}

char Barrel::extract()
{
    char* new_balls = new char [cnt - 1];
    for(int i = 1; i < cnt; ++i)
    {
        new_balls[i - 1] = balls[i];
    }
    char result = balls[0];
    cnt--;
    delete [] balls;
    balls = new_balls;
    return result;
}
//тест
//еще тест

void lets_play(Barrel & b)
{
    int turns = 0;
    std::cin >> turns;
    for (int i = 0; i < turns; ++i)
    {
        int roll = 0;
        std::cin >> roll;
        (roll > 0) ? b.countercw(abs(roll)) : b.clockwise(abs(roll));
        //        b.print();
        std::cout << b.extract();
        //        b.print();
    }
    std::cout << std::endl;
}

int main()
{
    char* str = new char [1001];
    std::cin >> str;
    Barrel b(str);
    lets_play(b);
    delete [] str;
    return 0;
}

