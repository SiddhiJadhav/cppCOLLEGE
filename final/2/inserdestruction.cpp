//operator overloading insertion and extraction
#include<iostream>
using namespace std;
const int size=3;

class vector{
		int v[size];
	public:
		vector();
		vector(int *);
		friend vector operator*(int a,vector b);
		friend vector operator*(vector b,int a);
		friend istream &operator>>(istream &,vector &);
		friend ostream &operator<<(ostream &,vector &);
};

vector::vector(){
for(int i=0;i<size;i++)
	v[i]=0;
}

vector::vector(int *x){
for(int i=0;i<size;i++)
	v[i]=x[i];
}

vector operator*(int a,vector b){
vector c;
for(int i=0;i<size;i++)
	c.v[i]=a*b.v[i];
return c;
}

vector operator*(vector b,int a){
vector c;
for(int i=0;i<size;i++)
	c.v[i]=a*b.v[i];
return c;
}

istream &operator>>(istream &din,vector &b){
for(int i=0;i<size;i++)
	din>>b.v[i];
return din;
}

ostream &operator<<(ostream &dout,vector &b){
dout<<"("<<b.v[0];
for(int i=1;i<size;i++)
	dout<<","<<b.v[i];
dout<<")";
return dout;
}

int x[size]={2,4,6};

int main(){
vector m;
vector n=x;
cout<<"\nEnter the elements of vector m:"<<m<<endl;
cin>>m;
cout<<endl;
cout<<"m="<<m<<endl;
vector p,q;
p=2*m;
q=m*2;
cout<<"\np="<<p<<endl;
cout<<"\nq="<<q<<endl;
}
/*
o/p:-
Enter the elements of vector m:(0,0,0)
1
1
1

m=(1,1,1)

p=(2,2,2)

q=(2,2,2)

*/
