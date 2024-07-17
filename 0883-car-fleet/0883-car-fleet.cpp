class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size(); // n -> no. of cars

        stack<float> st;  //initialize stack
        vector<pair<int,float>> vec;  //pair storing position & time to reach
         
        for(int i=0; i<n; i++){
            vec.push_back({position[i] , float(target-position[i])/speed[i]}); //stores the position and time
        }

        sort(vec.begin() , vec.end()); //sorts the vector by first element

        for(auto it:vec){ //auto increment vector

            float time = it.second; //stores the time to which the iteratir currently points at

            while(st.size() && (time >= st.top())) st.pop(); //st.size-> ensures that the stack is not empty //if top element is less than current time it is pushed //if top element greater than or equal to current time it is being popped and current time is pushed 

        st.push(time); 
        }

        return st.size();
    }
};