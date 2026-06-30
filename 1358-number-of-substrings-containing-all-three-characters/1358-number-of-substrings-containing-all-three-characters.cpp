class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        int r=0;
        int count=0;
        int hash[3]={0};
        while(r<s.size()){
        hash[s[r]-'a']++;
        while(hash[0] && hash[1] && hash[2]){
            count += (s.size()-r);
            hash[s[l]-'a']--;
            l++;
        }
        r++;

        }
        return count;
    }
};