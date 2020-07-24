#include<iostream>
#include<cstring>
#include<vector>
#define BLACK 178
#define WHITE 176
#define QUEEN 86
using namespace std;
class Point2D;
std::vector<Point2D> Chess_Points;
std::vector<Point2D*> U_V_Points;
class Point2D
{
	public:
		Point2D(int x,int y)
		{
			this->x = x;
			this->y = y;
		}
		Point2D(){};
		int getX();
		void setX(int);
		int getY();
		void setY(int);
	private:
		int x,y;
};
void Point2D::setX(int x)
{
	this->x = x;
}
void Point2D::setY(int y)
{
	this->y = y;
}
int Point2D::getX()
{
	return this->x;
}
int Point2D::getY()
{
	return this->y;
}



int DrawChessBoard(int size)
{
	int flat;
	for(int row = 0;row<size;row++)
	{
		for(int col=0;col<size;col++)
		{
			flat = row*size+col;
			if(flat%2 == 0)
				cout<<(char)WHITE<<"  ";
			
			else if(flat%2 == 1)
				cout<<(char)BLACK<<"  ";
		}
		cout<<endl;
		cout<<endl;
	}
}
int DrawChessBoard(int size,int** arr)
{
	int flat;
	for(int row = 0;row<size;row++)
	{
		for(int col=0;col<size;col++)
		{
			flat = row*size+col;
			if(arr[row][col] == 8)
				cout<<(char)QUEEN<<"  ";
			else
			{
				if(flat%2 == 0)
					cout<<(char)WHITE<<"  ";
			
				else if(flat%2 == 1)
					cout<<(char)BLACK<<"  ";
			}	
		}
		cout<<endl;
		cout<<endl;
	}
	
}
bool Put_Quenn(Point2D dot)
{
	Point2D* obj_diagonal = new Point2D();
	obj_diagonal->setX(dot.getX()-dot.getY());//u kosegen
	obj_diagonal->setY(dot.getX()+dot.getY());//v kosegen
	if(Chess_Points.empty())
	{
		Chess_Points.push_back(dot);
		U_V_Points.push_back(obj_diagonal);
	}
	
	else
	{
		for(int i=0;i<Chess_Points.size();i++)
		{
			if(Chess_Points[i].getX() == dot.getX())
			{
				delete obj_diagonal;
				return false;
			}
			else if(Chess_Points[i].getY() == dot.getY())
			{
				delete obj_diagonal;
				return false;
			}
			
		}
		for(int j=0;j<U_V_Points.size();j++)
		{
			if(U_V_Points[j]->getX() == dot.getX() - dot.getY() || U_V_Points[j]->getY() == dot.getX() + dot.getY())
			{
				delete obj_diagonal;
				return false;
			}
		}
		Chess_Points.push_back(dot);
		U_V_Points.push_back(obj_diagonal);
		return true;	
	}
	
}
int main(void)
{

	int in,flat,x,y,tpin;
	cout<<"boyut giriniz"<<endl;
	cin>>in;
	tpin = in;
	int **chess_table = new int*[in];
	for(int i=0;i<in;i++)
	{
		chess_table[i] = new int[in];
	}
	for(int row = 0;row<in;row++)
	{
		for(int col=0;col<in;col++)
		{
			chess_table[row][col] = 0;
		}
	}
	//DrawChessBoard(in);
	while(tpin > 0)
	{
		cout<<"Kalan Vezir -> "<<tpin<<endl;
		cout<<"Vezir'in X koordinatini giriniz:"<<endl;
		cin>>x;
		cout<<"Vezir'in Y koordinatini giriniz"<<endl;
		cin>>y;
		Point2D point1;
		point1.setX(x);
		point1.setY(y);
		if(Put_Quenn(point1))
		{
			chess_table[point1.getX()-1][point1.getY()-1] = 8; 	
			tpin--;
		}
		else
		{
			cout<<"Bu noktaya vezir koyulamaz"<<endl;
		}
	}
	DrawChessBoard(in,chess_table);
		
	
	return 0;
}
