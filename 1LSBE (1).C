#include<graphics.h>
#include<stdio.h>
#include<math.h>
int len;
int x1[500];
int x3[500];
char m5[30];
int main()
{
  char func1(char,int);
  void func2(char,int);
  void func3();
  //VIDEO GRAPHICS ARRAY
  int gdriver=VGA,gmode=VGAHI;
  char psize[80],pval[80];
  char m,ch,y[9];
  int a1,a2,a3,b1,b2,b3,g;
  struct palettetype pal;
  int i,j,k;
  FILE *fp,*fp1;
  initgraph(&gdriver,&gmode,"c:\\borlandc\\bgi");
  getpalette(&pal);
  sprintf(psize, "The palette has %d modifiable entries.", pal.size);
  for(i=0;i<pal.size;i++)
  setrgbpalette(pal.colors[i], i*4,i*4,i*4);
  printf("\n enter the string:\n");
  scanf("%s",m5);
  len=strlen(m5);
  m5[len]='#';
  len=len+1;
  func3();
  fp=fopen("z:\\ste\\sip2.raw","rb");
  fp1=fopen("z:\\ste\\j1.raw","wb");
   for(i=0;i<200;i++)
      {
		  for(j=0;j<200;j++)
	  {
	    ch=fgetc(fp)/16;
	    fputc((ch*16),fp1);
	  }
    }
	fclose(fp);
	fclose(fp1);
  fp=fopen("z:\\ste\\sip2.raw","rb");
  fp1=fopen("z:\\ste\\z1.raw","wb");
  if(fp==NULL)
  {
   printf("FILE NOT FOUND");
   getch();
}
else
{
     g=0;
     for(i=0;i<200;i++)
      {
	  for(j=0;j<200;j++)
	  {
	    ch=fgetc(fp)/16;
	    if(g<(len*8))
	    {
	       ch=func1(ch,g);
	       g++;

	    }
	    fputc((ch*16),fp1);
	  }
    }
	fclose(fp);
	fclose(fp1);
    }
  fp=fopen("z:\\ste\\z1.raw","rb");
  for(i=0;i<200;i++)
  {
     for(j=0;j<200;j++)
     {
     ch=fgetc(fp)/16;
    putpixel(j+300,i,ch);
     }
  }
  outtextxy(350,210,"EMBEDED IMAGE");
  fclose(fp);
  fp=fopen("z:\\ste\\sip2.raw","rb");
  for(i=0;i<200;i++)
  {
    for(j=0;j<200;j++)
    {
    ch=fgetc(fp)/16;
    putpixel(j,i,ch);
    }
  }
  outtextxy(50,210,"ORIGINAL IMAGE");
   getch();
}
 char func1(char ch,int g)
{
   int x2[8],k,l,j;
   l=ch;
   for(k=7;k>=0;k--)
   {
     x2[k]=l%2;
     l=l/2;
   }

   x2[7]=x1[g];
   l=0;
   for(k=0,j=7;k<8;k++,j--)
   {
      l=l+(pow(2,k)*x2[j]);
   }
   ch=l;
   return(ch);
}
void func3()
{
    int i,k,l,j,x2[500],h;
    char ch[30];
    for(i=0;i<len;i++)
    {
    ch[i]=m5[i];
    }
    for(i=0,h=0;i<len;i++)
    {
      for(k=7;k>=0;k--)
	  {
	  x2[k]=ch[i]%2;
	  ch[i]=ch[i]/2;
      }
      for(j=0;j<=7;j++)
      {
	   x1[h++]=x2[j];
      }
     }
     return 0;
}
