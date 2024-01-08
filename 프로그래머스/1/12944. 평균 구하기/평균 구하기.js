function solution(arr) {
    var answer = 0;
    for (value of arr)
        answer += value;
    answer /= arr.length;
    return answer;
}