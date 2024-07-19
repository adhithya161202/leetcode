class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>minel;
        vector<int>maxel;
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            int minelrow=INT_MAX;
            for(int j=0;j<m;j++){
                minelrow=min(minelrow,matrix[i][j]);
            }
            minel.push_back(minelrow);
        }
        for(int i=0;i<m;i++){
            int maxelcol=INT_MIN;
            for(int j=0;j<n;j++){
                maxelcol=max(maxelcol,matrix[j][i]);
            }
            maxel.push_back(maxelcol);
        }
       
        vector<int>result;
        for(int p=0;p<minel.size();p++){
            for(int q=0;q<maxel.size();q++){
                if(minel[p]==maxel[q]){
                    result.push_back(minel[p]);
                }
            }
        }
        return result;
    }
};
