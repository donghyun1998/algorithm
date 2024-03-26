function getYaksu(num) {
    let answer = 0;
    for (let i = 1; i <= num; i++)
        if (num % i === 0)
            answer++;
    console.log(answer);
    return answer
}


function solution(left, right) {
    var answer = 0;
    while (left <= right) {
     answer += getYaksu(left) % 2 === 0 ? left : -left;
        left++;
    }
    return answer;
}