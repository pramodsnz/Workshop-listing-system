#include<stdio.h>
#include<conio.h>
#include<string.h>
void welcomemenu();
void login();
void mainmenu();
int enter_data();
void display();
void edit();
void delete_data();
char user[10]="m",password[10]="1";
struct garage
{
	char name[50],address[50],contact[10],opening_time[10],closing_time[10],car_servicing_cost[10],bike_servicing_cost[10],mobil_change_cost[10],battery_changing_cost[10],tyre_change_cost[10],washing_cost[10],half_engine_repair_cost[10],full_engine_repair_cost[10],number_plate_printing_cost[10];
};
void main()
{
	welcomemenu();
	login();
	
}
void welcomemenu()
{
	char ch;
	printf("\t\t\t****************************************************************\n");
    printf("\t\t\t*                                                             *\n");
    printf("\t\t\t *                                                           *\n");
	printf("\t\t\t   ::::::::::WELCOME TO WORKSHOP LISTING SYSTEM:::::::::::::\n");
    printf("\t\t\t *                                                           *\n");
    printf("\t\t\t*                                                             *\n");
 	printf("\t\t\t****************************************************************\n");
	printf("\n\t\t\t....::Press any key to proceed::....");
	ch=getch();
}
void login()
{
	char uname[10],pass[10];
	system("cls");
	printf("\t\t\t:::::::::::::::::::::::::::::\n");
	printf("\t\t\t **:YOU ARE IN LOGIN PAGE:** \n");
	printf("\t\t\t:::::::::::::::::::::::::::::\n");
	printf("\t\t\tENTER THE USERNAME:");
	scanf("%s",&uname);
	printf("\t\t\tENTER THE PASSWORD:");
	scanf("%s",&pass);
	if(strcmp(user,uname)==0 && strcmp(pass,password)==0)
	{
		mainmenu();
    }
    else
    {
    	char ch;
    	printf("ID  OR PASSWORD DOESNOT MATCH\n Press any key to try again");
    	ch=getch();
    	login();
	}


}
void mainmenu()
{
	int choice;
	char ch;
	system("cls");
	printf("\t\t\t ..###########.M.E.N.U.#########.. ");
	printf("\n\t\t\t..  1. Add Workshop and Service   ..");
	printf("\n\t\t\t..  2. Available service          ..");
	printf("\n\t\t\t..  3. Update service             ..");
	printf("\n\t\t\t..  4. Delete service             ..");
	printf("\n\t\t\t..  5. Exit                       ..\n");
	printf("\t\t\t  ..#############################.. \n");
	printf("\t\t\t Choose any option:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("You are in Add Workshop and Service menu\n");
			enter_data();
			break;
		case 2:
		    printf("You are in Available menu\n");
		    display();
			break;
		case 3:
			printf("You are in Update service menu\n");
			edit();
			break;	 
		case 4:
			printf("You are in Delete service menu");
			delete_data();
			break;
		default:
		    printf("Please enter the valid choice\n");
			printf("Do you want to try again:\n");
			printf("Press Y for Yes and N for No\n");
			fflush(stdin);
			ch=getchar();
			if(ch=='Y')
			{
				mainmenu();
		    }		 		
	}
}
int enter_data()
{
	struct garage s;
	printf("Enter the name:");
	scanf("%s",&s.name);
	printf("Enter the address:");
	scanf("%s",&s.address);
	printf("Enter the contact:");
	scanf("%s",&s.contact);
	printf("Opens at:");
	scanf("%s",&s.opening_time);
	printf("Closes at:");
	scanf("%s",&s.closing_time);
	printf("Enter the car servicing cost:");
	scanf("%s",&s.car_servicing_cost);
	printf("Enter the bike servicing cost:");
	scanf("%s",&s.bike_servicing_cost);
	printf("Enter the mobil change cost:");
	scanf("%s",&s.mobil_change_cost);
	printf("Enter the tyre change cost:");
	scanf("%s",&s.tyre_change_cost);
	printf("Enter the battery changing cost:");
	scanf("%s",&s.battery_changing_cost);
	printf("Enter the washing cost:");
	scanf("%s",&s.washing_cost);
	printf("Enter the half engine repair cost:");
	scanf("%s",&s.half_engine_repair_cost);
	printf("Enter the full engine repair cost:");
	scanf("%s",&s.full_engine_repair_cost);
	printf("Enter the number plate printing cost:");
	scanf("%s",&s.number_plate_printing_cost);
	FILE *ptr;
	ptr = fopen("user_data.bin","ab+");
	fwrite(&s,sizeof(struct garage),1,ptr);
	fclose(ptr);
	
	return 0;
}


