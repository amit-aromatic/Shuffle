//SHUFFLE GAME
#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<stdlib.h>
#include<time.h>

enum boolean {false,true};

class pic
   {
    private:
      int p;
    public:
//       pic()  {}
      void set(int r)      {p=r;}
      void display();
      boolean issameas(pic);
    };

void pic::display()
 {
  cout<<char(p);
  }

boolean pic::issameas(pic q)
  {
    return (p==q.p)?true:false;
  }

struct record
{
char *name;
int hscore;
};

void getname(record,int);
void input(char[]);
void graphic();
void message();

FILE *hsc;

void main()
 {
  pic gameb[4],gamea[4],temp1,temp2,chosen[4];
  int pos,i,flag,score=0;
  long int wait;
  char a,pose[80];

  char vh,vname[80],dname[80];
  int hs,nhs,ishisc=0,vhs;
  record rec;

   clrscr();
   graphic();
   clrscr();
   message();
   vh=getch();
   if(vh=='h'||vh=='H')
      {
       hsc=fopen("hiscor.shf","r");
       fscanf(hsc," %[^\n]",vname);
       clrscr();
       cout<<"                               HIGH SCORE \n";
       cout<<endl<<endl;
       cout<<"\nNAME : "<<vname;
       fscanf(hsc,"\n%d",&vhs);
       cout<<"\nSCORE : "<<vhs;
       fclose(hsc);
       getch();
      }
   clrscr();
  play:

   hsc=fopen("hiscor.shf","r");
		    {
		      fscanf(hsc," %[^\n]\n%d",dname,&hs);

		    }


   clrscr();
	      //before shuffling
	 randomize();
	 for (i=0;i<4;i++)
	   {
	    again:
	   int t=random(4)+3;
	     temp1.set(t);
	     flag = 1;
		if(i>0){
	    for(int l=0;l<i;l++){
				   if(temp1.issameas(gameb[l]))
				    {
				    flag=0;
				    break;}
				}
			}
	    if(flag)
	    gameb[i].set(t);
	    else goto again;
	    }

	cout<<"Before shuffling:\n";
   for ( i=0;i<4;i++)
	   {
	    cout<<" ";
	    gameb[i].display();
	    }
	for(wait=0;wait<190000000;wait++);
	    clrscr();

			//after shuffling

	 for (i=0;i<4;i++)
	   {
	      again2:
	    int k=random(4)+3;
	    temp2.set(k);
	     flag = 1;
		if(i>0){
	    for(int l=0;l<i;l++){
				   if(temp2.issameas(gamea[l]))
				    {
				    flag=0;
				    break;}
				}
			}
	    if(flag)
	    gamea[i].set(k);
	    else goto again2;
	    }

	    cout<<"\nafter shuffling:\n";
 for (i=0;i<4;i++)
	   {
	    cout<<" ";
	    gamea[i].display();
	    }
		//input answer

    cout<<"\nEnter the original order of these suits:-";
   for(i=0;i<4;i++){
     cout<<"\nEnter for ";
     gamea[i].display();
     cout<<" : ";
     input(pose);
     pos=int(pose[0])-48;
    switch(pos)
     {
      case 1:chosen[0]=gamea[i];break;
      case 2:chosen[1]=gamea[i];break;
      case 3:chosen[2]=gamea[i];break;
      case 4:chosen[3]=gamea[i];break;
     }             }

	//evaluation of answer
   flag=1;
   for(i=0;i<4;i++)
   {
  if(!(chosen[i].issameas(gameb[i])))
     {
      flag=0;
      break;
     }
   }
		   //output result
   if(flag)
     {cout<<"\nYou Win!";
      score++;
      getch();
      clrscr();
      if(score>hs)  { ishisc=1; nhs=score; }

      cout<<"\nYour score :"<<score;
      cout<<endl<<"Press any key to continue...";
      getch();
      goto play;
      }

    else {cout<<"\nYou Lose!";
	  score=0;
	 cout<<"\nYou chose: ";
	 for(i=0;i<4;i++)
	   {
	     chosen[i].display();
	     cout<<" ";
	   }
	   cout<<"\nand correct order was : ";
	   for(i=0;i<4;i++)
	   {
	     gameb[i].display();
	     cout<<" ";
	   }
	   }
    getch();
    clrscr();
     again3:
     if(score==0){
	 if(ishisc==1) { getname(rec,nhs);
			ishisc=0; }
     cout<<"\nYour score :"<<score;
      cout<<"\nPlay again?(y/n)";
      cin>>a;
      if(a=='y'||a=='Y') goto play;
      else{
	 if(!(a=='n'||a=='N'))
	 {cout<<"Error!";  goto again3;  }
	else goto end;
	  }
		}
   end:
   fclose(hsc);
   cout<<"Press Enter to exit...";
   getch();
}


void input(char a[])
{

   aa:


     scanf(" %[^\n]",a);
     if(!(a[0]=='1'||a[0]=='2'||a[0]=='3'||a[0]=='4')){
					   cout<<"\nError! \nEnter again : ";
					   goto aa;
			   }

   return ;
}

void getname(record rec,int nhs)
{

cout<<"                            HIGH SCORE !!!"
    <<endl<<"                           CONGRATULATIONS\n\n\n";
hsc=fopen("hiscor.shf","w");
cout<<"\nEnter name:";
scanf(" %[^\n]",rec.name);
fprintf(hsc, "%s", rec.name);
rec.hscore=nhs;
fprintf(hsc, "\n%d" ,rec.hscore);
fclose(hsc);
return;
}

void graphic()
{
long int k;
gotoxy(31,12);
cout<<"H F L F S E U";
gotoxy(60,24);
for(k=0;k<90000000;k++);
gotoxy(31,12);
cout<<"E U H S F E F";
gotoxy(60,24);
for(k=0;k<90000000;k++);
gotoxy(31,12);
cout<<"H F L U E F S";
gotoxy(60,24);
for(k=0;k<90000000;k++);
gotoxy(31,12);
cout<<"S H U F F L E";
gotoxy(60,24);
for(k=0;k<200000000;k++);
return;
}

void message()
{
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl<<"   The GAME :"
    <<endl
    <<endl<<" An ordered set of card suits will be displayed for a second"
    <<endl<<" or two.The player is expected to remember that order.Then"
    <<endl<<" shuffling of suits will be done and player will be asked to"
    <<endl<<" enter the original order in terms of 1,2,3,4 ( 1 for the left "
    <<endl<<" most,2 for the next position,...,4 for the rightmost position.)"
    <<endl<<" one by one."
    <<endl<<" -------------------------NOTE---------------------------------"
    <<endl<<" If an entry is repeated ( eg. 3,2,3,1 ) ,then the results will"
    <<endl<<" be unexpected.In case the player enters an invalid character,"
    <<endl<<" an ERROR! message will be promped,but not for a repeated entry."
    <<endl<<" Also, only the first letter of the entry will be read( eg. "
    <<endl<<" 432jksj...qw!@#$$      will be read as 4)."
    <<endl
    <<endl
    <<endl<<"      So Go For It !!!"
    <<endl
    <<endl<<"  PRESS H TO VIEW HIGH SCORE,OR"
    <<endl<<"  PRESS ANY KEY TO STRAT...";
return;
}








