#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue> 
#include <string>
#include <sstream>
// clear screen  pake stl, clue utnuk Djikstra : Map Gets
// pake typedef struct untuk node Djikstra

using namespace std;

const int maks = 100;
int size = 9;

int matrix[maks][maks];

int visited[maks]; // array menampung node yg sudah dikunjungi
int result[maks];  // array untuk menampung hasil trace sesuai dengan urutan masuk
int iteration;

// cek apakah node "find" sudah pernah d kunjungi
bool is_visited(int find){
	return (visited[find] == 1);
}

// tampilkan node yang sudah dikunjungi
void show_visited(){
	printf("\n\t\t Visited : ");
	for(int i = 0; i < size; i++){
		if(visited[i] == 1){
			printf("%d|", i+1);
		}
	}
}

// set result secara terurut berdasarkan data yang masuk
void set_result(int index){
	result[iteration] = index;
	iteration++;
}

bool is_exists_result(int value){
	bool stat = false;
	bool loop = true;
	for(int i = 0; i < iteration && loop; i++){
		if(value == result[i]){
			stat = true;
			loop = false;
		}
	}
	return stat;
}

// cek apakah semua node sudah dikunjungi
bool is_max_visited(){
	int total = 0;
	for(int i = 0; i < size; i++){
		total += visited[i];
	}
	return (total == size);
}

// tampilkan status isi queue
void show_queue(queue <int> trace){	
	if(trace.empty()){
		printf("\n\t\t Queue \t : EMPTY\n");
	}else{
		printf("\n\t\t Queue \t : Front |");
		while(!trace.empty()){
			printf("%d|", trace.front() + 1);
			trace.pop();
		}
		printf(" Back");
	}
}

// tampilkan status isi stack
void show_stack(stack <int> trace){	
	if(trace.empty()){
		printf("\n\t\t Stack \t : EMPTY\n");
	}else{
		printf("\n\t\t Stack \t : Top << ");
		while(!trace.empty()){
			printf("%d|", trace.top() + 1);
			trace.pop();
		}
		printf("END");
	}
}

// RECURSIVE BFS
void recursive_bfs(int start, queue <int> &trace){
	int i;
	int it = -1;
	bool stat = true;
	trace.pop();
	
	printf("Point %d >> \t childs  : ", start + 1);
	for(i = 0; i < size; i++){
		if(matrix[start][i] == 1){
			if(! is_visited(i)){
				trace.push(i);
			}
			printf("%d, ", i + 1);
		}
	}
	
	show_visited();
	show_queue(trace);
	printf("\n\n");
	
	// skip jika ada node yg mau d cari ternyata sudah pernah dikunjungi
	while(!trace.empty() && stat){
		it = trace.front();
		
		if(! is_visited(it)){
			visited[trace.front()] = 1;
			set_result(it);
			stat = false;
		}else{
			it = -1;
			trace.pop();		
		}
	}
	
	if((!is_max_visited() || it > -1) && !trace.empty()){
		recursive_bfs(it, trace);
	}
}

void bfs(int start){
	queue <int> trace;
	int i;
	
	printf("----------------------------------------------------\n");
	start = start - 1; // convert ke index element array
	trace.push(start); // push ke queue untuk node awal
	visited[start] = 1;  // kasih flag untuk node yg pernah di akses
	
	set_result(start); 
	show_queue(trace);
	printf("\n\n");
	
	recursive_bfs(start, trace);
	
	show_queue(trace);
	printf("\n\n================  RESULT  ================");
	
	printf("\n\nTotal visited node \t\t : %d nodes", iteration);
	printf("\nBFS Result for start point %d \t : ", (start + 1));
	
	for(i = 0; i < iteration; i++){
		printf("%d, ", result[i]+1);
	}
}


// RECURSIVE DFS
void recursive_dfs(int start, stack <int> &trace){
	int i;
	int it = -1;
	bool stat = true;
	
	if(!is_exists_result(start)){
		set_result(start);
	}
	
	if(!trace.empty()){
		trace.pop();
	}
	
	printf("Point %d >> \t childs %d : ", start + 1, size);
	for(i = size - 1; i >= 0; i--){
		if(matrix[start][i] == 1){
			if(!is_visited(i)){ // Jika belum dikunjungi : masukkan ke stack
				trace.push(i);
				visited[i] = 1; // HARUS DI CEK LAGI.OK? 
			}else{
				if(!is_exists_result(i)){  // jika sudah dikunjungi, tp blm ada dalam list result : masukkan ke stack
					trace.push(i);
				}
			}
			printf("%d, ", i + 1);
		}
	}
	
	
	show_visited();
	show_stack(trace);
	printf("\n\n");
	
	if(!trace.empty()){
		recursive_dfs(trace.top(), trace);
	}
}


