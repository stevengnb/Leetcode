class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> save = new HashMap<>();
		
         for(int i = 0; i < s.length(); i++) {
        	if(save.containsKey(s.charAt(i))) {
        		if(t.charAt(i) != save.get(s.charAt(i))) return false;
        	} else {
        		if(save.containsValue(t.charAt(i)) && save.get(s.charAt(i)) == null) {
        			return false;
        		} else {
        			save.put(s.charAt(i), t.charAt(i));        			
        		}
        	}
        }
        
		return true;
    }
}