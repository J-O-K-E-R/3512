#include <iostream>
#include <fstream> 
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

struct Grades{
	string 			 id;
	map<string, int> scores;
};
struct cmp{
	string search;
	cmp(string s){
		search = s;
	}
	inline bool operator() (const Grades& g1, const Grades& g2){
		if(g1.scores.find(search) == g1.scores.end()){
			return false;
		}
	}
};

ostream& operator<<(ostream& os, const Grades& g){
	os << g.id << endl << g.scores.size() << endl;
	for(auto x : g.scores)
		os << x.first << ' ' << x.second << endl;

	return os;
}

istream& operator>>(istream& is, Grades& g){
	if(is.peek() == EOF){
		is.eof();
		return is;
	}
	 string key;
	 int i, score;
	 for(is >> g.id >> i; i > 0; --i){
	 	is >> key >> score;
	 	g.scores.insert({key, score});
	 }
	 return is;
}

int main(){
	//vetor<Grades> v;
	Grades        g;
	cout << "Enter student id" << endl;
	cin >> g;
	cout << g;
	return 0;
}

/*
Vector<Grades> v;
Grades g;
while(c >> g){
	
}
sort(v.begin(), v.end(), cmp("COMP 3512"))
*/