#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define DESC(i, n) for(int i = n-1; i >= 0; i--)
#define mset(v, n) memset(v, n, sizeof(v))

using namespace std;

int N;
int A[100000];
int M[100000][20];

void process(){
	/*int i, j;
	REP(i, n) m[i][0] = i;
	//cout << "Hello World" << endl;
	for (j = 1; 1 << j <= n; ++j){
		for (i = 0; i + (1 << j) -1 < n; ++i){
			if(v[m[i][j-1]] < v[m[i + (1 << (j - 1))][j - 1]]){
				m[i][j] = m[i][j-1];
			}
			else{
				m[i][j] = m[i + (1 << (j - 1))][j - 1];
			}
		}
	}*/

	      int i, j;
   
  //initialize M for the intervals with length 1
      for (i = 0; i < N; i++)
          M[i][0] = i;
  //compute values from smaller to bigger intervals
      for (j = 1; 1 << j <= N; j++)
          for (i = 0; i + (1 << j) - 1 < N; i++)
              if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                  M[i][j] = M[i][j - 1];
              else
                  M[i][j] = M[i + (1 << (j - 1))][j - 1];

}

int rmq(int i, int j){
	int k = int(log2(j - i + 1));
	if(A[M[i][k]] < A[M[j - 1 << k + 1][k]]){
		return M[i][k];
	}
	else{
		return M[j - 1 << k + 1][k];
	}

}

int main(){
	int q;
	int a, b;
	cin >> N;
	REP(i, N) cin >> A[i];

	process();
	cin >> q;
	REP(i, q){
		cin >> a >> b;
		cout << "rmq = " << rmq(min(a, b), max(a, b)) << endl;
		cout << A[rmq(min(a, b), max(a, b))] << endl;
	}

	return 0;
}