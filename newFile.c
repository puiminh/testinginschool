#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


const int MAX = 5000;
 
char* toLower(char* s) {
  for(char *p=s; *p; p++) *p=tolower(*p);
  return s;
}
int isNumber(char s[])
{
    for (int i = 0; s[i]!= '\0'; i++)
    {
        if (isdigit(s[i]) == 0)
              return 0;
    }
    return 1;
}
int isNotString(char s[])
{
    for (int i = 0; s[i]!= '\0'; i++)
    {
        if (isalpha(s[i]) == 0)
              return i;
    }
    return -1;
}
int main()
{
   int n=0,n2=0, a=0, a2=0,i, j;
   FILE *fptr, *fptr2;
   char s[100];

   char list[MAX][100];
   char stop[MAX][100];
   int count[MAX];
   int where[MAX][100];
   int unique[MAX];
   int bl=0,check,end,start,chudaudoan=1;
   int zzz;
   for (i=0; i<MAX; i++){ 
        count[i] = 1;
    }
   if ((fptr = fopen("./vanban.txt","r")) == NULL){
       printf("Error! opening vanban.txt file da bi loi");
 
       // Program exits if the file pointer returns NULL.
       exit(1);
   }
   if ((fptr2 = fopen("./stopw.txt","r")) == NULL){
       printf("Error! opening stopw.txt file da bi loi");
 
       // Program exits if the file pointer returns NULL.
       exit(1);
   }
 
 //Home:

    printf("stop array: \n");
    while(1){
        a2 = fscanf(fptr2,"%s", s);
        if ((a2 == EOF) || (n2>=MAX)) break;
	 printf("[%s] number %d\n", s, n2);        
        strcpy (stop[n2],s);
        n2++;
    }

    while(1){

        a = fscanf(fptr,"%s", s);
        if ((a == EOF)||(n>=MAX)) break;
        // printf("%s number %d\n", s, n);
        check=0;
        
        
        
        if (isupper(s[0])) {
        
        	printf("Phat hien tu %s co chu cai dau in hoa",s);
        
        	if ((end==1) || (chudaudoan==1)) {
        		printf(" ,nhung la tu cuoi cau (hoac dau doan) => pass\n");
        		chudaudoan=0;
        	}
        	else {
        		printf(" , nhung khong phai tu cuoi cau => TEN RIENG (X)\n");
        		check=-2;
        	}
        }
	end=0;
        if (s[strlen(s)-1]=='.') {
        	printf("\nPhat hien cuoi cau, end=1\n");
        	end=1;
        }
        if ((s[strlen(s)-1]=='.')||(s[strlen(s)-1]==',')) 
        	{
        		s[strlen(s)-1]='\0';
        		printf("\nPhat hien dau cham cau, loai bo -> %s\n",s);
        	}
        if (isNotString(s)!=-1) {
        	printf("\nX: Phat hien ky tu: {%c} khong hop le, loai bo tu [%s] (X)\n",s[isNotString(s)],s);
        	check=-2;
        }

	if (isNumber(s)) 
        	{
        		printf("Phat hien tu [%s], vi tri %d la number (X)\n\n",s,n);
        		check=-2;
        	} 	
        strcpy (list[n],toLower(s));
        

        for (j=0; j<n2; j++)
        	if (strcmp(toLower(s),toLower(stop[j]))==0) {
        		printf("\nX: Phat hien tu [%s], vi tri %d la tu bi cam (X)\n\n",s,n);
        		check=-2;
        		break;
        	}
 	
        if (check!=-2)
        {
		for(i = 0; i < n; i++){            
		    
		    if (strcmp (list[i],toLower(s)) == 0) {
		    printf("Phat hien giong nhau giua tu [%s] va list[%d]: %s, count[%d] + 1", list[i], i, list[i], i);
		    count[i]++;
		    printf(", count[%d] hien tai la %d\n",i,count[i]);
		    check=1;
		    printf("Set where[%s] + them vi tri moi phat hien: %d\n",list[i],n-1);
		    where[i][count[i]-1]= n;
		    }
		}
		if (check==0){
		    unique[bl] = n;
		    printf("\nPhat hien tu [%s] chua xuat hien bao gio, them vao unique[%d] gia tri: %d\n",list[n], bl, unique[bl]);
		    where[n][0]= n;
		    printf("Set where[%s] cho chinh vi tri hien tai: %d\n",list[n],n);
		    bl++;   
		}
        } else {
        	
        }
        n++;
         
    }
    printf("Unique: ");
    for (int i=0; i<bl ; i++){
        printf("%d ", unique[i]);
    }
    printf("\n");


    //Print the original list
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j< bl; j++)
    //         if(unique[j]==i) {
    //                 printf("list[%d]: [%s] count=%d", i, list[i], count[i]);
    //                 printf(" where: ");
    //                 for(int k=0; k<count[i]; k++){
    //                     printf("%d, ", where[i][k]);
                        
    //                 }
    //                 printf("\n");
    //             break;
    //         } 
            
            
    //     }
        

      char list3[MAX][bl];
      for (i=0; i<bl; i++){
      	 strcpy(list3[i],list[unique[i]]);
      }
      
  	char t[100],w[100];
  	
  	int u;
     for (i = 1; i < n; i++) {
      for (j = 1; j < n; j++) {
         if (strcmp(list3[j - 1], list3[j]) > 0) {
         
            strcpy(t, list3[j - 1]);
            strcpy(list3[j - 1], list3[j]);
            strcpy(list3[j], t);
         }
      }
   }
       printf("\n");
       
    int unique2[MAX], u2=0;
    int khonginnua=0;
    
    printf("\n");
    printf("\n");
    //for (int i=0; i<n; i++) 
    	//printf("%s ", list3[i]);


    printf("Order list: \n");	
    	
    for(int j = 0; j<n; j++){
    	for(int i = 0; i < bl; i++)
    	     {
	    	     	    if(strcmp(list3[j],list[unique[i]])==0) 
	    	     	    {
				    printf("[%s] count=%d", list[unique[i]], count[unique[i]]);
				    printf(" where: ");
				    for(int k=0; k<count[unique[i]]; k++){
				        printf("%d, ", where[unique[i]][k]);
				        
				    }
				    printf("\n");

		            }
                    } 
            
    } 
                
        
   fclose(fptr); 
  
   return 0;
}
