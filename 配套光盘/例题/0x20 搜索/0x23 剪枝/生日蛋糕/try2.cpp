//time:563MS
#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>
#include<map>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int N, M;//分别表示体积和层数
int min_s = 0x7fffffff;//初始化为最大值
inline int min_v(int m)//此函数用于计算搭建剩余蛋糕层所需的最小体积
{
	int v = 0;
	//将剩余层的半径设为最小值，即从最高层到当前的上一层分别为1,2,3,4...M-m
	//每一层高度H取值和R一样,才能保证V最小；
	for (int R = M - m; R >= 1; R--)
	{
		int H = R;
		v += R * R * H;
	}
	return v;
}

inline int max_v(int r, int h, int m)//此函数用于计算搭建剩余蛋糕层所需的最大体积
{
	int v = 0;
	//由于上层半径和高度必须必下层半径和高度小，所以每一层半径和高度的最大取值应是其下层的半径或高度减一
	for (int R = r, H = h; m <= M; R--, H--,m++)
	{
		//只有将剩余的每一层的半径和高度设为最大值，才能保证求得的V最大
		v += R * R * H;
	}
	return v;
}
inline void dfs(int r, int h, int m, int s, int v)//深度优先搜索，其中m表示当前在搭建的层数，s表示已经搭建的蛋糕层的表面积,v表示已经使用的体积
{
	if (m == M && N == v && s < min_s)
	{
		min_s = s;//更新最小表面积的数值
		return;
	}
	//如果预估蛋糕的最小面积大于前面所确立最小面积，则无需继续深索
	if (r == 0 || s + 2 * (N - v) / r > min_s)
		return;

	//如果预估搭建剩余层所需的最小体积大于剩余可用体积，则说明规定的体积不够用，返回
	if (min_v(m) > N - v)//第一种情况
		return;

	//如果预估搭建剩余层所需的最大体积小于剩余可用体积，则说明无法达到规定的体积，返回
	if (max_v(r, h, m) < N - v)//第二种情况
		return;

	//如果上述条件均不满足，则说明满足第三种情况，则继续深索
	for (int R = r - 1; R >= M - m; R--)//枚举下一层蛋糕的半径
		for (int H = h - 1; H >= M - m; H--)//枚举下一层蛋糕的高
		{
		//注意，此时的最小值不是M-m+1,因为对应的是下一层的半径和高，所以最小值应该是M-m
			dfs(R, H, m + 1, s + 2 * R * H, v + R * R * H);//深搜下一层
		}
}
int main()
{
    std::cin >> N >> M;
	for (int r1 = M; r1 * r1 <= N; r1++)//枚举所有可能的半径和高度
		for (int h1 = N / (r1 * r1); h1 >= M; h1--)
		{
			int s = r1 * r1 + r1 * h1 * 2;//表示第一层的表面积
			int v = r1 * r1 * h1;//表示第一层使用的体积
			dfs(r1, h1, 1, s, v);//固定了第一层的半径和高度之后，往上层去探索
		}
	if (min_s == 0x7fffffff)
		cout << 0 << endl;
	else
		cout << min_s << endl;
	return 0;
}