void dfs(int start){
	stack <int> trace;
	int i;
	
	printf("----------------------------------------------------\n");
	start = start - 1; // convert ke index element array
	trace.push(start); // push ke queue untuk node awal
	visited[start] = 1;  // kasih flag untuk node yg pernah di akses
	 
	show_stack(trace);
	printf("\n\n");
	
	recursive_dfs(start, trace);
	
	show_stack(trace);
	printf("\n\n================  RESULT  ================");
	
	printf("\n\nTotal visited node \t\t: %d nodes", iteration);
	printf("\nDFS Result for start point %d \t : ", (start + 1));
	
	for(i = 0; i < iteration; i++){
		printf("%d, ", result[i]+1);
	}
}

// inisialisasi tiap variabel global
void initialize(){
	iteration = 0; // iterasi awal sebuah result
	matrix[size][size];
	
	for(int i = 0; i < size; i++){
		visited[i] = 0;  	// proses inisialisasi visited node
		result[i] = 0;  	// proses inisialisasi result node
		
		for(int j = 0; j < size; j++){
			matrix[i][j] = 0;						
		}
	}
}

// lihat isi matrix
void show_matrix(){
	int i;
	int j;
	printf("\n\n >>>   Matrix Preview   <<<\n\n");
	
	printf("         \t   ");
	for(i = 0; i < size; i++){
		printf(" %d  ", i + 1);
	}
	printf("\n");
	for(i = 0; i < size; i++){
		printf("Point - %d\t: |", i + 1);
		for(j = 0; j < size; j++){
			printf(" %d |", matrix[i][j]);						
		}
		printf("\n");
	}
	printf("\n\n");
}

// set isi data matrix
void set_matrix(){
	string input;
	string data;
	int dt;
	
	printf(">>> Set Node \n");
	for(int i = 0; i < size; i++){
		printf("Point - %d : ", i+1);
		std::cin >> input; //fflush(stdin);
  		
  		istringstream ss(input);
		while(getline(ss, data, ',')){
			dt = std::stoi(data);
			
			if(dt > 0 && dt <= size){
				matrix[i][dt-1] = 1;
			}
		}
	}
}


int main () {
  	int  spoint;
  	char method;
  	char search;
  	char answer ;
  	bool stat;
  	
  	do{
	  	spoint = 0;
  		system("cls");
  		
  		
	  	
	  	printf(">>> Matrix Dimensions  :  ");
	  	cin >> size; //fflush(stdin);
	  	
	  	printf(">>> Matrix Dimensions  are %d X %d \n\n", size, size);
	  	
	  	initialize();
	   	
	   	printf("Direct Matrix (D) / Undirect Matrix (other) \t: ");
  	   	cin >> method; //fflush(stdin);
  	   	
  	   	set_matrix();
		show_matrix();
  	   	
	   	printf("BFS (b) / DFS (other) ? \t: ");
  	   	cin >> search; //fflush(stdin);
  	   	
  	   	stat = true;
  	   	
  	   	while(stat){
			printf("Start Point \t\t\t: ");
	   		cin >> spoint; //fflush(stdin);
	   		stat = (spoint > 0 && spoint <= size)? false : true;
		}
	   	
       	system("cls");
	  	printf(">>>>>>>>>>>>>>>>>>  PROCESSING  <<<<<<<<<<<<<<<<<<<< \n");  
		show_matrix();	  	
  	  	
  	    if(method == 'd' || method == 'D'){
			printf("Matrix \t\t >> Direct \n");
			if(search == 'b' || search == 'B'){
				printf("Method \t\t >> BFS mode \n");
				printf("Start Point \t >> %d  \n", spoint);
				bfs(spoint);
			}else{
				printf("Method \t\t >> DFS mode \n");
				printf("Start Point \t >> %d  \n", spoint);
				dfs(spoint);
			}	
		} else {
			printf("Matrix \t\t >> Undirect \n");
			if(search == 'b' || search == 'B'){
				printf("Method \t\t >> BFS mode \n");
				printf("Start Point \t >> %d  \n", spoint);
				bfs(spoint);
			}else{
				printf("Method \t\t >> DFS mode \n");
				printf("Start Point \t >> %d  \n", spoint);
				dfs(spoint);
			}	
		}
  	  	
  	  	printf("\n\nTry Again (y/n) ?: ");
  	  	cin >> answer; //fflush(stdin);
	}while(answer == 'y' || answer == 'Y');
  	
	return 0;
}
