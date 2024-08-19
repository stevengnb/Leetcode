class MinStack {
    Stack<Integer[]> stack;
    int min;

    public MinStack() {
        stack = new Stack<>();
    }
    
    public void push(int val) {
        if(stack.isEmpty()) min = val;
        if(val < min) min = val;

        stack.add(new Integer[]{val, min});
    }
    
    public void pop() {
        stack.pop();
        if(!stack.isEmpty()) min = stack.peek()[1]; 
    }
    
    public int top() {
        return stack.peek()[0];
    }
    
    public int getMin() {
        return stack.peek()[1];
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */