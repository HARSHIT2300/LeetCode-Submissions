​
// not much difficult to understand but implementation heavy prob + some tricky edge cases need to be considered  eg  s = "a" , b = "ab*c*k*" should give true
// + intuition is basically started from the fact that if the next character in p is * ,then handle it differently... if ip is equal to len(p)-1 then it needs to be handled differently
// is = current index of s , ip  = current index of p,  ss  = length(s), p = length(p)
​
​