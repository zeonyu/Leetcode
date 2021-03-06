//Last Modified: 14/12/2014
//Author: Junbo Xin

#include<vector>
#include<string>
#include<iostream>
using namespace std;

//********************Scramble string************************************
/*Given a string s1, we may represent it as a binary tree by partitioning
 it to two non-empty substrings recursively.
Below is one possible representation of s1 = "great":
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.
For example, if we choose the node "gr" and swap its two children, 
it produces a scrambled string "rgeat".
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".
Similarly, if we continue to swap the children of nodes "eat" and "at",
 it produces a scrambled string "rgtae".
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".
Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

//when F[i][j][k]=true  S1[i..i+k-1] == S2[j..j+k-1], k is the number of char
//when k=1, F[i][j][1] = S1[i] == S2[j]
//when k=2, F[i][j][2] = (F[i][j][1] && F[i+1][j+1][1]) || (F[i][j+1][1] && F[i+1][j][1]
//s1_left==s2_left && s1_right==s2_right   or   s1_left == s2_right && s1_right==s2_left
//F[i][j][1] && F[i+1][j+1][1]   ======> S1[i]   == S2[j] && S1[i+1]==S2[j+1]
 //F[i][j+1][1] && F[i+1][j][1]  ======> S1[i+1] == S2[j] && S1[i]  == S2[j+1]

bool isScramble(string s1, string s2) {
  int n= s1.length();
  int n2 = s2.length();
  if(n != n2) return false;
  bool dp[100][100][100];
  memset(dp,false,sizeof(bool)*100*100*100);
  for(int k = 1; k <= n; ++k){
    for(int i =0; i <= n-k; ++i){
      for(int j = 0; j <= n-k; ++j){
	if(k ==1)
	  dp[i][j][k] = s1[i]==s2[j];
	else
	  for(int m = 1; m < k; ++m){
	    if( (dp[i][j][m]&&dp[i+m][j+m][k-m]) || (dp[i][j+k-m][m]&&dp[i+m][j][k-m]) ){
	      dp[i][j][k] = true;
	      break;
	    }//end if
	  }//end m while
      } //end j while
    } // end i while
  }// end k while
  return dp[0][0][n];
}

 int main(){
   //***************Scramble string*****************
   string t1= "greatbk";
   string t2="rgtaeb";
   bool isScra= isScramble(t1,t2);
   cout << isScra << endl;
   getchar();
   return 0;
 }
