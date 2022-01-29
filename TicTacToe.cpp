#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

char square[9] = {'1','2','3','4','5','6','7','8','9'};

void Intro(){
	cout<<"Hey man. You are plating 'Tic Tac Toe' game. Basicaly you need a rules to play whatever game you are playing. \nHere they are"<<endl;
	cout<<"A game in which two players alternately put Xs and Os in compartments of a figure formed by two vertical \nlines crossing two horizontal lines and each tries to get a row of three Xs or three Os before the opponent does"<<endl;

}
void line(){
	cout<<"_______________________________________________________"<<endl;
}

void Board(){
	cout << "     |     |     " << endl;
    cout << "  " << square[0] << "  |  " << square[1] << "  |  " << square[2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[3] << "  |  " << square[4] << "  |  " << square[5] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[6] << "  |  " << square[7] << "  |  " << square[8] << endl;

    cout << "     |     |     " << endl << endl;
}

void playersMove(char mark){
	cout<<"Enter the position"<<endl;
	int pos = 0;
	bool flag = false;
	while(flag != true){
		cin>>pos;
		if(pos == 1 and square[0] == '1'){
			square[0] = mark;
			flag = true;
		}
		else if(pos == 2 and square[1] == '2'){
			square[1] = mark;
			flag = true;
		}
		else if(pos == 3 and square[2] == '3'){
			square[2] = mark;
			flag = true;
		}
		else if(pos == 4 and square[3] == '4'){
			square[3] = mark;
			flag = true;
		}
		else if(pos == 5 and square[4] == '5'){
			square[4] = mark;
			flag = true;
		}
		else if(pos == 6 and square[5] == '6'){
			square[5] = mark;
			flag = true;
		}
		else if(pos == 7 and square[6] == '7'){
			square[6] = mark;
			flag = true;
		}
		else if(pos == 8 and square[7] == '8'){
			square[7] = mark;
			flag = true;
		}
		else if(pos == 9 and square[8] == '9'){
			square[8] = mark;
			flag = true;
		}else{
			flag = false;
			cout<<"Invalid move. Try it again!"<<endl;
		}		
	}	
}

bool winner_check(char mark){
	 
	bool cb1 = square[0] == mark and square[1] == mark and square[2] == mark;
	bool cb2 = square[0] == mark and square[4] == mark and square[8] == mark;
	bool cb3 = square[0] == mark and square[3] == mark and square[6] == mark;
	bool cb4 = square[3] == mark and square[4] == mark and square[5] == mark;
	bool cb5 = square[2] == mark and square[4] == mark and square[6] == mark;
	bool cb6 = square[1] == mark and square[4] == mark and square[7] == mark;
	bool cb7 = square[2] == mark and square[5] == mark and square[8] == mark;
	bool cb8 = square[6] == mark and square[7] == mark and square[8] == mark;
	
	if(cb1 or cb2 or cb3 or cb4 or cb5 or cb6 or cb7 or cb8){
		return true;
	}
	return false;

}

bool aiMove(int pos, char mark){
	if(pos == 1 and square[0] == '1'){
		square[0] = mark;
		return true;
	}
	else if(pos == 2 and square[1] == '2'){
		square[1] = mark;
		return true;
	}
	else if(pos == 3 and square[2] == '3'){
		square[2] = mark;
		return true;
	}
	else if(pos == 4 and square[3] == '4'){
		square[3] = mark;
		return true;
	}
	else if(pos == 5 and square[4] == '5'){
		square[4] = mark;
		return true;
	}
	else if(pos == 6 and square[5] == '6'){
		square[5] = mark;
		return true;
	}
	else if(pos == 7 and square[6] == '7'){
		square[6] = mark;
		return true;
	}
	else if(pos == 8 and square[7] == '8'){
		square[7] = mark;
		return true;
	}
	else if(pos == 9 and square[8] == '9'){
		square[8] = mark;
		return true;
	}
	return false;
}

bool ais_check(int move, char ai_mark, char players_mark){ // функция проверяет выигрышные ходы игрока на поле. Если игрок может выиграть следующим ходом, то ИИ должен поставить свой знак в это место.
	if(square[0] == players_mark and square[1] == players_mark and square[2] == '3'){
		move = 2;
		square[move] = ai_mark;
		return true;
	}
	else if(square[0] == players_mark and square[2] == players_mark and square[1] == '2'){
		move = 1;
		square[move] = ai_mark;
		return true;
	}
	else if(square[1] == players_mark and  square[2] == players_mark and square[0] == '1'){
		move = 0;
		square[move] = ai_mark;
		return true;
	}
	else if(square[0] == players_mark and square[3] == players_mark and square[6] == '7'){
		move = 6;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[3] == players_mark and square[6] == players_mark and square[0] == '1'){
		move = 0;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[0] == players_mark and square[6] == players_mark and square[3] == '4'){
		move = 3;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[0] == players_mark and square[4] == players_mark and square[8] == '9'){
		move = 8;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[8] == players_mark and square[4] == players_mark and square[0] == '1'){
		move = 0;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[0] == players_mark and square[8] == players_mark and square[4] == '5'){
		move = 4;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[1] == players_mark and square[4] == players_mark and square[7] == '8'){
		move = 7;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[7] == players_mark and square[4] == players_mark and square[1] == '2'){
		move = 1;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[1] == players_mark and square[7] == players_mark and square[4] == '5'){
		move = 4;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[2] == players_mark and square[4] == players_mark and square[6] == '7'){
		move = 6;
		square[move] = ai_mark;	
		return true;
	}
	else if(square[6] == players_mark and square[4] == players_mark and square[2] == '3'){
		move = 2;
		square[move] = ai_mark;	
		return true;
	}
	else if(square[2] == players_mark and square[6] == players_mark and square[4] == '5'){
		move = 4;
		square[move] = ai_mark;	
		return true;
	}
	else if(square[2] == players_mark and square[5] == players_mark and square[8] == '9'){
		move = 8;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[8] == players_mark and square[5] == players_mark and square[2] == '3'){
		move = 2;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[2] == players_mark and square[8] == players_mark and square[5] == '6'){
		move = 5;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[3] == players_mark and square[4] == players_mark and square[5] == '6'){
		move = 5;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[5] == players_mark and square[4] == players_mark and square[3] == '4'){
		move = 3;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[3] == players_mark and square[5] == players_mark and square[4] == '5'){
		move = 4;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[6] == players_mark and square[7] == players_mark and square[8] == '9'){
		move = 8;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[8] == players_mark and square[7] == players_mark and square[6] == '7'){
		move = 6;
		square[move] = ai_mark;
		return true;	
	}
	else if(square[6] == players_mark and square[8] == players_mark and square[7] == '8'){
		move = 7;
		square[move] = ai_mark;
		return true;	
	}
	else{
		cin.ignore();
		return false;
	}
}

int ais_attack(char ai_mark){ // функция проверяет выигрышные ходы игрока на поле. Если ИИ может выиграть следующим ходом, то ИИ должен поставить свой знак в это место.
	if((square[0] == ai_mark and square[1] == ai_mark and square[2] == '3') or (square[6] == ai_mark and square[4] == ai_mark and square[2] == '3')
		or (square[8] == ai_mark and square[5] == ai_mark and square[2] == '3')){
		return 2;
	}
	else if((square[0] == ai_mark and square[2] == ai_mark and square[1] == '2') or (square[7] == ai_mark and square[4] == ai_mark and square[1] == '2')){
		return 1;
	}
	else if((square[1] == ai_mark and  square[2] == ai_mark and square[0] == '1') or (square[3] == ai_mark and square[6] == ai_mark and square[0] == '1')
		or (square[8] == ai_mark and square[4] == ai_mark and square[0] == '1')){
		return 0;
	}
	else if((square[0] == ai_mark and square[3] == ai_mark and square[6] == '7') or (square[2] == ai_mark and square[4] == ai_mark and square[6] == '7')
		or (square[8] == ai_mark and square[7] == ai_mark and square[6] == '7')){
		return 6;
	}
	else if((square[0] == ai_mark and square[6] == ai_mark and square[3] == '4') or (square[5] == ai_mark and square[4] == ai_mark and square[3] == '4')){
		return 3;	
	}
	else if((square[0] == ai_mark and square[4] == ai_mark and square[8] == '9') or (square[6] == ai_mark and square[7] == ai_mark and square[8] == '9')
		or (square[2] == ai_mark and square[5] == ai_mark and square[8] == '9')){
		return 8;	
	}
	else if((square[0] == ai_mark and square[8] == ai_mark and square[4] == '5') or (square[1] == ai_mark and square[7] == ai_mark and square[4] == '5')
		or (square[2] == ai_mark and square[6] == ai_mark and square[4] == '5') or (square[6] == ai_mark and square[8] == ai_mark and square[7] == '8')
		or (square[3] == ai_mark and square[5] == ai_mark and square[4] == '5')){
		return 4;	
	}
	else if((square[1] == ai_mark and square[4] == ai_mark and square[7] == '8') or (square[6] == ai_mark and square[8] == ai_mark and square[7] == '8')){
		return 7;	
	}
	else if((square[2] == ai_mark and square[8] == ai_mark and square[5] == '6') or (square[3] == ai_mark and square[4] == ai_mark and square[5] == '6')){
		return 5;	
	}
	return 100;

}

bool DrawCheck(){
	if(square[0] != '1' and square[1] != '2' and square[2] != '3' and square[3] != '4' and square[4] != '5'
		and square[5] != '6' and square[6] != '7' and square[7] != '8' and square[8] != '9'){
		return true;
	}
	return false;
}

void play_ai(int ai_levels){
	char ai_mark;
	char player_mark;
	cout<<"Select a mark: 'X' or 'O': ";
	cin>>player_mark;
	if(player_mark == 'X'){
		ai_mark = 'O';
	}else{
		ai_mark = 'X';
	}
	int move = 0;
	if(ai_levels == 1){
		cout<<"You are going to play with kiddy AI. Get ready, the game is about to start! Good luck and have fun!"<<endl;
		int sequence = 0;
		if(ai_mark == 'X'){
			while(true){
				if(sequence % 2 == 0){
					line();
					cout<<"AI's move!"<<endl;
					do{
						move = rand() % 9;	
					}while(aiMove(move, 'X') != 1);
					Board();
					if(winner_check('X') == 1){
						cout<<"AI beat player. X won the game!"<<endl;
						break;
					}
				}else{
					line();
					cout<<"Your turn. Ge ahead!"<<endl;
					playersMove('O');
					Board();
					if(winner_check('O') == 1){
						cout<<"Player beat the AI. Judjment day will be later;). O won the game!"<<endl;
						break;
					}
				}
				if(DrawCheck() == 1){
					cout<<"Draw!"<<endl;
					break;
				}
				sequence++;
			}
		}else{
			while(true){
				if(sequence % 2 == 0){
					line();
					cout<<"Your turn. Go ahead!"<<endl;
					playersMove('X');
					Board();
					if(winner_check('X') == 1){
						cout<<"Player beat AI. Judjment day will be later;). X won the game!"<<endl;
						break;
					}
				}else{
					line();
					cout<<"AI's move!"<<endl;
					do{
						move = rand() % 9;	
					}while(aiMove(move, 'O') != 1);
					Board();
					if(winner_check('O') == 1){
						cout<<"AI beat Player. O won the game!"<<endl;
						break;
					}
				}
				if(DrawCheck() == 1){
					cout<<"Draw!"<<endl;
					break;
				}
				sequence++;
			}	
		}
		
	}else{
		cout<<"You are going to play with Senior AI, foolish man. Get ready, the game is about to start! Good luck and have fun!"<<endl;
		int sequence = 0;
		if(ai_mark == 'X'){
			while(true){
				if(sequence % 2 == 0){
					line();
					cout<<"AI's move!"<<endl;
					if(ais_attack('X') == 100){
						if(not ais_check(move, 'X', 'O')){
							if(square[4] == '5'){square[4] = 'X';}
							else if(square[0] == '1'){square[0] = 'X';}
							else if(square[2] == '3'){square[2] = 'X';}
							else if(square[6] == '7'){square[6] = 'X';}
							else if(square[8] == '9'){square[8] = 'X';}
							else if(square[1] == '2'){square[1] = 'X';}
							else if(square[3] == '4'){square[3] = 'X';}
							else if(square[5] == '6'){square[5] = 'X';}
							else if(square[7] == '8'){square[7] = 'X';}
						}	
					}else{
						move = ais_attack('X');
						square[move] = 'X';
					}
					Board();
					if(winner_check('X') == 1){
						cout<<"AI beat Player. X won the game!"<<endl;
						break;
					}
				}else{
					line();
					cout<<"Your turn. Go ahead!"<<endl;
					playersMove('O');
					Board();
					if(winner_check('O') == 1){
						cout<<"Player beat the AI. Judjment day will be later;). O won the game!"<<endl;
						break;
					}
				}
				if(DrawCheck() == 1){
					cout<<"Draw!"<<endl;
					break;
				}
				sequence++;
			}
		}else{
			while(true){
				if(sequence % 2 == 0){
					line();
					cout<<"Your turn. Go ahead!"<<endl;
					playersMove('X');
					Board();
					if(winner_check('X') == 1){
						cout<<"Player beat AI. Judjment day will be later;). X won the game!"<<endl;
						break;
					}
				}else{
					line();
					cout<<"AI's move!"<<endl;
					if(ais_attack('O') == 100){
						if(not ais_check(move, 'O', 'X')){
							if(square[4] == 'O' and ((square[0] == 'X' and square[8] == 'X') or (square[2] == 'X' and square[6] == 'X'))) square[1] = 'O';
							else if(square[4] == '5') {square[4] = 'O';}
							else if(square[0] == '1'){square[0] = 'O';}
							else if(square[2] == '3'){square[2] = 'O';}
							else if(square[6] == '7'){square[6] = 'O';}
							else if(square[8] == '9'){square[8] = 'O';}
							else if(square[1] == '2'){square[1] = 'O';}
							else if(square[3] == '4'){square[3] = 'O';}
							else if(square[5] == '6'){square[5] = 'O';}
							else if(square[7] == '8'){square[7] = 'O';}
						}		
					}else{
						move = ais_attack('O');
						square[move] = 'O';
					}
					Board();
					if(winner_check('O') == 1){
						cout<<"AI beat Player. O won the game!"<<endl;
						break;
					}
				}
				if(DrawCheck() == 1){
					cout<<"Draw!"<<endl;
					break;
				}
				sequence++;
			}	
		}
	}
}

void play(){
	int sequence = 0;
	while(true){
		if(sequence % 2 == 0){
			line();
			cout<<"Player's 1('X') turn. Go ahead!"<<endl;
			playersMove('X');
			Board();
			if(winner_check('X') == 1){
				cout<<"X won the game!"<<endl;
				break;
			}
		}else{
			line();
			cout<<"Player's 2('O') turn. Go ahead!"<<endl;
			playersMove('O');
			Board();
			if(winner_check('O') == 1){
				cout<<"O won the game!"<<endl;
				break;
			}
		}
			
		if(DrawCheck() == 1){
			cout<<"Draw!"<<endl;
			break;
		}
		sequence++;
	}		
		
		
}


int main(){
	Intro();
	Board();
	
	cout<<"You have a choice. You can play with AI with levels (input-1). Or you can play with your friend (input-2): ";
	int game_mode = 0;
	cin>>game_mode;
	if(game_mode == 1){
		cout<<"Gamemode was chosen. You're going to play with AI"<<endl;
		int ai_levels = 0;
		cout<<"Now you should choose the level of difficulty. Input-1 to play with kiddy AI. Input-2 to play against Senior AI: ";
		cin>>ai_levels;
		play_ai(ai_levels);
	}
	else{
		cout<<"Gamemode was chosen. You're going to play with your friend. Have fun!"<<endl;
		play();
		
	}
	
}
