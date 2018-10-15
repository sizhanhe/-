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
    //��ȡ��Ŀ��
    scanf("%d",&n);

    srand((unsigned int)time(NULL));
    for(i=1;i<=n;i++){
        lab1:

        //�������������
        oneNum = rand()%100;
        twoNum = rand()%100;
        threeNum = rand()%100;

        //������������
        firstSymbol = rand()%4;
        secondSymbol = rand()%4;

        //�ж���������ȼ�
        if(firstSymbol < secondSymbol ){
            sum = operation(twoNum,threeNum,secondSymbol);
            sum = operation(oneNum,sum,firstSymbol);
        }else{
            sum = operation(oneNum,twoNum,secondSymbol);
            sum = operation(sum,threeNum,firstSymbol);
        }

        //������Ƿ�Ϊ������������������
        if(sum <= 0) goto lab1;

        //��ӡ����Ŀ
        printf("%d %c %d %c %d = ",oneNum,Symbol(firstSymbol),twoNum,Symbol(secondSymbol),threeNum,sum);

        //�ȶԴ��Ƿ���ȷ
        scanf("%f",&answer);
        if((int)(100*sum+0.5)/100 == (int)(100*answer+0.5)/100){
            printf("�ش���ȷ������\n");
            right++;
        }else{
            printf("�ش���󣡣�����ȷ����%.2f\n",((100*sum+0.5)/100));
        }
    }

    //��ӡ�����ս��
    printf("���β��Թ���%d���⣬���Ե���%d��,�������%d��׼ȷ����%.2f\n",n,right,n-right,(float)right/n);
    printf("��������hsz������ʲô������ָ����~~~\n")
    getc();
}

void menu(){
    printf("\t\t******************************************\n");
    printf("\t\t*               ������������             *\n");
    printf("\t\t******************************************\n\n");
    printf("��Ҫ�����ٵ�����������Ŀ��");
}

/*
��������opreation
�������ܣ�����+��-��*��/����
������a��b��������symbol�������
����ֵ�������� sum
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
��������Symbol
���ܣ��������ת��Ϊ��Ӧ���������
������numSymbol
����ֵ��symbol
*/
char Symbol(int numSymbol){
    char symbol;
    if(numSymbol == 0) symbol = '+';
    else if (numSymbol == 1) symbol = '-';
    else if (numSymbol == 2) symbol = '*';
    else symbol = '/';
    return symbol;
}
