class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count the frequency of each task
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }

        // Step 2: Max heap (priority queue) to always pick the task with the highest frequency
        // We use just the frequencies (int), so priority_queue is sorted in descending order
        priority_queue<int> pq;
        for (auto& it : freq) {
            pq.push(it.second); // Push frequency of each task
        }

        // Step 3: Cooldown queue to manage tasks that are waiting for the cooldown time to finish
        // Each element is a pair: {next_available_time, remaining_frequency}
        queue<pair<int, int>> cooldown;

        // Step 4: Time counter - represents total time units taken to complete all tasks
        int time = 0;

        // Continue while there are tasks to process in the heap or waiting in cooldown
        while (!pq.empty() || !cooldown.empty()) {
            time++; // Move to next time unit

            // Step 5: If a task's cooldown has ended (i.e., it's ready to be scheduled again)
            if (!cooldown.empty() && cooldown.front().first == time) {
                // Push it back to the heap to be scheduled again
                pq.push(cooldown.front().second);
                cooldown.pop();
            }

            // Step 6: If there are tasks in the heap that can be scheduled
            if (!pq.empty()) {
                int currentFreq = pq.top(); // Get the task with highest frequency
                pq.pop();

                // If more instances of this task are left, put it in cooldown
                if (currentFreq > 1) {
                    // Cooldown ends at time + n + 1, because `n` is the cooldown *between* same tasks
                    cooldown.push({time + n + 1, currentFreq - 1});
                }
            }
            // If no task is available in the heap, we just idle this time unit
        }

        // Step 7: Total time taken includes actual task execution and idle times
        return time;
    }
};
