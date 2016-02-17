#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>  
using namespace std;

bool is_valid_id(const string&);
bool is_valid_score(int id);
bool get_word(const string& prompt, string& word, bool (*is_valid)(const string&));
bool get_int(const string& prompt, int& n, bool (*is_valid)(int));

bool get_word(const string& prompt, string& word, bool (*is_valid)(const string&)){
	string line, id;
	bool valid = false;
	while(valid == false) {
		cout << prompt << endl;
		if(!(getline(cin, line))){
			valid = false;
			if(cin.eof()){
				cin.clear();
				return false;
			}
		}
		istringstream tt(line);
		tt >> id;
		if(((*is_valid)(id)) == true) {
			word = id;
			valid = true;
			return true;
		} else {
			valid = false;
		}
	}
	return false;
}

bool get_int(const string& prompt, int& n, bool (*is_valid)(int)) {
	string line;
	int score;
	bool valid = false;
	while(valid == false) {
		cout << prompt << endl;
		if(!(getline(cin, line))){
		valid = false;
			if(cin.eof()){
				cin.clear();
				return false;
			}
		}
		istringstream ss(line);
		ss >> score;
		if(((*is_valid)(score)) == true) {
			n = score;
			return true;
		} else {
			valid = false;
		}
	}
	return false;
}

bool is_valid(const string& id){
	if(id[0] != 'a'){
		return false;
	}
	for (int i = 1; i < 9; i++) {
		if(!isdigit(id[i])) {
			return false;
		}
	}
	if(id.size() > 9) {
		return false;
	}
	return true;
}
bool is_valid(int score){
	if(score >= 0 && score <= 100) {
		return true;
	}
	return false;
}

int main(){
	const string prompt = "Enter student id: ";
	const string prompt2 = "Enter student score: ";
	string word;
	int score;
	bool validid = false, validscore = false;
	while(1){
		validid = get_word(prompt, word, &is_valid);
		cin.clear();
		validscore = get_int(prompt2, score, &is_valid);
		cin.clear();
		if(validid == true && validscore == true) {
			cerr << setfill(' ') << setw(9) << word << " ";
			cerr << setfill(' ') << setw(3) << score << " ";
		}
	}
}
