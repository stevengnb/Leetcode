class Solution {
    public String removeOuterParentheses(String s) {
	StringBuilder fix = new StringBuilder();
	StringBuilder temp = new StringBuilder();
		int open = 0, close = 0;
	
	for (Character c : s.toCharArray()) {
		if(c == '(') open++;
		else close++;
		temp.append(c);
		
		if(open == close && open != 0) {
			fix.append(temp.substring(1, open+close-1));
			open = close = 0;
			temp.setLength(0);
		}
	}
	
      return fix.toString();
  }
	
}