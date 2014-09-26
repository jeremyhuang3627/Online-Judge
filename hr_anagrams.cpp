#include <iostream>
#include <map>
using namespace std;

string s1,s2;
map<char,int> m;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	getline(cin,s1);
	getline(cin,s2);

	/*cout << "s1 " << s1 << endl;
	cout << "s2 " << s2 << endl; */
	if(s1.length() != s2.length()){
		cout << "Not anagrams!" << endl;
	}else{
		for(int i=0;i<s1.length();i++){
			m[s1[i]]++;
			m[s2[i]]--;
		}
		map<char,int>::iterator it;
		for(it=m.begin();it!=m.end();it++){
			if(it->second!=0){
				//cout << "it->second " << it->second << " it->first " << it->first << endl;
				cout << "Not anagrams!" << endl;
				return 0;
			}
		}
		cout << "Anagrams!" << endl;
	}
    return 0;
}