#include <cmath>
#include <stdio.h>
#define G 10
typedef struct Point
{
	char show;//呈现
	double x, y;//坐标
	double vx, vy;//速度
	double fx, fy;//受力
	double p;//密度
	bool wall;//是否刚体
};
Point* Set(int l,int h)
{
	static Point* ph = new Point[l];
	for (int i = 0,int j = 0;j < h;)
	{
		scanf("%c", (ph + j)[i].show);
		if ((ph + j)[i].show == '#')
			(ph + j)[i].wall = true;
		(ph + j)[i].x = i + 1;
		(ph + j)[i].y = j + 1;
		(ph + j)[i].vx = 0;
		(ph + j)[i].vy = 0;
		(ph + j)[i].fx = 0;
		(ph + j)[i].fy = G;//赋值重力
		if (!(ph + j)[i].show == ' ')
			(ph + j)[i].p = 0;
		else
			(ph + j)[i].p = 1;
		i++;
		if (i = l)
		{
			i = 0;
			j++;
		}
	}
	return ph;
}
void ChangeState(int l,int h,Point *ph)
{
	for (int i = 0, int j = 0; j < h;)
	{
		/*
		change f
		change v
		change xy
		change p
		*/
		i++;
		if (i = l)
		{
			i = 0;
			j++;
		}
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