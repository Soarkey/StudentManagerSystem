#include<stdio.h>			//I/O函数
#include<stdlib.h>			//标准库函数
#include<string.h>			//字符串函数
#include<ctype.h>			//字符操作函数
#define M 100 				//定义常数表示记录数
#include<windows.h>         //窗口界面

typedef struct
{
	char no[20];		//学号
	char name[20];		//姓名
	char sex[5];		//性别
	int  age;			//年龄
	float score;        //分数
}STUDENTS;//学生结构体

//函数原型（函数声明）
void welcome();                                 //欢迎函数
int menu_select();								//主菜单函数
int enter(STUDENTS t[],int n);					//输入记录
void list(STUDENTS t[],int n);					//显示记录
void search_name(STUDENTS t[],int n);			//按姓名查找显示记录
void search_no(STUDENTS t[],int n);             //按学号查找显示记录
int del_name(STUDENTS t[],int n);				//按姓名删除记录
int del_no(STUDENTS t[],int n);                 //按学号删除记录
int add(STUDENTS t[],int n);					//插入记录
void save(STUDENTS t[],int n);					//记录保存为文件
int load(STUDENTS t[]);							//从文件中读记录
void display(STUDENTS t[],int n);				//按序号查找显示记录
void sort_name(STUDENTS t[],int n);				//按姓名排序
void sort_no(STUDENTS t[],int n);               //按学号排序
void copy();									//文件复制
void print_one(STUDENTS temp);					//显示单条记录
int find_name(STUDENTS t[],int n,char *s);		//按姓名查找
int find_no(STUDENTS t[],int n,char *no);		//按学号查找
void modify_name(STUDENTS t[],int n);           //通过姓名修改记录
void modify_no(STUDENTS t[],int n);				//通过学号修改记录
void quit(STUDENTS t[],int n);                  //退出系统,并保存信息
void aboutSystem();                             //关于系统


//欢迎函数
void welcome()
{
    printf("******************************************************************\n");
    printf("|                                                                |\n");
    printf("|                   欢迎进入学生管理系统                         |\n");
    printf("|                                                                |\n");
    printf("|");
    int i;
    for(i = 0; i< 64; i++)  //输出欢迎界面的动效
    {
        printf("_");
        Sleep(20);
    }
    printf("|\n");
    printf("|                                                                |\n");
    printf("|                                                                |\n");
    printf("|                      ______________                            |\n");
    printf("|                      | __________ |                            |\n");
    printf("|                      ||          ||                            |\n");
    printf("|                      || Welcome! ||                            |\n");
    printf("|                      ||__________||                            |\n");
    printf("|                      |____________|                            |\n");
    printf("|                          /____\\                                |\n");
    printf("|                                                                |\n");
    printf("|                                                                |\n");
    printf("|                                                                |\n");
    printf("|                     作者：Soarkey                               |\n");
    printf("|                     班级：XXXXXXXXXXX                          |\n");
    printf("|                                                                |\n");
    printf("|                                                                |\n");
    printf("******************************************************************\n");

}


//菜单函数，函数返回值为整数，代表所选的菜单项
int menu_select()
{
	char s[80];
	int c;
	printf("****************************** 主菜单 ****************************\n");
    printf("|                                                                |\n");
	printf("|		           0. 输入学生记录                       |\n");
	printf("|		           1. 浏览学生记录                       |\n");
	printf("|		           2. 按姓名查找                         |\n");
	printf("|		           3. 按学号查找                         |\n");
	printf("|		           4. 按姓名删除                         |\n");
	printf("|		           5. 按学号删除                         |\n");
	printf("|		           6. 按姓名修改                         |\n");
	printf("|		           7. 按学号修改                         |\n");
	printf("|		           8. 插入学生记录                       |\n");
	printf("|	                   9. 按序号浏览                         |\n");
	printf("|		           10.按姓名排序                         |\n");
    printf("|		           11.按学号排序                         |\n");
	printf("|		           12.拷贝到新文件                       |\n");
	printf("|		           13.程序退出(自动保存)                 |\n");
	printf("|		           14.关于系统                           |\n");
	printf("|                                                                |\n");
	printf("******************************************************************\n\n");
	do
	{
		printf("\n	输入您的菜单选项编号（0-14）：");		//提示输入选项
		scanf("%s",s);										//输入选择项
		c=atoi(s);											//将输入的字符串转化为整型数
		getchar();                                          //消除回车键
		if(c<0||c>14)
            printf("\t您输入的序号有误，请重新输入！！！");
	}while(c<0||c>14);										//选项不在0~11之间重输
		return c;											//返回选择项，主程序根据该数调用相应的函数
 }


