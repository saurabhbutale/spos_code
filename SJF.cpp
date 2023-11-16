#include<iostream>
#include<string.h>
#define MAX 1000
using namespace std;

void SJF_pre(int n, int BT[], string p[], int AT[]) {
    int Finish_time[10], TA[10], WT[10];
    float cnt = 0, count = 0;

    // Array to keep track of whether a process has finished
    bool finished[10] = { false };

    // Initialize the current time
    int currentTime = 0;

    while (true) {
        int minBT = MAX, shortest = -1;

        // Find the process with the minimum burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (AT[i] <= currentTime && !finished[i] && BT[i] < minBT) {
                minBT = BT[i];
                shortest = i;
            }
        }

        // If no process is found, exit the loop
        if (shortest == -1)
            break;

        // Update current time
        currentTime += BT[shortest];

        // Update Finish_time, Turnaround time, and Waiting time
        Finish_time[shortest] = currentTime;
        TA[shortest] = Finish_time[shortest] - AT[shortest];
        WT[shortest] = TA[shortest] - BT[shortest];
        finished[shortest] = true;
    }

     cout<<endl;
    cout<<"Premptive"<<endl;
    cout<<"GANTT-CHART"<<endl;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"  "<<p[i]<<"  ";
    }
    cout<<endl;
    cout<<AT[0];
    int d=BT[0]+AT[0];
    for(int i=0;i<n;i++)
    {
        cout<<"    "<<d;
        d=d+BT[i+1];
    }
    cout<<endl;
    for (int i = 0; i<n; i++)
    {
        cout<<"Turn-around time of "<<p[i]<<"= "<<TA[i]<<" msec"<<endl;
        cnt+=TA[i];
    }
    cnt=cnt/n;
    cout<<"Average Turn-around time of = "<<cnt<<" msec"<<endl;
    cout<<endl;
    for (int i = 0; i<n; i++)
    {
        WT[i]=TA[i]-BT[i];
        cout<<"Waiting time of "<<p[i]<<"= "<<WT[i]<<" msec"<<endl;
        count+=WT[i];
    }
    count=count/n;
    cout<<"Average Waiting time of = "<<count<<" msec"<<endl;
}

int main()
{
    int n,t, BT[10],AT[10],ttt;
    string p[10],temp;
    cout<<"Enter the number of process: ";
    cin>>n;
    for (int i = 0; i<n; i++)
    {
        cout<<"Enter the process name: ";
        cin>>p[i];
        cout<<"Enter the Burst time :";
        cin>>BT[i];
        cout<<"Enter the Arrival time : ";
        cin>>AT[i];
        if(AT[i]!=0)
        {
            if(i>1)
            {
                if(BT[i]<BT[i-1])
                {
                    t=BT[i];
                    BT[i]=BT[i-1];
                    BT[i-1]=t;

                    ttt=AT[i];
                    AT[i]=AT[i-1];
                    AT[i-1]=t;

                    temp=p[i];
                    p[i]=p[i-1];
                    p[i-1]=temp;
                }
            }
        }
    }
    SJF_pre(n,BT,p,AT);
    return 0;
}
