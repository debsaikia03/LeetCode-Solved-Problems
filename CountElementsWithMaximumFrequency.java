class Solution {
    public int maxFrequencyElements(int[] nums) {
        int c,max=1,a=0;
        for(int i=0;i<nums.length;i++)
        {
            c=1;
            for(int j=i+1;j<nums.length;j++)
            {
                if(nums[i]==nums[j])
                c++;
            }
            
            if(c==max)
            a++;

            else if(c>max)
            {
                max=c;
                a=0;
            }

        }
        
        if(max==1)
        {
          max=nums.length;
        }

        else {
        int k=max;
        while(a>0)
        {
            max=max+k;
            a--;
        }
        }

        return max;
    }
}