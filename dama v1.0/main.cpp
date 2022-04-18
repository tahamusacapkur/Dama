#include <iostream>
using namespace std;

int gameboard[8][8];
int counter1,counter2;
int player1_score,player2_score;
int selected_x,selected_y;
int moved_x,moved_y;
int turn;
char end_turn;
bool turn_continue;

void game_board_config();
void game_board_print();
void selection();
void move();

int main()
{
   game_board_config();
   game_board_print();

    cout << "\no will make first move \n\n";
    turn=1;

   while(1){

        turn_continue=false;

        switch (turn){
        case 1:
            cout << "player 1's turn\n";
            selection();
            if(gameboard[selected_x-1][selected_y-1]==1 && gameboard[moved_x-1][moved_y-1]==0){
                //tekli hareket
                if((selected_x-moved_x==-1)&&(selected_y-moved_y==0)){
                    gameboard[selected_x-1][selected_y-1]=0;
                    gameboard[moved_x-1][moved_y-1]=1;
                    turn=2;}
                //saða yeme
                else if((selected_x-moved_x==0)&&(selected_y-moved_y==-2)&&(gameboard[selected_x-1][selected_y]==2)){
                    gameboard[selected_x-1][selected_y-1]=0;
                    gameboard[moved_x-1][moved_y-1]=1;
                    gameboard[selected_x-1][selected_y]=0;
                    player1_score++;
                    turn_continue=true;}
                //sola yeme
                else if((selected_x-moved_x==0)&&(selected_y-moved_y==2)&&(gameboard[selected_x-1][selected_y-2]==2)){
                    gameboard[selected_x-1][selected_y-1]=0;
                    gameboard[moved_x-1][moved_y-1]=1;
                    gameboard[selected_x-1][selected_y-2]=0;
                    player1_score++;
                    turn_continue=true;}
                //ileri yeme
                else if((selected_x-moved_x==-2)&&(selected_y-moved_y==0)&&(gameboard[selected_x][selected_y-1]==2)){
                    gameboard[selected_x-1][selected_y-1]=0;
                    gameboard[moved_x-1][moved_y-1]=1;
                    gameboard[selected_x][selected_y-1]=0;
                    player1_score++;
                    turn_continue=true;}
                else
                    cout << "\ninvalid entrance\n\n";}
            else
                cout << "\ninvalid entrance\n\n";
            break;

       case 2:
            cout << "player 2's turn\n";
            selection();
            if(gameboard[selected_x-1][selected_y-1]==2 && gameboard[moved_x-1][moved_y-1]==0){
                //tekli hareket
                if((selected_x-moved_x==1)&&(selected_y-moved_y==0)){
                    gameboard[selected_x-1][selected_y-1]=0;
                    gameboard[moved_x-1][moved_y-1]=2;
                    turn=1;}
                //saða yeme
                else if((selected_x-moved_x==0)&&(selected_y-moved_y==-2)&&(gameboard[selected_x-1][selected_y]==1)){
                    gameboard[selected_x-1][selected_y-1]=0;
                    gameboard[moved_x-1][moved_y-1]=2;
                    gameboard[selected_x-1][selected_y]=0;
                    player1_score++;
                    turn_continue=true;}
                //sola yeme
                else if((selected_x-moved_x==0)&&(selected_y-moved_y==2)&&(gameboard[selected_x-1][selected_y-2]==1)){
                    gameboard[selected_x-1][selected_y-1]=0;
                    gameboard[moved_x-1][moved_y-1]=2;
                    gameboard[selected_x-1][selected_y-2]=0;
                    player1_score++;
                    turn_continue=true;}
                //ileri yeme
                else if((selected_x-moved_x==2)&&(selected_y-moved_y==0)&&(gameboard[selected_x-2][selected_y-1]==1)){
                    gameboard[selected_x-1][selected_y-1]=0;
                    gameboard[moved_x-1][moved_y-1]=2;
                    gameboard[selected_x-2][selected_y-1]=0;
                    player1_score++;
                    turn_continue=true;}
                else
                    cout << "\ninvalid entrance\n\n";}
            else
                cout << "\ninvalid entrance\n\n";
            break;
        }

        game_board_print();

        if(player1_score==15||player2_score==15)
            break;
    }

    return 0;
}

void game_board_config(){
    for(counter1=0;counter1<8;counter1++)
        for(counter2=0;counter2<8;counter2++){
            if(counter1==1||counter1==2)
                gameboard[counter1][counter2]=1;
            else if(counter1==5||counter1==6)
                gameboard[counter1][counter2]=2;
            else
                gameboard[counter1][counter2]=0;}
}

void game_board_print(){
    cout << ' ' << ' ';
    for(counter1=1;counter1<9;counter1++)
        cout << counter1<< ' ';

    cout << "\n" ;
    for(counter1=0;counter1<8;counter1++){
            cout << counter1+1 << ' ';
        for(counter2=0;counter2<8;counter2++){
            if(gameboard[counter1][counter2]==1)
                cout << "o" << ' ';
            else if(gameboard[counter1][counter2]==2)
                cout << "x" << ' ';
            else
                cout << "." << ' ';}
        cout << "\n" ;}

    if(turn_continue){
        while(1)
        {
            cout << "do you want end turn? Y/N: ";
            cin >> end_turn;

            if((end_turn=='y' || end_turn=='Y') && turn==1){
                turn=2;
                break;}
            else if((end_turn=='y' || end_turn=='Y') && turn==2){
                turn=1;
                break;}
            else
                break;}}
}

void selection(){
    cout << "select coordinates\nx: ";
    cin >> selected_x;
    cout << "y: ";
    cin >> selected_y;
    cout << "select coordinates where to play:\nx: ";
    cin >> moved_x;
    cout << "y: ";
    cin >> moved_y;
}
