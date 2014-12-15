// Given an input string, reverse the string word by word.

// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

//方法一：缺少字符串的预处理的功能，使得代码通不过
void reverseWords(string &s) {
    int n = s.size();
    reverseWordsHelper(s, 0, n-1);
    int last = -1;
    s[n] = " ";
    for(int i=0; i<=n; i++){
    	if(isspace(s[i])){
    		reverseWordsHelper(s, last+1, i-1);
    		last = i;
    	}
    }
}

void reverseWordsHelper(string &s, int start, int end){
	if(length <= 1) return s;
	while(start < end){
		swap(s[start], s[end]);
		start++;
		end--;
	}
}


//方法二：利用堆结构来做， 通过、、
void reverseWords(string &s){
	vector<string> stack_words;
	bool wordStart = false;

	const char *pHead = s.c_str();
	const char *pStr, *pBegin, *pEnd;

	//这部分预处理非常重要，加入一个bool值用于判断标记的位置
	for(pStr=pHead; *pStr!='\0';pStr++){
		if(!isspace(*pStr) && wordStart == false){
			wordStart = true;
			pBegin = pStr;
			continue;
		}
		if(isspace(*pStr) && wordStart == true){
			wordStart = false;
			pEnd = pStr;
			stack_words.push_back(s.substr(pBegin-pHead, pEnd-pBegin));
		}
	}

	if(wordStart == true){
		pEnd = pStr;
		stack_words.push_back(s.substr(pBegin-pHead, pEnd-pBegin));
	}

	string result = "";

	while(stack_words.size()>0){
		string tmp = stack_words.back();
		if(stack_words.size() == 1){
			result += tmp;
		}else{
			result += tmp;
			result += " ";
		}
		stack_words.pop_back();
	}
	s.clear();
	s = result;
}





