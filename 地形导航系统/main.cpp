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
	int rows,cols;  //rows:���� cols:����
	string fileName;
	ifstream file;
	int map[MAXROWS][MAXCOLS];
	int count=0;

	cout<<"�������ļ���:";
	cin>>fileName;

	file.open(fileName.c_str());

	if(file.fail()){
		cout<<"�ļ���ʧ��!"<<endl;
		exit(1);  //ֱ���ó����쳣�˳�
	}

	file>>rows>>cols;

	if(rows>MAXROWS||cols>MAXCOLS){
		cout<<"��ά����̫��"<<endl;
		exit(1);
	}

	//���ļ���ȡ��ά����
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			file>>map[i][j];
		}
	}

	//��ӡ��ͼ
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}

	//Ѱ�ҷ�ֵ
	/*
	����һ:
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(i==0||i==rows-1){//����������ΧһȦ
				continue;
			}else if(j==0||j==cols-1){
				continue;
			}else if(isPeak(map,i,j)){
				cout<<map[i][j];
			}
		}
	}
	*/
	//������:�±�ֱ�Ӵ�1��ʼ,ѭ��������ִ���ж϶�ά���������Χ
	for(int i=1;i<rows-1;i++){
		for(int j=1;j<cols-1;j++){
			if(isPeak(map,i,j)){
				count++;
				cout<<"�õ��η�ֵ��:"<<"map["<<i<<"],["<<j<<"]"<<"��ֵΪ:"<<map[i][j]<<endl;
			}
		}
	}
	cout<<"�õ���һ����"<<count<<"�����"<<endl;
	
	//��0������
	count=0;

	for(int i=1;i<rows-1;i++){
		for(int j=1;j<cols-1;j++){
			if(isValley(map,i,j)){
				count++;
				cout<<"�õ��ιȵ���:"<<"map["<<i<<"],["<<j<<"]"<<"��ֵΪ:"<<map[i][j]<<endl;
			}
		}
	}
	cout<<"�õ���һ����"<<count<<"���ȵ�"<<endl;

	extremes(map,rows,cols);

	//�ر��ļ�
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

	cout<<"�õ��ε���ߵ���map["<<i1<<"]"<<"["<<j1<<"]"<<":"<<max<<endl;
	cout<<"�õ��ε���͵���map["<<i2<<"]"<<"["<<j2<<"]"<<":"<<min<<endl;
}