//
//  main.cpp
//  2018年06月21日09:15:16  First
//
//  Created by 杨扬 on 18/6/21.
//  Copyright © 2018年 杨扬. All rights reserved.
//
/*
#include <iostream>
#include<fstream>
#include<cstdlib>
#include "cmath"
#include "algorithm"
using namespace std;
int main() {
    int studentid;
    sort(a,a+4,greater<int>());将greater改为less为从小到大
    
    freopen("111.txt","r",stdin);
    cin >> studentid;
    cout << studentid;
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
string Trim(string& str)
 {
      str.erase(0,str.find_first_not_of(" \t\r\n"));
    
     str.erase(str.find_last_not_of(" \t\r\n") + 1);
    
      return str;
     }

 int main()
{
      ifstream fin("/Users/S20171105130/Desktop/STUDENT1.0.csv");
    
      string line;
      while (getline(fin, line)) {
          //cout << line << endl;
        
           istringstream sin(line);
          vector<string> fields;
           string field;
           while (getline(sin, field, ',')) {
                fields.push_back(field);
               }
        
           string name = Trim(fields[0]);
           string age = Trim(fields[1]);
           string birthday = Trim(fields[2]);
           cout << name << "\t" << age << "\t" << birthday << endl;
          }
        system("pause");
        return 0;
        
        }

class csvdata{
     public:
        int studentID;
    string name;
    string sex;
    int birth;
    };//行的类定义
int main()
{
        vector<csvdata> incsv;
        csvdata intp;
        FILE *fp;
        fp=fopen("/Users/S20171105130/Documents/STUDENT1.0.csv","r");//你自己的文件路径
        while(1){
                 fscanf(fp,"%d,%s,%s,%d",&intp.studentID,&intp.name,&intp.sex,&intp.birth);
                incsv.push_back(intp);
                if (feof(fp))break;
            }
        fclose(fp);
        for(int i=0;i<incsv.size();i++)
            {
                   cout<<incsv[i].studentID<<" "<<incsv[i].name<<" "<<incsv[i].sex<<" "<<incsv[i].birth<<endl;
            }//输出显示每行的数据
    
    
    system("pause");
    return 0;
    }
    string Trim(string& str)
    {
        //str.find_first_not_of(" \t\r\n"),在字符串str中从索引0开始，返回首次不匹配"\t\r\n"的位置
        str.erase(0,str.find_first_not_of(" \t\r\n"));
        str.erase(str.find_last_not_of(" \t\r\n") + 1);
        return str;
    }
    int main()
    {
        ifstream fin("STUDENT1.0.csv");
        string line;
        while (getline(fin, line))
        {
            cout <<"原始字符串："<< line << endl;
            istringstream sin(line);
            vector<string> fields; //声明一个字符串向量
            string field;
            while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
            {
                fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
            }
            string name = Trim(fields[0]); //清除掉向量fields中第一个元素的无效字符，并赋值给变量name
            string age = Trim(fields[1]); //清除掉向量fields中第二个元素的无效字符，并赋值给变量age
            string birthday = Trim(fields[2]); //清除掉向量fields中第三个元素的无效字符，并赋值给变量birthday
            cout <<"处理之后的字符串："<< name << "\t" << age << "\t" << birthday << endl;
            
        }
        //int ID;
        //string name;
        // int sex;
        // int birth;
        //string class1;
        //int phone;
        //int judges1,judges2,judges3,judges4,judges5;
        //cin>>name;
        //freopen("STUDENT1.0.csv","r",stdin);
        //freopen("input.csv","w",stdout);
        //cout<<"name"<<endl;
        //fprintf(fp,"haha");
        
        return EXIT_SUCCESS;
 
 }*/
