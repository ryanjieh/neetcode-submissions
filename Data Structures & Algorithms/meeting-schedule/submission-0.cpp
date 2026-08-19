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

bool intcomp (Interval a, Interval b) {
    return a.end < b.end;
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), intcomp);
        int end = 0;
        for (auto i = intervals.begin(); i != intervals.end(); i++) {
            if (i->start >= end) {
                end = i->end;
            } else {
                return false;
            }
        }
        return true;
    }
};
