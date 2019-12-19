#include<iostream>
#include<unordered_map>

using namespace std;

long long fibonacci1(long long n){
  unordered_map<int,long long> dict;
  dict[0]=0;
  dict[1]=1ll;
  for(int i=2;i<=n;i++)
    dict[i]=dict[i-1]+dict[i-2];
  return dict[n];
}
long long fibonacci2(long long n){
  if(n==0)
    return 0;
  else if(n==1)
    return 1;
  return fibonacci2(n-1)+fibonacci2(n-2);
}

int main(){

  long long n;

  cin>>n;

  cout<<fibonacci1(n)<<endl;
  cout<<fibonacci2(n)<<endl;


  return 0;
}
