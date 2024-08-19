class Solution {
    public int evalRPN(String[] tokens) {
		Stack<String> stack = new Stack<>();
		Integer result = 0;
     
		for(int i = 0; i < tokens.length; i++) {
			if(tokens[i].equals("/") || tokens[i].equals("*") || tokens[i].equals("-") || tokens[i].equals("+")) {
				Integer b = Integer.parseInt(stack.peek());
				stack.pop();
				Integer a = Integer.parseInt(stack.peek());
				stack.pop();
				
				switch(tokens[i]) {
					case "/":
						result = a/b;
						break;
					case "+":
						result = a+b;
						break;
					case "*":
						result = a*b;
						break;
					case "-":
						result = a-b;
						break;
				}
				stack.add(result.toString());
			} else {
				stack.add(tokens[i]);
			}
		}

		return Integer.parseInt(stack.peek());
    }
}