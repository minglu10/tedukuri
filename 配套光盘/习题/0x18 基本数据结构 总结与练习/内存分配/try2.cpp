#include<iostream>
#include<queue>
#include<set>
#include<vector>
using namespace std;

typedef pair<int, int> PII;
queue<PII> waits;       // (first: 内存长度，second: 占用时间)
set<PII> runs;        // (first: 起始下标，sercond：长度)
priority_queue<PII,vector<PII>, greater<PII> > endts;       // (first: 释放时间，second: 起始下标)
int tm, cnt;

bool give(int t, int m, int p)
{
    for (set<PII>::iterator it = runs.begin(); it != runs.end(); it ++ )
    {
        set<PII>::iterator jt = it;
        jt ++ ;
        if (jt != runs.end())
        {
            if (m <= jt->first - (it->first + it->second - 1) - 1)
            {
                int start = it->first + it->second;
                runs.insert((PII){start, m});
                endts.push((PII){t + p, start});
                return true;
            }
        }
    }
    return false;
}

void finish(int t)
{
    while (endts.size() && endts.top().first <= t)
    {
        int f = endts.top().first;
        while (endts.size() && endts.top().first == f)
        {
            PII top = endts.top();
            endts.pop();
            set<PII>::iterator it = runs.lower_bound((PII){top.second, 0});
            runs.erase(it);
        }

        tm = f;
        while (waits.size())
        {
            PII front = waits.front();
            if (give(f, front.first, front.second))
            {
                waits.pop();
            }
            else break;
        }
    }
}

int main()
{
    int n;cin >> n;
    runs.insert((PII){-1, 1}), runs.insert((PII){n, 1});
    int t, m, p;
    while (cin >> t >> m >> p, t || m || p)
    {
        finish(t);
        if (!give(t, m, p))
        {
            waits.push((PII){m, p});
            cnt ++ ;
        }
    }
    finish(2e9);

    cout << tm << endl << cnt << endl;
    return 0;
}
