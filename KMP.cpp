#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <complex>
#include <math.h>
#include <utility>
#include <cmath>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <ctime>
 
#define all(a) (a).begin(),(a).end()
using namespace std;
 

vi PrefixFunction(string pattern){
	int PatternLength = pattern.length() ;
	vi PrefixTable(PatternLength) ;
	PrefixTable[0] = 0 ;
	int i = 0 ;
	for(int j=1; j<PatternLength; j++){
		while(i>0&&pattern[i]!=pattern[j]){
			i = PrefixTable[i] ;
		}
		if(pattern[i]==pattern[j]){
			i = i + 1 ;
		}
		PrefixTable[j] = i ;
	}
	return PrefixTable ;
}



void KMP(string text, string pattern){
	vi PrefixTable = PrefixFunction(pattern) ;
	int PatternLength = pattern.length() ;
	int TextLength = text.length() ;
	int j = 0 ;
	for(int i=0; i<TextLength; i++) {
		while(j>0&&pattern[j]!=text[i]){
			j = PrefixTable[j] ;
		}
		if(pattern[j]==text[i]){
			j = j + 1;
		}
		if(j==PatternLength){
			cout<<"Found at position (index 0): "<< (i-PatternLength)+1 << endl ;
			j = PrefixTable[j] ;
		}
	}
}



int main(){
	string text, pattern ;
	cin >> text >> pattern ;
	KMP(text, pattern) ;
	return 0;
}
