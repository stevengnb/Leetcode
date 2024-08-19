class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        if(s1.equals(s2)) return true;
        
        ArrayList<Character> c1 = new ArrayList<>();
        ArrayList<Character> c2 = new ArrayList<>();
        int diff = 0;
        
        for(int i = 0; i < s1.length(); i++) {
        	Character a = s1.charAt(i);
        	Character b = s2.charAt(i);
        	
        	if(a != b) {
        		c1.add(a);
        		c2.add(b);        
        		diff++;
        	}
        }
        
        return (diff == 2) && c1.get(0) == c2.get(1) && c2.get(0) == c1.get(1);
    }
}