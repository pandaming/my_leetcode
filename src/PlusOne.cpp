#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits){
	int carry = 1;
	vector<int> vec;
	while(digits.size() > 0){
		int data = digits.back();
		digits.pop_back();
		data = data + carry;
		vec.insert(vec.begin(), data%10);
		carry = data/10;
	}
	if(carry > 0){
		vec.insert(vec.begin(),carry);
	}
	return vec;
}

void printVector(vector<int> vec){
	for(int i=0; i<vec.size(); i++){
		cout << vec[i] << " ";
	}
	cout << endl;
};


int main(){
	int a[] = {9,9,9,9};
	vector<int> d(&a[0], &a[0]+sizeof(a)/sizeof(int));
	vector<int> v = plusOne(d);
	printVector(v);
	return 0;
}