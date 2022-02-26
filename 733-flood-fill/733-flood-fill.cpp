class Solution {
public:
    bool vis[51][51];
    int ch[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int x,int y,int &newColor,vector<vector<int>> &image)
    {
        if(vis[x][y]) return;
        vis[x][y]=true;
        for(int i=0;i<4;i++)
        {
            int chx = ch[i][0]+x,chy = ch[i][1]+y;
            if(0<=chx&&chx<image.size()&&chy>=0&&chy<image[0].size()&&image[chx][chy] == image[x][y])
            {
                dfs(chx,chy,newColor,image);
            }
        }
        image[x][y]=newColor;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        memset(vis,false,sizeof(vis));
        dfs(sr,sc,newColor,image);
        return image;
    }
};