/*
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "algorithm"
#include <cstdlib>
#include<stdio.h>
using namespace std;
struct student
{
    int StudentID;
    char name[200];
    char sex[200];
    int birth;
    char class_[200];
    char phone[200];
    int judge1;
    int judge2;
    int judge3;
    int judge4;
    int judge5;
    int grade;
};
int main()
{
    struct student s[1000];
    FILE *fp1,*fp2;
    int i=0,j;
    
    fp1 =fopen("/Users/S20171105130/Desktop/STUDENT4.csv","r");
    if(fp1==NULL)
    {
        printf("error\n");
        exit(-1);
    }
    else
    {
        fscanf(fp1,"%*[^\n]%*c");
        while(!feof(fp1))
        {
            fscanf(fp1,"%d,%[^,],%[^,],%d,%[^,],%[^,],%d,%d,%d,%d,%d",
                   &s[i].StudentID,&s[i].name,&s[i].sex,&s[i].birth,&s[i].class_,&s[i].phone,&s[i].judge1,&s[i].judge2,&s[i].judge3,&s[i].judge4,&s[i].judge5);
            i++;
        }
        j=i;
        
        for(i=0;i<j;i++)
        {
            printf("%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d\n",s[i].StudentID,
                   s[i].name,s[i].sex,s[i].birth,s[i].class_,s[i].phone,
                   s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);
        }
        
        fclose(fp1);
    }
    j=i;
    int max[100],min[100];
    
    for(i=0;i<j;i++)
    {
        max[i]=min[i]=s[i].judge1;
    }
    j=i;
    
    for(i=0;i<j;i++)
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
    j=i;
    
    for(i=0;i<j;i++)
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
    j=i;
    
    for(i=0;i<j;i++)
    {
        s[i].grade=(s[i].judge1+s[i].judge2+s[i].judge3+s[i].judge4+s[i].judge5-max[i]-min[i])/3;
    }
    j=i;
    i=0;
    
    fp2=fopen("/Users/S20171105130/Desktop/STUDENT5.0.csv","w");
    fprintf(fp2,"StudentID,name,sex,birth,class,phone,judge1,judge2,judge3,judge4,judge5,grade\n");
    
    while(i<j)
    {
        fprintf(fp2,"%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d,%d\n",
                s[i].StudentID,s[i].name,s[i].sex,s[i].birth,s[i].class_,
                s[i].phone,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5,s[i].grade);
        i++;
    }
    fclose(fp2);
    
    return 0;
}*/

/*int main()
{
    struct student s[2000];
    FILE *a;
    FILE *b;
    b=fopen("/Users/S20171105130/Desktop/STUDENT5.0.csv","a");//以文本方式打开文件。
    
    int  i=0,j,n,q,sum,max,min;
    if(b == NULL)
    {
    return -1;
    }//打开文件出错。
    while(fscanf(b, "%s", &v[i]) != EOF) //读取数据到数组，直到文件结尾(返回EOF)
        i++;
    fclose(b);//关闭文件
    for(j = 0; j < i; j ++)//循环输出数组元素。
    {
        
    }*/
        
    //用i来做计数器，用n来做总数，sum就是总和，max即是最大数，
    //min即是最小数
    /*string s1[200];
    string s2[200];
    string s3[200];
    string s4[200];
    string s5[200];
    string s6[200];
    string s7[200];
    string s8[200];
    string s9[200];
    string s10[200];
    string s11[200];
    int s12[10];*/
    

    //vector<string>::iterator fie;
    //while(getline(fin,line)){
     //   vector<string> fields;
     //   string field;
    //}
    /*
if ((a=fopen("/Users/S20171105130/Desktop/STUDENT4.csv","r"))==0)
{
    printf("nono\n");
}
else
{
    for(int t=0;t<3;t++)
        {
        fscanf(a,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ",&s1,&s2,&s3,&s4,&s5,&s6,&s7,&s8,&s9,&s10,&s11);
            
            //cout << s1[i].name<<endl;
        //if(i==1||i==2)
        //{
        //fprintf(b,"%s ,%s ,%s ,%s ,%s ,%s ,%d ,%d ,%d ,%d ,%d \n",s1,s2,s3,s4,s5,s6,s12[1],s12[2],s12[3],s12[4],s12[5]);
        //}
        //else{
        
        fprintf(b,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s \n",s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11);
        printf("%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s \n",s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11);
        
        
}
    
    
}*/
/*
 s1[i],s2[i],s3[i],s4[i],s5[i],s6[i],s7[i],s8[i],s9[i],s10[i],s11[i]
 #include<iostream.h>
 void main()
 {
 int  i,n,a,sum,max,min;
 //用i来做计数器，用n来做总数，sum就是总和，max即是最大数，
 //min即是最小数
 cout << "请输入要比较的数字的个数 n = "<<endl;
 cin >>n ;
 cout<<"请输入第1个数:" <<endl;
 cin >>a;
 min=a;                      //初始化各数
 max=a;
 sum=a;
 for( i=1;i<n;++i)            //循环应用
 {
 cout << "请输入第"<<i+1<<"个数"<<endl;
 cin >> a;
 if(a>max)  {max=a;}
 if(a<min)  {min=a;}
 sum+=a;
 }
 cout <<"  最大数max = " << max <<  "  最小数min = "<< min <<endl;
 cout << "除去最大数和最小数的总和为sum = " << sum-max-min <<endl;
 cout  <<"此时平均数" << (sum-max-min)/n<<endl;    //平均数是n-2个数的还是n个数的，你自己改吧
 }*/
