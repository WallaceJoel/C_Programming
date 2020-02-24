#include<stdio.h>
#include<stdlib.h>

void check(char sud[9][9], char values[9], char box[9], int j, int w){

for(int a = 0; a < 9; a++){
for(int i = 0; i < 9; i++){
if(values[a] == sud[i][w]){
values[a] = 'n';
continue;
}
if(values[a]== sud[j][i]){ 
values[a]= 'n';
continue;
}
if(values[a] == box[i]){
values[a] = 'n';
continue;
}
}

}

}
void box(int x, int y, char sud[9][9], char big[9]){
	int row;
	int col;

	for(int i = 0; i <9; i= i+3){
		if(x>=i && x<(i+3)){
		row = i;
		break;
		}
	}
	for(int i = 0; i <9; i= i+3){
		if(y>=i && y<(i+3)){
		col = i;
		break;
		}
	}

	int z = 0;
	for(int i = row; i < row+3;i++){
		for(int a = col; a < col+3;a++){
			if(sud[i][a] != '-'){
				big[z] = sud[i][a];
				z++;
			}else{
				big[z] = '-';
				z++;
			}
		}
	}

}//function end

int duku(char sud[9][9], int j, int w){
//first find all available values in box
	char s = sud[j][w];
	sud[j][w] = '-';
	char values[9] = {'1','2','3','4','5','6','7','8','9'};
	char block[9];
	box(j,w,sud,block);
	check(sud,values,block, j, w);
	int x = -1;
	for(int i = 0; i < 9; i++){
		if(s == values[i]){
			x = i;
			break;
		}
	}


	for(int i =0; i < 9; i++){
		if(values[i] != 'n' && i > x){
			sud[j][w] = values[i];
			return 1;
		}
	}
	return -1;

}//end


int main(int argc, char ** argv){

	char sud[9][9];

	FILE *fp = fopen(argv[1],"r");

	for(int i = 0; i < 9; i++){
	fscanf(fp ,"%c %c %c %c %c %c %c %c %c\n",&
			sud[i][0],&sud[i][1],&sud[i][2],
			&sud[i][3],&sud[i][4],&sud[i][5],
			&sud[i][6],&sud[i][7],&sud[i][8]);
	}
	fclose(fp);

	int index [81][2];
	int b=0;
	for(int i = 0; i < 9; i++){
		for(int a = 0; a < 9; a++){
			if(sud[i][a] == '-'){
			index[b][0] = i;
			index[b][1] = a;
			b++;
			}
		}
	}

	int i=0;
	int x=-1;
	while(i < b){
		int r = index[i][0];
		int c =index[i][1];
		x = duku(sud,r,c);
		if(x == -1){
			i--;
		}else{
			i++;
		}
	}


	for(int i = 0; i < 9; i++){
		for(int z = 0; z < 8; z++){
			printf("%c	", sud[i][z]);
		}
		printf("%c\n",sud[i][8]);
	}


	return 0;
}
