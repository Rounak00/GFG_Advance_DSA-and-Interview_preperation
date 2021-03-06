#include<bits/stdc++.h>
using namespace std;

// PURE BACKTRACKING
bool wildCardUtil(int i, int j, int patternLen, int strLen, string pattern, string str){
    if(i == patternLen && j == strLen){
        return true;
    }

    if(j == strLen){
        for(int k=i;k<patternLen;k++){
            if(pattern[k] != '*')
                return false;
        }
        return true;
    }

    if(i == patternLen){
        return false;
    }

    if(pattern[i] == '?')
        return wildCardUtil(i+1,j+1,patternLen,strLen,pattern,str);

    if(pattern[i] == '*'){
        return wildCardUtil(i+1,j,patternLen,strLen,pattern,str) || wildCardUtil(i,j+1,patternLen,strLen,pattern,str);
    }

    if(pattern[i] != str[j])
        return false;

    return wildCardUtil(i+1,j+1,patternLen,strLen,pattern,str);             
}

int wildCard(string pattern,string str){
    int patternLen = pattern.length();
    int strLen = str.length();
    return wildCardUtil(0,0,patternLen,strLen,pattern,str);
}

// DYNAMIC PROGRAMMING
bool wildCardUtil(int i, int j, int patternLen, int strLen, string pattern, string str,vector<int> dp[]){
    if(i == patternLen && j == strLen){
        return true;
    }

    if(j == strLen){
        for(int k=i;k<patternLen;k++){
            if(pattern[k] != '*')
                return false;
        }
        return true;
    }

    if(i == patternLen){
        return false;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(pattern[i] == '?')
        return dp[i][j] = wildCardUtil(i+1,j+1,patternLen,strLen,pattern,str,dp);

    if(pattern[i] == '*'){
        return dp[i][j] = wildCardUtil(i+1,j,patternLen,strLen,pattern,str,dp) || wildCardUtil(i,j+1,patternLen,strLen,pattern,str,dp);
    }

    if(pattern[i] != str[j])
        return dp[i][j] = false;

    return dp[i][j] = wildCardUtil(i+1,j+1,patternLen,strLen,pattern,str,dp);             
}

int wildCard(string pattern,string str){
    int patternLen = pattern.length();
    int strLen = str.length();
    vector<int> dp[patternLen];

    for(int i=0;i<patternLen;i++){
        for(int j=0;j<strLen;j++){
            dp[i].push_back(-1);
        }
    }
    return wildCardUtil(0,0,patternLen,strLen,pattern,str,dp);
}