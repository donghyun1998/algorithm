function solution(n)
{
    var answer = 0;
    str = String(n);
    arr = [...str];
    for (let i = 0; i < str.length; i++) {
        answer += parseInt(arr[i]);
    }

    return answer;
}