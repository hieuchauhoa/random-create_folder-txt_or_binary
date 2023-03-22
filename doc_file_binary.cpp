	#include <cstdlib>
#include<iostream.h>
#include <ctime>
#include <cstdlib>
#include<iostream.h>
#include <ctime>
#define maxn 100000
#include<string>
#include <stdio.h>
#include <fstream>

using namespace std;
	
	int main()
	{
		
	
	
		//doc_binary
		char ten[50];
		const char *tenfile;
		cout<<"duong dan den file:"<<endl;
		cin>>ten;
		tenfile=ten;
		
		
		
		int b[maxn];
		fstream g;
		g.open(tenfile,ios::binary|ios::in);
		if(!g) {cout<<"file err!!"<<endl;return 0;}
		g.read(reinterpret_cast<char *>(&b[0]),sizeof(b[0]));
			cout<<b[0]<<endl;
		int i=1;
			while(1)
		{
			g.read(reinterpret_cast<char *>(&b[i]),sizeof(b[i]));
			if(g.eof()) break;
			cout<<b[i]<<" ";
			i++;
		}
		cout<<endl;
		g.close();
		
		system("pause");
		
	}