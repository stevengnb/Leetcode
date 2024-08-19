class Solution {
    public String customSortString(String order, String s) {
        HashMap<Character, Integer> hm = new HashMap<>();
        StringBuilder sb = new StringBuilder();
        
        for(Character c : s.toCharArray()) {
            hm.put(c, hm.getOrDefault(c, 0) + 1);
        }
        
        for(Character c : order.toCharArray()) {
            if(hm.containsKey(c)) {
                for(int i = 0; i < hm.get(c); i++) {
                    sb.append(c);	    			 
                }
                hm.remove(c);
            }
        }
        
        if(!hm.isEmpty()) {
            for(Character c : hm.keySet()) {
                for(int i = 0; i < hm.get(c); i++) {
                    sb.append(c);
                }
            }
        }
        
        return sb.toString();
    }
}