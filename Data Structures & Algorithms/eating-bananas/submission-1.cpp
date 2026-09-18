class Solution {
public:
    int minEatingSpeed(const vector<int>& piles, int h) {
        int left = 1, right = *std::max_element( piles.begin(), piles.end() );
        while ( left < right ) { 
            int mid = left + ( right - left ) / 2;
            long long cur_time = 0;
            for ( int n : piles ) {
                cur_time += ( n + mid - 1 ) / mid;
                if ( cur_time > h ) break;
            }
            if ( cur_time > h ) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
