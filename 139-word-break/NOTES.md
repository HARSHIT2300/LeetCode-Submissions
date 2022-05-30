In this problem, I faced a problem as I realted it to a knapsack problem but the optimal valid solution is a linear dp... and is quite simple to understand
So dp[i] is a state that tells  us whether or  not it is possible to have a valid word from i to N
how to check that look at the outer loop from each i we traverse from i -> N in the inner loop and check for each particular word if it exists in dictionary and the word starting from next j should also be valid.
Now dp[n+1] is 1 bcoz any word if ending at j=N is valid then dp[j+1] a.k.a dp[N+1] has to be valid dp[N+1] has to be valid
Also if u want to replace this with a more intuitive way, u can explicitly treat the case of any word found existing in  dictionary and ending at j=N to be valid.(2nd Solution)