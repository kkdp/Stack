
  #include <bits/stdc++.h>
  
  
  using namespace std;

  // Largest area in Histogram 

  int main()
  {
    vector<int>h={ 4,2,4,2,1 } ;
    stack<int>s;
    int mx=-1;
    int i,n=h.size();
    for(i=0; i<n; i++)
    {
      if(s.empty())
        s.push(i);
      else
      {
        if(h[i]>=h[s.top()])
          s.push(i);
        else{
          while(s.empty()==false && h[s.top()]>=h[i])
          {
            int tp=s.top();
            s.pop() ;
            int tmp;
            if(s.empty()==false)
             tmp = h[tp]*(i-s.top()-1) ;
            else
              tmp=h[tp]*i;
            mx=max(mx,tmp) ;
          }
          if(s.empty()==false && h[s.top()]<h[i])
            s.push(i);
          if(s.empty())
            s.push(i);

        }

      }
    }
    while(s.empty()==false)
    {
      int tp=s.top();
      s.pop() ;
      int tmp;
            if(s.empty()==false)
             tmp = h[tp]*(i-s.top()-1) ;
            else
              tmp=h[tp]*i;
            mx=max(mx,tmp) ;
    }
    cout<<mx;
    return 0;
  }
