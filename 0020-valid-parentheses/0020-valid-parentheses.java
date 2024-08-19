class Solution {
    public boolean isValid(String s) {
		HashMap<Character, Character> parents = new HashMap<>();
		parents.put(')', '(');
		parents.put('}', '{');
		parents.put(']', '[');
		
		Stack<Character> stacks = new Stack<>();
    	int len = s.length();
    	
    	for(int i = 0; i < len; i++) {
    		if(!stacks.isEmpty() && (stacks.lastElement() == parents.get(s.charAt(i)))) {
    			stacks.pop();
    		} else {
    			stacks.push(s.charAt(i));
    		}
    	}
        	
    	
    	if(stacks.isEmpty()) {
    		return true;
    	} else {
    		return false;
    	}
    }
}