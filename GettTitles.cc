//title attribute grabber for html
//author hasnieking
//compiles with GNU GCC on Windows

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//sets title=" in the array
void setuparray(char title[]) {
	title[0] = 't';
	title[1] = 'i';
	title[2] = 't';
	title[3] = 'l';
	title[4] = 'e';
	title[5] = '=';
	title[6] = '"';
}

//test for the combination of chars that makes title="
bool testfortitle(ifstream &input, char &kar) {
	char title[7];
	setuparray(title);


	for (int i = 0; i <= 6; i++) {
		if (title[i] != kar) {
			return false;
		}
		else {
			kar = input.get();
		}
	}

return true;
}

//copies title to output file
void copytitle(ifstream &input, ofstream &output, string filenameout, char &kar) {
	output.open(filenameout.c_str(), ios::app);
	static bool first = false;

	//creates newline except for first time
	if (first) {
		output.put('\n');
	}
	first = true;

	//puts char in output file
	while (kar != '"') {
		cout << kar;
		output.put(kar);
		kar = input.get();
	}
	output.close();
}

int main() {
	//gets filename
	string filenamein;
	cout << "Input File: ";
	cin >> filenamein;
	string filenameout;
	cout << "Output File: ";
	cin >> filenameout;

	//opens file
	ifstream input;
	input.open(filenamein.c_str(), ios::in);
	ofstream output; 

	//gets first character of input file
	char kar;
	kar = input.get();

	cout << kar << endl;

	//deletes old output file when it exists
	if (!input.eof()) {
		output.open(filenameout.c_str(), ios::trunc);
		output.close();
	}

	//tests for the letter t, when found tests for title and then copies
	while (!input.eof()) {
		if (kar == 't') {
			if (testfortitle(input, kar)) {
				copytitle(input, output, filenameout, kar);
			}
		}
		else {
			kar = input.get();
		}
	}
	input.close();
	return 0;
}
