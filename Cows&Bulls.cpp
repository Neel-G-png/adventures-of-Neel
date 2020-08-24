#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string.h>


using namespace std;

class game
{
    int gen[4],input[4],user,c,flag,b;
    public:
    game()
    {
        user=0;
        flag=0;
    }
    void generate()
    {   
        int num;
        srand(time(0));
        do
        {          
            gen[0]=rand()%9+1;         
            gen[1]=rand()%9+1; 
            gen[2]=rand()%9+1;         
            gen[3]=rand()%9+1;
        }while(gen[0]==gen[1]||gen[0]==gen[2]||gen[0]==gen[3]||gen[1]==gen[2]||gen[1]==gen[3]||gen[2]==gen[3]);
        num=gen[0]*1000+gen[1]*100+gen[2]*10+gen[3];
        cout<<num<<"\n";
    }
    void addarray(int temp)
    {
        input[3]=temp%10;
        temp=temp/10;
        input[2]=temp%10;
        temp=temp/10;
        input[1]=temp%10;
        temp=temp/10;
        input[0]=temp;
    }
    void getdata()
    {
        int temp,res;
        char ch[10];
        do
        {
            cout<<"\nEnter your answer::";
            cin>>user;
            temp=user;
            addarray(temp);
            if(user==0)
            {
                cout<<"\n\n\t\t __     ______  _    _   _      ____   _____ _______ ";
                cout<<"\n\t\t \\ \\   / / __ \\| |  | | | |    / __ \\ / ____|__   __|";
                cout<<"\n\t\t  \\ \\_/ / |  | | |  | | | |   | |  | | (___    | |   ";
                cout<<"\n\t\t   \\   /| |  | | |  | | | |   | |  | |\\___ \\   | |   ";
                cout<<"\n\t\t    | | | |__| | |__| | | |___| |__| |____) |  | |   ";
                cout<<"\n\t\t    |_|  \\____/ \\____/  |______\\____/|_____/   |_|  \n\n";
                                                    

                res=4;
            }
            else
            {
            for(int i=0;i<4;i++)
            {
                if(input[i]==0)
                {
                    cout<<"\n\n\t\t!!!PLEASE ENTER DIGITS WITHOUT ZERO!!!";
                    cout<<"\n\nEnter your answer again:";
                    cin>>user;
                    addarray(user);
                }
                else
                {
                    for(int j=0;j<4;j++)
                    {
                        if(i!=j&&input[i]==input[j])
                        {
                            cout<<"\n\n\t\tYOU CANNOT REPEAT THE DIGITS";
                            cout<<"\n\nEnter your answer again:";
                            cin>>user;
                            addarray(user);
                        }
                    }
                }
            }
            }
            c=0;
            b=0;
            res=check();
            if(res==4)
            {
                cout<<"\n\n\t\t __     ______  _    _  __          ______  _   _ ";
                cout<<"\n\t\t \\ \\   / / __ \\| |  | | \\ \\        / / __ \\| \\ | |";
                cout<<"\n\t\t  \\ \\_/ / |  | | |  | |  \\ \\  /\\  / / |  | |  \\| |";
                cout<<"\n\t\t   \\   /| |  | | |  | |   \\ \\/  \\/ /| |  | | . ` |";
                cout<<"\n\t\t    | | | |__| | |__| |    \\  /\\  / | |__| | |\\  |";
                cout<<"\n\t\t    |_|  \\____/ \\____/      \\/  \\/   \\____/|_| \\_|\n\n\n";
                user=0;
            }
        }while(res!=4&&user!=0);
    }
    int check()
    {
        int i,j;
       
        for(i=0;i<4;i++)
        {
            if(input[i]==gen[i])
            {
                c=c+1;
            }
            else
            {
                for(j=0;j<4;j++)
                {   
                    if(input[i]==gen[j])
                    {
                        b=b+1;
                    }
                }
            }
        }
        cout<<"\t\t\t\t"<<user<<"\t"<<c<<"C "<<b<<"B";
        return c;
    }
   
};

int main()
{
    game g;
   
    system("CLS");
   
    char ch[5];
 
    cout<<"\n\t\t   _____                                    _   ____        _ _          ";
    cout<<"\n\t\t  / ____|                                  | | |  _ \\      | | |    ";
    cout<<"\n\t\t | |     _____      _____    __ _ _ __   __| | | |_) |_   _| | |___ ";
    cout<<"\n\t\t | |    / _ \\ \\ /\\ / / __|  / _` | '_ \\ / _` | |  _ <| | | | | / __|   ";
    cout<<"\n\t\t | |___| (_) \\ V  V /\\__ \\ | (_| | | | | (_| | | |_) | |_| | | \\__ \\";
    cout<<"\n\t\t  \\_____\\___/ \\_/\\_/ |___/  \\__,_|_| |_|\\__,_| |____/ \\__,_|_|_|___/    "; 
                                              
    cout<<"\n\n\n\t\tTHIS PROGRAM IS TO CHECK HOW INTELLIGENT YOU ARE\n\n";
   
    cout<<"\t\t\tRHULZZZ\n\n";

    cout<<"\t\t1:YOU CAN ONLY ENTER NUMBERS FROM 1-9, AND YOU CAN ONLY ENTER 4 DIGIT NUMBER\n\n";
   
    cout<<"\t\t2:YOU CANNOT REPEAT THE DIGITS\n\n";
   
    cout<<"\t\t3:'C' IS FOR A NUMBER THAT EXISTS IN MY NUMBER AND IT IS ALSO IN THE CORRECT PLACE\n\n";
   
    cout<<"\t\t4:'B' IS FOR A NUMBER THAT EXISTS IN MY NUMBER BUT IS NOT ON THE RIGHT PLACE\n\n";
   
    cout<<"\t\t5:THE GAME WILL AUTO MATICALY SHUT DOWN ONCE YOU ENTER THE RIGHT NUMBER\n\n";
   
    cout<<"\t\t6:IF YOU WANNA QUIT THEN ENTER 0 AND THE REST WILL BE HISTORY\n\n";
   
    cout<<"\n\n\t\t\tARE YOU READY TO PLAY\n\n\t\t\t\t";
   
    cin>>ch;
   
    system("CLS");
   
    g.generate();
   
    g.getdata();
   
    return 0;
}