//%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n
/*
#include <cstdlib>
#include<stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "algorithm"
using namespace std;

struct student
{
    
    int numbers;
    char name[10];
    char sex[10];
    int dateofbirt;
    char class1[15];
    char phoneNo[15];
    int judge1[5];
    int judge2[5];
    int judge3[5];
    int judge4[5];
    int judge5[5];
    int score;
};
int main()
{
    struct student s[100];
    FILE *a,*fp2;
    int i=0,j;
    
    a =fopen("/Users/S20171105130/Desktop/STUDENT4.csv","r");
    fp2=fopen("/Users/S20171105130/Desktop/STUDENT5.0.csv","w");
    fprintf(fp2,"numbers,name,sex,dateofbirth,class,phoneNo,judge1,judge2,judge3,judge4,judge5,score\n");
    if ((a=fopen("/Users/S20171105130/Desktop/STUDENT4.csv","r"))==0)
    {
        printf("nono\n");
    }
    else
    {
        fscanf(a,"%*[^\n]%*c");
        //while(!feof(a))
        for(i=0;i<2;i++)
        {
            fscanf(a,"%d,%[^,],%[^,],%d,%[^,],%[^,],%d,%d,%d,%d,%d",
                   &s[i].numbers,&s[i].name,&s[i].sex,&s[i].dateofbirt,&s[i].class1,
                   &s[i].phoneNo,&s[i].judge1,&s[i].judge2,&s[i].judge3,&s[i].judge4,&s[i].judge5);
            fprintf(fp2,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
                    s[i].numbers,s[i].name,s[i].sex,s[i].dateofbirt,s[i].class1,
                    s[i].phoneNo,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5,s[i].score);
        }
    }
    
    return 0;
}

        //j=i;
        
        for(i=0;i<j;i++)
        {
            printf("%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d\n",s[i].numbers,
                   s[i].name,s[i].sex,s[i].dateofbirt,s[i].class1,s[i].phoneNo,
                   s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);
        }
        

    }
    j=i;
    int max[100],min[100];
    
    for(i=0;i<j;i++)
    {
        max[i]=min[i]=s[i].judge1;
    }
    j=i;
    
    for(i=0;i<j;i++)
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
    j=i;
    
    for(i=0;i<j;i++)
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
    j=i;
    
    for(i=0;i<j;i++)
    {
        s[i].score=(s[i].judge1+s[i].judge2+s[i].judge3+s[i].judge4+s[i].judge5-max[i]-min[i])/3;
    }
    j=i;
    i=0;*/
    
    
    
    //while(i<j)
    //{
    
      //  i++;
    //}
//int max[100],min[100];

//for(i=0;i<2;i++)
////{
//    max[i]=min[i]=atoi(s[i].judge1);
//}
//j=i;
/*
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
 */
//fprintf(b,"numbers,name,sex,birth,class,phoneNo,judge1,judge2,judge3,judge4,judge5,grade\n");*/
/*#include<iostream>
 #include<fstream>
 #include<string>
 #include<cstdlib>
 
 
 using namespace std;
 
 struct student
 {
 char StudentID[100];
 char name[100];
 char sex[100];
 char birth[10];
 char class1[100];
 char phoneNo[100];
 char judge1[100];
 char judge2[100];
 char judge3[100];
 char judge4[100];
 char judge5[100];
 char judge[15][15];
 double grade;
 int judgeMax;
 int judgeMin;
 int max;
 int min;
 int sum;
 
 };
 
 int main()
 {
 struct student s[20000];
 int i=0,n=0;
 FILE *a;
 FILE *b;
 b=fopen("/Users/S20171105130/Desktop/STUDENT5.0.csv","w");
 ifstream start("/Users/S20171105130/Desktop/STUDENT4.csv");
 string end;
 while (getline(start, end))
 {
 n++;
 }
 cout<<n<<endl<<endl;
 
 if ((a=fopen("/Users/S20171105130/Desktop/STUDENT4.csv","r"))==0)
 {
 printf("Error");
 exit(-1);
 }
 else
 {
 //fscanf(a,"%*[^\n]%*c");//!feof(a)
 while(fscanf(a,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s",s[i].StudentID,s[i].name,s[i].sex,s[i].birth,s[i].class1,s[i].phoneNo,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5))
 {
 s[i].judgeMax=0,s[i].judgeMin=101;//给最高分和最低分变量赋初值
 for(j=0;j<5;++j)
 {
 if(atoi(s[i].judge[j])>s[i].judgeMax)
 {
 s[i].judgeMax=atoi(s[i].judge[j]);//判断一行中的最高分
 s[i].max=j;//最大值下标
 }
 if(atoi(s[i].judge[j])<s[i].judgeMin)
 {
 s[i].judgeMin=atoi(s[i].judge[j]);//判断一行中的最低分
 s[i].min=j;//最小值下标
 }
 }
 s[i].sum=atoi(s[i].judge[0])+atoi(s[i].judge[1])+atoi(s[i].judge[2])+atoi(s[i].judge[3])+atoi(s[i].judge[4])-s[i].judgeMax-s[i].judgeMin;//对评委打分求和，把字符转为整形并运算
 strcpy(s[i].judge[s[i].max],"MAX");//把最高分输出时用‘MAX’替换
 strcpy(s[i].judge[s[i].min],"MIN");//把最低分输出时用'MIN'替换
 if(i>=n)
 {
 break;
 }//文件读取结束直至最后一行
 i++;
 }
 }
 
 while(i>=n)
 {
 return 0;
 }//文件读取结束直至最后一行
 if(i==0)
 {
 printf("%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ",s[i].StudentID,s[i].name,s[i].sex,s[i].birth,s[i].class1,s[i].phoneNo,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);//测试输出结果
 fprintf(b,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s",s[i].StudentID,s[i].name,s[i].sex,s[i].birth,s[i].class1,s[i].phoneNo,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);//把第一行字符原样输出
 }
 else
 {
 printf("%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s",s[i].StudentID,s[i].name,s[i].sex,s[i].birth,s[i].class1,s[i].phoneNo,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);//测试输出结果
 fprintf(b,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s",s[i].StudentID,s[i].name,s[i].sex,s[i].birth,s[i].class1,s[i].phoneNo,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);//除第一行外所有的数据输出
 }
 i++;*/
