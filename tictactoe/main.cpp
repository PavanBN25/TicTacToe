#include <iostream>

#define vsize 3
#define vsize2 9

using namespace std;

int val[vsize][vsize]= {0};
int indx[vsize2]= {0};
int indy[vsize2]= {0};
int m[vsize2]= {0};

void display(int tp)
{
    int i=0;
    int j=0;
    int ptr=0;
    int s=0;
    if(tp==1)
    {
        for( i=0; i<=2; i++)
        {
            cout<< "______ _____ _____"<<endl;
            cout<< endl;
            for(int j=0; j<=2; j++)
            {
                ptr++;
                val[i][j]=ptr;
                indx[ptr]=i;
                indy[ptr]=j;
                cout<<"  "<<ptr<<"   "<<flush;
                if(j!=2)
                    cout<<"|"<<flush;
            }
            cout<<endl;
        }
        cout<< "______ _____ _____"<<endl;
    }
    else
    {
        for(i=0; i<=2; i++)
        {
            cout<< "______ _____ _____"<<endl;
            cout<< endl;
            for(j=0; j<=2; j++)
            {
                s=val[i][j];
                if(s==11)
                    cout<<"  "<<"X"<<"   "<<flush;
                else if(s==22)
                    cout<<"  "<<"Y"<<"  "<<flush;
                else
                    cout<<"  "<<val[i][j]<<"   "<<flush;
                if(j!=2)
                    cout<<"|"<<flush;
            }
            cout<<endl;
        }
        cout<< "______ _____ _____"<<endl;
    }
}
void update(int value,int p)
{
    int x=indx[value];
    int y=indy[value];
    int l=val[x][y];

    if(p==1)
    {
        m[l-1]=1;
        val[x][y]=11;
    }
    else
    {
        m[l-1]=2;
        val[x][y]=22;
    }
    display(2);
}
int check(int p)
{
    int valx=0;
    if(p==1)
    {
        valx=1;
    }
    else if(p==2)
    {
        valx=2;
    }
    for(int i=0; i<=6; i++)
    {
        //checks horizontal (0,1,2),(3,4,5),(6,7,8)
        if(((m[i]==valx)&&(m[i+1]==valx)&&(m[i+2]==valx)) && (((i+2)==2)||((i+2)==5)||((i+2)==8)))
        {
            return 0;
        }
    }

    for(int i=0; i<=2; i++)
    {
        //check vertical (0,3,6)  (1,4,7), (2,5,8)
        if(((m[i]==valx)&&(m[i+3]==valx)&&(m[i+6]==valx)))
        {
            return 0;
        }
    }


    if(((m[0]==valx)&&(m[4]==valx)&&(m[8]==valx))|| ((m[2]==valx)&&(m[4]==valx)&&(m[6]==valx)))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    cout << "Tic Tac Toe game !!!" << endl;
    cout << "Player 1 --->    X " << endl;
    cout << "Player 2 --->    Y " << endl;

    int px1=0;
    int px2=0;
    int countOfEntries=0;
    int flag=1;

    display(1);//,indx,indy);
    do
    {
        cout<<"Enter the number Player 1: "<<flush;
        cin>>px1;
        update(px1,1);//,indx,indy,marked);
        flag=check(1);//,marked);
        cout<<endl;
        countOfEntries++;
        if(flag==0)
        {
            cout<<"Player 1 won !!!"<<endl;
            break;
        }
        if(countOfEntries<9)
        {
            cout<<"Enter the number Player 2: "<<flush;
            cin>>px2;
            update(px2,2);//,indx,indy,marked);
            flag=check(2);//,marked);
            if(flag==0)
            {
                cout<<"Player 2 won !!!"<<endl;
                break;
            }
            countOfEntries++;
        }
        else
            break;
    }
    while(flag);

    if(flag==1)
    {

        cout<< "SORRY!! ITS A DRAW MATCH :( !!"<<endl;
    }
    return 0;
}
