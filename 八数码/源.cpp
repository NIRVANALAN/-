#include<iostream>
#include<queue>
#include<map>

using namespace std;

queue<int> q;
map<int, int> step;
map<int, int> used;
map<int, int> proc;
auto time = 0;
auto upper = 0;
auto init_state = 0;
auto dst = 123456780;
auto diff_count = 9;
void init();
int bfs();
bool check_can_move(int u, int i);
int move(int u, int i);
auto v = 0;
int tx[4] = {0, 1, 0, -1};
int ty[4] = {1, 0, -1, 0};

int main()
{
	// 1 0 3 4 2 6 7 5 8
	init();
	cout << "upper: " << upper << endl;
	cout << bfs() << endl;
	cout << "moving times: " << time << endl;
	// auto t = proc[dst];
	while (true)
	{
		cout << init_state;
		init_state = proc[init_state];
		if(init_state==0)
			break;
		else
		{
			cout << "-";
		}
	}
	cout << endl;
	// used[0] = 1;
	// cout << used[0];
	system("pause");
	return 0;
}

void init()
{
	int tmp;
	cin >> tmp;
	auto num = tmp;
	for (auto i = 0; i < 8; i++)
	{
		cin >> tmp;
		num = num * 10 + tmp;
	}
	auto tmp1 = num;
	init_state = num;
	auto tmp2 = dst;
	for (auto i = 0; i < 9; ++i)
	{
		tmp = tmp1 % 10;
		if (tmp != tmp2 % 10)
		{
			upper++;
		}
		tmp1 /= 10;
		tmp2 /= 10;
	}
	step.clear();
	used.clear();
	q.push(num);
	step[num] = 0;
	used[num] = 1;
}

int bfs()
{
	int i;
	int u;
	u = q.front();
	if (u == 123456780)
	{
		return 0;
	}
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			time++;
			// move in 4 positions
			if (check_can_move(u, i))
			{
				// auto v = move(u, i);
				proc[u] = v;
				if (v == 123456780)
				{
					return (step[u] + 1);
				}
				if (used.count(v) == 0)
				{
					q.push(v);
					step[v] = step[u] + 1;
					used[v] = 1;
				}
			}
		}
	}
	return -1;
}

bool check_can_move(int u, int i)
{
	int arr[3][3];
	int j, k;
	int row, col;
	int vx, vy;
	for (j = 2; j >= 0; j--)
	{
		for (k = 2; k >= 0; k--)
		{
			arr[j][k] = u % 10;
			u = u / 10;
			if (arr[j][k] == 0)
			{
				row = j;
				col = k;
			}
		}
	}
	vx = row + tx[i];
	vy = col + ty[i];
	if (vx >= 0 && vx < 3 && vy >= 0 && vy < 3)
	{
		arr[row][col] = arr[vx][vy];
		arr[vx][vy] = 0;
		// int num = 0;
		v = 0;
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				v = v * 10 + arr[j][k];
			}
		}
		auto tmp1 = v;
		auto tmp2 = dst;
		auto tmp = 0;
		auto dif = 0;
		for (auto i1 = 0; i1 < 9; ++i1)
		{
			tmp = tmp1 % 10;
			auto tt = tmp2 % 10;
			if (tmp != tt)
			{
				dif++;
				if (dif > upper)
				{
					arr[vx][vy] = arr[row][col];
					arr[row][col] = 0;
					return false;
				}
			}
			tmp1 /= 10;
			tmp2 /= 10;
		}
		// cout << "dif" << dif << endl;
		if (dif < diff_count)
		{
			diff_count = dif;
			return true;
		}
		// return true;
	}
	return false;
}

int move(int u, int i)
{
	int arr[3][3];
	int j, k;
	int row, col;
	int vx, vy;
	int num;
	for (j = 2; j >= 0; j--)
	{
		for (k = 2; k >= 0; k--)
		{
			arr[j][k] = u % 10;
			u = u / 10;
			if (arr[j][k] == 0)
			{
				row = j;
				col = k;
			}
		}
	}
	vx = row + tx[i];
	vy = col + ty[i];
	arr[row][col] = arr[vx][vy];
	arr[vx][vy] = 0;
	num = 0;
	for (j = 0; j < 3; j++)
	{
		for (k = 0; k < 3; k++)
		{
			num = num * 10 + arr[j][k];
		}
	}
	return num;
}
