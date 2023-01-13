  #include<iostream>
using namespace std;
int H[10];
int size=-1;
int parent(int i)
{
	return (i-1)/2;
}
int leftchild(int i)
{
	return ((2*i)+1);
}
int rightchild(int i)
{
	return ((i*2)+2);
}
void shiftup (int i)
{
	while(i>0 && H[parent(i)]<H[i])
	{
		swap(H[parent(i)],H[i]);
		i=parent(i);
	}
}
void shiftdown(int i)
{
	int maxindex=i;
	int l=leftchild(i);
	if(l<=size && H[l]>H[maxindex])
	{
		maxindex=l;
	}
	int r=rightchild(i);
	if(r <=size && H[r] > H[maxindex])
	{
		maxindex=r;
	}
	if(i!=maxindex)
	{
		swap(H[i],H[maxindex]);
		shiftdown(maxindex);
	}
}
void insert(int p)
{
	size=size+1;
	H[size]=p;
	shiftup(size);
}
int extractmax()
{
	int result =H[0];
	H[0]=H[size];
	size=size-1;
	return result;
}
void changepriority(int i,int p)
{
	int oldp=H[i];
	H[i]=p;
	if(p>oldp)
		shiftup(i);
	else
		shiftdown(i);	
}
int getmax()
{
	return H[0];
}
void remove(int i)
{
	H[i]=getmax()+1;
	shiftup(i);
	extractmax();
}
int main()
{
	insert(45);
	insert(20);
	insert(14);
	insert(12);
	insert(31);
	insert(7);
	insert(11);
	insert(13);
	insert(7);
int i=0;
cout<<"Priority que"<<endl;
while(i<=size)
{
	cout<<H[i]<<" ";
	i++;
}
cout<<"\n";
cout<<"node with max priority:: "<<extractmax()<<"\n";
cout<<"Priority queue after extracting max::";
int j;
for(j=0;j<size;j++)
{
	cout<<H[j]<<" ";
	
}
cout<<"\n";
changepriority(2,49);
cout<<"Priority queue after priority change::";
int k=0;
while(k<=size)
{
	cout<<H[k]<<" ";
	k++;
}
cout<<"\n";
remove(3);
cout<<"Priority queue after removing element::";
int l=0;
while(l<=size)
{
	cout<<H[l]<<" ";
	l++;
}
return 0;
}
