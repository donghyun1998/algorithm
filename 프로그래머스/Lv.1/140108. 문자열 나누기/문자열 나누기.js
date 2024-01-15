function solution(s) {
    var answer = 0, x = null, xCnt = 0, noXcnt = 0;
    for (let i = 0; i < s.length; i++) {
        if (!x || xCnt == noXcnt) {
            x = s[i];
            xCnt = 1;
            noXcnt = 0;
            answer++;
        } else {
            if (s[i] == x)
                xCnt++;
            else
                noXcnt++;
        }
    }
    return answer;
}