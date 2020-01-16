#include<iostream>
using namespace std;
class rem{
public:
    bool isMatch(string s, string p) {
    	int rows=s.length()+1;
    	int cols=p.length()+1;
    	bool** T = new bool* [rows];
    	for(int i=0;i<rows;i++)
    	    T[i] = new bool[cols];
    	T[0][0] = true;
    	for(int i = 1; i < cols; i++){
    		if(p[i-1] == '*'){
    			T[0][i] = T[0][i-2];
    		}else{
    			T[0][i] = false;
    		}
    	}
    	for(int i = 1; i < rows; i++){
    		T[i][0] = false;
    	}

    	for(int i = 1; i < rows; i++){
    		for(int j = 1; j < cols; j++){
    			if(s[i-1] == p[j-1] || p[j-1] == '.'){
    				T[i][j] = T[i-1][j-1];
    			}else if(p[j-1] == '*'){
    				T[i][j] = T[i][j-2];
    				if(s[i-1] == p[j-2] || p[j-2] == '.'){
    					T[i][j] = T[i][j] | T[i-1][j];
    				}
    			}else{
    				T[i][j] = false;
    			}
    		}
    	}
    	bool result = T[rows - 1][cols - 1];
    	for(int j=0;j<rows;j++)
    	    delete[] T[j];
    	delete[] T;

    	return result;
    }
};

int main(int argc, char* argv[]){
	rem rem_test;
	string a = "aa";
	string b = "a";
	cout<<rem_test.isMatch(a,b);
    return 0;
}
