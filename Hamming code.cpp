#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int m,r=1,i,j,one;
    cout<<"Enter the number of bits ( should not be greater than 11 ) in data";
    cin>>m;
    while(1)                         // for calculation of value of r
    {
        if((pow(2,r))>=(m+r+1))
            break;
        r++;
    }
    int bt[m+r],dt[m+r],t=0;
    cout<<"Enter "<<m<<" bit long data";
        for(i=0;i<m;i++)
            cin>>bt[i];
    for(i=0;t<m+r;i++)                         // reserve the redundant bit space with special symbol '8'
    {
        t=pow(2,i);
        dt[m+r-t]=8;
    }
    for(i=0,j=0;i<m+r;i++)                    // to fill data in array and redundant bit space with special symbol '8'
    {
        if(dt[i]!=8)
        {
            dt[i]=bt[j];
            j++;
        }
    }
    for(i=0,one=0;i<m+r;i+=2)                 // for the calculation of first redundat bit (r1)
    {
        if(dt[i]==1)
            one++;
    }
    if(one%2==1)
        dt[m+r-1]=1;
    else
     dt[m+r-1]=0;
     for(i=1,one=0;i<m+r;i+=3)          //Check 1.2 5.6 9.10  //  for the calculation of second redundat bit (r2)                         
    {
        if(dt[i]==1)
            one++;
        i++;
        if(dt[i]==1)
            one++;
    }
    if(one%2==1)
        dt[m+r-2]=1;
    else
     dt[m+r-2]=0;
     for(i=3,one=0;i<m+r;i+=5)          //Check 3.4.5.6  // for the calculation of third redundat bit (r4)                           
    {
        for(int j=0;j<4;j++)
        {
            if(i<m+r)
            {
                if(dt[i]==1)
                    one++;
                i++;
            }
        }
    }
    if(one%2==1)
        dt[m+r-4]=1;
    else
     dt[m+r-4]=0;
     for(i=7,one=0;i<m+r;i+=9)          //Check 7.8.9.10.11.12.13.14  // for the calculation of fourth redundat bit (r8)                        
    {
        for(int j=0;j<8;j++)
        {
            if(i<m+r)
            {
                if(dt[i]==1)
                    one++;
                i++;
            }
        }
    }
    if(one%2==1)
        dt[m+r-8]=1;
    else
        dt[m+r-8]=0;
    cout<<"Hamming code :";
    for(i=0;i<m+r;i++)
        cout<<dt[i]<<"  ";
    return 0;    
}