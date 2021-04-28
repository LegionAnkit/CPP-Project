#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct airline
{
	char passport[6];
	char name[15];
	int seat_num;
	char email[15];
	struct airline *next;
}
*begin, *stream;
struct airline *temp;


int main()
{
	void reserve(int x), cancel(), display(), savefile();
	int choice;
	begin = stream = NULL;
	int num = 1;
	do
	{

		printf("\n\n\n\t\t Please enter your choice from below (1-4):");
		printf("\n\n\t\t 1. Reservation");
		printf("\n\n\t\t 2. Cancel");
		printf("\n\n\t\t 3. DISPLAY RECORDS");
		printf("\n\n\t\t 4. EXIT");
        printf("\n\n\t\t Enter your choose ");



		scanf("%d", &choice); fflush(stdin);
		system("cls");
		switch (choice)
		{
		case 1:
			reserve(num);
			num++;
			break;
		case 2:
			cancel();
			break;
		case 3:
			display();
			break;
		case 4:
		{
				  savefile();
				  break;
		}
		default:
			printf("\n\n\t SORRY INVALID CHOICE!");
			printf("\n\n\t PLEASE CHOOSE FROM 1-4");
			printf("\n\n\t Do not forget to chose from 1-4");
		}
		getch();
	} while (choice != 4);
	return 0;
}


void details()
{
	printf("\n\t Enter your passport number:");
	gets(stream->passport); fflush(stdin);
	printf("\n\t Enter your  name:");
	gets(stream->name); fflush(stdin);
	printf("\n\t Enter your email address:");
	gets(stream->email); fflush(stdin);

}



void details();



void reserve(int x)
{
	stream = begin;
	if (begin == NULL)
	{
		begin = stream = (struct airline*)malloc(sizeof(struct airline));
		details();
		stream->next = NULL;
		printf("\n\t Seat booking successful!");
		printf("\n\t your seat number is: Seat A-%d", x);
		stream->seat_num = x;
		return;
	}
	else if (x > 15)
	{
		printf("\n\t\t Seat Full.");
		return;
	}
	else
	{
		while (stream->next)
			stream = stream->next;
		stream->next = (struct airline *)malloc(sizeof(struct airline));
		stream = stream->next;
		details();
		stream->next = NULL;
		printf("\n\t Seat booking successful!");
		printf("\n\t your seat number is: Seat A-%d", x);
		stream->seat_num = x;
		return;
	}
}


void savefile()
{
	FILE *fpointer = fopen("  records", "w");
	if (!fpointer)
	{
		printf("\n Error in opening file!");
		return;

	}
	stream = begin;
	while (stream)
	{
		fprintf(fpointer, "%-6s", stream->passport);
		fprintf(fpointer, "%-15s", stream->name);
		fprintf(fpointer, "%-15s", stream->email);
		stream = stream->next;
	}
	printf("\n\n\t Details have been saved to a file (  records)");
	fclose(fpointer);
}

void display()
{
	stream = begin;
	while (stream)
	{
		printf("\n\n Passport Number : %-6s", stream->passport);
		printf("\n         name : %-15s", stream->name);
		printf("\n      email address: %-15s", stream->email);
		printf("\n      Seat number: A-%d", stream->seat_num);
		printf("\n\n++*=====================================================*++");
		stream = stream->next;
	}

}

void cancel()
{
	stream = begin;
	system("cls");
	char passport[6];
	printf("\n\n Enter passport number to delete record?:");
	gets(passport); fflush(stdin);
	if (strcmp(begin->passport, passport) == 0)
	{
		temp = begin;
		begin = begin->next;
		free(temp);
		printf(" booking has been deleted");
		getch();
		return;

	}

	while (stream->next)
	{
		if (strcmp(stream->next->passport, passport) == 0)
		{
			temp = stream->next;
			stream->next = stream->next->next;
			free(temp);
			printf("has been deleted ");
			getch();
			return;
		}
		stream = stream->next;
	}
	printf("passport number is wrong please check your passport");

}


