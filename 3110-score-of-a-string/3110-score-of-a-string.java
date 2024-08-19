class Solution {
    public int scoreOfString(String s) {
		int total = 0;
		
        for(int i = 0; i < s.length()-1; i++) {
        	int a = (int)s.charAt(i);
        	int b = (int)s.charAt(i+1);
        	
        	total += Math.abs(a-b);
        }
        
        return total;
    }
}