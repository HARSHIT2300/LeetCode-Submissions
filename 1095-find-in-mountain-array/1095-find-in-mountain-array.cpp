/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
       int l = 1,r=n-2;
        int p_el;
        while(l <= r)
        {
            int mid = l + ((r-l)>>1);
            int m_el = mountainArr.get(mid);
            int r_el = mountainArr.get(mid+1);
            int l_el = mountainArr.get(mid-1);
            if(m_el > r_el && m_el > l_el)
            {
                p_el = mid; break;
            }
            else if(r_el > m_el) l = mid+1;  // peak element is to the right bcoz of the fact array is mountain array
            else r = mid-1;   // peak element is to the left bcoz of the fact that array is mountain array
            
        }
        cout<<p_el<<" ";
        int ans = -1;
        l = 0,r = p_el;
        while(l<=r)
        {
             int mid = l + ((r-l)>>1);
             int m_el = mountainArr.get(mid);
            if(m_el == target)
            {
                ans = mid;
                r = mid-1;
            }
            else if(m_el < target)
            {
                l = mid+1;
            }
            else r = mid-1;
        }
        cout<<ans<<" ";
        if(ans !=-1) return ans;
        l = p_el+1,r = n-1;
         while(l<=r)
        {
             int mid = l + ((r-l)>>1);
             int m_el = mountainArr.get(mid);
            if(m_el == target)
            {
                ans = mid;
                r = mid-1;
            }
            else if(m_el < target)
            {
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};