#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define DESC(i, n) for(int i = n-1; i >= 0; i--)

using namespace std;

void printv(int v[], int n){
	cout << "[";
	for(int i = 0; i < n; i++){
		cout << v[i];
//		cout << "("<<i<<")";
		if(i != n-1){
			cout << ", ";
		}
	}
	cout << "]" << endl;
}

void printv(int v[], int l, int r){
	cout << "[";
	for(int i = l; i <= r; i++){
		cout << v[i];
//		cout << "("<<i<<")";
		if(i != r){
			cout << ", ";
		}
	}
	cout << "]" << endl;
}

void troca(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void max_heapify(int v[], int n, int start){
	int l = 2*start, r = 2*start+1;
	int largest;
	if(l <= n && v[l] > v[start]){
		largest = l;
	}
	else largest = start;
	if(r <= n && v[r] > v[largest]){
		largest = r;
	}
	if(largest != start){
		cout << "Hello World" << endl;
		troca(v[start], v[largest]);
		max_heapify(v, n, largest);
	}

}

void heapsort(int v[], int n){
	int vaux[n+1];
	REP(i, n) vaux[i+1] = v[i];
	
	DESC(i, n) max_heapify(vaux, n, i+1);
	int naux = n;
	REP(i, n){
		v[i] = vaux[1];
		troca(vaux[1], vaux[naux]);
		naux--;
		max_heapify(vaux, naux, 1);
	}
	REP(i, n) v[i] = vaux[i+1];
	printv(v, n);
}

void Merge(int v[], int mid, int r){
	if(0 < r){
		int i = 0, j = mid+1, k = 0, vtemp[r+1];
		while(i < mid+1 && j < r+1){
			if(v[i] < v[j]) vtemp[k++] = v[i++];
			else vtemp[k++] = v[j++];
		}
		while(i < mid+1) vtemp[k++] = v[i++];
		while(j < r+1) vtemp[k++] = v[j++];
		REP(i, r+1){
			v[i] = vtemp[i];
		}
	}
}

void mergesort(int v[], int n){
	if(n > 0){
		int mid = n/2;
		mergesort(v, n/2);
		mergesort(v + n/2 + 1, n/2);
		Merge(v, n/2, n);
	}
}

void bubblesort(int v[], int n){
	REP(i, n) REP(j, n-1) if(v[j] > v[j+1]) troca(v[j], v[j+1]);
}

void insertionsort(int v[], int n){
	REP(i, n-1){
		if(v[i] > v[i+1]){
			int j = i + 1;
			while(v[j] < v[j-1]){
				troca(v[j], v[j-1]);
				j--;
			}
		}
	}
}

void selectionsort(int v[], int n){
	int menor = 100000;
	int indmenor;
	REP(i, n){
		menor = 100000;
		for(int j = i; j < n; j++){
			if(v[j] < menor) {menor = v[j]; indmenor = j;}
		}
		troca(v[indmenor], v[i]);
	}
}

void quicksort(int v[], int l, int r){
	if(r > l){
		int pivot = v[l];
		int i = l, j = r-1;
		while(i < j){
			while(v[i] <= pivot) i++;
			while(v[j] > pivot && j >= l) j--;
			if(i < j) troca(v[i], v[j]);
		}
		troca(v[j], v[l]);
		quicksort(v, l, j);
		quicksort(v, j+1, r);
	}
}

int main(){
	int v[] = {4,1,3,2,16,9,10,14,8,7};
	heapsort(v, 10);
	return 0;
}