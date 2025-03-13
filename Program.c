
/*
Miar Taweel

*/



#include <stdio.h>
#include <stdlib.h>

//building the structure of the trees' nodes
struct node{
int id;
char name[100];
char city[100];
int classId ;
char date[100] ;
struct node* left;
struct node* right;

};

//defining the pointer to the node as a standard value type
typedef struct node* arrow;

//The prototypes for all functions

arrow find(arrow ,int );

arrow insert(arrow T,int , char [100],char [100],int ,char [100] );

arrow insertName(arrow T,int , char [100],char [100],int ,char [100] );

arrow insertClass(arrow T,int , char [100],char [100],int ,char [100] );

int sum(arrow );

arrow FindMax( arrow  );

arrow FindMin( arrow );

arrow Delete ( int ,arrow );

arrow MakeEmpty(arrow);

void inorderN(arrow );

void inorderC(arrow ,char [100] );

arrow byName(arrow );

arrow byCity(arrow ,char [100]);

arrow byClass(arrow  );

arrow moveNodes(arrow , arrow );

arrow moveNodesN(arrow , arrow );

arrow moveNodesC(arrow, arrow ) ;





int main()
{FILE *file; // declaring and initialising the files pointer

int x=10,size=0,j;//initialising values

file = fopen("students.data.txt", "r");

char a[100][100];//Declaration of array of strings for the given Information from the file

 //Reading the values from the file , placing them in an array of strings
 while (fgets(a[size],100, file) != NULL &&(size<100)){
        size++;
    }

int idd;
int classIdd;
char namee[100];
char address[100];
char datee[100];

//Creating the first node
arrow T;
T=NULL;

 //Moving the information from the array to the tree and printing them on the screen
 if(size==0){
    printf("file is empty");
 }else{
  for(int j=0; j<size; j++){

          sscanf(a[j],"%d %s %s %d %s",&idd,&namee,&address,&classIdd, &datee);
          if(idd!=0){
          printf("\nStudent %d:", j + 1);
          T=insert(T,idd,namee,address,classIdd,datee);
          printf("\nID:%d  Name:%s  City:%s  Class ID:%d  Date:%s\n",idd,namee,address,classIdd, datee);
          }
          arrow L=NULL;


    }}


fclose(file);


//A loop for printing the menu and executing the operations
while(1){
printf("\nPlease Choose one of the following:\n1.Insert a student \n2.Update a student \n3.List all students Based on Their names\n4.Search for a city  \n5.List all students Based their class \n6.Delete a student\n7.Print report to file\n8.Exit\n");
 scanf("%d",&x);



//if conditions for each case(operation) of the menu
//Inserting a student case
if (x==1){
 int d;
 int classD;
 char n[100];
 char c[100];
 char D[100];
        //Scanning the information given by the user
        printf("Enter students ID:\n");
        scanf("%d",&d);
        printf("Enter students name:\n");
        scanf("%s",&n);
        printf("Enter students Class ID:\n");
        scanf("%d",&classD);
        printf("Enter students City:\n");
        scanf("%s",&c);
        printf("Enter students Enrolling date :\n");
        scanf("%s",&D);

        //Inserting the latter into the tree
         T=insert(T, d,n,c,classD ,D);

         printf("The student has been added\n");

       // printf("\n%s\n",T->name);



 }


// Updating a student
else if (x==2){
  int a=0;
  arrow found=NULL;
  int d;
  int classD;
 char n[100];
 char c[100];
 char D[100];

 //Finding the node based on the given input
 printf("Enter the students ID:\n");
     scanf("%d",&d);
     found =find(T,d);

     if(found !=NULL){
     printf("Name:%s\n",found->name);
    strcpy(n,found->name);
     printf("City:%s\n",found->city);
     strcpy(c,found->city);
     printf("Class Id:%d\n",found->classId);
     classD=found->classId;
     printf("Enrollment Date:%s\n",found->date);
     strcpy(D,found->date);
     T= Delete(d,T);

     //Cases to ensure which entity the user would like to update
     printf("\nUpdating:\n");
     printf("would you like to update the students ID\n1.yes  2.no\n");
     scanf("%d",&a);
     if (a==1){
        printf("\nEnter new students ID:\n");
         scanf("%d",&d);
            }
     printf("would you like to update the students name\n1.yes  2.no\n");
     scanf("%d",&a);
     if (a==1){
        printf("Enter new students name:\n");
        scanf("%s",&n);
     }
     printf("would you like to update the students Class ID\n1.yes  2.no\n");
     scanf("%d",&a);
    if (a==1){
         printf("Enter new students Class ID:\n");
        scanf("%d",&classD);
    }
     printf("would you like to update the students City\n1.yes  2.no\n");
     scanf("%d",&a);
     if (a==1){
       printf("Enter new students City:\n");
        scanf("%s",&c);
     }

     printf("would you like to update the students Enrolling date\n1.yes  2.no\n");
     scanf("%d",&a);
     if (a==1){
       printf("Enter new students Enrolling date :\n");
        scanf("%s",&D);
     }
     //Printing the updated info to the screen
     printf("\nName:%s\n",n);

     printf("City:%s\n",c);

     printf("Class Id:%d\n",classD);

     printf("Enrollment Date:%s\n\n",D);

        T=insert(T,d,n,c,classD,D);

     }else
       printf("\nstudent doesn't exist\n");
}
// Printing the students by name
else if (x==3 ){

     printf("\nThe students are :\n");
     T=byName(T);



}// Printing the students in a given city
 else if(x==4){


    char c [100];
    printf("\nplease Enter a City name :\n");
    scanf("%s",&c);//scanning the city from the user
    T=byCity(T,c);//Performing the task



//Printing the students by class id

} else if(x==5){


   T=byClass(T);//Performing the task


//Deleting a specific student
}else if(x==6){
     int d;
     printf("To delete a student enter the students ID:\n");
     scanf("%d",&d);// reading the students ID

     arrow found =find(T,d); //Finding the node
     if(found !=NULL){//if found Delete the student

         printf("Name:%s\n",found->name);
         printf("City:%s\n",found->city);
         printf("Class Id:%d\n",found->classId);
         printf("Enrollment Date:%s\n",found->date);
         T=Delete(d,T);
         printf("\nThe student has been deleted successfully \n");

    }else//if not found inform the user
     printf("\nstudent doesn't exist\n");


//Printing the information to the file
}else if(x==7){

   file = fopen("students.data.txt", "w");// opening the file

   //Creating a tree
   arrow L=NULL;
   //Copying all the information from the main tree and moving it to the new tree
   L=moveNodes(L,T);
   printf("The printed Information:\n");
   while( FindMin(L)!=NULL){//A loop to move all the Information from the the new tree into the file and printing them into the screen

        fprintf(file, "%d %s %s %d %s\n", FindMin(L)->id,FindMin(L)->name,FindMin(L)->city,FindMin(L)->classId,FindMin(L)->date);
        printf("%d %s %s %d %s\n", FindMin(L)->id,FindMin(L)->name,FindMin(L)->city,FindMin(L)->classId,FindMin(L)->date);
        L=Delete(FindMin(L)->id,L);//Deletes a node each time to run over all nodes


   }
   fclose(file);// closing the file

}//Exit case
else if(x==8)// breaks the infinite loop to stop the program
     break;


//Invalid input case
else printf("invalid input please enter again");

}


  return 0;
}

