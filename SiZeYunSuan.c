#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void menu();
char Symbol(int numSymbol);
float operation(int a,int b,int symbol);

main(){
    int n,i;
    int oneNum,twoNum,threeNum;
    int firstSymbol,secondSymbol;
    float sum;
    float answer;
    int right = 0;

    menu();
    //获取题目数
    scanf("%d",&n);

    srand((unsigned int)time(NULL));
    for(i=1;i<=n;i++){
        lab1:

        //随机生成三个数
        oneNum = rand()%100;
        twoNum = rand()%100;
        threeNum = rand()%100;

        //随机生成运算符
        firstSymbol = rand()%4;
        secondSymbol = rand()%4;

        //判断运算符优先级
        if(firstSymbol < secondSymbol ){
            sum = operation(twoNum,threeNum,secondSymbol);
            sum = operation(oneNum,sum,firstSymbol);
        }else{
            sum = operation(oneNum,twoNum,secondSymbol);
            sum = operation(sum,threeNum,firstSymbol);
        }

        //看结果是否为负数，负数重新生成
        if(sum <= 0) goto lab1;

        //打印出题目
        printf("%d %c %d %c %d = ",oneNum,Symbol(firstSymbol),twoNum,Symbol(secondSymbol),threeNum,sum);

        //比对答案是否正确
        scanf("%f",&answer);
        if((int)(100*sum+0.5)/100 == (int)(100*answer+0.5)/100){
            printf("回答正确！！！\n");
            right++;
        }else{
            printf("回答错误！！！正确答案是%.2f\n",((100*sum+0.5)/100));
        }
    }

    //打印出最终结果
    printf("本次测试共有%d道题，做对的有%d道,错误的有%d，准确率是%.2f\n",n,right,n-right,(float)right/n);
    printf("本程序由hsz开发有什么不足请指出来~~~\n")
    getc();
}

void menu(){
    printf("\t\t******************************************\n");
    printf("\t\t*               基础四则运算             *\n");
    printf("\t\t******************************************\n\n");
    printf("你要做多少道四则运算题目：");
}

/*
函数名：opreation
函数功能：进行+、-、*、/运算
参数：a，b运算数，symbol运算符号
返回值：运算结果 sum
*/
float operation(int a,int b,int symbol){
    float sum;

    if(symbol == 0) sum = a+b;
    else if(symbol == 1) sum = a-b;
    else if(symbol == 2) sum = a*b;
    else sum = (float)a/(float)b;

    return (sum);
}

/*
函数名：Symbol
功能：将随机数转换为对应得运算符号
参数：numSymbol
返回值：symbol
*/
char Symbol(int numSymbol){
    char symbol;
    if(numSymbol == 0) symbol = '+';
    else if (numSymbol == 1) symbol = '-';
    else if (numSymbol == 2) symbol = '*';
    else symbol = '/';
    return symbol;
}
