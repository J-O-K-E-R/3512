#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cctype>
#define LINESIZE 1024
using namespace std;

int main() {
	string line, word, number, y, x;
	double n = 0;
	int m = 0, z = 0, i, w = 0, p = 0, count = 0;
	int letter;
	bool period, input, checks;
	ostringstream output;
	
	while(1){
		cout << "Enter the input line: " << endl;
		if(!getline(cin, line)){
			cin.clear();
			cout << "Failed" << endl;
			period = true;
		}

		istringstream strings(line);
		if(!(strings >> word)) {
			cin.clear();
			cout << "Failed" << endl;
			period = true;
		}

		istringstream numb(word);
		//running checks for the first string
		for(i = 0; (unsigned)i < word.size(); i++){
			//checking for multiple letters
			if(isalpha(word[i])){
				letter = i;
				count++;
				if(count > 1){
					checks = true;
				}
			}
			//checking negatives
			if(word[i] == '-'){
				checks = true;
			}
			//checking for floating point number
			if(word[i] == '.') {
				if(isdigit(word[i+1]) && isdigit(word[i-1])){
					period = true;
				}
			}
		}
		if(!(strings >> number)){
			period = true;
		}
		//checking second string for floating point and numbers on each side
		for(i = 0; (unsigned)i < number.size(); i++){
			if(number[i] == '.'){
				if(isdigit(number[i+1]) && isdigit(number[i-1])){
					input = true;
				}
			}
			//checking negatives
			if(number[i] == '-'){

				checks = true;
			}
			//checking for letters
			if(isalpha(number[i])){
				count++;
				if(count > 1){
					checks = true;
				}
			}
		}
		istringstream format(number);
//////////////////////////////////////decimal, hex, octal//////////////////////////////////////////////////////////////
		//for base 10
		if(word[letter] == 'd' && period == false && input == false && checks == false) {
			format >> m;
			if(!(numb >> z)){
				cout << "Invalid specifications" << endl;
				cout << endl;
			}else{
				output << dec << right << setfill(' ') << setw(z) << m;
				cout << output.str() << endl;
			}
		}
		//for octal
		else if(word[letter] == 'o' && period == false && input == false && checks == false) {
			format >> m;
			if(!(numb >> z)){
				cout << "Invalid specifications" << endl;
				cout << endl;
			} else{
			output << oct << right << setfill(' ') << setw(z) << m;
			cout << output.str() << endl;
			}
		}
		//for lowercase hex
		else if(word[letter] == 'x' && period == false && input == false && checks == false) {
			format >> m;
			if(!(numb >> z)){
				cout << "Invalid specifications" << endl;
				cout << endl;
			}else{
			output << hex << nouppercase << right << setfill(' ') << setw(z) << m;
			cout << output.str() << endl;
			}
		}
		//for uppercase hex
		else if(word[letter] == 'X' && period == false && input == false && checks == false) {
			format >> m;
			if(!(numb >> z)){
				cout << "Invalid specifications" << endl;
				cout << endl;
			}else{
			output << hex << uppercase << right << setfill(' ') << setw(z) << m;
			cout << output.str() << endl;
			}
		}

////////////////////////////////////////////fixed, scientific/////////////////////////////////////////////////////////
		//this is for fixed
		else if(word[letter] == 'f' && period == true && input == true && checks == false) {
			format >> n;
			getline(numb, y, '.');
			getline(numb, x, 'f');
			istringstream width(y);
			width >> w;
			istringstream precision(x);
			precision >> p;
			output << fixed << right << setfill(' ') << setw(w) << setprecision(3) << n;
			cout << output.str() << endl;
		}
		//This is for lowercase scientific
		else if(word[letter] == 'e' && period == true && input == true && checks == false) {
			format >> n;

			getline(numb, y, '.');
			getline(numb, x, 'e');
			istringstream width(y);
			width >> w;
			istringstream precision(x);
			precision >> p;
			output << scientific << nouppercase << right << setfill(' ') << setw(w) << setprecision(p) << n;
			cout << output.str() << endl;
		}
		//This is for uppercase scientific
		else if(word[letter] == 'E' && period == true && input == true && checks == false) {
			format >> n;
			getline(numb, y, '.');
			getline(numb, x, 'E');
			istringstream width(y);
			width >> w;
			istringstream precision(x);
			precision >> p;
			output << scientific << uppercase << right << setfill(' ') << setw(w) << setprecision(3) << n;
			cout << output.str() << endl;
			} else {
			cout << "Invalid specifications" << endl;
			cout << endl;
		}
		//resset and clears all
		output.clear();
		output.str(string());
		period = false;
		input = false;
		checks = false;
		count = 0;
	}
}