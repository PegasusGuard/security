#include <iostream>
#include <windows.h>

using namespace std;

string cypher (string alpha, string target, string key);
string decypher (string alpha, string target, string key);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int action=1;
    string alphabet = "�����Ũ��������������������������";
    string target, key;
    while (action !=0)
    {
        cout << "������� ������(������������������ ����): ";
        cin >> target;
        cout << "������� ����(������������������ ����): ";
        cin >> key;
        while (target.size() > key.size())
            key += key;
        key.erase(target.size(), key.size() - target.size());
        cout << "��� ��������� ������� �� �������?" << endl
             << "0. ��������� ������" << endl
             << "1. �����������" << endl
             << "2. ������������" << endl
             << "������� ����� ��������: ";
        cin >> action;
        switch (action)
        {
            case 0:
                break;
            case 1:
                cout << cypher(alphabet, target, key) << endl;
                break;
            case 2:
                cout << decypher(alphabet, target, key) << endl;
                break;
            default:
                cout << "������������ ����, ����� ���� ��������� � ��������� ���" << endl;
                break;
        }
        cout << endl;
    }
    return 0;
}

string cypher (string alpha, string target, string key)
{
    string result;
    while (target.size() > 0)
    {
        int posKey = alpha.find(key[0]);
        int posTarget = alpha.find(target[0]);
        result += alpha[(posKey + posTarget) % 33];
        target.erase(0,1);
        key.erase(0,1);
    }
    return result;
}
string decypher (string alpha, string target, string key)
{
    string result;
    while (target.size() > 0)
    {
        int posKey = alpha.find(key[0]);
        int posTarget = alpha.find(target[0]);
        result += alpha[(posTarget + 33 - posKey) % 33];
        target.erase(0,1);
        key.erase(0,1);
    }
    return result;
}
