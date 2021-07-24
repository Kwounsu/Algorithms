int gcd(int a, int b){return b ? gcd(b, a % b) : a;} 

int lcm(int a, int b){return a / gcd(a, b) * b ;}  // a * b / gcd(a,b)는 overflow의 위험성 있음.
