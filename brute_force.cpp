#include<bits/stdc++.h>
using namespace std;

bool generateCombinations(vector<char> &source,vector<char> &key,vector<char> &current){
	static long long count=0;
	if(current.size()==key.size()){
		cout<<++count<<" : ";
		for(unsigned int i=0;i<key.size();i++){
			cout<<current[i];
		}
		cout<<endl;
		if(key==current){
			cout<<"MATCH FOUND!"<<endl;
			return true;
		}
		return false;
	}
	for(unsigned int i=0;i<source.size();i++){
		current.push_back(source[i]);
		if(generateCombinations(source,key,current)==true){
			return true;
		}
		current.pop_back();
	}
	return false;
}



int main(){
	vector<char> source; // VECTOR TO STORE ALL POSSIBLE CHARACTERS THAT NEEDS TO BE BRUTE FORCED.
	for(int i=0;i<26;i++){
		source.push_back('a'+i);
	}

	vector<char> current;
	vector<char> key;
	string s; //INPUT KEY HERE
	cout<<"Enter key to be searched here"<<endl;
	cin>>s;
	for(unsigned int i=0;i<s.length();i++){
		key.push_back(s[i]);
	}

	if(key.size()>source.size()){  //IF INPUT KEY SIZE IF GREATER THAN POSSIBLE CHARACTERS.
		cout<<"Key too long, NOT FOUND!"<<endl;
	}
	else{
	 generateCombinations(source,key,current);
	}
	return 0;
}
