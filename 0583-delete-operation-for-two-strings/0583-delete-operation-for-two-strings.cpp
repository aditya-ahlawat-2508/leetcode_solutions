class Solution {
public:
    int minDistance(string word1, string word2) {
    //    either you can delete one thing at a time or you can add one thing at a time 
    // so the main crux of the solution is to find lcs and then ans=(n1-lcs)+(n2-lcs)
    int n=word1.length();
    int m=word2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=m;j++) dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return ((n-dp[n][m])+(m-dp[n][m]));
    }
};