//输入记录，形参为结构体数组和原记录长度，函数返回类型为整型表示记录长度
int enter(STUDENTS t[],int n)
{
	int i,m;
	system("cls");
	printf("\n请输入学生记录条数：\n");
	scanf("%d",&m);									//输入记录数
	printf("请输入学生记录：\n");
	printf("学号                姓名                性别      年龄      分数\n");
	printf("------------------------------------------------------------------\n");
	for(i=0;i<m;i++)
	{
		scanf("%s%s%s%d%f",&t[i+n].no,&t[i+n].name,&t[i+n].sex,&t[i+n].age,&t[i+n].score);  //输入学生信息
		getchar();
    }
    printf("\n输入学生信息成功！\n");
	return n+m;										//返回新的记录条数
}


//显示记录，参数为记录数组和记录条数
void list(STUDENTS t[],int n)
{
	int i;
	system("cls");
	printf("**************************** 学生清单 ****************************\n");
	printf("                                                                  \n");
	printf("学号                姓名                性别      年龄      分数\n");
	printf("------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("%-20s%-20s%-10s%-10d%-5.2f\n",t[i].no,t[i].name,t[i].sex,t[i].age,t[i].score);
		if((i+1)%10==0 && n%10>0)					//判断输出是否达到10条记录
		{
			printf("------------------------------------------------------------------\n");
			printf("每页显示10条学生记录，按回车键向后翻页......\n");
			getchar();
			system("cls");
			printf("**************************** 学生清单 ****************************\n");
            printf("                                                                  \n");
			printf("学号                姓名                性别      年龄      分数\n");
			printf("------------------------------------------------------------------\n");
		}
	}
    printf("                                                                  \n");
	printf("------------------------------------------------------------------\n");
 }


 //查找姓名记录
void search_name(STUDENTS t[],int n)
{
	char s[20];										//保存待查找姓名字符串
	int i;											//保存查找到结点的序号
	system("cls");
	printf("*************************** 按姓名查找 ***************************\n");
	printf("                                                                  \n");
	printf("请输入查找的姓名：\n");
	scanf("%s",s);									//输入待查找姓名
	getchar();                                      //消除回车键影响
	i=find_name(t,n,s);								//调用find_name函数，得到一个整数
	if(i>n-1)										//如果整数i值大于n-1，说明没找到
		printf("没有姓名为%s的学生！\n",s);
	else
		print_one(t[i]);								//找到，调用显示函数显示记录
 }


//查找学号记录
void search_no(STUDENTS t[],int n)
{
    char no[20];                                    //保存待查找学号
	int i;											//保存查找到该结点的序号
	system("cls");
	printf("*************************** 按学号查找 ***************************\n");
	printf("                                                                  \n");
	printf("请输入查找的学号：\n");
	scanf("%s",no);									    //输入待查找学号
	getchar();                                          //消除回车键影响
	i=find_no(t,n,no);								    //调用find_no函数，得到一个整数
	if(i>n-1)										    //如果整数i值大于n-1，说明没找到
		printf("没有学号为%s的学生！\n",no);
	else
		print_one(t[i]);								//找到，调用显示函数显示记录
}


