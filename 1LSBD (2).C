#include<graphics.h>
#include<stdio.h>
#include<math.h>
int len;
int x1[500];
int x3[500];
char m5[30];
main()
{
    void func2(char,int);
  int gdriver=VGA,gmode=VGAHI,FLAG=0;
  char psize[80],pval[80];
  char m,ch,y[9],ch1;
  int a1,a2,a3,b1,b2,b3,g,l,k,xy;
  struct palettetype pal;
  int i,j;
  FILE *fp,*fp1;
  initgraph(&gdriver,&gmode,"c:\\borlandc\\bgi");
  getpalette(&pal);
  sprintf(psize, "The palette has %d modifiable entries.", pal.size);
  for(i=0;i<pal.size;i++)
  setrgbpalette(pal.colors[i], i*4,i*4,i*4);
  printf("\n enter the length");
  fp=fopen("z:\\ste\\z1.raw","rb");
  for(i=0;i<200;i++)
  {
     for(j=0;j<200;j++)
     {
    ch=fgetc(fp)/16;
    putpixel(j,i,ch);
     }
  }
  outtextxy(0,210,"RECEIVED IMAGE");
  fclose(fp);
  fp1=fopen("z:\\ste\\z1.raw","rb");
  if(fp1==NULL)
  {
    printf("FILE NOT FOUND");
    getch();
  }
else
{
    FLAG=0;
    g=0;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n the string decoded from the Received image:\t");
     for(i=0;i<200;i++)
      {
	if(FLAG)
	    break;
	else
	{
	    for(j=0;j<200;j++)
	    {
		if(FLAG)
		    break;
		else
		{
		  if(g<8)
		  {
		    ch=fgetc(fp1)/16;
		    func2(ch,g);
		    g++;

		  }
		  if(g==8)
		  {
		    g=0;
		    xy=0;
		    for(l=0,k=7;k>=0;k--,l++)
		    {
			xy=xy+(pow(2,l)*x3[k]);
		    }
		    ch1=xy;
		    if(ch1=='#')
		    {
			FLAG=1;
		    }
		    else
			printf("%c",ch1);
		   }
		   }
	    }
	}
       }
      fclose(fp1);
}
  getch();
}
void func2(char ch,int g)
{
   int x2[8],k,l,j;
   l=ch;
   for(k=7;k>=0;k--)
   {
     x2[k]=l%2;
     l=l/2;
   }
    x3[g]=x2[7];
}
