#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;


int isPrime(long n){
    if(n < 5 || n%2 == 0 || n%3 ==0) return (n == 2 || n == 3);
    long lim = sqrt(n) + 2;
    for(long p=5; p < lim; p+=6)
        if(n%p == 0 || n%(p+2) ==0) return 0;
    return 1;
}

int isAnagrammatic(char* s){
    if(strchr(s,'0') || strchr(s,'2') || strchr(s,'4') || strchr(s,'5') || strchr(s,'6') || strchr(s,'8'))
        return 0;
    int sSize = strlen(s);
    string S = s;
    sort(S.begin(),S.end());
//    cout << "[" << s << "]\n";
    do{
        if(!isPrime(atol(S.c_str()))) return 0;
//        cout << "> " << S << endl;
    } while(next_permutation(S.begin(),S.end()));
    return 1;
}

int main(){
    int aPrimes[] = {2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,337,373,733,919,991};
    long n;

    while(scanf("%ld",&n) && n){
	    long m=0,lim=n;
	    while(lim!=0){
		    m++;
		    lim = lim/10;
	    }
//	    cout << "m = " << m << endl;
	    lim = pow(10,m);
	    long a=0;
	    for(int i=0; i<22; i++){
		    if(aPrimes[i] > n && aPrimes[i] < lim){
			  a = aPrimes[i];
			  break;
		    }
	    }
	    printf("%ld\n",a);
    }

    /*for(long i = 0; i<10000000; i++){
        char s[20];
        sprintf(s,"%ld",i);
        if(isPrime(i) && isAnagrammatic(s))
            printf("%ld\n",i);
    }*/
    return 0;
}