//按姓名删除函数，参数为记录数组和记录条数
int del_name(STUDENTS t[],int n)
{
	char s[20];											//要删除记录的姓名
	int i;
	printf("请输入要删除的学生姓名：\n");
	scanf("%s",s);										//输入姓名
	getchar();
	i=find_name(t,n,s);									//调用find_name函数
	if(i==n)
		printf("没有找到名字为%s的学生！\n",s);
	else
	{
		printf("正在删除中...\n");
		for(;i<n;i++)   								//从删除位置开始依次前移学生记录
		{
			strcpy(t[i].name,t[i+1].name);
			strcpy(t[i].no,t[i+1].no);
			strcpy(t[i].sex,t[i+1].sex);
			t[i].age=t[i+1].age;
			t[i].score=t[i+1].score;
		}
		n--;											//删除后记录数n减1
		printf("删除成功！\n");
	 }
	 return n;											//返回记录数
 }


//按学号删除函数，参数为记录数组和记录条数
int del_no(STUDENTS t[],int n)
{
    char no[20];					    				//要删除记录的学号
	int i;
	printf("请输入要删除的学生学号：\n");
	scanf("%s",no);										//输入学号
	getchar();
	i=find_no(t,n,no);									//调用find_no函数
	if(i==n)
		printf("没有找到学号为%s的学生！\n",no);
	else
	{
		printf("正在删除中...\n");
		for(;i<n;i++)   								//从删除位置开始依次前移学生记录
		{
			strcpy(t[i].name,t[i+1].name);
			strcpy(t[i].no,t[i+1].no);
			strcpy(t[i].sex,t[i+1].sex);
			t[i].age=t[i+1].age;
			t[i].score=t[i+1].score;
		}
		n--;											//删除后记录数n减1
		printf("删除成功！\n");
	 }
	 return n;											//返回记录数
}


//插入记录函数，参数为结构体数组和记录数
int add(STUDENTS t[],int n)
{
	STUDENTS temp;											//新插入记录信息
	int i,j;
	char s[20];												//确定插入在哪个记录之前
	system("cls");                                          //清屏函数
	printf("请输入要插入的学生记录：\n");
	printf("******************************************************************\n");
	printf("学号                姓名                性别      年龄      分数\n");
	printf("------------------------------------------------------------------\n");
	scanf("%s %s %s %d %f",&temp.no,&temp.name,&temp.sex,&temp.age,&temp.score);	//插入输入信息
	getchar();
	printf("------------------------------------------------------------------\n");
	if(n>0)
	{
		printf("请输入插入位置的姓名，将新纪录插入在该名字前：\n");
		scanf("%s",&s);										//输入插入位置的姓名
		getchar();
		i=find_name(t,n,s);									//调用find_name,确定插入位置
	}
	else
		i=0;
	for(j=n-1;j>=i;j--)										//从最后一个结点开始向后移动一条
	{
															//当前记录拷贝到后一条
		strcpy(t[j+1].no,t[j].no);
		strcpy(t[j+1].name,t[j].name);
		strcpy(t[j+1].sex,t[j].sex);
		t[j+1].age=t[j].age;
		t[j+1].score=t[j].score;
	 }
	//将新插入记录拷贝到第i个位置
	strcpy(t[i].no,temp.no);
	strcpy(t[i].name,temp.name);
	strcpy(t[i].sex,temp.sex);
	t[i].age=temp.age;
	t[i].score=temp.score;
	n++;                                                    //记录数n加1
	printf("\n\t插入成功！\n");
	getchar();
	return n;												//返回记录数
 }


