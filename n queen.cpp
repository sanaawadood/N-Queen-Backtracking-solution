
//************-------N QUEENS PROBLEM WITH BACKTRACKING-------*************///
//Complexity :: T(n)= n*(T(n-1) + O(n)) ==> T(n)= n!			
			
#include <bits/stdc++.h>
using namespace std;

vector< pair<int,int> > vec;
int n,total_count=0,mat[1009][1009]={0};

bool check (int r1,int c1,int r2,int c2){	//checker function for 2 coordinates
	
	if(r1+c1 == r2+c2 || r1-c1 == r2-c2)	//check for diagonal perfection
		return false;
	if(r1==r2 || c1==c2)	//check for row column perfection
		return false;
		
	return true;
}

void printit(){		//function for printing the possible arrangment
	cout << endl;
	memset(mat,0,sizeof(mat));
	for(int i=0; i<n; i++)
		mat[vec[i].first][vec[i].second]=1;
		
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout << mat[i][j]<<" ";
		cout << "\n";
	}
}

void solve(int col){
	
	for (int i=0; i<n; i++){		//trying on different rows
	
		int ch=1;
		
		for (int j=0; j<col; j++){	//checking with previosly placed queens
			if( !check(vec[j].first, vec[j].second, i, col) ){
				ch=0;
				break;
			}
		}		
		if	(ch) {		// if no problem with previously placed queens
			vec[col]=make_pair(i,col);
			if(col == n-1){
				total_count++;
				printit();
			}
			else
				solve( col+1 );	
		}
	}
}

int main(){
	
	cin >> n;
	
	vec.resize(n);
	cout << "The possible combinations are:\n";
	solve(0);
	cout << "\nTotal combinations are " << total_count << endl;
		
    return 0;
}
