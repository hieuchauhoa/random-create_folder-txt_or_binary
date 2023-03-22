#include <cstdlib>
#include<iostream.h>
#include <ctime>
#define maxn 100000
#include<string>
#include <stdio.h>
#include <fstream>
using namespace std;

void hoi(int &loai,int &ten,int &soluong,int &dau,int &cuoi);
void random(int &dau,int &cuoi,int a[maxn],int n);




int main()
{
	int soluong,dau,cuoi,a[maxn];
	FILE *f;
	string loai;
	char ten[50];
	const char *tenfile;
	
	
		//nhap_lieu_file_text
	
	
	cout<<"loai file [1: file text, 2: file binary]:"<<endl;	
	cin>>loai;
	if(loai!="2"&&loai!="1")
	{ 
		cout<<"ERR"<<endl;
		return 0;
	}
	if(loai=="1")
	{	
		cout<<"ten file[ ?.txt ]:"<<endl;
		cin>>ten;
		tenfile=strcat(ten,".txt");
		cout<<endl;
		f=fopen(tenfile,"wt");
		
	
	
	
	
	
	
	
	//nhap_lieu_random
	cout<<"bao nhieu so rand[max="<<maxn<<"]"<<": ";
	cin>>soluong;
	if(soluong>maxn)
		{	
		  cout<<"ERR"<<endl;
		  return 0;  		  
  		}
	cout<<endl;	
	cout<<"so bat dau rand: ";	cin>>dau;	cout<<endl;	
	cout<<"so cuoi cung rand: ";  cin>>cuoi; cout<<endl;
	random(dau,cuoi,a,soluong);
	
	cout<<"hien so luong phan tu?[yes=1, no=0]:"<<endl;
	int hien;
	cin>>hien;
	if(hien!=1&&hien!=0)
	{
		cout<<"ERR"<<endl;
		return 0;
	}
	
	if(hien==1) fprintf(f,"%d\n",soluong);
	
		for(int i=0;i<soluong;i++)
		{
			fprintf(f,"%d ",a[i]);
		}
	cout<<"DONE!!!"<<endl;	
	system("pause");
	}
fclose(f);	


	//file_binary

if(loai=="2")
{
	cout<<"ten file:"<<endl;
	cin>>ten;
	//tenfile=strcat(ten,".txt");
	tenfile=ten;
	cout<<endl;
	fstream p;
	p.open(tenfile,ios::binary|ios::out|ios::trunc);
	
	
	
	//ghi_binary
	
	
	cout<<"bao nhieu so rand[max="<<maxn<<"]"<<": ";
	cin>>soluong;
	if(soluong>maxn)
		{	
		  cout<<"ERR"<<endl;
		  return 0;  		  
  		}
	cout<<endl;	
	cout<<"so bat dau rand: ";	cin>>dau;	cout<<endl;	
	cout<<"so cuoi cung rand: ";  cin>>cuoi; cout<<endl;
	random(dau,cuoi,a,soluong);
	
	cout<<"hien so luong phan tu?[yes=1, no=0]:"<<endl;
	int hien;
	cin>>hien;
	cout<<endl;
	if(hien!=1&&hien!=0)
	{
		cout<<"ERR"<<endl;
		return 0;
	}
	
	if(hien==1) p.write(reinterpret_cast<char *>(&soluong),sizeof(soluong));
	
		for(int i=0;i<soluong;i++)
		{
			p.write(reinterpret_cast<char *>(&a[i]),sizeof(a[i]));
		}
			p.close();
		
	
	cout<<"DONE!!!"<<endl;	
	system("pause");

}





}

void random(int &dau,int &cuoi,int a[maxn],int n)
{
	if(dau>cuoi)
	{
		int t;
		t=cuoi;
		cuoi=dau;
		dau=t;		
	}
	
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{		 
		 a[i] = rand() % (cuoi - dau + 1) + dau;		
	}	
}

