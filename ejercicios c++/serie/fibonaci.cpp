#include<iostream>
#include<conio.h>
#include<time.h>
#include<string.h>
using namespace std;
//serie 1,1,2,3,5,8....n
int main(){
 /* int v[100],n,may=0;
  cin>>n;
  for(int i=0;i<n;i++){
  	cin>>v[i];    	
  	if(v[i]>may){
  		may=v[i];
	  }	
  }
cout<<"\nel numero mayor es "<<may<<endl; */
   
   string s;
   cin>>s;
   char cad[]=s;
   strrev(cad);
   cout<<cad;
   
    getch();
	return 0;
}