//保存函数，参数为结构体数组和记录数
void save(STUDENTS t[],int n)
{
	int i;
	FILE *fp;											//指向文件的指针
	if((fp=fopen("record.txt","wb"))==NULL)				//打开文件，并判断打开是否正常
	{
		printf("无法打开学生记录文件！\n");					//打开失败
		return; 											//退出
	 }
	printf("\n学生信息正在保存中......\n");
	fprintf(fp,"%d",n);									//将记录数写入文件
	fprintf(fp,"\r\n");									//将换行符号写入文件
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%-20s%-30s%-10s%-10d%-5.2f",t[i].no,t[i].name,t[i].sex,t[i].age,t[i].score);//格式写入记录
		fprintf(fp,"\r\n");								//将换行符号写入文件
	 }
	fclose(fp);
	int j;                                        //关闭文件
	for(j = 0; j < 30; j++)                         //输出保存动效
    {
        printf(">");
        Sleep(50);
    }
    printf("\n学生信息保存成功！\n");		//显示保存成功
 }


//读入函数，参数为结构体数组
int load(STUDENTS t[])
{
	int i,n;
	FILE *fp;												//指向文件的指针
	if((fp=fopen("record.txt","rb"))==NULL)					//打开文件
	{
		printf("无法打开学生记录文件！\n");					//打开失败
		return -1; 											//退出
	 }
	fscanf(fp,"%d",&n);										//读入记录数
	for(i=0;i<n;i++)
		fscanf(fp,"%20s%30s%10s%10d%5f",t[i].no,t[i].name,t[i].sex,&t[i].age,&t[i].score);//按格式读入记录
	fclose(fp);												//关闭文件
	printf("\n学生信息正在加载中......\n");                               //输出提示
	int j;
	for(j = 0; j < 30; j++)                             //输出保存动效
    {
        printf(">");
        Sleep(50);
    }
	printf("\n已经成功加载学生记录文件到内存！\n");			//显示保存成功
	system("pause");
	return n;												//返回记录数
}


//按序号显示记录函数
void display(STUDENTS t[],int n)
{
	int id;
	printf("请输入序号：\n");
	scanf("%d",&id);										//输入序号
	getchar();
	if(id>=1&&id<n+1)											//判断序号是否在记录范围内
	{
		print_one(t[id-1]);										//调用输出函数显示该记录
		printf("\r\n");
	 }
	else
		printf("序号为%d的学生不存在！\n",id);					//如果序号超出范围时提示信息
 }


//按姓名排序函数，参数为结构体数组和记录数
void sort_name(STUDENTS t[],int n)
{
    //冒泡排序法
	int i,j;
	STUDENTS temp;										    //临时变量用于交换数据
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-j;j++)
		if((strcmp(t[j].name,t[j+1].name))>0)				//比较大小
		{
			temp=t[j];
			t[j]=t[j+1];
			t[j+1]=temp;
		 }
	 }
	printf("******** 排序成功！********\n");					//显示排序成功
 }


//按学号排序函数，参数为结构体数组和记录数
void sort_no(STUDENTS t[],int n)
{
    //冒泡排序法
    int i,j,flag;
	STUDENTS temp;										    //临时变量用于交换数据
	for(i=0;i<n-1;i++)
	{
		flag=0;												//设置标志判断是否发生交换
		for(j=0;j<n-1-j;j++)
		if((strcmp(t[j].no,t[j+1].no))>0)				//比较大小
		{
			temp=t[j];
			t[j]=t[j+1];
			t[j+1]=temp;
			flag++;
		 }
		if(flag==0)		break;								//如果标志为0，说明没有发生过交换，循环结束
	 }
	printf("******** 排序成功！********\n");					//显示排序成功
}


