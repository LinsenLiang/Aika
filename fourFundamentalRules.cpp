#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int testNum;              //题目个数
int num1,num2,num3;       //四则运算
int result;               //四则运算正确答案
int userAnswer;           //用户答案
int score = 0;            //用户回答正确个数
int operator1,operator2;  //运算符

void inputTestNum();       //获取题目个数
void test();               //题目
void Answer(int result);   //获取用户答案
void randomNumber();       //随机产生1~99的整数
void randomOperator();     //随机产生1~4的整数
void resultCheck(int ret); //判断产生答案是否是负数
int main()
{
    inputTestNum();
    printf("\n");
    test();
    printf("正确率：%d%%",score*100/testNum);
}

/*
  获取用户输入的题目个数
*/
void inputTestNum()
{
    int ret;
    printf("请输入题目个数(>0):");
    ret = scanf("%d",&testNum);
    while(ret!=1 || testNum<=0)
    {
        while(getchar()!='\n');//   清空键盘缓冲区
        printf("请输入正确的题目个数(>0):");
        ret = scanf("%d",&testNum);
    }
}

void test()
{
    int i;
    int div;
    srand(time(NULL));
    for(i=0;i<testNum;i++)
    {
        randomNumber();
        randomOperator();
        switch(operator1)
        {
            //第一个运算符为'+'
            case 1:
            switch(operator2)
            {
                case 1://第二个运算符为'+'
                    result = num1+num2+num3;
                    printf("%d + %d + %d = \n",num1,num2,num3);
                    Answer(result);

                break;

                case 2:
                    result = num1+num2-num3;
                    resultCheck(result);
                    result = num1+num2-num3;
                    printf("%d + %d - %d = \n",num1,num2,num3);
                    Answer(result);
                break;

                case 3:
                     result = num1+num2*num3;
                     printf("%d + %d * %d = \n",num1,num2,num3);
                    Answer(result);
                break;

                case 4:
                    result = num1+num2/num3;
                    printf("%d + %d / %d = \n",num1,num2,num3);
                    Answer(result);
                break;

            }
            break;

            //第一个运算符为'-'
            case 2:
            switch(operator2)
            {
                case 1:
                    result = num1-num2+num3;
                    resultCheck(result);
                    result = num1-num2+num3;
                    printf("%d - %d + %d = \n",num1,num2,num3);
                    Answer(result);

                break;

                case 2:
                    result = num1-num2-num3;
                    resultCheck(result);
                    result = num1-num2-num3;
                    printf("%d - %d - %d = \n",num1,num2,num3);
                    Answer(result);
                break;

                case 3:
                     result = num1-num2*num3;
                     resultCheck(result);
                     result = num1-num2*num3;
                     printf("%d - %d * %d = \n",num1,num2,num3);
                     Answer(result);
                break;

                case 4:
                    result = num1-num2/num3;
                    resultCheck(result);
                    result = num1-num2/num3;
                    printf("%d - %d / %d = \n",num1,num2,num3);
                    Answer(result);
                break;

            }
            break;

            //第一个运算符为'*'
            case 3:
            switch(operator2)
            {
                case 1:
                    result = num1*num2+num3;
                    printf("%d * %d + %d = \n",num1,num2,num3);
                   Answer(result);

                break;

                case 2:
                    result = num1*num2-num3;
                    resultCheck(result);
                    result = num1*num2-num3;
                    printf("%d * %d - %d = \n",num1,num2,num3);
                    Answer(result);
                break;

                case 3:
                     result = num1*num2*num3;
                     printf("%d * %d * %d = \n",num1,num2,num3);
                     Answer(result);
                break;

                case 4:
                    result = num1*num2/num3;
                    printf("%d * %d / %d = \n",num1,num2,num3);
                    Answer(result);
                break;

            }
            break;

            //第一个运算符为'/'
            case 4:
            switch(operator2)
            {
                case 1:
                    result = num1/num2+num3;
                    printf("%d / %d + %d = \n",num1,num2,num3);
                    Answer(result);

                break;

                case 2:
                    result = num1/num2-num3;
                    resultCheck(result);
                    result = num1/num2-num3;
                    printf("%d / %d - %d = \n",num1,num2,num3);
                    Answer(result);
                break;

                case 3:
                     result = num1/num2*num3;
                     printf("%d / %d * %d = \n",num1,num2,num3);
                     Answer(result);
                break;

                case 4:
                    result = num1/num2/num3;
                    printf("%d / %d / %d = \n",num1,num2,num3);
                    Answer(result);
                break;

            }
            break;

        }
    }
}


void randomNumber()
{
    num1 = rand()%99+1;
    num2 = rand()%99+1;
    num3 = rand()%99+1;
}

void randomOperator()
{
    operator1 = rand()%4+1;
    operator2 = rand()%4+1;
}

void resultCheck(int ret)
{
    while(ret<0)
    {
         randomNumber();
    }
}

void Answer(int result)
{
      printf("请输入答案：");
      scanf("%d",&userAnswer);
      if(result == userAnswer){
          printf("回答正确！\n");
          score++;
      }

      else
          printf("回答错误！正确答案是：%d\n",result);
      printf("\n");
 }
