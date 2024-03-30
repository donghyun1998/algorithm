function solution(a, b) {
    var x, y;
    if (a >= b) {
        x = b;
        y = a;
    } else {
        x = a;
        y = b;
    }
    var answer = 0;
    while (x <= y) {
        answer += x++;
    }
    return answer;
}