#include <stdio.h>
#include <stdlib.h>
#include "consoleapi.h"

void shuiping();
void chuizhi();
void zuoqingxie();
void youqingxie();
void jiantou();
void color_stripe()
{
	char a= '0';
    setConsoleWindowSize(80, 45);

	while(a=='0'||a=='1'||a=='2'||a=='3'||a=='4'||a=='5')
	{
        setColor(BLACK, 0, GREEN, 1); //ˢ�»�������ʹ�ּ��ɼ�

		printf("0��ˮƽ�ʴ���\n1����ֱ�ʴ���\n2������б�ʴ���\n3������б�ʴ���\n4����ͷ״�ʴ���\n5��ˮ��״�ʴ���\n���������˳�\n");
		//scanf("%d",&a);
		a = getch();
		//getchar();

		if(a=='0')//ʵ��ˮƽ�ʴ����
		{
			shuiping();
		}
		else if(a=='1')//ʵ�ִ�ֱ�ʴ����
		{
			chuizhi();
		}
		else if(a=='2')//ʵ������б�ʴ����
		{
			youqingxie();
		}
		else if(a=='3')//ʵ������б�ʴ����
		{
			zuoqingxie();
		}
		else if(a=='4')//ʵ�ּ�ͷ״�ʴ����
		{
			jiantou();
		}
		else if(a=='5')//ʵ��ˮ��״�ʴ����
		{
			jiantou();
			jiantou();
		}
		else{
            break;
		}

        fflush(stdin);
	}
}


//ˮƽ�ʴ�����
void shuiping()
{
	int i,j,k;
	for(i=0;i<25;++i)
	{
		for(j=0;j<=79;++j)
		{
			k=i%16;
			SetColor(k,k);
			putchar('A');
		}
	}
}

//��ֱ�ʴ�����
void chuizhi()
{
	int i,j,k;
	for(i=0;i<25;++i)
	{
		for(j=0;j<40;++j)
		{
			k=j%16;
			SetColor(k,k);
			putchar('A');
			putchar('A');
        }

	}
}

//����б�ʴ�����
void youqingxie()
{
	int i,j,k;
	for(i=0;i<25;++i)
	{
		for(j=0;j<40;++j)
		{
			if(j-i>=0)
				k=(j-i)%16;
			else
				k=(j-i)%16+16;
			SetColor(k,k);
			putchar('A');
			putchar('A');
		}
	}
}

//����б�ʴ�����
void zuoqingxie()
{
	int i,j,k;
	for(i=0;i<25;++i)
	{
		for(j=0;j<40;++j)
		{
			k=(i+j)%16;
			SetColor(k,k);
			putchar('A');
			putchar('A');
		}
	}
}

//��ͷ״�ʴ�����
void jiantou()
{
	int i,j,k;
	for(i=0;i<16;++i)
	{
		for(j=0;j<40;++j)
		{
			k=(i+j)%16;
			SetColor(k,k);
			putchar('A');
			putchar('A');
		}
	}
	for(i=0;i<16;++i)
	{
		for(j=0;j<40;++j)
		{
			if(j-i>=0)
				k=(j-i)%16;
			else
				k=(j-i)%16+16;
			SetColor(k,k);
			putchar('A');
			putchar('A');
		}
	}
}