//复制文件
void copy()
{
	char outfile[20];										//目标文件名
	int i,n;
	STUDENTS temp[M];										//定义临时变量
	FILE *sfp,*tfp;											//定义指向文件的指针
	system("cls");                                          //清屏
	if((sfp=fopen("record.txt","rb"))==NULL)				//打开学生记录文件
	{
		printf("无法打开学生记录文件！\n");					//打开失败
		return;											//退出
	 }
	printf("请输入目标文件名，形如c:\\f1\\te.txt:\n");
	scanf("%s",outfile);									//输入目标文件名
	getchar();
	if((tfp=fopen(outfile,"wb"))==NULL)						//打开目标文件
	{
		printf("无法打开目标文件！\n");						//打开失败
		return; 											//退出
	 }
	fscanf(sfp,"%d",&n);									//读出文件记录数
	fprintf(tfp,"%d",n);									//写入文件记录数
	fprintf(tfp,"\r\n");									//写入换行符
	for(i=0;i<n;i++)
	{
		fscanf(sfp,"%20s%30s%10s%10d%5f\n",temp[i].no,temp[i].name,temp[i].sex,&temp[i].age,&temp[i].score);//读入记录
		fprintf(tfp,"%-20s%-30s%-10s%-10d%5f",temp[i].no,temp[i].name,temp[i].sex,temp[i].age,temp[i].score);//写入记录
		fprintf(tfp,"\r\n");								//写入换行符
	 }
	fclose(sfp);											//关闭源文件
	fclose(tfp);											//关闭目标文件
	printf("正在复制文件中......\n");                       //输出提示
	int j;
	for(j = 0; j < 30; j++)                             //输出复制动效
    {
        printf(">");
        Sleep(50);
    }
	printf("\n已经成功复制学生记录到目标文件！\n");			//显示复制成功
}


//显示指定的一条记录
void print_one(STUDENTS temp)
{
    printf("------------------------------------------------------------------\n");
	printf("学号                姓名                性别      年龄      分数\n");
	printf("------------------------------------------------------------------\n");
	printf("%-20s%-20s%-10s%-10d%-5.2f\n",temp.no,temp.name,temp.sex,temp.age,temp.score);
	printf("------------------------------------------------------------------\n");
 }


//按姓名查找函数，参数为记录数组和记录条数以及姓名
int find_name(STUDENTS t[],int n,char *s)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(s,t[i].name)==0)				//记录中的姓名和待比较的姓名是否相同
		return i;								//相等，则返回该记录的下标号，程序提前结束
	}
	return i;									//返回i值
}


//按学号查找函数，参数为记录数组和记录条数以及记录学号no
int find_no(STUDENTS t[],int n,char *no)
{
	int i;
	for(i=0;i<n;i++)						//从第一条记录开始，直到最后一条
	{
		if(strcmp(no,t[i].no)==0)			//记录中的学号和待比较的学号是否相同
		return i;							//相等，则返回该记录的下标号，程序提前结束
	 }
	return i;								//返回i值
}


//修改函数，按照输入姓名修改
void modify_name(STUDENTS t[],int n)
{
    char s[20];								//要修改记录的学号
	int i;                                  //保存找到的下标
	system("cls");
	printf("*************************** 按姓名修改 ***************************\n");
	printf("                                                                  \n");
	printf("请输入要修改的学生姓名：\n");
	scanf("%s",&s);								//输入姓名
	getchar();
	i=find_name(t,n,s);							//调用find_no函数
	if(i==n)
		printf("没有找到姓名为%s的学生！\n",s);
	else
	{
		printf("学号为%s的学生修改前：\n",s);
		print_one(t[i]);
		printf("请输入修改后学生记录:\n");
		printf("学号                姓名                性别      年龄      分数\n");
		printf("------------------------------------------------------------------\n");
		scanf("%s",t[i].no);getchar();
		scanf("%s",t[i].name);getchar();
		scanf("%s",t[i].sex);getchar();
		scanf("%d",&t[i].age);getchar();
		scanf("%f",&t[i].score);getchar();
        printf("\n\n************* 修改成功！*************\n\n");
		printf("学号为%s的学生修改后的信息为：\n",s);
		print_one(t[i]);
	}
}


