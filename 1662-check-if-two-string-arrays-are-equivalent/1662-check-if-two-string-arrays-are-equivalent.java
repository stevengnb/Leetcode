class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
		StringBuilder sb1 = new StringBuilder();
		StringBuilder sb2 = new StringBuilder();
		
        for(String s : word1) {
        	sb1.append(s);
        }
        
        for(String s : word2) {
        	sb2.append(s);
        }
        
        return (new String(sb1)).equalsIgnoreCase(new String(sb2));
    }
}