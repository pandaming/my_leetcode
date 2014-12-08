// problem: Time Limit Exceeded
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        int n = S.size();
        int m = (1<<n)-1;
        for(int i=0; i<=m; i++){
          vector<int> vec;
          for(int j=0; j<n; j++){
            if(i & (1<<j)){
              vec.push_back(S[j]);
            }
          }
          bool flag = false;
          for(int k=0; k<result.size(); k++){
            if(veccmp(vec, result[k])){
              flag = true;
            }
          }
          if(flag){
            continue;
          }else{
            result.push_back(vec);
          }
        }
        return result;
    }

    bool veccmp(vector<int> v1, vector<int> v2){
      int n = v1.size();
      int m = v2.size();
      if(n != m) return false;
      for(int i=0; i<n; i++){
        if(v1[i] != v2[i])
          return false;
      }
      return true;
    }
};



//利用递归的方法来做，同时注意避免相同的数
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int> > result;
    if(S.size() == 0) return result;
    sort(S.begin(), S.end());
    
    vector<int> solution;
    result.push_back(solution);
    subsetHelper(S, 0, solution, result);
    return result;
}
void subsetHelper(vector<int> &num, int start, vector<int> solution, vector<vector<int> > &result){
    for(int i=start; i<num.size(); i++){
        if(i>start && num[i] == num[i-1]) continue;
        solution.push_back(num[i]);
        result.push_back(solution);
        subsetHelper(num, i+1, solution, result);
        solution.pop_back();
    }
}
};


