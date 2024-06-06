class Solution {
    public boolean isPalindrome(String s) {
        
       String s1 = s.replaceAll("[^a-zA-Z0-9]", "");

       

       StringBuffer s2 = new StringBuffer(s1);

       s2.reverse();

       if(s1.equalsIgnoreCase(s2.toString())){
          return true;
       } 

       return false;

    }
}