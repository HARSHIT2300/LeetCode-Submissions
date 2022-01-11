class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,vector<string>> adj;
        map<string,int> deg;
        int n = recipes.size();
        for(int i=0;i<n;i++ )
        {   
            for(auto &el : ingredients[i])
            {
                adj[el].push_back(recipes[i]);
                deg[recipes[i]]++;
            }
        }
        queue<string> q;
        for(auto &el : supplies) q.push(el);
        vector<string> ans;
        while(!q.empty())
        {
            string s = q.front();
            q.pop();
            for(auto &el : adj[s])
            {
                deg[el]--;
                if(deg[el] == 0) {q.push(el); ans.push_back(el);} 
            }
        }
        return ans;
    }
};