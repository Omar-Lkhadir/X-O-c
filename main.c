#include <stdio.h>
#include <stdlib.h>
int plan(int t[][3]){
    printf("\n          --------\n");
    for (int i=0;i<3;i++){
        printf("          ");
        for(int j=0;j<3;j++){
            printf("|");
            if(t[i][j]==0)
                printf(" ");
            if(t[i][j]==1)
                printf("X");
            if(t[i][j]==2)
                printf("O");
        }
        printf("|\n          --------\n");
    }
    return plan;
}
int test_gagnat(int t[][3]){
    for (int i=0;i<3;i++){
       if(t[i][0]==t[i][1] && t[i][0]==t[i][2] && t[i][0]!=0)
            return 1;

    }
    for(int i=0;i<3;i++){
       if(t[0][i]==t[1][i] && t[0][i]==t[2][i] && t[0][i]!=0)
            return 1;
       }
    if(t[0][0]== t[1][1] &&  t[0][0] == t[2][2] && t[0][0]!=0 )
        return 1;
    if(t[0][2]==t[1][1] && t[0][2]==t[2][0]  && t[0][2]!=0 )
        return 1;



    return 0;



}



int main()
{
    int t[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    plan(t);
    int l,c,test=0,choix,r;
    do{
            for(int i=1;i<=2 && i!=9 ;i++){
                do{
                    printf("\n joueure NR : %d \n",i);
                    do{
                        printf("entrer le NR de ligne (1,2 ou 3) : ");
                        scanf("%d",&l);
                    }while( l != 1 && l != 2 && l != 3);
                    do{
                        printf("entrer le NR de colonne (1,2 ou 3) : ");
                        scanf("%d",&c);
                    }while( c != 1 && c != 2 && c != 3);
                    if(t[l-1][c-1]==0){
                        t[l-1][c-1]=i;
                        test++;
                        choix = 0;
                    }else{
                        printf("\n autre choix s'il vous plait !!!\n");
                        choix = 1;
                    }
                }while(choix == 1);
                plan(t);
                if(test_gagnat(t)==1){
                    printf("\n ##~{[|[|`\`|`\`\{           %d est le gangnat dans ce matche            }{#{[|`\|`\\^~#~#{~#{#{~{\n  ",i);
                }

            }




    }while(test <9);




    return 0;
}
