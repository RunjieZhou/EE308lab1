#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <regex>
#include <stack>
#include <vector>
#include <map>
using namespace std;
int find_SubString(string s,string sub){//find the substring
	
	int index1 = 0;
	int a = 0;
	while((index1 = s.find(sub,index1)) != s.npos){
		index1=index1+1;
		a=a+1;
	}
	return a;
}
vector<int> lookforswi(vector<string> v1){//we find out the switch
	
	
	vector<int> ofoutput;
	stack<char> sto;
	bool bol = false;
	int number = 0;
	int lee=v1.size();
	for(int i=0;i<=lee-1;i++){
		string stri1 = v1[i];
		if(stri1.find("switch") != stri1.npos){
			bol = true;
		}
		if(bol){
			if(stri1.find('{') != stri1.npos){
				sto.push('{');
			}else if(stri1.find('}') != stri1.npos){
				sto.pop();
			}
		}
		if(sto.empty() == false){
			if(stri1.find("case") != stri1.npos){
				number =number+1;
			}
		}else{
			bol = false;
			if(number != 0){
				ofoutput.push_back(number);
				number = 0;
			}
		}
	}
	return ofoutput;
}
vector<string> processStr11(string str){//process string
	
	vector<string> vct;
	string sub = "";
	for(int i=0;i<str.length();i++){
		if(str[i] == '\n'){
			sub += str[i];
			vct.push_back(sub);
			sub = "";
		}else{
			sub =sub + str[i];
		}
	}
	return vct;
}
vector<int> seelifel(vector<string> v){
	stack<bool> sto;
	vector<int> ofoutput;
	int value1 = 0,value2 = 0;
	int size = 0;
	int le=v.size();
	for(int i=0;i<=le-1;i++){
		string stri1 = v[i];
		if(stri1.find("else if") == stri1.npos && stri1.find("if") != stri1.npos){
			sto.push(false);
			size =size+1;
			continue;
		}else if(stri1.find("else if") != stri1.npos && sto.empty() == false){
			sto.top() = true;
			continue;
		}else if(stri1.find("else if") == stri1.npos && stri1.find("else") != stri1.npos){
			if(sto.top() == true){
				value2 =value2+1;
			}else{
				value1 =value1+1;
			}
			sto.pop();
			continue;
		}
	}
	ofoutput.push_back(value1);
	ofoutput.push_back(value2);
	return ofoutput;
}
string readInof(string filename) {//return relevant string
	ifstream ifile(filename);
	ostringstream buf;
	char ch;
	while (buf && ifile.get(ch))
		buf.put(ch);
	ifile.close();
	return buf.str();
}

int main() {
	
	string place;
	cout << "Please input the file place" << endl;
	cin >> place;
	cin.clear(); 
	cin.sync(); 
	int level;
	cout << "Please input the level you need" << endl;
	scanf("%d",&level);
	string str = readInof(place);
	vector<string> ans = processStr11(str);
	
	vector<int> ofoutput = seelifel(ans);

	vector<int> ofoutput_switch = lookforswi(ans);
	//
	smatch outOf;//the word
	regex pattern("void|signed|unsigned|short|long|int|float|double|char|enum|struct|union|typedef|Bool|Imaginary|Complex|const|volatile|restrict|inline|auto|static|extern|register|sizeof|goto|return|break|continue|if|else|switch|case|default|do\\s|while|for");
	string::const_iterator iterStart = str.begin();
	string::const_iterator iterEnd = str.end();
	string temp;
	int number = 0;
	while (regex_search(iterStart, iterEnd, outOf, pattern))
	{
		number =number+1;
		iterStart = outOf[0].second;
	}
	if(level == 1){//when level =1
		
		cout << "total num: " << number << endl;
	}else if(level == 2){
		cout << "total num: " << number << endl;
		cout << "switch num: " << ofoutput_switch.size() << endl;
		cout << "case num: ";
		for(int i=0;i<ofoutput_switch.size();i++){
			cout << ofoutput_switch[i] << " ";
		}cout << endl;
	}else if(level == 3){
		cout << "total num: " << number << endl;
		cout << "switch num: " << ofoutput_switch.size() << endl;
		cout << "case num: ";
		for(int i=0;i<ofoutput_switch.size();i++){
			cout << ofoutput_switch[i] << " ";
		}cout << endl;
		cout << "if-else num: " << ofoutput[0] << endl;
	}else if(level == 4){
		cout << "total num: " << number << endl;
		cout << "switch num: " << ofoutput_switch.size() << endl;
		cout << "case num: ";
		for(int i=0;i<ofoutput_switch.size();i++){
			cout << ofoutput_switch[i] << " ";
		}cout << endl;
		cout << "if-else num: " << ofoutput[0] << endl;
		cout << "if-elseif-else num:" << ofoutput[1] << endl;
	}else{
		cout << "wrong level" << endl;
	}
	return 0;
}
