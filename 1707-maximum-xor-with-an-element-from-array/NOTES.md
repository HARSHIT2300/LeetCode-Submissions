bool cmp(pair<int,pair<int,int>> &v1,pair<int,pair<int,int>> &v2)
{
return (v1.second.first<=v2.second.first);
}
​
This piece of code was the cause of the Runtime Error.
Else Standard implementation of Trie +