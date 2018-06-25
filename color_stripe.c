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
        setColor(BLACK, 0, GREEN, 1); //刷新缓冲区，使字迹可见

		printf("0：水平彩带，\n1：垂直彩带，\n2：右倾斜彩带，\n3：左倾斜彩带，\n4：箭头状彩带，\n5：水纹状彩带，\n其他输入退出\n");
		//scanf("%d",&a);
		a = getch();
		//getchar();

		if(a=='0')//实现水平彩带输出
		{
			shuiping();
		}
		else if(a=='1')//实现垂直彩带输出
		{
			chuizhi();
		}
		else if(a=='2')//实现右倾斜彩带输出
		{
			youqingxie();
		}
		else if(a=='3')//实现左倾斜彩带输出
		{
			zuoqingxie();
		}
		else if(a=='4')//实现箭头状彩带输出
		{
			jiantou();
		}
		else if(a=='5')//实现水纹状彩带输出
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


//水平彩带函数
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

//垂直彩带函数
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

//右倾斜彩带函数
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

//左倾斜彩带函数
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

//箭头状彩带函数
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
