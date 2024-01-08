function solution(s){
    var answer = true;
    let p = 0, y = 0;
    for (value of s) {
        if (value === 'p' || value === 'P')
            p++;
        else if (value === 'y' || value === 'Y')
            y++;
    }
    return p == y;
}