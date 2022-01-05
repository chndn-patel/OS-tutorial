#include<bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
int frame_size;
int pages[N];

bool check(vector<int> v,int n)
{
     vector<int>::iterator i;
     i= find(v.begin(),v.end(),n);
     if(i!=v.end())
     return 0;
     else
     return 1;

}

void lru_page_replacement()
{
    vector<int> s;
    map<int, int> indexes;

    int page_faults = 0;
    for (int i=0; i<n; i++)
    {

        if(check(s,pages[i]))
        {
            if (s.size() < frame_size)
            {
                s.push_back(pages[i]);
                page_faults++;
            }
            else
            {
                int lru = INT_MAX, val;
                for (int j=0;j<s.size();j++)
                {
                    if (indexes[s[j]] < lru)
                    {
                        lru = indexes[s[j]];
                        val = j;
                    }
                }
               s[val]=pages[i];
                page_faults++;
            }

        }
        indexes[pages[i]] = i;
        for(int i=0;i<s.size();i++)
        {
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }

    cout<<"\nTotal Page Faults: "<<page_faults<<"\n\n";
}

int main()
{
    cout<<"Number of Frames: ";
    cin>>frame_size;

    cout<<"Page Reference Stream Length: ";
    cin>>n;

    cout<<"Page Reference Stream:\n";
    for(int i=0; i<n; i++)
        cin>>pages[i];

        cout<<endl<<endl<<endl;
    lru_page_replacement();
  
}
