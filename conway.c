#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

char cellTest (char *board, int w, int h, int x, int y) ;
void conwayStep (char *board, int w, int h);
void printConway (char *board, int w, int h);
int msleep (long msec);

char cellTest (char *board, int w, int h, int x, int y){
	char **rows = (char **)malloc(h*sizeof(char *));

    int i = 0, j=0;
    char *boardptr = board;

    for (i=0;i<h;i++){
        j = 0;
        *(rows+i) = (char*)malloc(w*sizeof(char));
        for (j=0; j<w; j++){
            *(*(rows+i)+j) = *boardptr;
            boardptr += 1;
            
        }
    }

    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
        }
    }

	char c_status = *(*(rows+y)+x);

	//check adjascent cells
	int sum = 0;
	char n_status = '0';
	
    for (j=y-1; j<=y+1; j++){
        i = x-1;
        for (i=x-1; i<=x+1; i++){
            if ((i==x&&j==y)||i<0||i>=w||j<0||j>=h){
                sum += 0;
            }else if (*(*(rows+j)+i) == '1'){
                sum += 1;
            }else if (*(*(rows+j)+i) == '0'){
                sum += 0;
            }
        }
    }

	if (c_status=='1'&&sum<2){
		n_status = '0';
	}else if (c_status=='1'&&sum>3){
		n_status = '0';
	}else if (c_status=='1'&&(sum==2||sum==3)){
		n_status = '1';
	}else if (c_status=='0'&&sum==3){
		n_status = '1';
	}else {
		n_status = '0';
	}



	return n_status;
}

void conwayStep (char *board, int w, int h){
	int x = 0;
	int y = 0;
	int size = w*h;
	int i = 0;
	char n_status; 
    char *next_board = (char*)malloc(w*h*sizeof(char));
	for (y = 0; y<h; y++){
		for (x = 0; x<w; x++, i++){
			n_status = cellTest(board, w, h, x, y);
			*(next_board + i) = n_status;
		}
	}
    for (y = 0, i=0; y<h; y++){
		for (x = 0; x<w; x++, i++){
			*(board+i) = *(next_board+i);
		}
	}
    
}

void printConway (char *board, int w, int h) {
	for (int j = 0; j < h; j++) {
		if (j == 0) {
			printf("  ");
			for (int i = 0; i < w; i++) {
				printf("%3d",i);
			}
		}
		
		printf("\n%2d ",j);
		for (int i = 0; i < w; i++) {
			if (*(board + j*w + i) == '1') {
				printf("███");
			} else if (*(board + j*w + i) == '0') {
				printf("   ");
			}		
		}
	}
	printf("\n\n");
}

int msleep(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}

int main () {
	char *board;  

	char filename[256];
	printf("Please enter the filename: ");
	scanf("%s", filename);
	strcat(filename,".conway");
	printf("Please enter how many steps you would like to simulate: ");
	int steps;
	scanf("%d", &steps);
	int time_step;
	printf("Please enter the delay in ms: ");
	scanf("%d", &time_step);
	
	FILE *f1 = fopen(filename, "r");
	int size_w;
	int size_h;
	fscanf(f1, "%d\n", &size_w);
	fscanf(f1, "%d\n", &size_h);
	
	// printf("w = %d\n", size_w);
	// printf("h = %d\n", size_h);
	
	board = (char*)malloc(size_h*size_w*sizeof(char));
	if (board == NULL) {
		printf("Runtime Error: Not Enough Memory!\n");
	}
	fread(board, sizeof(char), size_w*size_h, f1);
	
	// printConway(board, size_w, size_h);

	// cellTest(board, size_w, size_h, 0,0);
	// cellTest(board, size_w, size_h, 0,6);
	// cellTest(board, size_w, size_h, 7,3);
	// cellTest(board, size_w, size_h, 3,3);
	// cellTest(board, size_w, size_h, 2,2);
	// cellTest(board, size_w, size_h, 7,2);
	// cellTest(board, size_w, size_h, 2,5);		
	// cellTest(board, size_w, size_h, 8,5);
	// cellTest(board, size_w, size_h, 6,0);

	struct timespec ts;
	ts.tv_sec = 1/2;
	ts.tv_nsec = 0;

	printf("size_w = %d, size_h = %d\nBeginning conway sequence...\n", size_w, size_h);
	msleep(1000);

	for (int q = 0; q < steps; q++) {
		printf("\e[1;1H\e[2J");
		printf(">><<>><<>><<>><<>><<\n");
		printConway(board, size_w, size_h);	
		msleep(time_step);
		conwayStep(board, size_w, size_h);
	}
		
	free(board);
	fclose(f1);
	
}
