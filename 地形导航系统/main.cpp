#include<iostream>
#include<Windows.h>
#include<fstream>
#include<string>
#include<assert.h>

using namespace std;

#define MAXROWS 128
#define MAXCOLS 128

bool isPeak(int map[][MAXCOLS],int r,int c);
bool isValley(int map[][MAXCOLS],int r,int c);
void extremes(int map[][MAXCOLS],int r,int c);

int main(){
	int rows,cols;  //rows:行数 cols:列数
	string fileName;
	ifstream file;
	int map[MAXROWS][MAXCOLS];
	int count=0;

	cout<<"请输入文件名:";
	cin>>fileName;

	file.open(fileName.c_str());

	if(file.fail()){
		cout<<"文件打开失败!"<<endl;
		exit(1);  //直接让程序异常退出
	}

	file>>rows>>cols;

	if(rows>MAXROWS||cols>MAXCOLS){
		cout<<"二维数组太大"<<endl;
		exit(1);
	}

	//从文件读取二维数组
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			file>>map[i][j];
		}
	}

	//打印地图
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}

	//寻找峰值
	/*
	方法一:
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(i==0||i==rows-1){//不考虑最外围一圈
				continue;
			}else if(j==0||j==cols-1){
				continue;
			}else if(isPeak(map,i,j)){
				cout<<map[i][j];
			}
		}
	}
	*/
	//方法二:下标直接从1开始,循环条件不执行判断二维数组的最外围
	for(int i=1;i<rows-1;i++){
		for(int j=1;j<cols-1;j++){
			if(isPeak(map,i,j)){
				count++;
				cout<<"该地形峰值在:"<<"map["<<i<<"],["<<j<<"]"<<"峰值为:"<<map[i][j]<<endl;
			}
		}
	}
	cout<<"该地形一共有"<<count<<"个峰点"<<endl;
	
	//清0计数器
	count=0;

	for(int i=1;i<rows-1;i++){
		for(int j=1;j<cols-1;j++){
			if(isValley(map,i,j)){
				count++;
				cout<<"该地形谷点在:"<<"map["<<i<<"],["<<j<<"]"<<"峰值为:"<<map[i][j]<<endl;
			}
		}
	}
	cout<<"该地形一共有"<<count<<"个谷点"<<endl;

	extremes(map,rows,cols);

	//关闭文件
	file.close();
	system("pause");
	return 0;
}

bool isPeak(int map[][MAXCOLS],int r,int c){
	assert(r>0);
	assert(c>0);

	if(map[r][c]>map[r-1][c]&&map[r][c]>map[r+1][c]&&map[r][c]>map[r][c-1]&&map[r][c]>map[r][c+1]
		&&map[r][c]>map[r-1][c-1]&&map[r][c]>map[r-1][c+1]&&map[r][c]>map[r+1][c-1]&&map[r][c]>map[r+1][c+1]){
			return true;
	}
	return false;
}

bool isValley(int map[][MAXCOLS],int r,int c){
	assert(r>0);
	assert(c>0);

	if(map[r][c]<map[r-1][c]&&map[r][c]<map[r+1][c]&&map[r][c]<map[r][c-1]&&map[r][c]<map[r][c+1]
		&&map[r][c]<map[r-1][c-1]&&map[r][c]<map[r-1][c+1]&&map[r][c]<map[r+1][c-1]&&map[r][c]<map[r+1][c+1]){
			return true;
	}else{
		return false;
	}
} 

void extremes(int map[][MAXCOLS],int r,int c){
	int max=map[0][0];
	int min=map[0][0];
	int i1,j1,i2,j2;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(map[i][j]>max){
				max=map[i][j];
				i1=i;
				j1=j;
			}else if(map[i][j]<min){
				min=map[i][j];
				i2=i;
				j2=j;
			}
		}
	}

	cout<<"该地形的最高点是map["<<i1<<"]"<<"["<<j1<<"]"<<":"<<max<<endl;
	cout<<"该地形的最低点是map["<<i2<<"]"<<"["<<j2<<"]"<<":"<<min<<endl;
}