arrow find(arrow T,int x){//Finds a node based on the given Id


   if (T==NULL){

    return NULL;

   }else {
       if (T->id >x )
        find(T->left,x);
        else if (T->id<x )
        find(T->right,x);
        else if (T->id ==x )
        return T;

   }


}

arrow insert(arrow T,int x, char Name[100],char City[100],int ClassId ,char Date[100] ){//Inserts a node into the main BST "depending on  the ID"

if(T==NULL){

    T=(arrow)malloc(sizeof(struct node ));
    T->id=x;
    strcpy(T->name, Name);
    strcpy(T->city, City);
    strcpy(T->date, Date);
    T->classId=ClassId;
    T->left=NULL;
    T->right=NULL;

}

else if (x> T->id){

    T->right=insert(T->right,x,Name,City,ClassId,Date);
    }
else if (x< T->id){

    T->left=insert(T->left,x,Name,City,ClassId,Date);


    }else if (x== T->id)
    printf("");
return T;

}

arrow insertClass(arrow T,int x, char Name[100],char City[100],int ClassId ,char Date[100] ){//Inserts a node into a BST "depending on the Class ID"

if(T==NULL){

    T=(arrow)malloc(sizeof(struct node ));
    T->id=x;
    strcpy(T->name, Name);
    strcpy(T->city, City);
    strcpy(T->date, Date);
    T->classId=ClassId;
    T->left=NULL;
    T->right=NULL;

}

else if (ClassId> T->classId){

    T->right=insertClass(T->right,x,Name,City,ClassId,Date);
    }
else if (ClassId< T->classId){

    T->left=insertClass(T->left,x,Name,City,ClassId,Date);


    }else
    printf("");


return T;

}

arrow insertName(arrow T, int x, char Name[100], char City[100], int ClassId, char Date[100]) {//Inserts a node into a BST "depending on the Name ID"
    if (T == NULL) {
        T = (arrow)malloc(sizeof(struct node));
        T->id = x;
        strcpy(T->name, Name);
        strcpy(T->city, City);
        strcpy(T->date, Date);
        T->classId = ClassId;
        T->left = NULL;
        T->right = NULL;
    } else if (strcmp(Name, T->name)>0) {

        T->right = insertName(T->right, x, Name, City, ClassId, Date);

    } else if (strcmp(Name, T->name)<0) {
        T->left = insertName(T->left, x, Name, City, ClassId, Date);
    } else {
        T->right = insertName(T->right, x, Name, City, ClassId, Date);
    }

    return T;
}

arrow byName(arrow T){//Creates a tree which takes all of the main trees nodes and are sorted based on the name order then prints them to the screen

arrow L=NULL;//creating a new tree
L=moveNodesN(L,T);//taking the main trees' nodes based on the name order
inorderN(L);//printing the new trees content


return T;
}