#include<iostream>
#include<fstream>
using namespace std;
struct STUDENT//定义一个student结构体
{
    char num[15];
    char name[20];
    char sex[10];
    char age[30];
    char grade[20];
    char pnum[20];
    char judge[15][15];
    int judgeMax;
    int judgeMin;
    int max;
    int min;
    int sum;
};

int main()
{
    struct STUDENT s[50000];//定义结构体数组s
    int i=0;
    int j=0;
    int n=0;//
    FILE *a;//定义一个地址指针用于指向数据源文件
    FILE *b;//定义一个地址指针用于指向写入数据的文件
    b=fopen("/Users/S20171105130/Desktop/STUDENT5.0.csv","w");//打开test4.csv文件用来后续文本写入
    ifstream START("/Users/S20171105130/Desktop/STUDENT4.csv");//打开test3.csv文件用来后续文本读取
    string END;
    while (getline(START,END))//逐行读取文本内容
    {
        n++;
    }
    if ((a=fopen("/Users/S20171105130/Desktop/STUDENT4.csv","r"))==0)//判断数据源文件是否存在且能否正常打开
    {
        printf("Error");
    }
    else
    {
        while(fscanf(a,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].grade,s[i].pnum,s[i].judge[0],s[i].judge[1],s[i].judge[2],s[i].judge[3],s[i].judge[4]))//循环读取数据源文件的文本内容
        {
            s[i].judgeMax=0,s[i].judgeMin=101;//给最高分和最低分变量赋初值
            for(j=0;j<5;++j)
            {
                if(atoi(s[i].judge[j])>s[i].judgeMax)
                {
                    s[i].judgeMax=atoi(s[i].judge[j]);//判断一行中的最高分
                    s[i].max=j;//最大值下标
                }
                if(atoi(s[i].judge[j])<s[i].judgeMin)
                {
                    s[i].judgeMin=atoi(s[i].judge[j]);//判断一行中的最低分
                    s[i].min=j;//最小值下标
                }
            }
            s[i].sum=atoi(s[i].judge[0])+atoi(s[i].judge[1])+atoi(s[i].judge[2])+atoi(s[i].judge[3])+atoi(s[i].judge[4])-s[i].judgeMax-s[i].judgeMin;//对评委打分求和，把字符转为整形并运算
            strcpy(s[i].judge[s[i].max],"MAX");//把最高分输出时用‘MAX’替换
            strcpy(s[i].judge[s[i].min],"MIN");//把最低分输出时用'MIN'替换
            if(i>=n)
            {
                break;
            }//文件读取结束直至最后一行
            i++;
        }
    }
    for(i=0;i<n;++i)
    {
        if(i==0)
        {
            printf("%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s\n",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].grade,s[i].pnum,s[i].judge[0],s[i].judge[1],s[i].judge[2],s[i].judge[3],s[i].judge[4]);//测试输出结果
            fprintf(b,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s\n",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].grade,s[i].pnum,s[i].judge[0],s[i].judge[1],s[i].judge[2],s[i].judge[3],s[i].judge[4]);//把第一行字符原样输出
        }
        else
        {
            printf("%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%d\n",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].grade,s[i].pnum,s[i].judge[0],s[i].judge[1],s[i].judge[2],s[i].judge[3],s[i].judge[4],s[i].sum/3);//测试输出结果
            fprintf(b,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%d\n",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].grade,s[i].pnum,s[i].judge[0],s[i].judge[1],s[i].judge[2],s[i].judge[3],s[i].judge[4],s[i].sum/3);//除第一行外所有的数据输出
        }
    }
    return 0;
}
