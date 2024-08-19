class Solution {
    public String reverseOnlyLetters(String s) {
        char str[] = s.toCharArray();
        int left = 0;
        int right = s.length()-1;
        
        while(left < right) {
            if(Character.isAlphabetic(str[left]) && Character.isAlphabetic(str[right])) {
                char c = str[left];
                str[left] = str[right];
                str[right] = c;
                left++;
                right--;
            } 
            else if(!Character.isAlphabetic(str[left])) left++;
        else if(!Character.isAlphabetic(str[right])) right--;
        }
        
        return new String(str);
    }
}