class Solution {
public:
    int candy(vector<int>& rating) {
        int candyCount = 0 ,  n = rating.size();
        vector<int> lcandy(n,1), rcandy(n,1), cand(n,1),cand1(n,1);
        for(int i = 0; i <n-1 ;i++)
        {
            if(rating[i]> rating[i+1])
            {
                rcandy[i]++;
            }
        }
        for(int i = n-1; i >=1 ;i--)
        {
            if(rating[i]> rating[i-1])
            {
                lcandy[i]++;
            }
        }
        for(int i = n-1; i>=0;i--)
        {
            if(lcandy[i]==rcandy[i] && lcandy[i]==2)
            {
                cand[i] = max(cand[i-1],cand[i+1])+1;
            }
            if(lcandy[i]>rcandy[i])
            {
                cand[i] = cand[i-1]+1;
            }
            if(lcandy[i]<rcandy[i])
            {
                cand[i] = cand[i+1]+1;
            }
        }
        for(int i = 0; i<n;i++)
        {
            if(lcandy[i]==rcandy[i] && lcandy[i]==2)
            {
                cand[i] = max(cand[i-1],cand[i+1])+1;
            }
            if(lcandy[i]>rcandy[i])
            {
                cand[i] = cand[i-1]+1;
            }
            if(lcandy[i]<rcandy[i])
            {
                cand[i] = cand[i+1]+1;
            }
        }

        for(auto it:lcandy)
        {
            cout<<it <<" ";
        }
        cout<<endl;
        for(auto it:rcandy)
        {
            cout<<it <<" ";
        }
        cout<<endl;
        int cc = 0;
        for(int i = 0 ; i<n ; i++)
        {
            
            candyCount+=cand[i];
            cc+=cand[i];

        }
        return max(candyCount,cc);


        // if(n==1)
        // return 1;
        // for(int i = n-1; i >= 0; i--)
        // {
            
        //     if( i == n-1)
        //     {
        //         if(rating[i] > rating[i-1])
        //         {
        //             cnd[i]++;
        //         }

        //     }
        //     else
        //     {
              
        //         if(i>0 && rating[i]> rating[i+1] && rating [i]> rating[i-1])
        //         {
                 
        //            int mxc  = max(cnd[i-1], cnd[i+1]);
        //             cnd[i] = mxc+1;
        //             cout<<cnd[i]<<endl;
                   
        //         }
        //        else if(i>0 && rating[i]> rating[i-1])
        //        {
                   
        //            cnd[i] = cnd[i-1]+1;
        //            for(int j = i+1;j<n; j++)
        //            {
                       
        //                if(rating[j]> rating[j-1])
        //              {
        //                     cnd[j] = max(cnd[j],cnd[j-1]+1);
        //              }
        //              else break;
        //            }
        //        }
        //        else if(i == 0)
        //        {
        //            if(rating[i]> rating [ i+1])
        //            {
        //                cnd[i] = cnd[i+1]+1;
        //            }
        //        }
        //        else
        //        {
        //            if(rating[i]> rating[i+1])
        //            {
        //                cnd[i] = max(cnd[i],cnd[i+1]+1);
        //            }
        //        }
        //     }
        // }

        // for(auto it: cnd)
        // {
        //     cout<<it<<" ";
        //     candyCount +=it;
        // }
        // return candyCount;
        
    }
};