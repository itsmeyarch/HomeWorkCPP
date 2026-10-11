#include <iostream>
#include <string>

//Завдання 1
//Написати програму, яка аналізує повний шлях до файлу(наприклад,
//    C:\Users\Admin\Documents\report.pdf) та витягує з нього чисте ім'я
//    файлу і його розширення.
//    Вимоги до реалізації :
//● Пошук з кінця : Використати метод rfind('\\') (reverse find), щоб
//знайти позицію останнього слеша у рядку.
//● Відокремлення файлу : Застосувати substr(), щоб відрізати весь
//шлях до папок і зберегти лише ім'я файлу (у нашому випадку
//report.pdf).
//● Відокремлення розширення : До отриманого імені застосувати
//rfind('.'), щоб знайти останню крапку.
//● Розділити рядок на дві частини(назва та розширення) через
//substr() і вивести їх у консоль окремими рядками.

int main()
{
    std::string path;

    std::cout << "Write path to file: ";
    std::getline(std::cin, path);

    int pos = path.rfind('\\');
    std::string file = path.substr(pos + 1);

    int dot = file.rfind('.');
    
    if (dot != std::string::npos) {
        std::string name = file.substr(0, dot);
        std::string expansion = file.substr(dot + 1);

        std::cout << "File name: " << name << '\n';
        std::cout << "File expansion: " << expansion << '\n';
    }
}
