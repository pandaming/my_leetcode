string strMulti(string num, char ch){
	int n = ch - '0';
	string s;
	int carry = 0;
	for(int i=num.size()-1; i>=0; i--){
		int x = (s[i]-'0')*n + carry;
		carry = x/10;
		s.insert(s.begin(), x%10 + '0');
	}
	if(carry > 0){
		s.insert(s.begin(), carry+'0');
	}
	return s;
}

string strPlus(string &num1, string&num2){
	string s;
	int carry = 0;
	int len1 = num1.size();
	int len2 = num2.size();

	for(int i=len1-1, j=len2-1; i>=0 || j>=0; i--, j--){
		int x1 = i>=0? num1[i]-'0':0;
		int x2 = j>=0? num2[j]-'0':0;
		int x = x1+x2+carry;
		carry = x/10;
		s.insert(s.begin(), x%10+'0');
	}
	if(carry > 0){
		s.insert(s.begin(), carry+'0');
	}
	return s;
}

string multiply(string num1, string num2){

	int shift = 0;
	string result = "0";
	for(int i=num1.size()-1; i>=0; i--){
		string s=strMulti(num2, num1[i]);
		for(int j=0; j<shift; j++){
			s.insert(s.end(), '0');
		}

		result = strPlus(result, s);
		shift++;
	}
	return result;
}


