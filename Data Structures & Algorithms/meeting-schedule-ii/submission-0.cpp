/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> minstart;
        priority_queue<int, vector<int>, greater<int>> minend;
        int answer = 0;
        int openrooms = 0;
        for (auto i = intervals.begin(); i != intervals.end(); ++i) {
            minstart.push(i->start);
            minend.push(i->end);
        }
        while (!minstart.empty()) {
            if (minstart.top() < minend.top()) {
                answer = max(answer, ++openrooms);
                minstart.pop();
            } else {
                --openrooms;
                minend.pop();
            }
        }
        return answer;
    }
};