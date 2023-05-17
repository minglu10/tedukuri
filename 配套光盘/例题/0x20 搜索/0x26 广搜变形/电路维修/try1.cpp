#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<functional>
#include<cstdlib>
#include<utility> 

using namespace std;

const int cap=500011;
int dist[510][510];    //两点间的最短距离
char map[510][510];    //读图
pair<int,int> q[cap*2]; //队列
int r,c,li,ri;
inline bool valid(int x,int y)  //是否出界 
{
    return x>=0&&x<=r&&y>=0&&y<=c;
}

inline void que_add(int x,int y,int v)  
{
    if(dist[x][y]<0||v<dist[x][y])
    {
        dist[x][y]=v;
        if(li==ri||v>dist[q[li].first][q[li].second])
          q[ri++]=make_pair(x,y);      //make_pair是生成pair类型的数据 注释1
        else  q[--li]=make_pair(x,y);
    }
}

int main()
{
    int kase;
    for(scanf("%d",&kase);kase;--kase)
    {
        scanf("%d %d",&r,&c);
        if((r+c)%2)           //注释2
        {
            for(int i=0;i<r;i++) {
              scanf("%s",map[i]);
            }
            printf("NO SOLUTION\n");
        }
        else
        {
            for(int i=0;i<r;i++)
              scanf("%s",map[i]);
            li=ri=cap;
            q[ri++]=make_pair(0,0);
            memset(dist,-1,sizeof(dist));
            dist[0][0]=0;  //初始化距离无穷大
           while(li!=ri)  //队列非空
            {
                int cx=q[li].first;
                int cy=q[li].second;
                ++li;
                if(valid(cx-1,cy-1))
                {
                    if(map[cx-1][cy-1]=='\\') 
                      que_add(cx-1,cy-1,dist[cx][cy]);
                    else
                      que_add(cx-1,cy-1,dist[cx][cy]+1);
                }
                if(valid(cx-1,cy))
                {
                    if(map[cx-1][cy]=='/') 
                      que_add(cx-1,cy+1,dist[cx][cy]);
                    else
                      que_add(cx-1,cy+1,dist[cx][cy]+1);
                }
                if(valid(cx+1,cy-1))
                {
                    if(map[cx][cy-1]=='/') 
                      que_add(cx+1,cy-1,dist[cx][cy]);
                    else
                      que_add(cx+1,cy-1,dist[cx][cy]+1);
                }
                if(valid(cx+1,cy+1))
                {
                    if(map[cx][cy]=='\\') 
                      que_add(cx+1,cy+1,dist[cx][cy]);
                    else
                      que_add(cx+1,cy+1,dist[cx][cy]+1);  
                }
            }
            printf("%d\n",dist[r][c]);
        }
    }
    return 0;
}