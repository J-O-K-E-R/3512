#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

struct Grades {
	string 				id;
	map<string,int>		score;
};

ostream& operator<<(ostream& os, Grades& g)
{
	os << g.id << endl;
	os << g.score.size() << endl;
	for(auto& x: g.score)
	{
		os << x.first << ' ' << x.second << endl;
	}
	return os;
}

istream& operator>>(istream& is, Grades& g)
{
	int n;
	if(!(is >> g.id >> n))
	{
		return is;
	}
	
	g.score.clear();
	
	for(int i = 0; i < n; i++)
	{
		string course;
		int score;
		is >> course >> score;
		g.score.insert(make_pair(course, score));
	}
	return is;
}

struct Cmp {
	string cmpcourse;
	Cmp(const string& course) : cmpcourse(course) {}
	bool operator()(Grades& lhs, Grades& rhs) const
	{
		auto lh = lhs.score.find(cmpcourse);
		auto rh = rhs.score.find(cmpcourse);
		
		if(lh == lhs.score.end())
		{
			return false;
		}
		
		if(rh == rhs.score.end())
		{
			return true;
		}
		return rh->second < lh->second;
	}
};

//everytime you see a new max you need to clear it!!!!

struct MaxFinder {
	string cmpcourse;
	int topscore = 0;
	vector<string> topid;
	MaxFinder(const string& input):cmpcourse(input){}
 
	void operator ()(const Grades& g)
	{
  
		auto it = g.score.find(cmpcourse);
		if (it != g.score.end()) 
		{
			if (it->second > topscore)
			{	
				topscore = it->second;
			topid.clear();
			topid.push_back(g.id);
			
			} else if (it->second == topscore) 
			{
				topid.push_back(g.id);
			}
	`	}
	}
};


int main() {
	  vector<Grades> grades;
	  vector<string> topid;
	  Grades g;
	  
	  while(cin >> g)
	  {
		  grades.push_back(g);
	  }
	  
	  sort(grades.begin(), grades.end(), Cmp("COMP2512"));
	  cout << endl;
	  
 	  for(auto& x : grades)
	  {
		  cout << x << endl;
	  }
	  
	  MaxFinder m = for_each(grades.begin(), grades.end(), MaxFinder("COMP3512"));
	  
	  if(m.topid.size() == 0)
	  {
		  cout << "no students taking course" << endl;
		  return 0;
	  }
	  
	  for(auto& x : m.topid)
	  {
		  cout << "The student(s) with the highest score is: " << x << endl;
	  }
	  cout << "The max score for COMP3512 is: " << m.topscore;
}