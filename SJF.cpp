#include<bits/stdc++.h>
using namespace std;
struct process{
int pid;
int AT;
int BT;
int TAT;
int CT;
int RT;
int WT;
int start_time;

};
int main()
{
  int n;
  struct process p[50];
  int iscompleted[50]={0};
  cout<<"Enter the number of processes : ";
  cin>>n;
  for(int i =0;i<n;i++)
  {
     cout<<"Enter the arrival time of process"<<i+1<<" : ";
     cin>>p[i].AT;
     cout<<"Enter the Burst time of process"<<i+1<<"   : ";
     cin>>p[i].BT;
      p[i].pid= i+1;
     cout<<endl;
  }
   int current_time=0;
   int completed =0;


   while(completed!=n)
   {  int index=-1;
      int mi=INT_MAX;
      //find the process with lowest burst_time which is not yet completed
       for(int i=0;i<n;i++)
       {
           if(p[i].AT<=current_time&&iscompleted[i]==0)
           {
               if(p[i].BT < mi)  // if variable (mi) is greater the burst time of the ith process then
               {

                   mi=p[i].BT;
                   index=i;
               }
               else if(p[i].BT == mi) // if two process have same burst_time,process which arrived
                                      // in the ready queue early is preferred.
               {
                   if(p[i].AT<p[index].AT)
                   {
                       index=i;
                   }
               }
           }

       }

       if(index!=-1)                //if the process is found
       {
          p[index].start_time=current_time;
          p[index].CT = p[index].start_time + p[index].BT;
          p[index].TAT = p[index].CT - p[index].AT;
          p[index].WT = p[index].TAT - p[index].BT;

          iscompleted[index]=1;
          completed++;
          current_time= p[index].CT;

       }
       else
       {
           current_time++;  //if process is not yet arrived in the ready queue.
       }
   }

   cout<<endl<<endl<<endl;
   cout<<"Process\tAT\tBT\tCT\tTAT\tWT\n\n";
   int a=0,twt=0,trt=0;
   for(int i=0;i<n;i++)
   {
       cout<<p[i].pid<<"\t"<<p[i].AT<<"\t"<<p[i].BT<<"\t"<<p[i].CT<<"\t"<<p[i].TAT<<"\t"<<p[i].WT<<"\n";
       a+=p[i].TAT;      //Total turn around Time
       twt+=p[i].WT;     //Total Waiting Time
       trt+=p[i].RT;     //Total Response Time
   }
   cout<<"\nAverage Turn around time = "<<(float)a/n;
   cout<<"\nAverage Waiting Time = " <<(float)twt/n;
  //N cout<<"\n\n\n\n\n\n\n";

}
/* AT=Arrival Time
   BT- Burst Tme
   CT = Completion Time
   TAT = Turn Around Time
   WT = Waiting Time
   RT = Response Time

*/
