class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int maxSide=0;
        for(int i=0;i<bottomLeft.size();i++){
            for(int j=i+1;j<topRight.size();j++){
                int maxbottomLext_X=max(bottomLeft[i][0],bottomLeft[j][0]);
                int maxbottomLext_Y=max(bottomLeft[i][1],bottomLeft[j][1]);

                int mintopRight_X=min(topRight[i][0],topRight[j][0]);
                int mintopRight_Y=min(topRight[i][1],topRight[j][1]);
                
                int max_W=(mintopRight_X-maxbottomLext_X);
                int max_H=(mintopRight_Y-maxbottomLext_Y);

                maxSide=max(maxSide,min(max_W,max_H));
            }
        }
        return maxSide*1LL*maxSide;
    }
};