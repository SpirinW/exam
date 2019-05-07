#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
  ifstream file("input.txt");
  int n;
  cin>>n;
  vector <vector <double> > a(n, vector <double> (n));
  vector <vector <double> > ed(n, vector <double> (n));
  for (int i = 0; i < n; ++i)
  {
    for(int j = 0; j < n; ++j)
      ed[i][j]=(i==j);
  }
  for (int i = 0; i < n; ++i)
    {
      for (int j =0; j < n; ++j)
          file>>a[i][j];
    }
  cout<<"Your martix:\n";
  for (int i = 0; i < n; ++i)
  {
    for(int j = 0; j < n; ++j)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }
  for (int k = 0; k < n; ++k)
  {
  	for (int i = k+1 ; i < n; ++i )
      {
        if(a[k][k])
          {
            double m = a[i][k]/a[k][k];
            for (int j = k ; j < n+1 ; ++j)
                {
                  a[i][j]-=m*a[k][j];
                  ed[i][j]-=m*ed[k][j];
                }
          }
      }
  }
  int det=1;
  for(int i = 0; i < n; i++)
    det*=a[i][i];
  cout<<"Det = "<<det<<endl;
  if(det)
  {
    for(int k = n-1; k > 0; --k)
    {
      for (int i = k-1; i >= 0; --i)
      {
        if(a[k][k])
        {
          double m=a[i][k]/a[k][k];
          for(int j = 0; j < n; ++j)
            {
              a[i][j]-=m*a[k][j];
              ed[i][j]-=m*ed[k][j];
            }
        }
      }
    }
    for (int i = 0; i < n; ++i)
    {
      ed[i][i]/=a[i][i];
    }
      for (int i = 0; i < n; ++i)
        {
          for (int j =0; j < n; ++j)
              cout<<ed[i][j]<<" ";
          cout<<endl;
        }
  }
  else
    cout<<"Sry(\n";
  file.close();
  return 0;  
}