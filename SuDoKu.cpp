#include<bits/stdc++.h>
using namespace std;

int n;

bool checkArray(int a[100][100],int& row, int& col)
{
	for(row=0;row<n;row++)
	{
		for(col=0;col<n;col++)
		{
			if(a[row][col]==0) return false;//chua dien xong
		}
	}
	return true;
}

bool safe(int a[100][100], int row, int col, int num)
{
	//kiem tra tren dong
	for(int i=0;i<n;i++)
	{
		if(a[row][i]==num) return false;
	}
	//kiem tra tren cot
	for(int j=0;j<n;j++)
	{
		if(a[j][col]==num) return false;
	}
	//kiem tra trong o vuong
	int startRow = row - row%3;
	int startCol = col - col%3;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i+startRow][j+startCol]==num) return false;
		}
	}
	return true;
}
bool BackTrackingSUDOKU(int a[100][100])
{
	int row,col;
	//Kiem tra xem tat ca da duoc dien chua
	if(checkArray(a,row,col))
	{
       return true;
	}
	
	//dien so
	for(int num=1; num<=9; num++)
	{
		//Kiem tra xem so do co thoa man dieu kien chua
		if(safe(a,row,col,num))
		{
			a[row][col]=num;
			if(BackTrackingSUDOKU(a)) return true;
			a[row][col]=0;
		}
	}
	return false;
}
int main()
{
	n=9;
	int a[100][100];
	for(int i=0;i<n;i++)
	{
		cout << "Nhap hang " <<i+1<< " :" ;
		for(int j=0;j<n;j++)
		{
			cin >> a[i][j];
		}
	}
	if(BackTrackingSUDOKU(a)==true) 
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	else{
		cout << "Khong co loi giai!" << endl;
	}
}
