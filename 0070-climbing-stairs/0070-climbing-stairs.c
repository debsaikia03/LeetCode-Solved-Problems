int climbStairs(int n) {

   //base case
   if(n <= 1) return 1;

   int d[n+1]; //storing no. of ways

    d[0] = 1;
    d[1] = 1;

   for(int i = 2; i <= n; i++){

     d[i] = d[i-1] + d[i-2]; 
   } 

   return d[n];
}