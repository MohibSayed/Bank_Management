#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
int i,j;
int main_exit;
void menu();

struct date
{
    int month, day, year;
};

struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;


void fordelay(int j)
{   
	int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void close(void)
{
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    system("color A");
	printf("\n\n\t\t\t\t\tThis C Mini Project is developed by MOHIB!\n\n");
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n\n\n\n\n\n\n\n\n");
}

void new_acc()
{
	int choice;
	FILE *ptr;
	ptr = fopen("record.txt","a");
	account_no: 
				system("cls");
				//printf("\t\t\t\t\xB2\xB2\xB2\xB2\ ADD RECORD \xB2\xB2\xB2\xB2\xB2");
    			printf("\n\n\n\tEnter today's date(mm/dd/yyyy):");
    			scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    			printf("\n\tEnter Account Number: ");
    			scanf("%d",&check.acc_no);
    			
    			while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n"
				      ,&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year
					  ,&add.age,add.address,add.citizenship,&add.phone,add.acc_type
					  ,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
				{
					if(check.acc_no == add.acc_no)
					{
						printf("\n Account number already in use.");
						fordelay(100000000); //microseconds
						goto account_no;
					}
				}
				add.acc_no=check.acc_no;
				printf("\n\tEnter the name: ");
				scanf("%s",&add.name);
				printf("\n\tEnter the date of birth(mm/dd/yyyy):");
    			scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    			printf("\n\tEnter the age:");
    			scanf("%d",&add.age);
    			printf("\n\tEnter the address:");
    			scanf("%s",add.address);
    			printf("\n\tEnter the citizenship number:");
    			scanf("%s",add.citizenship);
    			printf("\n\tEnter the phone number: ");
    			scanf("%lf",&add.phone);
    			printf("\n\tEnter the amount to deposit:$ ");
    			scanf("%f",&add.amt);
    			printf("\n\tType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
                scanf("%s",add.acc_type);
                
                fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
				fclose(ptr);
				system("color F2");
				printf("\n\t\t\t\t\xB2*\xB2*\xB2*\xB2*\xB2*\xB2*\xB2 Account created successfully! \xB2*\xB2*\xB2*\xB2*\xB2*\xB2*\xB2");
	add_invalid:
				printf("\n\n\t\t\t\t   #PRESS 1 to go to MAIN MENU, #PRESS 0 to exit ");
				scanf("%d",&main_exit);	
				system("cls");
				if(main_exit==1)
				{
					menu();
				}		
				else if(main_exit==0)
				{
					close();
				}
				else
				{
					printf("\n\tINVALID CHOICE :(");
					goto add_invalid;
				}	
}

void edit(void)
{
	int choice, test = 0;
	FILE *old, *newfile;
	old =fopen("record.txt","r");
	newfile =fopen("newfile.txt","w");
	printf("\n\tEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if(add.acc_no==upd.acc_no)
        { 
		    test=1;
            printf("\n\tWhich information do you want to change?\n\t1.Address\n\t2.Phone\n\n\tEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
            {
				printf("\n\tEnter the new address:");
                scanf("%s",upd.address);
                fprintf(newfile,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("\n\n\t**************************************  Changes saved!  **************************************");
            }
            else if(choice==2)
            {
                printf("\n\tEnter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newfile,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("\n\n\t  **************************************  Changes saved!  **************************************");
            }

        }
        else
            fprintf(newfile,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
	fclose(old);
    fclose(newfile);
    remove("record.txt");
    rename("newfile.txt","record.txt");

    if(test!=1)
        {   system("cls");
            printf("\n\tRecord not found!!\a\a\a");
            edit_invalid:
                         printf("\n\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
              			 scanf("%d",&main_exit);
              			 system("cls");
                 		 if (main_exit==1)
 							menu();
                         else if (main_exit==2)
                			close();
                         else if(main_exit==0)
                			edit();
                         else   
                			{
                   				 printf("\n\tInvalid!\a");
                    			 goto edit_invalid;
							}
        }
     else
        {
			printf("\n\n\n\tEnter 1 to go to the main menu and 0 to exit:");
        	scanf("%d",&main_exit);
        	system("cls");
        	if (main_exit==1)
            	menu();
        	else
            	close();
        }
}

void transact(void)
{
	int choice, test=0;
	FILE *old, *newfile;
	old = fopen("record.txt","r");
	newfile = fopen("newfile.txt","w");
	printf("\n\tEnter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
    	if(add.acc_no==transaction.acc_no)
            {   test=1;
			printf("\n\n\tDo you want to\n\t1.Deposit\n\t2.Withdraw?\n\n\tEnter your choice(1 for deposit and 2 for withdraw):");
            scanf("%d",&choice);
            if(choice == 1)
            {
            	printf("\n\tEnter Amount to be Deposited:$ ");
            	scanf("%f",&transaction.amt);
                add.amt+=transaction.amt;
                fprintf(newfile,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\n\t\t\t\t\  *\xB2*\xB2*\xB2*\xB2*\xB2*\xB2*\xB2 Deposited successfully! \xB2*\xB2*\xB2*\xB2*\xB2*\xB2*\xB2*");
			}
			else
            {
                printf("\n\tEnter the amount you want to withdraw:$ ");
                scanf("%f",&transaction.amt);
                add.amt-=transaction.amt;
                fprintf(newfile,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\n\t\t\t\t  *\xB2*\xB2*\xB2*\xB2*\xB2*\xB2*\xB2 Withdrawn successfully! \xB2*\xB2*\xB2*\xB2*\xB2*\xB2*\xB2*");
            }
		}
		else
            {
               fprintf(newfile,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
	}
   fclose(old);
   fclose(newfile);
   remove("record.txt");
   rename("newfile.txt","record.txt");
   if(test!=1)
   {
       printf("\n\n\tRecord not found!!");
       transact_invalid:
       printf("\n\n\n\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
       scanf("%d",&main_exit);
       system("cls");
       if (main_exit==0)
                transact();
       else if (main_exit==1)
                menu();
       else if (main_exit==2)
                close();
       else
       {
           printf("\n\tInvalid!");
           goto transact_invalid;
       }

   }
   else
   {
        printf("\n\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }	
}

void see(void)
{
	int choice;
	int test = 0;
	FILE *ptr;
	ptr = fopen("record.txt","r");
	
	printf("\n\tDo you want to check by- \n\t1. Account number \n\t2. Name \n #PRESS 1 for ACC_NO \t #PRESS 2 FOR NAME: ");
	scanf("%d",&choice);
	if(choice == 1)
	{
		printf("\n\tEnter Account Number: ");
		scanf("%d",check.acc_no);
		while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
        	if(add.acc_no==check.acc_no)
        	{
        		system("cls");
        		test =1;
        		printf("\n\tAccount NO.:%d\n\n\tName:%s \n\n\tDOB:%d/%d/%d \n\n\tAge:%d \n\n\tAddress:%s \n\n\tCitizenship No:%s \n\n\tPhone number:%.0lf \n\n\tType Of Account:%s \n\n\tAmount deposited:$ %.2f \n\n\tDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
			}
		}
	}
	else if(choice==2)
	{
		printf("\n\tEnter Name: ");
		scanf("%s",check.name);
		while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
        	if(strcmpi(add.name,check.name)==0)
        	{
        		system("cls");
        		test =1;
        		printf("\n\tAccount NO.:%d\n\n\tName:%s \n\n\tDOB:%d/%d/%d \n\n\tAge:%d \n\n\tAddress:%s \n\n\tCitizenship No:%s \n\n\tPhone number:%.0lf \n\n\tType Of Account:%s \n\n\tAmount deposited:$ %.2f \n\n\tDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
			}
		}
	}
	fclose(ptr);
	if(test!=1)
    {   
		system("cls");
        printf("\nRecord not found!!\a\a\a");
        see_invalid:
   		            printf("\n\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
         	        scanf("%d",&main_exit);
                    system("cls");
                    if (main_exit==1)
                                 menu();
                    else if (main_exit==2)
                                 close();
                    else if(main_exit==0)
                                 see();
                    else
                    {
                        system("cls");
                        printf("\n\tInvalid!\a");
                        goto see_invalid;
					}	
    }               
    else
        {
			printf("\nEnter 1 to go to the main menu and 0 to exit:");
       		scanf("%d",&main_exit);
		}
       		if (main_exit==1)
        	{
            	system("cls");
            	menu();
            }

        	else
            {
				system("cls");
            	close();
            }
            

}

void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.txt","r");
    newrec=fopen("newfile.txt","w");
    printf("\n\n\tEnter the Account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {
				test++;
            	printf("\n\n\n\n\t    ***************************  Record deleted successfully! ***************************\n");
            }
    }
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("newfile.txt","record.txt");
   if(test==0)
        {
              printf("\n\tRecord not found!!\a\a\a");
              erase_invalid:
              printf("\n\n\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {
						printf("\n\tInvalid!\a");
                    	goto erase_invalid;
					}
        }
    else
        {
			printf("\n\n\tEnter 1 to go to the main menu and 0 to exit:");
        	scanf("%d",&main_exit);
        	system("cls");
        	if (main_exit==1)
            	menu();
       		 else
            	close();
        }

}

void view_list(void)
{
	FILE *view;
	view = fopen("record.txt","r");
	int test = 0;
	system("cls");
	printf("\n\tACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");
	while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n\t%5d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }
       fclose(view);
       if(test==0)
       {
       	system("cls");
       	printf("\n\t Oops! NO RECORDS :(\n");
	   }
	   view_list_invalid: 
	   					printf("\n\n\tEnter 1 to go to main menu \t Enter 0 to exit");
	   					scanf("%d",&main_exit);
	   					system("cls");
	   					if (main_exit == 1)
	   							menu();
	   					else if(main_exit == 0)
	   							close();
	   					else
        				{
            				printf("\n\tInvalid!\a");
           					goto view_list_invalid;
       					}
}

void menu(void)
{
	 int choice;
    system("cls");
    
   // system("color 9");
    system("color 1F");
    printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    
	printf("\n\n\t\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
	
	printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t\t\t    \xB2*\xB2*\xB2*\xB2*\xB2*\xB2*\xB2 WELCOME TO THE MAIN MENU \xB2*\xB2*\xB2*\xB2*\xB2*\xB2*\xB2");
    printf("\n\n\n\t\t1.Create new account\n\n\t\t2.Update information of existing account\n\n\t\t3.For transactions\n\n\t\t4.Check the details of existing account\n\n\t\t5.Removing existing account\n\n\t\t6.View customer's list\n\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    
    system("cls");
    
	switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;

    }
}




int main()
{
	char pass[100], password[100]="codewithmohib";
	int i = 0;
	system("color F");
	
	printf("\n\n\t\tEnter Password: ");
	scanf("%s",&pass);
	
	if(strcmp(pass,password)==0)
	{
		system("color A");
		printf("\n\n\t\tPassword MATCHED successfully!");
		for(i=0;i<6;i++)
		{
			fordelay(100000000);
			printf(".");
		}
		system("cls");
		menu();
	}
	else
	{
		system("color C");
		printf("\n\n\t\tOops! Wrong Password :(   ");
		
		login_try: 
					printf("\n\n\t\t#PRESS 1 to try again, #PRESS 0 to exit");
					scanf("%d",&main_exit);
					if(main_exit == 1)
					{
						system("cls");
						main();
					}
					else if(main_exit == 0)
					{
						system("cls");
						close();
					}
					else 
					{
						printf("INVALID CHOICE ENTERED :(");
						fordelay(100000000);
						system("cls");
						goto login_try;
					}
	}
	return 0;
}
