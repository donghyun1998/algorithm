function solution(n) {
    let str = n.toString().split('').sort((a,b)=>{return b - a}).join('');
    return Number(str);
}