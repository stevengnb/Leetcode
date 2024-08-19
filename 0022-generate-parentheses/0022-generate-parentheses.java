class Solution {
    public List<String> generateParenthesis(int n) {
		List<String> newList = new ArrayList<>(); 
		generateString(newList, n, 0, 0, "");
		return newList;
    }
	
	public void generateString(List<String> theList, int n, int open, int close, String str) {
		// open = (
		// close = )
		if(str.length() == 2 * n) {
			theList.add(str);
			System.out.println(str);
			return;
		}
		
		if(open < n) {
			generateString(theList, n, open+1, close, str + "(");
		} 
		
		if(close < open) {
			generateString(theList, n, open, close+1, str + ")");
		}
	}
}