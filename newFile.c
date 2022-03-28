#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
   int n=0, a, i, j;
   FILE *fptr;
  
   char s[100];

   char list[200][100];
   int count[200];
   int where[200][100];
   int unique[200];
   int bl=0,check;
   int zzz;
   for (i=0; i<200; i++){ count[i] = 1;}
   if ((fptr = fopen("/home/SinhVien/Downloads/Ex1/vanban.txt","r")) == NULL){
       printf("Error! opening file");
 
       // Program exits if the file pointer returns NULL.
       exit(1);
   }
 

    while(a != EOF){

        a = fscanf(fptr,"%s", s);
        
        // printf("%s number %d\n", s, n);
        strcpy (list[n],s);
        n++;
        check=0;
        for(i = 0; i < n-1; i++){            
            
            if (strcmp (list[i],s) == 0) {
            printf("Phat hien giong nhau giua tu %s va list[%d]: %s, count[%d] + 1", list[i], i, list[i], i);
            count[i]++;
            printf(", count[%d] hien tai la %d\n",i,count[i]);
            check=1;
            where[i][count[i]-1]= n-1;
            }
        }
        if (check==0){
            unique[bl] = n-1;
            printf("\n Them vao unique[%d] gia tri: %d\n",i, unique[bl]);
            where[n-1][0]= n-1;
            
            bl++;   
        }
         
    }
    for (int i=0; i<bl ; i++){
        printf("%d ", unique[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j< bl; j++)
            if(unique[j]==i) {
                    printf("list[%d]: %s count %d", i, list[i], count[i]);
                    printf(" where: ");
                    for(int k=0; k<count[i]; k++){
                        printf("%d, ", where[i][k]);
                        
                    }
                    printf("\n");
                break;
            } 
            
            
        }
   fclose(fptr); 
  
   return 0;
}