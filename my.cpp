#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<vector>

using namespace std;

struct student
{
    int StudentID;
    char name[100];
    char sex[100];
    int birth;
    char class1[100];
    char phoneNo[100];
    int judge1;
    int judge2;
    int judge3;
    int judge4;
    int judge5;
    int grade;

};

int main()
{
    struct student s[200];
    int i=0,n=0,j=0;
    FILE *a;
    FILE *b;
    b=fopen("C:\\Users\\lenovo\\Desktop\\STUDENT5.csv","w");
    ifstream start("C:\\Users\\lenovo\\Desktop\\STUDENT4.csv");
    string end;
    while (getline(start, end))//逐行读取文本内容,每读取一行就n+1 
    {
        n++;
    }
    //cout<<n<<endl<<endl;
    
   if ((a=fopen("C:\\Users\\lenovo\\Desktop\\STUDENT4.csv","r"))==0)
    {
        printf("Error");
    }
    else
    {
    	fscanf(a,"%*[^\n]%*c");//!feof(a)
        while(fscanf(a,"%d ,%s ,%s ,%d ,%s ,%s ,%d ,%d ,%d ,%d ,%d",&s[i].StudentID,&s[i].name,&s[i].sex,&s[i].birth,&s[i].class1,&s[i].phoneNo,&s[i].judge1,&s[i].judge2,&s[i].judge3,&s[i].judge4,&s[i].judge5))
        {
        	
        	
            //while(i>n-1)
            //    break;
            //printf("%d ,%s ,%s ,%d ,%s ,%s ,%d ,%d ,%d ,%d ,%d",&s[i].StudentID,&s[i].name,&s[i].sex,&s[i].birth,&s[i].class1,&s[i].phoneNo,
			//&s[i].judge1,&s[i].judge2,&s[i].judge3,&s[i].judge4,&s[i].judge5);
            //while(i>n-1)\n",s[i].StudentID,s[i].name,s[i].sex,s[i].birth,s[i].grade,s[i].pnum,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);
            // fprintf(b,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s\n",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].grade,s[i].pnum,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);
            //i++;
        }
        //j=i;
        for(i=0;i<j;i++)
        {
           printf("%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d",&s[i].StudentID,&s[i].name,&s[i].sex,&s[i].birth,&s[i].class1,&s[i].phoneNo,
			&s[i].judge1,&s[i].judge2,&s[i].judge3,&s[i].judge4,&s[i].judge5);
        }
    }
    int max[100],min[100];
    
    for(i=0;i<2;i++)
    {
        max[i]=min[i]=s[i].judge1;
    }
    //j=i;
    
    for(i=0;i<2;i++)
    {
        if(s[i].judge2>max[i])
            max[i]=s[i].judge2;
        if(s[i].judge3>max[i])
            max[i]=s[i].judge3;
        if(s[i].judge4>max[i])
            max[i]=s[i].judge4;
        if(s[i].judge5>max[i])
            max[i]=s[i].judge5;
    }
    //j=i;
    
    for(i=0;i<2;i++)
    {
        if(s[i].judge2<min[i])
            min[i]=s[i].judge2;
        if(s[i].judge3<min[i])
            min[i]=s[i].judge3;
        if(s[i].judge4<min[i])
            min[i]=s[i].judge4;
        if(s[i].judge5<min[i])
            min[i]=s[i].judge5;
    }
    //j=i;
    
    for(i=0;i<2;i++)
    {
        s[i].grade=(s[i].judge1+s[i].judge2+s[i].judge3+s[i].judge4+s[i].judge5-max[i]-min[i])/3;
    }
    fprintf(b,"numbers,name,sex,birth,class,phoneNo,judge1,judge2,judge3,judge4,judge5,grade\n");
    fprintf(b,"%d ,%s ,%s ,%d ,%s ,%s ,%d ,%d ,%d ,%d ,%d ,%d",&s[i].StudentID,&s[i].name,&s[i].sex,&s[i].birth,&s[i].class1,&s[i].phoneNo,&s[i].judge1,&s[i].judge2,&s[i].judge3,&s[i].judge4,&s[i].judge5,&s[i].grade);
    
    return 0;
}

