#include <stdio.h>
/*
 *Author:junstrix@gmail.com
 *Blog:http://imljp.info
 *Email:junstrix@gmail.com
 *Data:2011-3-6
 */
#define LANGUAGE 1     /* Set system language:0=>English 1=>chinese */
#define SYSTEM_CLEAR system("clear")  	/* system() ,Linux use "clear" and windows use "cls"  */

void print_minus(void)
{
  int i;
  for (i = 0 ; i < 58; ++i)
    {
      printf ("-");
    }
  printf ("\n");
}

void DataTypeLength(void)	/* test system Data Type Length */
{
  print_minus();
  #if LANGUAGE
  printf ("各种数据类型长度：\n");
  #else
  printf ("This is data type length about system\n");
  #endif
  printf ("\n");
  printf ("sizeof(char)   = %d\n",sizeof(char));
  printf ("sizeof(short)  = %d\n",sizeof(short));
  printf ("sizeof(int)    = %d\n",sizeof(int));
  printf ("sizeof(float)  = %d\n",sizeof(float));
  printf ("sizeof(long)   = %d\n",sizeof(long));
  printf ("sizeof(double) = %d\n",sizeof(double));
}

void Sys_Endian(void)		/* Test endian in system is litter or big  */
{
  int x = 0x11223344;
  char * y = (char *) &x;
  char z;
  z = x & *y;
  //  printf ("z = 0x%x\n",z);
  printf ("\n");
  #if LANGUAGE
  printf ("系统Endian:\n\n");
  #else
  printf ("The system Endian is:\n\n");
  #endif
  if (z == 0x44)
    {
      printf ("\t\tLitter Endian\n\n");
    }
  else
    printf ("\t\tBig Endian\n\n");
}

int Cal_Age(void)		/* Caculate your age */
{
  int birthyear,birthmon;	/* 出生年月 */
  int current_year,current_mon; /* 目前年月 */
  int age_year,age_mon;			  /* 年龄 */
  int cal_select = 0;
  int num_right = 0;
  while(1)
    {
      printf ("input your birthyear and birthmonth. e.g:1990 07\n");
    re_birmon:      scanf("%d %d",&birthyear,&birthmon); /* error!! use :goto re_input birthmonth */
      if (birthmon > 12 || birthmon < 1)
	{
	  printf ("error:month must be (1 <= month >= 20)\n");
	  printf ("\n");
	  printf ("re_input your birthyear and birthmonth. e.g:1990 07\n");
	  goto re_birmon;
	}
      printf ("your birthyear in %d\n",birthyear);
      printf("your birthmonth in %d\n",birthmon);
      printf ("\n");
      do			/* error: do <- ..... -> while  */
	{
	  printf ("input current year and month. e.g:2011 03\n");
	  scanf("%d %d",&current_year,&current_mon);
	  if (current_year < birthyear || current_mon > 12 || current_mon < 1)
	    {
	      printf ("error: current year must be(current_year > birthyear, 1 <= month <= 12\n");
	    }
	  else
	    num_right = 1;
	} while (num_right == 0);
      SYSTEM_CLEAR;
      if (current_mon > birthmon)
	{
	  age_mon = current_mon - birthmon;
	}
      else
	age_mon = birthmon - current_mon;
      print_minus();
      printf ("your birth  : %d-%d month\n",birthyear,birthmon);
      printf ("Current Data:  %d-%d month\n",current_year,current_mon);
      printf ("your age is %d year %d mon .\n",age_year = current_year - birthyear,age_mon);
      printf ("\n");
      printf ("select number,1=>continue 0=>quit[1/0]:\n");
      scanf("%d",&cal_select);
      switch(cal_select)
	{
	case 1 : SYSTEM_CLEAR;Cal_Age() ;break;
	case 0 : SYSTEM_CLEAR;break;
	}      
      return 0;
    }  
}

int main(int argc, char *argv[])
{
  int select;
  SYSTEM_CLEAR;
  while(1)
    {
      #if LANGUAGE
      printf ("***************** 测试系统信息 ***************************\n");
      printf ("                 1.=>测试系统数据类型长度<=\n");
      printf ("                 2.=>测试系统大端还是小端<=\n");
      printf ("                 3.=>计算你的年龄大小<=\n");
      printf ("                 4.=>冒泡算法处理<=\n");
      printf ("                 0.=> !! 退出 !!<=\n");
      #else
      printf ("***************** Test info about system *****************\n");
      printf ("                 1.=>Test system Data type length<=\n");
      printf ("                 2.=>Test system Endian<=\n");
      printf ("                 3.=>Caculate age<=\n");
      printf ("                 4.=>Maopao <=\n");
      printf ("                 0.=>!! Quit !!<=\n");
      #endif
      print_minus();
      #if LANGUAGE
      printf ("选择数字，进入相应功能[1/2/3/0]\n");
      #else
      printf ("input number[1/2/0]");
      #endif
      scanf("%d",&select);
      switch(select)
	{	 
	case 0 : return 0;
	case 1 : SYSTEM_CLEAR;DataTypeLength();break;
	case 2 : SYSTEM_CLEAR;Sys_Endian();break;
	case 3 : SYSTEM_CLEAR;Cal_Age();break;
	default : ; break;
	}
    }
}
