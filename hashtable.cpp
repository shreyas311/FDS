#include<iostream>    
#define MAX 10  
#define SIZE 10  
#define FALSE 0  
#define TRUE 1  
using namespace std;   
struct hashtable  
{    
   int chain;  
   long int key;  
   string name;  
}s[MAX];  
class hasht 
{    
 	public:    
 	    int hash(int regno); 
};
int hasht::hash(int regno)  
{    
	int h;  
	h=regno % MAX;    
	return h;
} 
int main() 
 {    
	int i,flag1=0,a,no1,h,c,index,j;         
	string sname;  
    hasht t;    
	for(i=0;i<MAX;i++)
	{       
		s[i].key=-1;    
	    s[i].chain=-1;   
	    s[i].name='-';    
	}   
	do 
	{ 
		for(j=0;j<MAX;j++) 
		{  
			if(s[j].key==-1)                             	
			break;
		}  
		if(j==MAX) 
		{			                   
   		  	cout<<"\nHash Table is full: "<<endl;  
			break;   
		}                  
	    cout<<"\nEnter the registerNo NUmber : ";         
		cin>>no1;                     
		cout<<"Enter the name:";                     
		cin>>sname;       
        h=t.hash(no1);              
        c=-1;                    
		index=h;            	
		do{          
        	if(s[h].key==-1) 
            {       
                flag1=1;  
                s[h].key=no1;         
   		        s[h].name=sname;                 
				if(c!=-1)                 
              		s[c].chain=h;                   
	        }                       
   			else if(t.hash(s[h].key)==index)              
           		c=h;                       
   				h=t.hash(h+1);   
            }while(flag1==0 && h<MAX);      
		flag1=0; 
		cout<<"------------------------------";  
		cout<<"\nIndex"<<"\t"<<"Key"<<"\t\t"<<"Name"<<"\t\t"<<"chain"<<"\n";                 
		for(i=0;i<MAX;i++)  
			cout<<i<<"\t"<<s[i].key<<"\t\t"<<s[i].name<<"\t\t"<<s[i].chain<<"\n";			 					
		cout<<"-----------------------------"; 
	    cout<<"\n Do you want to continue Press(0/1): ";                  
		cin>>a;     
	            
	}while(a==1);           
return 0;
}

