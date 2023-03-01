#include<iostream>
using namespace std;
#define M 100000007
#define Max 1000006
#define base 31
long long HashT= 0,f[Max];
long long b[Max];
long long getHash(int l, int r){
    long long res= (f[r] - f[l - 1] * b[r-l+1] % M + M) % M;
    return res;
}
int main(){
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int lengthT= t.length(),lengthS= s.length();
    s=' ' + s;
    t= ' ' + t;
    b[0] = 1;
    for(int i= 1; i<= lengthT; i++) b[i] = b[i-1] * base % M;
    for(int i= 1; i<=lengthT; i++){
        HashT = (HashT * base + (t[i] -'a' + 1)) % M;
    }
    for(int i= 1; i<=lengthS; i++){
        f[i] = (f[i-1] * base + (s[i] - 'a' + 1)) % M;
    }
    for(int i= 1; i+lengthT-1 <= lengthS; i++){
        if(getHash(i, i+lengthT-1) == HashT)
            cout << i << " ";
    }
    return 0;
}