//修改函数，按照输入学号修改
void modify_no(STUDENTS t[],int n)
{
	char no[20];								//要修改记录的学号
	int i;                                      //保存找到的下标
	system("cls");
	printf("*************************** 按学号修改 ***************************\n");
	printf("                                                                  \n");
	printf("请输入要修改的学生学号：\n");
	scanf("%s",no);								//输入学号
	getchar();
	i=find_no(t,n,no);							//调用find_no函数
	if(i==n)
		printf("没有找到学号为%s的学生！\n",no);
	else
	{
		printf("学号为%s的学生修改前：\n",no);
		print_one(t[i]);
		printf("请输入修改后学生记录:\n");
		printf("学号                姓名                性别      年龄      分数\n");
		printf("------------------------------------------------------------------\n");
		scanf("%s",t[i].no);getchar();
		scanf("%s",t[i].name);getchar();
		scanf("%s",t[i].sex);getchar();
		scanf("%d",&t[i].age);getchar();
		scanf("%f",&t[i].score);getchar();
        printf("\n\n************* 修改成功！*************\n\n");
		printf("学号为%s的学生修改后的信息为：\n",no);
		print_one(t[i]);
	}
}


//退出函数,使程序退出并保存信息
void quit(STUDENTS t[],int n)
{
    save(t,n);
    Sleep(50);
    puts("\n您已经成功退出本系统，欢迎再次使用！！！");
    system("pause");
    exit(0);
}


//关于系统函数
void aboutSystem()
{
    system("cls");
    SYSTEMTIME sys;             //设置时间变量
    GetLocalTime(&sys);         //获取系统当前时间
    printf("**************************** 关于系统 ****************************\n");
    printf("|                                                                |\n");
    printf("|                                                                |\n");
    printf("|                                                                |\n");
    printf("|                         学生信息管理系统                       |\n");
    printf("|                                                                |\n");
    printf("|                           作者：Soarkey                         |\n");
    printf("|                         班级：XXXXXXXXXX                      |\n");
    printf("|                                                                |\n");
    printf("|              Copyright ◎ 2016 StudentManagerSystem            |\n");
    printf("|                        All Rights Reserved                     |\n");
    printf("|                                                                |\n");
    printf("|                                                                |\n");
    printf("|          ");
    printf("今天是   %4d年%2d月%2d日  星期%d  %2d时%2d分%2d秒",sys.wYear,sys.wMonth,sys.wDay,sys.wDayOfWeek,sys.wHour,sys.wMinute,sys.wSecond);
    printf("            |\n");
    printf("|                                                                |\n");
    printf("******************************************************************\n");
}


//主函数
int main()
{
    system("title 学生信息管理系统");                   //设置窗口标题
    system("mode con cols=67 lines=32");                //设置窗口大小
    system("color F9");                                 //设置窗口颜色(前景色为淡蓝色，背景色为白色)
	STUDENTS stu[M];									//定义结构体数组
	int length;											//保存记录长度
	welcome();                                          //欢迎函数
	length=load(stu);                                   //加载文件到内存
	for(;;)												//无限循环
	{
		system("cls");									//清屏
		switch(menu_select())							//调用主菜单函数，返回值作为开关语句的条件
		{
			case 0:length=enter(stu,length);break;		//输入记录
			case 1:list(stu,length);break;				//显示全部记录
			case 2:search_name(stu,length);break;		//按姓名查找记录
			case 3:search_no(stu,length);break;         //按学号查找记录
			case 4:length=del_name(stu,length);break;	//按姓名删除记录
			case 5:length=del_no(stu,length);break;     //按学号删除记录
			case 6:modify_name(stu,length);break;       //按姓名修改记录
			case 7:modify_no(stu,length);break;			//按学号修改记录
			case 8:length=add(stu,length);break;		//插入记录
			case 9:display(stu,length);break;			//按序号显示记录
			case 10:sort_name(stu,length);break;		//按姓名排序
			case 11:sort_no(stu,length);break;          //按学号排序
			case 12:copy();break;						//复制文件到目标文件
			case 13:quit(stu,length);break;             //程序结束,并保存信息
			case 14:aboutSystem();break;                //关于系统
        }
		printf("按回车键返回菜单...\n");				//提示信息
		getchar();                                      //消除回车键
	 }
	return 0;
 }
