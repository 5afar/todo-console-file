#include "../include/todo.hpp"

void Menu_msg()
{
    std::string text = "\tTo-do app!\n\
    [1] Create new line\n\
    [2] Delete line\n\
    [3] Drop all\n\
    [4] Save list\n\
    [5] Load list\n\
    [6] Show list\n\
    [7] Exit\n\
    ";
    std::cout << text << std::endl;
}
int Input()
{
    short int in;
    std::cout << "-> ";
    std::cin >> in;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 666;
    }
    return in;
}
int main()
{
    Todo app;
    bool stop = false;
    int cho;
    while (!stop)
    {
        Menu_msg();
        cho = Input();
        switch (cho)
        {
        case 1:
            app.Create();
            break;
        case 2:
            app.Drop();
            break;
        case 3:
            app.DropAll();
            break;
        case 4:
            app.Save();
            break;
        case 5:
            app.Load();
            break;
        case 6:
            app.Show();
            break;
        case 666:
            std::cout << "Not a number!" << std::endl;
            break;
        default:
            std::cout << "Closing the app..." << std::endl;
            stop = true;
            break;
        }
    }

    return 0;
}