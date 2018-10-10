#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int testNum;              //��Ŀ����
int num1,num2,num3;       //��������
int result;               //����������ȷ��
int userAnswer;           //�û���
int score = 0;            //�û��ش���ȷ����
int operator1,operator2;  //�����

void inputTestNum();       //��ȡ��Ŀ����
void test();               //��Ŀ
void Answer(int result);   //��ȡ�û���
void randomNumber();       //�������1~99������
void randomOperator();     //�������1~4������
void resultCheck(int ret); //�жϲ������Ƿ��Ǹ���
int main()
{
    inputTestNum();
    printf("\n");
    test();
    printf("��ȷ�ʣ�%d%%",score*100/testNum);
}

/*
  ��ȡ�û��������Ŀ����
*/
void inputTestNum()
{
    int ret;
    printf("��������Ŀ����(>0):");
    ret = scanf("%d",&testNum);
    while(ret!=1 || testNum<=0)
    {
        while(getchar()!='\n');//   ��ռ��̻�����
        printf("��������ȷ����Ŀ����(>0):");
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
            //��һ�������Ϊ'+'
            case 1:
            switch(operator2)
            {
                case 1://�ڶ��������Ϊ'+'
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

            //��һ�������Ϊ'-'
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

            //��һ�������Ϊ'*'
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

            //��һ�������Ϊ'/'
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
      printf("������𰸣�");
      scanf("%d",&userAnswer);
      if(result == userAnswer){
          printf("�ش���ȷ��\n");
          score++;
      }

      else
          printf("�ش������ȷ���ǣ�%d\n",result);
      printf("\n");
 }
