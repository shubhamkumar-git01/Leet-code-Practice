// Problem: 3302. Find the Lexicographically Smallest Valid Sequence
// Runtime: 92 ms (Beats 5.32%)
// Memory: 139.5 MB (Beats 7.45%)

class Solution {
public:
 vector<int> validSequence(string a,string b){
  int n=a.size(),m=b.size(),x=m,y=m;
  vector<int>s(n+1),t(n+1),r;
  for(int i=n-1;i>=0;i--){
   int X=x,Y=y;
   if(x&&a[i]==b[x-1])x--;
   y=min(y&&a[i]==b[y-1]?y-1:y,X?X-1:X);
   s[i]=m-x;t[i]=m-y;
  }
  int j=0,u=0;
  for(int i=0;i<n&&j<m;i++)
   if(a[i]==b[j]?(m-j-1<=(u?s[i+1]:t[i+1])):!u&&m-j-1<=s[i+1]){
    r.push_back(i);u|=a[i]!=b[j];j++;
   }
  return j==m?r:vector<int>();
 }
};