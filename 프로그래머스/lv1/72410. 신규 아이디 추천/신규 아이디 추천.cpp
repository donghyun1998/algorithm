#include <string>
#include <vector>
#include <iostream>

using namespace std;

string  get_delete_x_string(string original)
{
    string res = "";
    for (int i = 0; i < original.size(); i++)
        if (original[i] != 'X')
            res += original[i];
    return (res);
}

string solution(string new_id) {
    for (int i = 0; i < new_id.size(); i++) // 1단계
        if (new_id[i] <= 'Z' && new_id[i] >= 'A')
            new_id[i] += 32; // 소문자로 바꿔줌
    // cout << new_id << '\n';
    for (int i = 0; i < new_id.size(); i++) // 2단계
        if (!(isalnum(new_id[i]) || (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')))
            new_id[i] = 'X'; // X는 나중에 뺄 것
    // cout << new_id << '\n';
    new_id = get_delete_x_string(new_id);
    for (int i = 0; i + 1 < new_id.size(); i++) // 3단계
        if (new_id[i] == '.' && new_id[i] == new_id[i + 1])
            new_id[i] = 'X';
    // cout << new_id << '\n';
    new_id = get_delete_x_string(new_id);
    for (int i = 0; i < new_id.size(); i++) // 4단계
    {
        if (new_id[0] == '.')
            new_id[0] = 'X';
        if (new_id[new_id.size() - 1] == '.')
            new_id[new_id.size() - 1] = 'X';
    }
    // cout << new_id << '\n';
    new_id = get_delete_x_string(new_id);
    if (new_id == "") // 5
        new_id += 'a';
    // cout << new_id << '\n';
    for (int i = 0; i < new_id.size(); i++) // 6
    {
        if (new_id.size() >= 16)
            new_id = new_id.substr(0, 15);
        for (int i = 1; i < new_id.size() - 1; i++)
        {
            if (new_id[new_id.size() - i] != '.')
            {
                new_id = new_id.substr(0, new_id.size() - i + 1);
                break ;
            }
        }
    }
    // cout << new_id << '\n';
    while (new_id.size() < 3)
        new_id += new_id[new_id.size() - 1];
    return new_id;
}