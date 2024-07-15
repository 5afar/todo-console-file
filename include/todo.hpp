#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>


/*
Одна задача - одна строчка
Ограничить количество символов в строке ~ 100 символов
ограничить количество задач в списке ~ 10
*/

class Todo
{
private:
    std::vector<std::string> List;
    std::string Input();
    void Find();
    bool CheckSize();
public:

    // create() создает новую задачу и записывает ее в вектор
    void Create();
    void Drop();
    void DropAll();
    void Save();
    void Load();
    void Show();
};


