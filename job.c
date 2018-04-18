#include<stdio.h>
 
void main()
{
    int brust_time[20],p[20],waitting_time[20],turn_arround_time[20],i,j,n,all_total=0,position,temp;
    float avg_wt,avg_tat;
    printf("/nplease how much u want process.... Enter number of process:");
    scanf("%d",&n);
 
    printf("\n******Enter Burst Time:\n**********8888");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&brust_time[i]);
        p[i]=i+1;         
    }
 
    for(i=0;i<n;i++)/*********** //sorting burst time in ascending order using selection sort*******************/
    {
        position=i;
        for(j=i+1;j<n;j++)
        {
            if(brust_time[j]<brust_time[position])
                position=j;
        }
 
        temp=brust_time[i];
        brust_time[i]=brust_time[position];
        brust_time[position]=temp;
 
        temp=p[i];
        p[i]=p[position];
        p[position]=temp;
    }
 
    waitting_time[0]=0;            //waiting time = zero
 
    /***************calculate waiting time*****************************/
    for(i=1;i<n;i++)
    {
        waitting_time[i]=0;
        for(j=0;j<i;j++)
            waitting_time[i]+=brust_time[j];
 
        all_total+=waitting_time[i];
    }
 
    avg_wt=(float)all_total/n;      //its calculate the average waiting time by using all_total
    all_total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        turn_arround_time[i]=brust_time[i]+waitting_time[i];     //its calculate turnaround time by using brusttime nd waitting time
        all_total+=turn_arround_time[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],brust_time[i],waitting_time[i],turn_arround_time[i]);
    }
 
    avg_tat=(float)all_total/n;     //its calculate  how much average turnaround time
    printf("\n\nfinally there isn Average Waiting Time=%f",avg_waitting_time);
    printf("\n\nfinally there isnAverage Turnaround Time=%f\n",avg_tat);
}
