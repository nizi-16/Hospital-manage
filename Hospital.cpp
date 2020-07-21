#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define fee 500
#define fee1 2000
#define samepatient 250
int keyupdate_=0;
int keyupdate1_=0;
int keyupdate2_=0;
struct node
{
 int age;
 char sex[10];
 int key;
 char bloodgroup[3];
 char name[50];
 char date[15];
 char phonenumber[15];
 char category[25];
 struct node *link;
};
struct node *start1=NULL;
struct node *start=NULL;
struct node * createnode()
{
 struct node *p;
 p=(struct node*)malloc(sizeof(struct node));
 return p;
};
void insertnormalpatient_()
{
 int option;
 struct node *temp=createnode();
 keyupdate_++;
 temp->key=keyupdate_;
 temp->link=NULL;
 printf("enter your name,sex,bloodgroup and age\n");
 scanf("%s%s%s%d",temp->name,temp->sex,temp->bloodgroup,&temp->age);
 printf("enter the date\n");
 scanf("%s",temp->date);
 printf("enter you phone number\n");
 scanf("%s",temp->phonenumber);
 printf("1-eye-opthalmologist-vijay\n");
 printf("2-bones-orthopaedician-rajan\n");
 printf("3-childcare-paediatrician-murali\n");
 printf("4-excretory-urologist-padma\n");
 printf("5-skin-dermatologist-ashwin\n");
 printf("6-MRI x-ray-radiologist-ganesan\n");
 printf("7-blood urine test-pathologist-sairam\n");
 printf("8-breathing problem-pulmonologist-ram\n\n");
 printf("choose your problem\n");
 scanf("%d",&option);
 if(option==1)
 {strcpy(temp->category,"opthalmologist");}
 if (option==2)
 {strcpy(temp->category,"orthopaedician");}
 if (option==3)
 {strcpy(temp->category,"paediatrician");}
 if (option==4)
 {strcpy(temp->category,"urologist");}
 if (option==5)
 {strcpy(temp->category,"dermatologist");}
 if (option==6)
 {strcpy(temp->category,"radiologist");}
 if (option==7)
 {strcpy(temp->category,"pathologist");}
 if (option==8)
 {strcpy(temp->category,"pulmonologist");}
 if(start==NULL)
 {start=temp;}
 else{
 struct node *t=start;
 while(t->link!=NULL)
 {
 t=t->link;
 }
 t->link=temp;
 }
 printf("------------\n");
 printf("choose another option\n");
}
void insertemergencypatient_()
{
 int option1;
 struct node *temp=createnode();
 keyupdate1_++;
 temp->key=keyupdate1_;
 temp->link=NULL;
 printf("enter your name,sex bloodgroup and age\n");
 scanf("%s%s%s%d",temp->name,&temp->sex,temp->bloodgroup,&temp->age);
 printf("enter the date\n");
 scanf("%s",temp->date);
 printf("enter your phone number\n");
 scanf("%s",temp->phonenumber);
 printf("1-surgery-general surgeon-rajesh\n");
 printf("2-heart-cardiologist-ramu\n");
 printf("3-reproduction-gynacologist-priyal\n\n");
 printf("choose the option");
 scanf("%d",&option1);
 if(option1==1)
 {strcpy(temp->category,"general surgeon");}
 if(option1==2)
 {strcpy(temp->category,"cardilogist");}
 if(option1==3)
 {strcpy(temp->category,"gynacologist");}
 if(start1==NULL)
 {start1=temp;}
 else{
 struct node *t=start1;
 while(t->link!=NULL)
 {
 t=t->link;
 }
 t->link=temp;
 }
 printf("------------\n");
 printf("choose another option\n");
}
void printemergencypatientdetails()
{
 int i=1;
 struct node *t=start1;
 while(t!=NULL)
 {
 printf("%d.>",i);
 printf("%s\n",t->name);
 printf(" %s\n",t->sex);
 printf(" %d\n",t->age);
 printf(" %s\n",t->bloodgroup);
 printf(" %s\n",t->date);
 printf(" %s\n",t->phonenumber);
 printf(" ------------");
 t=t->link;
 i++;
 }
 printf("------------\n");
 printf("choose another option\n");
}
void printnormalpatientdetails_()
{
 int i=1;
 struct node *t=start;
 while(t!=NULL)
 {printf("%d.>",i);
 printf("%s\n",t->name);
 printf(" %s\n",t->sex);
 printf(" %d\n",t->age);
 printf(" %s\n",t->bloodgroup);
 printf(" %s\n",t->date);
 printf(" %s\n",t->phonenumber);
 t=t->link;
 i++;
 }
 printf(" ------------\n");
 printf("choose another option\n");
}
void diagnoseexistedpatient_(int k)
{
 struct node *t=start;
 while(t!=NULL)
 {
 if(t->key==k)
 {
 keyupdate2_++;
 printf("Member existed\n");
 printf("------------\n");
 printf("choose another option\n");
 break;
 }
 else{
 t=t->link;
 }
 }
}
void totalfee()
{
 int a=((keyupdate2_*samepatient)+(keyupdate_*fee)+(keyupdate1_*fee1));
 printf("total fees :%d\n",a);
 printf("------------\n");
 printf("choose another option\n");
}
void totalpatient()
{
 int a=keyupdate1_+keyupdate_+keyupdate2_;
 printf("total number of patients :%d\n",a);
 printf("------------\n");
 printf("choose another option\n");
}
int main()
{
 int j,k;
printf("1:- to insert normal patient\n");
printf("2:- to insert emergency patient\n");
printf("3:- to print normal patient details\n");
printf("4:- to print emergency patient details\n");
printf("5:- to diagnose existed patient \n");
printf("6:- total fee\n");
printf("7:- total patient\n");
printf("8:- to exit\n");
while(1)
{
scanf("%d",&j);
 {
switch(j)
{
 case 1: insertnormalpatient_();
 break;
 case 2: insertemergencypatient_();
 break;
 case 3: printnormalpatientdetails_();
 break;
 case 4: printemergencypatientdetails();
 break;
 case 5: printf("enter the key number");
 scanf("%d",&k);
 diagnoseexistedpatient_(k);
 break;
 case 6: totalfee();
 break;
 case 7: totalpatient();
 break;
 case 8: exit(0);
 break;
}
}
}
return 0;
}
