class Solution {
    public static int maxDepth(String s) {
    	int max, open;
    	max = open = 0;
    	
    	for(Character c : s.toCharArray()) {
    		if(c == '(') open++ ; 
    		else if(c == ')') open--;
    		
    		if(open > max) max = open;
    	}
    	
    	return max;
    }
}