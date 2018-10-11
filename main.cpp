#include<iostream>
#include<fstream>
using namespace std;
struct student//定义一个student结构体
{
    char StudentID[15],name[20],sex[10],birth[30],CLASS[20],phone[20],JUDGE[15][15];
    int MAX,MIN,max,min;
    double sum;
};

int main()
{
    int n=0,i=0;
    ifstream fin("/Users/S20171105130/Desktop/STUDENT4.csv");//定义一个fin对象
    string END;
    while (getline(fin, END))//逐行读取文本内容，读到/n截止，读取fin指向文件
    {
        n++;
    }
    struct student s[20000];//定义结构体数组s
    FILE *fp;
    
    if ((fp=fopen("/Users/S20171105130/Desktop/STUDENT4.csv","r"))==0)//以只读的方式打开文件
    {
        printf("error");
    }
    else
    {
        while(fscanf(fp,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s",s[i].StudentID,s[i].name,s[i].sex,s[i].birth,s[i].CLASS,s[i].phone,s[i].JUDGE[0],s[i].JUDGE[1],s[i].JUDGE[2],s[i].JUDGE[3],s[i].JUDGE[4]))//读取STUDENT文件里的数据，i为0时读取第一行。。。
        {
            
            int MAX_[20],MIN_[20];
            MAX_[i]=MIN_[i]=atoi(s[i].JUDGE[0]);
            if(atoi(s[i].JUDGE[1])>MAX_[i])
                MAX_[i]=atoi(s[i].JUDGE[1]);
            if(atoi(s[i].JUDGE[2])>MAX_[i])
                MAX_[i]=atoi(s[i].JUDGE[2]);
            if(atoi(s[i].JUDGE[3])>MAX_[i])
                MAX_[i]=atoi(s[i].JUDGE[3]);
            if(atoi(s[i].JUDGE[4])>MAX_[i])
                MAX_[i]=atoi(s[i].JUDGE[4]);
            if(atoi(s[i].JUDGE[1])<MIN_[i])
                MIN_[i]=atoi(s[i].JUDGE[1]);
            if(atoi(s[i].JUDGE[2])<MIN_[i])
                MIN_[i]=atoi(s[i].JUDGE[2]);
            if(atoi(s[i].JUDGE[3])<MIN_[i])
                MIN_[i]=atoi(s[i].JUDGE[3]);
            if(atoi(s[i].JUDGE[4])<MIN_[i])
                MIN_[i]=atoi(s[i].JUDGE[4]);
            s[i].sum=(atoi(s[i].JUDGE[0])+atoi(s[i].JUDGE[1])+atoi(s[i].JUDGE[2])+atoi(s[i].JUDGE[3])+atoi(s[i].JUDGE[4])-MAX_[i]-MIN_[i]);
            if(i>=n)
            {
                break;
            }
            i++;
        }
    }
    FILE *fp1;
    fp1=fopen("/Users/S20171105130/Desktop/STUDENT5.0.csv","w");//只写方式打开文件
    for(i=0;i<n;++i)
    {
        if(i==0)
        {
            printf("%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s\n",s[i].StudentID,s[i].name,s[i].sex,s[i].birth,s[i].CLASS,s[i].phone,s[i].JUDGE[0],s[i].JUDGE[1],s[i].JUDGE[2],s[i].JUDGE[3],s[i].JUDGE[4]);
            fprintf(fp1,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s\n",s[i].StudentID,s[i].name,s[i].sex,s[i].birth,s[i].CLASS,s[i].phone,s[i].JUDGE[0],s[i].JUDGE[1],s[i].JUDGE[2],s[i].JUDGE[3],s[i].JUDGE[4]);
        }
        else
        {
            printf("%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,平均分为:%.2f\n",s[i].StudentID,s[i].name,s[i].sex,s[i].birth,s[i].CLASS,s[i].phone,s[i].JUDGE[0],s[i].JUDGE[1],s[i].JUDGE[2],s[i].JUDGE[3],s[i].JUDGE[4],s[i].sum/3);
            fprintf(fp1,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,平均分为:%.2f\n",s[i].StudentID,s[i].name,s[i].sex,s[i].birth,s[i].CLASS,s[i].phone,s[i].JUDGE[0],s[i].JUDGE[1],s[i].JUDGE[2],s[i].JUDGE[3],s[i].JUDGE[4],s[i].sum/3);
        }
    }
    fclose(fp);
    fclose(fp1);
    return 0;
}
