#include<bits/stdc++.h>
using namespace std;

//4 to 10 xor
/*
assume l=4 and r=10
then xor of l-1 ^ xor of r
*/


/*
if they say 1 to n then 
1-> 1
2-> 3
3-> 0
4-> 4
5-> 1
6-> 7
7-> 0
same like that 
8-> 8
16-> 16
 that means multiples of 4 xor is that number
 if(n%4==0) print(n)
 if (n%4==1) print(1) 
  if(n%4==2) print(n+1)
 if (n%4==3) print(0) 

*/
