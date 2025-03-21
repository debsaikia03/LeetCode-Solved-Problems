class Solution {
    public int findContentChildren(int[] g, int[] s) {
        
        Arrays.sort(g);
        Arrays.sort(s);

        int l=0;
        int r=0;

        int count = 0;

        while(l < g.length && r < s.length){

            if(s[r] >= g[l]){

                count++;
                l++;
                r++;
            }

            else{

                r++;
            }
        }

        return count;
    }
}