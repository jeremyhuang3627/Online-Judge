#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

void nextPermutation(vector<int> &num) {
	for(int i=num.size()-1;i>0;i--)
     {
          if(num[i-1] < num[i]){
               int t = num[i-1];
               int j = i;
               while(j<num.size()-1 && num[j+1] > t){
                    j++;
               }
               num[i-1] = num[j];
               num[j] = t;

               sort(num.begin()+i,num.end());
               return;
          }
     }

     sort(num.begin(),num.end());
}

int main()
{	
     int a[3] = {1,3,2};
     vector<int> v (a,a+3);
     nextPermutation(v);
     for(int i=0;i<v.size();i++)
     {
          cout << v[i] << " ";
     }
     cout << endl;
	return 0;
}