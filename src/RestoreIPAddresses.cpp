//dfs,加上剪枝，注意边界的判断。
class Solution{
private:
	vector<string> result;
	int pos[4];
public:
	vector<string> restoreIpAddresses(string &s){
		dfs(0,4,s,0);
		return result;
	}

	void dfs(int dep, int maxDep, string &s, int start){
		if(dep == maxDep){
			if(start == s.size()){
				int beg = 0;
				string addr;
				for(int i=0; i<4;i++){
					string ip(s, beg, pos[i]-beg+1);
					beg = pos[i]+1;
					addr += i==0?ip:"."+ip;
				}
				result.push_back(addr);
			}
			return;
		}
		for(int i=start; i<s.size(); i++){
			if(checkNum(s, start, i)){
				pos[dep] = i;
				dfs(dep+1, maxDep, s, i+1);
			}
		}
	}

	bool checkNum(string &s, int start, int end){
		string ip(s, start, end-start+1);
		if(ip.size() == 1){
			return ip >= "0" && ip <="9";
		}else if(ip.size() == 2){
			return ip >="10" && ip <= "99";
		}else if(ip.size() == 3){
			return ip >= "100" && ip <="255";
		}else{
			return false;
		}
	}
};