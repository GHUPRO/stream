#include <cmath>
#include <stdio.h>
#include <vector>
using namespace std;
#define G 10
#define distance 1
typedef struct Point
{
	char show;//呈现
	double x, y;//坐标
	double vx, vy;//速度
	double fx, fy;//受力
	double p;//密度
	bool wall;//是否刚体
};
vector<Point> Set(int l,int h)
{
	vector<Point> list;
	int i = 0;
	int j = 0;
	char now;
	while(i < l&&scanf("%c",&now) != EOF)
	{
		if (now == '\n')
			continue;
		if (now != ' ')
		{
			Point ij;
			ij.x = j;
			ij.y = i;
			ij.vx = ij.vy = 0;
			ij.fx = ij.fy = 0;
			if (now != '#')
				ij.wall = false;
			else
				ij.wall = true;
			list.push_back(ij);
		}
		j++;
		if (j == h)
		{
			i++;
			j = 0;
		}
	}
	return list;
}
void ChangeState(vector<Point> &list)
{
	for (auto& p : list)
	{
		if (p.wall)
			continue;
		float r2 = distance * distance;
		float xmin = p.x - r;
		float ymin = p.y - r;
		float xmax = p.x + r;
		float ymax = p.y + r;
		for (auto &apr : list)
		{
			if (&apr != &p && apr.x < xmax && apr.x > xmin && apr.y < ymax && apr.y> ymin)
			{

				float h2 = ((apr.x - p.x) * (apr.x - p.x) + (apr.y - p.y) * (apr.y - p.y));
				float ff = k * (h2 - r2);
				p.fx -= ff;
				p.fy -= ff;
				apr.fx += ff;
				apr.fy += ff;

				float dvx = p.vx - apr.vx;
				float dvy = p.vy - apr.vy;
				float mu = 0.8;
				p.fx += mu * dvx;
				p.fy += mu * dvy;
				apr.fx -= mu * dvx;
				apr.fy -= mu * dvy;
			}
			else
				continue;
		}
		p.vx += p.fx;
		p.vy += p.fy;
		p.x += p.vx;

		p.y += p.vy;

	}
}
int main()
{
	int l;
	int h;
	scanf("%d,%d", &l, &h);
	Point* ph = Set(l,h);
	ChangeState(l, h, ph);
}