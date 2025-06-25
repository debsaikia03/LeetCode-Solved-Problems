class Solution {

private:
    bool canEatPiles(const std::vector<int>& piles, int h, int speed){
        int hours = 0;

        for(int i: piles){
            hours += std::ceil(static_cast<double>(i) / speed);
        }

        return hours <= h;
    }


public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int minSpeed = 1;
        
        //get max pile
        int maxSpeed = *max_element(piles.begin(), piles.end());


        while(minSpeed < maxSpeed){
            int mid = minSpeed + (maxSpeed-minSpeed) / 2;

            if(canEatPiles(piles, h, mid)){
                maxSpeed = mid;
            }
            else{
                minSpeed = mid + 1;
            }
        }

        return minSpeed;
    }
    

    
};