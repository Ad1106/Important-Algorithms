#include<iostream>
using namespace std;
int main()
{
	cout<<endl<<endl<<"SENDER SIDE"<<endl<<endl;
    int m,n,p,i,t,j,z,zeros=0;;
    cout<<"Enter the number of bits in data";
    cin>>m;
    cout<<"Enter the number of bits in divisior";
    cin>>n;
    p=m+n-1;
    int bt[p],dv[n],dt[p],f[n];
    for(i=0;i<p;i++)
        dt[i]=0;
    cout<<"Enter "<<m<<" bit long data";
    for(i=0;i<m;i++)
    {
        cin>>bt[i];
        dt[i]=bt[i];
    }
    cout<<"Enter "<<n<<" bit long divisior";
    for(i=0;i<n;i++)
        cin>>dv[i];
    for(i=0;i<m;i++)
    {
        t=i;
        if (dt[i]==1)
        {
            for(j=0;j<n;j++)
            {
                if(dt[t]==dv[j])
                {
                    dt[t]=0;
                    f[j]=0;
                }
                else 
                {
                    dt[t]=1;
                    f[j]=1;
                }
                t++;
            }
        }
    }
	cout<<"Our reminder or we can say CRC is : ";
    for(i=0;i<n;i++)
        cout<<f[i]<<"  ";
        //////////////////////////   Reciever Side ///////////////////////////////
    for(i=m,z=0;i<p;i++)
    dt[m]=f[z++];
    
     for(i=0;i<m;i++)
    {
        t=i;
        if (dt[i]==1)
        {
            for(j=0;j<n;j++)
            {
                if(dt[t]==dv[j])
                {
                    dt[t]=0;
                    f[j]=0;
                }
                else 
                {
                    dt[t]=1;
                    f[j]=1;
                }
                t++;
            }
        }
    }
    cout<<endl<<endl<<"RECIEVER SIDE Checking"<<endl;
    //cout<<"Our reminder or we can say CRC is : ";
    for(i=0;i<n;i++)
    {
    	//cout<<f[i];
    	if(dt[i]==0)
    	zeros++;
	}
		
       if(zeros==n)
       cout<<endl<<"Error not present in transmission";
       else
       cout<<endl<<"Error present in transmission";
	   return 0;
}
    
    