void display(){
	char b[30];
	struct garage s;
	printf("Enter the garage name to search:");
	scanf("%s",b);
	FILE *ptr;
	ptr = fopen("user_data.bin","r");
	while(fread(&s,sizeof(struct garage),1,ptr)){
		if (strcmp(s.name,b)==0){
			printf("Name:%s\n",s.name);
			printf("The address is:%s\n",s.address);
			printf("Contact:%s\n",s.contact);
			printf("Opens at:%s\n",s.opening_time);
			printf("Closes at:%s\n",s.closing_time);
			printf("The battery changing cost is:%s\n",s.battery_changing_cost);
			printf("The bike servicing cost is:%s\n",s.bike_servicing_cost);
			printf("The car servicing cost is:%s\n",s.car_servicing_cost);
			printf("The full engine repair cost is:%s\n",s.full_engine_repair_cost);
			printf("The half engine repair cost is:%s\n",s.half_engine_repair_cost);
			printf("The mobil change cost:%s\n",s.mobil_change_cost);
			printf("The number plate printing cost:%s\n",s.number_plate_printing_cost);
			printf("The tyre changing cost:%s\n",s.tyre_change_cost);
			printf("The Washing cost:%s\n",s.washing_cost);
			
		}
	}
	fclose(ptr);
	getch();
}
void edit()
{
	FILE *pt,*ptr;
	struct garage s;
	char b[20];
	printf("Enter the garage name to edit:");
	scanf("%s",&b);
	pt = fopen("user_data.bin","rb+");
	ptr = fopen("testfile.bin","ab+");
	while(fread(&s,sizeof(struct garage),1,pt)){
	
		if (strcmp(s.name,b)==0){
			printf("Enter the name:%s\n",s.name);
			printf("The address is: %s\n",s.address);
			printf("Contact:%s\n",s.contact);
			printf("Opens at:%s\n",s.opening_time);
			printf("Closes at:%s\n",s.closing_time);
			printf("The battery changing cost is:%s\n",s.battery_changing_cost);
			printf("The bike servicing cost is:%s\n",s.bike_servicing_cost);
			printf("The car servicing cost is:%s\n",s.car_servicing_cost);
			printf("The full engine repair cost is:%s\n",s.full_engine_repair_cost);
			printf("The half engine repair cost is:%s\n",s.half_engine_repair_cost);
			printf("Enter the number plate printing cost:%s\n",s.number_plate_printing_cost);
			printf("The tyre changing cost:%s\n",s.tyre_change_cost);
			printf("The Washing cost:%s\n",s.washing_cost);
			struct garage g1;
				printf("Enter the name:");
	            scanf("%s",&g1.name);
	            printf("Enter the address:");
             	scanf("%s",&g1.address);
             	printf("Enter the contact:");
             	scanf("%s",&g1.contact);
            	printf("Opens at:");
            	scanf("%s",&g1.opening_time);
            	printf("Closes at:");
            	scanf("%s",&g1.closing_time);
            	printf("Enter the battery changing cost:");
            	scanf("%s",&g1.battery_changing_cost);
              	printf("Enter the car servicing cost:");
             	scanf("%s",&g1.car_servicing_cost);
            	printf("Enter the bike servicing cost:");
               	scanf("%s",&g1.bike_servicing_cost);
            	printf("Enter the mobil change cost:");
            	scanf("%s",&g1.mobil_change_cost);
               	printf("Enter the tyre change cost:");
            	scanf("%s",&g1.tyre_change_cost);
               	printf("Enter the washing cost:");
             	scanf("%s",&g1.washing_cost);
            	printf("Enter the half engine repair cost:");
            	scanf("%s",&g1.half_engine_repair_cost);
              	printf("Enter the full engine repair cost:");
               	scanf("%s",&g1.full_engine_repair_cost);
            	printf("Enter the number plate printing cost:");
            	scanf("%s",&g1.number_plate_printing_cost); 
			fwrite(&g1,sizeof(struct garage),1,ptr);

	}
	else{
		fwrite(&s,sizeof(struct garage),1,ptr);
	}
}
fclose(ptr);
fclose(pt);
remove("user_data.bin");
rename("testfile.bin","user_data.bin");
}






void delete_data()
{
	FILE *pt,*ptr;
	struct garage s;
	char b[20];
	printf("Enter the garage name to delete data:");
	scanf("%s",&b);
	pt = fopen("user_data.bin","rb+");
	ptr = fopen("testfile.bin","ab+");
	while(fread(&s,sizeof(struct garage),1,pt)){
	
		if (strcmp(s.name,b)==0){
			printf("Data Erased");

	}
	else{
		fwrite(&s,sizeof(struct garage),1,ptr);
	}
}
fclose(ptr);
fclose(pt);
remove("user_data.bin");
rename("testfile.bin","user_data.bin");
}


