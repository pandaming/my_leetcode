class MinStack{
private:
	stack<int> stack;
	stack<int> stack_min;
public:
	void push(int x){
		stack.push(x);
		if(stack_min.empty() || x < stack_min.top()){
			stack_min.push(x);
		}

	}
	void pop(){
		int top = stack.top();
		stack.pop();
		if(top == stack_min.top())
			stack_min.pop();
	}
	int top(){
		return stack.top();
	}
	int getMin(){
		return stack_min.top();
	}
};
