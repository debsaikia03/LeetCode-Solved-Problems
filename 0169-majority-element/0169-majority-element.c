int majorityElement(int* nums, int numsSize) {
    
    int el;
    int cnt = 0;

    for(int i=0; i<numsSize; i++){

        if(cnt == 0){

            el = nums[i];
            cnt++;
        }

        else if (nums[i] == el){

            cnt++;
        }

        else{

            cnt--;
        }
    }

    return el;
}