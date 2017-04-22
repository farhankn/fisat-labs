#include <iostream>
unsigned long int *prime;
arr = malloc (sizeof(int) * 12000000);
bool primes[12000000];
void checker(int N) {
    
    for(unsigned long int i = 0; i <= 12000000;++i) {
        primes[i] = true;
    }
    primes[0] = false;
    primes[1] = false;
    for(unsigned long int i = 2;i*i<= N;++i) {
         if(primes[i] == true) {
             for(unsigned long int j = i*i; j<=N;j+=i)
                 primes[j] = false;
        }
    }
}
int check(unsigned long int num){
    unsigned long int ans=0;
    for(unsigned long int i=1;i<num;i++){
        ans=ans+prime[i];
        if(ans==num){
            return 1;
        }
        else if(ans>num){
            return 0;
        }
    }
}
int main()
{
    int k=1,ans,count;
    unsigned long int N,n;
    checker(110000);
    for(unsigned long int i = 0; i <= 12000000;++i) {
       if(primes[i] == true){
            prime[k]=i;
            k++;
       }

        
    }
    cin>>N;
    n=N;
    for (unsigned long int i = 3; i < N; ++i)
    {
        /*while(primes[n]==0){
        n--;
        }*/
        if(check(i)&&primes[i]==true)
            count++;
    }
    cout<<count<<"\n";
    return 0;
}
