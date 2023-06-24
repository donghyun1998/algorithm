#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool checkAllProductSale(unordered_map<string, int> map, vector<string> want, vector<int> number)
{
    for (int i = 0; i < want.size(); i++)
        if (map.find(want[i]) == map.end() || map[want[i]] < number[i]) // map의 상품 개수가 필요 개수보다 같거나 많으면
            return false;
    return true;
}


int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> map;
    
    for (int i = 0; i < 10; i++) // 1 ~ 10일간의 할인 품목을 map에 다 넣어줌
    {
        if (map.find(discount[i]) == map.end())
            map[discount[i]] = 1;
        else
            map[discount[i]] += 1;
    }
    for (int i = 10; i <= discount.size(); i++)
    {
        if (checkAllProductSale(map, want, number))
            answer++;
        if (i == discount.size()) // 마지막이면 
            break ;
        map[discount[i - 10]] -= 1; // i - 10일 꺼 삭제
        if (map.find(discount[i]) == map.end()) // i일 꺼 추가
            map[discount[i]] = 1;
        else
            map[discount[i]] += 1;
    }
    return answer;
}