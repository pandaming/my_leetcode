// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        
        for(int i=0; i<numRows; i++){
            vector<int> vec;
            if(i == 0){
                vec.push_back(1);
            }else{
                vec.push_back(1);
                for(int j=0; j<i-1; j++){
                    vec.push_back(result[i-1][j]+result[i-1][j+1]);
                }
                vec.push_back(1);
            }
            result.push_back(vec);
        }
        return result;
    }
};
