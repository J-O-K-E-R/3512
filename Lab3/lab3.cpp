#include <iostream>
#include <vector>
using namespace std;

string rtrim(const string& s);
string replace_all(const string& source, const string& oldstr, const string& newstr);
string squeeze(const string& s, char c);
vector<string> 
split(const string& s, const string& delim);

string rtrim(const string& s){
	string line;
	line = s.substr();
	for(string::size_type i = line.length() - 1; i > 0; i--){
		if(isspace(line[i])){
			line.erase(i, 1);
		} else 
			return line;
	}
	return line;
}
string replace_all(const string& s, const string& oldstr, const string& newstr){
	string line;
	string::size_type i, j, k, pos, lpos = 0, sz = oldstr.size();
	for(i = 0; i < s.size(); i++){
		if(s[i] == oldstr[0]){
			if(sz > s.size() - i){
				break;
			}
			for(j = i, k = 0;k < sz; j++, k++){
				if(s[j] != oldstr[k])
					break;
			}
		pos = i;
		line.append( s, lpos, pos - lpos);
		line += newstr;
		lpos = pos + sz;
		}
	}
	line += s.substr(lpos);
    return line;
}
string squeeze(const string& s, char c){
	string line;
	int count;
	string::size_type i, lpos = 0, pos;
	for(i = 0; i < s.size(); i++){
		count = 0;
		if(s[i] == c){
			pos = i;
			line.append(s, lpos, pos - lpos);
			while(s[i] == c) {
				i++;
				count++;
			}
			lpos = pos + count - 1;
		}
	}
	line += s.substr(lpos);
	return line;
}
vector<string> 
split(const string& s, const string& delim){
	vector<string> line;
	string::size_type i, i2, pos, lpos = 0;
	string word;
	line.clear();
	for(i = 0; i < s.size(); i++){
		pos = i;
		for(i2 = 0; i2 < delim.size(); i2++){
			if(s[i] == delim[i2]){
				word.append(s, lpos, pos - lpos);
				line.push_back(word);
				lpos = pos + 1;
				word.erase();
			}
		}
	}
	word = s.substr(lpos);
	line.push_back(word);
	return line;
}

int main(){
	const string s = "    hello  world   \n   ";
	const string t = "alley-dalley";
	const string u = "al";
	const string v = "oke";
	const string w = "naahaaasapeemaapetilon";
	const string x = "ab<cd>ef<gh>i";
	const string y = "<ab><>cd<";
	const string z = "<>";
	char c = 'a';
	string res1, res2, res3;
	vector<string> res4, res4v2;
	vector<string>::size_type i;
	string answer3 = "nahasapeemapetilon";
	res1 = rtrim(s);
	res2 = replace_all(t, u, v);
	res3 = squeeze(w, c);
	res4 = split(x, z);
	res4v2 = split(y, z);
	cout << "-------Funciton #1--------" << endl;
	cout << "|" <<  s << "|" << endl;
	cout << "|" <<  res1 << "|" << endl;
	cout << "-------Funciton #2--------" << endl;
	cout << "|" <<  t << "|" << endl;
	cout << "|" <<  res2 << "|" << endl;
	cout << "-------Funciton #3--------" << endl;
	cout << "|" <<  w << "|" << endl;
	cout << "|" <<  res3 << "|" << endl;
	cout << "|" << answer3 << "|" << endl;
	cout << "-------Funciton #4--------" << endl;
	for(i = 0; i < res4.size(); i++){
		cout << '"'<< res4.at(i) << '"' << " ";
		cout << endl;
	}
	cout << "--------------" << endl;
	for(i = 0; i < res4v2.size(); i++){
		cout << '"'<< res4v2.at(i) << '"' << " ";
		cout << endl;
	}
}
