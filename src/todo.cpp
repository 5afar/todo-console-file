#include "../include/todo.hpp"

using std::cout;
using std::endl;

void Todo::Create()
{
    cout << "Type your task lower: " << endl;
    std::string s = Input();
    List.push_back(s);
}
void Todo::Drop()
{
    cout << "What`s line you want delete: ";
    int in = -1;
    std::cin >> in;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Incorrect choice!" << endl;
        return;
    }
    in--;
    if (in < 0 || in > 9)
    {
        cout << "Out of range!" << endl;
        return;
    }
    if (in > List.size() - 1)
    {
        cout << "Out of range!" << endl;
        return;
    }
    if (List.empty())
    {
        return;
    }
    List.erase(List.begin() + in);
    cout << "Complete delete operation!" << endl;
    return;
}
void Todo::DropAll(){
    List.clear();
}
void Todo::Load()
{
    cout << "Insert file path: ";
    std::string filePath = Input();

    std::filesystem::path pathObj(filePath);
    if (pathObj.has_extension())
    {
        std::string extension = pathObj.extension().string();
        if (extension != ".sda")
        {
            cout << "Invalid extension!" << endl;
            ;
            return;
        }
    }
    else
    {
        cout << "Extension not found!" << endl;
        return;
    }

    std::ifstream file(filePath);
    std::string line;
    if (file.is_open())
    {
        while (file >> line)
        {
            List.push_back(line);
        }
    }
    else
    {
        cout << "File not found!" << endl;
    }
    file.close();
    cout << "Load complete!" << endl;
}
void Todo::Save()
{
    std::ofstream save_file("./save.sda");
    std::ostream_iterator<std::string> save_iter(save_file, "\n");
    std::copy(List.begin(), List.end(), save_iter);
    cout << "Save complete on \"save.sda\"!" << endl;
}
void Todo::Show()
{
    int count = 1;
    if (List.empty())
    {
        cout << "List is empty!" << endl;
        return;
    }
    for (const auto &item : List)
    {
        cout << "[" << count << "] " << item << endl;
        count++;
    }
}

std::string Todo::Input()
{
    std::string s;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, s);
    return s;
}