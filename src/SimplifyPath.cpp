//有些非常恶心的结果通不过  /...
class Solution {
public:
    string simplifyPath(string path) {
    	vector<string> vec;
    	vec.clear();
    	string s;
    	int len = path.size();
    	for(int i=0; i<len;){
    		if(path[i] == '/'){
    			string tmp;
    			for(int j=i+1; j<len && path[j] != '/';){
    				if(path[j]=='.' && paht[j+1]=='.'){
    					if(vec.size() != 0)
    						vec.pop_back();
    					j=j+2;
    					break;
    				}
    				tmp += path[j];
    				j++;
    			}
    			if(tmp != "" || tmp != "."){
    				vec.push_back(tmp);
    			}
    			i=j;
    		}
    	}    
    	if(vec.size() == 0){
    		s += '/';
    	}
    	for(int i=0; i<vec.size(); i++){
    		s += '/'+vec[i];
    	}
    	return s;

    }
};


//先对string进行预处理，把信息都放到一个vector中存起来，在遍历vec
vector<string> split(string path){
	vector<string> elems;
	int n = path.size();
	for(int i=0; i<n;){
		if(path[i] == '/'){
			string tmp;
			int j = i+1;
			while(j < n && path[j] != '/'){
				tmp += path[j];
				j++;
			}
			elems.push_back(tmp);
			i=j;
		}
	}
	return elems;
}

string simplifyPath(string path) {
	vector<string> elems = split(path);
	string result;

	int ignor = 0;
	for(int i=elems.size()-1; i>=0; i--){
		if(elems[i]==""||elems[i]=="."){
			continue;
		}
		if(elems[i] == ".."){
			ignor++;
			continue;
		}
		if(ignor>0){
			ignor--;
			continue;
		}
		if(result.size() == 0){
			result = '/'+elems[i];
		}else{
			result = "/"+elems[i]+result;
		}
	}
	return result.size() ?result : "/";

}