arrow byCity(arrow T,char c [100]){//Creates a tree which takes all of the main trees nodes and are sorted based on the name order then prints the nodes which have  the same city as the one given to the screen

arrow L=NULL;//creating a new tree
L=moveNodesN(L,T);//taking the main trees' nodes based on the name order
inorderC(L,c);//printing the new trees content based on the given city


return T;
}

arrow byClass(arrow T){//Creates a tree which takes all of the main trees nodes and are sorted based on the name order then prints the nodes to the screen

arrow nameTree=NULL;//creating a new tree sorted based on the names
arrow classIdTree=NULL;//creating a new tree sorted based on classIDs
nameTree=moveNodesN(nameTree,T);//taking the main trees' nodes based on the name order
classIdTree=moveNodesC(classIdTree,T);//taking the main trees' nodes based on the class ID order
inorderCl(classIdTree,nameTree);//printing the both trees content

return T;
}

arrow moveNodes(arrow L, arrow T) { //Copies all the information from the main tree and moving it to the new tree "Based on the ID" recursively
    if (T == NULL) {
        return L;
    }

    L = insert(L,T->id,T->name,T->city,T->classId,T->date);
    L = moveNodes(L, T->left);
    L = moveNodes(L, T->right);

    return L;
}

arrow moveNodesN(arrow L, arrow T) {//Copies all the information from the main tree and moving it to the new tree "Based on the names" recursively
    if (T == NULL) {
        return L;
    }

    L = insertName(L,T->id,T->name,T->city,T->classId,T->date);
    L = moveNodesN(L, T->left);
    L = moveNodesN(L, T->right);

    return L;
}

arrow moveNodesC(arrow L, arrow T) {//Copies all the information from the main tree and moving it to the new tree "Based on the ClassID" recursively
    if (T == NULL) {
        return L;
    }

    L = insertClass(L,T->id,T->name,T->city,T->classId,T->date);
    L = moveNodesC(L, T->left);
    L = moveNodesC(L, T->right);

    return L;
}

void inorder(arrow T){// Prints the content of the main tree starting from the smallest node Id till the greatest id
//L root right
 if (T!=NULL){

    inorder(T->left);
    printf("%d ",T->id);
    inorder(T->right);
}
}

void inorderN(arrow T){// Prints the content of a tree starting from the first node name  till the last nodes' name

 if (T!=NULL){

    inorderN(T->left);
     printf("\n\n-Name:%s\n-ID:%d\n-City:%s\n-Class ID:%d\n-Enrollment Date:%s\n",T->name,T->id,T->city,T->classId,T->date);
    inorderN(T->right);
}
}

void inorderNC(arrow T,int c){// Prints the content of the name tree depending if that nodes' city is the same as the given classID

 if (T!=NULL){

    inorderNC(T->left,c);
    if (T->classId==c){
    printf("\n-Name:%s\n-ID:%d\n-City:%s\n-Enrollment Date:%s\n",T->name,T->id,T->city,T->date);}
    inorderNC(T->right,c);
}
}

void inorderC(arrow T,char c [100] ){// Prints the content of the name tree depending if that nodes' city is the same as the given city

 if (T!=NULL){

    inorderC(T->left,c);
    if(strcmp(T->city,c)==0){
    printf("\n-Name:%s\n-ID:%d\n-Class ID:%d\n-Enrollment Date:%s\n",T->name,T->id,T->classId,T->date);
    }
    inorderC(T->right,c);
}
}

void inorderCl(arrow T,arrow L){// Prints the content of the classID tree and each from each node it prints its following nodes in the name tree

 if (T!=NULL){

    inorderCl(T->left,L);
    printf("\nClass ID:%d\n",T->classId);
    inorderNC(L,T->classId);
    inorderCl(T->right,L);
}
}





arrow FindMax( arrow tree ){
    if( tree == NULL)
return NULL;
else if( tree -> right == NULL)
       return tree;
    else
return FindMax( tree->right);
}


arrow FindMin( arrow tree ){
     if( tree != NULL)
       while( tree->left != NULL)
          tree = tree->left;
return tree; }


arrow Delete(int X, arrow T) {
    arrow TmpCell;

    if (T == NULL) {
        printf("\nElement does not exist\n");
    } else if (X < T->id) {
        T->left = Delete(X, T->left);
    } else if (X > T->id) {
        T->right = Delete(X, T->right);
    } else if (T->left && T->right) {
        // Node to be deleted has two children
        TmpCell = FindMin(T->right);
        T->id = TmpCell->id;
        T->right = Delete(T->id, T->right);
    } else {
        // Node to be deleted has one or no children
        TmpCell = T;
        if (T->left == NULL) {
            T = T->right;
        } else if (T->right == NULL) {
            T = T->left;
        }
        free(TmpCell);
    }
    return T;
}


arrow MakeEmpty( arrow T )// Makes an empty Tree
{
    if( T != NULL )
    {
        MakeEmpty( T->left );
        MakeEmpty( T->right );
        free( T );
    }
    return NULL;
}
