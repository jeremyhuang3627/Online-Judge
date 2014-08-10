#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
 
#define Inf 2147483647
#define Pi acos(-1.0)
#define M 10000
#define LL long long
#define ULL unsigned long long
 
inline LL Power(int b, int p) { LL ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }
 
#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
//#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)

using namespace std;

string m [999 + 5][18278 + 5];
map<string,bool> converted;

int stringToInt(string s){
	istringstream buffer(s);
	int ret;
	buffer >> ret;
	return ret;
}

string intToString(int x){
	stringstream ss;
	ss << x;
	string ret;
	ss >> ret;
	return ret;
}

int intpow(int x,int e){
	int ret = 1;
	F(i,0,e){
		ret *= x;
	}
	return ret;
}

pair<int,int> parseColName(string s){
	cout << "parsing col name s : " << s;
	string letters = "";
	string num = "";

	F(i,0,s.length()){
		if(isalpha(s[i])){
			letters += s[i];
		}else if(isdigit(s[i]))
		{
			num += s[i];
		}
	}

	int col = 0;
	
	F(i,0,letters.size()){
		col += (letters[i] - 'A' + 1) * intpow(26,letters.size() - 1 - i);
	}

	int row = stringToInt(num);

	cout << " row " << row << " col " << col << endl;
	return make_pair(row,col);
}

vector<pair<int,int> > parseFormula(string s)
{
	vector<pair<int,int> > ret;
	if(s[0] != '='){
		return ret; 
	}

	string sub = s.substr(1);
	//cout << "s " << s << " sub " << sub << endl;

	const char * c = sub.c_str();

	vector<string> colnames;

	string cn = "";
	while(*c != '\0'){
		if(*c == '+'){
			ret.push_back(parseColName(cn));
			cn = "";
		}else{
			cn += *c;
		}
		c++;
	}

	ret.push_back(parseColName(cn));

	return ret;
}

int solve(string s,pair<int,int> p,map<string,pair<int,int> > &fm)
{
	//cout << "s " << s << endl;
	vector<pair<int,int> > ps = parseFormula(s);
	int sum = 0;
	//cout << "solving " << s << endl;
	F(i,0,ps.size()){
		int row = ps[i].first;
		int col = ps[i].second;
		if(m[row][col][0]=='='){ // is a formula
			sum += solve(m[row][col],ps[i],fm);
		}else{
			sum += stringToInt(m[row][col]);
		}
	}
	//cout << "t5" << endl;
	m[p.first][p.second] = intToString(sum);
	converted[s] = true;
	//cout << "t6" << endl;
	return sum;
}

void print(int row,int col){
	F(i,1,row + 1){
		F(j,1,col + 1){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int cn;
	scanf("%d",&cn);
	F(i,1,cn + 1){
		int col,row;
		map<string,pair<int,int> > fm;
		scanf("%d %d",&col,&row);
		
		F(j,1,row + 1){
			F(k,1,col + 1){
				cin >> m[j][k];
				if(m[j][k][0] == '='){
					fm[m[j][k]] = make_pair(j,k);
				}
			}
		}
		map<string,pair<int,int> >::iterator it;
		converted.clear();
		for(it = fm.begin();it!= fm.end();it++){
			if(!converted[it->first]){
				solve(it->first,it->second,fm);
			}
		}
		print(row,col);
	}
	cout << "test parseColName " << endl;
	parseColName("ZZZ123");
	return 0;
}