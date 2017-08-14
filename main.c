#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>


int main()
{
    printf(" \n\n\n \t\t ### GRAFLAR ARASINDAKI EN KISA YOL ###\n\n\n");
    int matris[21][21],adj[21][21],visited[400]={0};
    int node,i,j,x,y,c1,c2,a,b,u,v,ne=1;
    int m=0,n=0,mincost=0;
    int range[100],r=0,k=0;

    allegro_init();
    install_keyboard();
    set_gfx_mode( GFX_AUTODETECT_WINDOWED , 440,440, 0, 0);
    clear_to_color( screen, makecol( 255, 255, 255));

    int xk=-17,yk=0;
    for(i=0;i<=20;i++)
     {
      textprintf_ex(screen ,font ,xk=xk+20,1, makecol( 255, 0, 0),makecol( 60, 60, 100) ,"%d",i);
     }
     for(i=1;i<=20;i++)
     {
      textprintf_ex(screen ,font ,2,yk=yk+20, makecol( 255, 0, 0),makecol( 60, 60, 100) ,"%d",i);
     }

    flag1:
    printf("\tLutfen girilecek maksimum dugum sayisini giriniz : ");
    scanf("%d",&node);
    if(node>400)
    {
        printf("\n\t!! En fazla '400' dugum girebilirsiniz !!\n\n ");
        goto flag1;
    }
    for(i=1;i<=20;i++)
    {
        for(j=1;j<=20;j++)
        {
          matris[i][j]=0;
        }
    }
    for(i=1;i<=node;i++)
    {
        printf("%d.dugumun koordinatlarini giriniz: \n",i);
        flag2:
        printf("    x : ");
        scanf("%d",&x);
        if(x>20 || x<=0)
        {
            printf("!! Gecersiz bir deger girdiniz [1-20] !!\n\n");
            goto flag2;
        }
        flag3:
        printf("    y : ");
        scanf("%d",&y);
        if(y>20 || y<=0 )
        {
            printf("!! Gecersiz bir deger girdiniz [1-20] !!\n\n");
            goto flag3;
        }
        matris[x][y]=1;
    }
          printf("\n");
          printf("\n");

    for(i=1;i<=20;i++)
    {
        printf("\t");
        for(j=1;j<=20;j++)
        {
            printf("%d  ",matris[i][j]);

        }
        printf("\n");
    }

     for(i=1;i<=20;i++)
    {
        for(j=1;j<=20;j++)
        {
          if(matris[i][j]==1)
          {
           rectfill(screen,(j-1)*20+17,(i-1)*20+8,j*20+17,i*20+8,makecol( 100, 100, 0));
          }
        }
    }

 printf("\n\n");

 printf("  *** DUGUMLER ARASI MESAFELER ***\n\n");

  for(i=1;i<=20;i++)
  {
      for(j=1;j<=20;j++)
      {
          if(matris[i][j]==1)
            {
            for(m=1;m<=20;m++)
             {
              for(n=1;n<=20;n++)
                {
                     if(matris[m][n]==1)
                       {
                         c1=abs(m-i);
                         c2=abs(n-j);
                         range[r]=c1+c2;
                         r++;
                         printf("%d-%d' den %d-%d' e mesafe : %d br. \n",i,j,m,n,c1+c2);
                        }
                    }

             }
        printf("-------------------\n");

              }
            }
        }

      printf("\n\n");
      // ağırlık matrisine maliyetleri atıyoruz
      for(i=1;i<=node;i++)
      {
          for(j=1;j<=node;j++)
          {
              adj[i][j]=range[k];
              k++;
          }
      }

      printf("    *** AGIRLIK MATRISI *** \n\n");
    for(i=1;i<=node;i++)
      {
          for(j=1;j<=node;j++)
          {
              if(adj[i][j]==0)
            {
                adj[i][j]=0;
            }
          }
      }
 for(i=1;i<=node;i++)
      {
          printf("\t");
          for(j=1;j<=node;j++)
          {
              printf("%d ",adj[i][j]);
          }
          printf("\n");
      }

int min;
      visited[1]=1;
	while(ne < node)
	{
		for(i=1,min=999;i<=node;i++)
		{
		    for(j=1;j<=node;j++)
            {
                if(adj[i][j]< min)
                {
                    if(visited[i]!=0)
                    {
                        min=adj[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
         if(visited[u]==0 || visited[v]==0)
          {
           printf("\n %d.kenar (%d %d) maliyet: %d br.",ne++,a,b,min);
           mincost+=min;
           visited[b]=1;
          }
		adj[a][b]=adj[b][a]=999;
	}
	printf("\n\n Minimum maliyet: %d br.",mincost);
	printf("\n");
    system("pause");
    return 0;
}
END_OF_MAIN();
